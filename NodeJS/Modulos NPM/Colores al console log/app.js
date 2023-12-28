const chalk = require('chalk');
 
console.log(chalk.blue('Hello world!'));
console.log(chalk.green('Hello world!'));
console.log(chalk.red('Hello world!'));
console.log(chalk.yellow('Hello world!'));
console.log(chalk.magenta('Hello world!\n'));

//negrita : OK
console.log(chalk.bold.green('Hello world!\n'));

//cursiva : NO me funciona
console.log(chalk.italic.green('Hello world!\n'));

//subrayado : OK
console.log(chalk.underline.green('Hello world!\n'));

//invierte los colores con el fondo
console.log(chalk.inverse.blue('Hello world!\n'));

//color de fondo
//Por defecto el color de las letras es blanco
console.log(chalk.bgRed('Hello world!\n'));
//podemos especificar el color de la letra
console.log(chalk.bgRed.yellow('Hello world!\n'));
console.log(chalk.bgMagenta.black('Hello world!\n'));

console.log(`Server on port ${chalk.green('3000')}`);
