/*
La cabecera tokens.h será utilizada para crear una lista de los tokens
reconocidos a lo largo de la ejecución del programa, incuyendo el valor
del atomo necesario a cada uno para realizar el análisis sintáctico

Como se utilizarán apuntadores, nuestro nodo será la estructura Token
definida como:
*/
#include<stdio.h>
#include<stdlib.h>
#include <string.h>
// Estructura de los tokens, con un apuntador al siguiente token
typedef struct Token
{
    int clase;
    float valor;
    char atomo;
    struct Token* next;
}Token;
// Se manejará como una lista ligada simple
typedef struct TokensList{
    struct Token* head;
}TokensList;

// Funciones
TokensList ListadeTokens(); // Crea una lista de tokens y la retorna
void verTokens(TokensList); // TODO: Funcion para mostrar los tokens, recibe el TokensList
void agregarToken(TokensList *lista,int clase,float valor); // TODO: Agrega el token al final de la lista
char atomo(int clase, float valor); // TODO: Crea el atomo

// Se crea una lista de tokens
TokensList crearTokensList(){
    TokensList listaDeTokens;
    listaDeTokens.head = NULL; // Se hace referencia nulla al head de la lista
    return listaDeTokens;
}
