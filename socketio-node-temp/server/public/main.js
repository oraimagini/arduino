console.log('temperatura de los fermentadores')

const socket = io();
socket.on('temp', function(data) {
   console.log(data)
   const temperature = document.getElementById('printdata')
   temperature.innerHTML = `${data} c°`
})

