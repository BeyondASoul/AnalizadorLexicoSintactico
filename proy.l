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
#include "identificadores.h"
#include "cadenas.h"
#include "constanteExponencial.h"
#include "gramatica.h"
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



/*EXPRESIONES DE CLASE*/

real {num}+(\.)+{num}+
clase0epos {real}((e|E)({espacio}?|"+"){num}+)?
clase0eneg {real}((e|E)({espacio}?"-")({num}+))
clase1 ("bool"|"break"|"case"|"char"|"continue"|"default"|"do"|"else"|"float"|"for"|"if"|"int"|"return"|"string"|"switch"|"while"|"void")
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
    contadorConstantes++; // Aumenta el contador de constantes
    char *exponencial=malloc(sizeof(yytext)); // Se reserva la memoria
    strcpy(exponencial,yytext); // Copia yytext a exponencial
    agregarConstanteExp(&tablaDeRealesExp,exponencial); // Agrega la constante
    agregarToken(&tablaDeTokens,0,contadorConstantes,'r'); // Agrega el token
};
{clase0epos} {
    fprintf(archSal,"clase0epos %s\n",yytext);
    contadorConstantes++; // Aumenta el contador de constantes
    char *exponencial=malloc(sizeof(yytext)); // Se reserva la memoria
    strcpy(exponencial,yytext); // Copia yytext a exponencial
    agregarConstanteExp(&tablaDeRealesExp,exponencial); // Agrega la constante
    agregarToken(&tablaDeTokens,0,contadorConstantes,'r'); // Agrega el token
};
{clase0eneg} {
    fprintf(archSal,"clase0eneg %s\n",yytext);
    contadorConstantes++; // Aumenta el contador de constantes
    char *exponencial=malloc(sizeof(yytext)); // Se reserva la memoria
    strcpy(exponencial,yytext); // Copia yytext a exponencial
    agregarConstanteExp(&tablaDeRealesExp,exponencial); // Agrega la constante
    agregarToken(&tablaDeTokens,0,contadorConstantes,'r'); // Agrega el token
};
{clase1} {
    fprintf(archSal,"clase1 %s\n",yytext);
    char *value=malloc(sizeof(yytext)); // Se reserva la memoria
    strcpy(value,yytext); // Copia yytext a value
    agregarToken(&tablaDeTokens,1,busquedaPal(value),'_'); // Agrega token con el valor correspondiente
};
{clase2} {
    fprintf(archSal,"clase2 %s\n",yytext);
    int value=toAscii(yytext); // Convierte yytext a Ascii
    agregarToken(&tablaDeTokens,2,value,'_'); // Agrega token con el valor correspondiente
};
{clase3} {
    fprintf(archSal,"clase3 %s\n",yytext);
    char *identificador=malloc(sizeof(yytext)); // Reserva la memoria para el identificador
    strcpy(identificador,yytext); // Copia yytext a identificador
    agregarIdent(&tablaDeIdentificadores,identificador,-1); // Agrega el identificador
    agregarToken(&tablaDeTokens,3,buscaIdent(&tablaDeIdentificadores,identificador),'a'); // Agrega el token buscando el identificador en la tabla
};
{clase4} {
    fprintf(archSal,"clase4 %s\n",yytext);
    agregarToken(&tablaDeTokens,4,61,'='); // Agrega token con el valor correspondiente
};
{clase5} {
    fprintf(archSal,"clase5 %s\n",yytext);
    char *value=malloc(sizeof(yytext)); // Se reserva la memoria
    strcpy(value,yytext); // Copia yytext a value
    agregarToken(&tablaDeTokens,5,busquedaOp(value),'_'); // Agrega token con el valor correspondiente
}
{clase6} {
    fprintf(archSal,"clase6 %s\n",yytext);
    int value=toFloat(yytext); // Convierte yytext a int por ser constante ENTERA
    agregarToken(&tablaDeTokens,6,value,'e'); // Agrega token con el valor correspondiente
};
{clase7} {
    fprintf(archSal,"clase7 %s\n",yytext);
    contadorCadenas++; // Aumenta el contador de cadenas
    char *cadena=malloc(sizeof(yytext)); // Reserva la memoria de la cadena
    strcpy(cadena,yytext); // Copia yytext a cadena
    agregarCadena(&tablaDeCadenas,cadena); // Agrega la cadena
    agregarToken(&tablaDeTokens,7,contadorCadenas,'s'); // Agrega el token
};
{clase8} {
    fprintf(archSal,"clase8 %s\n",yytext);
    if(!strcmp("**",yytext)){
        agregarToken(&tablaDeTokens,8,48,'_'); // Agrega el token para ** que es 0, 48 en ascii
    }
    else{
        int value=toAscii(yytext);
        agregarToken(&tablaDeTokens,8,value,'_'); // Agrega el token para cualquier otro
    }
};
({espacio}|\\n|\\t) {fprintf(logFile,"        ESPACIO, SALTO O TABULACIÓN        \n");}
(\@.*) {fprintf(logFile,"********COMENTARIO con @********\n");}
. { printf("ERROR, EL ANALIZADOR SINTACTICO NO ESPERABA '%s'\n\n",yytext);
    fprintf(logFile,"xxxxxxxxERROR: '%s' NO ES NINGUN TOKEN VÁLIDOxxxxxxxx\n",yytext);};
