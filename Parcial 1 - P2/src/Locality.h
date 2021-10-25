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

typedef struct
{
	int id;
	int idCustomer;
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
/// @param localityOne
/// @param len Tamanio del array
/// @return Retorna -1 si hubo error o 0 si esta todo ok
int addLocality(Locality* list, Locality localityOne, int len);

#endif /* LOCALITY_H_ */
