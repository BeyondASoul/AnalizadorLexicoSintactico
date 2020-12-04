/*SILVA NUÑEZ ALEJANDRO BRYAN*/
/*SANTIAGO VILLEGAS FERNANDO*/
/*ANALIZADOR LÉXICO-SINTACTICO*/
/*COMPILADORES*/
/*ENTREGA: 03/12/2020*/
/*OBJETIVO: Construir, en un mismo programa, los analizadores Léxico y
Sintáctico Descendente Recursivo que revisen programas escritos en el lenguaje definido por la gramática de la clase.*/
// Obtiene el átomo, dependiendo de su clase y su valor
char getTokenAtomo(int clase, int valor){
	switch (clase)
	{
	case 0: return '_'; break; // No hace nada, ya se agrega el atomo en proy.l
	case 1: switch (valor){
				case 0: return 'b'; break;
				case 1: return 'q'; break;
				case 2: return 'k'; break;
				case 3: return 'c'; break;
				case 4: return 't'; break;
				case 5: return 'd'; break;
				case 6: return 'h'; break;
				case 7: return 'l'; break;
				case 8: return 'f'; break;
				case 9: return 'p'; break;
				case 10: return 'i'; break;
				case 11: return 'n'; break;
				case 12: return 'u'; break;
				case 13: return 'g'; break;
				case 14: return 'x'; break;
				case 15: return 'w'; break;
				case 16: return 'o'; break;
			}
	case 2: return (char)valor; break;
	case 3: return '_'; break; // No hace nada, ya se agrega el atomo en proy.l
	case 4: return '_'; break; // No hace nada, ya se agrega el atomo en proy.l
	case 5: switch (valor){
				case 0: return '!'; break;
				case 1: return '?'; break;
				case 2: return '>'; break;
				case 3: return '<'; break;
				case 4: return 'y'; break;
				case 5: return 'm'; break;
			}
	case 6: return '_'; break; // No hace nada, ya se agrega el atomo en proy.l
	case 7: return '_'; break; // No hace nada, ya se agrega el atomo en proy.l
	case 8: if (valor==48){
				return '#'; break;
			}
			else{
				return (char)valor; break;
			}
	}
}