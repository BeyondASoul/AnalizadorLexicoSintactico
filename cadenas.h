/*
	De igual manera a los tokens e identificadores, se utilizara
	este archivo para la creación y manipulación de las cadenas
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
// Estructura de las cadenas, con un apuntador a la siguiente cadena
typedef struct Cad{
    int posicion;
    char* valor;
    struct Cad* next;
}Cad;
// Se manejará como una lista ligada simple
typedef struct CadList{
    struct Cad* head;
}CadList;

// Agrega una cadena
void agregarCadena(CadList *listaCad, char* valor){
		if(listaCad->head==NULL){
			Cad *cad= (Cad*)malloc(sizeof(Cad));
			cad->posicion=0;
			cad->valor=valor;
            cad->next=NULL;
            listaCad->head=cad;
		}
		else{
			Cad *actual = listaCad->head;
			int pos=1;
			while (actual->next != 0) 
			{
				actual = actual->next;
				pos=pos+1;
			}
			Cad *newCad = (Cad*)malloc(sizeof(Cad));
			newCad->posicion=pos;
			newCad->valor=valor;
			newCad->next=NULL;
			actual->next=newCad;
		}
}

// Imprime las cadenas
void verCadenas(FILE* archSal, CadList list){
    if(list.head==NULL){
        fprintf(archSal,"No hay cadenas.\n");
    }
    else{
        Cad *actual = list.head;
        while (actual != 0) {
            fprintf(archSal,"Posicion: %d\t\tValor: %s\n",actual->posicion,actual->valor);
            actual = actual->next;
        }
    }
}