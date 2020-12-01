#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char palabraAtomo(char* cadena)
{
	if(cadena=="bool")
		return (char)98;
	else if(cadena=="break")
		return (char)113;
	else if(cadena=="case")
		return 'k';
	else if(cadena=="char")
		return 'c';
	else if(cadena=="continue")
		return 't';
	else if(cadena=="default")
		return 'd';
	else if(cadena=="do")
		return 'h';
	else if(cadena=="else")
		return 'l';
	else if(cadena=="float")
		return 'f';
	else if(cadena=="for")
		return 'p';
	else if(cadena=="if")
		return 'i';
	else if(cadena=="int")
		return 'n';
	else if(cadena=="return")
		return 'u';
	else if(cadena=="string")
		return 'g';
	else if(cadena=="switch")
		return 'x';
	else if(cadena=="while")
		return 'w';
	else if(cadena=="void")
		return 'o';
}
char simboloAtomo(char* cadena)
{
	if(cadena=="{")
		return '{';
	else if(cadena=="}")
		return '}';
	else if(cadena==",")
		return ',';
	else if(cadena==":")
		return ':';
	else if(cadena=="(")
		return '(';
	else if(cadena==")")
		return ')';
	else if(cadena=="[")
		return '[';
	else if(cadena=="]")
		return ']';
}
char opReAtomo(char* cadena)
{
	if(cadena=="!=")
		return '!';
	else if(cadena=="==")
		return '?';
	else if(cadena==">")
		return '>';
	else if(cadena=="<")
		return '<';
	else if(cadena==">=")
		return 'y';
	else if(cadena=="<=")
		return 'm';
}
char opArAtomo(char* cadena)
{
	if(cadena=="+")
		return '+';
	else if(cadena=="-")
		return '-';
	else if(cadena=="*")
		return '*';
	else if(cadena=="/")
		return '/';
	else if(cadena=="**")
		return '#';
	else if(cadena=="%")
		return '%';
}