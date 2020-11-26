#include "tokens.h"
// Funciones
void siguienteAtomo(); // Ayuda a obtener el siguiente atomo para analizar.
// Define los no termniales de las gramáticas, siendo P el indicador de prima
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
        caracter=tokenAct->atomo; // el caracter almacena el atomo del token actual
    }
    return;
}
// Definiendo la gramática como funciones
void P(){
    // Derivando P en D'YY'
    DP();
    Y();
    YP();
}
void YP(){
    //Derivando Y' en YY'
    Y();
    YP();
    //TODO: Derivando en epsilon
}
void Y(){
    //Derivando Y en [
    if (caracter=='[')
    { // Comparando atomo
        siguienteAtomo();
        // Derivando Y en [V'
        VP();
        //Derivando Y en [V'a
        if (caracter=='a')
        {
            siguienteAtomo();
            // Derivando Y en [V'a(
            if (caracter=='(')
            {
                siguienteAtomo();
                // Derivando Y en [V'a()
                if (caracter==')')
                {
                    siguienteAtomo();
                    // Derivando Y en [V'a(){
                        if (caracter=='{')
                        {
                            siguienteAtomo();
                            // Derivando Y en [V'a(){D'
                            DP();
                            // Derivando Y en [V'a(){D'B
                            B();
                            // Derivando Y en [V'a(){D'B}
                            if (caracter=='}')
                            {
                                siguienteAtomo();
                                //Derivando Y en [V'a(){D'B}]
                                if (caracter==']')
                                {
                                    siguienteAtomo();
                                    return;
                                }
                                else
                                {
                                    printf("Error");
                                }
                            }
                            else
                            {
                                printf("Error");
                            }
                        }
                        else
                        {
                            printf("Error");
                        }
                }
                else
                {
                    printf("Error");
                }
            }
            else
            {
                printf("Error");
            }
            
        }
        else{
            printf("Error");
        }
    }
    else{
        printf("Error");
    }
}