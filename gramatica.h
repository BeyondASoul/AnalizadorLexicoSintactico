#include "tokens.h"

typedef int bool; 
#define true 1 
#define false 0 
// Funciones
void getAtomo(); // Ayuda a obtener el siguiente atomo para analizar.
// Define los no termniales de las gramáticas, siendo P el indicador de prima
void P(); // inicial 
void YP(); // Gramatica Y'
void Y(); // Gramatica Y
void VP(); // Gramatica V'
void DP(); // Gramatica D'
void D(); // Gramatica D
void L(); // Gramatica L
void C(); // Gramatica C
void V(); // Gramatica V
void G(); // Gramatica G
void S(); // Gramatica S
void U(); // Gramatica U
void W(); // Gramatica W
void H(); // Gramatica H
void X(); // Gramatica X
void O(); // Gramatica O
void B(); // Gramatica B
void I(); // Gramatica I
void J(); // Gramatica J
void N(); // Gramatica N
void R(); // Gramatica R
void K(); // Gramatica K
void E(); // Gramatica E
void EP(); // Gramatica E'
void T(); // Gramatica T
void TP(); // Gramatica T'
void F(); // Gramatica F
void A(); // TODO: Añadir la gramatica de asignación
void printConEsperado(bool prima,char noTerminal,char esperado,char hay);
void printErrorNT(bool prima,char noTerminal,char hay);

//Variables
char c;
Token* tokenAux=NULL;

