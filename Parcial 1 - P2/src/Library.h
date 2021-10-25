/*
 * Library.h
 *
 *  Created on: Sep 16, 2021
 *      Author: Gonza
 */

#ifndef LIBRARY_H_
#define LIBRARY_H_

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "conio.h"


////// INGRESO //////

/// @brief Nos permite el ingreso de un numero entero
/// @param mensaje Es el mensaje que imprimiremos en pantalla
/// @param numeroIngresado Es el puntero de la variable en donde almacenaremos el numero ingresado
/// @return Retorna un valor logico para validar si hubo error (0) o salio ok (1)
int IngresarEntero(char mensaje[], int* numeroIngresado);

/// @brief Nos permite el ingreso de un numero flotante
/// @param mensaje Es el mensaje que imprimiremos en pantalla
/// @param numeroIngresado Es el puntero de la variable en donde almacenaremos el numero ingresado
/// @return Retorna un valor logico para validar si hubo error (0) o salio ok (1)
int IngresarFlotante(char mensaje[], float* numeroIngresado);

/// @brief Nos permite el ingreso de un numero flotante double
/// @param mensaje Es el mensaje que imprimiremos en pantalla
/// @param numeroIngresado Es el puntero de la variable en donde almacenaremos el numero ingresado
/// @return Retorna un valor logico para validar si hubo error (0) o salio ok (1)
int IngresarDoble(char mensaje[], double* numeroIngresado);

/// @brief Nos permite ingresar un caracter, retornando este mismo
/// @param mensaje Es el mensaje que imprimiremos en pantalla, para especializar la funcion
/// @param caracter Es el puntero de la variable char en donde almacenaremos el caracter ingresado
/// @return Retorna un valor logico para validar si hubo error (0) o salio ok (1)
int IngresarCaracter(char mensaje[], char* caracter);

/// @brief Misma funcion que IngresarNumero, pero validando el numero en un rango maximo y minimo
/// @param mensaje Es el mensaje que imprimiremos en pantalla, para especializar la funcion
/// @param min Valor minimo que puede ser ingresado
/// @param max Valor maximo que puede ser ingresado
/// @param pNumeroIngresado Es el puntero de la variable en donde almacenaremos el numero ingresado
/// @return Retorna un valor logico para validar si hubo error (0) o salio ok (1)
int IngresarEnteroValidado(char mensaje[], int min, int max, int* pNumeroIngresado);

/// @brief Misma funcion que IngresarFlotante, pero validando el numero en un rango maximo y minimo
/// @param mensaje Es el mensaje que imprimiremos en pantalla, para especializar la funcion
/// @param min Valor minimo que puede ser ingresado
/// @param max Valor maximo que puede ser ingresado
/// @param pNumeroIngresado Es el puntero de la variable en donde almacenaremos el numero ingresado
/// @return Retorna un valor logico para validar si hubo error (0) o salio ok (1)
int IngresarFlotanteValidado(char mensaje[], float min, float max, float* pNumeroIngresado);

/// @brief Misma funcion que las demas, pero utilizando double, aceptando un valor muchisimo mayor
/// @param mensaje Es el mensaje que imprimiremos en pantalla, para especializar la funcion
/// @param min Valor minimo que puede ser ingresado
/// @param max Valor maximo que puede ser ingresado
/// @param pNumeroIngresado Es el puntero de la variable en donde almacenaremos el numero ingresado
/// @return Retorna un valor logico para validar si hubo error (0) o salio ok (1)
int IngresarDobleValidado(char mensaje[], double min, double max, double* pNumeroIngresado);

/// @brief Nos permite ingresar un caracter validado entre dos otros caracteres
/// @param mensaje Es el mensaje que imprimiremos en pantalla, para especializar la funcion
/// @param caracter Es el puntero de la variable donde almacenaremos el ingreso
/// @param s Es el primer caracter a validar
/// @param n Es el segundo caracter a validar
/// @return Retorna un valor logico para validar si hubo error (0) o salio ok (1)
int IngresarCaracterValidado(char mensaje[], char* caracter, char s, char n);

