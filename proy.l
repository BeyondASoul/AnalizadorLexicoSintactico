/*SILVA NUÑEZ ALEJANDRO BRYAN*/
/*SANTIAGO VILLEGAS FERNANDO*/
/*ANALIZADOR LÉXICO*/
/*COMPILADORES*/
/*ENTREGA: 29/10/2020*/
/*ELABORACIÓN: DEL XX/XX/XXXX AL 27/10/2020.*/

%{
/*LOS ARCHIVOS SE UTILIZAN PARA ARMAR LAS TABLAS NECESARIAS, GUARDAR LOS TOKENS Y ALMACENAR LOS ERRORES.
PARA TENER INDICES DE LAS TABLAS UTILIZAMOS LAS VARIABLES IDEN, CTE Y CAD*/
FILE *identificadores;
FILE *cadenas;
FILE *numeros;
FILE *tokens;
FILE *x;
int iden=-1;
int cte=-1;
int cad=-1;
%}
%option noyywrap


/*EXPRESIONES BÁSICAS*/

num [0-9]
let [a-zA-Z]
espacio [[:space:]]
comentunalinea "//".*" "*
comentmulti \/\*(.*\n)*.*\*\/


/*EXPRESIONES DE CLASE*/

real {num}+(\.)+{num}+
clase0epos {real}((e|E)({espacio}|"+"){num}+)?
clase0eneg {real}((e|E)({espacio}?"-")({num}+))
clase1bo ("bool")
clase1br ("break")
clase1ca ("case")
clase1ch ("char")
clase1co ("continue")
clase1de ("default")
clase1do ("do")
clase1el ("else")
clase1fl ("float")
clase1fo ("for")
clase1if ("if")
clase1in ("int")
clase1re ("returnt")
clase1st ("string")
clase1sw ("switch")
clase1wh ("while")
clase1vo ("void")
clase2lli ("{")
clase2lld ("}")
clase2co (",")
clase2dp (":")
clase2pi ("(")
clase2pd (")")
clase2ci ("[")
clase2cd ("]")
clase3 {let}+({let}|{num}|("_"))*
clase4 ("=")
clase5nc ("!"{clase4})
clase5dc ({clase4}{clase4})
clase5mq (">")
clase5nq ("<")
clase5mi (">"{clase4})
clase5ni ("<"{clase4})
clase6 {num}{1,14}
clase7 \"([^\"]*)\"
clase8m ("+")
clase8g ("-")
clase8aa ("**")
clase8a ("*")
clase8d ("/")
clase8p ("%")

/*UNA VEZ QUE SE TIENEN LAS EXPRESIONES REGULARES DE LAS CLASES, SE CREARÁN LAS DIFERENTES ACCIONES*/
/*QUE EL PROGRAMA REALIZARÁ DEPENDIENDO DE LA EXPRESIÓN REGULAR RECONOCIDA*/
%%

{clase0epos} {cte++;fprintf(numeros,"%d                 %s\n",cte,yytext);fprintf(tokens,"%d,%d",0,cte);}
{clase0eneg} {cte++;fprintf(numeros,"%d                 %s\n",cte,yytext);fprintf(tokens,"%d,%d",0,cte);}
{clase1bo} {fprintf(tokens,"%d,%d\n",1,0);}
{clase1br} {fprintf(tokens,"%d,%d\n",1,1);}
{clase1ca} {fprintf(tokens,"%d,%d\n",1,2);}
{clase1ch} {fprintf(tokens,"%d,%d\n",1,3);}
{clase1co} {fprintf(tokens,"%d,%d\n",1,4);}
{clase1de} {fprintf(tokens,"%d,%d\n",1,5);}
{clase1do} {fprintf(tokens,"%d,%d\n",1,6);}
{clase1el} {fprintf(tokens,"%d,%d\n",1,7);}
{clase1fl} {fprintf(tokens,"%d,%d\n",1,8);}
{clase1fo} {fprintf(tokens,"%d,%d\n",1,9);}
{clase1if} {fprintf(tokens,"%d,%d\n",1,10);}
{clase1in} {fprintf(tokens,"%d,%d\n",1,11);}
{clase1re} {fprintf(tokens,"%d,%d\n",1,12);}
{clase1st} {fprintf(tokens,"%d,%d\n",1,13);}
{clase1sw} {fprintf(tokens,"%d,%d\n",1,14);}
{clase1wh} {fprintf(tokens,"%d,%d\n",1,15);}
{clase1vo} {fprintf(tokens,"%d,%d\n",1,16);}
{clase2lli} {fprintf(tokens,"%d,%d\n",2,123);}
{clase2lld} {fprintf(tokens,"%d,%d\n",2,125);}
{clase2co} {fprintf(tokens,"%d,%d\n",2,44);}
{clase2dp} {fprintf(tokens,"%d,%d\n",2,58);}
{clase2pi} {fprintf(tokens,"%d,%d\n",2,40);}
{clase2pd} {fprintf(tokens,"%d,%d\n",2,41);}
{clase2ci} {fprintf(tokens,"%d,%d\n",2,91);}
{clase2cd} {fprintf(tokens,"%d,%d\n",2,93);}
{clase3} {iden++;fprintf(identificadores,"%d                 %s               %d\n",iden,yytext,-1);fprintf(tokens,"%d,%d\n",3,iden);}
{clase4} {fprintf(tokens,"%d,%d\n",4,61);}
{clase5nc} {fprintf(tokens,"%d,%d\n",5,0);}
{clase5dc} {fprintf(tokens,"%d,%d\n",5,1);}
{clase5mq} {fprintf(tokens,"%d,%d\n",5,2);}
{clase5nq} {fprintf(tokens,"%d,%d\n",5,3);}
{clase5mi} {fprintf(tokens,"%d,%d\n",5,4);}
{clase5ni} {fprintf(tokens,"%d,%d\n",5,5);}
{clase6} {fprintf(tokens,"%d,%s\n",6,yytext);}
{clase7} {cad++;fprintf(cadenas,"%d                 %s\n",cad,yytext);fprintf(tokens,"%d,%d\n",7,cad);}
{clase8m} {fprintf(tokens,"%d,+\n",8);}
{clase8g} {fprintf(tokens,"%d,-\n",8);}
{clase8a} {fprintf(tokens,"%d,*\n",8);}
{clase8d} {fprintf(tokens,"%d,/\n",8);}
{clase8aa} {fprintf(tokens,"%d,%d\n",8,0);}
{clase8p} {fprintf(tokens,"%d,%\n",8);}
({espacio}|\\n|\\t) {fprintf(x,"******ESPACIO, SALTO O TABULACIÓN******\n");}
. {fprintf(x,"ERROR: %s NO ES NINGUN TOKEN VÁLIDO\n",yytext);}

%%

int main(int argc, char *argv[])
{
yyin = fopen(argv[1],"r");
x=fopen("output.txt","w");
identificadores = fopen("identificadores.txt","w");
fprintf(identificadores,"Posicion          Nombre          Tipo\n");
cadenas = fopen("cadenas.txt","w");
fprintf(cadenas,"Posicion          Dato\n");
numeros = fopen("numeros.txt","w");
fprintf(numeros,"Posicion          Dato\n");
tokens = fopen("tokens.txt","w");
yylex();
fclose(identificadores);
fclose(cadenas);
fclose(numeros);
fclose(tokens);
return 0;
}
