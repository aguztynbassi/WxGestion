#ifndef ARCHIVO_H
#define ARCHIVO_H
#include <vector>
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

template<class T> class Archivo {
protected:
	string Nombre_archivo;
	vector <T> V;
public:
	/**
	* @brief
	*	constructor por defecto que solo le paso el nombre del Archivo
	* @param n nombre del Archivo
	*/
	Archivo(string);
	/**
	* @brief
	*	funcion que se encarga de abrir el Archivo y poner todos los datos
	*	en el vector
	*/
	bool Abrir();
	/**
	* @brief
	*	funcion que cuenta cuantos datos hay en el vector
	* @return cantidad de datos
	*/
	int Cantidad();
	/**
	* @brief
	*	funcion que guarda todos los datos del vector en el Archivo
	* @return true si se guardo, false sino
	*/
	bool Guardar();
	/**
	* @brief
	*	funcion para cargar un nuevo dato al final del vector
	* @param a es el nuevo dato
	*/
	void Cargar(T);
	/**
	* @brief
	*	funcion que remplaza el dato de la posicion i por el nuevo dato a
	* @param i posicion del vector
	* @param a nuevo dato
	*/
	void Modificar(int, T);
	/**
	* @brief
	*	funcion para Eliminar un dato del vector
	* @param i posicion del vector
	*/
	void Eliminar(int);
	/**
	* @brief
	*	funcion para ver un dato del vector
	* @param i posicion del vector
	* @return devuelve el dato que esta en la posicion i
	*/
	const T &Ver(int);
	/**
	* @brief
	*	sobrecarga del operator[]
	* @param i posicion del vector
	* @return devuelve el dato que esta en la posicion i
	*/
	const T &operator[] (int);
	/**
	* @brief
	*	Limpia todo el vector
	*/
	void Limpiar();
};

template<class T>Archivo<T>::Archivo (string n) {Nombre_archivo=n;}

template<class T>int Archivo<T>::Cantidad ( ) { return V.size();}

template<class T>void Archivo<T>::Eliminar (int i) { V.erase(V.begin()+i);}

template<class T>void Archivo<T>::Cargar (T a) { V.push_back(a); }

template<class T>void Archivo<T>::Modificar (int i, T a) { V[i]=a;}

template<class T>const T & Archivo<T>::operator[] (int i) { return V[i];}

template<class T>void Archivo<T>::Limpiar ( ) { V.clear();}

template<class T>const T & Archivo<T>::Ver (int i) { return V[i]; }

template<class T>bool Archivo<T>::Abrir ( ) {
	ifstream Archi(Nombre_archivo.c_str(),ios::binary|ios::ate);
	if(!Archi.is_open()) return false;
	int tamanio_archivo = Archi.tellg();
	int cantidad = tamanio_archivo/sizeof(typename T::struct_binario);
	V.resize(cantidad);
	Archi.seekg(0,ios::beg);
	int i=0;
	while(i!=Cantidad()){
		V[i].LeerDesdeBinario(Archi);
		++i;
	}
	Archi.clear();
	Archi.close();
	return true;
}

template<class T>bool Archivo<T>::Guardar ( ) {
	ofstream Archi(Nombre_archivo.c_str(),ios::binary|ios::trunc);
	if(!Archi.is_open()) return false;
	int i=0;
	while(i!=Cantidad()){
		V[i].GuardarDesdeBinario(Archi);
		++i;
	}
	return true;
}

#endif
