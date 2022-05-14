#pragma once
#include "Estructuras.h"
#include <stack>
#include <iostream>
class PrimeroProfundidad {
public:
	static void buscar(NodoArbol cabeza, NodoGrafo* meta) {
		stack<NodoArbol*> agenda = stack<NodoArbol*>();
		agenda.push(&cabeza); //colocar nodo inicial en la agenda
		while (agenda.size() > 0)
		{
			NodoArbol* curr = agenda.top(); //sacar elemento de la agenda
			agenda.pop(); //quitar elemento de la agenda
			if (curr->padre != NULL) {
				cout << curr->padre->nodoGrafo->nombre << "=>";
			}
			cout << curr->nodoGrafo->nombre << endl;
			if (meta == curr->nodoGrafo) {
				cout << "-------------------------" << endl;
				cout << "\n" << " Solucion:" << endl;
				curr->printRoute();
				cout << "\n" << " Costo : " << curr->costo;
				cout << "-------------------------" << endl;
				break;
			}
			else {
				int tam = curr->nodoGrafo->vecinos.size();
				for (int i = 0; i < tam; i++) { //ver posibles estados adyacentes
					if (!curr->esAncestro(curr->nodoGrafo->vecinos[i])) { //verificar que no sea ancestro
						agenda.push(new NodoArbol(curr->nodoGrafo->vecinos[i], curr)); //si no es ancestro, insertar hijo
					}
				}
			}
		}
	}
};