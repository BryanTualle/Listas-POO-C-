#include "Nodo.h"

Nodo::Nodo()
{
}

Nodo::Nodo(int a, Nodo *lista)
{
	dato = a;
	sig = lista;
}

int Nodo::GetDato()
{
	return dato;
}

Nodo* Nodo::GetNodo()
{
	return sig;
}

void Nodo::SetDato(int setVal)
{
	dato = setVal;
}

void Nodo::SetNodo(Nodo *siguiente)
{
	sig = siguiente;
}

Nodo::~Nodo()
{
}
