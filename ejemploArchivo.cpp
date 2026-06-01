#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Amigo {
private:
	string 	nombre;
	string cumple;
	char	sexo;
	char	estado;		//eliminado = E, activo = A
	string mail;
public:
	Amigo();
	Amigo(string nom, string cmp, char sx, string ml);
	void setAmigo(string nom, string cmp, char sx, string ml);
	string getNombre();
	string getCumple();
	char getSexo();
	char getEstado();
	string getMail();
	void guardarArchivo(ofstream& fsalida);
	bool leerArchivo(ifstream& fentrada);
	bool eliminar(fstream& fes, int nroReg);
	bool modificar(fstream& fes, int nroReg);
	bool buscar(ifstream& fentrada, int nroReg);
	int getTamBytesRegistro();
};

///////////////////////////
#include "Amigo.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
Amigo::Amigo() {
	nombre = "";
	cumple = "";
	sexo = ' ';
	estado = ' ';
	mail = "";
}
Amigo::Amigo(string nom, string cmp, char sx, string ml) {
	nombre = nom;
	cumple = cmp;
	sexo = sx;
	estado = 'A';
	mail = ml;
}
void Amigo::setAmigo(string nom, string cmp, char sx, string ml) {
	nombre = nom;
	cumple = cmp;
	sexo = sx;
	estado = 'A';
	mail = ml;
}
string Amigo::getNombre() {
	return(nombre);
}
string Amigo::getCumple() {
	return(cumple);
}
char Amigo::getSexo() {
	return(sexo);
}
char Amigo::getEstado() {
	return(estado);
}
string Amigo::getMail() {
	return(mail);
}
void Amigo::guardarArchivo(ofstream& fsalida) {
	fsalida.write(reinterpret_cast<char*>(&nombre), sizeof(nombre));
	fsalida.write(reinterpret_cast<char*>(&cumple), sizeof(cumple));
	fsalida.write(reinterpret_cast<char*>(&sexo), sizeof(sexo));
	fsalida.write(reinterpret_cast<char*>(&estado), sizeof(estado));
	fsalida.write(reinterpret_cast<char*>(&mail), sizeof(mail));
}
bool Amigo::leerArchivo(ifstream& fentrada) {
	bool k = false;
	if (fentrada.is_open() == true) {
		fentrada.read(reinterpret_cast<char*>(&nombre), sizeof(nombre));
		if (fentrada.eof() == false) {
			fentrada.read(reinterpret_cast<char*>(&cumple), sizeof(cumple));
			fentrada.read(reinterpret_cast<char*>(&sexo), sizeof(sexo));
			fentrada.read(reinterpret_cast<char*>(&estado), sizeof(estado));
			fentrada.read(reinterpret_cast<char*>(&mail), sizeof(mail));
			k = true;
		}
		else {
			//cout << endl << "Registro no existe";
		}
	}
	else {
		cout << endl << "Arhivo no existe";
	}
	return(k);
}
bool Amigo::eliminar(fstream& fes, int nroReg) {
	bool k = false;
	if (fes.is_open() == true) {
		fes.seekg(getTamBytesRegistro() * (nroReg - 1), ios::beg);
		fes.read(reinterpret_cast<char*>(&nombre), sizeof(nombre));
		if (fes.eof() == false) {
			fes.read(reinterpret_cast<char*>(&cumple), sizeof(cumple));
			fes.read(reinterpret_cast<char*>(&sexo), sizeof(sexo));
			fes.read(reinterpret_cast<char*>(&estado), sizeof(estado));
			fes.read(reinterpret_cast<char*>(&mail), sizeof(mail));

			estado = 'E';
			fes.seekp(getTamBytesRegistro() * (nroReg - 1), ios::beg);
			fes.write(reinterpret_cast<char*>(&nombre), sizeof(nombre));
			fes.write(reinterpret_cast<char*>(&cumple), sizeof(cumple));
			fes.write(reinterpret_cast<char*>(&sexo), sizeof(sexo));
			fes.write(reinterpret_cast<char*>(&estado), sizeof(estado));
			fes.write(reinterpret_cast<char*>(&mail), sizeof(mail));
			k = true;
		}
		else {
			cout << endl << "Registro no existe";
		}
	}
	else {
		cout << endl << "Arhivo no existe";
	}
	return(k);
}
bool Amigo::modificar(fstream& fes, int nroReg) {
	bool k = false;
	if (fes.is_open() == true) {
		string nomAux;
		nomAux = nombre;
		fes.seekg(getTamBytesRegistro() * (nroReg - 1), ios::beg);
		fes.read(reinterpret_cast<char*>(&nombre), sizeof(nombre));
		if (fes.eof() == false) {
			nombre = nomAux;
			estado = 'A';
			fes.seekp(getTamBytesRegistro() * (nroReg - 1), ios::beg);
			fes.write(reinterpret_cast<char*>(&nombre), sizeof(nombre));
			fes.write(reinterpret_cast<char*>(&cumple), sizeof(cumple));
			fes.write(reinterpret_cast<char*>(&sexo), sizeof(sexo));
			fes.write(reinterpret_cast<char*>(&estado), sizeof(estado));
			fes.write(reinterpret_cast<char*>(&mail), sizeof(mail));
			k = true;
		}
		else {
			cout << endl << "Registro no existe";
		}
	}
	else {
		cout << endl << "Arhivo no existe";
	}
	return(k);
}
bool Amigo::buscar(ifstream& fentrada, int nroReg) {
	bool k = false;
	if (fentrada.is_open() == true) {
		fentrada.seekg(getTamBytesRegistro() * (nroReg - 1), ios::beg);
		fentrada.read(reinterpret_cast<char*>(&nombre), sizeof(nombre));
		fentrada.read(reinterpret_cast<char*>(&cumple), sizeof(cumple));
		fentrada.read(reinterpret_cast<char*>(&sexo), sizeof(sexo));
		fentrada.read(reinterpret_cast<char*>(&estado), sizeof(estado));
		fentrada.read(reinterpret_cast<char*>(&mail), sizeof(mail));
		if (fentrada.eof() == false) {
			k = true;
		}
		else {
			//cout << endl << "Registro no XX existe";
		}
	}
	else {
		cout << endl << "Arhivo no existe";
	}
	return(k);
}
int Amigo::getTamBytesRegistro() {
	return(sizeof(nombre) + sizeof(cumple) + sizeof(sexo) + sizeof(estado) + sizeof(mail));
}

