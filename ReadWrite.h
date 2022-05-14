#pragma once
#include "Estructuras.h"
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include<map>

using namespace std;
void readFila(string line,vector<string> &temp) 
{
	stringstream ss(line); //permite que separes por comas
	temp.clear();
	while (ss.good())
	{
		string fila;
		getline(ss, fila, ',');
		temp.push_back(fila);
	}
	
}
void readNodos(map<string, NodoGrafo*> &nodos)
{
	ifstream archivo("MEXICO.csv");
	string line;
	vector<string> fila = vector<string>();
	//map<string,NodoGrafo*> nodos = map<string, NodoGrafo*>();
	
	while (getline(archivo,line)) 
	{
		readFila(line, fila);
		// Nodo A, Nodo B, costo, posxA , posyA , posxB , posyB
		if (nodos.find(fila[0]) == nodos.end())
			nodos.insert(pair<string, NodoGrafo*>(fila[0], new NodoGrafo(fila[0], stof(fila[3]), stof(fila[4]))));
		if (nodos.find(fila[1]) == nodos.end())
			nodos.insert(pair<string, NodoGrafo*>(fila[1], new NodoGrafo(fila[1], stof(fila[5]), stof(fila[6]))));

		nodos.at(fila[0])->costevecinos.push_back(Vecino(nodos.at(fila[1]), stof(fila[2])));
		nodos.at(fila[1])->costevecinos.push_back(Vecino(nodos.at(fila[0]), stof(fila[2])));

		nodos.at(fila[0])->vecinos.push_back((nodos.at(fila[1])));
		nodos.at(fila[1])->vecinos.push_back((nodos.at(fila[0])));
		
	}

}


