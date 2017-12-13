#include "Lista.h"
#include <iostream>

using namespace std;


Lista::Lista()
{
	lista = NULL;
}

Lista::~Lista()
{
}

void Lista::LeerDatos(int dato)
{
	Nodo *nuevo = new Nodo(dato, lista);
	lista = nuevo;
}

void Lista::ImprimirDatos()
{
	Nodo *aux;
	aux = lista;

	printf("\nLista:\n");

	if (lista != NULL)
	{
		
		//cout << "Lista: \n";
		do
		{
			printf(" %d ->", aux->GetDato());
			//cout << aux->GetDato() << endl;
			aux = aux->GetNodo();
		} while (aux != NULL);
		
		printf(" NULL\n");
	}
	else
		printf("\n NULL\n");
}

bool Lista::Buscar(int dato)
{
	Nodo *aux;
	aux = lista;
	int ayu;

	while (aux != NULL)
	{
		if (aux->GetDato() == dato)
		{
			cout << "El dato se encuentra en la lista" << endl;
			return true;
		}
		ayu = 0;
		aux = aux->GetNodo();
	}

	if (ayu == 0)
	{
		cout << "El dato NO se encuentra en la lista" << endl;
		return false;
	}
}

void Lista::InsertarDespuesDe(int dato)
{
	int help;
	cout << "Ingresar valor a insertar: ";
	cin >> help;

	Nodo *nuevo = new Nodo();
	nuevo->SetDato(help);

	if (Buscar(dato))
	{
		Nodo *aux;
		aux = lista;
		while (aux->GetDato() != dato)
		{
			aux = aux->GetNodo();
		}
		Nodo *sig = aux->GetNodo();
		aux->SetNodo(nuevo);
		nuevo->SetNodo(sig);
	}
}

void Lista::Modificar(int dato)
{
	Nodo *aux;
	aux = lista;
	int help;

	if (Buscar(dato))
	{
		cout << "Por cual valor se desea modificar?" << endl;
		cin >> help;
		do
		{
			if (dato == aux->GetDato())
			{
				aux->SetDato(help);
			}
			aux = aux->GetNodo();
		} while (aux != NULL);
	}
}

void Lista::Eliminar(int dato)
{
	if (lista != NULL)
	{
		if (Buscar(dato))
		{
			if (dato == lista->GetDato())
			{
				lista = lista->GetNodo();
			}
			else
			{
				Nodo *aux = lista;
				while (aux->GetNodo()->GetDato() != dato)
				{
					aux = aux->GetNodo();
				}
				Nodo *siguiente = aux->GetNodo()->GetNodo();
				aux->SetNodo(siguiente);
			}
		}
	}
	else
		ImprimirDatos();
}
