/*
 * Locality.h
 *
 *  Created on: Oct 25, 2021
 *      Author: Gonza
 */

#ifndef LOCALITY_H_
#define LOCALITY_H_

#include "Library.h"

#define TRUE 1
#define FALSE 0

#define TAML 7

typedef struct
{
	int id;
	char locality[51];
	int isEmpty;
}Locality;

/// @brief Inicializa el array de localidades, cambiando el estado de isEmpty a true en todas sus posiciones
/// @param list Array de localidades
/// @param len Tamanio del array
/// @return Retorna -1 si hubo error o 0 si esta todo ok
int initLocality(Locality* list, int len);

/// @brief Busca dentro del array la primer posicion que tenga estado isEmpty en true
/// @param list Array de localidades
/// @param len Tamanio del array
/// @return Retorna -1 si hubo error, si no el indice de la primer posicion libre
int findFirstEmptyLocalityPosition(Locality* list, int len);

/// @brief Agrega una localidad al array de localidades, buscando la primer posicion libre si es que existe, y cambia el estado de isEmpty a false
/// @param list Array de localidades
/// @param localityOne Auxiliar que se utilizara para igualar el listado
/// @param len Tamanio del array
/// @return Retorna -1 si hubo error o 0 si esta todo ok
int addLocality(Locality* list, Locality localityOne, int len);

/// @brief Agrega 10 localidades al array de localidades, en caso de que la bandera sea 0, caso contrario, no hace nada
/// @param localityList Array de localidades
/// @param len Tamanio del array
/// @param id ID utilizado para identificar la localidad
/// @param flagLocality Bandera que cambiara su valor una vez se agreguen las 10 localidades
/// @return Retorna -1 si hubo error, 1 si esta todo ok o 0 si la bandera es diferente a 0
int registerLocalitys(Locality* localityList, int len, int* id, int* flagLocality);

/// @brief Imprime en la consola el array de localidades que se han agregado
/// @param localityList Array de localidades
/// @param len Tamanio del array
/// @return Retorna -1 si hubo error o 0 si esta todo ok
int printLocalitys(Locality* localityList, int len);

/// @brief Nos permite encontrar el indice dentro del array de la localidad que coincida con ese ID
/// @param list Array de localidades
/// @param len Tamanio del array
/// @param id ID a comparar
/// @return Retorna -1 si hubo error, o el indice si fue exitoso
int findLocalityIndexById(Locality* list, int len, int id);

#endif /* LOCALITY_H_ */
