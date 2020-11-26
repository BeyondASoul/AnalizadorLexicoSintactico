#include "tokens.h"
// Funciones
void siguienteAtomo(); // Ayuda a obtener el siguiente atomo para analizar.
// Define los no termniales de las gramáticas, siendo P el indicador de prima
void P(); // inicial // TODO
void YP(); // TODO
void Y(); // TODO
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
// Demás funciones útiles
// TODO: Funcion que reconozca el error
// Varaibles globales
char   caracter; //caracter actual
Token* tokenAnt   = NULL; //Referencia al token anterior
Token* tokenAct   = NULL; //Referencia al token actual

void siguienteAtomo(){
    tokenAnt=tokenAct; // Se cambia la referencia del token anterior
    if (tokenAct->next==NULL){ // Agrega un token provisional para conocer el final
        tokenAct=NULL;
        caracter='_';
    }else{
        tokenAct=tokenAct->next; // Se cambia la referencia del token actual
        caracter=tokenAct->atomo; // el caracter almacena el atomo
    }
    return;
}
// Definiendo la gramática como funciones
