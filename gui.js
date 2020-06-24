//-------------------
var express = require("express");
var app = express();
var http = require("http").Server(app);
var io = require("socket.io")(http);

//Socket setup
io.on('connection', function(socket)
{
    console.log('made socket connection', socket.id)

    //withdraw handler
    socket.on('withdraw', function(data)
    {
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
        io.sockets.emit('response', withdrawResponse)
    });
  
  
    //balance handler
    socket.on('balance', function(data)
    {
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
        io.sockets.emit('response', balanceResponse)
    });
});
    
http.listen(8080, function()
{
    console.log('listening on: 8080')
});