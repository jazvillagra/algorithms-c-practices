/*
 * ReporteEmpresa.c
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

FILE * registro;
int dia, cod, cdia;
int suma, contadorDias;
int cantVentasPorDia[31];

void primerRegistro();
void corteControl();
void procesarDatos();
void reporteFinal();

int main(int argc, char **argv){
	suma=0;
	registro = fopen("registroVentas.csv", "r");
	if (registro != NULL){
		fscanf(registro, "%d,%d", &dia, &cod);
		primerRegistro();
		
		while(!feof(registro)){
			if(cdia != dia){
				corteControl();
			}
			procesarDatos();
			fscanf(registro, "%d,%d", &dia, &cod);
		}
		//fscanf(registro, "%d,%d,", &dia, &cod);
		corteControl();
		fclose(registro);
		reporteFinal();
	} else{
		printf("El archivo no existe o no se pudo leer");
	}
	return 0;
}

void primerRegistro(){
	int k;
	cdia=dia;
	for (k=0;k<31;k++){
		cantVentasPorDia[k]=0;
	}
}

void procesarDatos(){
	cantVentasPorDia[dia-1]++;
	//printf("\n\tCantidad Ventas en Ese dia: %d",cantVentasPorDia[dia-1]);
	//printf("\nSuma parcial= %d",suma);
}

void corteControl(){
	contadorDias++;
	printf("\nDia: %d",cdia);
	printf("\nVentas totales= %d", cantVentasPorDia[cdia-1]);
	suma = suma + cantVentasPorDia[cdia-1];
	cdia=dia;
}
void reporteFinal(){
	double prom;
	printf("\nSuma de ventas totales= %d \nDias contados para el promedio= %d",suma,contadorDias);
	prom = suma / contadorDias;
	printf("\nTotal Ventas del mes: %f",prom);
}
