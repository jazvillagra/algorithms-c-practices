/*
 * ventas_desde_1980.c
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
 * Una empresa se dedica desde 1980 a comercializar 30 diferentes productos importados. Tiene grabado en un archivo ordenado por año, mes y día todas las compras y ventas realizadas desde que empezó a operar en el país. El formato de registro es el siguiente:
Año, mes, dia, cod_producto(1 al 30), tipo,(1=compra, 2=venta), cantidad, monto unitario.
Imprimir un reporte que demuestre la ganancia obtenida por cada producto y la utilidad total en el año.
 * 
 */

#include <stdio.h>
#include <stdlib.h>
//Declaramos el registro que contiene los datos en el archivo
struct reg{
	int year;
	int month;
	int day;
	int code;
	int type;
	int quant;
	int price;
};
struct reg line;
//Proceso de corte de control
void firstReg();
void yearCut();
void productProcess();
void final();
//Declaramos el archivo y las variables globales
FILE * sellsFile;
int cYear, sells, buys, yearSells;
int products[30];
int main(int argc, char **argv){
	sellsFile=fopen("totalSells.csv","r");
	if(sellsFile != NULL){
		fscanf(sellsFile,"%d,%d,%d,%d,%d,%d,%d", &line.year, &line.month, &line.day, &line.code, &line.type, &line.quant, &line.price);
		firstReg();
		while(feof(sellsFile)){
			if(cYear != line.year){
				yearCut();
			}
			productProcess();
			fscanf(sellsFile,"%d,%d,%d,%d,%d,%d,%d", &line.year, &line.month, &line.day, &line.code, &line.type, &line.quant, &line.price);
		}
		yearCut();
		fclose(sellsFile);
		final();
	} else {
		printf("\nEl archivo no existe o no se pudo leer.\nFile does not exist or cannot be read.");
	}
	return 0;
}

void firstReg(){
	int i;
	cYear=line.year;
	for(i=0;i<30;i++){
		products[i]=0;
	}
	sells=0;
	buys=0;
	yearSells=0;
}

void productProcess(){
	int totalPay = line.quant * line.price;
	if(line.type == 1){
			buys = buys + line.quant;
	}
	}else{
		products[line.code]= products[line.code] + totalPay;
		sells = sells + line.quant;
	}
	yearSells = yearSells + products[line.code];
}

void yearCut(){
	printf("\n\tAño: %d", cYear);
	printf("\n\tTotal recaudado: %d", yearSells);
	yearSells=0;
}

void final(){
	int i;
	for (i=0;i<30;i++){
		if(products[i]>0){
			printf("\n\t\tCodigo Producto: %d", i);
			printf("\n\t\tTotal recaudado: %d", products[i]);
			printf("\n\t\tSe compraron: %d",buys);
			printf("\n\t\tSe vendieron: %d",sells);
		}
	}
}
