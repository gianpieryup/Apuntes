# Expresiones Regulares en JavaScript

### JavaScript

````javascript
Aparesca una subcadena
let reg = /abc/		// like '%abc%'

Operador (*)
Una 'a' preceda a cero o más 'b' (* significa 0 o más ocurrencias del elemento precedente)  y sea inmediatamente seguida por una 'c'
let reg = /ab*c/	// like '%ab...bc%'

Operador (+)
Significa 1 o más ocurrencias del elemento precedente
let reg = /u+/		// like '%u...%'

Operador (\)
let reg = /a*/      // like '%a...a%' 	
El cambiar el patrón, el carácter especial (*) es interpretado como un carácter simple
let reg = /a\*/		// like '%a*%'

Operador (^) : Se usa el principio para quitar el (%)
let reg = /^B/ 		// like 'B%'

Operador ($) : Se usa al final para quitar el (%)
let reg = /r$/ 		// like '%r'

````



