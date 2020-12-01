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
        printf("c=%c\n",c);
    }
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
        Y();
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
        getAtomo();//(
        getAtomo();//)
        getAtomo();//{
        getAtomo();//b c f n g [ \0
        DP();
        B();
        getAtomo();//]
        getAtomo();
    }
    else
        printf("ERROR EN Y\n");
    return;
}
void VP()
{
    if(c=='b'||c=='c'||c=='f'||c=='n'||c=='g')
        V();
    else if(c=='o')
        return;
    else 
        printf("ERROR EN VP \n");
    return;
}
void DP()
{
    if(c=='b'||c=='c'||c=='f'||c=='n'||c=='g')
        D();
    else if(c=='['||c=='\0')
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
    else if(c=='\0')
        return;
    else
        printf("ERROR EN C\n");
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
    if(c=='[')
    {
        getAtomo();//e
        getAtomo();//]
        getAtomo();//lo que sigue
    }
    else if(c=='\0')
        return;
    else 
        printf("ERROR EN G\n");
    return;
}
void S() // TODO
{
    if(c=='x')
    {
        X();
    }
    else if(c=='i')
    {
        I();
    }
    else if(c=='w')
    {
        W();
    }
    else if(c=='h')
    {
        H();
    }
    else if(c=='p')
    {
        N();
    }
    else if(c=='u')
    {
        getAtomo();// \0 (
        U();
        getAtomo();// lo que sigue
    }
    else if(c=='t')
    {
        getAtomo();//:
        getAtomo();//Lo que sigue
    }
    else if(c=='[')
    {
        getAtomo();//a
        getAtomo();//(
        getAtomo();//)
        getAtomo();//]
        getAtomo();//:
        getAtomo();//lo que sigue
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
        getAtomo();// lo que sigue
    }
    else if(c=='\0')
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
        getAtomo();// ( a e r [
        R();
        getAtomo();//{
        getAtomo();// x i w h p u t [ \0
        B();
        getAtomo(); // lo que sigue
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
        getAtomo();// x i w h p u t [ \0
        B();
        getAtomo(); //w
        W();
        getAtomo(); //( a e r [
        R();
        getAtomo();//:
        getAtomo();//lo que siguue
    }
    else
        printf("ERROR EN H\n");
    return;
}
void X() // TODO
{
    if(c=='x')
    {
        getAtomo();//(
        getAtomo();//a
        getAtomo();//)
        getAtomo();//{
        getAtomo();// k \0
        O();
        getAtomo();//[
        getAtomo();// x i w h p u t [ \0
        B();
        getAtomo(); //}
        getAtomo(); //lo que sigue
    }
    else
        printf("ERROR EN X\n");
    return;
}
void O() // TODO
{
    if(c=='k')
    {
        getAtomo();//e
        getAtomo();//[
        getAtomo();// x i w h p u t [ \0
        B();
        getAtomo();//q
        getAtomo();//:
        getAtomo();// k \0
        O();
    }
    else if(c=='\0')
        return;
    else 
        printf("ERROR EN O\n");
    return;
}
void B() // TODO
{
    if(c=='x'||c=='i'||c=='w'||c=='h'||c=='p'||c=='u'||c=='t'||c=='[')
        S();
    else if(c=='\0')
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
        getAtomo();//( a e r [
        R();
        getAtomo();//{
        getAtomo();// x i w h p u t [ \0
        B();
        getAtomo();// ele
        J();
        getAtomo();//lo que sigue
    }
    else
        printf("ERROR EN I\n");
    return;
}
void J() // TODO
{
    if(c=='l')
    {
        getAtomo();//{
        getAtomo();// x i w h p u t [ \0
        B();
        getAtomo();// lo que sigue
    }
    else if(c=='\0')
        return;
    else
        printf("ERROR EN J \n");
    return;
}
void N() // TODO
{
    if(c=='p')
    {
        getAtomo();//[
        getAtomo();//e
        getAtomo();//]
        getAtomo();//{
        getAtomo();// x i w h p u t [ \0
        B();
        getAtomo();//lo que sigue;
    }
    else
        printf("ERROR EN N \n");
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
    if(c=='+')
    {
        getAtomo();
        T();
        EP();
    }
    else if(c=='-')
    {
        getAtomo();
        T();
        EP();
    }
    else if(c=='\0')
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
    else if(c=='\0')
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
        getAtomo(); //(
        getAtomo(); //)
        getAtomo(); //]
        getAtomo();
    }
    else
        printf("ERROR EN F\n");
    return;
}




