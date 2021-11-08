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
/// @param list Array de clientes
/// @param orderList Array de pedidos
/// @param len Tamanio array clientes
/// @param orderLen Tamanio array pedidos
/// @param id ID que utilizaremos para asignar y aumentar automaticamente en cada pedido
/// @return Retorna -1 si hubo error o 0 si esta todo ok
int createOrder(Customer* list, Order* orderList, int len, int orderLen, int* id);

/// @brief Imprime un listado de los clientes con la cantidad de pedidos pendientes que tiene
/// @param list Array de clientes
/// @param localityList Array de localidades
/// @param orderList Array de pedidos
/// @param len Tamanio array clientes
/// @param localityLen Tamanio array localidades
/// @param orderLen Tamanio array pedidos
/// @return Retorna -1 si hubo error o 0 si esta todo ok
int printCustomersPendingOrders(Customer* list, Locality* localityList, Order* orderList, int len, int localityLen, int orderLen);

/// @brief Imprime un listado de pedidos pendientes, si es que hay
/// @param list Array de clientes
/// @param orderList Array de pedidos
/// @param len Tamanio array clientes
/// @param orderLen Tamanio array pedidos
/// @return Retorna -1 si hubo error o 0 si esta todo ok
int printPendingOrders(Customer* list, Order* orderList, int len, int orderLen);

/// @brief Imprime un listado de pedidos completados, si es que hay, con la cantidad de kg de cada tipo de basura procesado
/// @param list Array de clientes
/// @param orderList Array de pedidos
/// @param len Tamanio array clientes
/// @param orderLen Tamanio array pedidos
/// @return Retorna -1 si hubo error o 0 si esta todo ok
int printCompletedOrders(Customer* list, Order* orderList, int len, int orderLen);

/// @brief Nos permite buscar segun una localidad la cantidad de pedidos pendientes
/// @param list Array de localidades
/// @param orderList Array de pedidos
/// @param len Tamanio array localidades
/// @param orderLen Tamanio array pedidos
/// @return Retorna El contador de pedidos segun la localidad ingresada o -1 si hubo error
int searchPendingOrdersByLocality(Locality* list, Order* orderList, int len, int orderLen);

/// @brief Calcula el promedio de polipropileno por cliente
/// @param list Array de clientes
/// @param orderList Array de pedidos
/// @param len Tamanio array clientes
/// @param orderLen Tamanio array pedidos
/// @param averagePolypropylenePerCustomer Promedio calculado segun la division de kgs de polipropileno sobre la cantidad total de clientes
/// @return Retorna -1 si hubo error o el promedio calculado si esta todo ok
int averagePolypropylenePerCustomer(Customer* list, Order* orderList, int len, int orderLen, float* averagePolypropylenePerCustomer);

/// @brief Da de alta un cliente, utilizando la funcion addCustomer, y pidiendo los datos dentro de una estructura auxiliar
/// @param list Array de clientes
/// @param len Tamanio del array
/// @param id Puntero de la variable ID, que se utilizara para autoincrementarla
/// @return Retorna -1 si hubo error o 0 si esta todo ok
int registerCustomer(Customer* list, Locality* localityList, int len, int localityLen, int* id, int* idLocality, int* flagLocality);

/// @brief Pide el ingreso de un ID y mediante la busqueda por ID, si hubo match pide que se elija que cambiar, direccion o localidad
/// @param list Array de clientes
/// @param len Tamanio del array
/// @return Retorna -1 si hubo error o 0 si esta todo ok
int modifyCustomer(Customer* list, Locality* localityList, int len, int localityLen);

/// @brief Imprime en pantalla el listado de clientes con todos sus datos
/// @param list Array de clientes
/// @param len Tamanio del array
/// @return Retorna -1 si hubo error o 0 si esta todo ok
int printCustomers(Customer* list, Locality* localityList, int len, int localityLen);

/// @brief Pide el ingreso de un ID y mediante removeCustomer, pide confirmar la accion y lo "elimina" de manera logica si hubo match
/// @param list Array de clientes
/// @param len Tamanio del array
/// @return Retorna -1 si hubo error o 1 si esta todo ok o 0 si se ha cancelado la operacion
int deleteCustomer(Customer* list, Locality* localityList, int len, int localityLen);

/// @brief Cuenta la cantidad de pedidos segun el estado que recibe como parametro
/// @param list Array de clientes
/// @param orderList Array de pedidos
/// @param len Tamanio array clientes
/// @param orderLen Tamanio array pedidos
/// @param status Nos permite especificar el estado del pedido que nos interesa contar, PENDING para pendiente, COMPLETED para completado y -1 para general
/// @return Retorna -1 si hubo error o el contador si esta todo ok
int countCompletedPendingOrders(Customer* list, Order* orderList, int len, int orderLen, int status);

/// @brief Nos permite hardcodear, dentro de cada array una cierta cantidad de datos pre-establecidos para acelerar los testeos
/// @param list Array de clientes
/// @param localityList Array de localidades
/// @param flagRegistered Bandera de alta cliente
/// @param flagRegisteredLocalitys Bandera de alta localidad
/// @param len Tamanio array clientes
/// @param localityLen Tamanio array localidades
/// @return Retorna 0
int hardCodeData(Customer* list, Locality* localityList, Order* orderList, int* id, int* idOrder, int* flagRegistered, int* flagRegisteredLocalitys, int* flagCreatedOrder, int len, int localityLen, int orderLen);

#endif /* NEXUS_H_ */
