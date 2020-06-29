//Make connection
const io = require("socket.io-client");
const socket = io.connect("http://145.24.222.11:8080");

socket.on("connect", function()
{
    console.log("connected to server");

    function emitWithdraw(pincode, rek, aantal, aankomstBank, aankomstLand) 
    {
        data =
        {
            body:
            {
                pin: pincode,
                account: rek,
                amount: aantal
            },
            header:
            {
                originCountry: 'DE',
                originBank: 'ANVI',
                receiveCountry: aankomstLand,
                receiveBank: aankomstBank
            }
        }
        socket.emit('withdraw',data);
    }
    function emitBalance(pincode, rek, aankomstBank, aankomstLand) 
    {
        data =
        {
            body:
            {
                pin: pincode,
                account: rek
            },
            header:
            {
                originCountry: 'DE',
                originBank: 'ANVI',
                receiveCountry: aankomstLand,
                receiveBank: aankomstBank
            }
        }
        socket.emit('balance',data);
    }
    function emitBank(pincode, rek, aankomstBank, aankomstLand, actie) 
    {
        data =
        {
            body:
            {
                pin: pincode,
                account: rek
            },
            header:
            {
                originCountry: 'DE',
                originBank: 'ANVI',
                receiveCountry: aankomstLand,
                receiveBank: aankomstBank,
                action: actie
            }
        }
        socket.emit('bank',data);
    }
    emitBank('7654','12345600','DASB','DE', 'balance');     //of withdraw
    // emitBalance('7654','12345600','ANVI','DE');
    // emitWithdraw('7654','12345600',20,'ANVI','DE');
});


socket.on('response', responseBody =>
{
    console.log(responseBody);
/*
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
    */
})