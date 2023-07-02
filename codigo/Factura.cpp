#include "Factura.h"
#include <fstream>
#include "Cliente.h"
#include "Producto.h"
#include <string>
#include <cstring>
#include <sstream>
#include "ArchivoProducto.h"
#include "ArchivoCliente.h"
#include "ArchivoFactura.h"
#include "Fecha.h"

using namespace std;

Factura::Factura ():HojaCliente("hojacliente.dat"), HojaProducto("hojaproducto.dat"){
	HojaCliente.Abrir();
	HojaProducto.Abrir();
	stringstream aux;
	aux<<f.VerAnio()<<f.VerMes()<<f.VerDia()<<f.VerHora()<<f.VerMinuto()<<f.VerSegundo();
	ID=aux.str();
	total=0.0f;
}

Factura::Factura (ArchivoCliente nc, ArchivoProducto np):HojaCliente(nc), HojaProducto(np){
	stringstream aux;
	aux<<f.VerAnio()<<f.VerMes()<<f.VerDia()<<f.VerHora()<<f.VerMinuto()<<f.VerSegundo();
	ID=aux.str();
	total=0.0f;
}

Factura::~Factura ( ) {carrito.clear();}

float Factura::VerTotal ( ) const { return total;}

string Factura::VerID ( ) const {return ID;}

unsigned int Factura::VerIDCliente ( ) const {return CodigoCliente;}

bool Factura::criterio_comparacion_codigo (nodo_venta f1, nodo_venta f2) {return (f1.ID < f2.ID);}

bool Factura::criterio_comparacion_cliente (nodo_venta f1, nodo_venta f2) {return (f1.DNI < f2.DNI);}

bool Factura::criterio_comparacion_producto (nodo_venta f1, nodo_venta f2) {return (f1.CODIGO < f2.CODIGO);}

void Factura::CargarCarrito (unsigned int idproducto, float c) {
	nodo_venta au;
	int pos = HojaCliente.BuscarDNI(CodigoCliente,0);
	Cliente aux1=HojaCliente.Ver(pos);
	for(int i=0;i<HojaProducto.Cantidad();i++) { 
		Producto aux=HojaProducto.Ver(i);
		if(aux.VerCodigo()==idproducto and c > 0.0f){
			strcpy(au.ID,ID.c_str());
			au.CANTIDAD=c;
			au.DIA=f.VerDia();
			au.MES=f.VerMes();
			au.ANIO=f.VerAnio();
			
			au.DNI=CodigoCliente;
			strcpy(au.NOMBRE,aux1.VerNombre().c_str());
			strcpy(au.APELLIDO,aux1.VerApellido().c_str());
			strcpy(au.DIRECCION,aux1.VerTelefono().c_str());
			strcpy(au.TELEFONO,aux1.VerDireccion().c_str());
			
			
			au.CODIGO=idproducto;
			strcpy(au.NOMBRE_P,aux.VerNombre().c_str());
			au.PRECIO=aux.VerPrecio();
			
			total += (aux.VerPrecio()*c);
		}
	}
	carrito.push_back(au);
}

bool Factura::CargaCliente (unsigned int idcliente) {
	for(int i=0;i<HojaCliente.Cantidad();i++) { 
		Cliente aux;
		aux=HojaCliente.Ver(i);
		if(aux.VerDni()==idcliente){
			CodigoCliente=idcliente;
			return true;
		}
	}
	return false;
}

void Factura::Vender ( ArchivoFactura & HojaFactura) {
	for(size_t i=0;i<carrito.size();i++) { 
		nodo_venta aux=carrito[i];
		HojaFactura.Cargar(aux);
	}
}

