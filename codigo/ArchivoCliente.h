#ifndef ARCHIVOCLIENTE_H
#define ARCHIVOCLIENTE_H
#include "ArchivoCliente.h"
#include "Cliente.h"
#include "Archivo.h"
#include <string>
using namespace std;
/// @brief constante para indicar que falló una búsqueda
#define NO_SE_ENCUENTRA -1

/**
* @brief
*	enumeración para los posibles criterios de ordenamiento
*	es para pasar como argumento al método, queda más legible que un número
*/
enum CriterioOrdenDelCliente { ORDEN_DNI, ORDEN_APELLIDO_Y_NOMBRE, ORDEN_TELEFONO, ORDEN_DIRECCION };

class ArchivoCliente : public Archivo<Cliente> {
private:
	int cliente_filtrado=Cantidad();
public:
	/**
	* @brief
	*	constructor por defecto que solo le paso el nombre del Archivo
	* @param n nombre del Archivo
	*/
	ArchivoCliente(string n);
	/**
	* @brief
	*	destructor
	*/
	~ArchivoCliente();
	/**
	* @brief
	*	funcion para cargar un nuevo Cliente al final del vector
	* @param a es el nuevo Cliente
	*/
	void CargarCliente(Cliente);
	/**
	* @brief
	*	funcion para Eliminar un Cliente del vector
	* @param i posicion del vector
	*/
	void EliminarCliente(int); 
	/**
	* @brief
	*	ordena a los clientes segun el vector CriterioOrdenDelCliente
	* @param criterio es el parametro que se le pasa
	*/
	void Ordenar(CriterioOrdenDelCliente criterio);
	///-------       Filtrado Cliente    -------- /
	bool Filtrar_NomCliente (int, string);
	bool Filtrar_DniCliente (int, string);
	///-------  Filtrado Cantidad Cliente -------/
	int VerClienteFiltrado() const;
	int Filtrar_cant_NomCliente (string);
	int Filtrar_cant_DniCliente (string);
	///---Funciones que retornan la posicion de lo buscado ---///
	int BuscarDNI(string parte, int &pos);
	int BuscarDNI(unsigned int, int pos);
	int BuscarApellidoYNombre(string parte, int &pos);
};

#endif

