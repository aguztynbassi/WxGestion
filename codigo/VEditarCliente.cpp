#include "VEditarCliente.h"
#include "ArchivoCliente.h"
#include "wxfbWindows.h"
#include "Utils.h"
#include "Cliente.h"
#include <wx/string.h>
#include <wx/msgdlg.h>

VEditarCliente::~VEditarCliente() {EndModal(0);}

void VEditarCliente::ClickCancelar (wxCommandEvent & event) {EndModal(0);}

void VEditarCliente::ClickGuardar (wxCommandEvent & event) {
	long dni, dia, mes, anio;
	m_text_dia->GetValue().ToLong(&dia);
	m_text_mes->GetValue().ToLong(&mes);
	m_text_anio->GetValue().ToLong(&anio);
	m_text_dni->GetValue().ToLong(&dni);
	Cliente c(dni,
			  wx_to_std(m_text_nombre->GetValue()),
			  wx_to_std(m_text_apellido->GetValue()),
			  wx_to_std(m_text_direccion->GetValue()),
			  wx_to_std(m_text_telefono->GetValue()),
			  dia,mes,anio);
	string error = c.Validar();
	if (error.size())
		wxMessageBox(std_to_wx(error));
	else{
		archi_cliente.Modificar(indice, c);
		archi_cliente.Guardar();
		EndModal(1);
	}
}

VEditarCliente::VEditarCliente (wxWindow *parent, int cual, ArchivoCliente &archi) : VCliente(parent), archi_cliente(archi) {
	SetTitle("Editar Cliente");
	m_button6->SetLabel("Cancelar");
	m_button7->SetLabel("Guardar");
	indice=cual;
	Cliente c=archi_cliente.Ver(cual);
	m_text_dni->SetValue(wxString()<<c.VerDni());
	m_text_nombre->SetValue(std_to_wx(c.VerNombre()));
	m_text_apellido->SetValue(std_to_wx(c.VerApellido()));
	m_text_direccion->SetValue(std_to_wx(c.VerDireccion()));
	m_text_telefono->SetValue(std_to_wx(c.VerTelefono()));
	m_text_dia->SetValue(wxString()<<c.VerDia());
	m_text_mes->SetValue(wxString()<<c.VerMes());
	m_text_anio->SetValue(wxString()<<c.VerAnio());
}
