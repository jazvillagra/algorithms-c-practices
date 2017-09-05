/*
 * paresImpares-right.c
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
#include <time.h>
#include <math.h>

void ordenar(int *);
int j, i,a;
int main(){
	int V[10];
	srand (time (NULL));

	printf("El vector es:\n");
	for(i=0;i<10;i++){
		V[i]=rand()%1000+1;
		printf("%d\t",V[i]);
	}
	ordenar(V);		
	return 0;
}

void ordenar(int *V){
	printf("%d", V[1]);
	
	
    for (i = 0; i < 10; ++i){
        for (j = i + 1; j < 10; ++j){
            if (V[i]%2==0){
                a =  V[i];
                V[i] = V[j];
                V[j] = a;
            }
        }
    }
	printf("\n\nEl vector ordenado es:\n");
	for(i=0;i<10;i++){
		printf("%d\n",V[i]);
	}
}
