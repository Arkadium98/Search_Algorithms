#pragma once
#include<vector>
#include<string>
#include<iostream>
#include<math.h>

using namespace std;
class NodoArbol;
class NodoGrafo;
class Vecino 
{
public: 
	NodoGrafo* nodo;
	float costo;

	Vecino(NodoGrafo* nodo,float costo) 
	{
		this->nodo = nodo;
		this->costo = costo;
	
	}
};
class NodoGrafo {
public:
	vector<NodoGrafo*> vecinos; //Arreglo de vecinos
	vector<Vecino> costevecinos;
	string nombre;
	NodoArbol* visited_1;
	NodoArbol* visited_2;
	float heuristica,posx,posy;
	NodoGrafo(string ciudad,float posx =NULL,float posy = NULL ) {
		this->nombre = ciudad;
		this->costevecinos = vector<Vecino>();
		this->visited_1 = NULL;//salida
		this->visited_2 = NULL;//meta
		this->heuristica = NULL;
		this->posx = posx;
		this->posy = posy;
	}
	float GetHeuristica(float metaposx, float metaposy) 
	{
		if (this->heuristica == NULL) 
		{
			this->heuristica = sqrtf(powf(metaposx - this->posx,2) + powf(metaposy - this->posy,2));
		}
		return this->heuristica;
	}
};
class NodoArbol {
public:
	NodoArbol* padre;
	NodoGrafo* nodoGrafo;
	float costo;

	NodoArbol(NodoGrafo* nodoGrafo) {
		this->nodoGrafo = nodoGrafo;
		this->padre = NULL;
		this->costo = 0;

	}
	NodoArbol(NodoGrafo* nodoGrafo, NodoArbol* padre) {
		this->nodoGrafo = nodoGrafo;
		this->padre = padre;
	}
	bool esAncestro(NodoGrafo* insertable) {
		if (this->padre != NULL) {//no es la raiz
			if ((*this->padre).nodoGrafo == insertable) {
				return true;
			}
			else
			{
				return (*this->padre).esAncestro(insertable);
			}
		}
		else {
			return false;
		}
	}
	int contarAncestros() {
		if (this->padre != NULL) {//no es la raiz
			return this->padre->contarAncestros() + 1;
		}
		else {
			return 1;
		}
	}
	void printRoute() {
		if (this->padre != NULL) {//no es la raiz
			(*this->padre).printRoute();
			cout << (*(*this->padre).nodoGrafo).nombre << "=>";
			cout << (*(this->nodoGrafo)).nombre << endl;
		}
	}
	void printRouteBack() {
		if (this->padre != NULL) {//no es la raiz
			cout << (*(this->nodoGrafo)).nombre << "=>";
			cout << (*(*this->padre).nodoGrafo).nombre << endl;
			(*this->padre).printRouteBack();
		}
	}
};
