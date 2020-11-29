/*
La cabecera identificadores.h será utilizada para crear una lista de los 
identificadores reconocidos a lo largo de la ejecución del programa.

Como se utilizarán apuntadores, nuestro nodo será la estructura Ident,
definida como:
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
// Estructura de los ID, con un apuntador al siguiente ID
typedef struct Ident{
    int posicion;
    char* identificador;
    int tipo;
    struct Ident* next;
}Ident;
// Se manejará como una lista ligada simple
typedef struct IdentList{
    struct Ident* head;
}IdentList;

// Funciones
IdentList crearIdentList(); // Crea una lista de identificadores
void agregarIdent(IdentList *lista, char* identificador);
int buscaIdent(IdentList *lista, char* identificador);

// Crea una lista de indetificadores
IdentList crearIdentList(){
    IdentList listaDeIdentificadores;
    listaDeIdentificadores.head = NULL;
    return listaDeIdentificadores;
}
void agregarIdent(IdentList *lista, char* identificador)
{
	Ident* siguiente= (Ident*) malloc(sizeof(Ident));
	if(lista->head==NULL)
	{
		siguiente->posicion=0;
		siguiente->identificador=identificador;
		siguiente->tipo=-1;
		siguiente->next=NULL;
		lista->head=siguiente;
	}
	else
	{
		Ident *current = lista->head;
		int pos=current->posicion;
    while (current->next != 0) 
    {
      current = current->next;
      pos=current->posicion;
    }
    siguiente->posicion=pos++;
		siguiente->identificador=identificador;
		siguiente->tipo=-1;
		siguiente->next=NULL;
		current->next=siguiente;
	}
}
int buscaIdent(IdentList *lista, char* identificador)
{
	if(lista->head==NULL)
		return 0;	
	Ident *current = lista->head;
  while (current->next != 0) 
  {
  	if(strcmp(current->identificador,identificador)==0)
   		return current->posicion;
   	else
   	{
  	 	current=current->next;
    }
  }
  return -1;
}