#ifndef ARCHIVOFACTURA_H
#define ARCHIVOFACTURA_H
#include "Factura.h"
#include "Archivo.h"
#include <string>
#include <vector>
#include "Fecha.h"
using namespace std;
/// @brief constante para indicar que falló una búsqueda
#define NO_SE_ENCUENTRA -1

/**
* @brief
*	enumeración para los posibles criterios de ordenamiento
*	es para pasar como argumento al método, queda más legible que un número
*/
enum CriterioOrdenDeFacturas { ORDEN_ID, ORDEN_ID_CLIENTE,  ORDEN_ID_PRODUCTO};

class ArchivoFactura: public Archivo<nodo_venta> {
private:
	int total_filtrado;
public:
	/**
	* @brief
	*	costructor
	* @param n es el nombre del Archivo
	*/
	ArchivoFactura(string);
	/**
	* @brief
	*	destructor
	*/
	~ArchivoFactura();
	/**
	* @brief
	*	ordena a las Facturas segun el vector CriterioOrdenDeFacturas
	* @param criterio es el parametro que se le pasa
	*/
	void Ordenar(CriterioOrdenDeFacturas criterio);
	/**--------Funciones Filtrado------**/
	int VerTotalFiltrado()const;
	bool FiltrarFecha(int pos, Fecha &, Fecha &);
	bool FiltrarFactura(int pos, string);
	bool FiltrarCliente(int, string);
	bool FiltrarProducto(int, string);
	/**------Cantidad de Filtrados-----**/
	int FiltrarCantidadCliente(string aux);
	int FiltrarCantidadFactura(string aux);
	int FiltrarCantidadProducto(string aux);
	int FiltrarCantidadFecha(Fecha, Fecha);
	/**------Cantidad de Filtrado con Fechas-------**/
	int FiltrarCantidadClienteConFecha(string , Fecha , Fecha );
	int FiltrarCantidadFacturaConFecha(string , Fecha , Fecha );
	int FiltrarCantidadProductoConFecha(string, Fecha , Fecha );
	/**-----Funciones para retornar la posicion de lo buscado----*/
	int BuscarCodigoCliente (string parte, int &pos);
	int BuscarCodigoProducto (string parte, int &pos);
	int BuscarCodigoFactura (string parte, int &pos);
	int BuscarFecha (Fecha, Fecha, int &);
};

#endif
