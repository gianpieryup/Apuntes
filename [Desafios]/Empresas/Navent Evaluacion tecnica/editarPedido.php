<?php
$json = file_get_contents("tablaPedidos.json");
$array = json_decode($json, true);//lo hace un array asociativo

if ($_POST) {
  $nuevo = ['pedidos'=> []  ];
  foreach ($array["pedidos"] as  $value) {
    if($value["id"]==$_GET["id"]) {
        $value["nombre"]=$_POST["nombre"];
        $value["monto"]=$_POST["monto"];
        $value["descuento"]=$_POST["descuento"];
        $nuevo['pedidos'][]=$value;
    }else {
        $nuevo['pedidos'][]=$value;
    }
  }
  $nuevo = json_encode($nuevo, JSON_PRETTY_PRINT);
  file_put_contents("tablaPedidos.json", $nuevo);
  header("Location:index.html");
}

if (isset($_GET["id"])) {
  $pedido = null;
    // var_dump($array["pedidos"]);
  foreach ($array["pedidos"] as  $value) {
    if($value["id"]==$_GET["id"]) {
        $pedido = $value;
        break;
    }
  }
  if ($pedido == null) {//No lo encontro
    echo "No existe el pedido"."<br>";
    exit;
  }
  // var_dump($pedido);
}

?>


<!DOCTYPE html>
<html lang="en" dir="ltr">
  <head>
    <meta charset="utf-8">
    <title>Editar Pedido</title>
    <link rel="stylesheet" href="https://bootswatch.com/4/lux/bootstrap.min.css">
  </head>
  <body>
<div class="container">
  <h2 class="m-3">Edita el Pedido</h2>
  <div class="col-md-5">
    <div class="card">
      <div class="card-body">
        <!-- FORM TO ADD TASKS -->
        <form action="editarPedido.php?id=<?= $_GET['id'] ?>" id="formulario" method="post">
          <div class="form-group">
            <input type="text" name="nombre" id="nombre" placeholder="Nombre" class="form-control" value="<?=$pedido["nombre"] ?>" required>
          </div>
          <div class="form-group">
            <input type="number" name="monto" id="monto" placeholder="Monto" class="form-control" value="<?=$pedido["monto"] ?>" required>
          </div>
          <div class="form-group">
            <input type="number" name="descuento" id="descuento" placeholder="Descuento" class="form-control" value="<?=$pedido["descuento"] ?>" required>
          </div>
          <!-- <input type="hidden" id="taskId"> -->
          <button type="submit" class="btn btn-primary btn-block text-center guardar">
            Guardar Pedidos
          </button>
        </form>
      </div>
    </div>
  </div>
</div>
  </body>
</html>
