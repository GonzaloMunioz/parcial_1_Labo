/*
 * Nexus.c
 *
 *  Created on: Oct 20, 2021
 *      Author: Gonza
 */

#include "Nexus.h"

int createOrder(Customer* list, Order* orderList, int len, int orderLen, int* id)
{
	int idCustomer;
	int indexCustomer;
	int retorno;
	Order orderOne;

	retorno = -1;
	IngresarEntero("\nIngrese el ID del cliente que realizara el pedido: ", &idCustomer);
	indexCustomer = findCustomerById(list, len, idCustomer);
	while(indexCustomer == -1)
	{
		IngresarEntero("\nIngrese el ID de un cliente existente: ", &idCustomer);
		indexCustomer = findCustomerById(list, len, idCustomer);
	}

	orderOne.idCustomer = list[indexCustomer].id;
	IngresarEnteroValidado("Ingrese la cantidad de kilos totales que se recolectaran del cliente: ", 1, 30000, &orderOne.totalJunk.totalKg);

	if(addOrder(orderList, orderOne, orderLen, *id) != -1)
	{
		*id = *id + 1;
		retorno = 0;
	}
	else
	{
		printf("\nOcurrio un error a la hora de crear el pedido de recoleccion, revise los campos requeridos");
	}

	return retorno;
}

int countOrders(int id, Order* list, int len, int status)
{
	int i;
	int ordersCounter;

	ordersCounter = 0;

	for(i = 0 ; i < len ; i++)
	{
		if(status != -1)
		{
			if((list[i].idCustomer == id) && (list[i].status == status))
			{
				ordersCounter++;
			}
		}
		else
		{
			if((list[i].idCustomer == id))
			{
				ordersCounter++;
			}
		}

	}

	return ordersCounter;
}

int printCustomersPendingOrders(Customer* list, Locality* localityList, Order* orderList, int len, int orderLen)
{
	int i;
	int retorno;
	int pendingOrdersCounter;

	retorno = -1;

	if(list != NULL && len > 0)
	{
		printf("\n*************************************************************************************************\n ID          NOMBRE         DIRECCION          LOCALIDAD           CUIT       PEDIDOS PENDIENTES\n");
		for(i = 0 ; i < len ; i++)
		{
			pendingOrdersCounter = countOrders(list[i].id, orderList, orderLen, PENDING);
			if(list[i].isEmpty != TRUE)
			{
				printf("%3d %15s %17s %18s %18s %11d\n", list[i].id, list[i].companyName, list[i].address, localityList[i].locality, list[i].cuit, pendingOrdersCounter);
			}
		}
		printf("*************************************************************************************************\n");
		retorno = 0;
	}

	return retorno;
}

int printPendingOrders(Customer* list, Order* orderList, int len, int orderLen)
{
	int i;
	int retorno;
	int indexCustomer;
	int pendingOrdersCounter;

	pendingOrdersCounter = 0;
	retorno = -1;

	if(list != NULL && orderLen > 0)
	{
		pendingOrdersCounter = countOrdersByStatus(orderList, orderLen, PENDING);
		if(pendingOrdersCounter > 0)
		{
			printf("\n-------------------------------------------------------------------------\n ID PEDIDO            CUIT            DIRECCION       KILOS A RECOLECTAR\n");
			for(i = 0 ; i < orderLen ; i++)
			{
				indexCustomer = findCustomerById(list, len, orderList[i].idCustomer);
				if((orderList[i].status == PENDING) && (orderList[i].idCustomer == list[indexCustomer].id))
				{
					printf("%6d %23s %17s %16d\n", orderList[i].id, list[indexCustomer].cuit, list[indexCustomer].address, orderList[i].totalJunk.totalKg);
				}
			}
			printf("-------------------------------------------------------------------------\n");
		}
		else
		{
			printf("No se han encontrado pedidos pendientes\n");
		}

		retorno = 0;
	}

	return retorno;
}

