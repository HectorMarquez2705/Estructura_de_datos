#pragma once
#define MAX 10
#include <iostream>
#include <string>
#include "Vector.h"

using namespace std;

class Matriz
{
	private:
		Vector dato[MAX][MAX];
		int n;
	public:
		Matriz();
		void setN(int tam);
		int getN() const;
		void generar(vector v[], int tam);
		void mostrar() const;

};
