/*
 * Orders.c
 *
 *  Created on: Oct 20, 2021
 *      Author: Gonza
 */

#include "Orders.h"

int initOrders(Order* list, int len)
{
	int i;
	int retorno;

	retorno = -1;

	if(list != NULL && len > 0)
	{
		for(i = 0 ; i < len ; i++)
		{
			list[i].status = EMPTY;
		}
		retorno = 0;
	}

	return retorno;
}

int findFirstEmptyOrderPosition(Order* list, int len)
{
	int i;
	int flagFound;
	int retorno;

	i = 0;
	flagFound = FALSE;
	retorno = -1;

	while(flagFound == FALSE && i < len)
	{
		if(list[i].status == EMPTY)
		{
			flagFound = TRUE;
			retorno = i;
		}
		else
		{
			i++;
		}
	}

	return retorno;
}

int addOrder(Order* list, Order orderOne, int len, int id)
{
	int i;
	int retorno;

	retorno = -1;
	i = findFirstEmptyOrderPosition(list, len);

	if(i != -1 && len > 0 && list != NULL)
	{
		list[i] = orderOne;
		list[i].id = id + 1;
		list[i].status = PENDING;
		retorno = 0;
	}
	else
	{
		printf("Ocurrio un error a la hora de agregar la orden de recoleccion, revise los campos requeridos");
	}

	return retorno;
}

int printOrders(Order* list, int len)
{
	int i;
	int retorno;
	int pendingOrdersCounter;

	pendingOrdersCounter = 0;
	retorno = -1;

	if(list != NULL && len > 0)
	{
		pendingOrdersCounter = countOrdersByStatus(list, len, PENDING);
		if(pendingOrdersCounter > 0)
		{
			printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n ID PEDIDO        KILOS TOTALES       ID CLIENTE\n");
			for(i = 0 ; i < len ; i++)
			{
				if(list[i].status == PENDING)
				{
					printf("%6d %20d %15d\n", list[i].id, list[i].totalJunk.totalKg, list[i].idCustomer);
				}
			}
			printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
		}
		else
		{
			printf("No se han encontrado pedidos pendientes\n\n");
		}
		retorno = 0;
	}

	return retorno;
}


int findOrderById(Order* list, int len, int id)
{
	int i;
	int retorno;
	int flagFound;

	i = 0;
	retorno = -1;
	flagFound = FALSE;

	if(list != NULL && len > 0)
	{
		while(flagFound == FALSE && i < len)
		{
			if(list[i].id == id && list[i].status == PENDING)
			{
				retorno = i;
				flagFound = TRUE;
			}
			else
			{
				i++;
			}
		}
	}

	return retorno;
}

int addProcessedOrder(Order* list, TotalKg totalKg, int len, int indexOrder)
{
	int retorno;

	retorno = -1;

	if(indexOrder != -1 && len > 0 && list != NULL)
	{
		list[indexOrder].totalJunk = totalKg;
		list[indexOrder].status = COMPLETED;
		retorno = 0;
	}
	else
	{
		printf("Ocurrio un error a la hora de terminar el procesamiento, revise los campos requeridos");
	}

	return retorno;
}

int processOrder(Order* list, int len){
	int retorno;
	int id;
	int indexOrder;

	retorno = -1;

	printOrders(list, len);
	IngresarEnteroValidado("Ingrese el ID del pedido que desea procesar: ", 0, 1001, &id);
	indexOrder = findOrderById(list, len, id);
	while(indexOrder == -1)
	{
		IngresarEnteroValidado("Ingrese el ID de un pedido existente: ", 0, 1001, &id);
		indexOrder = findOrderById(list, len, id);
	}
	TotalKg totalKg = {0, 0, 0, list[indexOrder].totalJunk.totalKg};
	IngresarEnteroValidado("Ingrese la cantidad de kilos de polietileno de alta densidad procesados: ", 0, list[indexOrder].totalJunk.totalKg, &totalKg.highDensityPolyethylene);
	IngresarEnteroValidado("Ingrese la cantidad de kilos de polietileno de baja densidad procesados: ", 0, list[indexOrder].totalJunk.totalKg, &totalKg.lowDensityPolyethylene);

	while((totalKg.highDensityPolyethylene + totalKg.lowDensityPolyethylene + totalKg.polypropylene) > list[indexOrder].totalJunk.totalKg)
	{
		printf("La cantidad de kilos totales ingresados no puede ser mayor a la cantidad total de kilos declarados(%dkgs)", list[indexOrder].totalJunk.totalKg);
		IngresarEnteroValidado("\nIngrese la cantidad de kilos de polietileno de baja densidad procesados: ", 0, list[indexOrder].totalJunk.totalKg, &totalKg.lowDensityPolyethylene);
	}
	IngresarEnteroValidado("Ingrese la cantidad de kilos de polipropileno procesados: ", 0, list[indexOrder].totalJunk.totalKg, &totalKg.polypropylene);
	while((totalKg.highDensityPolyethylene + totalKg.lowDensityPolyethylene + totalKg.polypropylene) > list[indexOrder].totalJunk.totalKg)
	{
		printf("La cantidad de kilos totales ingresados no puede ser mayor a la cantidad total de kilos declarados(%dkgs)", list[indexOrder].totalJunk.totalKg);
		IngresarEnteroValidado("\nIngrese la cantidad de kilos de polipropileno procesados: ", 0, list[indexOrder].totalJunk.totalKg, &totalKg.polypropylene);
	}

	if(addProcessedOrder(list, totalKg, len, indexOrder) != -1)
	{
		retorno = 0;
	}
	else
	{
		printf("\nOcurrio un error a la hora de procesar el pedido, revise los campos requeridos");
	}

	return retorno;
}

int countOrdersByStatus(Order* list, int len, int status)
{
	int i;
	int completedOrdersCounter;

	completedOrdersCounter = 0;

	for(i = 0 ; i < len ; i++)
	{
		if(list[i].status == status)
		{
			completedOrdersCounter++;
		}
	}

	return completedOrdersCounter;
}
























