
// serialport biblioteca para conectar con arduino
const { SerialPort } = require('serialport');
const { ReadlineParser } = require('@serialport/parser-readline');

// Puerto, revisar estos datos en arduino-ide 
const port = new SerialPort({ path: '/dev/ttyACM0', baudRate: 9600 });

var dataArduino;

// formato de información por consola 
const parser = port.pipe(new ReadlineParser({ delimiter: '\r\n' }));

parser.on('data', console.log)
