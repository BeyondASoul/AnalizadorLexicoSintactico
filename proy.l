/*SILVA NUÑEZ ALEJANDRO BRYAN*/
/*SANTIAGO VILLEGAS FERNANDO*/
/*ANALIZADOR LÉXICO-SINTACTICO*/
/*COMPILADORES*/
/*ENTREGA: 03/12/2020*/
/*OBJETIVO: Construir, en un mismo programa, los analizadores Léxico y Sintáctico Descendente Recursivo que revisen programas escritos en el lenguaje definido por la gramática de la clase.*/

%{
/*Bibliotecas e inicializacines: */
#include <stdio.h>
#include <string.h>
#include "tokens.h"
#include "identificadores.h"
#include "cadenas.h"
#include "constanteExponencial.h"
#include "atomo.h"

// Archivos de salida necesarios
FILE *archSal; 
FILE *tokensFile;
FILE *identificadoresFile;
FILE *cadenasFile;
FILE *constantesExpFile;
FILE *logFile;
// Variables necesarias para clase 0 y clase 7
int contadorCadenas;
int contadorConstantes;
// Listas ligadas de tokens, identificadores, cadenas y constantes reales
TokensList tablaDeTokens;
IdentList tablaDeIdentificadores;
CadList tablaDeCadenas;
RealListExp tablaDeRealesExp;
Token aux;//token auxiliar para recorrer la tabla de tokens para el analizador sintáctico
char c; //atomo
// Lista estática de operadores relacionales y palabras reservadas
char *operadoresRel[6]={"!=","==",">","<",">=","<="};
char *palabrasRes[17]={"bool","break","case","char","continue","default","do","else","float","for","if","int","return","string","switch","while","void"};
// Funciones para buscar el token en cada lista (operadores relacionales y palabras reservadas)
// OPERADORES RELACIONALES
int busquedaOp(char* cadena){
    for(int i=0;i<6;i++){
        if(!strcmp(operadoresRel[i],cadena)){
            return i;
        }
    }
    return -1;
}
// PALABRA RESERVADA
int busquedaPal(char* cadena){
    for(int i=0;i<17;i++){
        if(!strcmp(palabrasRes[i],cadena)){
            return i;
        }
    }
    return -1;
}
// Funciones para convertir yytext en valores deseados para el token.
// Convierte a Ascii
int toAscii(char *caracter){
    return (int)*caracter;
}
// Convierte a Float
float toFloat(char *num){
    return atof(num);
}
%}

/*EXPRESIONES BÁSICAS*/

num [0-9]
let [a-zA-Z]
espacio [[:space:]]
comentunalinea \/\/.*
comentmulti \/\*(.*"\n")*\*\/


/*EXPRESIONES DE CLASE*/

real {num}+(\.)+{num}+
clase0epos {real}((e|E)({espacio}|"+"){num}+)?
clase0eneg {real}((e|E)({espacio}?"-")({num}+))
clase1 ("bool"|"break"|"case"|"char"|"continue"|"default"|"do"|"else"|"float"|"for"|"if"|"int"|"returnt"|"string"|"switch"|"while"|"void")
clase2 "{"|"}"|","|":"|"("|")"|"["|"]"
clase3 {let}+({let}|{num}|("_"))*
clase4 "="
clase5 ("!"{clase4})|({clase4}{clase4})|(">")|("<")|(">"{clase4})|("<"{clase4})
clase6 {num}{1,14}
clase7 \"([^\"]*)\"
clase8 ("+"|"-"|"**"|"*"|"/"|"%")

