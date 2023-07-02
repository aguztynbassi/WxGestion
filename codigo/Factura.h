#ifndef FACTURA_H
#define FACTURA_H
#include <string>
#include <vector>
#include "Fecha.h"
#include "ArchivoCliente.h"
#include "ArchivoProducto.h"
#include <fstream>
#include <cstring>

class ArchivoFactura;

using namespace std;

struct nodo_venta{
	char ID[14];
	int DIA,MES,ANIO;
	float CANTIDAD;
	//Producto
	unsigned int CODIGO;
	char NOMBRE_P[32];
	float PRECIO;
	//Cliente
	unsigned int DNI;
	char NOMBRE[20];
	char APELLIDO[20];
	char DIRECCION[40];
	char TELEFONO[20];
	
	nodo_venta(){
		string id="NULL";
		strcpy(ID,id.c_str());
		CODIGO=DNI=DIA=MES=ANIO=0;
		CANTIDAD=0.0f;
		strcpy(NOMBRE,id.c_str());
		strcpy(APELLIDO,id.c_str());
		strcpy(DIRECCION,id.c_str());
		strcpy(TELEFONO,id.c_str());
		
		strcpy(NOMBRE_P,id.c_str());
	}
	
	nodo_venta(string id, string nc, string ap, string di, string t, string np, unsigned int idc, unsigned int idp, int d, int m, int a, float c, float p){
		strcpy(ID,id.c_str());
		DIA=d;
		MES=m;
		ANIO=a;
		CANTIDAD=c;
		
		DNI=idc;
		strcpy(NOMBRE,nc.c_str());
		strcpy(APELLIDO,ap.c_str());
		strcpy(TELEFONO,t.c_str());
		strcpy(DIRECCION,di.c_str());
		
		CODIGO=idp;
		strcpy(NOMBRE_P,np.c_str());
		PRECIO=p;
	}
	
	void GuardarDesdeBinario (ofstream & o) {
		nodo_venta aux;
		
		strcpy(aux.ID,ID);
		aux.DIA=DIA;
		aux.MES=MES;
		aux.ANIO=ANIO;
		aux.CANTIDAD=CANTIDAD;
		
		aux.DNI=DNI;
		strcpy(aux.NOMBRE,NOMBRE);
		strcpy(aux.APELLIDO,APELLIDO);
		strcpy(aux.DIRECCION,DIRECCION);
		strcpy(aux.TELEFONO,TELEFONO);
		
		aux.CODIGO=CODIGO;
		strcpy(aux.NOMBRE_P,NOMBRE_P);
		aux.PRECIO=PRECIO;
		
		o.write((char*)&(aux), sizeof(nodo_venta));
	}
	
	void LeerDesdeBinario (ifstream & i) { 
		
		nodo_venta aux;
		i.read((char*)&aux,sizeof(aux));
		
		strcpy(ID, aux.ID);
		DIA=aux.DIA;
		MES=aux.MES;
		ANIO=aux.ANIO;
		CANTIDAD=aux.CANTIDAD;
		
		DNI=aux.DNI;
		strcpy(NOMBRE, aux.NOMBRE);
		strcpy(APELLIDO, aux.APELLIDO);
		strcpy(DIRECCION, aux.DIRECCION);
		strcpy(TELEFONO, aux.TELEFONO);
		
		CODIGO=aux.CODIGO;
		strcpy(NOMBRE_P, aux.NOMBRE_P);
		PRECIO=aux.PRECIO;
	}
	
	bool operator<(nodo_venta n){
		if(this->ID<n.ID) return true;
	}
	bool operator>(nodo_venta n){
		if(this->ID>n.ID) return true;
	}
	bool operator==(nodo_venta n){
		if(this->ID==n.ID) return true;
	}
	using struct_binario = nodo_venta;
};

class Factura{
private:
	ArchivoCliente HojaCliente;
	ArchivoProducto HojaProducto;
	Fecha f;
	string ID;
	unsigned int CodigoCliente;
	float total;
	vector <nodo_venta> carrito;
public:
	/**
	* @brief
	*	constructor por defecto
	*/
	Factura();
	/**
	* @brief
	*	constructor
	* @param ArchivoCliente
	* @param ArchivoProducto
	*/
	Factura(ArchivoCliente, ArchivoProducto);
	/**
	* @brief
	*	Busca y carga un cliente a la venta si existe
	* @param DNI del Cliente
	* @return true si existe
	*/
	bool CargaCliente(unsigned int);
	/**
	* @brief
	*	Busca y carga un Producto y su cantidad (<0.0f) al carrito
	* @param codigo de barras del Producto
	* @param cantidad del articulo
	*/
	void CargarCarrito(unsigned int, float);
	/**
	* @brief
	*	Carga la venta en el vector de ventas
	* @param ArchivoFactura
	*/
	void Vender(ArchivoFactura &);
	/**
	* @brief
	*	muestra el codigo de la factura AAAAMMDDHHMMSS utilizando la fecha como
	*	comstructor del codigo. Esto se hizo porque a los fines del proyecto
	*	no se va a realizar mas de una venta en el mismo momento
	* @return id de la factura
	*/
	string VerID()const;
	/**
	* @brief
	*	muestra el DNI del cliente
	* @return id del Cliente
	*/
	unsigned int VerIDCliente()const;
	/**
	* @brief
	*	calcula todos los precios de Productos por la cantidad
	* @return el total de la venta
	*/
	float VerTotal()const;
	/**
	* @brief
	*	funsion que compara si el codigo de la factura de n es menor que n+1
	* @param nodo_venta n 
	* @param nodo_venta n+1
	* @return true si n < n+1
	*/
	static bool criterio_comparacion_codigo(nodo_venta, nodo_venta);
	/**
	* @brief
	*	funsion que compara si el codigo del Cliente n es menor que n+1
	* @param nodo_venta n 
	* @param nodo_venta n+1
	* @return true si n < n+1
	*/
	static bool criterio_comparacion_cliente(nodo_venta, nodo_venta);
	/**
	* @brief
	*	funsion que compara si el codigo del Producto n es menor que n+1
	* @param nodo_venta n 
	* @param nodo_venta n+1
	* @return true si n < n+1
	*/
	static bool criterio_comparacion_producto(nodo_venta, nodo_venta);
	/**
	* @brief
	*	destructor
	*/
	~Factura();
};

#endif

