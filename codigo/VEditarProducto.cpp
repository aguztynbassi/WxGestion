#include "VEditarProducto.h"
#include <wx/msgdlg.h>
#include "ArchivoProducto.h"
#include "Producto.h"
#include <wx/string.h>
#include "Utils.h"


VEditarProducto::~VEditarProducto() {EndModal(0);}

void VEditarProducto::ClickCancelar (wxCommandEvent & event) {EndModal(0);}

void VEditarProducto::ClickGuardar (wxCommandEvent & event) {
	long codi;
	double preci;
	m_text_codigo->GetValue().ToLong(&codi);
	m_text_precio->GetValue().ToDouble(&preci);
	Producto p(codi,
			   wx_to_std(m_text_nombre->GetValue()),
			   preci);
	string error=p.Validar();
	if(error.size()){
		wxMessageBox(std_to_wx(error));
	}else{
		archi_producto.Modificar(indice, p);
		archi_producto.Guardar();
		EndModal(1);
	}
}


VEditarProducto::VEditarProducto (wxWindow * parent, int cual, ArchivoProducto & archi): VProducto(parent), archi_producto(archi) {
	SetTitle("Editar Producto");
	m_button8->SetLabel("Cancelar");
	m_button9->SetLabel("Guardar");
	indice=cual;
	Producto p=archi_producto.Ver(indice);
	m_text_codigo->SetValue(wxString()<<p.VerCodigo());
	m_text_nombre->SetValue(std_to_wx(p.VerNombre()));
	m_text_precio->SetValue(wxString()<<p.VerPrecio());
}

