#pragma once
#include "Nodo.h"
class Lista
{
private:
	Nodo *lista;

public:
	Lista();
	~Lista();
	void LeerDatos(int);
	void ImprimirDatos();
	bool Buscar(int);
	void Modificar(int);
	void InsertarDespuesDe(int);
	void Eliminar(int);
};

