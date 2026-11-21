def frase_del_dia() -> None:
    """Imprime una frase motivacional."""
    print("[Consejo] Da pequeños pasos cada día y llegarás lejos.")

def cuenta_regresiva(segundos: int) -> None:
    """Imprime una cuenta regresiva sencilla."""
    print("Iniciando cuenta regresiva:")
    for i in range(segundos, 0, -1):
        print(f"Faltan {i}...")
    print("¡Despegue exitoso!")

if __name__ == "__main__":
    frase_del_dia()
    print()
    cuenta_regresiva(3)
