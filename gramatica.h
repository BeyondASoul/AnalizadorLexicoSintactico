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
        return;
    }
    else
        printf("ERROR EN P\n");
}
void YP()
{
    if(c=='['){
        Y();
        return;
    }
    else if(c=='\0')
        return;
    else
        printf("ERROR EN YP\n");
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
        return;
    }
    else
        printf("ERROR EN Y\n");
}
void VP()
{
    if(c=='b'||c=='c'||c=='f'||c=='n'||c=='g'){
        V();
        return;
    }
    else if(c=='o')
        return;
    else 
        printf("ERROR EN VP \n");
}
void DP()
{
    if(c=='b'||c=='c'||c=='f'||c=='n'||c=='g'){
        D();
        return;
    }
    else if(c=='['||c=='\0')
        return;
    else 
        printf("ERROR EN DP\n");
}
void D()
{
    if(c=='b'||c=='c'||c=='f'||c=='n'||c=='g')
    {
        V();
        L();
        return;
    }
    else 
        printf("ERROR EN D\n");
}
void L()
{
    if(c=='a')
    {
        getAtomo();
        G();
        C();
        return;
    }
    else
        printf("ERROR EN L\n");
}
void C()
{
    if(c==',')
    {
        getAtomo();
        L();
        return;
    }
    else if(c=='\0')
        return;
    else
        printf("ERROR EN C\n");
}
void V() // TODO
{
    if(c=='b'||c=='c'||c=='f'||c=='n'||c=='g'){
        getAtomo();
        return;
    }
    else
        printf("ERROR EN V\n");
}
void G() // TODO
{
    if(c=='[')
    {
        getAtomo();//e
        getAtomo();//]
        getAtomo();//lo que sigue
        return;
    }
    else if(c=='\0')
        return;
    else 
        printf("ERROR EN G\n");
}
void S() // TODO
{
    if(c=='x')
    {
        X();
        return;
    }
    else if(c=='i')
    {
        I();
        return;
    }
    else if(c=='w')
    {
        W();
        return;
    }
    else if(c=='h')
    {
        H();
        return;
    }
    else if(c=='p')
    {
        N();
        return;
    }
    else if(c=='u')
    {
        getAtomo();// \0 (
        U();
        getAtomo();// lo que sigue
        return;
    }
    else if(c=='t')
    {
        getAtomo();//:
        getAtomo();//Lo que sigue
        return;
    }
    else if(c=='[')
    {
        getAtomo();//a
        getAtomo();//(
        getAtomo();//)
        getAtomo();//]
        getAtomo();//:
        getAtomo();//lo que sigue
        return;
    }
    else 
        printf("ERROR EN S\n");
}
void U() // TODO
{
    if(c=='(')
    {
        getAtomo(); //a e r [
        F();
        getAtomo();// lo que sigue
        return;
    }
    else if(c=='\0')
        return;
    else
        printf("ERROR EN U\n");
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
        return;
    }
    else
        printf("ERROR EN W\n");
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
        return;
    }
    else
        printf("ERROR EN H\n");
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
        return;
    }
    else
        printf("ERROR EN X\n");
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
        return;
    }
    else if(c=='\0')
        return;
    else 
        printf("ERROR EN O\n");
}
void B() // TODO
{
    if(c=='x'||c=='i'||c=='w'||c=='h'||c=='p'||c=='u'||c=='t'||c=='['){
        S();
        return;
    } 
    else if(c=='\0')
        return;
    else
        printf("ERROR EN B\n");
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
        return;
    }
    else
        printf("ERROR EN I\n");
}
void J() // TODO
{
    if(c=='l')
    {
        getAtomo();//{
        getAtomo();// x i w h p u t [ \0
        B();
        getAtomo();// lo que sigue
        return;
    }
    else if(c=='\0')
        return;
    else
        printf("ERROR EN J \n");
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
        return;
    }
    else
        printf("ERROR EN N \n");
}
void R() // TODO
{
    if(c=='('||c=='a'||c=='e'||c=='r'||c=='[')
    {
        E();
        K();
        E();
        return;
    }
    else
        printf("ERROR EN R\n");
}
void K() // TODO
{
    if(c=='!'||c=='?'||c=='>'||c=='<'||c=='y'||c=='m'){
        getAtomo();
        return;
    }
    else
        printf("ERROR EN K \n");
}
void E() // TODO
{
    if(c=='('||c=='a'||c=='e'||c=='r'||c=='[')
    {
        T();
        EP();
        return;
    }
    else
        printf("ERROR EN E\n");
}
void EP() // TODO
{
    if(c=='+')
    {
        getAtomo();
        T();
        EP();
        return;
    }
    else if(c=='-')
    {
        getAtomo();
        T();
        EP();
        return;
    }
    else if(c=='\0')
        return;
    else
        printf("ERROR EN EP\n");
}
void T() // TODO
{
    if(c=='('||c=='a'||c=='e'||c=='r'||c=='[')
    {
        F();
        TP();
        return;
    }
    else 
        printf("ERROR EN T\n");
}
void TP() // TODO
{
    if(c=='*'||c=='/'||c=='%'||c=='#')
    {
        getAtomo();
        F();
        TP();
        return;
    }
    else if(c=='\0')
        return;
    else 
        printf("ERROR EN TP\n");
}
void F() // TODO
{
    if(c=='(')
    {
        getAtomo();
        E();
        return;
    }
    else if(c=='a')
    {
        getAtomo();
        G();
        return;
    }
    else if(c=='e'||c=='r'){
        getAtomo();
        return;
    }
    else if(c=='[')
    {
        getAtomo(); //a
        getAtomo(); //(
        getAtomo(); //)
        getAtomo(); //]
        getAtomo();
        return;
    }
    else
        printf("ERROR EN F\n");
}




