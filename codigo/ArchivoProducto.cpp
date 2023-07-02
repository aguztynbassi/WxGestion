#include "ArchivoProducto.h"
#include "Archivo.h"
#include <string>
#include "Producto.h"
#include "Utils.h"
#include <algorithm>
#include <sstream>
using namespace std;

ArchivoProducto::~ArchivoProducto() {}

ArchivoProducto::ArchivoProducto (string n):Archivo(n) {}

void ArchivoProducto::CargarProducto (Producto p) {
	bool band=false;
	int i=0;
	while((band == false) and (i < Cantidad())){
		Producto aux=V[i];
		if(aux.VerCodigo()==p.VerCodigo()){
			band=true;
		}
		i++;
	}
	if(band==true){
		Modificar((i-1),p);
	}else{
		Cargar(p);
	}
}

void ArchivoProducto::EliminarProducto (int i) {
	Producto aux;
	aux=Ver(i);
	aux.Borrar();
	Modificar(i,aux);
}

void ArchivoProducto::Ordenar (CriterioOrdenDelProducto criterio) {
	switch (criterio) {
	case ORDEN_CODIGO: 
		sort(V.begin(),V.end(), Producto::criterio_comparacion_codigo); 
		break;
	case ORDEN_NOMBRE: 
		sort(V.begin(),V.end(), Producto::criterio_comparacion_nombre); 
		break;
	};
}
//--------- Funciones que retorna lo buscado ------//
int ArchivoProducto::BuscarCodigo (unsigned int parte , int pos) {
	for (int i=pos;i<Cantidad();i++) {
		Producto &p = V[i];
		if (p.VerCodigo() == parte)
			return i;
	}
	return NO_SE_ENCUENTRA;
}
int ArchivoProducto::BuscarCodigo (string parte, int &pos) {
	stringstream a;
	string s;
	for (int i=pos;i<Cantidad();i++,pos++) {
		Producto &p = V[pos];
		a<< p.VerCodigo();
		s = a.str();
		if (s.find(parte, 0) != string::npos)
			return pos;
	}
	return NO_SE_ENCUENTRA;
}

int ArchivoProducto::BuscarNombre (string parte, int &pos) {
	pasar_a_minusculas(parte);
	for (int i=pos;i<Cantidad();i++,pos++) {
		Producto &p = V[pos];
		string apenom = p.VerNombre();
		pasar_a_minusculas(apenom);
		if (apenom.find(parte,0)!=string::npos)
			return pos;
	}
	return NO_SE_ENCUENTRA;
}


	//------ Filtrado Producto --------//
bool ArchivoProducto::Filtrar_NomProducto (int pos, string parte) {
	Producto &p= V[pos];
	string cadena = p.VerNombre();
	if (cadena.find(parte, 0) != string::npos){
		return true;
	}
	return false;
}

bool ArchivoProducto::Filtrar_CodProducto (int pos, string parte) {
	Producto &p = V[pos];
	stringstream cp;
	cp<< p.VerCodigo();
	string cadena = cp.str();
	if (cadena.find(parte, 0) != string::npos){
		return true;
	}
	return false;
}
	//------ Filtrado Cantidad Producto-----//
int ArchivoProducto::Filtrar_cant_NomProducto (string aux) {
	int total=0;
	for(int i=0;i<Cantidad();i++) { 
		if(Filtrar_NomProducto(i, aux) == true)
			total= total+1;
	}
	producto_filtrado = total;
	return total;
}

int ArchivoProducto::Filtrar_cant_CodProducto (string aux) {
	int total= 0;
	for(int i=0;i<Cantidad();i++) { 
		if(Filtrar_CodProducto(i, aux) == true)
			total++;
	}
	producto_filtrado=total;
	return total;
}

int ArchivoProducto::VerProductoFiltrado ( ) const {return producto_filtrado;}
