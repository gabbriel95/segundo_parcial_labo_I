#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
//1
typedef struct
{
    int id;
    char nombre[128];
    char autor[128];
    int precio;
    int idEditorial;
}Ebook;

typedef struct
{
    int idEditorial;
    char nombreEditorial[51];
}Editoriales;

Ebook* employee_new();
Ebook* book_newParametros(char* idStr,char* tituloStr,char* autorStr, char* precioStr, char* idEditorialStr);


void employee_delete();

int ebook_setId(Ebook* this,int id);
int ebook_getId(Ebook* this);

int ebook_setIdEditorial(Ebook* this, int id);
int ebook_getIdEditorial(Ebook* this);

int ebook_setNombre(Ebook* this,char* nombre);
int ebook_getNombre(Ebook* this,char* nombre);

int ebook_setNombreAutor(Ebook* this, char* nombre);
int ebook_getNombreAutor(Ebook* this, char* nombre);

int ebook_setHorasTrabajadas(Ebook* this,int horasTrabajadas);
int ebook_getHorasTrabajadas(Ebook* this,int* horasTrabajadas);

int ebook_setPrecio(Ebook* this, int precio);
int ebook_getPrecio(Ebook* this, int* precio);

//Crear una funcion que compare a dos empleados x nombre
int ebook_CompareByName(void* pEmpleadoA, void* pEmpleadoB);
int ebook_CompareById(void* pEmpleadoA, void* pEmpleadoB);


int ebook_SolicitarNombre(char* name, Ebook* empleado);
int ebook_SolicitarSalario(int salario, Ebook* empleado);
int ebook_SolicitarHorasTrabajadas(int horas, Ebook* empleado);

int editorial_setNombreEditorial(Editoriales* this, char* nombre);
int editorial_getNombreEditorial(Editoriales* this, char* nombre);
int editorial_setIdEditorial(Editoriales* this, int id);
int editorial_getIdEditorial(Editoriales* this);

#endif // employee_H_INCLUDED
