/*
	De igual manera a los tokens y a los tokens e identificadores, se utilizara
	este archivo para la creación y manipulación de las cadenas
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
// Estructura de las cadenas, con un apuntador a la siguiente cadena
typedef struct Cad{
    int posicion;
    char* cadena;
    struct Cad* next;
}Cad;
// Se manejará como una lista ligada simple
typedef struct CadList{
    struct Cad* head;
}CadList;

CadList crearTablaCadenas()
{
	CadList listaDeCadenas;
  listaDeCadenas.head = NULL;
  return listaDeCadenas;
}
void agregarCad(CadList *lista, char* cadena)
{
	Cad* siguiente=(Cad*)malloc(sizeof(Cad));
	if(lista->head==NULL)
	{
		siguiente->posicion=0;
		siguiente->cadena=cadena;
		siguiente->next=NULL;
		lista->head=siguiente;
	}
	else
	{
		Cad *current = lista->head;
		int pos=current->posicion;
    while (current->next != 0) 
    {
      current = current->next;
      pos=current->posicion;
    }
    siguiente->posicion=pos++;
		siguiente->cadena=cadena;
		siguiente->next=NULL;
		current->next=siguiente;
	}
}
int buscaCad(CadList *lista, char* cadena)
{
	Cad *current = lista->head;
  while (current->next != 0) 
  {
  	if(strcmp(current->cadena,cadena))
   		return current->posicion;
   	else
   	{
  	 	current=current->next;
    }
  }
  return -1;
}