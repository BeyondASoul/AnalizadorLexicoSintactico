/*SILVA NUÑEZ ALEJANDRO BRYAN*/
/*SANTIAGO VILLEGAS FERNANDO*/
/*ANALIZADOR LÉXICO-SINTACTICO*/
/*COMPILADORES*/
/*ENTREGA: 03/12/2020*/
/*OBJETIVO: Construir, en un mismo programa, los analizadores Léxico y
Sintáctico Descendente Recursivo que revisen programas escritos en el lenguaje definido por la gramática de la clase.*/


#include "tokens.h"

// Define el booleano, utilizado para verificar en el error si el no terminal es primo o no.
typedef int bool;
#define true 1
#define false 0

// Funciones
void getAtomo(); // Ayuda a obtener el siguiente atomo para analizar.
// Define los no termniales de las gramáticas, siendo P el indicador de prima
void P();                                                                    // inicial
void YP();                                                                   // Gramatica Y'
void Y();                                                                    // Gramatica Y
void VP();                                                                   // Gramatica V'
void DP();                                                                   // Gramatica D'
void D();                                                                    // Gramatica D
void L();                                                                    // Gramatica L
void C();                                                                    // Gramatica C
void V();                                                                    // Gramatica V
void G();                                                                    // Gramatica G
void S();                                                                    // Gramatica S
void U();                                                                    // Gramatica U
void W();                                                                    // Gramatica W
void H();                                                                    // Gramatica H
void X();                                                                    // Gramatica X
void O();                                                                    // Gramatica O
void B();                                                                    // Gramatica B
void I();                                                                    // Gramatica I
void J();                                                                    // Gramatica J
void N();                                                                    // Gramatica N
void R();                                                                    // Gramatica R
void K();                                                                    // Gramatica K
void E();                                                                    // Gramatica E
void EP();                                                                   // Gramatica E'
void T();                                                                    // Gramatica T
void TP();                                                                   // Gramatica T'
void F();                                                                    // Gramatica F
void A();                                                                    // Gramatica A
void M();                                                                    // Gramatica M
void printConEsperado(bool prima, char noTerminal, char esperado, char hay); // Imprime error
void printErrorNT(bool prima, char noTerminal, char hay);                    // Imprime error
void printEntrada(bool prima, char noTerminal, char caracter);               // Imprime entrada a cada no terminal
//Variables
char c;
Token *tokenAux = NULL;
FILE *archSalG;

