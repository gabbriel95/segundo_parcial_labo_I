#include <stdio.h>
#include <stdlib.h>

#include "Ebook.h"
#include "LinkedList.h"


int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int output = -1;
	char bufferId[1024];
	char bufferNombre[1024];
	char bufferHsTrabajadas[1024];
	char bufferSueldo[1024];
	char bufferEditorial[1000];
	Ebook* pEmployee;
	int respuesta;

	if(pFile != NULL && pArrayListEmployee != NULL)
	{
		fscanf(pFile, "%[^,],%[^,],%[^,], %[^,], %[^\n]\n", bufferId, bufferNombre, bufferHsTrabajadas, bufferSueldo, bufferEditorial);
		do
		{
			respuesta = fscanf(pFile, "%[^,],%[^,],%[^,], %[^,], %[^\n]\n", bufferId, bufferNombre, bufferHsTrabajadas, bufferSueldo, bufferEditorial);

			if(respuesta == 5 && pEmployee != NULL)
			{
				pEmployee = book_newParametros(bufferId, bufferNombre, bufferHsTrabajadas, bufferSueldo, bufferEditorial);
				if(pEmployee != NULL)
				{
					ll_add(pArrayListEmployee, pEmployee);
					//0 = ok
				}
			}

			/*else
			{
				break;
			}*/

		}while(!feof(pFile));

	}

	//fclose(pFile);
    return output;
}
