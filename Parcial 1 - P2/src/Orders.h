/*
 * Orders.h
 *
 *  Created on: Oct 20, 2021
 *      Author: Gonza
 */

#ifndef ORDERS_H_
#define ORDERS_H_

#include "Library.h"

#define TRUE 1
#define FALSE 0

#define EMPTY -1
#define PENDING 1
#define COMPLETED 0

#define T 1000

typedef struct
{
	int lowDensityPolyethylene;
	int highDensityPolyethylene;
	int polypropylene;
	int totalKg;
}TotalKg;

typedef struct
{
	int id;
	int idCustomer;
	int status;
	TotalKg totalJunk;
}Order;

/// @brief Inicializa el array de pedidos, cambiando el estado de status a empty en todas sus posiciones
/// @param list Array de pedidos
/// @param len Tamanio del array
/// @return Retorna -1 si hubo error o 0 si esta todo ok
int initOrders(Order* list, int len);int findFirstEmptyOrderPosition(Order* list, int len);

/// @brief Agrega un pedido al array de pedidos, buscando la primer posicion libre si es que existe, y cambia el estado de status a pending
/// @param list Array de pedidos
/// @param orderOne
/// @param len Tamanio del array
/// @param id Recibe el valor de ID para asignarlo
/// @return Retorna -1 si hubo error o 0 si esta todo ok
int addOrder(Order* list, Order orderOne, int len, int id);int printOrders(Order* list, int len);

/// @brief Recibe un ID y realiza una busqueda en el array comparando ese ID
/// @param list Array de pedidos
/// @param len Tamanio del array
/// @param id ID que recibe de forma externa para realizar la comparacion
/// @return Retorna -1 si hubo error o el indice en case de haber sido exitosa la comparacion
int findOrderById(Order* list, int len, int id);int addProcessedOrder(Order* list, TotalKg totalKg, int len, int indexOrder);

/// @brief Muestra en pantalla los pedidos pendientes, y pide un ID de un pedido existente, luego cambia el estado de status a completed
/// @param list Array de pedidos
/// @param len Tamanio del array
/// @return Retorna -1 si hubo error o 0 si esta todo ok
int processOrder(Order* list, int len);

/// @brief Recorre el array de pedidos, contando la cantidad de pedidos segun estado que hay
/// @param list Array de pedidos
/// @param len Tamanio del array
/// @param status Recibe el estado que queremos contar
/// @return Retorna -1 si hubo error, o el contador de pedidos si esta todo ok
int countOrdersByStatus(Order* list, int len, int status);

#endif /* ORDERS_H_ */