///////////////////////////////////////////////
#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "Amigo.h"
using namespace std;

class ABMamigo {
private:
	string  nomArchivo;
	Amigo* amig;
public:
	ABMamigo(string nomArch);
	void introducirDatos(Amigo* newReg);
	void mostrarRegistro(int nroReg);
	void adicionarNuevo();
	void listar();
	int buscarReg();
	void eliminarReg();
	void modificarReg();
};

///////////////////////////////////////////
#include "ABMamigo.h"
#include <iostream>
#include <fstream>
#include <string>
#include "Amigo.h"
using namespace std;

ABMamigo::ABMamigo(string nomArch) {
	nomArchivo = nomArch;
}
void ABMamigo::introducirDatos(Amigo* newReg) {
	string	nombre;
	string	cumple;
	char	sexo;
	string mail;
	cout << endl << endl << "Introducir los siguientes datos --->>> :" << endl;
	fflush(stdin);
	cout << "Nombre : ";
	getline(cin, nombre);
	cout << "Fecha de nacimiento (DD/MM/AAAA) : ";
	getline(cin, cumple);
	cout << "Correo electronico : ";
	getline(cin, mail);
	cout << "Sexo <F/M>: ";
	cin >> sexo;
	newReg->setAmigo(nombre, cumple, sexo, mail);
}
void ABMamigo::mostrarRegistro(int nroReg) {
	cout << endl << nroReg << ".- " << amig->getNombre() << " || " << amig->getCumple() << " || " << amig->getSexo() << " || " << amig->getEstado() << " || " << amig->getMail();

}
void ABMamigo::adicionarNuevo() {
	ofstream fsalida(nomArchivo, ios::app | ios::binary);
	amig = new Amigo();
	introducirDatos(amig);
	amig->guardarArchivo(fsalida);
	fsalida.close();
}
void ABMamigo::listar() {
	int cr = 0;
	cout << endl << endl << "Los registros son --->>> : " << endl;
	amig = new Amigo();
	ifstream fentrada(nomArchivo, ios::in | ios::binary);
	while (amig->leerArchivo(fentrada) == true) {
		cr++;
		if (amig->getEstado() == 'A') {
			mostrarRegistro(cr);
		}
	}
	fentrada.close();
}
int ABMamigo::buscarReg() {
	int nroReg;
	cout << endl << endl << "Introducir numero de registro a buscar :  ";
	cin >> nroReg;
	amig = new Amigo();
	ifstream fentrada(nomArchivo, ios::in | ios::binary);
	if (amig->buscar(fentrada, nroReg) == true) {
		mostrarRegistro(nroReg);
	}
	else {
		cout << endl << "Registro no existe";
		nroReg = -1;
	}
	fentrada.close();
	return(nroReg);
}
void ABMamigo::eliminarReg() {
	int nroReg;
	nroReg = buscarReg();
	if (nroReg > 0) {
		fstream fes(nomArchivo, ios::in | ios::out | ios::binary);
		amig = new Amigo();
		if (amig->eliminar(fes, nroReg) == true) {
			cout << endl << "Registro eliminado correctmente " << endl;
		}
		else {
			cout << endl << "Registro no existe pa eliminar" << endl;
		}
		fes.close();
	}
}
void ABMamigo::modificarReg() {
	int nroReg;
	nroReg = buscarReg();
	if (nroReg > 0) {
		fstream fes(nomArchivo, ios::in | ios::out | ios::binary);
		amig = new Amigo();
		introducirDatos(amig);
		if (amig->modificar(fes, nroReg) == true) {
			cout << endl << "modificado correctamente... " << endl;
		}
		else {
			cout << endl << "Registro no existe pa modificar";
		}
		fes.close();
	}
}

