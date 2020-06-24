//Make connection
const io = require("socket.io-client");
const socket = io.connect("http://145.24.222.11:8080");

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
        originBank: 'HOII',
        receiveCountry: 'DE',
        receiveBank: 'ANVI'
    }
}

getBalance = {
    body: 
    {
        pin: '7654',
        account: '12345600'
    },
    header: 
    {
        originCountry: 'DE',
        originBank: 'DASB',
        receiveCountry: 'DE',
        receiveBank: 'ANVI'
    }
}

socket.on("connect", function()
{
    console.log("connected to server");

    function emitWithdraw(pin, rek, amount, aankomstBank, aankomstLand) 
    {
        withdraw.body.pin = pin;            //vervang voor data
        withdraw.body.account = rek;
        withdraw.body.amount = amount;
        withdraw.header.receiveBank = aankomstBank;
        withdraw.header.receiveCountry = aankomstLand;

        socket.emit('withdraw',withdraw);
    }
    function emitBalance(pin, rek, aankomstBank, aankomstLand) 
    {
        getBalance.body.pin = pin;
        getBalance.body.account = rek;
        getBalance.header.receiveBank = aankomstBank;
        getBalance.header.receiveCountry = aankomstLand;

        socket.emit('balance',getBalance);
    }
    
    emitBalance('7654','12345600','ANVI','DE');
    // emitWithdraw('7654','12345600',20,'ANVI','DE');
});


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