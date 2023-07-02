#include<iostream>
#include "ArchivoCliente.h"
#include "Cliente.h"
#include <cstdlib>
#include "ArchivoProducto.h"
#include "Producto.h"
#include <string>
#include "Archivo.h"
#include "ArchivoFactura.h"
#include "Factura.h"
using namespace std;

/// cargar 2 clientes en un Archivo
int main(){
	ArchivoCliente archi("hojacliente.dat");
	archi.Abrir();
	Cliente c0(114456,"tito","Perez","juan del campillo 3075","342 44662**",1,1,1962);
	archi.CargarCliente(c0);
	archi.Guardar();
	archi.Abrir();
	for(int i=0;i<archi.Cantidad();i++) {
		Cliente aux=archi.Ver(i);
			cout<<"DNI: "<<aux.VerDni()<<endl
				<<"Apellido: "<<aux.VerApellido()<<endl
				<<"Nombre: "<<aux.VerNombre()<<endl
				<<"Direccion: "<<aux.VerDireccion()<<endl
				<<"Telefono: "<<aux.VerTelefono()<<endl
				<<"Dia: "<<aux.VerDia()<<endl
				<<"Mes: "<<aux.VerMes()<<endl
				<<"Anio: "<<aux.VerAnio()<<endl
				<<"Existe: "<<aux.VerExistencia()<<endl;
			cout<<"-------------------------"<<endl;
	}
	cout<<archi.Cantidad()<<endl;
	archi.Guardar();
	system("pause");
	return 0;
}

/// cargar 2 Producto en un Archivo
//int main(){ 
//	ArchivoProducto archi("hojaproducto.dat");
//	if(archi.Abrir()){
//		cout<<"se abrio"<<endl;
//	}else{
//		cout<<"no se abrio"<<endl;
//	}
////	Producto p0(1,"caramelos",0.1f);
////	Producto p1(14243,"alfajores",10.5f);
////	Producto p2(12322,"conitos",62.5f);
//	Producto p3(84565,"chocolate",27.6f);
////	archi.CargarProducto(p0);
////	archi.CargarProducto(p1);
////	archi.CargarProducto(p2);
//	archi.CargarProducto(p3);
//	if(!archi.Guardar()){
//		cout<<"No se guardo un carajo"<<endl;
//	}else{
//		cout<<"Guardo todo"<<endl;
//	}
//	if(!archi.Abrir()){
//		cout<<"no se abrio"<<endl;
//	}else{
//		cout<<"se abrio"<<endl;
//	}
//	for(int i=0;i<archi.Cantidad();i++) { 
//		Producto aux;
//		aux=archi.Ver(i);
//		cout<<"codigo: "<<aux.VerCodigo()<<endl
//			<<"nombre: "<<aux.VerNombre()<<endl
//			<<"Precio: "<<aux.VerPrecio()<<endl
//			<<"Existe: "<<aux.VerExistencia()<<endl;
//			cout<<"-------------------------"<<endl;
//	}
//	cout<<archi.Cantidad()<<endl;
//	bool error=archi.Guardar();
//	if(error==true){
//		cout<<"Guardo todo"<<endl;
//	}else{
//		cout<<"No se guardo un carajo"<<endl;
//	}
//	system("pause");
//	return 0;
//}

/// vender 2 Productos a un Cliente
//int main(){
//	Factura fac;
//	fac.CargaCliente(115255);
//	fac.CargarCarrito(14243,1);
//	fac.CargarCarrito(1,50);
//	cout<<"total: "<<fac.VerTotal()<<endl;
//	ArchivoFactura archi("hojafactura.dat");
//	fac.Vender(archi);
//	system("pause");
//	return 0;
//}
//
//int main(void){
//	system("pause");
//}
