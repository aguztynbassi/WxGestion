#ifndef VAGREGARFACTURA_H
#define VAGREGARFACTURA_H
#include "wxfbWindows.h"
#include "ArchivoFactura.h"
#include "Factura.h"
#include "ArchivoCliente.h"
#include "ArchivoProducto.h"

class VAgregarFactura : public VFactura {
	
private:
	ArchivoFactura &archi_factura;
	ArchivoCliente &archi_cliente;
	ArchivoProducto &archi_producto;
	Factura f;
protected:
	void OnClickCancelarVenta( wxCommandEvent& event ) ;
	void OnClickVender( wxCommandEvent& event ) ;
	void OnClickCargarCliente( wxCommandEvent& event ) ;
	void OnClickCargarCarrito( wxCommandEvent& event ) ;
public:
	VAgregarFactura(wxWindow *parent, ArchivoFactura &archi, ArchivoCliente &ac, ArchivoProducto &ap);
	~VAgregarFactura();
};

#endif

