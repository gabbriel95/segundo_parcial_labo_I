#include "Ebook.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Utn.h"



Ebook* ebook_new()
{
	Ebook* this = (Ebook*) malloc(sizeof(Ebook));

	if(this != NULL)
	{
		return this;
	}
	else
	{
		puts("\n No se pudo asignar espacio en memoria");
		exit(0);
	}


}


int ebook_setId(Ebook* this, int id)
{
	int retorno = -1;

	if(this != NULL)
	{
		this->id = id;
		retorno = 1;
	}

	return retorno;
}

int ebook_getId(Ebook* this)
{
	int retorno = -1;
	if(this != NULL)
	{
		retorno = this->id;
	}

	return retorno;

}

int ebook_setIdEditorial(Ebook* this, int id)
{
	int retorno = -1;

	if(this != NULL)
	{
		this->idEditorial = id;
		retorno = 1;
	}

	return retorno;
}

int ebook_getIdEditorial(Ebook* this)
{
	int retorno = -1;
	if(this != NULL)
	{
		retorno = this->idEditorial;
	}

	return retorno;

}

int ebook_setPrecio(Ebook* this, int precio)
{
	int setea = -1;

	if(this != NULL)
	{
		this->precio = precio;
		setea = 0;
	}

	return setea;
}

int ebook_getPrecio(Ebook* this, int* precio)
{
	int retorno = -1;
	if(this != NULL)
	{
		*precio = this->precio;
		retorno  = 0;
	}

	return retorno;
}


int ebook_setNombre(Ebook* this, char* nombre)
{
	int retorno = -1;

	if(this != NULL && nombre != NULL)
	{
		strcpy(this->nombre, nombre);
		retorno = 0;
	}

	return retorno;
}

int ebook_getNombre(Ebook* this, char* nombre)
{
	int retorno = -1;

	if(this != NULL && nombre != NULL)
	{
		strcpy(nombre, this->nombre);
		retorno  = 0;
	}
	return retorno;
}

int ebook_setNombreAutor(Ebook* this, char* nombre)
{
	int retorno = -1;

	if(this != NULL && nombre != NULL)
	{
		strcpy(this->autor, nombre);
		retorno = 0;
	}

	return retorno;
}

int ebook_getNombreAutor(Ebook* this, char* nombre)
{
	int retorno = -1;

	if(this != NULL && nombre != NULL)
	{
		strcpy(nombre, this->autor);
		retorno  = 0;
	}
	return retorno;
}

Ebook* book_newParametros(char* idStr,char* tituloStr,char* autorStr, char* precioStr, char* idEditorialStr)
{
	int id;
	int sueldo;
	int idEditorial;

	Ebook* auxEmpleado;

	if(idStr != NULL && tituloStr != NULL && autorStr != NULL && precioStr != NULL && idEditorialStr != NULL)
	{
		id = atoi(idStr);
		sueldo = atoi(precioStr);
		idEditorial = atoi(idEditorialStr);
		auxEmpleado = ebook_new();

		if(auxEmpleado != NULL)
		{
			ebook_setId(auxEmpleado, id);
			ebook_setNombre(auxEmpleado, tituloStr);
			ebook_setPrecio(auxEmpleado, sueldo);
			ebook_setNombreAutor(auxEmpleado, autorStr);
			ebook_setIdEditorial(auxEmpleado, idEditorial);

		}


	}

	return auxEmpleado;
}



int ebook_CompareByName(void* pEmpleadoA, void* pEmpleadoB)
{
	int retorno = 0;
	Ebook* e1;
	Ebook* e2;

	e1 =(Ebook*) pEmpleadoA;
	e2 =(Ebook*) pEmpleadoB;

	if(strcmp(e1->autor, e2->autor) >0)
	{
		retorno =  1;
	}
	else
	{
		if(strcmp(e1->autor, e2->autor) < 0)
		{
			retorno = -1;
		}
	}

	return retorno;
}

int ebook_CompareById(void* pEmpleadoA, void* pEmpleadoB)
{
	int retorno = 0;

	Ebook* e1;
	Ebook* e2;

	e1 =(Ebook*) pEmpleadoA;
	e2 =(Ebook*) pEmpleadoB;

	if(e1->id > e2->id)
	{
		retorno = 1;
	}
	else
	{
		if(e1->id < e2->id)
		{
			retorno = -1;
		}
	}

	return retorno;
}

int editorial_setNombreEditorial(Editoriales* this, char* nombre)
{
	int retorno = -1;

	if(this != NULL && nombre != NULL)
	{
		strcpy(this->nombreEditorial, nombre);
		retorno = 0;
	}

	return retorno;
}

int editorial_getNombreEditorial(Editoriales* this, char* nombre)
{
	int retorno = -1;

	if(this != NULL && nombre != NULL)
	{
		strcpy(nombre, this->nombreEditorial);
		retorno  = 0;
	}
	return retorno;
}

int editorial_setIdEditorial(Editoriales* this, int id)
{
	int retorno = -1;

	if(this != NULL)
	{
		this->idEditorial = id;
		retorno = 1;
	}

	return retorno;
}

int editorial_getIdEditorial(Editoriales* this)
{
	int retorno = -1;
	if(this != NULL)
	{
		retorno = this->idEditorial;
	}

	return retorno;

}


