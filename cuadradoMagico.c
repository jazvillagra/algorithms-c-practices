/*
 * cuadradoMagico.c
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

int isMagic(int cuad[3][3]);

int main(){
	int i, j, resp;
	resp = 0;
	int cuad[3][3];
	printf("Introduzca los elementos de la matriz. Deben ser nros del 1 al 9:\n");
	for(i = 0; i < 3; i++){
		for (j = 0; j < 3; j++){
			scanf("%d", &cuad[i][j]);
			while(cuad[i][j] > 9 || cuad[i][j] < 1){
				printf("El valor introducido no es valido. Introduzca de nuevo ese elemento (1 al 9): ");
				scanf("%d", &cuad[i][j]);
			}
		}
	}
	
	resp = isMagic(cuad);
	
	if(resp)
		printf("\nEl cuadrado es magico.");
	else
		printf("\nEl cuadrado NO es magico");
	
	return 0;
}

int isMagic(int cuad[3][3]){
	int i,j, magic, diag1, diag2;
	int fila[3], colum[3];
	magic = 0;
	diag1 = cuad[0][0] + cuad[1][1] + cuad[2][2];
	diag2 = cuad[0][2] + cuad[1][1] + cuad[2][0];
	
	printf("La suma de las diagonales es: %d y %d", diag1, diag2);
	if(diag1 == diag2){
		for(i = 0; i < 3; i++){
			fila[i] = 0;
			colum[i] = 0;
			for (j = 0; j < 3; j++){
				printf("\nFila nro %d y columna nro. %d",i,j);
				fila[i] += cuad[i][j];
				printf("\tElemento: %d",cuad[i][j]);
				printf("\nAhora al reves. Fila %d y columna %d", j, i);
				colum[i] += cuad[j][i];
				printf("\tElemento: %d",cuad[j][i]);
			}
			printf("\nFila nro. %d: %d", i, fila[i]);
			printf("\nColumna nro. %d: %d", i, colum[i]);
			if(fila[i] == colum[i]){
				magic = 1;
			}else{
				magic = 0;
				break;
			}
		}
	}else{
		magic = 0;
	}
	printf("MAGIC: %d",magic);
	return magic;
}
