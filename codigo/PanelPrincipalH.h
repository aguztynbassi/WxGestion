#ifndef PANELPRINCIPALH_H
#define PANELPRINCIPALH_H
#include "wxfbWindows.h"
#include "ArchivoCliente.h"
#include "ArchivoProducto.h"
#include "ArchivoFactura.h"
#include <wx/string.h>
#include <wx/msgdlg.h>

class PanelPrincipalH : public PanelPrincipal {
	
private:
	ArchivoCliente &archi_cliente;
	ArchivoProducto &archi_producto;
	ArchivoFactura &archi_factura;
	double total_factura=0;
	/**
	* Toma los datos del Cliente desde la instancia de ArchivoCliente y los carga en su
	* correspondiente fila de la grilla. Se usa al cargar por primera vez, al editar,
	* o al agregar Cliente. La grilla ya debe tener lugar, es decir, debe existir el
	* renglon (estara vacio o tendra basura).
	* @param i el indice del Cliente en el arreglo de la clase ArchivoCliente (en base 0)
	**/
	void CargarFilaCliente(int i);
	/**
	* Toma los datos del Producto desde la instancia de ArchivoProducto y los carga en su
	* correspondiente fila de la grilla. Se usa al cargar por primera vez, al editar,
	* o al agregar Producto. La grilla ya debe tener lugar, es decir, debe existir el
	* renglon (estara vacio o tendra basura).
	* @param i el indice del Cliente en el arreglo de la clase ArchivoProducto (en base 0)
	**/
	void CargarFilaProducto(int i);
	void CargarFiltrado_Cliente(wxString filtradoC);
	void CargarFiltrado_Producto(wxString filtradoP);
	void CargarFiltrado(wxString filtrado);
	void CargarFiltrado(Fecha , Fecha );
	void CargarFiltrado(wxString filtrado, Fecha , Fecha );
protected:
	/**
	* Lanza el manual de usuario
	**/
	void OnClickManual( wxCommandEvent& event ) ;
	/**
	* Lanza la licencia
	**/
	void OnClickLicencia( wxCommandEvent& event ) ;
	/**
	* Lanza ventana con nombre del proyecto y autores
	**/
	void OnClickSobreMi( wxCommandEvent& event ) ;
	/**
	* El doble click en la grilla equivale al click en el boton "Editar".
	**/
	void OnDobleClickGrillaCliente( wxGridEvent& event ) ;
	/**
	* El doble click en la grilla equivale al click en el boton "Editar".
	**/
	void OnClickDobleClickGrillaProducto( wxGridEvent& event ) ;
	/**
	* Si se hace click en la cabecera de alguna columna, la tabla se ordena segun
	* ese dato. Para esto, se le pide a la base de datos que ordene, y luego 
	* se recargan los datos de todas las filas.
	**/
	void OnClickGrillaCliente( wxGridEvent& event ) ;
	/**
	* Si se hace click en la cabecera de alguna columna, la tabla se ordena segun
	* ese dato. Para esto, se le pide a la base de datos que ordene, y luego 
	* se recargan los datos de todas las filas.
	**/
	void OnClickGrillaProducto( wxGridEvent& event ) ;
	/**
	* El doble click en el texto equivale al click buscar.
	**/
	void EnterBuscarCliente( wxCommandEvent& event ) ;
	/**
	* Cuando se hace click en buscar, se busca desde la persona que esta seleccionada
	* en la tabla, en adelante, algun nombre y apellido que contenga lo que indica
	* el cuadro de busqueda (puede contenerlo en cualquier parte, y la busqueda no
	* distingue mayusculas y minusculas).
	* Si hay mas de uno que coinciden, cada click en buscar nos lleva al siguiente.
	**/
	void OnClickBuscarCliente( wxCommandEvent& event ) ;
	/**
	* El doble click en el texto equivale al click buscar.
	**/
	void EnterBuscarProducto( wxCommandEvent& event ) ;
	/**
	* Cuando se hace click en buscar, se busca desde la persona que esta seleccionada
	* en la tabla, en adelante, algun codigo que contenga lo que indica
	* el cuadro de busqueda
	* Si hay mas de uno que coinciden, cada click en buscar nos lleva al siguiente.
	**/
	void OnClickBuscarProducto( wxCommandEvent& event ) ;
	/**
	* El doble click en el texto equivale al click buscar.
	**/
	void EnterBuscarFactura( wxCommandEvent& event ) ;
	/**
	* Cuando se hace click en buscar, se busca desde la persona que esta seleccionada
	* en la tabla, en adelante, algun codigo que contenga lo que indica
	* el cuadro de busqueda
	* Si hay mas de uno que coinciden, cada click en buscar nos lleva al siguiente.
	**/
	void OnClickBuscarFactura( wxCommandEvent& event ) ;
	/**
	* Al hacer click en "Agregar", se abre de forma modal la ventana para ingresar
	* los datos. En forma modal significa que esta ventana espera a que termine la
	* otra. Cuando termina, el codigo de retorno me indica si la otra ventana agrego
	* o no (el usuario puede hacer click en Agregar o en Cancelar) a un nuevo
	* cliente. En caso afirmativo, esta ventana debe actualizar la grilla.
	**/
	void OnClickAgregarCliente( wxCommandEvent& event ) ;
	/**
	* Al hacer click en "Agregar", se abre de forma modal la ventana para ingresar
	* los datos. En forma modal significa que esta ventana espera a que termine la
	* otra. Cuando termina, el codigo de retorno me indica si la otra ventana agrego
	* o no (el usuario puede hacer click en Agregar o en Cancelar) a un nuevo
	* Producto. En caso afirmativo, esta ventana debe actualizar la grilla.
	**/
	void OnClickAgregarProducto( wxCommandEvent& event ) ;
	/**
	* Al hacer click en "Vender", se abre de forma modal la ventana para ingresar
	* los datos. En forma modal significa que esta ventana espera a que termine la
	* otra. Cuando termina, el codigo de retorno me indica si la otra ventana agrego
	* o no (el usuario puede hacer click en Agregar o en Cancelar) a una nueva
	* venta. En caso afirmativo, esta ventana debe actualizar la grilla.
	**/
	void OnClickVender( wxCommandEvent& event ) ;
	/**
	* Al hacer click en "Ver/Editar", se abre de forma modal la ventana para ver y/o
	* modificar los datos. En forma modal significa que esta ventana espera a que 
	* termine la otra. Cuando termina, el codigo de retorno me indica si la otra 
	* ventana modifico o no los datos (el usuario puede hacer click en Agregar o
    * en Cancelar) En caso afirmativo, esta ventana debe actualizar la grilla.
	**/
	void OnClickVerCliente( wxCommandEvent& event ) ;
	/**
	* Al hacer click en "Ver/Editar", se abre de forma modal la ventana para ver y/o
	* modificar los datos. En forma modal significa que esta ventana espera a que 
	* termine la otra. Cuando termina, el codigo de retorno me indica si la otra 
	* ventana modifico o no los datos (el usuario puede hacer click en Agregar o
	* en Cancelar) En caso afirmativo, esta ventana debe actualizar la grilla.
	**/
	void OnClickVerProducto( wxCommandEvent& event ) ;
	/**
	* Cuando se hace click en "Eliminar", primero se pide confirmacion, y en caso
	* afirmativo se elimina el Cliente de la base de datos, y la fila de la tabla.
	**/
	void OnClickEliminarCliente( wxCommandEvent& event ) ;
	/**
	* Cuando se hace click en "Eliminar", primero se pide confirmacion, y en caso
	* afirmativo se elimina el Producto de la base de datos, y la fila de la tabla.
	**/
	void OnClickEliminarProducto( wxCommandEvent& event ) ;
	
	void OnAbout( wxCommandEvent& event ) ;
public:
	/**
	* Inicializa la ventana, llenando la grilla y definiendo
	* las propiedades adicionales de la tabla.
	**/
	PanelPrincipalH(ArchivoCliente &archi1, ArchivoProducto &archi2, ArchivoFactura &archi3);
	void OnButtonClose(wxCommandEvent &evt);
	/**
	* Destructor
	**/
	~PanelPrincipalH();
};

#endif