/*UNA VEZ QUE SE TIENEN LAS EXPRESIONES REGULARES DE LAS CLASES, SE CREARÁN LAS DIFERENTES ACCIONES*/
/*QUE EL PROGRAMA REALIZARÁ DEPENDIENDO DE LA EXPRESIÓN REGULAR RECONOCIDA*/
%%
{real} {
    fprintf(archSal,"real sin e %s\n",yytext);
    contadorConstantes++;
    char *exponencial=malloc(sizeof(yytext)); // Se reserva la memoria
    strcpy(exponencial,yytext); // Copia yytext a exponencial
    agregarConstanteExp(&tablaDeRealesExp,exponencial);
    agregarToken(&tablaDeTokens,0,contadorConstantes,"r");
};
{clase0epos} {
    fprintf(archSal,"clase0epos %s\n",yytext);
    contadorConstantes++;
    char *exponencial=malloc(sizeof(yytext)); // Se reserva la memoria
    strcpy(exponencial,yytext); // Copia yytext a exponencial
    agregarConstanteExp(&tablaDeRealesExp,exponencial);
    agregarToken(&tablaDeTokens,0,contadorConstantes,"r");
};
{clase0eneg} {
    fprintf(archSal,"clase0eneg %s\n",yytext);
    contadorConstantes++;
    char *exponencial=malloc(sizeof(yytext)); // Se reserva la memoria
    strcpy(exponencial,yytext); // Copia yytext a exponencial
    agregarConstanteExp(&tablaDeRealesExp,exponencial);
    agregarToken(&tablaDeTokens,0,contadorConstantes,"r");
};
{clase1} {
    fprintf(archSal,"clase1 %s\n",yytext);
    char *value=malloc(sizeof(yytext)); // Se reserva la memoria
    strcpy(value,yytext); // Copia yytext a value
    agregarToken(&tablaDeTokens,1,busquedaPal(value),palabraAtomo(yytext)); // Agrega token con el valor correspondiente
};
{clase2} {
    fprintf(archSal,"clase2 %s\n",yytext);
    int value=toAscii(yytext); // Convierte yytext a Ascii
    agregarToken(&tablaDeTokens,2,value,simboloAtomo(yytext)); // Agrega token con el valor correspondiente
};
{clase3} {
    fprintf(archSal,"clase3 %s\n",yytext);
    char *identificador=malloc(sizeof(yytext));
    strcpy(identificador,yytext);
    agregarIdent(&tablaDeIdentificadores,identificador,-1);
    agregarToken(&tablaDeTokens,3,buscaIdent(&tablaDeIdentificadores,identificador),"a");
};
{clase4} {
    fprintf(archSal,"clase4 %s\n",yytext);
    agregarToken(&tablaDeTokens,4,61,"="); // Agrega token con el valor correspondiente
};
{clase5} {
    fprintf(archSal,"clase5 %s\n",yytext);
    char *value=malloc(sizeof(yytext)); // Se reserva la memoria
    strcpy(value,yytext); // Copia yytext a value
    agregarToken(&tablaDeTokens,5,busquedaOp(value),opReAtomo(yytext)); // Agrega token con el valor correspondiente
}
{clase6} {
    fprintf(archSal,"clase6 %s\n",yytext);
    int value=toFloat(yytext); // Convierte yytext a int por ser constante ENTERA
    agregarToken(&tablaDeTokens,6,value,"e"); // Agrega token con el valor correspondiente
};
{clase7} {
    fprintf(archSal,"clase7 %s\n",yytext);
    contadorCadenas++;
    char *cadena=malloc(sizeof(yytext));
    strcpy(cadena,yytext);
    agregarCadena(&tablaDeCadenas,cadena);
    agregarToken(&tablaDeTokens,7,contadorCadenas,"s");
};
{clase8} {
    fprintf(archSal,"clase8 %s\n",yytext);
    if(!strcmp("**",yytext)){
        agregarToken(&tablaDeTokens,8,48,opArAtomo(yytext));
    }
    else{
        int value=toAscii(yytext);
        agregarToken(&tablaDeTokens,8,value,opArAtomo(yytext));
    }
};
({espacio}|\\n|\\t) {fprintf(logFile,"        ESPACIO, SALTO O TABULACIÓN        \n");}
({comentunalinea}"\n"|{comentmulti}) {fprintf(logFile,"\\\\\\\\COMENTARIO UNICO/MULTILINEA: %s\n",yytext);}
(\@{comentunalinea}|\@{comentmulti}) {fprintf(logFile,"********COMENTARIO con @ DESCARTADO: %s\n",yytext);}
. {fprintf(logFile,"xxxxxxxxERROR: '%s' NO ES NINGUN TOKEN VÁLIDOxxxxxxxx\n",yytext);}

%%

int main(int argc, char *argv[])
{
    // Se abren todos los archivos necesarios
    yyin = fopen(argv[1],"r");
    archSal = fopen(argv[2],"w");
    tokensFile = fopen("tokens.txt","w");
    identificadoresFile = fopen("identificadores.txt","w");
    cadenasFile = fopen("cadenas.txt","w");
    constantesExpFile = fopen("constantesExp.txt","w");
    logFile = fopen("log.txt","w");

    // Comienza el análisis léxico
    fprintf(archSal,"Comienza el análisis léxico:\n");
    yylex(); // Analisis Lexico
    aux=tablaDeTokens.head;//se ubica en el primer elemento 
    c=getAtomo();
    // Aqui se imprimen tokens, identificadores, cadenas y reales.
    verTokens(tokensFile,tablaDeTokens);
    verIdentificadores(identificadoresFile,tablaDeIdentificadores);
    verCadenas(cadenasFile,tablaDeCadenas);
    verConstantesExp(constantesExpFile,tablaDeRealesExp);

    fprintf(archSal,"Termina el análisis léxico.\n");

    fclose(tokensFile);
    fclose(identificadoresFile);
    fclose(cadenasFile);
    fclose(constantesExpFile);
    fclose(logFile);
}
