<?php

class Pedido
{
  private $id;
  private $nombre;
  private $monto;
  private $descuento;


  function __construct($array)
  {
    if (isset($array["id"])){
      $this->id = $array["id"];

    } else {
      $this->id = null;
    }
    $this->nombre = trim($array["nombre"]);
    $this->monto = trim($array["monto"]);
    $this->descuento = trim($array["descuento"]);
  }
}
