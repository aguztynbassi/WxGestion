#include "Producto.h"
#include "Utils.h"
#include <fstream>
#include <cstring>
using namespace std;

Producto::Producto() {
	codigo=0;
	nombre="";
	precio=0.0f;
	existe=true;
}

Producto::Producto (unsigned int c, string n, float p) {
	codigo=c;
	nombre=pasar_a_minusculas(n);
	precio=p;
	existe=true;
}

Producto::~Producto() {}

unsigned int Producto::VerCodigo ( ) const {return codigo;}

string Producto::VerNombre ( ) const {return nombre;}

float Producto::VerPrecio ( ) const {return precio;}

bool Producto::VerExistencia ( ) const {return existe;}

void Producto::LeerDesdeBinario (ifstream & i) {
	nodo_producto aux;
	i.read((char*)&aux,sizeof(aux));
	codigo=aux.CODIGO;
	nombre=aux.NOMBRE;
	precio=aux.PRECIO;
	existe=aux.EXISTE;
}

void Producto::GuardarDesdeBinario (ofstream & o) {
	nodo_producto aux;
	
	if(nombre.size()>sizeof(aux.NOMBRE)-1) nombre.erase(sizeof(aux.NOMBRE)-1);
	
	aux.CODIGO=codigo;
	strcpy(aux.NOMBRE,nombre.c_str());
	aux.PRECIO=precio;
	aux.EXISTE=existe;
	
	o.write((char*)&aux,sizeof(aux));
}

bool Producto::operator< (Producto p) {return (this->VerCodigo() < p.VerCodigo());}

bool Producto::operator== (Producto p) {return (this->VerCodigo() == p.VerCodigo());}

bool Producto::operator> (Producto p) {return (this->VerCodigo() > p.VerCodigo());}

bool Producto::criterio_comparacion_codigo (Producto p1, Producto p2) {return (p1.VerCodigo() < p2.VerCodigo());}

bool Producto::criterio_comparacion_nombre (Producto p1, Producto p2) {return (p1.VerNombre() < p2.VerNombre());}

string Producto::Validar ( )const {
	string errores;
	if (codigo==0) errores+= "El codigo no puede estar vacio.\n";
	if (nombre.size()==0) errores+= "El nombre no puede estar vacio.\n";
	if (nombre.size()>256) errores+= "El nombre no puede estar vacio.\n";
	if (precio==0.0f) errores+= "El precio no puede ser 0.\n";
	return errores;
}

void Producto::Cargar ( ) {existe=true;}

void Producto::Borrar ( ) {existe=false;}

void Producto::CargarCodigo (unsigned int i) {codigo=i;}

void Producto::CargarNombre (string n) {nombre=pasar_a_minusculas(n);}

void Producto::CargarPrecio (float f) {precio=f;}

