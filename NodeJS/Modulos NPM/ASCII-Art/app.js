const figlet = require('figlet')

figlet('Hello', {
    font: 'Ghost',//Opcional Documentacion
    horizontalLayout: 'default',
    verticalLayout: 'default'

},(err,result)=>{
	console.log(err || result)
})