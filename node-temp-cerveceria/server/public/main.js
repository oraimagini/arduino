console.log('temperatura de los fermentadores')

const socket = io();
socket.on('temp', function(data) {
   console.log(data)
})