/* Función para obtener el atomo siguiente e ir recorriendolos*/
void getAtomo()
{
    if (tokenAux->next==NULL){
        tokenAux=NULL;
        c='_';
    }else{
        tokenAux=tokenAux->next;
        c=tokenAux->atomo;
    }
    printf("c=%c\n",c);
}
// Definiendo la gramática como funciones
void P()
{
    if(c=='b'||c=='c'||c=='f'||c=='n'||c=='g'||c=='['||c=='\0')
    {
        DP();
        Y();
        YP();
    }
    else
        printErrorNT(0,'P',c);
    return;
}
void YP()
{
    if(c=='[')
    {
        Y();
        YP();
    }
    else if(c=='\0')
        return;
    else
        printErrorNT(1,'Y',c);
    return;
}
void Y()
{
    if(c=='[')
    {
        getAtomo();
        VP();
        if(c=='a')
        {
            getAtomo();
            if(c=='(')
            {
                getAtomo();
                if(c==')')
                {
                    getAtomo();
                    if(c=='{')
                    {
                        getAtomo();
                        DP();
                        B();
                        if(c=='}')
                            getAtomo();
                            if (c==']'){
                                if (tokenAux->next!=NULL)
                                    printConEsperado(0,'Y',']',c);
                                else
                                    printf("ANALISIS SINTÁCTICO TERMINADO CORRECTAMENTE\n");
                                    exit(EXIT_SUCCESS);
                            }
                        else
                            printConEsperado(0,'Y','}',c);
                    }
                    else
                        printConEsperado(0,'Y','{',c);
                }
                else
                    printConEsperado(0,'Y',')',c);
            }
            else
                printConEsperado(0,'Y','(',c);
        }
        else
            printConEsperado(0,'Y','a',c);
    }
    else
        printConEsperado(0,'Y','[',c);
    return;
}
void VP()
{
    if(c=='b'||c=='c'||c=='f'||c=='n'||c=='g')
        V();
    else if(c=='o')
        getAtomo();
    else 
        printErrorNT(1,'V',c);
    return;
}
void DP()
{
    if(c=='b'||c=='c'||c=='f'||c=='n'||c=='g')
    {
        D();
        DP();
    }
    else if(c=='x'||c=='i'||c=='w'||c=='h'||c=='p'||c=='u'||c=='t'||c=='['||c=='\0')
        return;
    else 
        printErrorNT(1,'D',c);
    return;
}
void D()
{
    if(c=='b'||c=='c'||c=='f'||c=='n'||c=='g')
    {
        V();
        L();
        if(c==':')
            getAtomo();
        else
            printErrorNT(0,'D',c);
    }
    else 
        printf("ERROR EN D\n");
    return;
}
void L()
{
    if(c=='a')
    {
        getAtomo();
        G();
        C();
    }
    else
        printErrorNT(0,'L',c);
    return;
}
void C()
{
    if(c==',')
    {
        getAtomo();
        L();
    }
    else if(c=='\0'||c==':')
        return;
    else
        printErrorNT(0,'C',c);
    return;
}
void V() // TODO
{
    if(c=='b'||c=='c'||c=='f'||c=='n'||c=='g')
        getAtomo();
    else
        printErrorNT(0,'V',c);
    return;
}
void G() // TODO
{
    if(c=='[')
    {
        getAtomo();//e
        if(c=='e')
        {
            getAtomo();//lo que sigue
            if (c==']')
                getAtomo();
            else
                printConEsperado(0,'G',']',c); 
        }
    }
    else if(c=='\0'||c==':'||c==',')
        return;
    else 
        printConEsperado(0,'G','[',c); 
    return;
}
void S() // TODO
{
    if(c=='x')
        X();
    else if(c=='i')
        I();
    else if(c=='w')
        W();
    else if(c=='h')
        H();
    else if(c=='p')
        N();
    else if(c=='u')
    {
        getAtomo();// \0 (
        U();
        if(c==':')
            getAtomo();// lo que sigue
        else
            printConEsperado(0,'S',':',c); 
    }
    else if(c=='t')
    {
        getAtomo();//:
        if(c==':')
            getAtomo();//Lo que sigue
        else
            printConEsperado(0,'S',':',c); 
    }
    else if(c=='[')
    {
        getAtomo();//a
        if(c=='a')
        {
            getAtomo();//(
            if(c=='(')
            {
                getAtomo();//)
                if(c==')')
                {
                    getAtomo();//]
                    if(c==']')
                    {
                        getAtomo();//:
                        if(c==':')
                            getAtomo();
                        else
                            printConEsperado(0,'S',':',c); 
                    }
                    else
                        printConEsperado(0,'S',']',c);
                }
                else
                    printConEsperado(0,'S',')',c);
            }
            else
                printConEsperado(0,'S','(',c);
        }
        else
            printConEsperado(0,'S','a',c);
    }
    else 
        printErrorNT(0,'S',c);
    return;
}
void U() // TODO
{
    if(c=='(')
    {
        getAtomo(); //a e r [
        F();
        if(c==')')
            getAtomo();// lo que sigue
        else
            printConEsperado(0,'U',')',c);
    }
    else if(c==':')
        return;
    else
        printErrorNT(0,'U',c);
    return;
}
void W() // TODO
{
    if(c=='w')
    {
        getAtomo();//(
        if(c=='(')
        {
            getAtomo();//
            R();
            if(c==')')
            {
                getAtomo();// {
                if(c=='{')
                {
                    getAtomo();
                    B();
                    if(c=='}')
                        getAtomo();
                    else
                        printConEsperado(0,'W','}',c);
                }
                else
                    printConEsperado(0,'W','{',c);
            }
            else
                printConEsperado(0,'W',')',c);
        }
        else
            printConEsperado(0,'W','(',c);
    }
    else
        printErrorNT(0,'W',c);
    return;
}
void H() // TODO
{
    if(c=='h')
    {
        getAtomo();//{
        if(c=='{')
        {
            getAtomo();// x i w h p u t [ \0
            B();
            if(c=='w')
            {
                getAtomo(); //(
                if(c=='(')
                {
                    getAtomo(); //( a e r [
                    R();
                    if(c==')')
                    {
                        getAtomo();
                        if(c==':')
                            getAtomo();
                        else
                            printConEsperado(0,'H',':',c);
                    }
                    else
                        printConEsperado(0,'H',')',c);
                }
                else
                    printConEsperado(0,'H','(',c);
            }
            else
                printConEsperado(0,'H','w',c);
        }
        else
            printConEsperado(0,'H','{',c);
    }
    else
        printConEsperado(0,'H','h',c);
    return;
}
void X() // TODO
{
    if(c=='x')
    {
        getAtomo();//(
        if(c=='(')
        {
            getAtomo();//a
            if(c=='a')
            {
                getAtomo();//{
                if(c=='{')
                {
                    getAtomo();
                    O();
                    if(c=='d')
                    {
                        getAtomo();
                        if(c=='[')
                        {
                            getAtomo();
                            B();
                            if(c==']')
                            {
                                getAtomo();
                                if(c=='}')
                                    getAtomo();
                                else
                                    printConEsperado(0,'X','}',c);
                            }
                            else
                                printConEsperado(0,'X',']',c);
                        }
                        else
                            printConEsperado(0,'X','[',c);
                    }
                    else
                        printConEsperado(0,'X','d',c);
                }
                else
                    printConEsperado(0,'X','{',c);
            }
            else
                printConEsperado(0,'X','a',c);
        }
        else
            printConEsperado(0,'X','(',c);
    }
    else
        printConEsperado(0,'X','x',c);
    return;
}
void O() // TODO
{
    if(c=='k')
    {
        getAtomo();//e
        if(c=='e')
        {
            getAtomo();//[
            if(c=='[')
            {
                getAtomo();// x i w h p u t [ \0
                B();
                if(c==']')
                {
                    getAtomo();//q
                    if(c=='q')
                    {
                        getAtomo();//:
                        if(c==':')
                        {
                            getAtomo();// k \0
                            O();
                        }
                        else
                            printConEsperado(0,'O',':',c);
                    }
                    else
                        printConEsperado(0,'O','q',c);
                }
                else
                    printConEsperado(0,'O',']',c);
            }
            else
                printConEsperado(0,'O','[',c);
        }
        else
            printConEsperado(0,'O','e',c);
    }
    else if(c=='\0'||c=='d')
        return;
    else 
        printConEsperado(0,'O','k',c);
        printf("ERROR EN O, SE ESPERABA: k\n");
    return;
}
void B() // TODO
{
    if(c=='x'||c=='i'||c=='w'||c=='h'||c=='p'||c=='u'||c=='t'||c=='[')
    {
        S();
        B();
    }
    else if(c=='\0'||c==']'||c=='}')
        return;
    else
        printErrorNT(0,'B',c);
    return;
}
void I() // TODO
{
    if(c=='i')
    {
        getAtomo();//(
        if(c=='(')
        {
            getAtomo();//( a e r [
            R();
            if(c==')')
            {
                getAtomo();//{
                if(c=='{')
                {
                    getAtomo();// x i w h p u t [ \0
                    B();
                    if(c=='}')
                    {
                        getAtomo();// ele
                        J();
                        if(c==':')
                            getAtomo();//lo que sigue
                        else
                            printConEsperado(0,'I',':',c);
                            printf("ERROR EN I, SE ESPERABA: :\n");
                    }
                    else
                        printConEsperado(0,'I','}',c);
                }
                else
                    printConEsperado(0,'I','{',c);
            }
            else
                printConEsperado(0,'I',')',c);
        }
        else
            printConEsperado(0,'I','(',c);
    }
    else
        printConEsperado(0,'I','i',c);
    return;
}
void J() // TODO
{
    if(c=='l')
    {
        getAtomo();//{
        if(c=='{')
        {
            getAtomo();// x i w h p u t [ \0
            B();
            if(c=='}')
                getAtomo();// lo que sigue
            else
                printConEsperado(0,'J','}',c);
        }
        else
            printConEsperado(0,'J','{',c);
    }
    else if(c=='\0'||c==':')
        return;
    else
            printConEsperado(0,'J','l',c);
    return;
}
void N() // TODO
{
    if(c=='p')
    {
        getAtomo();//[
        if(c=='[')
        {
            getAtomo();//e
            if(c=='e')
            {
                getAtomo();//]
                if(c==']')
                {
                    getAtomo();//{
                    if(c=='{')
                    {
                        getAtomo();// x i w h p u t [ \0
                        B();
                        if(c=='}')
                            getAtomo();//lo que sigue;
                        else
                            printConEsperado(0,'N','}',c);
                    }
                    else
                        printConEsperado(0,'N','{',c);
                }
                else
                    printConEsperado(0,'N',']',c);
                    printf("ERROR EN N, SE ESPERABA: ]\n");
            }
            else
                printConEsperado(0,'N','e',c);
        }
        else
            printConEsperado(0,'N','[',c);
    }
    else
        printConEsperado(0,'N','p',c);
    return;
}
void R() // TODO
{
    if(c=='('||c=='a'||c=='e'||c=='r'||c=='[')
    {
        E();
        K();
        E();
    }
    else
        printErrorNT(0,'R',c);
        printf("ERROR EN R\n");
    return;
}
void K() // TODO
{
    if(c=='!'||c=='?'||c=='>'||c=='<'||c=='y'||c=='m')
        getAtomo();
    else
        printErrorNT(0,'K',c);
    return;
}
void E() // TODO
{
    if(c=='('||c=='a'||c=='e'||c=='r'||c=='[')
    {
        T();
        EP();
    }
    else
        printErrorNT(0,'E',c);
    return;
}
void EP() // TODO
{
    if(c=='+'||c=='-')
    {
        getAtomo();
        T();
        EP();
    }
    else if(c=='\0'||c=='('||c=='a'||c=='e'||c=='r'||c=='['||c==')')
        return;
    else
        printErrorNT(1,'E',c);
    return;
}
void T() // TODO
{
    if(c=='('||c=='a'||c=='e'||c=='r'||c=='[')
    {
        F();
        TP();
    }
    else 
        printErrorNT(0,'T',c);
    return;
}
void TP() // TODO
{
    if(c=='*'||c=='/'||c=='%'||c=='#')
    {
        getAtomo();
        F();
        TP();
    }
    else if(c=='\0'||c=='('||c=='a'||c=='e'||c=='r'||c=='['||c==')'||c=='+'||c=='-')
        return;
    else 
        printErrorNT(1,'T',c);
    return;
}
void F() // TODO
{
    if(c=='(')
    {
        getAtomo();
        E();
        if(c==')')
            getAtomo();
        else
            printConEsperado(0,'F',')',c);
    }
    else if(c=='a')
    {
        getAtomo();
        G();
    }
    else if(c=='e'||c=='r')
        getAtomo();
    else if(c=='[')
    {
        getAtomo(); //a
        if(c=='a')
        {
            getAtomo(); //(
            if(c=='(')
            {
                getAtomo(); //)
                if(c==')')
                {
                    getAtomo(); //]
                    if(c==']')
                        getAtomo();
                    else
                        printConEsperado(0,'F',']',c);
                }
                else
                    printConEsperado(0,'F',')',c);
            }
            else
                printConEsperado(0,'F','(',c);
        }
        else
            printConEsperado(0,'F','[',c);
    }
    else
        printConEsperado(0,'F','a',c);
    return;
}

void printConEsperado(bool prima,char noTerminal,char esperado,char hay){
    if (prima == 1)
        printf("ERROR EN '%cP', SE ESPERABA '%c' PERO SE ENCONTRÓ '%c'\n", noTerminal, esperado, hay);
    else
        printf("ERROR EN '%c', SE ESPERABA '%c' PERO SE ENCONTRÓ '%c'\n", noTerminal, esperado, hay);
    //exit(EXIT_FAILURE);
}
void printErrorNT(bool prima,char noTerminal, char hay){
    if (prima == 1)
        printf("ERROR EN '%cP', NO SE ESPERABA '%c'\n", noTerminal, hay);
    else
        printf("ERROR EN '%c', NO SE ESPERABA '%c'\n", noTerminal, hay);
    //exit(EXIT_FAILURE);
}

