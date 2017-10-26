/*
 * try_fseek.c
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
GNU General Public License for more details.
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

int main(int argc, char **argv){
	FILE * fp;
	
	
	if((fp = fopen("archivo.dat","r")) == NULL){
		printf("No se puede abrir el archivo.\n");
		exit(1);
	}
	if(fseek(fp, atol("jalsjeo"), SEEK_SET)){
		printf("Error de posicionamiento");
		exit(1);
	}
	
	printf("El byte %ld es %c.\n", atol("jalsjeo"), getc(fp));
	
	fclose(fp);
	return 0;
}

