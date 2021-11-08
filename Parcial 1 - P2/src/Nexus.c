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
	orderOne.idLocality = list[indexCustomer].idLocality;
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

int countOrders(int id, Order* list, int len, int status, int option)
{
	int i;
	int ordersCounter;

	ordersCounter = 0;

	for(i = 0 ; i < len ; i++)
	{
		if(status != -1)
		{
			if(option == 1)
			{
				if((list[i].idCustomer == id) && (list[i].status == status))
				{
					ordersCounter++;
				}
			}
			else
			{
				if((list[i].idLocality == id) && (list[i].status == status))
				{
					ordersCounter++;
				}
			}
		}
		else
		{
			if((list[i].idCustomer == id) && ((list[i].status == PENDING) || (list[i].status == COMPLETED)))
			{
				ordersCounter++;
			}
		}

	}

	return ordersCounter;
}

int printCustomersPendingOrders(Customer* list, Locality* localityList, Order* orderList, int len, int localityLen, int orderLen)
{
	int i;
	int indexLocality;
	int retorno;
	int pendingOrdersCounter;

	retorno = -1;

	if(list != NULL && len > 0)
	{
		printf("\n*************************************************************************************************\n ID          NOMBRE         DIRECCION          LOCALIDAD           CUIT       PEDIDOS PENDIENTES\n");
		for(i = 0 ; i < len ; i++)
		{
			indexLocality = findLocalityIndexById(localityList, localityLen, list[i].idLocality);
			pendingOrdersCounter = countOrders(list[i].id, orderList, orderLen, PENDING, 1);
			if(list[i].isEmpty == FALSE)
			{
				printf("%3d %15s %17s %18s %18s %11d\n", list[i].id, list[i].companyName, list[i].address, localityList[indexLocality].locality, list[i].cuit, pendingOrdersCounter);
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
					printf("%6d %24s %18s %16d\n", orderList[i].id, list[indexCustomer].cuit, list[indexCustomer].address, orderList[i].totalJunk.totalKg);
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

int searchPendingOrdersByLocality(Locality* list, Order* orderList, int len, int orderLen)
{
	int retorno;
	int indexLocality;
	int idLocality;
	int pendingOrdersCounter;

	retorno = -1;
	printLocalitys(list, len);
	IngresarEnteroValidado("Ingrese el ID de la localidad que desea averiguar la cantidad de pedidos pendientes: ", 1, 7, &idLocality);
	indexLocality = findLocalityIndexById(list, len, idLocality);
	if(indexLocality == -1)
	{
		printf("No se han registrado pedidos con esa localidad");
	}
	else
	{
		pendingOrdersCounter = countOrders(list[indexLocality].id, orderList, orderLen, PENDING, -1);
		if((pendingOrdersCounter > 0))
		{
			printf("La cantidad de pedidos pendientes para %s, es: %d\n", list[indexLocality].locality, pendingOrdersCounter);
		}
		else
		{
			printf("La localidad %s, no tiene pedidos pendientes\n", list[indexLocality].locality);
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

int registerCustomer(Customer* list, Locality* localityList, int len, int localityLen, int* id, int* idLocality, int* flagLocality)
{
	int retorno;
	Customer customerOne;

	retorno = -1;

	registerLocalitys(localityList, localityLen, idLocality, flagLocality);

	IngresarCadena("\nIngrese el nombre de su empresa: ", customerOne.companyName, 51);
	IngresarCadena("Ingrese su direccion: ", customerOne.address, 51);
	addCuit(customerOne.cuit);
	printLocalitys(localityList, localityLen);
	IngresarEnteroValidado("Ingrese el ID de su localidad: ", 1, 11, &customerOne.idLocality);

	if((addCustomer(list, customerOne, len, *id) != -1))
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

int modifyCustomer(Customer* list, Locality* localityList, int len, int localityLen)
{
	int id;
	int indexCustomer;
	int option;
	int retorno;

	retorno = -1;

	printCustomers(list, localityList, len, localityLen);
	IngresarEntero("\nIngrese el ID del cliente que desea modificar: ", &id);
	indexCustomer = findCustomerById(list, len, id);

	if(indexCustomer != -1 && list != NULL)
	{
		IngresarEnteroValidado("\n1. Direccion\n2. Localidad\nIndique la opcion que desea modificar: ", 1, 2, &option);
		switch(option)
		{
			case 1:
				IngresarCadena("Ingrese su nueva direccion: ", list[indexCustomer].address, 51);
				break;

			case 2:
				printLocalitys(localityList, localityLen);
				IngresarEnteroValidado("Ingrese el ID de su nueva localidad: ", 1, 7, &list[indexCustomer].idLocality);
				break;

		}
		retorno = 0;
	}

	return retorno;
}

int printCustomers(Customer* list, Locality* localityList, int len, int localityLen)
{
	int i;
	int indexLocality;
	int retorno;

	retorno = -1;

	if(list != NULL && len > 0)
	{
		printf("\n===========================================================================\n ID          NOMBRE         DIRECCION          LOCALIDAD          CUIT\n");
		for(i = 0 ; i < len ; i++)
		{
			indexLocality = findLocalityIndexById(localityList, localityLen, list[i].idLocality);
			if(list[i].isEmpty != TRUE)
			{
				printf("%3d %15s %18s %18s %16s\n", list[i].id, list[i].companyName, list[i].address, localityList[indexLocality].locality, list[i].cuit);
			}
		}
		printf("===========================================================================\n");
		retorno = 0;
	}

	return retorno;
}

int deleteCustomer(Customer* list, Locality* localityList, int len, int localityLen)
{
	int id;
	int retorno;
	char character;

	retorno = -1;

	if(list != NULL)
	{
		printCustomers(list, localityList, len, localityLen);
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
		ordersCounter = countOrders(list[i].id, orderList, orderLen, status, 1);
		if((flag == 0) || ordersCounter > mostOrders)
		{
			mostOrders = ordersCounter;
			mostOrdersIndex = i;
			flag = TRUE;
		}
	}

	return mostOrdersIndex;
}

int hardCodeData(Customer* list, Locality* localityList, Order* orderList, int* id, int* idOrder, int* flagRegistered, int* flagRegisteredLocalitys, int* flagCreatedOrder, int len, int localityLen, int orderLen)
{
	int option;

	Customer aux[25] =
							{{1, 1 ,"Michelin", "Dardo Rocha 4560", "20-45341896-3", FALSE},
							{2, 2, "Natura", "Mendoza 603", "20-39537923-5", FALSE},
							{3, 3, "La Serenisima", "Rivadavia 4579", "30-24677628-3", FALSE},
							{4, 4, "Coto", "Bynnon 243", "30-21578691-4", FALSE},
							{5, 5, "ChangoMas", "Lavalle 5783", "30-24545691-4", FALSE},
							{6, 6, "Macro", "Republica 1462", "20-41587991-4", FALSE},
							{7, 6, "Carrefour", "Republica 483", "20-22514691-3", FALSE},
							{8, 7, "Dia%", "Lerroux 783", "30-32652691-5", FALSE},
							{9, 5, "La Casa", "San Luis 3243", "30-34578789-3", FALSE},
							{10, 5, "YPF", "Tucuman 749", "30-22618652-4", FALSE},
							{11, 1, "Shell", "San Juan 1145", "20-45678607-3", FALSE},
							{12, 1, "Axion", "Antartida 1478", "30-22688643-3", FALSE},
							{13, 1, "Grido", "Catamarca 637", "30-30608691-4", FALSE},
							{14, 2, "La Veneciana", "La Rioja 445", "20-22577691-4", FALSE},
							{15, 2, "McDonalds", "Loria 1420", "30-35758619-5", FALSE},
							{16, 3, "Burger King", "Laprida 1456", "20-20587961-5", FALSE},
							{17, 3, "KFC", "Corrientes 794", "30-27631145-4", FALSE},
							{18, 4, "Wendy's", "Jose Verdi 1463", "30-29599682-4", FALSE},
							{19, 1, "Lacoste", "Entre Rios 974", "20-39578695-3", FALSE},
							{20, 3, "Adidas", "Gorriti 624", "30-23487681-5", FALSE},
							{21, 4, "Nike", "Las Heras 784", "30-36487125-4", FALSE},
							{22, 7, "Puma", "Ayacucho 835", "20-37587325-5", FALSE},
							{23, 7, "Penguin", "Almafuerte 151", "30-48487789-5", FALSE},
							{24, 5, "Rusty", "Mariano Boedo 965", "30-28587451-3", FALSE},
							{25, 6, "Levi's", "Gral. Frias 5624", "20-36578625-4", FALSE}};

	Locality auxLocality[7] =
							{{1, "Avellaneda", FALSE},
							{2, "Wilde", FALSE},
							{3, "Gerli", FALSE},
							{4, "Bernal", FALSE},
							{5, "Quilmes", FALSE},
							{6, "Banfield", FALSE},
							{7, "Lomas de Zamora", FALSE}};

	Order auxOrder[100] =
							{{1, 1, 1, PENDING, {0, 0, 0, 15000}},
							{2, 1, 1, PENDING, {0, 0, 0, 16000}},
							{3, 1, 1, PENDING, {0, 0, 0, 9000}},
							{4, 1, 1, PENDING, {0, 0, 0, 12000}},
							{5, 1, 1, PENDING, {0, 0, 0, 3000}},
							{6, 1, 1, COMPLETED, {3500, 3500, 8000, 15000}},
							{7, 1, 1, COMPLETED, {8000, 12000, 5000, 25000}},
							{8, 1, 1, COMPLETED, {11000, 7000, 2000, 20000}},
							{9, 1, 1, COMPLETED, {5500, 5500, 10000, 21000}},
							{10, 1, 1, COMPLETED, {7000, 2000, 1000, 10000}},
							{11, 2, 2, PENDING, {0, 0, 0, 25000}},
							{12, 2, 2, PENDING, {0, 0, 0, 17000}},
							{13, 2, 2, PENDING, {0, 0, 0, 29000}},
							{14, 2, 2, PENDING, {0, 0, 0, 21000}},
							{15, 2, 2, PENDING, {0, 0, 0, 16000}},
							{16, 2, 2, PENDING, {0, 0, 0, 4000}},
							{17, 2, 2, PENDING, {0, 0, 0, 9000}},
							{18, 2, 2, COMPLETED, {3500, 4000, 2500, 10000}},
							{19, 2, 2, COMPLETED, {2000, 3000, 3000, 8000}},
							{20, 3, 3, COMPLETED, {3500, 3500, 8000, 15000}},
							{21, 3, 3, PENDING, {0, 0, 0, 17000}},
							{22, 3, 3, PENDING, {0, 0, 0, 29000}},
							{23, 3, 3, COMPLETED, {3500, 4000, 2500, 10000}},
							{24, 3, 3, COMPLETED, {11000, 7000, 2000, 20000}},
							{25, 3, 3, COMPLETED, {2000, 3000, 3000, 8000}},
							{26, 3, 3, COMPLETED, {5500, 5500, 10000, 21000}},
							{27, 3, 3, COMPLETED, {3500, 4000, 2500, 10000}},
							{28, 3, 3, COMPLETED, {2000, 3000, 3000, 8000}},
							{29, 4, 4, PENDING, {0, 0, 0, 16000}},
							{30, 4, 4, PENDING, {0, 0, 0, 9000}},
							{31, 4, 4, PENDING, {0, 0, 0, 12000}},
							{32, 4, 4, COMPLETED, {7000, 2000, 1000, 10000}},
							{33, 5, 5, COMPLETED, {11000, 7000, 2000, 20000}},
							{34, 5, 5, COMPLETED, {5500, 5500, 10000, 21000}},
							{35, 5, 5, COMPLETED, {7000, 2000, 1000, 10000}},
							{36, 5, 5, COMPLETED, {3500, 3500, 8000, 15000}},
							{37, 5, 5, PENDING, {0, 0, 0, 17000}},
							{38, 6, 6, PENDING, {0, 0, 0, 16000}},
							{39, 6, 6, PENDING, {0, 0, 0, 9000}},
							{40, 6, 6, PENDING, {0, 0, 0, 12000}},
							{41, 6, 6, COMPLETED, {7000, 2000, 1000, 10000}},
							{42, 7, 6, COMPLETED, {11000, 7000, 2000, 20000}},
							{43, 7, 6, COMPLETED, {5500, 5500, 10000, 21000}},
							{44, 7, 6, COMPLETED, {7000, 2000, 1000, 10000}},
							{45, 7, 6, COMPLETED, {3500, 3500, 8000, 15000}},
							{46, 7, 6, PENDING, {0, 0, 0, 17000}},
							{47, 7, 6, PENDING, {0, 0, 0, 16000}},
							{48, 8, 7, PENDING, {0, 0, 0, 16000}},
							{49, 8, 7, PENDING, {0, 0, 0, 9000}},
							{50, 8, 7, PENDING, {0, 0, 0, 12000}},
							{51, 8, 7, COMPLETED, {7000, 2000, 1000, 10000}},
							{52, 9, 5, COMPLETED, {5500, 5500, 10000, 21000}},
							{53, 9, 5, COMPLETED, {3500, 4000, 2500, 10000}},
							{54, 9, 5, COMPLETED, {2000, 3000, 3000, 8000}},
							{55, 9, 5, PENDING, {0, 0, 0, 16000}},
							{56, 9, 5, PENDING, {0, 0, 0, 9000}},
							{57, 10, 5, PENDING, {0, 0, 0, 16000}},
							{58, 10, 5, PENDING, {0, 0, 0, 9000}},
							{59, 10, 5, PENDING, {0, 0, 0, 12000}},
							{60, 10, 5, COMPLETED, {7000, 2000, 1000, 10000}},
							{61, 11, 1, COMPLETED, {11000, 7000, 2000, 20000}},
							{62, 11, 1, COMPLETED, {5500, 5500, 10000, 21000}},
							{63, 11, 1, COMPLETED, {7000, 2000, 1000, 10000}},
							{64, 11, 1, COMPLETED, {3500, 3500, 8000, 15000}},
							{65, 11, 1, PENDING, {0, 0, 0, 17000}},
							{66, 12, 1, PENDING, {0, 0, 0, 16000}},
							{67, 12, 1, PENDING, {0, 0, 0, 9000}},
							{68, 12, 1, PENDING, {0, 0, 0, 12000}},
							{69, 12, 1, COMPLETED, {7000, 2000, 1000, 10000}},
							{70, 13, 1, COMPLETED, {11000, 7000, 2000, 20000}},
							{71, 13, 1, COMPLETED, {5500, 5500, 10000, 21000}},
							{72, 13, 1, COMPLETED, {7000, 2000, 1000, 10000}},
							{73, 13, 1, COMPLETED, {3500, 3500, 8000, 15000}},
							{74, 13, 1, PENDING, {0, 0, 0, 17000}},
							{75, 13, 1, PENDING, {0, 0, 0, 16000}},
							{76, 14, 2, PENDING, {0, 0, 0, 16000}},
							{77, 14, 2, PENDING, {0, 0, 0, 9000}},
							{78, 14, 2, PENDING, {0, 0, 0, 12000}},
							{79, 14, 2, COMPLETED, {7000, 2000, 1000, 10000}},
							{80, 15, 2, COMPLETED, {5500, 5500, 10000, 21000}},
							{81, 15, 2, COMPLETED, {3500, 4000, 2500, 10000}},
							{82, 15, 2, COMPLETED, {2000, 3000, 3000, 8000}},
							{83, 15, 2, PENDING, {0, 0, 0, 16000}},
							{84, 15, 2, PENDING, {0, 0, 0, 9000}},
							{85, 16, 3, COMPLETED, {7000, 2000, 1000, 10000}},
							{86, 16, 3, COMPLETED, {11000, 7000, 2000, 20000}},
							{87, 16, 3, COMPLETED, {5500, 5500, 10000, 21000}},
							{88, 16, 3, COMPLETED, {7000, 2000, 1000, 10000}},
							{89, 16, 3, COMPLETED, {3500, 3500, 8000, 15000}},
							{90, 16, 3, PENDING, {0, 0, 0, 17000}},
							{91, 16, 3, PENDING, {0, 0, 0, 16000}},
							{92, 17, 3, PENDING, {0, 0, 0, 16000}},
							{93, 17, 3, PENDING, {0, 0, 0, 9000}},
							{94, 17, 3, PENDING, {0, 0, 0, 12000}},
							{95, 17, 3, COMPLETED, {7000, 2000, 1000, 10000}},
							{96, 18, 4, COMPLETED, {5500, 5500, 10000, 21000}},
							{97, 18, 4, COMPLETED, {3500, 4000, 2500, 10000}},
							{98, 18, 4, COMPLETED, {2000, 3000, 3000, 8000}},
							{99, 18, 4, PENDING, {0, 0, 0, 16000}},
							{100, 18, 4, PENDING, {0, 0, 0, 9000}}};

	IngresarEnteroValidado("\nQue datos desea hardcodear?\n 1) Clientes\n 2) Localidades\n 3) Pedidos\n 4) Todo\nIndique: ", 1, 4, &option);
	switch(option)
	{
		case 1:
			for(int i = 0; i < 25; i++)
			{
				list[i] = aux[i];
			}
			*flagRegistered = 1;
			*id = list[24].id;
			break;

		case 2:
			for(int i = 0; i < localityLen; i++)
			{
				localityList[i] = auxLocality[i];
			}
			*flagRegisteredLocalitys = 1;
			break;

		case 3:
			for(int i = 0; i < 100; i++)
			{
				orderList[i] = auxOrder[i];
			}
			*flagCreatedOrder = 1;
			break;

		case 4:
			for(int i = 0; i < 25; i++)
			{
				list[i] = aux[i];
			}
			for(int i = 0; i < localityLen; i++)
			{
				localityList[i] = auxLocality[i];
			}
			for(int i = 0; i < 100; i++)
			{
				orderList[i] = auxOrder[i];
			}
			*flagRegistered = 1;
			*flagRegisteredLocalitys = 1;
			*flagCreatedOrder = 1;
			*id = list[24].id;
			*idOrder = orderList[99].id;
			break;
	}

	return 0;
}










