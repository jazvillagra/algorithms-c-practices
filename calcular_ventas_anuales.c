/*
 * calcular_ventas_anuales.c
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

FILE * archivo;
int cZona;
int cantVentasPorMesZona[12], cantVentasPorMes[12];
struct registro{
	int zona;
	int dia;
	int mes;
	int importe;
};
struct registro linea;
void primerRegistro();
void corteZona();
void procesarDatos();
void reporteFinal();

int main(int argc, char **argv){
	
	archivo= fopen("ventas.csv","r");
	if (archivo != NULL){
		fscanf(archivo, "%d,%d,%d,%d", &linea.zona, &linea.dia, &linea.mes, &linea.importe);
		primerRegistro();
		while(!feof(archivo)){
//				printf("\n zona test en while %d \n", linea.zona);
			if(cZona != linea.zona){
				corteZona();
			}
			procesarDatos();
			fscanf(archivo,"%d,%d,%d,%d", &linea.zona, &linea.dia, &linea.mes, &linea.importe);
		}
		corteZona();
		fclose(archivo);
		reporteFinal();
	} else {
		printf("El archivo no existe o no se pudo leer");
	}
	return 0;
}

void primerRegistro(){
	int k;
	//printf("\n zona test %d \n", linea.zona);
	cZona=linea.zona;
	for(k=0;k<12;k++){
		cantVentasPorMesZona[k]=0;
		cantVentasPorMes[k]=0;
	}
}

void procesarDatos(){
	//printf("\n zona en procesarDatos %d \n", linea.zona);
	cantVentasPorMesZona[linea.mes - 1] = cantVentasPorMesZona[linea.mes - 1] + linea.importe;
	cantVentasPorMes[linea.mes - 1] =cantVentasPorMes[linea.mes - 1] + cantVentasPorMesZona[linea.mes - 1];
}

void corteZona(){
	int k;
	printf("\nZona %d", cZona);
	for(k=0;k<12;k++){
		if(cantVentasPorMesZona[k] > 0){
			printf("\n\tVentas en Mes %d: %d", k+1, cantVentasPorMesZona[k]);
			cantVentasPorMesZona[k]=0;
		}
	}
	cZona= linea.zona;
}

void reporteFinal(){
	int k;
	printf("\n\nTotal de ventas de la empresa por mes: \n");
	for(k=0;k<12;k++){
		if(cantVentasPorMes[k]>0){
			printf("Mes %d: %d\n",k+1,cantVentasPorMes[k]);
		}
	}
}
