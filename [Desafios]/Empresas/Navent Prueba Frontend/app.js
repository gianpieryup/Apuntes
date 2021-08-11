$(document).ready(function() {
  var colorGuardado = localStorage.getItem('color')

  if (colorGuardado == 'red') {
      $('.fa-heart').css('background-color','red')
  }
  console.log(colorGuardado);

  $('.fa-heart').click(function(){
    var color = localStorage.getItem('color');
    if (color != null) {//si hay guardado algo
      if (color == 'red') {//si esta en rojo
        //lo pinto de negro
        localStorage.setItem('color','negro');
        $('.fa-heart').css('background-color','black')
      }
      if (color == 'negro') {//si esta negro
        //lo pinto de rojo
        localStorage.setItem('color','red');
        $('.fa-heart').css('background-color','red')
      }
    }else {
      localStorage.setItem('color','red');
      $('.fa-heart').css('background-color','red')
    }
    console.log(localStorage.getItem('color'));
  })

  $(window).resize(function() {
     var heightBrowser =$(window).width();
     if (heightBrowser>720) {
       $('.titulo').html('Si vas a utilizar un pasaje de Lorem Ipsum, necesitás esta...');
     }else {
        $('.titulo').html('Si vas a utilizar un pasaje de Lorem Ipsum, necesitás esta seguro');
     }
  })

//precio de aviso GUARDADO EN Storage
var precio = localStorage.getItem('precio');
if (precio != null) {//Hay un precio guardado en el local storage
  var precioXmetro = parseFloat(Math.round((precio/380) * 100) / 100).toFixed(1);
  $('.caja-precioXmetro').html('$/m<sup>2</sup>'+ precioXmetro);
  $('.precio').html('U$S ' + precio);
}
//caundo presiono para modificar el precio
$('.precio').click(function() {
  var inputPrecio =  document.getElementById('input-precio');
  var formulario = document.querySelector(".precio-form");
  formulario.onsubmit = function(event){
    if (inputPrecio.value == "") {
      event.preventDefault();//evitamos que se envie el formulario vacio
      $('.invalido-numero').css('display','block');//avisamos que no esta completando el campo
    }else {
      var precio =inputPrecio.value ;
        localStorage.setItem('precio',precio);
    }
  };
})

//validaciones de email
var emailRegex = /^(([^<>()\[\]\.,;:\s@\"]+(\.[^<>()\[\]\.,;:\s@\"]+)*)|(\".+\"))@(([^<>()[\]\.,;:\s@\"]+\.)+[^<>()[\]\.,;:\s@\"]{2,})$/i;
$('.botom').click(function() {
  var inputEmail =  document.getElementById('input-email');
  var formulario = document.querySelector(".email-form");
  formulario.onsubmit = function(event){
    if (inputEmail.value == "") {
      event.preventDefault();//evitamos que se envie el formulario vacio
      $('.invalido-email').html("campo vacio");//especificamos el tipo de error
    }else {
      if (!emailRegex.test(inputEmail.value)) {
        event.preventDefault();//evitamos que se envie el formulario vacio
        $('.invalido-email').html("formato de email no valido");//especificamos el tipo de error
      }
    }
  }
})

})
