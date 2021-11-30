#include <stdio_ext.h>
#include <stdlib.h>

#include "LinkedList.h"
#include "Controller.h"
#include "string.h"

#include "Ebook.h"
#include "Utn.h"

/****************************************************
 * Alumno: Mendez Juan Gabriel
 * Division:1F
    Menu:

*****************************************************/



int main()
{
	LinkedList* listaBooks = ll_newLinkedList();
	LinkedList* listaMinotauro;
	int opcion;
	char nombreArchivo[12];

	do
	    {
		printf( "\n1. Cargar datos desde archivo modo texto\n"
				"2. Ordenar lista por autor\n"
				"3. Filtrar libros por editorial MINOTAURO\n"
				"4. Guardar archivos de libros editorial MINOTAURO\n"
				"5. Listar libros\n"
				"6. Aplicar descuentos y generar archivo\n"
				"7. Salir\n");

			Utn_GetNumero(&opcion, "\nSeleccione una opcion\n", "\n Error, opcion no valida", 1, 7, 3);

			switch(opcion)
	        {
	        case 1:
	        	if(PedirCadenaChars(nombreArchivo, 10, "\nIngrese el nombre del archivo que desea abrir:", "Error", 3) == 1)
	        	{
	        		if(strcmp(nombreArchivo, "libros") == 0)
	        		{
	        			controller_loadFromText("libros.csv", listaBooks);
	        		}else if(strcmp(nombreArchivo, "editoriales") == 0)
	        		{
	        			controller_loadFromText("editoriales.csv", listaBooks);
	        		}else if(strcmp(nombreArchivo, "mapeado") == 0)
	        		{
	        			controller_loadFromText("mapeado.csv", listaBooks);
	        		}
	        	}

	        	break;
	        case 2:
	        	controller_sortEbook(listaBooks);
	            break;

	        case 3:
	        	listaMinotauro = controller_ListaEditoriales(listaBooks);
	            break;

	        case 4:
	        	controller_saveAsText("filtrado.csv", listaMinotauro);
	            break;

	        case 5:
	        	controller_ListBooks(listaBooks);
	            break;

	        case 6:
	            controller_aplicaDescuento(listaBooks);
	        	controller_saveAsText("mapeado.csv", listaBooks);
	            break;

	        case 7:
	            break;

	        }

	    }
	    while(opcion != 7);


    return 0;
}

