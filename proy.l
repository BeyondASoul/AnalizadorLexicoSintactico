/*SILVA NUÑEZ ALEJANDRO BRYAN*/
/*SANTIAGO VILLEGAS FERNANDO*/
/*ANALIZADOR LÉXICO-SINTACTICO*/
/*COMPILADORES*/
/*ENTREGA: 03/12/2020*/
/*OBJETIVO: Construir, en un mismo programa, los analizadores Léxico y Sintáctico Descendente Recursivo que revisen programas escritos en el lenguaje definido por la gramática de la clase.*/

%{
#include <stdio.h>
#include <string.h>
#include "tokens.h"
#include "identificadores.h"
#include "gramatica.h"
FILE *archSal;
TokensList tablaDeTokens;
IdentList tablaDeIdentificadores;
%}



/*EXPRESIONES BÁSICAS*/

num [0-9]
let [a-zA-Z]
espacio [[:space:]]
comentunalinea "//".*" "*
comentmulti \/\*(.*\n)*.*\*\/


/*EXPRESIONES DE CLASE*/

real {num}+(\.)+{num}+
clase0epos {real}((e|E)({espacio}|"+"){num}+)?
clase0eneg {real}((e|E)({espacio}?"-")({num}+))
clase1 "bool"|"break"|"case"|"char"|"continue"|"default"|"do"|"else"|"float"|"for"|"if"|"int"|"returnt"|"string"|"switch"|"while"|"void"
clase2 "{"|"}"|","|":"|"("|")"|"["|"]"
clase3 {let}+({let}|{num}|("_"))*
clase4 "="
clase5 ("!"{clase4})|({clase4}{clase4})|(">")|("<")|(">"{clase4})|("<"{clase4})
clase6 {num}{1,14}
clase7 \"([^\"]*)\"
clase8 "+"|"-"|"**"|"*"|"/"|"%"

/*UNA VEZ QUE SE TIENEN LAS EXPRESIONES REGULARES DE LAS CLASES, SE CREARÁN LAS DIFERENTES ACCIONES*/
/*QUE EL PROGRAMA REALIZARÁ DEPENDIENDO DE LA EXPRESIÓN REGULAR RECONOCIDA*/
%%

{clase0epos} {// TODO}
{clase0eneg} {// TODO}
{clase1} {// TODO}
{clase2} {// TODO}
{clase3} {// TODO}
{clase4} {// TODO}
{clase5} {// TODO}
{clase6} {// TODO}
{clase7} {// TODO}
{clase8} {// TODO}
({espacio}|\\n|\\t) {fprintf(archSal,"******ESPACIO, SALTO O TABULACIÓN******\n");}
. {fprintf(archSal,"ERROR: %s NO ES NINGUN TOKEN VÁLIDO\n",yytext);}

%%

int main(int argc, char *argv[])
{
    yyin = fopen(argv[1],"r");
    archSal = fopen(argv[2],"w");

    // ANALISIS LEXICO
    tablaDeTokens = crearTokensList();
    tablaDeIdentificadores = crearIdentList();
    yylex(); // Analisis Lexico
    // TODO: Funciones en cabeceras de tokens e identificadores

    // ANALISIS SINTACTICO
    P(); // Simbolo inicial de la gramatica
}