/* Función para obtener el atomo siguiente e ir recorriendolos*/
void getAtomo()
{
    if (tokenAux->next == NULL)
    {
        tokenAux = NULL;
        c = '_';
    }
    else
    {
        tokenAux = tokenAux->next;
        c = tokenAux->atomo;
    }
    fprintf(archSalG, "Actualizando el caracter actual: Átomo = '%c'\n", c);
}
// Definiendo la gramática como funciones
void P() // Conjunto de selección: c.s={ b c f n g [ }
{
    printEntrada(0, 'P', c);
    if (c == 'b' || c == 'c' || c == 'f' || c == 'n' || c == 'g' || c == '[' || c == '_')
    {
        DP();
        Y();
        YP();
    }
    else
        printErrorNT(0, 'P', c);
    return;
}
void YP() // Conjunto de selección: c.s={ [ ┤ }
{
    printEntrada(1, 'Y', c);
    if (c == '[')
    {
        Y();
        YP();
    }
    else if (c == '_')
        return;
    else
        printErrorNT(1, 'Y', c);
    return;
}
void Y() // Conjunto de selección: c.s={ [ }
{
    printEntrada(0, 'Y', c);
    if (c == '[')
    {
        getAtomo();
        VP();
        if (c == 'a')
        {
            getAtomo();
            if (c == '(')
            {
                getAtomo();
                if (c == ')')
                {
                    getAtomo();
                    if (c == '{')
                    {
                        getAtomo();
                        DP();
                        B();
                        if (c == '}')
                        {
                            getAtomo();
                            if (c == ']')
                                getAtomo();
                            if (c == '_')
                            {
                                printf("TERMINÓ EL ANÁLISIS SINTÁCTICO CON ÉXITO...\n\n");
                                printf("PARA MÁS DETALLES, CONSULTE EL ARCHIVO: salida.txt\n\n");
                                printf("-------------------------------------------\n");
                                fprintf(archSalG, "TERMINÓ EL ANÁLISIS SINTÁCTICO CON ÉXITO...\n\n");
                                fprintf(archSalG, "-------------------------------------------\n");
                                return exit(EXIT_SUCCESS);
                            }
                            else if (c == '[')
                                Y();
                            else
                            {
                                printConEsperado(0, 'Y', '_', c);
                            }
                        }
                        else
                            printConEsperado(0, 'Y', '}', c);
                    }
                    else
                        printConEsperado(0, 'Y', '{', c);
                }
                else
                    printConEsperado(0, 'Y', ')', c);
            }
            else
                printConEsperado(0, 'Y', '(', c);
        }
        else
            printConEsperado(0, 'Y', 'a', c);
    }
    else
        printConEsperado(0, 'Y', '[', c);
    return;
}
void VP() // Conjunto de selección: c.s={ b c f n g o }
{
    printEntrada(1, 'V', c);
    if (c == 'b' || c == 'c' || c == 'f' || c == 'n' || c == 'g')
        V();
    else if (c == 'o')
        getAtomo();
    else
        printErrorNT(1, 'V', c);
    return;
}
void DP() // Conjunto de selección: c.s={ b c f n g [ x i w h p u t } }
{
    printEntrada(1, 'D', c);
    if (c == 'b' || c == 'c' || c == 'f' || c == 'n' || c == 'g')
    {
        D();
        DP();
    }
    else if (c == 'a' || c == 'x' || c == 'i' || c == 'w' || c == 'h' || c == 'p' || c == 'u' || c == 't' || c == '[' || c == '}' || c == '_')
        return;
    else
        printErrorNT(1, 'D', c);
    return;
}
void D() // Conjunto de selección: c.s={ b c f n g }
{
    printEntrada(0, 'D', c);
    if (c == 'b' || c == 'c' || c == 'f' || c == 'n' || c == 'g')
    {
        V();
        L();
        if (c == ':')
            getAtomo();
        else
            printErrorNT(0, 'D', c);
    }
    else
        printErrorNT(0, 'D', c);
    return;
}
void L() // Conjunto de selección: c.s={ a }
{
    printEntrada(0, 'L', c);
    if (c == 'a')
    {
        getAtomo();
        G();
        C();
    }
    else if (c == 's')
    {
        getAtomo(); // conjutno de selección
        C();
    }
    else
        printErrorNT(0, 'L', c);
    return;
}
void C() // Conjunto de selección: c.s={ , : }
{
    printEntrada(0, 'C', c);
    if (c == ',')
    {
        getAtomo();
        L();
    }
    else if (c == '_' || c == ':')
        return;
    else
        printErrorNT(0, 'C', c);
    return;
}
void V() // Conjunto de selección: c.s={ b c f n g }
{
    printEntrada(0, 'V', c);
    if (c == 'b' || c == 'c' || c == 'f' || c == 'n' || c == 'g')
        getAtomo();
    else
        printErrorNT(0, 'V', c);
    return;
}
void G() // Conjunto de selección: c.s={ [ : ( a e r ) + - # % / * ! ? <> y m = }
{
    printEntrada(0, 'G', c);
    if (c == '[')
    {
        getAtomo(); //e
        if (c == 'e')
        {
            getAtomo(); //lo que sigue
            if (c == ']')
                getAtomo();
            else
                printConEsperado(0, 'G', ']', c);
        }
    }
    else if (c == '_' || c == ':' || c == ',' || c == '(' || c == 'a' || c == 'e' || c == 'r' || c == ')' || c == '+' || c == '-' || c == '#' || c == '%' || c == '/' || c == '*' || c == '!' || c == '?' || c == '<' || c == '>' || c == 'y' || c == 'm' || c == '=')
        return;
    else
        printConEsperado(0, 'G', '[', c);
    return;
}
void S() // Conjunto de selección: c.s={ a x i w h p u t [ }
{
    printEntrada(0, 'S', c);
    if (c == 'x')
        X();
    else if (c == 'a')
        A();
    else if (c == 'i')
        I();
    else if (c == 'w')
        W();
    else if (c == 'h')
        H();
    else if (c == 'p')
        N();
    else if (c == 'u')
    {
        getAtomo(); // _ (
        U();
        if (c == ':')
            getAtomo(); // lo que sigue
        else
            printConEsperado(0, 'S', ':', c);
    }
    else if (c == 't')
    {
        getAtomo(); //:
        if (c == ':')
            getAtomo(); //Lo que sigue
        else
            printConEsperado(0, 'S', ':', c);
    }
    else if (c == '[')
    {
        getAtomo(); //a
        if (c == 'a')
        {
            getAtomo(); //(
            if (c == '(')
            {
                getAtomo(); //)
                if (c == ')')
                {
                    getAtomo(); //]
                    if (c == ']')
                    {
                        getAtomo(); //:
                        if (c == ':')
                            getAtomo();
                        else
                            printConEsperado(0, 'S', ':', c);
                    }
                    else
                        printConEsperado(0, 'S', ']', c);
                }
                else
                    printConEsperado(0, 'S', ')', c);
            }
            else
                printConEsperado(0, 'S', '(', c);
        }
        else
            printConEsperado(0, 'S', 'a', c);
    }
    else
        printErrorNT(0, 'S', c);
    return;
}
void U() // Conjunto de selección: c.s={ : ( }
{
    printEntrada(0, 'U', c);
    if (c == '(')
    {
        getAtomo(); //a e r [
        F();
        if (c == ')')
            getAtomo(); // lo que sigue
        else
            printConEsperado(0, 'U', ')', c);
    }
    else if (c == ':')
        return;
    else
        printErrorNT(0, 'U', c);
    return;
}
void W() // Conjunto de selección: c.s={ w }
{
    printEntrada(0, 'W', c);
    if (c == 'w')
    {
        getAtomo(); //(
        if (c == '(')
        {
            getAtomo(); //
            R();
            if (c == ')')
            {
                getAtomo(); // {
                if (c == '{')
                {
                    getAtomo();
                    B();
                    if (c == '}')
                        getAtomo();
                    else
                        printConEsperado(0, 'W', '}', c);
                }
                else
                    printConEsperado(0, 'W', '{', c);
            }
            else
                printConEsperado(0, 'W', ')', c);
        }
        else
            printConEsperado(0, 'W', '(', c);
    }
    else
        printErrorNT(0, 'W', c);
    return;
}
void H() // Conjunto de selección: c.s={ h }
{
    printEntrada(0, 'H', c);
    if (c == 'h')
    {
        getAtomo(); //{
        if (c == '{')
        {
            getAtomo(); // x i w h p u t [ _
            B();
            if (c == '}')
            {
                getAtomo(); //w
                if (c == 'w')
                {
                    getAtomo(); // (
                    if (c == '(')
                    {
                        getAtomo();
                        R();
                        if (c == ')')
                            getAtomo();
                        if (c == ':')
                            getAtomo();
                        else
                            printConEsperado(0, 'H', ')', c);
                    }
                    else
                        printConEsperado(0, 'H', '(', c);
                }
                else
                    printConEsperado(0, 'H', 'w', c);
            }
            else
                printConEsperado(0, 'H', '}', c);
        }
        else
            printConEsperado(0, 'H', '{', c);
    }
    else
        printConEsperado(0, 'H', 'h', c);
    return;
}
void X() // Conjunto de selección: c.s={ x }
{
    printEntrada(0, 'X', c);
    if (c == 'x')
    {
        getAtomo(); //(
        if (c == '(')
        {
            getAtomo(); //a
            if (c == 'a')
            {
                getAtomo(); //{
                if (c == ')')
                {
                    getAtomo();
                    if (c == '{')
                    {
                        getAtomo();
                        O();
                        if (c == 'd')
                        {
                            getAtomo();
                            if (c == '[')
                            {
                                getAtomo();
                                B();
                                if (c == ']')
                                {
                                    getAtomo();
                                    if (c == '}')
                                        getAtomo();
                                }
                                else
                                    printConEsperado(0, 'X', ']', c);
                            }
                            else
                                printConEsperado(0, 'X', '[', c);
                        }
                        else
                            printConEsperado(0, 'X', 'd', c);
                    }
                    else
                        printConEsperado(0, 'X', '{', c);
                }
                else
                    printConEsperado(0, 'X', '(', c);
            }
            else
                printConEsperado(0, 'X', 'a', c);
        }
        else
            printConEsperado(0, 'X', '(', c);
    }
    else
        printConEsperado(0, 'X', 'x', c);
    return;
}
void O() // Conjunto de selección: c.s={ k d }
{
    printEntrada(0, 'O', c);
    if (c == 'k')
    {
        getAtomo(); //e
        if (c == 'e')
        {
            getAtomo(); //[
            if (c == '[')
            {
                getAtomo(); // x i w h p u t [ _
                B();
                if (c == ']')
                {
                    getAtomo(); //q
                    if (c == 'q')
                    {
                        getAtomo(); //:
                        if (c == ':')
                        {
                            getAtomo(); // k _
                            O();
                        }
                        else
                            printConEsperado(0, 'O', ':', c);
                    }
                    else
                        printConEsperado(0, 'O', 'q', c);
                }
                else
                    printConEsperado(0, 'O', ']', c);
            }
            else
                printConEsperado(0, 'O', '[', c);
        }
        else
            printConEsperado(0, 'O', 'e', c);
    }
    else if (c == '_' || c == 'd')
        return;
    else
        printConEsperado(0, 'O', 'k', c);
    return;
}
void B() // Conjunto de selección: c.s={ a x i w h p u t [ ] } }
{
    printEntrada(0, 'B', c);
    if (c == 'a' || c == 'x' || c == 'i' || c == 'w' || c == 'h' || c == 'p' || c == 'u' || c == 't' || c == '[')
    {
        S();
        B();
    }
    else if (c == '_' || c == ']' || c == '}')
        return;
    else
        printErrorNT(0, 'B', c);
    return;
}
void I() // Conjunto de selección: c.s={ i }
{
    printEntrada(0, 'I', c);
    if (c == 'i')
    {
        getAtomo(); //(
        if (c == '(')
        {
            getAtomo(); //( a e r [
            R();
            if (c == ')')
            {
                getAtomo(); //{
                if (c == '{')
                {
                    getAtomo(); // x i w h p u t [ _
                    B();
                    if (c == '}')
                    {
                        getAtomo(); // ele
                        J();
                        if (c == ':')
                            getAtomo(); //lo que sigue
                        else
                            printConEsperado(0, 'I', ':', c);
                    }
                    else
                        printConEsperado(0, 'I', '}', c);
                }
                else
                    printConEsperado(0, 'I', '{', c);
            }
            else
                printConEsperado(0, 'I', ')', c);
        }
        else
            printConEsperado(0, 'I', '(', c);
    }
    else
        printConEsperado(0, 'I', 'i', c);
    return;
}
void J() // Conjunto de selección: c.s={ l : }
{
    printEntrada(0, 'J', c);
    if (c == 'l')
    {
        getAtomo(); //{
        if (c == '{')
        {
            getAtomo(); // x i w h p u t [ _
            B();
            if (c == '}')
                getAtomo(); // lo que sigue
            else
                printConEsperado(0, 'J', '}', c);
        }
        else
            printConEsperado(0, 'J', '{', c);
    }
    else if (c == '_' || c == ':')
        return;
    else
        printConEsperado(0, 'J', 'l', c);
    return;
}
void N() // Conjunto de selección: c.s={ p }
{
    printEntrada(0, 'N', c);
    if (c == 'p')
    {
        getAtomo(); //[
        if (c == '[')
        {
            getAtomo(); //e
            if (c == 'e')
            {
                getAtomo(); //]
                if (c == ']')
                {
                    getAtomo(); //{
                    if (c == '{')
                    {
                        getAtomo(); // x i w h p u t [ _
                        B();
                        if (c == '}')
                            getAtomo(); //lo que sigue;
                        else
                            printConEsperado(0, 'N', '}', c);
                    }
                    else
                        printConEsperado(0, 'N', '{', c);
                }
                else
                    printConEsperado(0, 'N', ']', c);
            }
            else
                printConEsperado(0, 'N', 'e', c);
        }
        else
            printConEsperado(0, 'N', '[', c);
    }
    else
        printConEsperado(0, 'N', 'p', c);
    return;
}
void R() // Conjunto de selección: c.s={ ( a e r [ }
{
    printEntrada(0, 'R', c);
    if (c == '(' || c == 'a' || c == 'e' || c == 'r' || c == '[')
    {
        E();
        K();
        E();
    }
    else
        printErrorNT(0, 'R', c);
    return;
}
void K() // Conjunto de selección: c.s={ ! ? > < y m }
{
    printEntrada(0, 'K', c);
    if (c == '!' || c == '?' || c == '>' || c == '<' || c == 'y' || c == 'm')
        getAtomo();
    else
        printErrorNT(0, 'K', c);
    return;
}
void E() // Conjunto de selección: c.s={ ( a e r [ }
{
    printEntrada(0, 'E', c);
    if (c == '(' || c == 'a' || c == 'e' || c == 'r' || c == '[')
    {
        T();
        EP();
    }
    else if (c == ':')
        return;
    else
        printErrorNT(0, 'E', c);
    return;
}
void EP() // Conjunto de selección: c.s={ + - ! ? <> y m ) : }
{
    printEntrada(1, 'E', c);
    if (c == '+' || c == '-')
    {
        getAtomo();
        T();
        EP();
    }
    else if (c == '_' || c == '!' || c == '?' || c == '<' || c == '>' || c == 'y' || c == 'm' || c == ')' || c == ':')
        return;
    else
        printErrorNT(1, 'E', c);
    return;
}
void T() // Conjunto de selección: c.s={ ( a e r [ }
{
    printEntrada(0, 'T', c);
    if (c == '(' || c == 'a' || c == 'e' || c == 'r' || c == '[')
    {
        F();
        TP();
    }
    else
        printErrorNT(0, 'T', c);
    return;
}
void TP() // Conjunto de selección: c.s={ * / % # + - ! ? <> y m ) : }
{
    printEntrada(1, 'T', c);
    if (c == '*' || c == '/' || c == '%' || c == '#')
    {
        getAtomo();
        F();
        TP();
    }
    else if (c == '_' || c == '+' || c == '-' || c == '!' || c == '?' || c == '<' || c == '>' || c == 'y' || c == 'm' || c == ')' || c == ':')
        return;
    else
        printErrorNT(1, 'T', c);
    return;
}
void F() // Conjunto de selección: c.s={ ( a e r [ }
{
    printEntrada(0, 'F', c);
    if (c == '(')
    {
        getAtomo();
        E();
        if (c == ')')
            getAtomo();
        else
            printConEsperado(0, 'F', ')', c);
    }
    else if (c == 'a')
    {
        getAtomo();
        G();
    }
    else if (c == 'e' || c == 'r')
        getAtomo();
    else if (c == '[')
    {
        getAtomo(); //a
        if (c == 'a')
        {
            getAtomo(); //(
            if (c == '(')
            {
                getAtomo(); //)
                if (c == ')')
                {
                    getAtomo(); //]
                    if (c == ']')
                        getAtomo();
                    else
                        printConEsperado(0, 'F', ']', c);
                }
                else
                    printConEsperado(0, 'F', ')', c);
            }
            else
                printConEsperado(0, 'F', '(', c);
        }
        else
            printConEsperado(0, 'F', '[', c);
    }
    else
        printConEsperado(0, 'F', 'a', c);
    return;
}

