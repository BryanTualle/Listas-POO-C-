#ifndef LISTA_H
#define LISTA_H
#include "Nodo.h";
class Lista {
public:
	Lista();
	void insertarInicio(int);
	void insertarFinal(int);
	void insertarDespuesDe(int, int);
	void insertarAntesDe(int, int);
	void imprimir();
	void eliminar(int);
	void borrar();
	bool buscar(int);
	bool listaVacia();
private:
	Nodo *primero;
	Nodo *ultimo;
};
#endif // LISTA_H

