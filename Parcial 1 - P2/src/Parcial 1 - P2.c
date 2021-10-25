/*
 ============================================================================
 Name        : Parcial.c
 Author      : Gonzalo Munioz
 Description : Segunda parte del parcial de laboratorio I
 ============================================================================
 */

#include "Nexus.h"

int main(void) {
	setbuf(stdout, NULL);

	int seguir;
	int id;
	int idOrder;
	int flagRegistered;
	int flagCreatedOrder;
	float averagePolypropylene;
	int mostPendingOrders;
	int mostCompletedOrders;
	int mostOrders;
	Customer arrayCustomers[TAM]; //= {{1 ,"Michelin", "Rafael Calzada", "Dardo Rocha 3455", "20-44361856-3", FALSE}, {2, "Natura", "Jose Marmol", "Mendoza 892", "20-39487913-5", FALSE}, {3, "La Serenisima", "Lomas de Zamora", "Rivadavia 3844", "30-24347618-3", FALSE}, {4, "Coto", "Adrogue", "Bynnon 243", "30-21578691-4", FALSE}};
	Locality arrayLocalitys[TAM];
	Order arrayOrders[T]; //= {{1, 1, PENDING, {0, 0, 0, 15000}}, {2, 2, PENDING, {0, 0, 0, 8000}}, {3, 2, PENDING, {0, 0, 0, 12000}}, {4, 2, PENDING, {0, 0, 0, 23000}}, {5, 1, COMPLETED, {4500, 3000, 7500, 0}}, {6, 2, COMPLETED, {8000, 4000, 3500, 0}}};

	id = 0;
	idOrder = 0;
	seguir = 0;
	flagRegistered = 1;
	flagCreatedOrder = 1;
	averagePolypropylene = 0;
	initCustomers(arrayCustomers, TAM);
	initLocality(arrayLocalitys, TAM);
	initOrders(arrayOrders, T);

	do
	{
		IngresarEnteroValidado("\n1) ALTA cliente:\n2) MODIFICAR cliente:\n3) BAJA cliente:\n4) CREAR PEDIDO de recoleccion:\n5) PROCESAR residuos:\n6) IMPRIMIR listado de clientes:"
				"\n7) IMPRIMIR pedidos pendientes:\n8) IMPRIMIR pedidos procesados:\n9) INFORMAR cantidad de pedidos segun localidad ingresada:"
				"\n10) INFORMAR cantidad de kilos de polipropileno reciclado promedio por cliente:\n11) INFORMAR: \n\t- CLIENTE con mas pedidos pendientes"
				"\n\t- CLIENTE con mas pedidos completados\n\t- CLIENTE con mas pedidos realizados\n0) SALIR: \n\nIndique la opcion deseada: ", 0, 11, &seguir);
		switch(seguir)
		{
			case 1:
				if(registerCustomer(arrayCustomers, arrayLocalitys, TAM, &id) == -1)
				{
					printf("Ocurrio un error con el alta del cliente, revise los campos requeridos\n");
				}
				else
				{
					printf("El cliente fue dado de alta con exito. Su id es: %d\n", id);
					flagRegistered = 1;
				}

				break;

			case 2:
				if(flagRegistered == 1)
				{
					if(modifyCustomer(arrayCustomers, arrayLocalitys, TAM) == -1)
					{
						printf("Ocurrio un error con la modificacion del cliente, revise los campos requeridos\n");
					}
					else
					{
						printf("El cliente fue modificado con exito\n");
					}
				}
				else
				{
					printf("Primero debe dar de alta al menos un cliente\n");
				}

				break;

			case 3:
				if(flagRegistered == 1)
				{
					if(deleteCustomer(arrayCustomers, arrayLocalitys, TAM) == 1)
					{
						printf("El cliente fue dado de baja con exito\n");
					}
				}
				else
				{
					printf("Primero debe dar de alta al menos un cliente\n");
				}

				break;

			case 4:
				if(flagRegistered == 1)
				{
					if(printCustomers(arrayCustomers, arrayLocalitys, TAM) == -1)
					{
						printf("Ocurrio un error a la hora de mostrar el listado de clientes, revise los campos requeridos\n");
					}
					else
					{
						if(createOrder(arrayCustomers, arrayOrders, TAM, T, &idOrder) != -1)
						{
							printf("Se ha creado exitosamente el pedido de recoleccion\n");
							flagCreatedOrder = 1;
						}
						else
						{
							printf("Ocurrio un error con la creacion del pedido, revise los campos requeridos\n");
						}
					}
				}
				else
				{
					printf("Primero debe dar de alta al menos un cliente\n");
				}

				break;

			case 5:
				if(flagRegistered == 1 && flagCreatedOrder == 1)
				{
					if(processOrder(arrayOrders, T) == -1)
					{
						printf("Ocurrio un error a la hora de procesar el pedido, revise los campos requeridos\n");
					}
					else
					{
						printf("Se ha procesado exitosamente el pedido de recoleccion\n");
					}
				}
				else
				{
					printf("Primero debe dar de alta al menos un cliente y/o pedido\n");
				}

				break;

			case 6:
				if(flagRegistered == 1)
				{
					if(printCustomersPendingOrders(arrayCustomers, arrayLocalitys, arrayOrders, TAM, T) == -1)
					{
						printf("Ocurrio un error a la hora de mostrar el listado, revise los campos requeridos\n");
					}
				}
				else
				{
					printf("Primero debe dar de alta al menos un cliente\n");
				}

				break;

			case 7:
				if(flagRegistered == 1 && flagCreatedOrder == 1)
				{
					if(printPendingOrders(arrayCustomers, arrayOrders, TAM, T) == -1)
					{
						printf("Ocurrio un error a la hora de mostrar el listado de pedidos pendientes, revise los campos requeridos\n");
					}
				}
				else
				{
					printf("Primero debe dar de alta al menos un cliente y/o pedido\n");
				}

				break;

			case 8:
				if(flagRegistered == 1 && flagCreatedOrder == 1)
				{
					if(printCompletedOrders(arrayCustomers, arrayOrders, TAM, T) == -1)
					{
						printf("Ocurrio un error a la hora de mostrar el listado de pedidos completados, revise los campos requeridos\n");
					}
				}
				else
				{
					printf("Primero debe dar de alta al menos un cliente y/o pedido\n");
				}

				break;

			case 9:
				if(flagRegistered == 1 && flagCreatedOrder == 1)
				{
					if(searchPendingOrdersByLocality(arrayLocalitys, arrayOrders, TAM, T) == -1)
					{
						printf("Ocurrio un error a la hora de buscar la cantidad de pedidos pendientes, revise los campos requeridos\n");
					}
				}
				else
				{
					printf("Primero debe dar de alta al menos un cliente y/o pedido\n");
				}

				break;

			case 10:
				if(flagRegistered == 1 && flagCreatedOrder == 1)
				{
					if(averagePolypropylenePerCustomer(arrayCustomers, arrayOrders, TAM, T, &averagePolypropylene) == -1)
					{
						printf("Ocurrio un error a la hora de calcular el promedio de polipropileno , revise los campos requeridos\n");
					}
				}
				else
				{
					printf("Primero debe dar de alta al menos un cliente y/o pedido\n");
				}

				break;

			case 11:
				mostPendingOrders = countCompletedPendingOrders(arrayCustomers, arrayOrders, TAM, T, PENDING);
				mostCompletedOrders = countCompletedPendingOrders(arrayCustomers, arrayOrders, TAM, T, COMPLETED);
				mostOrders = countCompletedPendingOrders(arrayCustomers, arrayOrders, TAM, T, -1);
				printf("La empresa con mas pedidos pendientes es: %s\n", arrayCustomers[mostPendingOrders].companyName);
				printf("La empresa con mas pedidos completados es: %s\n", arrayCustomers[mostCompletedOrders].companyName);
				printf("La empresa con mas pedidos realizados es: %s\n", arrayCustomers[mostOrders].companyName);
				break;
		}
	}
	while(seguir != 0);

	return EXIT_SUCCESS;
}



























