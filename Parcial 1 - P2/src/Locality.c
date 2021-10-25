/*
 * Locality.c
 *
 *  Created on: Oct 22, 2021
 *      Author: Gonza
 */

#include "Locality.h"

int initLocality(Locality* list, int len)
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

int findFirstEmptyLocalityPosition(Locality* list, int len)
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

int addLocality(Locality* list, Locality localityOne, int len)
{
	int i;
	int retorno;

	retorno = -1;
	i = findFirstEmptyLocalityPosition(list, len);
	FormatearCadena(localityOne.locality);
	if(i != -1 && len > 0 && list != NULL)
	{
		list[i] = localityOne;
		list[i].isEmpty = FALSE;
		retorno = 0;
	}
	else
	{
		printf("Ocurrio un error a la hora de agregar la orden de recoleccion, revise los campos requeridos");
	}

	return retorno;
}

