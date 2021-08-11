$(document).ready(function() {
  // Testing Jquery
  console.log('jquery Funcionando!');
  cargarPedidos();
  var formulario = document.getElementById('formulario');
      formulario.addEventListener('submit',function(e) {
      e.preventDefault();
      console.log("Me diste clik");

    var inputNombre = document.querySelector("[name=nombre]").value;
    var inputMonto = document.querySelector("[name=monto]").value;
    var inputDescuento = document.querySelector("[name=descuento]").value;
    var campos = {nombre:inputNombre, monto:inputMonto, descuento:inputDescuento};
    var datosFormulario = new FormData();
    datosFormulario.append('datos',JSON.stringify(campos));
    fetch('pedidosDAO.php',{
      method : 'POST',
      body : datosFormulario
    })
    .then(function(response){
      return response.json();
    })
    .then(function(data){
      cargarPedidos();
      $('#formulario').trigger('reset');
    })

  })

  function cargarPedidos(){
    fetch("tablaPedidos.json")
    .then(function(response){
      return response.json();
    })
    .then(function(data){
        var template = '';
        console.log(  data.pedidos);
        data.pedidos.forEach(function(elem) {
          console.log(elem);
        })
        data.pedidos.forEach(function(elem) {
          console.log(elem);
                 template += `
                         <tr taskId="${elem.id}">
                         <td>${elem.id}</td>
                         <td>
                         <a href="#" class="task-item">
                           ${elem.nombre}
                         </a>
                         </td>
                         <td>${elem.monto}</td>
                         <td>${elem.descuento}</td>
                         <td>
                         <a href="editarPedido.php?id=${elem.id}" class="btn btn-warning">Modificar</a>
                         <a href="pedidosDAO.php?id=${elem.id}" class="task-delete btn btn-danger">Delete</a>
                         </td>
                         </tr>
                       `;
        })
           $('#tasks').html(template);
    })
    .catch(function(error){
      console.log("El error es: " + error);
    })
  }

})
