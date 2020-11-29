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

// Busca el identificador y verifica si existe
int buscaIdent(IdentList *lista, char* identificador){
    if(lista->head==NULL){
        return -1;
    }   
    else
    {
        Ident *ident = lista->head;
        if(!strcmp(ident->identificador,identificador)){
            return 0;
        }
        int pos=0;
        while (ident->next != 0) {
            ident = ident->next;
            pos=pos+1;
            if(!strcmp(ident->identificador,identificador)){
                return pos;
            }
        }
        return -1;
    }   
}
// Agrega un identificador
void agregarIdent(IdentList *listaIdent, char* identificador, int tipo){
	if(buscaIdent(listaIdent,identificador)==-1){
		if(listaIdent->head==NULL){
			Ident *ident= (Ident*)malloc(sizeof(Ident));
			ident->posicion=0;
            ident->tipo=tipo;
			ident->identificador=identificador;
            ident->next=NULL;
            listaIdent->head=ident;
		}
		else{
			Ident *actual = listaIdent->head;
			int pos=1;
			while (actual->next != 0) 
			{
				actual = actual->next;
				pos=pos+1;
			}
			Ident *newIdent = (Ident*)malloc(sizeof(Ident));
			newIdent->posicion=pos;
            newIdent->tipo=tipo;
			newIdent->identificador=identificador;
			newIdent->next=NULL;
			actual->next=newIdent;

		}
	}
}

// Imprime los identificadores
void verIdentificadores(FILE* archSal, IdentList list){
    if(list.head==NULL){
        fprintf(archSal,"No hay identificadores.\n");
    }
    else{
        Ident *actual = list.head;
        while (actual != 0) {
            fprintf(archSal,"Posicion: %d\t\tNombre: %s\t\t\tTipo: %d\n",actual->posicion,actual->identificador,actual->tipo);
            actual = actual->next;
        }
    }
}
