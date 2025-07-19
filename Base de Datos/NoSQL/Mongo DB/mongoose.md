# Mongoose

Como siempre mirar la documentación oficial, siempre ayuda

<span style='color:red'>**Mongoose**</span> es un ORM de <span style='color:green'>**MongoDB**</span>

Prerrequisitos: mongo, mongod, CRUD, collections y documents

 ````shell
`Tener Node`
node -v

`Tener mongod`
mongod --version

`Instalacion`
npm install mongoose
 ````

### Conexión a mongoDB

````javascript
const mongoose = require('mongoose')

const uri = 'mongodb://localhost/mydatabase'
mongoose.connect(uri, {
  useNewUrlParser: true,
  useUnifiedTopology: true,
  useCreateIndex: true,//Si te sale un error sobre indices
}).catch(err => console.log(err));

//EVENTOS
//Cuando la conexion fue dada
mongoose.connection.on('open', _ => {
    console.log('Database is connected to',uri)
})

//Cuando ocurra un error en la conexion
mongoose.connection.on('error', err => {
    console.log(err)
})
````

### Las Tablas

Las definimos con un Schema, creamos entonces archivos `.js` en la carpeta `models`

````javascript
//Sea el archivo Product.js que hara referencia a la tabla Product
const {Schema} = require('mongoose');

const productSchema = new Schema({
    name: String,
    description: String,
    price: {type:Number,default:0}//Con más especificaciones
})

module.exports = model('Product',productSchema)
````

Otro Modelo

````javascript
const { Schema, model } = require('mongoose');

const userSchema = new Schema({
    username: {
        type: String,
        unique: true,
        required: true
    },
    password: String,
    date: {
        type: Date,
        default: new Date()
    },
    name: String
});

module.exports = new model('User', userSchema);
//En mongoDb los nombres se guardan en plural 'Users'
````

> BONUS: Si la tabla ya tiene datos repetidos y el modelo tiene el campo unique este se pierde e ignora esa regla :c

Como importarlo en un nuevo archivo

````javascript
require('./connection');

// using the model 
const product = require('./models/product');

// creating a new document base on the model
const product = new product({
    name: 'laptop',
    description: 'lenovo thinkpad x1 carbon 6th generation',
    price: '1300.99'
});

console.log(product);//Aqui vemos que mongoose le creo un '_id'


// Guardar y crear document
product.save((err, document) => {
    if (err) console.log(err);
    console.log('saved:', document);//Para verificar que se guardo aparecera un campo '__v'
});
````

Cuidadito con el Asincronismo, como ya no se usan callbacks te muestro el `async await`

````javascript
require('./connection');

const Product = require('./models/Product')

async function main() {
    const product  = new Product({
        name: 'Keyboard',
        description: 'Coursair K68 RGB Game Keyboard',
        price: '150'
    });
    const productSaved = await product.save();
    return productSaved;
}

main()
    .then(productSaved => console.log(productSaved))
    .catch(err => console.log(err));
````

### CRUD

Creamos una :file_folder: llamada CRUD, con las siguientes operaciones

#### FIND

````javascript
require('../connection');

const User = require('../models/User');

const searchProducts = async () => {//definicion de la funcion asyncrona
    // search all products
    const products = await User.find({});//Dentro del find la condicion
    
    console.log(products)
};

searchProducts();
````

#### FINDONE

````javascript
require('../connection');

const User = require('../models/User');

const someFunction = async () => {//definicion de la funcion asyncrona
    const newUser = await User.findOne({username: 'fazt'});
    const otherUser = await User.findOne({username: 'ryan'});
    
    console.log(newUser)
    console.log(otherUser)
};

someFunction();
````

#### UPDATE

````javascript
require('../connection');

const User = require('../models/User');

//Actualiza solo uno
const someFunction = async () => {
    const user = await User.findOne({username: 'fazt'});//busca
    user.name = 'joe';//Mofica
    await user.save();//Por que ya sabe cual objeto es por el id
    console.log(user);
};

//Puedo actualizar propiedades que no esten definidas aun en el schema
const otherFunction = async () => {
    const user = await User.findOneAndUpdate({username: 'fazt'}, {
        name: 'Ryan Ray'
    }, {new: true});//Para que devuelva el dato actualizado
    console.log(user);
};

// someFunction();
otherFunction();
````

#### DELETE

````javascript
require('../connection');

const Product = require('../models/Product');

//Osea hallo el id y con ese elimino
const someFunction = async () => {
    // Borrar el primero que cumpla la propiedad
    // const deletedProduct = await Product.deleteOne({name: 'laptop hp'});
    
    // Borrar todos los que cumplan
    // const result = await Product.deleteMany({name: 'laptop hp'});
    
    // Igual que el anterior pero me devuelve el objeto borrado
    // const result = await Product.findOneAndDeletmousee({name: 'mouse'});
    
    // Borra por ID
    const result = await Product.findByIdAndDelete('5e290e03a1def223dc11c70d');
    console.log(result);
};

someFunction();
````

**Si quiero trabajar con Typescript  existe un superconjunto de mongoose llamado typegoose**

