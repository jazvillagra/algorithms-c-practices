/*
 * formatearCaracteres.c
 * 
 * Copyright 2017 Jaz <jvillagra@stark>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void formateo(char *, char *, int veces);
int main(int argc, char **argv){
	
	char format[900],cadena[900];
	char *form;
	int veces;
	printf("Introduzca una sentencia con %% donde se deba agregar valores:\n ");
	scanf("%[^\n]", cadena);
	getc(stdin);
	printf("Introduzca valores para formatear sentencia anterior separados por | :\n ");
	scanf("%[^\n]", format);
	getc(stdin);
	char formato[900];
	strcpy(formato, format);
	
	form = strtok(format, "|");
	while(form != NULL){
		form = strtok(NULL, "|");
		veces++;
	}
	
	formateo(formato, cadena, veces);
	return 0;
}

void formateo(char *fmt, char* cad, int veces){
	
	char *corte;
	char bas[900];
	char *f;
	f = strtok(fmt, "|");
	corte= strstr(cad, "%");
	if(veces > 0 && corte != NULL){
		strcpy(bas, corte+1);
		corte[0]='\0';
		strcat(cad, f);
		strcat(cad, bas);
		f = strtok(NULL,"|");
		formateo(f, cad, veces-1);
	}else{
		printf("\n%s",cad);
	}
}
