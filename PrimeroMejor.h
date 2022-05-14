#pragma once
#include "Estructuras.h"
#include <stack>
#include <iostream>
#include <vector>
#include <algorithm>

class PrimeroMejor
{
	static bool SortVecinos(NodoArbol* vec1, NodoArbol* vec2)
	{
		return vec1->costo < vec2->costo;
	}
public:
	static void buscar(NodoArbol cabeza, NodoGrafo* meta) {

		vector<Vecino> arr = vector <Vecino>();
		//Estadoinicial
		vector<NodoArbol*> agenda = vector<NodoArbol*>();
		agenda.push_back(&cabeza);


		while (agenda.size() > 0)
		{


			sort(agenda.begin(), agenda.end(), SortVecinos);

			NodoArbol* curr = agenda[0]; //sacar elemento de la agenda
			agenda.erase(agenda.begin()); //quitar el primer elemento de la agenda
			

			if (curr->padre != NULL) {
				cout << curr->padre->nodoGrafo->nombre << "=>";
			}
			cout << curr->nodoGrafo->nombre << endl;
			if (meta == curr->nodoGrafo) {
				cout << "-------------------------" << endl;
				cout <<"\n"<<" Solucion : " << endl;
				curr->printRoute();
				cout << "\n" << " Costo : "<<curr->costo;
				cout << "-------------------------" << endl;
				break;
			}
			else {
				int tam = curr->nodoGrafo->costevecinos.size();
				for (int i = 0; i < tam; i++) { //ver posibles estados adyacentes
					if (!curr->esAncestro(curr->nodoGrafo->costevecinos[i].nodo)) { //verificar que no sea ancestro
						NodoArbol* temp = new NodoArbol(curr->nodoGrafo->costevecinos[i].nodo, curr);
						temp->costo = curr->nodoGrafo->costevecinos[i].costo + curr->costo; // Es para que sea el costo de moverse en el arbol
						agenda.push_back(temp); //si no es ancestro, insertar hijo
					}
				}
			}



		}
	}
};

