''' ASCII-UNICODE
En Python existen las funciones 'ord' y 'chr' que sirven para trabajar 
con caracteres y su representación en Unicode
Podes ver la tabla para constatar los caracteres
'''

# Letra Mayusculas (65-90)
for num in range(65,91):
    print("Num",num,"-> caracter:",chr(num)) 


# Letras Minusculas (97-122)
for num in range(97,123):
    print("Num",num,"-> caracter:",chr(num))
    
# Cambiar a mayusculas o minusculas
palabra = "Yo TE conoZco"
print(palabra.lower())
print(palabra.upper())

