# Findroots
Este programa utiliza el m�todo de Vieta para resolver la ecuacion c�bica de la forma aX^3 + bX^2 + cX + d = 0

## Comenzando
### Prerequisitos
Findroots no necesita ninguna libreria externa pero requiere CMake para poder crear el proyecto en su IDE preferido. 
### Instalaci�n
Puedes instalar CMake siguiendo las instrucciones de la pagina oficial:

https://cmake.org/install/

Para descargar el proyecto corres el siguiente comando en el programa de linea de comandos:

```git clone https://github.com/marcomedrano1999/findroots.git```

Para crear la carpeta del proyecto, copea la ruta del directorio donde se descargaron los documentos, abre CMake y p�gala en el cuadro a la izquierda de la etiqueta "Where is the
source code:". Haz lo mismo con el cuadro abajo de este, pero agregando a final lo siguiente: ```/Build```. Da click en el boton "Configure" (se deben de desplegar valores en rojo
en el cuadro arriba del mencionado boton) y despues da click en el boton "Generate". Una explicaci�n m�s detallada se puede encontrar en el siguiente video:

https://www.youtube.com/watch?v=wl2Srog-j7I&list=PLpHIphr3laQZxwrehzusWud6nEyym8SJ2&index=1

## �C�mo funciona?
Como se mencion� anteriormente, este programa utiliza el metodo de Vieta descrito ampliamente en https://ru.wikipedia.org/wiki/%D0%A2%D1%80%D0%B8%D0%B3%D0%BE%D0%BD%D0%BE%D0%BC%D0%B5%D1%82%D1%80%D0%B8%D1%87%D0%B5%D1%81%D0%BA%D0%B0%D1%8F_%D1%84%D0%BE%D1%80%D0%BC%D1%83%D0%BB%D0%B0_%D0%92%D0%B8%D0%B5%D1%82%D0%B0 
(en ruso). Para poder utilizar �ste m�todo necesitamos transformar la ecuacion cubica de la forma general aX^3 + bX^2 + cX + d = 0 a la forma  X^3 + (b/a)X^2 + (c/a)X + (d/a) = 0 dividiendo los coeficientes entre a.

Despues, procedemos a calcular los elementos principales (Q, R and S), cuya f�rmula se describe en el documento. El valor S nos permite determinar que sub-f�rmula debemos aplicar. Si S > 0, 
hay tres raices reales. Si S = 0, tenemos dos raices reales diferentes (una de las cuales se repite). Finalmente, si S < 0, solo existe una raiz real. Con esto, usamos la formula para cada caso y obtenemos la solucion.


### Entradas
Para ejecutar el programa en la linea de comandos, escribimos:
```findroots a b c d```
donde a, b, c y d son los coeficientes de la forma general de la ecuacion c�bica. Si 'a' es igual a cero o si es un c�racter, el programa no regresa raices. Si 'b', 'c' o 'd' son c�racteres, esos coeficientes
se tomara como si fueran 0.

### Salidas
El programa regresa las raices utilizando fix 5 en el siguiente formato:
```{root1, root2, root3}```
donde 'root1', 'root2' y'root3' son los valores de las raices de los coeficientes dados. Si, para los coeficientes dados, solo se tiene una raiz real, 'root1' ser� la �nica que aparecer� entre los braquets.
Como se mencion� anteriormente, si el valor ingresado de 'a' es cero o un c�racter, el programa no regresa ninguna ra�z. En otras palabras, regresa solamente el par de braquets.

## Elaborado con
IDE: Visual Studio 2017

CMake version: 3.18.3

## Autor 
**Marco Medrano**

## Agradecimientos
Francois Vita

Comunidad de Stack overflow