/// @brief Es una funcion que nos permite ingresar una cadena de caracteres, por ejemplo un nombre
/// @param mensaje Es el mensaje que imprimiremos en pantalla, para especializar la funcion
/// @param cadena Es el vector que pasamos por referencia
/// @return Retorna un valor logico para validar si hubo error (0) o salio ok (1)
int IngresarCadena(char mensaje[], char* cadena, int tam);

/// @brief Nos permite ingresar una cadena de caracteres alfabeticos exclusivamente
/// @param mensaje Es el mensaje que imprimiremos en pantalla, para especializar la funcion
/// @param mensajeError Si se ingresa un valor incorrecto, se imprimira este mensaje
/// @param cadena Es la direccion de memoria donde se almacenara la cadena ingresada
/// @return Retorna un valor logico para validar si hubo error (0) o salio ok (1)
int IngresarNombre(char mensaje[], char mensajeError[], char* cadena, int tam);

/// @brief Nos permite ingresar un vector de enteros
/// @param numeros Es la direccion de memoria donde se almacenara el vector ingresado
/// @param tam Es el tamaño maximo del vector
/// @return Retorna un valor logico para validar si hubo error (0) o salio ok (1)
int IngresarVector(int* numeros, int tam);


////// SALIDA //////

/// @brief Imprime un numero entero en pantalla que recibe como parametro
/// @param mensaje Es el mensaje que se imprimira antes de imprimir el numero
/// @param numeroIngresado Es el numero que imprimiremos en pantalla
void ImprimirNumero(char mensaje[] , int numeroIngresado);

/// @brief Imprime un vector de enteros, en un formato de listado
/// @param mensaje Es el mensaje que se imprimira antes de imprimir el listado de numeros
/// @param numeroIngresado Es el vector que recibira como parametro para imprimirlo en pantalla
/// @param T Es el tamaño del vector
/// @param caracter Es un caracter identificativo para especializar la funcion,  'T' = todos, 'P' = pares, 'I' = impares, '+' = positivos, '-' = negativos, '0' = neutro
void ImprimirVector(char mensaje[], int numeroIngresado[], int T, char caracter);


////// FUNCIONES LOGICAS //////

/// @brief Valida la positividad, negatividad o neutralidad de un numero que recibe como parametro
/// @param numeroIngresado Es el numero que recibe como parametro para validar su signo
/// @return Devuelve un valor logico dependiendo el resultado de la validacion, 1 = positivo, 0 = neutro, -1 = negativo
int ValidarPositivo(float numeroIngresado);

/// @brief Valida la paridad de un numero que recibe como parametro
/// @param numeroIngresado Es el numero que recibe como parametro para validar su paridad
/// @return Devuelve un valor logico dependiendo el resultado de la validacion, 1 = par, 0 = impar
int ValidarPar(int numeroIngresado);

/// @brief Valida si un numero es entero o flotante, con decimales
/// @param numeroIngresado Es el numero que recibe como parametro para validar si tiene decimales, o no
/// @return Devuelve un valor logico dependiendo el resultado de la validacion, 1 = flotante, 0 = entero
int ValidarFlotante(float numeroIngresado);

/// @brief Funcion que nos permite especializar los contadores para un vector
/// @param numeroIngresado Es el vector que recibe como parametro para contar
/// @param T Es el tamaño del vector
/// @param caracter Es el caracter que nos sirve para especializar la funcion,  'T' = todos, 'P' = pares, 'I' = impares, '+' = positivos, '-' = negativos, '0' = neutro
/// @return Devuelve contador, de esta forma sera posible almacenar el resultado
int ContadorVector(int numeroIngresado[], int T, char caracter);

