#ifndef NODO_H
#define NODO_H
class Nodo {
public:
	Nodo(int, Nodo*);
	Nodo(int);
	void setSiguiente(Nodo*);
	Nodo *getSiguiente();
	void setAnterior(Nodo*);
	Nodo *getAnterior();
	void setDato(int);
	int getDato();
private:
	Nodo *siguiente;
	Nodo *anterior;
	int dato;
};

#endif // NODO_H