int printCompletedOrders(Customer* list, Order* orderList, int len, int orderLen)
{
	int i;
	int retorno;
	int indexCustomer;
	int completedOrdersCounter;

	completedOrdersCounter = 0;
	retorno = -1;

	if(list != NULL && orderLen > 0)
	{
		completedOrdersCounter = countOrdersByStatus(orderList, orderLen, COMPLETED);
		if(completedOrdersCounter > 0)
		{
			printf("\n----------------------------------------------------------------------------------------------------\n ID PEDIDO            CUIT            DIRECCION       KILOS DE PAD     KILOS DE PBD     KILOS DE PP\n");
			for(i = 0 ; i < orderLen ; i++)
			{
				indexCustomer = findCustomerById(list, len, orderList[i].idCustomer);
				if((orderList[i].status == COMPLETED) && (orderList[i].idCustomer == list[indexCustomer].id))
				{
					printf("%6d %23s %17s %13d %16d %16d\n", orderList[i].id, list[indexCustomer].cuit, list[indexCustomer].address, orderList[i].totalJunk.highDensityPolyethylene, orderList[i].totalJunk.lowDensityPolyethylene, orderList[i].totalJunk.polypropylene);
				}
			}
			printf("----------------------------------------------------------------------------------------------------\n");
		}
		else
		{
			printf("No se han procesado pedidos hasta el momento\n");
		}
		retorno = 0;
	}

	return retorno;
}

int findIndexByLocality(Locality* list, char string[], int len)
{
	int i;
	int retorno;
	int flagFound;

	i = 0;
	flagFound = FALSE;
	retorno = -1;

	FormatearCadena(string);

	while((i < len) && (flagFound == FALSE))
	{
		if((strcmp(list[i].locality, string) == 0) && (list[i].isEmpty == FALSE))
		{
			retorno = i;
			flagFound = TRUE;
		}
		else
		{
			i++;
		}
	}

	return retorno;
}

int searchPendingOrdersByLocality(Locality* list, Order* orderList, int len, int orderLen)
{
	int retorno;
	int indexCustomer;
	char string[4096];
	int pendingOrdersCounter;

	retorno = -1;
	IngresarCadena("Ingrese la localidad que desea averiguar la cantidad de pedidos pendientes: ", string, 51);
	indexCustomer = findIndexByLocality(list, string, len);
	if(indexCustomer == -1)
	{
		printf("No se han registrado pedidos con esa localidad");
	}
	else
	{
		pendingOrdersCounter = countOrders(list[indexCustomer].idCustomer, orderList, orderLen, PENDING);
		if((pendingOrdersCounter > 0))
		{
			printf("La cantidad de pedidos pendientes para %s, es: %d\n", list[indexCustomer].locality, pendingOrdersCounter);
		}
		else
		{
			printf("La localidad %s, no tiene pedidos pendientes\n", list[indexCustomer].locality);
		}
		retorno = 0;
	}


	return retorno;
}

int averagePolypropylenePerCustomer(Customer* list, Order* orderList, int len, int orderLen, float* averagePolypropylenePerCustomer)
{
	int i;
	int j;
	int retorno;
	int customersCounter;
	int polypropyleneAccumulator;

	retorno = 0;
	customersCounter = 0;
	polypropyleneAccumulator = 0;

	if(averagePolypropylenePerCustomer != NULL)
	{
		for(i = 0 ; i < len ; i++)
		{
			if(list[i].isEmpty != TRUE)
			{
				customersCounter++;
			}
		}
		for(j = 0 ; j < orderLen ; j++)
		{
			polypropyleneAccumulator += orderList[j].totalJunk.polypropylene;
		}
		*averagePolypropylenePerCustomer = polypropyleneAccumulator / customersCounter;
		if(*averagePolypropylenePerCustomer > 0)
		{
			printf("El promedio de polipropileno reciclado por cliente es: %.2f\n", *averagePolypropylenePerCustomer);
		}
		else
		{
			printf("No se han procesado pedidos que contengan polipropileno por el momento");
		}
		retorno = 1;
	}

	return retorno;
}

