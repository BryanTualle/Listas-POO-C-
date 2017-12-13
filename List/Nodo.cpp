#include "stdafx.h"
#include <stdio.h>
#include "Nodo.h"
Nodo::Nodo(int dato, Nodo* sig) {
	this->dato = dato;
	sig = NULL;
}
Nodo::Nodo(int dato) {
	this->dato = dato;
	this->siguiente = NULL;
}
void Nodo::setDato(int dato) {
	this->dato = dato;
}
void Nodo::setSiguiente(Nodo *siguiente) {
	this->siguiente = siguiente;
}
void Nodo::setAnterior(Nodo *anterior) {
	this->anterior = anterior;
}
int Nodo::getDato() {
	return this->dato;
}
Nodo *Nodo::getSiguiente() {
	return this->siguiente;
}
Nodo *Nodo::getAnterior() {
	return this->anterior;
}
