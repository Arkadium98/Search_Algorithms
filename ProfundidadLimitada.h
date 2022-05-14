#pragma once
#include "Estructuras.h"
#include <stack>
#include <iostream>
class ProfundidadLimitada {
public:
	static NodoArbol* buscar(NodoArbol cabeza, NodoGrafo* meta, int limite = 1) {
		stack<NodoArbol*> agenda = stack<NodoArbol*>();
		agenda.push(&cabeza); //colocar nodo inicial en la agenda
		NodoArbol* curr = NULL;
		while (agenda.size() > 0)
		{
			curr = agenda.top(); //sacar elemento de la agenda
			agenda.pop(); //quitar elemento de la agenda
			if (curr->padre != NULL) {
				cout << curr->padre->nodoGrafo->nombre << "=>";
			}
			cout << curr->nodoGrafo->nombre << endl;
			if (meta == curr->nodoGrafo || curr->contarAncestros() > limite) {
				cout << "-------------------------" << endl;
				cout << "\n"<<" Solucion:" << endl;
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
		return curr;
	}
};