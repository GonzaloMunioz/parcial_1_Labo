/*
 * Customers.h
 *
 *  Created on: Oct 5, 2021
 *      Author: Gonza
 */

#ifndef CUSTOMERS_H_
#define CUSTOMERS_H_

#include "Library.h"

#define FALSE 0
#define TRUE 1

#define TAM 100

typedef struct
{
	int id;
	char companyName[51];
	char address[51];
	char cuit[13];
	int isEmpty;
}Customer;

/// @brief Inicializa el array de clientes, cambiando el estado de isEmpty a true en todas sus posiciones
/// @param list Array de clientes
/// @param len Tamanio del array
/// @return Retorna -1 si hubo error o 0 si esta todo ok
int initCustomers(Customer* list, int len);int findFirstEmptyPosition(Customer* list, int len);

/// @brief Agrega un cliente al array de clientes, buscando la primer posicion libre si es que existe, y cambia el estado de isEmpty a false
/// @param list Array de clientes
/// @param customerOne Estructura auxiliar que usaremos para igualar nuestra estructura original
/// @param len Tamanio del array
/// @param id Recibe el valor de ID para asignarlo
/// @return Retorna -1 si hubo error o 0 si esta todo ok
int addCustomer(Customer* list, Customer customerOne, int len, int id);int findCustomerById(Customer* list, int len, int id);

/// @brief Cambia el estado de isEmpty a true en caso de haber encontrado match
/// @param list Array de clientes
/// @param len Tamanio del array
/// @param id ID que recibe del pedido de ID de la funcion deleteCustomer
/// @return Retorna -1 si hubo error o 0 si esta todo ok
int removeCustomer(Customer* list, int len, int id);

/// @brief Pide el ingreso de una cadena de 11 digitos numericos, y le da un formato estilo cuit, con guiones
/// @param cuit Cadena donde se guardara el cuit ya formateado
/// @return Retorna 0 si hubo error o 1 si esta todo ok
int addCuit(char cuit[]);

#endif /* CUSTOMERS_H_ */
