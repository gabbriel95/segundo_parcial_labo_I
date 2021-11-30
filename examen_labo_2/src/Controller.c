#include <stdio.h>
#include <stdlib.h>

#include "Ebook.h"
#include "LinkedList.h"
#include "parser.h"
#include "Utn.h"

void controller_mostrarUnLibro(LinkedList* pArrayListBooks,int id);


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListBooks)
{
	FILE* archivoDatos = fopen(path, "r+");
	int retorno = -1;

	if(archivoDatos != NULL && pArrayListBooks != NULL)
	{
		retorno = 1;
		ll_clear(pArrayListBooks);

		parser_EmployeeFromText(archivoDatos, pArrayListBooks);
		puts("\nModo texto cargado correctamente\n");

	}
	else
	{
		puts("\nNo se pudo realizar la carga\n");
	}

	fclose(archivoDatos);
    return retorno;
}



/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListBooks(LinkedList* pArrayListBooks)
{
	int retorno = -1;
	int tamanioLista = ll_len(pArrayListBooks);
	char id[20] = "Id";
	char titulo[20] = "Titulo";
	char autor[20] = "Autor";
	char precio[20] = "Precio";
	char editorial[20] = "Editorial";


	if(ll_isEmpty(pArrayListBooks) == 0)
	{
		if(pArrayListBooks != NULL)
		{
			printf("%5s %35s %40s %20s %15s\n",id,titulo,autor,precio, editorial);
			for(int i=0; i<tamanioLista; i++)
			{
				controller_mostrarUnLibro(pArrayListBooks,i);
				retorno = 1;
			}
		}
	}
	else
	{
		puts("Primero cargue una lista\n");
	}

    return retorno;
}

/// @brief Muestra un empleado
/// @param pArrayListEmployee
/// @param id
void controller_mostrarUnLibro(LinkedList* pArrayListBooks,int id)
{
	//FUNCA BIEN
	Ebook* pEmpleado;
	int auxId = 0;
	int auxIdEditorial =0;

	char auxName[51];
	char autor[51];
	int auxPrecio = 0;

	if(pArrayListBooks != NULL)
	{
		pEmpleado = ll_get(pArrayListBooks, id);

		if(pEmpleado != NULL)
		{
			auxId = ebook_getId(pEmpleado);
			ebook_getNombreAutor(pEmpleado, autor);
			ebook_getNombre(pEmpleado, auxName);
			ebook_getPrecio(pEmpleado,&auxPrecio);
			auxIdEditorial = ebook_getIdEditorial(pEmpleado);
			printf("%5d %40s %40s %15d  %10d\n", auxId, auxName, autor, auxPrecio, auxIdEditorial);
		}

	}
}



/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEbook(LinkedList* pArrayListBooks)
{
	int retorno = -1;

	if(ll_isEmpty(pArrayListBooks) == 0)
	{
		if(pArrayListBooks != NULL)
		{
			puts("\n Este proceso puede tardar bastante tiempo, por favor tenga paciencia\n");
			retorno = 1;
			ll_sort(pArrayListBooks, ebook_CompareByName, 1);
			puts("\nOrdenamiento completado");

		}

	}
	else
	{
		puts("Primero cargue una lista\n");
	}

    return retorno;
}


int filtrarEditoriales(void* parametro)
{
	int retorno = 0;
	Ebook* auxEditorial;

	if(parametro != NULL)
	{
		auxEditorial = (Ebook*) parametro;
		if(auxEditorial->idEditorial == 4)
		{
			retorno = 1;
		}
	}

	return retorno;
}

int contadorDeAlgo(void* parametro)
{
	int retorno = 0;
	Ebook* auxEditorial;

	if(parametro != NULL)
	{
		auxEditorial = (Ebook*) parametro;
		if(auxEditorial->idEditorial == 4)
		{
			retorno = 1;
		}
	}

	return retorno;
}

int controller_Contador(LinkedList* this)
{
	int retorno = 0;

	retorno = ll_count(this, contadorDeAlgo);

	return retorno;
}


LinkedList* controller_ListaEditoriales(LinkedList* this)
{
	LinkedList* listaEditoriales;

	if(this!= NULL)
	{
		listaEditoriales = ll_filter(this, filtrarEditoriales);

	}

	return listaEditoriales;
}

int controller_saveAsText(char* path, LinkedList* pArrayList)
{
	FILE* pArchivo;
	int retorno = -1;
	int id;
	int auxPrecio;
	int auxIdEditorial;
	char nombre[51];
	char nombreAutor[51];
	int tamLista = ll_len(pArrayList);
	Ebook* auxEbook;
	pArchivo = fopen(path,"w");

	if(ll_isEmpty(pArrayList) == 0)
	{
		if(pArchivo != NULL)
		{
			for(int i=0; i<tamLista; i++)
			{
				auxEbook = (Ebook*) ll_get(pArrayList, i);

				if(auxEbook != NULL)
				{
					id = ebook_getId(auxEbook);
					ebook_getNombre(auxEbook, nombre);
					ebook_getNombreAutor(auxEbook, nombreAutor);
					ebook_getPrecio(auxEbook, &auxPrecio);
					auxIdEditorial = ebook_getIdEditorial(auxEbook);
					fprintf(pArchivo, "%d,%s,%s,%d,%d\n", id, nombre, nombreAutor, auxPrecio, auxIdEditorial);
				}

			}
				ll_clear(pArrayList);
				puts("\n Exito al guardar en modo texto\n");
				retorno = 1;
				fclose(pArchivo);
		}
		else
		{
			puts("\n No se pudo abrir el archivo\n");
		}

	}
	else
	{
		puts("Primero cargue una lista\n");
	}
    return retorno;

	return 0;
}


//HASTA ACA BIEN


