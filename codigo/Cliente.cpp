#include "Cliente.h"
#include <string>
#include <sstream>
#include "Utils.h"
#include <fstream>
#include <cstring>

using namespace std;

Cliente::Cliente() {
	dni=dia=mes=anio=0;
	nombre=apellido=direccion=telefono="";
	existe=true;
}

Cliente::~Cliente() {}

void Cliente::CargarDni (unsigned int i) {dni=i;}

void Cliente::CargarNombre (string i) { nombre=pasar_a_minusculas(i);}

void Cliente::CargarApellido (string i) { apellido=pasar_a_minusculas(i);}

void Cliente::CargarDireccion (string i) { direccion=pasar_a_minusculas(i);}

void Cliente::CargarFechaDeNacimiento (unsigned int x, unsigned int y, unsigned int z) {
	dia=x;
	mes=y;
	anio=z;
}

void Cliente::CargarTelefono (string c) { telefono=c;}

string Cliente::VerTelefono ( ) const {return telefono;}

unsigned int Cliente::VerDni ( ) const {return dni;}

string Cliente::VerNombre ( ) const {return nombre;}

string Cliente::VerApellido ( ) const {return apellido;}

string Cliente::VerDireccion ( ) const {return direccion;}

bool Cliente::VerExistencia ( ) const {return existe;}

void Cliente::Cargar ( ) {existe=true;}

void Cliente::Borrar ( ) {existe=false;}

void Cliente::LeerDesdeBinario (ifstream & i) {
	nodo_cliente aux;
	i.read((char*)&aux,sizeof(aux));
	
	dni=aux.DNI;
	dia=aux.DIA;
	mes=aux.MES;
	anio=aux.ANIO;
	nombre=aux.NOMBRE;
	apellido=aux.APELLIDO;
	direccion=aux.DIRECCION;
	telefono=aux.TELEFONO;
	existe=aux.EXISTE;
}

void Cliente::GuardarDesdeBinario (ofstream & o) {
	nodo_cliente aux;
	
	if(nombre.size()>sizeof(aux.NOMBRE)-1) nombre.erase(sizeof(aux.NOMBRE)-1);
	if(apellido.size()>sizeof(aux.APELLIDO)-1) nombre.erase(sizeof(aux.APELLIDO)-1);
	if(direccion.size()>sizeof(aux.DIRECCION)-1) nombre.erase(sizeof(aux.DIRECCION)-1);
	if(telefono.size()>sizeof(aux.TELEFONO)-1) nombre.erase(sizeof(aux.TELEFONO)-1);
	
	aux.DNI=dni;
	aux.DIA=dia;
	aux.MES=mes;
	aux.ANIO=anio;
	strcpy(aux.NOMBRE,nombre.c_str());
	strcpy(aux.APELLIDO,apellido.c_str());
	strcpy(aux.DIRECCION,direccion.c_str());
	strcpy(aux.TELEFONO,telefono.c_str());
	aux.EXISTE=existe;
	
	o.write((char*)&aux,sizeof(aux));
}

bool Cliente::operator< (Cliente c) { return (this->VerDni() < c.VerDni()); }

bool Cliente::operator== (Cliente c) { return (this->VerDni() == c.VerDni()); }

bool Cliente::operator> (Cliente c) { return (this->VerDni() > c.VerDni()); }

bool Cliente::criterio_comparacion_dni (Cliente c1, Cliente c2) { return (c1.VerDni()<c2.VerDni()); }

bool Cliente::criterio_comparacion_apellido_y_nombre (Cliente c1, Cliente c2) {
	string s1 = c1.VerApellido()+", "+c1.VerNombre();
	string s2 = c2.VerApellido()+", "+c2.VerNombre();
	return s1<s2;
}

bool Cliente::criterio_comparacion_direccion (Cliente c1, Cliente c2) {
	return (c1.VerDireccion()<c2.VerDireccion());
}

bool Cliente::criterio_comparacion_telefono (Cliente c1, Cliente c2) {
	return (c1.VerTelefono()<c2.VerTelefono());
}

const string Cliente::Validar ( ) {
	string errores;
	if (nombre.size()==0){ errores+= "El nombre no puede estar vacio.\n";}
	if (nombre.size()>256){ errores+= "El nombre es demasiado largo.\n";}
	if (apellido.size()==0) errores+= "El apellido no puede estar vacio.\n";
	if (apellido.size()>256) errores+= "El apellido es demasiado largo.\n";
	if (direccion.size()==0) errores+= "La direccion no puede estar vacia.\n";
	if (direccion.size()>256) errores+= "La direccion es demasiado larga.\n";
	if (telefono.size()==0) errores+= "El telefono no puede estar vacio.\n";
	if (telefono.size()>256) errores+= "El telefono es demasiado largo.\n";
	if (dni==0) errores+= "El DNI no puede estar vacio.\n";
	if (dia<=0 || dia>31) errores+= "El dia debe estar entre 1 y 31.\n";
	if (mes<=0 || mes>12) errores+= "El mes debe estar entre 1 y 12.\n";
	if (anio==0 && anio<=1900) errores+= "El año no puede ser menor a 1900.\n";
	return errores;
}

Cliente::Cliente (unsigned int dn, string no, string ap, string di, string te, int d, int m, int a) {
	dni=dn;
	dia=d;
	mes=m;
	anio=a;
	nombre=pasar_a_minusculas(no);
	apellido=pasar_a_minusculas(ap);
	direccion=pasar_a_minusculas(di);
	telefono=pasar_a_minusculas(te);
	existe=true;
}

unsigned int Cliente::VerDia ( ) const {return dia;}

unsigned int Cliente::VerMes ( ) const {return mes;}

unsigned int Cliente::VerAnio ( ) const {return anio;}

