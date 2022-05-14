#include <iostream>
#include<queue>//cola
#include<stack>//pila
#include<vector>
#include<string>
#include<map>
#include"ReadWrite.h"
//-------------
#include <fstream>
#include <cstdlib>
#include <algorithm>
//--------------
#include "PrimeroAncho.h"
#include "PrimeroProfundidad.h"
#include "Bidireccional.h"
#include "ProfundidadLimitada.h"
#include "ProfundidadIterativa.h"
#include "AscensoColina.h"
#include "K_Beans.h"
#include "PrimeroMejor.h"
#include "BeamSearch.h"
#include "AStar.h"
using namespace std;


int main()
{
	map<string, NodoGrafo*> nodos = map<string, NodoGrafo*>();
	readNodos(nodos);
	map<string, NodoGrafo*>::iterator it = nodos.begin();
	
	while (it != nodos.end())
	{
		cout <<"\t"<< it->first;
		it++;
	}
	string partida, destino;
	cout << "\n Digite el nombre del punto de partida : ";
	cin >> partida;
	cout << "\n Digite el nombre del punto de destino : ";
	cin >> destino;

	NodoArbol cabeza = NodoArbol(nodos.at(partida)); //colocar nodo inicial en la raiz del arbol
	NodoGrafo* meta = nodos.at(destino);
	int opc;
	cout << "----------Menu de Algoritmos ----------" << endl;
	cout << "\t" << "1) Primero Ancho" << endl;
	cout << "\t" << "2) Primero Profundidad" << endl;
	cout << "\t" << "3) Bidireccional" << endl;
	cout << "\t" << "4) Profuncidad Limitada" << endl;
	cout << "\t" << "5) Profundidad Iterativa" << endl;
	cout << "\t" << "6) Ascenso Colina" << endl;
	cout << "\t" << "7) K Beans" << endl;
	cout << "\t" << "8) Primero Mejor" << endl;
	cout << "\t" << "9) Beam Search" << endl;
	cout << "\t" << "10) A *" << endl;
	cout << "Digite el numero del algoritmo (1 a 10) : ";
	cin >> opc;
	switch (opc) 
	{
	case 1:
		PrimeroAncho::buscar(cabeza, meta);
		break;
	case 2:
		PrimeroProfundidad::buscar(cabeza, meta);
		break;
	case 3:
		Bidireccional::buscar(cabeza, meta);
		break;
	case 4:
		ProfundidadLimitada::buscar(cabeza, meta, 4);
		break;
	case 5:
		ProfundidadIterativa::buscar(cabeza, meta);
		break;
	case 6:
		AscensoColina::buscar(cabeza, meta);
		break;
	case 7:
		K_Beans::buscar(cabeza, meta);
		break;
	case 8:
		PrimeroMejor::buscar(cabeza, meta);
		break;
	case 9:
		BeamSearch::buscar(cabeza, meta);
		break;
	case 10:
		AStar::buscar(cabeza, meta);
		break;
	}

	system("pause");

	return 0;

}