/// @brief Funcion que nos permite especializar los acumuladores de un vector
/// @param numeroIngresado Es el vector que recibe como parametro para acumular
/// @param T Es el tamaño del vector
/// @param caracter Es el caracter que nos sirve para especializar la funcion, 'T' = todos, 'P' = pares, 'I' = impares, '+' = positivos, '-' = negativos, '0' = neutro
/// @return Devuelve acumulador, de esta forma sera posible almacenar el resultado
int AcumuladorVector(int numeroIngresado[], int T, char caracter);

/// @brief Es una funcion que nos permite identificar el mayor o menor numero ingresado en una estructura repetitiva
/// @param i Es el indice que nos ayudara a identificar si es la primer iteracion, o no
/// @param numeroIngresado Es el numero que queremos identificar si es el maximo o el minimo
/// @param mayorMenorNumero Es el mayor o menor numero actual, que utilizaremos para comparar y reasignar de ser necesario
/// @param caracter Es el caracter identificativo para especializar la funcion, '<' = menor, '>' = mayor
/// @return Devuelve el mayor o menor numero reasignado, si es necesario
int MayorMenorNumero(int i, int numeroIngresado, int mayorMenorNumero, char caracter);

/// @brief Es una funcion que nos permite intercambiar el valor de dos variables numericas entre si
/// @param numeroUno Es el puntero del valor 'a', es decir, la ubicacion en memoria
/// @param numeroDos Es el puntero del valor 'b', es decir, la ubicacion en memoria
/// @param primerNumero Es el valor 'a', que utilizaremos para intercambiar
/// @param segundoNumero Es el valor 'b', que utilizaremos para intercambiar
void IntercambiarValores(int* numeroUno, int* numeroDos, int primerNumero, int segundoNumero);

/// @brief Es una funcion que nos permite ordenar datos numericos de forma decreciente
/// @param valor Es el vector, con los valores cargados
/// @param tam Es el tamaño del vector
void OrdenarDatos(int valor[], int tam);

/// @brief Nos permite, a partir de un string nombre y otro apellido, concatenarlos y ordenarlos, primero el apellido y luego el nombre
/// @param nombre Es el string nombre, que se concatenara luego del string apellido
/// @param apellido Es el string apellido, que sera el primero en la combinacion
/// @param nombreCompleto Es el string resultante de la concatenacion de los dos arrays
/// @return Es un valor logico, para evitar retornar void
int RetornarNombreCompleto(char nombre[], char apellido[], char nombreCompleto[]);

/// @brief Es un 'formateo' de strings, en el que el array se transforma en minuscula, para luego convertir en mayuscula la primer letra y cualquiera que este consiguiente a un espacio
/// @param cadena Es el string a formatear
/// @return Es un valor logico, para evitar retornar void
int FormatearCadena(char cadena[]);

/// @brief Nos permite validar un numero que recibe como parametro
/// @param cadena Es el numero ingresado, convertido a caracter para validar su valor en la tabla ASCII
/// @return Retorna un valor logico para validar si hubo error (0) o salio ok (1)
int ValidarNumero(char cadena[]);

/// @brief Nos permite validar un caracter alfabetico
/// @param cadena Es la cadena de caracteres que recibe como parametro para validar
/// @return Retorna un valor logico para validar si hubo error (0) o salio ok (1)
int ValidarAlfa(char *cadena);


////// FUNCIONES MATEMATICAS //////

/// @brief Permite realizar una operacion matematica basica, devolviendo el resultado de la misma
/// @param numeroUno Es el primer operando de la operacion
/// @param numeroDos Es el segundo operando de la operacion
/// @param operador Es el indicador de tipo caracter, que determinara que operacion se realizara
/// @return Es el resultado de la operacion entre los numeros
double OperacionesLogicas(float numeroUno, float numeroDos, char operador);

/// @brief Nos permite ingresar un numero y calcular su factorial
/// @param  valorAFactorear Es el valor que factorizaremos, deberá ser entero
/// @return Nos devuelve el factorial del numero ingresado
long double Factorial(int valorAFactorear);


#endif /* LIBRARY_H_ */
