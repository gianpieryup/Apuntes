# Subida de Imágenes

Instalar el modulo `Multer`

````javascript
//En app.js
const multer = require('multer');

//Por defecto no se guarda con la extension.
//Multer tiene metodos, para definir su configuracion. Entonces podemos arreglar lo de la extension
const storage = multer.duskStorage({
   destination: path.join(__dirname,'public/uploads'),
   //Funcion: Con que nombre se guardara el archivo
   filename(req,file,cb)=>{
       //Especificamos el 'original': osea con el que vino. Podemos esto despues alterarlo
       cb(null,file.originalname)
   } 
});

---------------------------
//Antes de las rutas, Es un Midelware
//Si no existe la carpeta la crea
app.use(multer({
    storage: storage,
    limits: {fileSize: 100000},//Opcional
    dest: path.join(__dirname,'public/uploads')	//Lugar donde seran subidas las imagenes//Se puede omitir si esta especificado en 'storage'
}).single('image'));//(name del Input)
// .single : Si es solo una imagen


//Para que las imagenes sean publicas y puedan ser accedidas en nuestro navegador: Luego esta carpeta 'public' puede ser accedida desde cualquier lado del navegador
// Static Files
app.use(express.static(path.join(__dirname,'public')));
//TIPEAR: localhost:3000/uploads/asd.jpg

//----------------Donde sea que esto este
//Creamos una ruta que recibe la imagen
app.post('/upload',(req,res)=> {
    console.log(req.file);// Informacion de la imagen
    res.send('uploaded')
})
````

Donde va esto ?

Obviamente no todo va en `app.js` ,si quisiéramos tenerlo el `midellware mulder` en una sola ruta lo quitamos de `app.js` y escribimos de la siguiente forma.

````javascript
const multer = require('multer');
const path = require('path');
//const uuid = require('uuid');No olvidar import

const storage = multer.diskStorage({
    destination: path.join(__dirname, '../public/uploads'),//Ojo con las rutas
    filename:  (req, file, cb) => {
        cb(null, file.originalname);
        //Podemos cambiar el nombre con uuid
        //cb(null,uuid() + path.extname(file.originalname).toLocaleLowerCase());
        //El ultimo (.) es por si te viene la extension en Mayusculas
    }
})
const uploadImage = multer({
    storage,//Toma la 'const' definida arriba
    limits: {fileSize: 1000000}//(< 1 Mb)
}).single('image');

router.post('/images/upload', (req, res) => {
    uploadImage(req, res, (err) => {
        if (err) {
            err.message = 'The file is so heavy for my service';
            return res.send(err);
        }
        console.log(req.file);
        res.send('uploaded');
    });
});

````

### Validaciones

Para validar si lo que se esta subiendo es una imagen o bien el formato `.jpg o .png`

TIP : `cb: significa callback`

````javascript
const uploadImage = multer({
    storage, //Toma la 'const' definida arriba
    limits: {fileSize: 1000000}, //(< 1 Mb)
    fileFilter: (req, file,cb) => { //Validaciones
        //validacion de extension
        const filetypes = /jpeg|jpg|png|gif/;
        const mimetype = filetypes.test(file.mimetype);
        const extname = filetypes.test(path.extname(file.originalname));
        if (mimetype && extname){
            return cb(null,true)
        }
        cb("Error: El archivo debe ser una imagen valida")
    }
}).single('image');
````



