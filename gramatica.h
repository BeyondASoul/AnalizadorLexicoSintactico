#include "tokens.h"
// Funciones
void getAtomo(); // Ayuda a obtener el siguiente atomo para analizar.
// Define los no termniales de las gramáticas, siendo P el indicador de prima
void initGram(TokensList a);
void P(); // inicial 
void YP(); // Gramatica Y'
void Y(); // Gramatica Y
void VP(); // TODO
void DP(); // TODO
void D(); // TODO
void L(); // TODO
void C(); // TODO
void V(); // TODO
void G(); // TODO
void S(); // TODO
void U(); // TODO
void W(); // TODO
void H(); // TODO
void X(); // TODO
void O(); // TODO
void B(); // TODO
void I(); // TODO
void J(); // TODO
void N(); // TODO
void R(); // TODO
void K(); // TODO
void E(); // TODO
void EP(); // TODO
void T(); // TODO
void TP(); // TODO
void F(); // TODO
void A(); // TODO: Añadir la gramatica de asignación
Token* tokenAux;
TokensList tabla;
char c;
// Demás funciones útiles
// TODO: Funcion que reconozca el error
// Varaibles globales
/*char   caracter; //caracter actual
Token* tokenAnt   = NULL; //Referencia al token anterior
Token* tokenAct   = NULL; //Referencia al token actual
*/
void initGram(TokensList a)
{
    tabla=a;
    tokenAux=tabla.head;
}
void getAtomo()
{
    c=tokenAux->atomo;
    tokenAux=tokenAux->next;
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
        printf("ERROR EN P\n");
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
        printf("ERROR EN YP\n");
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
            getAtomo();//(
            if(c=='(')
            {
                getAtomo();//)
                if(c==')')
                {
                    getAtomo();//{
                    if(c=='{')
                    {
                        getAtomo();//b c f n g [ \0
                        DP();
                        B();
                        if(c=='}')
                            getAtomo();//]
                        else
                            printf("ERROR EN Y, SE ESPERABA: }\n");
                    }
                    else
                        printf("ERROR EN Y, SE ESPERABA: {\n");
                }
                else
                    printf("ERROR EN Y, SE ESPERABA: )\n");
            }
            else
                printf("ERROR EN Y, SE ESPERABA: (\n");
        }
        else
            printf("ERROR EN Y, SE ESPERABA: a\n");
    }
    else
        printf("ERROR EN Y, SE ESPERABA: [\n");
    return;
}
void VP()
{
    if(c=='b'||c=='c'||c=='f'||c=='n'||c=='g')
        V();
    else if(c=='o')
        getAtomo();
    else 
        printf("ERROR EN VP \n");
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
        printf("ERROR EN DP\n");
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
            printf("ERROR EN D, SE ESPERABA: :\n");
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
        printf("ERROR EN L\n");
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
        printf("ERROREN C\n");
    return;
}
void V() // TODO
{
    if(c=='b'||c=='c'||c=='f'||c=='n'||c=='g')
        getAtomo();
    else
        printf("ERROR EN V\n");
    return;
}
void G() // TODO
{
    getAtomo();
    if(c=='e')
    {
        getAtomo();//]
        if(c==']')
            getAtomo();//lo que sigue
        else
            printf("ERROR EN G, SE ESPERABA: ]\n");
    }
    else if(c=='\0')
        return;
    else 
        printf("ERROR EN G, SE ESPERABA: e\n");
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
            printf("ERROR EN S, SE ESPERABA: :\n");
    }
    else if(c=='t')
    {
        getAtomo();//:
        if(c==':')
            getAtomo();//Lo que sigue
        else
            printf("ERROR EN S, SE ESPERABA: :\n");
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
                            printf("ERROR EN S, SE ESPERABA: :\n");
                    }
                    else
                        printf("ERROR EN S, SE ESPERABA: ]\n");
                }
                else
                    printf("ERROR EN S, SE ESPERABA: )\n");
            }
            else
                printf("ERROR EN S, SE ESPERABA: (\n");
        }
        else
            printf("ERROR EN S, SE ESPERABA a\n");
    }
    else 
        printf("ERROR EN S\n");
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
            printf("ERROR EN U, SE ESBERABA: )\n");
    }
    else if(c==':')
        return;
    else
        printf("ERROR EN U\n");
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
                        printf("ERROR EN W, SE ESPERABA: }\n");
                }
                else
                    printf("ERROR EN W, SE ESPERABA: {\n");
            }
            else
                printf("ERROR EN W, SE ESPERABA: )\n");
        }
        else
            printf("ERROR EN W, SE ESPERABA: (\n");
    }
    else
        printf("ERROR EN W\n");
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
                            printf("ERROR EN H, SE ESPERABA: :\n");
                    }
                    else
                        printf("ERROR EN H, SE ESPERABA: )\n");
                }
                else
                    printf("ERROR EN H, SE ESPERABA: (\n");
            }
            else
                printf("ERROR EN H, SE ESPERABA: w\n");
        }
        else
            printf("ERROR EN H, SE ESPERABA: {\n");
    }
    else
        printf("ERROR EN H, SE ESPERABA: h\n");
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
                                    printf("ERROR EN X, SE ESPERABA: }\n");
                            }
                            else
                                printf("ERROR EN X, SE ESPERABA: ]\n");
                        }
                        else
                            printf("ERROR EN X, SE ESPERABA: [\n");
                    }
                    else
                        printf("ERROR EN X, SE ESPERABA: d\n");
                }
                else
                    printf("ERROR EN X, SE ESPERABA: {\n");
            }
            else
                printf("ERROR EN X, SE ESPERABA: a\n");
        }
        else
            printf("ERROR EN X, SE ESPERABA (\n");
    }
    else
        printf("ERROR EN X, SE ESPERABA: x\n");
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
                            printf("ERROR EN O, SE ESPERABA: :\n");
                    }
                    else
                        printf("ERROR EN O, SE ESPERABA: q\n");
                }
                else
                    printf("ERROR EN O, SE ESPERABA: ]\n");
            }
            else
                printf("ERROR EN O, SE ESPERABA: [\n");
        }
        else
            printf("ERROR EN O, SE ESPERABA: e\n");
    }
    else if(c=='\0'||c=='d')
        return;
    else 
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
        printf("ERROR EN B\n");
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
                            printf("ERROR EN I, SE ESPERABA: :\n");
                    }
                    else
                        printf("ERROR EN I, SE ESPERABA: }\n");
                }
                else
                    printf("ERROR EN I, SE ESPERABA: {\n");
            }
            else
                printf("ERROR EN I, SE ESPERABA: )\n");
        }
        else
            printf("ERROR EN I, SE ESPERABA: (\n");
    }
    else
        printf("ERROR EN I, SE ESPERABA: i\n");
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
                printf("ERROR EN J, SE ESPERABA: }\n");
        }
        else
            printf("ERROR EN J, SE ESPERABA: {\n");
    }
    else if(c=='\0'||c==':')
        return;
    else
        printf("ERROR EN J, SE ESPERAN: l\n");
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
                            printf("ERROR EN N, SE ESPERABA: }\n");
                    }
                    else
                        printf("ERROR EN N, SE ESPERAB: {\n");
                }
                else
                    printf("ERROR EN N, SE ESPERABA: ]\n");
            }
            else
                printf("ERROR EN N, SE ESPERABA: e\n");
        }
        else
            printf("ERROR EN N, SE ESPERABA: [\n");
    }
    else
        printf("ERROR EN N, SE ESPERABA: p \n");
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
        printf("ERROR EN R\n");
    return;
}
void K() // TODO
{
    if(c=='!'||c=='?'||c=='>'||c=='<'||c=='y'||c=='m')
        getAtomo();
    else
        printf("ERROR EN K \n");
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
        printf("ERROR EN E\n");
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
        printf("ERROR EN EP\n");
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
        printf("ERROR EN T\n");
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
        printf("ERROR EN TP\n");
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
            printf("ERROR EN F, SE ESPERABA: )\n");
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
                        printf("ERROR EN F, SE ESPERABA: ]\n");
                }
                else
                    printf("ERROR EN F, SE ESPERABA: )\n");
            }
            else
                printf("ERROR EN F, SE ESPERABA: (\n");
        }
        else
            printf("ERROR EN F, SE ESPERABA: (\n");
    }
    else
        printf("ERROR EN F, SE ESPERABA: a\n");
    return;
}