void A() // Conjunto de selección: c.s={ a }
{
    printEntrada(0, 'A', c);
    if(c=='a')
    {
        getAtomo();//=
        if(c=='[')
            G();
        if(c=='=')
        {
            getAtomo(); // conjunto de selección M
            M();
            if(c==':')
                getAtomo(); //lo que sigue
        }
    }
    return;
}
void M() // Conjunto de selección: c.s={ ( a e r [ s + }
{
    printEntrada(0, 'M', c);
    if (c == '(' || c == 'a' || c == 'e' || c == 'r' || c == '[')
        E();
    else if (c == 's')
        getAtomo(); // :
    else if (c == '+')
    {
        getAtomo();
        L();
        if (c == ':')
            getAtomo();
        else
            printConEsperado(0, 'M', ':', c);
    }
    else
        printErrorNT(0, 'M', c);
    return;
}

// Función que notifica el error en un no terminal, e indica lo que esperaba
void printConEsperado(bool prima, char noTerminal, char esperado, char hay)
{
    if (prima == 1)
    {
        fprintf(archSalG, "EL ANALISIS SINTACTICO SE HA DETENIDO EN EL NO TERMINAL '%cP', CON EL ÁTOMO '%c' PORQUE SE ESPERABA ENCONTRAR '%c'\n", noTerminal, hay, esperado);
        printf("ERROR EN '%cP', SE ESPERABA '%c' PERO SE ENCONTRÓ '%c'\n", noTerminal, esperado, hay);
        printf("PARA MÁS DETALLES, CONSULTE EL ARCHIVO: salida.txt\n");
    }
    else
    {
        fprintf(archSalG, "EL ANÁLISIS SINTÁCTICO SE HA DETENIDO EN EL NO TERMINAL '%c', CON EL ÁTOMO '%c' PORQUE SE ESPERABA ENCONTRAR '%c'\n", noTerminal, hay, esperado);
        printf("ERROR EN '%c', SE ESPERABA '%c' PERO SE ENCONTRÓ '%c'\n", noTerminal, esperado, hay);
        printf("PARA MÁS DETALLES, CONSULTE EL ARCHIVO: 'salida.txt'\n");
    }
    exit(EXIT_FAILURE);
}

