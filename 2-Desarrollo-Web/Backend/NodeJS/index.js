const http = require('http')

http.createServer(function(req,res){  // creando un servidor
   res.write('<h1>Hola mundo desde NodeJS</h1>') 
   res.end()
}).listen(3000);  // en que puerto escucha

// Ir a localhost:3000