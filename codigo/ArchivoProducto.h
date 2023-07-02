#ifndef ARCHIVOPRODUCTO_H
#define ARCHIVOPRODUCTO_H
#include "ArchivoProducto.h"
#include "Archivo.h"
#include "Producto.h"
#include <string>
using namespace std;
/// @brief constante para indicar que falló una búsqueda
#define NO_SE_ENCUENTRA -1

/**
* @brief
*	enumeración para los posibles criterios de ordenamiento
*	es para pasar como argumento al método, queda más legible que un número
*/
enum CriterioOrdenDelProducto { ORDEN_CODIGO, ORDEN_NOMBRE };

class ArchivoProducto : public Archivo<Producto> {
private:
	int producto_filtrado= Cantidad();
public:
	/**
	* @brief
	*	cosntructor
	* @param n es el nombre del Archivo
	*/
	ArchivoProducto(string n);
	/**
	* @brief
	*	destructor
	*/
	~ArchivoProducto();
	/**
	* @brief
	*	ordena a los productos segun el vector CriterioOrdenDelProducto
	* @param criterio es el parametro que se le pasa
	*/
	void Ordenar(CriterioOrdenDelProducto criterio);
	
	/**
	* @brief
	*	funcion para cargar un nuevo Producto al final del vector
	* @param a es el nuevo Producto
	*/
	void CargarProducto(Producto);
	/**
	* @brief
	*	funcion para Eliminar un Producto del vector
	* @param i posicion del vector
	*/
	void EliminarProducto(int);
	///----------- Filtrado Producto -----//
	bool Filtrar_NomProducto(int, string);
	bool Filtrar_CodProducto(int, string);
	///---  Filtrado Cantidad Producto ---//
	int VerProductoFiltrado()const;
	int Filtrar_cant_NomProducto(string);
	int Filtrar_cant_CodProducto (string);
	///--- Funcones que retornan la posicion de lo buscado ----//
	int BuscarNombre(string parte, int &pos);
	int BuscarCodigo(string parte, int &pos);
	int BuscarCodigo(unsigned int parte, int pos);
};

#endif

