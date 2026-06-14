#Ejercicio 1
5e-3 %Equivale a decir 5*10^-3 == 0.005

#Ejercicio 3
0:2:50
10:-0.5:-10

#Ejercicio 4
x = linspace(0,2*pi,100)
y = cos(x)
plot(x,y)

#Ejercicio 5
#a)
x = linspace(-2*pi,2*pi,100)
y = sin(x)
plot(x,y,'*')
#b)
x = 0:100
y = sqrt(x)
plot(x,y,'*')
#c)
x = -5:5
y = 3*x.^2 + 5 % x es un array de numeros,NO un solo numero
plot(x,y,'*')

#Ejercicio 6
# f) g*h # No cumplen la restriccion de las dimesiones

#Ejercicio 7
function y=f(x)
  y=2*x.^2+1;
endfunction

x = -10:10
y = f(x)
plot(x,y,'*') # plot: recibe dos arrays como parametros

%AHHH
%A Todas las funciones les falta un 'end' para cerrar

#Ejercicio 8
#a) x! factorial
#b) Como siempre floor(x)<= x y se da la igualdad cuando X es entero
#Si x no es entero imprime por consola 'X no es entero.'
#Si x es entero hay dos casos:
    #Si x es 0 entonces retorna 1
    #Si X no es 0 retorna X!
#c) Es una funcion que recibe una lista de numeros y devuelve el menor
#d) Crea la matriz identidad de tamaño nxn donde n es el parametro de la funcion
#e) Retorna el numero mas grande (de la forma 2^-n) tal que (a+1==1)
    #   a =    1.1102230246251565e-16
#f) Sea x el numero pasado por parametro, la funcion busca en menor n_0/
# x^n_0/n_0! <= E (donde E , es el de la maquina, osea 1 + E == 1)
# Una ves hallado n0, retorna la Sumatoria[0,n_0] de x^n/n!
% OBSERVACION
% Sea S la sumatoria mencionada
% Como para la maquina S + (x^n/n!) == S , para todo n>n_0
% Entonces S[0,n0] == S[0,infinito] 
% Pero esto es una serie muy conocida e^x
% Por lo tanto (para la maquina) el resultado debe coincidir con e^x


#Ejercicio 9
function a = maximovector()
x = input('Introduce un vector: ')
n = length(x);
a = x(1);
for i=2:n
if x(i)>a
a = x(i);
end
end
end

#Ejercicio 10
function [mayor,pos] = maximoPosicion()
x = input('Introduce un Vector: ')
n = length(x);
mayor = x(1);
pos = 1;
for i=2:n
  if x(i)>mayor
    mayor = x(i);
    pos = i;
  endif  
endfor
end

% Cuandon es multiple las
% [mayor, pos] = maximoPosicion()

#Ejercicio 11
% max()
#Para un argumento vectorial, devuelve el valor máximo. 
#Para un argumento de matriz, devuelva un vector de fila con el valor máximo de cada columna.

% [x, ix] = max (x)
% devuelve el primer índice de los valores máximos. Así,
[x, ix] = max ([1, 3, 5, 2, 5]) 
   ? x = 5 
       ix = 3

%RPTA: Si, funciona con matrizes y con vectores
function m = maximoMatriz(x)
 m = max(max(x));
endfunction


