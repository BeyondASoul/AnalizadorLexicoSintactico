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
void verIDs(IdentList); // TODO: Funcion para ver identificadores
void agregarID(IdentList *lista,char* identificador,int tipo); // TODO: Funcion para agregar id
int buscarID(IdentList *lista,char* identificador); // TODO: Funcion para buscat id
char *buscarPorId(IdentList *lista,int posicion); // TODO: Funcion para buscar por Id

// Crea una lista de indetificadores
IdentList crearIdentList(){
    IdentList lista;
    lista.head = NULL;
    return lista;
}
