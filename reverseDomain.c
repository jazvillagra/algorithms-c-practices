/*
 * reverseDomain.c
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

void reverseDomain(char *);

int main(int argc, char **argv)
{
	char dominio[900];	
	int valid = 1;
	printf("Ingrese el nombre de dominio: ");
	scanf("%s`", dominio);
	
	printf("\n1- Dominio ingresado: %s", dominio);
	
	for (int i=0; i < strlen(dominio); ++i){
		if (strncmp(&dominio[i],".",1) == 0){
			if (i==0 || i == strlen(dominio)-1 ){
				printf("\nERROR. El dominio no puede empezar ni terminar con un punto");
				valid = 0;
				break;
			}
			
			if (strncmp(&dominio[i+1],".",1) == 0){
				printf("\nERROR. El dominio no puede tener dos puntos seguidos");
				valid = 0;
				break;
			}
		}
	}
	if(valid == 1)
		reverseDomain(dominio);
	
	return 0;
}

void reverseDomain(char * dominio){
	
	char copy[900];
	char * pack;
	char rev1[900] = "";
	char rev2[900] = "";
	int b = 0;
	
	//printf("\n HOLA ENTRE A LA FUNCION CON LA VARIABLE DOMINIO = %s", dominio);
	
	strcpy(copy,dominio);
	
	pack = strtok(copy,".");
	
	while(pack != NULL){
		if(b == 0){
			strcpy(rev1, pack);
			strcat(rev1,".");
			strcat(rev1, rev2);
			b = 1;
		}else{
			strcpy(rev2, pack);
			strcat(rev2,".");
			strcat(rev2,rev1);
			b = 0;
		}
		pack = strtok(NULL, ".");
	}
	if( b==1){
		rev1[strlen(rev1)-1]='\0';
		printf("\n2- Reversed: %s", rev1);
	}else{
		rev2[strlen(rev2)-1]='\0';
		printf("\n2- Reversed: %s",rev2);
	}
}
