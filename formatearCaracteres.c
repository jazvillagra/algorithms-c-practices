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
int main(){
	
	char *cadena;
	char *format;
	
	char *form;
	int veces;
	printf("Introduzca una sentencia con %% donde se deba agregar valores:\n ");
	scanf("%[^\n]", cadena);
	getc(stdin);
	printf("Introduzca valores para formatear sentencia anterior separados por | :\n ");
	scanf("%[^\n]", format);
	printf("\n\tSe leyo: %s", format);
	getc(stdin);
	char formato[900];
	strcpy(formato, format);
	printf("\n\tSe copio: %s", formato);
	form = strtok(formato, "|");
	printf("\n\tSe corto: %s", form);
	
	while(form != NULL){
		veces++;
		form = strtok(NULL, "|");
		printf("\n\tVeces= %d\n\tSe corto: %s", veces,form);
	}
	
	formateo(format, cadena, veces);
	return 0;
}

void formateo(char *fmt, char *cad, int veces){
	
	char *corte;
	char bas[900];
	char *f;
	f = strtok(fmt, "|");
	printf("\n1- f = %s", f);
	corte= strstr(cad, "%");
	printf("\n2- corte = %s", corte);
	printf("\n3- cad = %s", cad);
	printf("\n4- Ahora entra al if");
	if(veces > 0 && corte != NULL){
		strcpy(bas, corte+1);
		printf("\n5- Entra al if. Con bas = %s", bas);
		corte[0]='\0';
		printf("\n6- Ahora en corte hay un espacio vacio.");
		printf("\n7- Ahora cad = %s", cad);
		strcat(cad, f);
		printf("\n8- cad = %s", cad);
		strcat(cad, bas);
		printf("\n9- Y ahora cad = %s", cad);
		f = strtok(NULL,"|");
		printf("\n10- Ultimo corte hecho en f= %s", f);
		printf("\n\n");
		formateo(f, cad, veces-1);
	}else{
		printf("\n%s",cad);
	}
}
