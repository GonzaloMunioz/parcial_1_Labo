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
	if((i != -1))
	{
		list[i] = localityOne;
		list[i].isEmpty = FALSE;
		retorno = 0;
	}
	else
	{
		printf("Ocurrio un error a la hora de agregar la localidad, revise los campos requeridos");
	}

	return retorno;
}

int registerLocalitys(Locality* localityList, int len, int* id, int* flagLocality)
{
	int retorno;
	Locality localityOne;

	retorno = -1;

	if((*flagLocality == 0) && (len > 0) && (localityList != NULL))
	{
		printf("\nPrimero se deben ingresar 7 localidades \n\n");
		for(int i = 0; i < len; i++)
		{
			IngresarCadena(" -Ingrese el nombre de su localidad: ", localityOne.locality, 51);
			FormatearCadena(localityOne.locality);
			localityOne.id = *id + 1;

			if((addLocality(localityList, localityOne, len) != -1))
			{
				*id = *id + 1;
				*flagLocality = 1;
				retorno = 1;
			}
			else
			{
				printf("\nOcurrio un error a la hora de registrar la localidad, revise los campos requeridos");
			}
		}
	}
	else
	{
		retorno = 0;
	}

	return retorno;
}

int printLocalitys(Locality* localityList, int len)
{
	int i;
	int retorno;

	retorno = -1;

	if(localityList != NULL && len > 0)
	{
		printf("\n==========================\n  ID          LOCALIDAD\n");
		for(i = 0 ; i < len ; i++)
		{
			if(localityList[i].isEmpty != TRUE)
			{
				printf("%4d %18s\n", localityList[i].id, localityList[i].locality);
			}
		}
		printf("==========================\n");
		retorno = 0;
	}

	return retorno;
}

int findLocalityIndexById(Locality* list, int len, int id)
{
	int i;
	int flagFound;
	int retorno;

	i = 0;
	flagFound = 0;
	retorno = -1;

	while((i < len) && (flagFound == 0))
	{
		if(list[i].id == id)
		{
			retorno = i;
			flagFound = 1;
		}
		else
		{
			i++;
		}
	}

	return retorno;
}



