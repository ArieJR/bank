//-------------nieuwe versie client---------------

//connectie maken met Land-node
const io = require("socket.io-client");
const socket = io.connect("http://172.16.0.1:8085");

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


process.on('message', response => 
{
    console.log(response);
    if(data.header.action == 'balance')
    {
        //balance actie
        
    }
    else
    {
        //withdraw actie
    }
    chuan = response.body.code;
    process.send(chuan)
})

/*
//terwijl er connectie is met de Land-node
socket.on("connect", function()
{
    console.log("connected to server");

    //functies voor opvragen van data via emit
    function emitWithdraw(pin, rek, amount, aankomstBank, aankomstLand)
    {
        withdraw =
        {
            body:
            {
                pin: '0000',
                account: '01234567',
                amount: 30.00
            },
            header:
            {
                originCountry: 'DE',
                originBank: 'ANVI',
                receiveCountry: 'DE',
                receiveBank: 'ANVI'
            }
        }
        withdraw.body.pin = pin;
        withdraw.body.account = rek;
        withdraw.body.amount = amount;
        withdraw.header.receiveBank = aankomstBank;
        withdraw.header.receiveCountry = aankomstLand;

        socket.emit('withdraw',withdraw);
    }
    function emitBalance(pin, rek, aankomstBank, aankomstLand)
    {
        getBalance = 
        {
            body:
            {
                pin: '7654',
                account: '12345600'
            },
            header:
            {
                originCountry: 'DE',
                originBank: 'ANVI',
                receiveCountry: 'DE',
                receiveBank: 'ANVI'
            }
        }
        getBalance.body.pin = pin;
        getBalance.body.account = rek;
        getBalance.header.receiveBank = aankomstBank;
        getBalance.header.receiveCountry = aankomstLand;

        socket.emit('balance',getBalance);
    }

    //op deze manier een emit versturen
    // emitBalance('1122','00000002','DASB','DE');
    // emitBalance('1122','00000012','DASB','DE');
    // emitBalance('1142','00000002','DASB','DE');
    // emitWithdraw('1122','00000002',50,'DASB','DE');


    //voor het verhandelen van de ontvangst nadat er data is opgevraagd
    socket.on('response', responseBody =>
    {
        console.log(responseBody);

        if(responseBody.body.code == 200)
        {
            if(responseBody.header.action == 'withdraw')
            {

            }
            else if(responseBody.header.action == 'balance')
            {

            }
            else
            {
                //error
            }
        }
        else if(responseBody.body.code == 401)
        {
            //pincode fout
        }
        else if(responseBody.body.code == 402)
        {
            //niet genoeg balance
        }
        else if(responseBody.body.code == 403)
        {
            //pas geblokkeerd
        }
        else if(responseBody.body.code == 404)
        {
            //bestaat niet
        }
    })


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
*/

