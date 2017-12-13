/*
 * matrizCamino.c
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


int main(int argc, char **argv){
	
	int m,n,i,j;
	printf("Introduzca la cantidad de filas: ");
	scanf("%d", &m);
	printf("Introduzca la cantidad de columnas: ");
	scanf("%d", &n);
	
	char caminos[m][n];

	printf("Introduza:\n\tA= arriba\n\tB= abajo\n\tI= izquierda\n\tD= derecha\n\tC= cerrado\n");
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			scanf("\n %c", &caminos[i][j]);
		}
	}
	printf("\nA ver:\n");
	j=0;
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			printf("\t%c", caminos[i][j]);
		}
		printf("\n");
	}
}

