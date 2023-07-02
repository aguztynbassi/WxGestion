#include "VAgregarFactura.h"
#include <wx/msgdlg.h>
#include "Utils.h"
#include "Cliente.h"
#include "Producto.h"
#include <iomanip>
using namespace std;

VAgregarFactura::~VAgregarFactura() { EndModal(0);}

void VAgregarFactura::OnClickCargarCliente( wxCommandEvent& event )  {
	long codi;
	m_text_Cargar_cliente->GetValue().ToLong(&codi);	
	wxString val1 = m_text_Cargar_cliente->GetValue();
	int pos=archi_cliente.BuscarDNI(codi,0);
	if(val1.IsEmpty() || !val1.ToLong(&codi) || pos==NO_SE_ENCUENTRA){
		m_text_Cargar_cliente->Clear();
		wxMessageBox("Debe ingresar un codigo","Error",wxOK|wxICON_ERROR,this);
		return;
	}
	Cliente aux=archi_cliente.Ver(pos);
	m_lista_cliente->Append(wxString("DNI: ")<<aux.VerDni());
	m_lista_cliente->Append(wxString("Apellido y Nombre: ")<<aux.VerApellido()<<", "<<aux.VerNombre());
	m_lista_cliente->Append(wxString("Dirección: ")<<aux.VerDireccion());
	m_lista_cliente->Append(wxString("Telefono: ")<<aux.VerTelefono());
	f.CargaCliente(codi);
	m_text_Cargar_cliente->Clear();
}

void VAgregarFactura::OnClickCargarCarrito( wxCommandEvent& event )  {
	long codi;
	double cant;
	m_text_Cargar_producto->GetValue().ToLong(&codi);
	m_text_Cargar_cantidad->GetValue().ToDouble(&cant);
	wxString val1 = m_text_Cargar_producto->GetValue();
	wxString val2 = m_text_Cargar_cantidad->GetValue();
	int pos=archi_producto.BuscarCodigo(codi,0);
	if(val1.IsEmpty() || !val1.ToLong(&codi) || val2.IsEmpty() || !val2.ToDouble(&cant) || pos==NO_SE_ENCUENTRA){
		m_text_Cargar_producto->Clear();
		m_text_Cargar_cantidad->Clear();
		wxMessageBox("Debe ingresar un codigo y cantidad","Error",wxOK|wxICON_ERROR,this);
		return;
	}
	Producto aux=archi_producto.Ver(pos);
	double total = aux.VerPrecio()*cant;
	m_lista_productos->Append(wxString()<<aux.VerNombre()<<" "<<aux.VerPrecio()<<" "<<cant<<" $"<<total);
	f.CargarCarrito(codi,cant);
	m_text_Cargar_producto->Clear();
	m_text_Cargar_cantidad->Clear();
	m_total->SetLabel(wxString("total: ")<<f.VerTotal()<<" $ ");
}

void VAgregarFactura::OnClickCancelarVenta( wxCommandEvent& event )  {EndModal(0);}

void VAgregarFactura::OnClickVender( wxCommandEvent& event )  {
	wxString val1 = m_text_Cargar_cliente->GetValue();
	wxString val3 = m_text_Cargar_producto->GetValue();
	wxString val2 = m_text_Cargar_cantidad->GetValue();
	if(!m_lista_cliente->IsEmpty() and !m_lista_productos->IsEmpty()){
		f.Vender(archi_factura);
		archi_factura.Guardar();
		EndModal(1);
	}else if(m_lista_productos->IsEmpty()){
		wxMessageBox("Debe ingresar un codigo y cantidad de Producto","Error",wxOK|wxICON_ERROR,this);
		return;
	}else{
		wxMessageBox("Debe ingresar un codigo de Cliente","Error",wxOK|wxICON_ERROR,this);
		return;
	}
}

VAgregarFactura::VAgregarFactura (wxWindow * parent, ArchivoFactura & archi, ArchivoCliente &ac, ArchivoProducto &ap) : VFactura(parent), archi_factura(archi), archi_cliente(ac), archi_producto(ap){
	SetTitle("Nueva Venta");
	m_button17->SetLabel("Cancelar");
	m_button18->SetLabel("Vender");
	m_id->SetLabel(wxString("Factura n: ")<<f.VerID());
}
