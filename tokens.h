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
    int valor;
    char atomo;
    struct Token* next;
}Token;
// Se manejará como una lista ligada simple
typedef struct TokensList{
    struct Token* head;
}TokensList;

void agregarToken(TokensList *tokens,int clase,int valor,char* atomo){
    if(tokens->head==NULL){
        Token *nodo = (Token*)malloc(sizeof(Token));
        nodo->clase = clase;
        nodo->valor = valor;
        nodo->atomo= atomo;
        nodo->next = NULL;
        tokens->head = nodo;
    }   
    else{
        Token *current = tokens->head;
        while (current->next != 0) {
            current = current->next;
        }
        Token *nuevoNodo;
        nuevoNodo = (Token*)malloc(sizeof(Token));
        nuevoNodo->clase = clase;
        nuevoNodo->valor = valor;
        nuevoNodo->atomo= atomo;
        nuevoNodo->next = NULL;
        current->next = nuevoNodo;
    }   
}

//Funcion para imprimir los tokens
void verTokens(FILE* archSal, TokensList tokens) {
    if(tokens.head==NULL){
        fprintf(archSal,"No hay tokens.\n");
    }
    else{
        Token *current = tokens.head;
        while (current != 0) {
            if (current->clase==8){
                fprintf(archSal,"(%d,%c,%c)\n",current->clase,(char)current->valor,(char)current->atomo);
            }
            else{
                fprintf(archSal,"(%d,%d,%c)\n",current->clase,current->valor,(char)current->atomo);
            }
            
            current = current->next;
        }
    }
}