int registerCustomer(Customer* list, Locality* localityList, int len, int* id)
{
	int retorno;
	Customer customerOne;
	Locality localityOne;

	retorno = -1;
	IngresarCadena("\nIngrese el nombre de su empresa: ", customerOne.companyName, 51);
	IngresarCadena("Ingrese su direccion: ", customerOne.address, 51);
	IngresarCadena("Ingrese su localidad: ", localityOne.locality, 51);
	addCuit(customerOne.cuit);
	localityOne.idCustomer = *id + 1;

	if((addCustomer(list, customerOne, len, *id) != -1) && (addLocality(localityList, localityOne, len) != -1))
	{
		*id = *id + 1;
		retorno = 0;
	}
	else
	{
		printf("\nOcurrio un error a la hora de dar de alta al cliente, revise los campos requeridos");
	}

	return retorno;
}

int modifyCustomer(Customer* list, Locality* localityList, int len)
{
	int id;
	int indexCustomer;
	int option;
	int retorno;

	retorno = -1;

	printCustomers(list, localityList, len);
	IngresarEntero("\nIngrese el ID del cliente que desea modificar: ", &id);
	indexCustomer = findCustomerById(list, len, id);

	if(indexCustomer != -1 && list != NULL)
	{
		IngresarEnteroValidado("1. Direccion\n2. Localidad\nIndique la opcion que desea modificar: ", 1, 2, &option);
		switch(option)
		{
			case 1:
				IngresarCadena("Ingrese su nueva direccion: ", list[indexCustomer].address, 51);
				break;

			case 2:
				IngresarCadena("Ingrese su nueva localidad: ", localityList[indexCustomer].locality, 51);
				break;

		}
		retorno = 0;
	}

	return retorno;
}

int printCustomers(Customer* list, Locality* localityList, int len)
{
	int i;
	int retorno;

	retorno = -1;

	if(list != NULL && len > 0)
	{
		printf("\n===========================================================================\n ID          NOMBRE         DIRECCION          LOCALIDAD          CUIT\n");
		for(i = 0 ; i < len ; i++)
		{
			if(list[i].isEmpty != TRUE)
			{
				printf("%3d %15s %18s %18s %16s\n", list[i].id, list[i].companyName, list[i].address, localityList[i].locality, list[i].cuit);
			}
		}
		printf("===========================================================================\n");
		retorno = 0;
	}

	return retorno;
}

int deleteCustomer(Customer* list, Locality* localityList, int len)
{
	int id;
	int retorno;
	char character;

	retorno = -1;

	if(list != NULL)
	{
		printCustomers(list, localityList, len);
		IngresarEntero("\nIngrese el ID del cliente que desea dar de baja: ", &id);
		IngresarCaracterValidado("Desea confirmar la baja del cliente?\nIndique 's' (si) o 'n' (no): ", &character, 's', 'n');
		if(character == 's')
		{
			removeCustomer(list, len, id);
			retorno = 1;
		}
		else
		{
			printf("Se ha cancelado la baja del cliente");
			retorno = 0;
		}
	}

	return retorno;
}

int countCompletedPendingOrders(Customer* list, Order* orderList, int len, int orderLen, int status)
{
	int i;
	int mostOrders;
	int mostOrdersIndex;
	int ordersCounter;
	int flag;

	flag = FALSE;

	for(i = 0 ; i < len ; i++)
	{
		ordersCounter = countOrders(list[i].id, orderList, orderLen, status);
		if((flag == 0) || ordersCounter > mostOrders)
		{
			mostOrders = ordersCounter;
			mostOrdersIndex = i;
			flag = TRUE;
		}
	}

	return mostOrdersIndex;
}

