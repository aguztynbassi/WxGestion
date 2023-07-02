#include "VAgregarProducto.h"
#include "Utils.h"
#include <string>
#include <wx/msgdlg.h>
#include <wx/textctrl.h>
#include "Producto.h"
#include "ArchivoProducto.h"
using namespace std;

VAgregarProducto::VAgregarProducto(wxWindow *parent, ArchivoProducto &archi) : VProducto(parent), archi_producto(archi) {
	SetTitle("Producto Nuevo");
	m_button8->SetLabel("Cancelar");
	m_button9->SetLabel("Guardar");
}

VAgregarProducto::~VAgregarProducto() {EndModal(0);}

void VAgregarProducto::ClickCancelar (wxCommandEvent & event) {EndModal(0);}

void VAgregarProducto::ClickGuardar (wxCommandEvent & event) {
	long codi;
	double preci;
	m_text_codigo->GetValue().ToLong(&codi);
	m_text_precio->GetValue().ToDouble(&preci);
	Producto p(codi,
			   wx_to_std(m_text_nombre->GetValue()),
			   preci);
	string error=p.Validar();
	int val = archi_producto.BuscarCodigo(p.VerCodigo(), 0);
	if(error.size()){
		wxMessageBox(std_to_wx(error));
	}else if (val != NO_SE_ENCUENTRA){
		int res = wxMessageBox("El Producto ya existe.¿Desea modificarlo?", "Advertencia!!!", wxYES_NO);
		if (res == wxYES){
			archi_producto.Modificar(val, p);
			archi_producto.Guardar();
			EndModal(1);
		}
	}else{
		archi_producto.CargarProducto(p);
		archi_producto.Guardar();
		EndModal(1);
	}
}

