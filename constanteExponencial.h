/*SILVA NUÑEZ ALEJANDRO BRYAN*/
/*SANTIAGO VILLEGAS FERNANDO*/
/*ANALIZADOR LÉXICO-SINTACTICO*/
/*COMPILADORES*/
/*ENTREGA: 03/12/2020*/
/*OBJETIVO: Construir, en un mismo programa, los analizadores Léxico y
Sintáctico Descendente Recursivo que revisen programas escritos en el lenguaje definido por la gramática de la clase.*/
/*
	De igual manera a los tokens y a los tokens, identificadores y cadenas,
	se utilizara este archivo para la creación y manipulación de las constantes reales
*/
#include <stdio.h>
#include <stdlib.h>
// Estructura de las cadenas, con un apuntador a la siguiente cadena
typedef struct RealExp
{
	int posicion;
	char *constante;
	struct RealExp *next;
} RealExp;
// Se manejará como una lista ligada simple
typedef struct RealListExp
{
	struct RealExp *head;
} RealListExp;

// Agrega una constante real en una lista ligada simple
void agregarConstanteExp(RealListExp *listaConstExp, char *constante)
{
	if (listaConstExp->head == NULL)
	{
		RealExp *real = (RealExp *)malloc(sizeof(RealExp));
		real->posicion = 0;
		real->constante = constante;
		real->next = NULL;
		listaConstExp->head = real;
	}
	else
	{
		RealExp *actual = listaConstExp->head;
		int pos = 1;
		while (actual->next != 0)
		{
			actual = actual->next;
			pos = pos + 1;
		}
		RealExp *newConst = (RealExp *)malloc(sizeof(RealExp));
		newConst->posicion = pos;
		newConst->constante = constante;
		newConst->next = NULL;
		actual->next = newConst;
	}
}

// Imprime las constantes reales de la lista ligada simple
void verConstantesExp(FILE *archSal, RealListExp list)
{
	if (list.head == NULL)
	{
		fprintf(archSal, "No hay constantes reales exponenciales.\n");
	}
	else
	{
		RealExp *actual = list.head;
		while (actual != 0)
		{
			fprintf(archSal, "Posicion: %d\t\tValor: %s\n", actual->posicion, actual->constante);
			actual = actual->next;
		}
	}
}