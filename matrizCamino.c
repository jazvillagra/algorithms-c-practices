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
#include <ctype.h>

struct nodo{
	int x;
	int y;
	struct nodo *siguiente;
};

struct nodo *inicio = NULL;
struct nodo *final = NULL;

void encolar(int,int);
struct nodo * desencolar();

int main(int argc, char **argv){
	
	int m,n,i,j,f,c, ff, cf;
	printf("Introduzca la cantidad de filas: ");
	scanf("%d", &m);
	printf("Introduzca la cantidad de columnas: ");
	scanf("%d", &n);
	
	char caminos[m][n];
	int copy[m][n];

	printf("Introduza:\n\tA= arriba\n\tB= abajo\n\tI= izquierda\n\tD= derecha\n\tC= cerrado\n");
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			scanf("\n %c", &caminos[i][j]);
			copy[i][j]=0;
		}
	}
	
	printf("Introduzca el nro de fila y columna de inicio:\n");
	scanf("%d\n%d",&f,&c);
	printf("Introduzca el nro de fila y columna de fin:\n");
	scanf("%d\n%d",&ff,&cf);
	i=f;
	j=c;
	while(i>=0 && i<m && j>=0 && j<n && toupper(caminos[i][j])!='C' && copy[i][j]!=1){
		copy[i][j] = 1;
		encolar(i,j);
		switch (toupper(caminos[i][j]))
		{
			case 'A':
				i--;
				break;
			case 'B':
				i++;
				break;
			case 'D':
				j++;
				break;
			case 'I':
				j--;
				break;
			default:
				printf("Invalid");
		}
	}
	
	if(i==ff && j==cf){
		printf("El camino recorrido para llegar exitosamente a la posicion final es: ");
		struct nodo *recorrido = desencolar();
		while(recorrido!=NULL){
			printf("%d, %d\n",recorrido->x, recorrido->y);
			recorrido = desencolar();
		}
	}else{
		printf("No existe un camino para llegar al destino");
	}
	
	printf("\nA ver:\n");
	
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			printf("\t%c", caminos[i][j]);
		}
		printf("\n");
	}
}

void encolar(int x, int y){
	struct nodo *nuevo = (struct nodo*)malloc(sizeof(struct nodo));
	nuevo->x = x;
	nuevo->y = y;
	nuevo->siguiente = NULL;
	if(inicio == NULL){
		inicio = nuevo;
		final = nuevo;
	}else{
		final->siguiente = nuevo;
		final = nuevo;
	}
}

struct nodo *desencolar(){
	struct nodo *aux = inicio;
	if(aux==NULL){
		return NULL;
	}
	inicio = inicio->siguiente;
	if(inicio==NULL){
		final = NULL;
	}
	
	return aux;
}
