/*
 * Nexus.h
 *
 *  Created on: Oct 20, 2021
 *      Author: Gonza
 */

#ifndef NEXUS_H_
#define NEXUS_H_

#include "Customers.h"
#include "Orders.h"
#include "Locality.h"

/// @brief Registra un pedido dentro del array de pedidos
/// @param list
/// @param orderList
/// @param len
/// @param orderLen
/// @param id
/// @return
int createOrder(Customer* list, Order* orderList, int len, int orderLen, int* id);

/// @fn int printCustomersPendingOrders(Customer*, Locality*, Order*, int, int)
/// @brief
///
/// @param list
/// @param localityList
/// @param orderList
/// @param len
/// @param orderLen
/// @return
int printCustomersPendingOrders(Customer* list, Locality* localityList, Order* orderList, int len, int orderLen);

/// @fn int printPendingOrders(Customer*, Order*, int, int)
/// @brief
///
/// @param list
/// @param orderList
/// @param len
/// @param orderLen
/// @return
int printPendingOrders( Customer* list, Order* orderList, int len, int orderLen);

/// @fn int printCompletedOrders(Customer*, Order*, int, int)
/// @brief
///
/// @param list
/// @param orderList
/// @param len
/// @param orderLen
/// @return
int printCompletedOrders(Customer* list, Order* orderList, int len, int orderLen);

/// @fn int countOrdersStatus(int, Order*, int, int)
/// @brief
///
/// @param id
/// @param list
/// @param len
/// @param status
/// @return
int countOrdersStatus(int id, Order* list, int len, int status);

/// @fn int countCustomerOrders(int, Order*, int)
/// @brief
///
/// @param id
/// @param list
/// @param len
/// @return
int countCustomerOrders(int id, Order* list, int len);

/// @fn int searchPendingOrdersByLocality(Locality*, Order*, int, int)
/// @brief
///
/// @param list
/// @param orderList
/// @param len
/// @param orderLen
/// @return
int searchPendingOrdersByLocality(Locality* list, Order* orderList, int len, int orderLen);

/// @brief Calcula el promedio de polipropileno por cliente
/// @param list
/// @param orderList
/// @param len
/// @param orderLen
/// @param averagePolypropylenePerCustomer
/// @return Retorna -1 si hubo error o el promedio calculado si esta todo ok
int averagePolypropylenePerCustomer(Customer* list, Order* orderList, int len, int orderLen, float* averagePolypropylenePerCustomer);

/// @brief Da de alta un cliente, utilizando la funcion addCustomer, y pidiendo los datos dentro de una estructura auxiliar
/// @param list Array de clientes
/// @param len Tamanio del array
/// @param id Puntero de la variable ID, que se utilizara para autoincrementarla
/// @return Retorna -1 si hubo error o 0 si esta todo ok
int registerCustomer(Customer* list, Locality* localityList, int len, int* id);

/// @brief Pide el ingreso de un ID y mediante la busqueda por ID, si hubo match pide que se elija que cambiar, direccion o localidad
/// @param list Array de clientes
/// @param len Tamanio del array
/// @return Retorna -1 si hubo error o 0 si esta todo ok
int modifyCustomer(Customer* list, Locality* localityList, int len);

/// @brief Imprime en pantalla el listado de clientes con todos sus datos
/// @param list Array de clientes
/// @param len Tamanio del array
/// @return Retorna -1 si hubo error o 0 si esta todo ok
int printCustomers(Customer* list, Locality* localityList, int len);

/// @brief Pide el ingreso de un ID y mediante removeCustomer, pide confirmar la accion y lo "elimina" de manera logica si hubo match
/// @param list Array de clientes
/// @param len Tamanio del array
/// @return Retorna -1 si hubo error o 1 si esta todo ok o 0 si se ha cancelado la operacion
int deleteCustomer(Customer* list, Locality* localityList, int len);

/// @brief Cuenta la cantidad de pedidos segun el estado que recibe como parametro
/// @param list
/// @param orderList
/// @param len
/// @param orderLen
/// @param status
/// @return Retorna -1 si hubo error o el contador si esta todo ok
int countCompletedPendingOrders(Customer* list, Order* orderList, int len, int orderLen, int status);

#endif /* NEXUS_H_ */
