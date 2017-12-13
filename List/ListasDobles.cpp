/*
								UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
										Listas Dobles_POO
		Autores: 				Bryan Tualle y	Sandra Castro
		Fecha de Creación:		11/12/2017
		Fecha de modificacion:	12/12/2017
		Docente: 				Ing. Edgar Fernando Solis Acosta
		Carrera: 				Ing. Sistemas e Informática
*/
#include "stdafx.h"
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <string>
#include <locale.h>
#include "Lista.h"
using namespace std;
void Menu(Lista);
bool Esnumero(string);
void main() {
	locale::global(locale("spanish"));
	system("Color F8");
	Lista list;
	Menu(list);
	system("pause>NULL");
}
void Menu(Lista list) {
	system("cls");
	string menu[] = { "Insertar al inicio","Insertar al final","Insertar antes de","Insertar despues de","Eliminar","Mostrar","Buscar","Salir" };
	int cursor = 0;
	string dato;
	bool ok = false;
	int num,ele;
	char tecla;
	while (1) {
		system("cls");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
		cout << "\t\t\tMenu\n";
		for (int i = 0;i <= 7;i++) {
			if (cursor == i) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 180);
				cout << menu[i];
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
				cout << "\n";
			}
			else {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
				cout << menu[i] << "\n";
			}
		}
		while (1) {
			tecla = _getch();
			if (tecla == 80) {
				cursor++;
				if (cursor == 8) {
					cursor = 0;
				}
				break;
			}
			else if (tecla == 72) {
				cursor--;
				if (cursor == -1) {
					cursor = 7;
				}
				break;
			}
			else if (tecla == 13) {
				switch (cursor) {
				case 0:
					system("CLS");
					do {
						ok = true;
						cout << "Ingresa un número: ";
						cin >> dato;
						if (!Esnumero(dato)) {
							cout << "Ingresa un número válido" << endl;
							ok = false;
						}
					} while (!ok);
					num = atof(dato.c_str());
					list.insertarInicio(num);
					Menu(list);
					break;
				case 1:
					system("CLS");
					do {
						ok = true;
						cout << "Ingresa un número: ";
						cin >> dato;
						if (!Esnumero(dato)) {
							cout << "Ingresa un número válido" << endl;
							ok = false;
						}
					} while (!ok);
					num = atof(dato.c_str());
					list.insertarFinal(num);
					Menu(list);
					break;
				case 2:
					system("CLS");
					do {
						ok = true;
						cout << "Ingresa el número siguiente al que deseas ingresar: ";
						cin >> dato;
						if (!Esnumero(dato)) {
							cout << "Ingresa un número válido" << endl;
							ok = false;
						}
					} while (!ok);
					ele = atof(dato.c_str());
					if (list.buscar(ele)) {
						do {
							ok = true;
							cout << "Ingresa un número: ";
							cin >> dato;
							if (!Esnumero(dato)) {
								cout << "Ingresa un número válido" << endl;
								ok = false;
							}
						} while (!ok);
						num = atof(dato.c_str());
						list.insertarAntesDe(ele,num);
					}
					else {
						cout << "No existe ese número en la lista";
						system("pause>NULL");
					}
					Menu(list);
					break;
				case 3:
					system("CLS");
					do {
						ok = true;
						cout << "Ingresa el número anterior al que deseas ingresar: ";
						cin >> dato;
						if (!Esnumero(dato)) {
							cout << "Ingresa un número válido" << endl;
							ok = false;
						}
					} while (!ok);
					ele = atof(dato.c_str());
					if (list.buscar(ele)) {
						do {
							ok = true;
							cout << "Ingresa un número: ";
							cin >> dato;
							if (!Esnumero(dato)) {
								cout << "Ingresa un número válido" << endl;
								ok = false;
							}
						} while (!ok);
						num = atof(dato.c_str());
						list.insertarDespuesDe(ele,num);
					}
					else {
						cout << "No existe ese número en la lista";
						system("pause>NULL");
					}
					Menu(list);
					break;
				case 4:
					system("CLS");
					do {
						ok = true;
						cout << "Ingresa el número a eliminar: ";
						cin >> dato;
						if (!Esnumero(dato)) {
							cout << "Ingresa un número válido" << endl;
							ok = false;
						}
					} while (!ok);
					num = atof(dato.c_str());
					list.eliminar(num);
					system("pause>NULL");
					Menu(list);
					break;
				case 5:
					system("CLS");
					list.imprimir();
					system("pause>NULL");
					Menu(list);
					break;
				case 6:
					system("CLS");
					do {
						ok = true;
						cout << "Ingresa el número a buscar: ";
						cin >> dato;
						if (!Esnumero(dato)) {
							cout << "Ingresa un número válido" << endl;
							ok = false;
						}
					} while (!ok);
					num = atof(dato.c_str());
					if (list.buscar(num))cout << "Dato encontrado";
					else cout << "Dato no encontrado";
					system("pause>NULL");
					Menu(list);
					break;
				case 7:
					system("CLS");
					cout << "Gracias por usar nuestro programa:3 ";
					system("pause>NULL");
					exit(0);
					break;
				}
				break;
			}
		}
	}
}
bool Esnumero(string n) {
	bool ok = true;
	int i = 0;
	int punto = 0;
	for (string::const_iterator it = n.begin();it != n.end() && ok;++it) {
		ok = isdigit(*it);
		if (!ok) {
			if (n[0] == '-') {
				++it;
				ok = isdigit(*it);
				if (!ok) {
					if (n[i] == ',') {
						punto++;
					}
					if (punto == 1)
						ok = true;
					else ok = false;
				}
			}
			else {
				if (n[i] == ',') {
					punto++;
				}
				if (punto == 1)
					ok = true;
				else ok = false;
			}
		}
		i++;
	}
	return ok;
}

