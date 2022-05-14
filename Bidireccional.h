#pragma once
#include "Estructuras.h"
#include <stack>
#include <iostream>
class Bidireccional {
public:
	static void buscar(NodoArbol cabeza, NodoGrafo* meta) {
		stack<NodoArbol*> agenda_1 = stack<NodoArbol*>();
		stack<NodoArbol*> agenda_2 = stack<NodoArbol*>();
		agenda_1.push(&cabeza); //colocar nodo inicial en la agenda
		agenda_2.push(new NodoArbol(meta)); //colocar nodo inicial en la agenda
		while (agenda_1.size() > 0 && agenda_2.size() > 0)
		{
			NodoArbol* curr_1 = agenda_1.top(); //sacar elemento de la agenda
			NodoArbol* curr_2 = agenda_2.top(); //sacar elemento de la agenda
			agenda_1.pop(); //quitar elemento de la agenda
			agenda_2.pop(); //quitar elemento de la agenda
			if (curr_1->padre != NULL) {
				cout << curr_1->padre->nodoGrafo->nombre << "=>";
			}
			cout << curr_1->nodoGrafo->nombre << endl;
			if (curr_1->nodoGrafo->visited_2 != NULL || curr_2->nodoGrafo->visited_1 != NULL) {//si ya encontró la solución
				cout << "-------------------------" << endl;
				cout << "\n" << " Solucion:" << endl;
				curr_1->printRoute();
				curr_2->printRouteBack();
				cout << "\n" << " Costo : " << curr_1->costo+ curr_2->costo;
				cout << "-------------------------" << endl;
				break;
			}
			else {
				int tam = curr_1->nodoGrafo->vecinos.size();
				for (int i = 0; i < tam; i++) { //ver posibles estados adyacentes
					if (!curr_1->esAncestro(curr_1->nodoGrafo->vecinos[i])) { //verificar que no sea ancestro
						NodoArbol* temp = new NodoArbol(curr_1->nodoGrafo->vecinos[i], curr_1);
						curr_1->nodoGrafo->vecinos[i]->visited_1 = temp;
						agenda_1.push(temp); //si no es ancestro, insertar hijo
					}
				}
				tam = curr_2->nodoGrafo->vecinos.size();
				for (int i = 0; i < tam; i++) { //ver posibles estados adyacentes
					if (!curr_2->esAncestro(curr_2->nodoGrafo->vecinos[i])) { //verificar que no sea ancestro
						NodoArbol* temp = new NodoArbol(curr_2->nodoGrafo->vecinos[i], curr_2);
						curr_2->nodoGrafo->vecinos[i]->visited_2 = temp;
						agenda_2.push(temp); //si no es ancestro, insertar hijo
					}
				}
			}
		}
	}
};