#pragma once
class Nodo
{
private:
	int dato;
	Nodo *sig;
public:
	Nodo();
	~Nodo();
	Nodo(int, Nodo *);
	int GetDato();
	void SetDato(int);
	Nodo* GetNodo();
	void SetNodo(Nodo *);
};

