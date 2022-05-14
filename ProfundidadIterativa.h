#pragma once
#include "Estructuras.h"
#include "ProfundidadLimitada.h"
#include <stack>
#include <iostream>
class ProfundidadIterativa {
public:
	static void buscar(NodoArbol cabeza, NodoGrafo* meta, int limite = 1, int paso = 1) {
		while (true)
		{
			NodoArbol* sol = ProfundidadLimitada::buscar(cabeza, meta, limite++);
			if (sol->nodoGrafo == meta) {
				break;
			}
		}
		
	}
};

