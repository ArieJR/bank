//-------------nieuwe versie client---------------
 
//Make connection
const io = require("socket.io-client");
const socket = io.connect("http://145.24.222.11:8085");

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
        receiveCountry: 'NE',
        receiveBank: 'TEST'
    }
}

getBalance = {
    body: 
    {
        pin: '7654',
        account: 'DU-ANVI-12345600'
    },
    header: 
    {
        originCountry: 'DE',
        originBank: 'ANVI',
        receiveCountry: 'DE',
        receiveBank: 'DASB'
    }
}

socket.on("connect", function()
{
    console.log("connected to server");

    function emitWithdraw(pin, rek, amount, aankomstBank, aankomstLand) 
    {
        withdraw.body.pin = pin;
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
    
    // emitBalance('7654','DU-ANVI-12345600','NE','GERS');
    emitWithdraw('1654','DU-ANVI-12345600',20,'DE','DASB');


});


socket.on('response', responseBody =>
{
    console.log(responseBody);
})