def mostrar_suma(a: float, b: float) -> None:
    """Calcula e imprime la suma de dos números."""
    resultado = a + b
    print(f"La suma de {a} + {b} es: {resultado}")

def tabla_multiplicar(numero: int, limite: int = 5) -> None:
    """Imprime la tabla de multiplicar hasta un límite dado."""
    print(f"--- Tabla del {numero} ---")
    for i in range(1, limite + 1):
        print(f"{numero} x {i} = {numero * i}")

if __name__ == "__main__":
    mostrar_suma(7, 3)
    print()
    tabla_multiplicar(4)
