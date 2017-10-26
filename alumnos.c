/*
 * alumnos.c
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
int curso, cedula, nota, cCurso, cCedula, prom;
int promAlum[90], promCursos[12];
char alumno[100], asignatura[100];

FILE * calificaciones;

void primerRegistro();
void cortePromAlumnos();
void cortePromCurso();
void procesarDatos();
void resumenFinal();

int main(int argc, char **argv){
	
	calificaciones= fopen("calificaciones.csv","r");
	if (calificaciones != null){
		fscanf(calificaciones, "%d,%d,%d,%s,%s", &curso, &cedula, &nota, &alumno, &asignatura);
		primerRegistro();
		while(!=eof(calificaciones)){
			if(cCurso != curso){
				cortePromAlumnos();
			}
			procesarDatos();
			fscanf(calificaciones, "%d,%d,%d,%s,%s", &curso, &cedula, &nota, &alumno, &asignatura);
		}
		cortePromAlumnos();
		fclose(calificaciones);
		resumenFinal();
	} else{
		printf("El archivo no existe o no se pudo leer");
	}
	return 0;
}

void primerRegistro(){
	int k;
	for (k=0;k<90;k++){
		promAlum[k]=0
		if (k<12)
			promCursos[k]=0;
	}
}

void cortePromAlumnos(){
	
}