%%
int main(int argc, char *argv[])
{
    // ----------------------------------------------------
    // Se abren todos los archivos necesarios
    yyin = fopen(argv[1],"r");
    archSal = fopen(argv[2],"w");
    tokensFile = fopen("tokens.txt","w");
    identificadoresFile = fopen("identificadores.txt","w");
    cadenasFile = fopen("cadenas.txt","w");
    constantesExpFile = fopen("constantesExp.txt","w");
    logFile = fopen("log.txt","w");

    // ----------------------------------------------------
    // COMIENZA EL ANÁLISIS LÉXICO
    fprintf(archSal,"-------------------------------------------\n\nCOMIENZA EL ANÁLISIS LÉXICO:\n");
    yylex(); // Analisis Lexico
    // AQUI SE IMPRIMEN TOKENS, IDENTIFICADORES, CADENAS Y REALES.
    verTokens(tokensFile,tablaDeTokens);
    verIdentificadores(identificadoresFile,tablaDeIdentificadores);
    verCadenas(cadenasFile,tablaDeCadenas);
    verConstantesExp(constantesExpFile,tablaDeRealesExp);
    printf("-------------------------------------------\n\n");
    printf("TERMINÓ EL ANÁLISIS LÉXICO CON ÉXITO...\n\n");
    printf("PARA VER LOS TOKENS GENERADOS, VISITE: 'tokens.txt'\n\n");
    printf("PARA VER LOS IDENTIFICADORES GENERADOS, VISITE: 'identificadores.txt'\n\n");
    printf("PARA VER LAS CADENAS GENERADAS, VISITE: 'cadenas.txt'\n\n");
    printf("PARA VER LAS CONSTANTES REALES, VISITE: 'constantesExp.txt'\n\n");
    printf("PARA VER EL LOG DE ESPACIOS, COMENTARIOS Y ERRORES, VISITE: 'log.txt'\n\n");
    fprintf(archSal,"TERMINÓ EL ANÁLISIS LÉXICO CON ÉXITO...\n\n");
    printf("-------------------------------------------\n\n");

    // ----------------------------------------------------
    // COMIENZA EL ANÁLISIS SINTÁCTICO
    fprintf(archSal,"-------------------------------------------\n\nCOMIENZA EL ANÁLISIS SINTÁCTICO:\n");
    tokenAux=tablaDeTokens.head; // Token Auxiliar
    c=tokenAux->atomo; // Atomo del token auxiliar que irá avanzando
    archSalG=archSal; // Referencia a archivo de salida para usar en gramatica.h
    fprintf(archSal,"Atomo incial: c=%c\n",c); // Imprime el atomo inicial
    P(); // Comienza la gramática con el simbolo P

    // ----------------------------------------------------
    // CIERRA LOS ARCHIVOS UTILIZADOS
    fclose(archSal);
    fclose(tokensFile);
    fclose(identificadoresFile);
    fclose(cadenasFile);
    fclose(constantesExpFile);
    fclose(logFile);
}
