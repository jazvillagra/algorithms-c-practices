/*
 * agenda_lista_enlazada-v1.c
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

struct _agenda {
	char nombre[20];
	char telefono[12];
	struct _agenda *siguiente;
};
struct _agenda *primero,*ultimo;

void mostrar_menu(){
	printf("\n\nMenú:\n=====\n\n");
	printf("1.- Agregar contacto\n");
	printf("2.- Borrar contacto\n");
	printf("3.- Obtener un contacto\n");
	printf("4.- Mostrar lista\n");
	printf("5.- Salir\n");
	printf("Escoge una opción:\n");
}
/* Con esta función añadimos un elemento al final de la lista */
void adir_elemento(){
	
	struct _agenda *nuevo;
	
	/* reservamos memoria para el nuevo elemento*/
	nuevo = (struct _agenda *) malloc (sizeof(struct _agenda));
	if (nuevo==NULL){
		printf("No hay memoria disponible!");
	}
	printf("\nNuevo elemento:\n");
	printf("Nombre: \n");//fflush(stdout);
	scanf("%s", nuevo->nombre);
	printf("Telefono: \n");//fflush(stdout);
	scanf("%s",nuevo->telefono);
	/* el campo siguiente va a ser NULL por ser el ultimo elemento de la lista */
	nuevo->siguiente = NULL;
	
	/* ahora metemos el nuevo elemento en la lista. Lo situamos al final de la lista
	 * Comprobamos si la lista está vacia. Si primero = NULL es que no hay ningún elemento en la lista. Tambien vale ultimo=NULL */
	 if(primero == NULL){
		 printf("Primer elemento. \n");
		 primero = nuevo;
		 ultimo = nuevo;
	}else{
		/* el que hasta ahora era el ultimo tiene que apuntar al nuevo */
		ultimo -> siguiente = nuevo;
		/*hacemos que el nuevo sea ahora el ultimo */
		ultimo = nuevo;
	}
}

void mostrar_lista(){
	struct _agenda *aux;
	int i;
	i=0;
	aux=primero;
	printf("\nMostrando la lista completa: \n");
	while(aux!=NULL) {
		printf("Nombre: %s, Telefono: %s\n", aux->nombre, aux->telefono);
		aux = aux->siguiente;
		i++;
	}
	if(i==0)
		printf("\nLa lista está vacia!");
}


void borrar_elemento(){
	struct _agenda *act, *ant, *aux;
	aux =(struct _agenda *) NULL;
	int i;
	int x;
	printf("\nIngrese el nro. de nodo a eliminar: ");
	scanf("%d", &x);
	i=0;
	act=primero;
	ant=primero;
	/* debe haber un puntero adicional para guardar el anterior, y reemplazar el aux[i] con el anterior */
	while(act!=NULL && i < x-1) {
		ant= act;
		act= act->siguiente;
		printf("\n\t\tElemento anterior: %s", ant->nombre);
		printf("\n\t\tElemento actual: %s", act->nombre);
		i++;
	}
	if(act != NULL){
		aux=act;
		ant->siguiente=act->siguiente;
		free(aux);
	}
	if(i==0)
		printf("\nLa lista está vacia!");
}



int main(int argc, char **argv){
	int opcion;
	primero = (struct _agenda *) NULL;
	ultimo  = (struct _agenda *) NULL;
	do{
		mostrar_menu();
		scanf("%d", &opcion);
		switch(opcion){
			case 1: adir_elemento();
				break;
			case 2: borrar_elemento();
				break;
			case 3:	printf("No disponible todavia\n");
				break;
			case 4: mostrar_lista();
				break;
			case 5: exit(1);
			
			default: printf("Opción no válida\n");
				break;
		}
	}while(opcion !='5');
	return 0;
}

