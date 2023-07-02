#ifndef MX_APPLICATION_H
#define MX_APPLICATION_H

#include <wx/app.h>
#include "ArchivoCliente.h"
#include "ArchivoProducto.h"
#include "ArchivoFactura.h"

using namespace std;
class mxApplication : public wxApp {
public:
	mxApplication();
	virtual bool OnInit();
private:
	ArchivoCliente archi_cliente;
	ArchivoProducto archi_producto;
	ArchivoFactura archi_factura;
};

#endif
