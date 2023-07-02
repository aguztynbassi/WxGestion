#include "ArchivoCliente.h"
#include <string>
#include "Archivo.h"
#include "Cliente.h"
#include "Utils.h"
#include <algorithm>
#include <sstream>
using namespace std;

ArchivoCliente::~ArchivoCliente() {}

ArchivoCliente::ArchivoCliente (string n):Archivo(n) {}

void ArchivoCliente::CargarCliente (Cliente c) {
	bool band=false;
	int i=0;
	while((band == false) and (i < Cantidad())){
		Cliente aux=V[i];
		if(aux.VerDni()==c.VerDni()){
			band=true;
		}
		i++;
	}
	if(band==true){
		Modificar((i-1),c);
	}else{
		Cargar(c);
	}
}

void ArchivoCliente::EliminarCliente (int i) {
	Cliente aux;
	aux=Ver(i);
	aux.Borrar();
	Modificar(i,aux);
}

void ArchivoCliente::Ordenar (CriterioOrdenDelCliente criterio) {
	switch (criterio) {
	case ORDEN_DNI: 
		sort(V.begin(),V.end(),Cliente::criterio_comparacion_dni); 
		break;
	case ORDEN_APELLIDO_Y_NOMBRE: 
		sort(V.begin(),V.end(),Cliente::criterio_comparacion_apellido_y_nombre); 
		break;
	case ORDEN_TELEFONO: 
		sort(V.begin(),V.end(),Cliente::criterio_comparacion_telefono); 
		break;
	case ORDEN_DIRECCION: 
		sort(V.begin(),V.end(),Cliente::criterio_comparacion_direccion); 
		break;
	};
}
//--- Funciones que retornan la posicion de lo buscado ---//
int ArchivoCliente::BuscarApellidoYNombre (string parte, int &pos) {
	pasar_a_minusculas(parte);
	for(int i=pos;pos<Cantidad();i++,pos++) {
		Cliente &p = V[pos];
		string apenom = p.VerNombre()+", "+p.VerApellido();
		pasar_a_minusculas(apenom);
		if (apenom.find(parte,0)!=string::npos)
			return pos;
	}
	return NO_SE_ENCUENTRA;
}

int ArchivoCliente::BuscarDNI (string parte, int &pos) {
	stringstream a;
	string s;
	for(int i=pos;pos<Cantidad();i++,pos++) {
		Cliente &p = V[pos];
		a<<p.VerDni();
		s = a.str();
		if (s.find(parte, 0) != string:: npos)
			return pos;
	}
	return NO_SE_ENCUENTRA;
}

int ArchivoCliente::BuscarDNI (unsigned int parte, int pos) {
	for (int i=pos;i<Cantidad();i++) {
		Cliente &p = V[i];
		if (p.VerDni() == parte)
			return i;
	}
	return NO_SE_ENCUENTRA;
}


	// ------- Filtrado Cliente  ------//
bool ArchivoCliente::Filtrar_NomCliente (int pos, string parte ) {
	Cliente aux = Ver(pos);
	stringstream aa;
	aa << aux.VerNombre() << ", " << aux.VerApellido();
	string cadena = aa.str();
	if ( cadena.find(parte, 0) != string::npos){
		return true;
	}
	return false;
}

bool ArchivoCliente::Filtrar_DniCliente (int pos, string parte ) {
	Cliente &c = V[pos];
	stringstream d;
	d<< c.VerDni();
	string cadena = d.str();
	if (cadena.find(parte, 0) != string::npos){
		return true;
	}
	return false;
}

int ArchivoCliente::Filtrar_cant_NomCliente (string parte ) {
	int total=0;
	for(int i=0;i<Cantidad();i++) { 
		if (Filtrar_NomCliente(i, parte)== true)
			total++;
	}
	cliente_filtrado = total;
	return total;
}

int ArchivoCliente::Filtrar_cant_DniCliente (string parte ) {
	int total=0;
	for(int i=0;i<Cantidad();i++) { 	
		if (Filtrar_DniCliente(i, parte) == true)
			total++;
	}
	cliente_filtrado = total;
	return total;
}

int ArchivoCliente::VerClienteFiltrado ( ) const {
	return cliente_filtrado;
}

