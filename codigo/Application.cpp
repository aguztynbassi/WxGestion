#include "Application.h"
#include <wx/image.h>
#include "PanelPrincipalH.h"
#include <string>
#include "ArchivoCliente.h"
#include "ArchivoProducto.h"
#include "ArchivoFactura.h"
using namespace std;

IMPLEMENT_APP(mxApplication)

mxApplication::mxApplication():archi_cliente("hojacliente.dat"),archi_producto("hojaproducto.dat"),archi_factura("hojafactura.dat"){
	archi_cliente.Abrir();
	archi_producto.Abrir();
	archi_factura.Abrir();
}
	
bool mxApplication::OnInit() {
	PanelPrincipalH *v = new PanelPrincipalH(archi_cliente,archi_producto,archi_factura);
	v->Show();
	return true;
}
