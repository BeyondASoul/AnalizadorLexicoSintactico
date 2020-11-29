/*
	De igual manera a los tokens y a los tokens, identificadores y cadenas,
	se utilizara este archivo para la creación y manipulación de las cadenas
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
// Estructura de las cadenas, con un apuntador a la siguiente cadena
typedef struct Real{
    int posicion;
    float num;
    struct Real* next;
}Real;
// Se manejará como una lista ligada simple
typedef struct RealList{
    struct Real* head;
}RealList;

RealList crearTablaReales()
{
	RealList listaDeReales;
  listaDeReales.head = NULL;
  return listaDeReales;
}
void agregarReal(RealList *lista, float num)
{
	Real* siguiente=(Real*)malloc(sizeof(Real));
	if(lista->head==NULL)
	{
		siguiente->posicion=0;
		siguiente->num=num;
		siguiente->next=NULL;
		lista->head=siguiente;
	}
	else
	{
		Real *current = lista->head;
		int pos=current->posicion;
    while (current->next != 0) 
    {
      current = current->next;
      pos=current->posicion;
    }
    siguiente->posicion=pos++;
		siguiente->num=num;
		siguiente->next=NULL;
		current->next=siguiente;
	}
}
int buscaReal(RealList *lista, float num)
{
	Real *current = lista->head;
  while (current->next != 0) 
  {
  	if(current->num==num)
   		return current->posicion;
   	else
   	{
  	 	current=current->next;
    }
  }
  return -1;
}