//-------------------
var express = require("express");
var app = express();
var http = require("http").Server(app);
var io = require("socket.io")(http);

//tussen js
const { fork } = require('child_process');
const landNode = fork('client.js');


//database setup
var mysql = require('mysql');

var database = mysql.createConnection
({
    host:"localhost",
    user:"0981073",
    password:"inti54321",
    database:"ANVI"
});

database.connect(function(err)
{
    if (err) throw err;
    console.log("Connected!");
});

//Socket setup
io.on('connection', function(socket)
{
    console.log('made socket connection', socket.id)

    socket.on('bank', function(data)
    {
        console.log(data);

        landNode.send(data);                            //data doorsturen naar client.js

        landNode.on("message", function(response)       //data ontvangen en doorsturen naar QT
        {
            console.log(response);
            socket.emit('response', (response));
        });
    });

    //withdraw handler, voor het afhandelen van de vraag naar een withdraw
    socket.on('withdraw', function(data)
    {
        data.body.account = 'DU-ANVI-'+data.body.account;
        console.log(data);

        withdrawResponse =
        {
            body:
            {
                code: 200,
                message: 'Succes'
            },
            header:
            {
                originCountry: 'DE',
                originBank: 'ANVI',
                receiveCountry: data.header.originCountry,
                receiveBank: data.header.originBank,
                action: 'withdraw'
            }
        }

        //kijken of rekeningnummer bestaat
        database.query('SELECT case when ? =(SELECT Rekeningnummer FROM ANVI.Pas WHERE Rekeningnummer=?) then 1 else 0 end as bool FROM ANVI.Pas', [data.body.account, data.body.account],(err, rekResult) =>
        {
            if(err) throw err;

            if(rekResult[0].bool == 1)
            {
                //kijken of de pas geblokkeerd is
                database.query('SELECT Pas_geblokkeerd FROM Pas WHERE Rekeningnummer=?',[data.body.account],(err,blokkedResult) =>
                {
                    if(err) throw err;

                    if(blokkedResult[0].Pas_geblokkeerd == 0)
                    {
                        //kijken of de pincode correct is
                        database.query('SELECT case when ? =(SELECT Pincode FROM ANVI.Pas WHERE Rekeningnummer = ?) then 1 else 0 end as bool FROM ANVI.Pas',[data.body.pin, data.body.account],(err, pincodeResult) =>
                        {
                            if(err) throw err;

                            if(pincodeResult[0].bool == 1)
                            {
                                //aantal_foutpogingen resetten
                                database.query('UPDATE `ANVI`.`Pas` SET `Aantal_foutpogingen` = 0 WHERE (Rekeningnummer=?)', [data.body.account], (err, result) =>
                                {
                                    if(err) throw err;
                                })
                                //balance checken
                                database.query('SELECT Saldo FROM ANVI.Rekening WHERE `Rekeningnummer` = ?', [data.body.account], (err, balanceResult) =>
                                {
                                    if(err) throw err;

                                    if(balanceResult[0].Saldo >= data.body.amount)
                                    {
                                        //geld overschrijven naar bank account
                                        database.query('UPDATE `ANVI`.`Rekening` SET `Saldo` = `Saldo`-? WHERE (`Rekeningnummer` = ?)', [data.body.amount, data.body.account], (err, result) =>
                                        {
                                            if(err) throw err;
                                        })
                                        database.query('UPDATE `ANVI`.`Rekening` SET `Saldo` = `Saldo`+? WHERE (`Gebruikers_ID` = 5);', [data.body.amount], (err, result) =>
                                        {
                                            if(err) throw err;
                                        })
                                        //emit versturen
                                        withdrawResponse.body.code = 200;
                                        withdrawResponse.body.message = 'Succes';
                                        socket.emit('response',withdrawResponse)
                                    }
                                    else
                                    {
                                        withdrawResponse.body.code = 402;
                                        withdrawResponse.body.message = 'Niet genoeg saldo';
                                        socket.emit('response',withdrawResponse)
                                    }
                                })
                            }
                            else //stuur terug dat pincode fout is
                            {
                                //zet aantal_foutpogingen 1 omhoog
                                database.query('UPDATE `ANVI`.`Pas` SET `Aantal_foutpogingen` = `Aantal_foutpogingen`+1 WHERE (Rekeningnummer=?)', [data.body.account], (err, result) =>
                                {
                                    if(err) throw err;
                                })
                                database.query('SELECT Aantal_foutpogingen FROM Pas WHERE (Rekeningnummer=?)',[data.body.account],(err, pogResult) =>
                                {
                                    if(err) throw err;

                                    if(pogResult[0].Aantal_foutpogingen == 3)
                                    {
                                        //pas blokkeren
                                        database.query('UPDATE `ANVI`.`Pas` SET `Pas_geblokkeerd` = 1 WHERE (Rekeningnummer=?)', [data.body.account], (err, result) =>
                                        {
                                            if(err) throw err;
                                        })
                                        withdrawResponse.body.code = 403;
                                        withdrawResponse.body.message = '3 foute pogingen, pas geblokkeerd';
                                        socket.emit('response',withdrawResponse)
                                    }
                                    else
                                    {
                                        withdrawResponse.body.code = 401;
                                        withdrawResponse.body.message = 'foute pincode';
                                        withdrawResponse.body.attempts = pogResult[0].Aantal_foutpogingen;
                                        socket.emit('response',withdrawResponse)
                                    }
                                })
                            }
                        })
                    }
                    else
                    {
                        withdrawResponse.body.code = 403;
                        withdrawResponse.body.message = 'pas geblokkeerd';
                        socket.emit('response',withdrawResponse)
                    }
                })
            }
            else //rekeningnummer bestaat niet in de database
            {
                withdrawResponse.body.code = 404;
                withdrawResponse.body.message = 'rekeningnummer bestaat niet';
                socket.emit('response',withdrawResponse)
            }
        })
    });
  
  
    //balance handler, voor het afhandelen van de vraag naar een balance
    socket.on('balance', function(data)
    {
        data.body.account = 'DU-ANVI-'+data.body.account;
        console.log(data);

        balanceResponse =
        {
            body:
            {
                code: 200,
                message: 'Success',
                balance: 0
            },
            header:
            {
                originCountry: 'DE',
                originBank: 'ANVI',
                receiveCountry: data.header.originCountry,
                receiveBank: data.header.originBank,
                action: 'balance'
            }
        }

        //kijken of rekeningnummer bestaat
        database.query('SELECT case when ? =(SELECT Rekeningnummer FROM ANVI.Pas WHERE Rekeningnummer=?) then 1 else 0 end as bool FROM ANVI.Pas', [data.body.account, data.body.account],(err, rekResult) =>
        {
            if(err) throw err;

            if(rekResult[0].bool == 1)
            {
                //kijken of de pas geblokkeerd is
                database.query('SELECT Pas_geblokkeerd FROM Pas WHERE Rekeningnummer=?',[data.body.account],(err,blokkedResult) =>
                {
                    if(err) throw err;

                    if(blokkedResult[0].Pas_geblokkeerd == 0)
                    {
                        //kijken of de pincode correct is
                        database.query('SELECT case when ? =(SELECT Pincode FROM ANVI.Pas WHERE Rekeningnummer = ?) then 1 else 0 end as bool FROM ANVI.Pas',[data.body.pin, data.body.account],(err, pincodeResult) =>
                        {
                            if(err) throw err;

                            if(pincodeResult[0].bool == 1)
                            {
                                //aantal_foutpogingen resetten
                                database.query('UPDATE `ANVI`.`Pas` SET `Aantal_foutpogingen` = 0 WHERE (Rekeningnummer=?)', [data.body.account], (err, result) =>
                                {
                                    if(err) throw err;
                                })
                                //balance opvragen
                                database.query('SELECT Saldo FROM ANVI.Rekening WHERE `Rekeningnummer` = ?', [data.body.account], (err, balanceResult) =>
                                {
                                    if(err) throw err;
                                    balanceResponse.body.balance = balanceResult[0].Saldo;

                                    //emit versturen
                                    balanceResponse.body.code = 200;
                                    balanceResponse.body.message = 'Succes';
                                    socket.emit('response',balanceResponse)
                                })
                            }
                            else //stuur terug dat pincode fout is
                            {
                                //zet aantal_foutpogingen 1 omhoog
                                database.query('UPDATE `ANVI`.`Pas` SET `Aantal_foutpogingen` = `Aantal_foutpogingen`+1 WHERE (Rekeningnummer=?)', [data.body.account], (err, result) =>
                                {
                                    if(err) throw err;
                                })
                                database.query('SELECT Aantal_foutpogingen FROM Pas WHERE (Rekeningnummer=?)',[data.body.account],(err,pogResult) =>
                                {
                                    if(err) throw err;

                                    if(pogResult[0].Aantal_foutpogingen == 3)
                                    {
                                        //pas blokkeren
                                        database.query('UPDATE `ANVI`.`Pas` SET `Pas_geblokkeerd` = 1 WHERE (Rekeningnummer=?)', [data.body.account], (err, result) =>
                                        {
                                            if(err) throw err;
                                        })
                                        balanceResponse.body.code = 403;
                                        balanceResponse.body.message = '3 foute pogingen, pas geblokkeerd';
                                        socket.emit('response',balanceResponse)
                                    }
                                    else
                                    {
                                        balanceResponse.body.code = 401;
                                        balanceResponse.body.message = 'foute pincode';
                                        balanceResponse.body.attempts = pogResult[0].Aantal_foutpogingen;
                                        socket.emit('response',balanceResponse)
                                    }
                                })
                            }
                        })
                    }
                    else
                    {
                        balanceResponse.body.code = 403;
                        balanceResponse.body.message = 'pas geblokkeerd';
                        socket.emit('response',balanceResponse)
                    }
                })
            }
            else //rekeningnummer bestaat niet in de database
            {
                balanceResponse.body.code = 404;
                balanceResponse.body.message = 'rekeningnummer bestaat niet';
                socket.emit('response',balanceResponse)
            }
        })
    });
});

http.listen(8080, function()
{
    console.log('listening on: 8080')
});
