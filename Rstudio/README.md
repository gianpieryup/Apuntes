# R estudio

*Limpiar consola* <kbd>ctrl + L</kbd> 

Un  poco marea el manejo de listas

#### Crear Lista

````R
x <- 1:5    # x = [1,2,3,4,5] 
y = c(1, 2, 3,4)
````

### NA

````R
# is.na(a) devuelve TRUE o FALSE

# is.na(vector) devuelve un vector.Con valores TRUE si es NA y FALSE si no lo es
z = c(1, NA, 3,NA)
is.na(z)
[1] FALSE  TRUE FALSE  TRUE
````

#### ifelse

El valor de retorno es un vector de la misma longitud

````R
# ifelse(test_expression, x, y)
a = c(5,7,2,9)
ifelse(a %% 2 == 0,"even","odd")
[1] "odd"  "odd"  "even" "odd"

# Es decir, el i-elemento de resultado será x[i], si test_expression[i] es       TRUE, lo contrario se toma el valor de y[i].
ifelse(a %% 2 == 0,c(8,9,5,5),c(4,2,2,1))
[1] 4 2 5 1
````

