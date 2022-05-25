const { SerialPort } = require('serialport');

const { ReadlineParser } = require('@serialport/parser-readline');

const port = new SerialPort({ path: '/dev/ttyACM0', baudRate: 9600 });

var dataArduino;

const parser = port.pipe(new ReadlineParser({ delimiter: '\r\n' }));

parser.on('data', console.log)
