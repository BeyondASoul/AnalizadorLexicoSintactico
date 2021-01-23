/*SILVA NUÑEZ ALEJANDRO BRYAN*/
/*SANTIAGO VILLEGAS FERNANDO*/
/*ANALIZADOR LÉXICO-SINTACTICO-SEMÁNTICO*/
/*COMPILADORES*/
/*ENTREGA: 26/01/2021*/
/*OBJETIVO: CONSTRUIR EN UN MISMO PROGRAMA, LOS ANALIZADORES LÉXICO, SINTÁCTICO 
Y SEMÁNTICO QUE REVISEN PROGRAMAS FUENTE ESCRITOS CON EL LENGUAJE ELABORADO EN CLASE.*/

// Obtiene el átomo, dependiendo de su clase y su valor
char *palabrasRes[17]={"bool","break","case","char","continue","default","do","else","float","for","if","int","return","string","switch","while","void"};

// PALABRA RESERVADA
int busquedaPal(char* cadena){
    for(int i=0;i<17;i++){
        if(!strcmp(palabrasRes[i],cadena)){
            return i;
        }
    }
    return -1;
}

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
	return '_';
}