// Función que notifica el error en un no terminal, e indica lo que encontró
void printErrorNT(bool prima, char noTerminal, char hay)
{
    if (prima == 1)
    {
        fprintf(archSalG, "EL ANÁLISIS SINTÁCTICO SE HA DETENIDO EN EL NO TERMINAL '%c' CON EL ÁTOMO '%c'\n", noTerminal, c);
        printf("ERROR EN '%cP', NO SE ESPERABA '%c'\n", noTerminal, hay);
        printf("PARA MÁS DETALLES, CONSULTE EL ARCHIVO: salida.txt\n");
    }
    else
    {
        fprintf(archSalG, "EL ANÁLISIS SINTÁCTICO SE HA DETENIDO EN EL NO TERMINAL '%c' CON EL ÁTOMO '%c'\n", noTerminal, c);
        printf("ERROR EN '%c', NO SE ESPERABA '%c'\n", noTerminal, hay);
        printf("PARA MÁS DETALLES, CONSULTE EL ARCHIVO: salida.txt\n");
    }
    exit(EXIT_FAILURE);
}

// Función que notifica la entrada a un no terminal, y el atomo con el que se ingresa al mismo
void printEntrada(bool prima, char noTerminal, char caracter)
{
    if (prima == 1)
        fprintf(archSalG, "Entrando a '%cP' con el átomo = '%c'\n", noTerminal, c);
    else
        fprintf(archSalG, "Entrando a '%c' con el átomo = '%c'\n", noTerminal, c);
}
