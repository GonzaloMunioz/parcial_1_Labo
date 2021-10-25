/*
 * Customers.c
 *
 *  Created on: Oct 5, 2021
 *      Author: Gonza
 */

#include "Customers.h"

int initCustomers(Customer* list, int len)
{
	int i;
	int retorno;

	retorno = -1;

	if(list != NULL && len > 0)
	{
		for(i = 0 ; i < len ; i++)
		{
			list[i].isEmpty = TRUE;
		}
		retorno = 0;
	}

	return retorno;
}

int findFirstEmptyPosition(Customer* list, int len)
{
	int i;
	int flagFound;
	int retorno;

	i = 0;
	flagFound = FALSE;
	retorno = -1;

	while(flagFound == FALSE && i < len)
	{
		if(list[i].isEmpty == TRUE)
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

int addCustomer(Customer* list, Customer customerOne, int len, int id)
{
	int i;
	int retorno;

	retorno = -1;
	i = findFirstEmptyPosition(list, len);
	FormatearCadena(customerOne.companyName);
	FormatearCadena(customerOne.address);

	if(i != -1 && len > 0 && list != NULL)
	{
		list[i] = customerOne;
		list[i].id = id + 1;
		list[i].isEmpty = FALSE;
		retorno = 0;
	}
	else
	{
		printf("Ocurrio un error a la hora de agregar al cliente, revise los campos requeridos");
	}

	return retorno;
}

int findCustomerById(Customer* list, int len, int id)
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
			if(list[i].id == id && list[i].isEmpty != TRUE)
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

int removeCustomer(Customer* list, int len, int id)
{
	int i;
	int retorno;

	retorno = -1;

	i = findCustomerById(list, len, id);

	if(i != -1 && len > 0 && list != NULL)
	{
		list[i].isEmpty = TRUE;
	}

	return retorno;
}



int addCuit(char* cuit)
{
	int i;
	int j;
	int retorno;
	char stringCuit[4096];

	j = 0;
	retorno = 0;

	if(cuit != NULL)
	{
		IngresarCadena("Ingrese su C.U.I.T. (sin espacios ni guiones): ", stringCuit, 11);
		while((ValidarNumero(stringCuit) == 0) || (strlen(stringCuit) != 11))
		{
			IngresarCadena("Ingrese un C.U.I.T. valido de 11 digitos (sin espacios ni guiones, por favor): ", stringCuit, 11);
		}
		for(i = 0 ; i <= 13 ; i++)
		{
			if(i != 2 && i != 11)
			{
				cuit[i] = stringCuit[j];
				j++;
			}
			else
			{
				cuit[i] = '-';
			}
		}
		retorno = 1;
	}

	return retorno;
}
