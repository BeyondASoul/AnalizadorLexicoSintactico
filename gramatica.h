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
void P()
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
void YP()
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
void Y()
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
void VP()
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
void DP()
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
void D()
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
void L()
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
void C()
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
void V()
{
    printEntrada(0, 'V', c);
    if (c == 'b' || c == 'c' || c == 'f' || c == 'n' || c == 'g')
        getAtomo();
    else
        printErrorNT(0, 'V', c);
    return;
}
void G()
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
    else if (c == '_' || c == ':' || c == ',' || c == '(' || c == 'a' || c == 'e' || c == 'r' || c == ')' || c == '+' || c == '-' || c == '#' || c == '%' || c == '/' || c == '*' || c == '!' || c == '?' || c == '<' || c == '>' || c == 'y' || c == 'm')
        return;
    else
        printConEsperado(0, 'G', '[', c);
    return;
}
void S()
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
void U()
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
void W()
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
void H()
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
void X()
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
void O()
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
void B()
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
void I()
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
void J()
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
void N()
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
void R()
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
void K()
{
    printEntrada(0, 'K', c);
    if (c == '!' || c == '?' || c == '>' || c == '<' || c == 'y' || c == 'm')
        getAtomo();
    else
        printErrorNT(0, 'K', c);
    return;
}
void E()
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
void EP()
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
void T()
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
void TP()
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
void F()
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
void A()
{
    printEntrada(0, 'A', c);
    if (c == 'a')
    {
        getAtomo();
        if (c == '=')
        {
            getAtomo();
            M();
            if (c == ':')
                getAtomo();
        }
    }
    return;
}
void M()
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
void printConEsperado(bool prima, char noTerminal, char esperado, char hay)
{
    if (prima == 1)
    {
        fprintf(archSalG,"EL ANALISIS SINTACTICO SE HA DETENIDO EN EL NO TERMINAL '%cP', CON EL ÁTOMO '%c' PORQUE SE ESPERABA ENCONTRAR '%c'\n",noTerminal,hay,esperado);
        printf("ERROR EN '%cP', SE ESPERABA '%c' PERO SE ENCONTRÓ '%c'\n", noTerminal, esperado, hay);
        printf("PARA MÁS DETALLES, CONSULTE EL ARCHIVO: salida.txt\n");
    }
    else
    {
        fprintf(archSalG,"EL ANÁLISIS SINTÁCTICO SE HA DETENIDO EN EL NO TERMINAL '%c', CON EL ÁTOMO '%c' PORQUE SE ESPERABA ENCONTRAR '%c'\n",noTerminal,hay,esperado);
        printf("ERROR EN '%c', SE ESPERABA '%c' PERO SE ENCONTRÓ '%c'\n", noTerminal, esperado, hay);
        printf("PARA MÁS DETALLES, CONSULTE EL ARCHIVO: 'salida.txt'\n");
    }
    exit(EXIT_FAILURE);
}
void printErrorNT(bool prima, char noTerminal, char hay)
{
    if (prima == 1)
    {
        fprintf(archSalG,"EL ANÁLISIS SINTÁCTICO SE HA DETENIDO EN EL NO TERMINAL '%c' CON EL ÁTOMO '%c'\n",noTerminal,c);
        printf("ERROR EN '%cP', NO SE ESPERABA '%c'\n", noTerminal, hay);
        printf("PARA MÁS DETALLES, CONSULTE EL ARCHIVO: salida.txt\n");
    }
    else
    {
        fprintf(archSalG,"EL ANÁLISIS SINTÁCTICO SE HA DETENIDO EN EL NO TERMINAL '%c' CON EL ÁTOMO '%c'\n",noTerminal,c);
        printf("ERROR EN '%c', NO SE ESPERABA '%c'\n", noTerminal, hay);
        printf("PARA MÁS DETALLES, CONSULTE EL ARCHIVO: salida.txt\n");
    }
    exit(EXIT_FAILURE);
}

void printEntrada(bool prima, char noTerminal, char caracter)
{
    if (prima == 1)
        fprintf(archSalG, "Entrando a '%cP' con el átomo = '%c'\n", noTerminal, c);
    else
        fprintf(archSalG, "Entrando a '%c' con el átomo = '%c'\n", noTerminal, c);
}
