#include "Ebook.h"

int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);
int controller_addEmployee(LinkedList* pArrayListEmployee);
int controller_editEmployee(LinkedList* pArrayListEmployee);
int controller_removeEmployee(LinkedList* pArrayListEmployee);
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);



int controller_sortEbook(LinkedList* pArrayListEmployee);
int controller_ListBooks(LinkedList* pArrayListBooks);
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);
int filtrarEditoriales(void* parametro);
LinkedList* controller_ListaEditoriales(LinkedList* this);
int contadorDeAlgo(void* parametro);
int controller_Contador(LinkedList* this);



//funciones que se van a llamar desde el main
