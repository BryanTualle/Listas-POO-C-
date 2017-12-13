#include "stdafx.h"
#include <stdio.h>
#include <windows.h>
#include "Lista.h"
Lista::Lista() {
	primero = ultimo = NULL;
}
bool Lista::listaVacia() {
	return primero == NULL;
}
void Lista::insertarInicio(int dato) {
	Nodo *nuevo = new Nodo(dato);
	if (listaVacia()) {
		primero = ultimo = nuevo;
	}
	else {
		nuevo->setSiguiente(primero);
		primero = nuevo;
	}
}
void Lista::insertarFinal(int dato) {
	Nodo *nuevo = new Nodo(dato);
	if (listaVacia()) {
		primero = ultimo = nuevo;
	}
	else {
		ultimo->setSiguiente(nuevo);
		ultimo = nuevo;
	}
}
void Lista::insertarDespuesDe(int busca, int dato) {
	Nodo *aux = primero;
	Nodo *anterior = NULL;
	Nodo* nuevo = new Nodo(dato);
	bool ok = false;
	while (aux&&!ok) {
		if (aux->getDato() == busca)
			ok = true;
		else {
			anterior = aux;
			aux = aux->getSiguiente();
		}
	}
	if (ok) {
		if (aux == ultimo) {
			insertarFinal(dato);
		}
		else {
			anterior = aux;
			aux = aux->getSiguiente();
			anterior->setSiguiente(nuevo);
			nuevo->setSiguiente(aux);
		}
	}
	else {
		printf("No se encontro el dato anterior al que se quiere ingresar");
		system("pause>NULL");
	}
}
void Lista::insertarAntesDe(int busca, int dato) {
	Nodo *aux = primero;
	Nodo *anterior = NULL;
	Nodo* nuevo = new Nodo(dato);
	bool ok = false;
	while (aux&&!ok) {
		if (aux->getDato() == busca)
			ok = true;
		else {
			anterior = aux;
			aux = aux->getSiguiente();
		}
	}
	if (ok) {
		if (aux == primero) {
			insertarInicio(dato);
		}
		else {
			anterior->setSiguiente(nuevo);
			nuevo->setSiguiente(aux);
		}
	}
	else {
		printf("No se encontro el dato anterior al que se quiere ingresar");
		system("pause>NULL");
	}
}
void Lista::imprimir() {
	Nodo *aux = primero;
	while (aux) {
		printf("%d->", aux->getDato());
		aux = aux->getSiguiente();
	}
	printf("FIN\n");
}
void Lista::borrar() {
	Nodo *aux;
	while (primero) {
		aux = primero;
		primero = primero->getSiguiente();
		delete aux;
	}
	printf("Lista eliminada\n");
}
void Lista::eliminar(int dato) {
	Nodo *aux = primero;
	Nodo *anterior = NULL;
	bool ok = false;
	while (aux&&!ok) {
		if (aux->getDato() == dato)
			ok = true;
		else {
			anterior = aux;
			aux = aux->getSiguiente();
		}
	}
	if (ok) {
		if (aux == primero) {
			primero = aux->getSiguiente();
		}
		else {
			anterior->setSiguiente(aux->getSiguiente());
		}
		delete aux;
		printf("Dato eliminado\n");
	}
	else
		printf("Dato a eliminar no encontrado \n");
}
bool Lista::buscar(int dato) {
	Nodo *aux = primero;
	bool ok = false;
	while (aux&&!ok) {
		if (aux->getDato() == dato)
			ok = true;
		else
			aux = aux->getSiguiente();
	}
	return ok;
}
