<?php
include "pedido.php";
/*La clase PedidosDAO tiene los siguientes métodos estáticos que actualizan la tabla Pedido
(tomarlos como ya implementados, no es necesario codificarlos):
void insertOrUpdate(Pedido pedido): inserta un nuevo pedido en la base de datos o modifica un pedido existente (en cado de crear uno nuevo, el pedido pasado como parámetro se completa con el nuevo id).
void delete(Pedido pedido): elimina el pedido que corresponde al id recibido.
Pedido select(Integer idPedido): busca un pedido por id.
2-*/

$json = file_get_contents("tablaPedidos.json");
$array = json_decode($json, true);//lo hace un array asociativo

if (isset($_POST["datos"])) {
  $pedido =  json_decode($_POST["datos"],true);
  $pedido = [
  "id" => nextId(),
  "nombre" => $pedido["nombre"] ,
  "monto" =>  $pedido["monto"],
  "descuento" => $pedido["descuento"]
  ];

  $array["pedidos"][] = $pedido;
  $array = json_encode($array, JSON_PRETTY_PRINT);
  file_put_contents("tablaPedidos.json", $array);

  echo json_encode("Todo bien") ;
}

function nextId(){
  if (!file_exists("tablaPedidos.json")) {
    $json = "";//'' no va
  }else {
    $json = file_get_contents("tablaPedidos.json");
  }
  if ($json == "") {
    return 1;
  }

  $array = json_decode($json, true);
  $ultimoUsuario = array_pop($array["pedidos"]);
  $lastId = $ultimoUsuario["id"];

  return $lastId + 1;
}

//borrar
if ( isset($_GET["id"]) ) {
  $idAeliminar = $_GET['id'];
      for ($i=0; $i < count($array["pedidos"]) ; $i++) {
        if($array["pedidos"][$i]["id"] == $idAeliminar ){
          unset($array["pedidos"][$i]);
          // $array.splice($i,1);
        }
      }
      $nuevo = ['pedidos'=> []  ];
      foreach($array["pedidos"] as $value){
        $nuevo['pedidos'][]=$value;
      }
      // var_dump($nuevo);
      $nuevo = json_encode($nuevo, JSON_PRETTY_PRINT);
       // var_dump($nuevo);
      file_put_contents("tablaPedidos.json", $nuevo);
      header("Location:index.html");
}


//buscarPorID

class PedidoDao
{
  function listaUsuarios(){
    $json = file_get_contents("tablaPedidos.json");
    $array = json_decode($json, true);

    return $array["pedidos"];
  }
  function nextId(){
    // TODO: que pasa si no hay usuario anterior.
    if (!file_exists("tablaPedidos.json")) {
      $json = "";//'' no va
    }else {
      $json = file_get_contents("tablaPedidos.json");
    }
    if ($json == "") {
      return 1;
    }

    $array = json_decode($json, true);
    $ultimoUsuario = array_pop($array["usuarios"]);
    $lastId = $ultimoUsuario["id"];

    return $lastId + 1;
  }

  function guardarUsuario($usuario){
    // TOD: que pasa si no hay archivo.
    if (!file_exists("tablaPedidos.json")) {
      $json = '';
    }else {
      $json = file_get_contents("tablaPedidos.json");
    }
  //  $json = file_get_contents("tablaPedidos.json");
    $array = json_decode($json, true);

    $array["pedidos"][] = $usuario;
    $array = json_encode($array, JSON_PRETTY_PRINT);

    file_put_contents("tablaPedidos.json", $array);
  }
  function insertOrUpdate(Pedido $pedido){
  /*inserta un nuevo pedido en la base de datos o modifica un pedido existente (en cado de crear uno nuevo, el pedido pasado como parámetro se completa con el nuevo id)*/
  }

  function delete(Pedido $pedido){
  /*elimina el pedido que corresponde al id recibido.}*/
  }
}
