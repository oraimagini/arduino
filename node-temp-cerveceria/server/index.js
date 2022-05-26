// server
const http = require('http');
const express = require('express');
//const io = require('socketio');

const app = express();
const server = http.createServer(app);

app.use(express.static(__dirname + '/public'));
server.listen(3000, function () {
   console.log('server listening on port', 3000)
})

// serialport biblioteca para conectar con arduino
const { SerialPort } = require('serialport');
const { ReadlineParser } = require('@serialport/parser-readline');

// Puerto, revisar estos datos en arduino-ide 
const port = new SerialPort({ path: '/dev/ttyACM0', baudRate: 9600 });

var dataArduino;

// formato de información por consola 
const parser = port.pipe(new ReadlineParser({ delimiter: '\r\n' }));

parser.on('data', function (data){
   console.log(data)
})
