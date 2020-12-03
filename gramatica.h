#include "tokens.h"

typedef int bool;
#define true 1
#define false 0
// Funciones
void getAtomo(); // Ayuda a obtener el siguiente atomo para analizar.
// Define los no termniales de las gramáticas, siendo P el indicador de prima
void P();  // inicial
void YP(); // Gramatica Y'
void Y();  // Gramatica Y
void VP(); // Gramatica V'
void DP(); // Gramatica D'
void D();  // Gramatica D
void L();  // Gramatica L
void C();  // Gramatica C
void V();  // Gramatica V
void G();  // Gramatica G
void S();  // Gramatica S
void U();  // Gramatica U
void W();  // Gramatica W
void H();  // Gramatica H
void X();  // Gramatica X
void O();  // Gramatica O
void B();  // Gramatica B
void I();  // Gramatica I
void J();  // Gramatica J
void N();  // Gramatica N
void R();  // Gramatica R
void K();  // Gramatica K
void E();  // Gramatica E
void EP(); // Gramatica E'
void T();  // Gramatica T
void TP(); // Gramatica T'
void F();  // Gramatica F
void A();  // TODO: Añadir la gramatica de asignación
void printConEsperado(bool prima, char noTerminal, char esperado, char hay);
void printErrorNT(bool prima, char noTerminal, char hay);

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
    fprintf(archSalG,"Atomo actual: c=%c\n",c);
}
// Definiendo la gramática como funciones
void P()
{
    printf("Entrando a P con c=%c\n", c);
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
    printf("Entrando a YP con c=%c\n", c);
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
    printf("Entrando a Y con c=%c\n", c);
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

                                fprintf(archSalG, "Terminó el análisis sintáctico con éxito...\n");
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
    printf("Entrando a VP con c=%c\n", c);
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
    printf("Entrando a DP con c=%c\n", c);
    if (c == 'b' || c == 'c' || c == 'f' || c == 'n' || c == 'g')
    {
        D();
        DP();
    }
    else if (c == 'x' || c == 'i' || c == 'w' || c == 'h' || c == 'p' || c == 'u' || c == 't' || c == '[' || c == '}' || c == '_')
        return;
    else
        printErrorNT(1, 'D', c);
    return;
}
void D()
{
    printf("Entrando a D con c=%c\n", c);
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
    printf("Entrando a L con c=%c\n", c);
    if (c == 'a')
    {
        getAtomo();
        G();
        C();
    }
    else
        printErrorNT(0, 'L', c);
    return;
}
void C()
{
    printf("Entrando a C con c=%c\n", c);
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
void V() // TODO
{
    printf("Entrando a V con c=%c\n", c);
    printf("Entrando a V con c=%c\n", c);
    if (c == 'b' || c == 'c' || c == 'f' || c == 'n' || c == 'g')
        getAtomo();
    else
        printErrorNT(0, 'V', c);
    return;
}
void G() // TODO
{
    printf("Entrando a G con c=%c\n", c);
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
    else if (c == '_' || c == ':' || c == ','||c=='('||c=='a'||c=='e'||c=='r'||c==')'||c=='+'||c=='-'||c=='#'||c=='%'||c=='/'||c=='*'||c=='!'||c=='?'||c=='<'||c=='>'||c=='y'||c=='m')
        return;
    else
        printConEsperado(0, 'G', '[', c);
    return;
}
void S() // TODO
{
    printf("Entrando a S con c=%c\n", c);
    if (c == 'x')
        X();
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
void U() // TODO
{
    printf("Entrando a U con c=%c\n", c);
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
void W() // TODO
{
    printf("Entrando a W con c=%c\n", c);
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
void H() // TODO
{
    printf("Entrando a H con c=%c\n", c);
    if (c == 'h')
    {
        getAtomo(); //{
        if (c == '{')
        {
            getAtomo(); // x i w h p u t [ _
            B();
            if (c == 'w')
            {
                getAtomo(); //(
                if (c == '(')
                {
                    getAtomo(); //( a e r [
                    R();
                    if (c == ')')
                    {
                        getAtomo();
                        if (c == ':')
                            getAtomo();
                        else
                            printConEsperado(0, 'H', ':', c);
                    }
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
            printConEsperado(0, 'H', '{', c);
    }
    else
        printConEsperado(0, 'H', 'h', c);
    return;
}
void X() // TODO
{
    printf("Entrando a X con c=%c\n", c);
    if (c == 'x')
    {
        getAtomo(); //(
        if (c == '(')
        {
            getAtomo(); //a
            if (c == 'a')
            {
                getAtomo(); //{
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
                                else
                                    printConEsperado(0, 'X', '}', c);
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
                printConEsperado(0, 'X', 'a', c);
        }
        else
            printConEsperado(0, 'X', '(', c);
    }
    else
        printConEsperado(0, 'X', 'x', c);
    return;
}
void O() // TODO
{
    printf("Entrando a O con c=%c\n", c);
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
void B() // TODO
{
    printf("Entrando a B con c=%c\n", c);
    if (c == 'x' || c == 'i' || c == 'w' || c == 'h' || c == 'p' || c == 'u' || c == 't' || c == '[')
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
void I() // TODO
{
    printf("Entrando a I con c=%c\n", c);
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
void J() // TODO
{
    printf("Entrando a J con c=%c\n", c);
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
void N() // TODO
{
    printf("Entrando a N con c=%c\n", c);
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
void R() // TODO
{
    printf("Entrando a R con c=%c\n", c);
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
void K() // TODO
{
    printf("Entrando a K con c=%c\n", c);
    if (c == '!' || c == '?' || c == '>' || c == '<' || c == 'y' || c == 'm')
        getAtomo();
    else
        printErrorNT(0, 'K', c);
    return;
}
void E() // TODO
{
    printf("Entrando a E con c=%c\n", c);
    if (c == '(' || c == 'a' || c == 'e' || c == 'r' || c == '[')
    {
        T();
        EP();
    }
    else
        printErrorNT(0, 'E', c);
    return;
}
void EP() // TODO
{
    printf("Entrando a EP con c=%c\n", c);
    if (c == '+' || c == '-')
    {
        getAtomo();
        T();
        EP();
    }
    else if (c == '_' || c == '!' || c == '?' || c == '<' || c == '>' || c == 'y' || c == 'm'||c==')')
        return;
    else
        printErrorNT(1, 'E', c);
    return;
}
void T() // TODO
{
    printf("Entrando a T con c=%c\n", c);
    if (c == '(' || c == 'a' || c == 'e' || c == 'r' || c == '[')
    {
        F();
        TP();
    }
    else
        printErrorNT(0, 'T', c);
    return;
}
void TP() // TODO
{
    printf("Entrando a TP con c=%c\n", c);
    if (c == '*' || c == '/' || c == '%' || c == '#')
    {
        getAtomo();
        F();
        TP();
    }
    else if (c == '_' || c == '+' || c == '-' || c == '!' || c == '?' || c == '<' || c == '>' || c == 'y' || c == 'm'||c==')')
        return;
    else
        printErrorNT(1, 'T', c);
    return;
}
void F() // TODO
{
    printf("Entrando a F con c=%c\n", c);
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

void printConEsperado(bool prima, char noTerminal, char esperado, char hay)
{
    if (prima == 1)
        printf("ERROR EN '%cP', SE ESPERABA '%c' PERO SE ENCONTRÓ '%c'\n", noTerminal, esperado, hay);
    else
        printf("ERROR EN '%c', SE ESPERABA '%c' PERO SE ENCONTRÓ '%c'\n", noTerminal, esperado, hay);
    exit(EXIT_FAILURE);
}
void printErrorNT(bool prima, char noTerminal, char hay)
{
    if (prima == 1)
        printf("ERROR EN '%cP', NO SE ESPERABA '%c'\n", noTerminal, hay);
    else
        printf("ERROR EN '%c', NO SE ESPERABA '%c'\n", noTerminal, hay);
    exit(EXIT_FAILURE);
}
