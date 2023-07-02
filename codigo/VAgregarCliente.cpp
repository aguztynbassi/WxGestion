#include "VAgregarCliente.h"
#include "Cliente.h"
#include "ArchivoCliente.h"
#include "Application.h"
#include <string>
#include <cstdlib>
#include "Utils.h"
#include "wxfbWindows.h"
#include <wx/msgdlg.h>
using namespace std;

VAgregarCliente::~VAgregarCliente() {EndModal(0);}

VAgregarCliente::VAgregarCliente (wxWindow *parent, ArchivoCliente &archi) : VCliente(parent), archi_cliente(archi) {
	SetTitle("Contacto Nuevo");
	m_button6->SetLabel("Cancelar");
	m_button7->SetLabel("Guardar");
}

void VAgregarCliente::ClickCancelar( wxCommandEvent& event )  {EndModal(0);}

void VAgregarCliente::ClickGuardar( wxCommandEvent& event){
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
	int val=archi_cliente.BuscarDNI(c.VerDni(),0);
	if (error.size())
		wxMessageBox(std_to_wx(error));
	else if(val!=(NO_SE_ENCUENTRA)){
		int res = wxMessageBox(c_to_wx("El cliente ya existe.¿Desea modificarlo?"),"Advertencia",wxYES_NO);
		if (res==wxYES) {
			archi_cliente.Modificar(val,c);
			archi_cliente.Guardar();
			EndModal(1);
		}
	}else{
		archi_cliente.CargarCliente(c);
		archi_cliente.Guardar();
		EndModal(1);
	}
}

