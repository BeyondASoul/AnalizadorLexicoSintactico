#include "tokens.h"
// Funciones
void siguienteAtomo(); // Ayuda a obtener el siguiente atomo para analizar.
// Define los no termniales de las gramáticas, siendo P el indicador de prima
void P(char c); // inicial 
void YP(char c); // Gramatica Y'
void Y(char c); // Gramatica Y
void VP(char c); // TODO
void DP(char c); // TODO
void D(char c); // TODO
void L(char c); // TODO
void C(char c); // TODO
void V(char c); // TODO
void G(char c); // TODO
void S(char c); // TODO
void U(char c); // TODO
void W(char c); // TODO
void H(char c); // TODO
void X(char c); // TODO
void O(char c); // TODO
void B(char c); // TODO
void I(char c); // TODO
void J(char c); // TODO
void N(char c); // TODO
void R(char c); // TODO
void K(char c); // TODO
void E(char c); // TODO
void EP(char c); // TODO
void T(char c); // TODO
void TP(char c); // TODO
void F(char c); // TODO
void A(char c); // TODO: Añadir la gramatica de asignación
// Demás funciones útiles
// TODO: Funcion que reconozca el error
// Varaibles globales
/*char   caracter; //caracter actual
Token* tokenAnt   = NULL; //Referencia al token anterior
Token* tokenAct   = NULL; //Referencia al token actual

void siguienteAtomo(){
    tokenAnt=tokenAct; // Se cambia la referencia del token anterior
    if (tokenAct->next==NULL){ // Agrega un token provisional para conocer el final
        tokenAct=NULL;
        caracter='_';
    }else{
        tokenAct=tokenAct->next; // Se cambia la referencia del token actual
        caracter=tokenAct->atomo; // el caracter almacena el atomo del token actual
    }
    return;
}*/
// Definiendo la gramática como funciones
void P(char c)
{

    if(c=="b"||c=="c"||c=="f"||c=="n"||c=="g"||c=="["||c=="\0")
    {
        DP(c);
        Y(c);
        YP(c);
    }
    else
        printf("ERROR\n");
    return;
}
void YP(char c)
{
    if(c=="[")
        Y(c);
    else if(c=="\0")
        return;
    else
        printf("ERROR\n");
    return;
}
void Y(char c)
{
    if(c=="[")
    {
        c=getchar();
        VP(c);
        getchar();//(
        getchar();//)
        getchar();//{
        c=getchar();//b c f n g [ \0
        DP(c);
        B(c);
        getchar();//]
        c=getchar();
    }
    else
        printf("ERROR\n");
    return;
}
void VP(char c)
{
    if(c=="b"||c=="c"||c=="f"||c=="n"||c=="g")
        V(c);
    else if(c=="o")
        return;
    else 
        printf("ERROR\n");
    return;
}
void DP(char c)
{
    if(c=="b"||c=="c"||c=="f"||c=="n"||c=="g")
        D(c);
    else if(c=="["||c=="\0")
        return;
    else 
        printf("ERROR\n");
    return;
}
void D(char c)
{
    if(c=="b"||c=="c"||c=="f"||c=="n"||c=="g")
    {
        V(c);
        L(c);
    }
    else 
        printf("ERROR\n");
    return;
}
void L(char c)
{
    if(c=="a")
    {
        c=getchar();
        G(c);
        C(c);
    }
    else
        printf("ERROR\n");
    return;
}
void C(char c)
{
    if(c==",")
    {
        c=getchar();
        L(c);
    }
    else if(c=="\0")
        return;
    else
        printf("ERROR\n");
    return;
}
void V(char c) // TODO
{
    if(c=="b"||c=="c"||c=="f"||c=="n"||c=="g")
        c=getchar();
    else
        printf("ERROR\n");
    return;
}
void G(char c) // TODO
{
    if(c=="[")
    {
        getchar();//e
        getchar();//]
        c=getchar();//lo que sigue
    }
    else if(c=="\0")
        return;
    else 
        printf("ERROR\n");
    return;
}
void S(char c) // TODO
{
    if(c=="x")
    {
        X(c);
    }
    else if(c=="i")
    {
        I(c);
    }
    else if(c=="w")
    {
        W(c);
    }
    else if(c=="h")
    {
        H(c);
    }
    else if(c=="p")
    {
        N(c);
    }
    else if(c=="u")
    {
        c=getchar();// \0 (
        U(c);
        c=getchar();// lo que sigue
    }
    else if(c=="t")
    {
        getchar();//:
        c=getchar();//Lo que sigue
    }
    else if(c=="[")
    {
        getchar();//a
        getchar();//(
        getchar();//)
        getchar();//]
        getchar();//:
        c=getchar();//lo que sigue
    }
    else 
        printf("ERROR\n");
    return;
}
void U(char c) // TODO
{
    if(c=="(")
    {
        c=getchar(); //a e r [
        F(c);
        c=getchar();// lo que sigue
    }
    else if(c=="\0")
        return;
    else
        printf("ERROR\n");
    return;
}
void W(char c) // TODO
{
    if(c=="w")
    {
        getchar();//(
        c=getchar();// ( a e r [
        R(c);
        getchar();//{
        c=getchar();// x i w h p u t [ \0
        B(c);
        c=getchar(); // lo que sigue
    }
    else
        printf("ERROR\n");
    return;
}
void H(char c) // TODO
{
    if(c=="h")
    {
        getchar();//{
        c=getchar();// x i w h p u t [ \0
        B(c);
        c=getchar(); //w
        W(c);
        c=getchar(); //( a e r [
        R(c);
        getchar();//:
        c=getchar();//lo que siguue
    }
    else
        printf("ERROR\n");
    return;
}
void X(char c) // TODO
{
    if(c=="x")
    {
        getchar();//(
        getchar();//a
        getchar();//)
        getchar();//{
        c=getchar();// k \0
        O(c);
        getchar();//[
        c=getchar();// x i w h p u t [ \0
        B(c);
        getchar(); //}
        c=getchar(); //lo que sigue
    }
    else
        printf("ERROR\n");
    return;
}
void O(char c) // TODO
{
    if(c=="k")
    {
        getchar();//e
        getchar();//[
        c=getchar();// x i w h p u t [ \0
        B(c);
        getchar();//q
        getchar();//:
        c=getchar();// k \0
        O(c);
    }
    else if(c=="\0")
        return;
    else 
        printf("ERROR\n");
    return;
}
void B(char c) // TODO
{
    if(c=="x"||c=="i"||c=="w"||c=="h"||c=="p"||c=="u"||c=="t"||c=="[")
        S(c);
    else if(c=="\0")
        return;
    else
        printf("ERROR\n");
    return;
}
void I(char c) // TODO
{
    if(c=="i")
    {
        getchar();//(
        c=getchar();//( a e r [
        R(c);
        getchar();//{
        c=getchar();// x i w h p u t [ \0
        B(c);
        c=getchar();// ele
        J(c);
        c=getchar();//lo que sigue
    }
    else
        printf("ERROR\n");
    return;
}
void J(char c) // TODO
{
    if(c=="l")
    {
        getchar();//{
        c=getchar();// x i w h p u t [ \0
        B(c);
        c=getchar();// lo que sigue
    }
    else if(c=="\0")
        return;
    else
        printf("ERROR\n");
    return;
}
void N(char c) // TODO
{
    if(c=="p")
    {
        getchar();//[
        getchar();//e
        getchar();//]
        getchar();//{
        c=getchar();// x i w h p u t [ \0
        B(c);
        c=getchar();//lo que sigue;
    }
    else
        printf("ERROR\n");
    return;
}
void R(char c) // TODO
{
    if(c=="("||c=="a"||c=="e"||c=="r"||c=="[")
    {
        E(c);
        K(c);
        E(c);
    }
    else
        printf("ERROR\n");
    return;
}
void K(char c) // TODO
{
    if(c=="!"||c=="?"||c==">"||c=="<"||c=="y"||c=="m")
        c=getchar();
    else
        printf("ERROR\n");
    return;
}
void E(char c) // TODO
{
    if(c=="("||c=="a"||c=="e"||c=="r"||c=="[")
    {
        T(c);
        EP(c);
    }
    else
        printf("ERROR\n");
    return;
}
void EP(char c) // TODO
{
    if(c=="+")
    {
        c=getchar();
        T(c);
        EP(c);
    }
    else if(c=="-")
    {
        c=getchar();
        T(c);
        EP(c);
    }
    else if(c=="\0")
        return;
    else
        printf("ERROR\n");
    return;
}
void T(char c) // TODO
{
    if(c=="("||c=="a"||c=="e"||c=="r"||c=="[")
    {
        F(c);
        TP(c);
    }
    else 
        printf("ERROR\n");
    return;
}
void TP(char c) // TODO
{
    if(c=="*"||c=="/"||c=="%"||c=="#")
    {
        c=getchar();
        F(c);
        TP(c);
    }
    else if(c=="\0")
        return;
    else 
        printf("ERROR\n");
    return;
}
void F(char c) // TODO
{
    if(c=="(")
    {
        c=getchar();
        E(c);
    }
    else if(c=="a")
    {
        c=getchar();
        G(c);
    }
    else if(c=="e"||c=="r")
        c=getchar();
    else if(c=="[")
    {
        getchar(); //a
        getchar(); //(
        getchar(); //)
        getchar(); //]
        c=getchar();
    }
    else
        printf("ERROR\n");
    return;
}




