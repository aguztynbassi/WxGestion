#include "ArchivoFactura.h"
#include "Archivo.h"
#include <string>
#include <algorithm>
#include "Factura.h"
#include "Utils.h"
#include <sstream>
#include "Fecha.h"
using namespace std;

ArchivoFactura::ArchivoFactura (string n):Archivo(n) {}

ArchivoFactura::~ArchivoFactura ( ) {}

void ArchivoFactura::Ordenar (CriterioOrdenDeFacturas criterio) {
	switch (criterio) {
	case ORDEN_ID: 
		sort(V.begin(),V.end(), Factura::criterio_comparacion_codigo); 
		break;
	case ORDEN_ID_CLIENTE: 
		sort(V.begin(),V.end(), Factura::criterio_comparacion_cliente); 
		break;
	case ORDEN_ID_PRODUCTO: 
		sort(V.begin(),V.end(), Factura::criterio_comparacion_producto); 
		break;
	};
}

bool ArchivoFactura::FiltrarCliente (int pos, string cdni) {
	nodo_venta aux=Ver(pos);
	stringstream au;
	au<<aux.DNI;
	string cadena = au.str();
	if (cadena.find(cdni,0) !=string::npos){
		return true;
	}
	return false;
}

bool ArchivoFactura::FiltrarProducto (int pos, string cpro) {
	nodo_venta aux = Ver(pos);
	stringstream au;
	au<<aux.CODIGO;
	string cadena = au.str();
	if ( cadena.find(cpro, 0) != string::npos)
		return true;
	return false;
}

bool ArchivoFactura::FiltrarFecha (int pos, Fecha & f1, Fecha & f2) {
	nodo_venta aux=Ver(pos);
	if(f1.VerAnio()<=aux.ANIO and aux.ANIO <= f2.VerAnio())return true;
	else if(f1.VerMes()<=aux.MES and aux.MES <= f2.VerMes())return true;
	else if(f1.VerDia()<=aux.DIA and aux.DIA <= f2.VerDia())return true;
	return false;
}

bool ArchivoFactura::FiltrarFactura (int pos, string cfac) {
	nodo_venta au = Ver(pos);
	string cadena=au.ID;
	if (cadena.find(cfac, 0) != string::npos){
		return true;}
	return false;
}

int ArchivoFactura::FiltrarCantidadCliente (string aux) {
	int total = 0;
	for(int i=0;i<Cantidad();i++) { 
		if (FiltrarCliente(i,aux)==true)
			total= total+1;
	}
	total_filtrado=total;
	return total;
}

int ArchivoFactura::FiltrarCantidadFactura (string aux) {
	int total = 0;
	for(int i=0;i<Cantidad();i++) { 
		if (FiltrarFactura(i, aux)==true){
			total = total+1;}
	}
	total_filtrado=total;
	return total;
}

int ArchivoFactura::FiltrarCantidadProducto (string aux) {
	int total = 0;
	for(int i=0;i<Cantidad();i++) { 
		if (FiltrarProducto(i, aux)==true)
			total++;
	}
	total_filtrado=total;
	return total;
}
int ArchivoFactura::FiltrarCantidadFecha (Fecha f1, Fecha f2) {
	int total=0;
	for(int i=0;i<Cantidad();i++) { 
		if (FiltrarFecha(i, f1, f2) == true)
			total++;
	}
	total_filtrado = total;
	return total;
}

int ArchivoFactura::BuscarCodigoCliente (string parte, int &pos) {
	stringstream a;
	string s;
	for(int i=pos;pos<Cantidad();i++,pos++) {
		nodo_venta &p = V[pos];
		a<<p.DNI;
		s = a.str();
		if (s.find(parte, 0) != string:: npos)
			return pos;
	}
	return NO_SE_ENCUENTRA;
}

int ArchivoFactura::BuscarCodigoProducto (string parte, int &pos) {
	stringstream a;
	string s;
	for(int i=pos;pos<Cantidad();i++,pos++) {
		nodo_venta &p = V[pos];
		a<<p.CODIGO;
		s = a.str();
		if (s.find(parte, 0) != string:: npos)
			return pos;
	}
	return NO_SE_ENCUENTRA;
}

int ArchivoFactura::BuscarCodigoFactura (string parte, int &pos) {
	stringstream a;
	string s;
	for(int i=pos;pos<Cantidad();i++,pos++) {
		nodo_venta &p = V[pos];
		a<<p.ID;
		s = a.str();
		if (s.find(parte, 0) != string:: npos)
			return pos;
	}
	return NO_SE_ENCUENTRA;
}

int ArchivoFactura::FiltrarCantidadClienteConFecha (string aux, Fecha f1 , Fecha f2 ) {
	int total = 0;
	for(int i=0;i<Cantidad();i++) { 
		if((FiltrarCliente(i, aux)==true)and (FiltrarFecha(i, f1, f2)== true))
			total++;
	}	
	total_filtrado= total;
	return total;
}

int ArchivoFactura::FiltrarCantidadFacturaConFecha (string aux, Fecha f1 , Fecha f2 ) {
	int total = 0;
	for(int i=0;i<Cantidad();i++) {
		if((FiltrarFactura(i, aux)==true)and (FiltrarFecha(i, f1, f2)== true))
			total++;
	}
	total_filtrado= total;
	return total;
}

int ArchivoFactura::FiltrarCantidadProductoConFecha (string aux, Fecha f1, Fecha f2) {
	int total=0;
	for(int i=0;i<Cantidad();i++) { 
		if((FiltrarProducto(i, aux)==true)and (FiltrarFecha(i, f1, f2)== true))
			total++;
	}
	total_filtrado= total;
	return total;
}

int ArchivoFactura::BuscarFecha (Fecha f1, Fecha f2, int &pos) {
	for(int i=pos;pos<Cantidad();i++,pos++) {
//		nodo_venta aux = Ver(pos);
		if(FiltrarFecha(pos,f1,f2)==true)
			return pos;
	}	
	return NO_SE_ENCUENTRA;
}


int ArchivoFactura::VerTotalFiltrado ( )const {
	return total_filtrado;
}

