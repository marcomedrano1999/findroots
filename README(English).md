# Findroots
This program returns the real roots of a cubic ecuation using the Vita's trigonometric formula. This programs solves the cubic ecuation in the form of aX^3 + bX^2 + cX + d = 0

## Getting Started
### Prerequites
Findroots doesn't need any external libraries but it's necessary to install CMake to create the
project in your computer.
### Installing
You can install CMake following the steps explained in the official page:

https://cmake.org/install/

You can download this project by running the following comand

```git clone https://github.com/marcomedrano1999/findroots.git```

Open CMake and paste the project's path in the "Where is the source code", then paste it again in "Where to build binaries" and add "/Build" at the end. 
Once you've done this, click in the "Configure" button, it must display red values. Finally, click in the Generate botton, and select your favorite IDE.
A better explanation can be found in the next video:

https://www.youtube.com/watch?v=wl2Srog-j7I&list=PLpHIphr3laQZxwrehzusWud6nEyym8SJ2&index=1

## How does it work?
We start from the formula described in https://ru.wikipedia.org/wiki/%D0%A2%D1%80%D0%B8%D0%B3%D0%BE%D0%BD%D0%BE%D0%BC%D0%B5%D1%82%D1%80%D0%B8%D1%87%D0%B5%D1%81%D0%BA%D0%B0%D1%8F_%D1%84%D0%BE%D1%80%D0%BC%D1%83%D0%BB%D0%B0_%D0%92%D0%B8%D0%B5%D1%82%D0%B0 
(in russian). To be able to use this, we need to transform the general cubic ecuation from aX^3 + bX^2 + cX + d = 0 to  X^3 + (b/a)X^2 + (c/a)X + (d/a) = 0 by dividing the coefficients by a.

Then, we calculate the main components (Q, R and S), as described in the document. The S value tell us the following steps we should implement. If S > 0, there are three real
roots. If S = 0, we have only 2 different real roots (one of those is repeadead). Finally, if S < 0, there is only one real root. Then, we implement the formula for each case.


### Inputs
To execute the program in the line command, we need to type:
```findroots a b c d```
where a, b, c and d are the coefficients of the general cubic ecuation. If 'a' is equal to cero or if its a character, the program returns cero roots. If 'b', 'c' or 'd' are characters, that coefficient 
will be considered as 0.

### Outputs
The programs returns the roots with a fix of 5 in the following style:
```{root1, root2, root3}```
where 'root1', 'root2' and 'root3' are the values of the roots of the given inputs. If the ecuation only has one real root, 'root1' will be the only one that appers between the braces.
As I mencionated before, if the 'a' you introduce is equal to cero or is a character, the program returns cero roots, in other words, it return only the pair of braces.

## Build with
IDE: Visual Studio 2017

CMake version: 3.18.3

## Author 
**Marco Medrano**

## Acknowledgments
Francois Vita

Stack overflow community

