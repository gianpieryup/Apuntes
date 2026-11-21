def saludar(nombre: str) -> None:
    """Imprime un saludo personalizado."""
    print(f"¡Hola, {nombre}! Espero que tengas un excelente día.")

def despedir(nombre: str) -> None:
    """Imprime una despedida."""
    print(f"¡Hasta luego, {nombre}! Nos vemos pronto.")

if __name__ == "__main__":
    saludar("Mundo")
    id = input("Ingresa tu ID: ")
    print(f"Tu ID es: {id}")
    despedir("Mundo")
