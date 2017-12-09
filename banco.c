/*
 * banco.c
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
//Declaramos el registro que contiene los datos en el archivo
struct registro{
	int sucursal,asiento,nroLinea,importe;
	char *cuenta;
	char *tipoLinea;
	char *fecha;
};
struct registro linea;
//Proceso de corte de control
void primerRegistro();
void procesarDatos();
void primerCorte();
void segundoCorte();
void reporteFinal();
//Declaramos el archivo y las variables globales
FILE * archivo;
int cSucursal, cAsiento, debe, haber, totalDebe, totalHaber;
int main(int argc, char **argv){
	archivo=fopen("banco.csv","r");
	if(archivo != NULL){
		fscanf(archivo,"%d,%d,%d,%s,%s,%s,%d", &linea.sucursal, &linea.asiento, &linea.nroLinea, linea.cuenta, linea.fecha, linea.tipoLinea, &linea.importe);
		primerRegistro();
		while(!feof(archivo)){
			if (cSucursal != linea.sucursal || cAsiento != linea.asiento){
				segundoCorte();
			}
			procesarDatos();
			fscanf(archivo,"%d,%d,%d,%s,%s,%s,%d", &linea.sucursal, &linea.asiento, &linea.nroLinea, linea.cuenta, linea.fecha, linea.tipoLinea, &linea.importe);
		}
		segundoCorte();
		fclose(archivo);
		reporteFinal();
	}else{
		printf("\nEl archivo no existe o no se pudo leer");
	}
	return 0;
}

void primerRegistro(){
	cSucursal= linea.sucursal;
	cAsiento= linea.asiento;
	printf("\nSucursal: %d", cSucursal);
	printf("\n\tAsiento: %d", cAsiento);
}

void procesarDatos(){
	printf("\n\t\t %d \t %s \t %s \t %s", linea.nroLinea, linea.tipoLinea, linea.fecha, linea.cuenta);
	int d;
	char *value= "D";
	linea.tipoLinea = toupper(linea.tipoLinea);
	d = strcmp(&linea.tipoLinea, &value);
	if(d == 0){
		printf("\t%d",linea.importe);
		totalDebe= totalDebe + linea.importe;
	}else{
		printf("\t\t%d", linea.importe);
		totalHaber= totalHaber + linea.importe;
	}
}
void primerCorte(){
	printf("\nSucursal: %d", linea.sucursal);
	cSucursal=linea.sucursal;
}

void segundoCorte(){
	printf("\n\t\t\tTotal Asiento %d:\t%d\t%d", cAsiento, totalDebe, totalHaber);
	if(!feof(archivo)){
		if(cSucursal != linea.sucursal){
			primerCorte();
		}
		printf("\n\tAsiento: %d",linea.asiento);
		cAsiento=linea.asiento;
	}
	totalDebe=0;
	totalHaber=0;
}
void reporteFinal(){
	
}