///////////////////////////////

#include <iostream>
#include <fstream>
#include "ABMamigo.h"
using namespace std;

void main() {
	int op;
	ABMamigo* amig = new ABMamigo("amigOO.dat");
	do {
		cout << "****MENU****\n";
		cout << "1. Registrar amigo.\n";
		cout << "2. Eliminar amigo.\n";
		cout << "3. Actualizar amigo.\n";
		cout << "4. Listar amigos.\n";
		cout << "5. Buscar amigo.\n";
		cout << "0. Salir.\n";
		cout << "Seleccione una opcion: ";
		cin >> op;
		cin.ignore();

		switch (op) {
			case 1:
				cout << "1. Registrar amigo.\n";
				amig->adicionarNuevo();
				cout << endl;
				break;
			case 2:
				cout << "2. Eliminar amigo.\n";
				amig->eliminarReg();
				cout << endl;
				break;
			case 3:
				cout << "3. Actualizar amigo.\n";
				amig->modificarReg();
				cout << endl;
				break;
			case 4:
				cout << "4. Listar amigos.\n";
				amig->listar();
				cout << endl;
				break;
			case 5:
				cout << "5. Buscar amigo.\n";
				amig->buscarReg();
				cout << endl;
				break;
			case 0:
				cout << "Salir.\n";
				break;
			default:
				cout << "Opcion invalida, intente de nuevo.\n";
		}

	} while (op != 0);
}