/*
 * reemplazarCadenas.c
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

char reemp(char *cad, char *cd, char *rp, int veces);

int main(){
	
	char cadena[900];
	char aBuscar[900];
	char reemplazo[900];
	int veces;
	
	printf("Ingrese una sentencia/oracion: \n");
	scanf("%[^\n]",cadena);
	getc(stdin);
	printf("Ingrese la cadena a buscar: \n");
	scanf("%[^\n]",aBuscar);
	getc(stdin);
	printf("Ingrese la cadena que reemplazara a la anterior: \n");
	scanf("%[^\n]",reemplazo);
	getc(stdin);
	printf("Ingrese la cantidad de veces que se reemplazara la cadena: \n");
	scanf("%d", &veces);
	
	reemp(cadena, aBuscar, reemplazo, veces);
	printf("\n%s", cadena);
	return 0;

}

char reemp(char *cad, char *cd, char *rp, int veces){
	
	char *corte;
	char bas[900];
	corte= strstr(cad, cd);
	//printf("\n \t CADENA A BUSCAR: %s\n", cd);
	//printf("\t ESTA ES LA VARIABLE CORTE:%s\n", corte);
	if(veces > 0 && corte != NULL){
		//todo lo comentado era solo para las pruebas de escritorio
		strcpy(bas, corte+strlen(cd));
		printf("\n \t ESTA ES LA VARIABLE BAS:%s\n",bas);
		corte[0]='\0';
		strcat(cad,rp);
		printf("\n\t ESTA ES LA VARIABLE CAD:%s\n",cad);
		strcat(cad,bas);
		printf("\n\t ESTA ES LA VARIABLE CAD:%s\n",cad);
		reemp(cad, cd, rp, veces-1);
	}
	
	return 0;
	
}
