///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun 17 2015)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __WXFBWINDOWS_H__
#define __WXFBWINDOWS_H__

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/menu.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/sizer.h>
#include <wx/statbox.h>
#include <wx/radiobut.h>
#include <wx/button.h>
#include <wx/grid.h>
#include <wx/panel.h>
#include <wx/notebook.h>
#include <wx/frame.h>
#include <wx/dialog.h>
#include <wx/listbox.h>
#include <wx/statline.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class PanelPrincipal
///////////////////////////////////////////////////////////////////////////////
class PanelPrincipal : public wxFrame 
{
	private:
	
	protected:
		wxMenuBar* m_menubar1;
		wxMenu* m_ayuda;
		wxNotebook* m_notebook;
		wxPanel* m_panel1;
		wxStaticText* m_staticText15;
		wxTextCtrl* m_f1dia;
		wxStaticText* m_staticText19;
		wxTextCtrl* m_f1mes;
		wxStaticText* m_staticText201;
		wxTextCtrl* m_f1anio;
		wxStaticText* m_staticText16;
		wxTextCtrl* m_f2dia;
		wxStaticText* m_staticText21;
		wxTextCtrl* m_f2mes;
		wxStaticText* m_staticText22;
		wxTextCtrl* m_f2anio;
		wxRadioButton* m_radioBtnFactura;
		wxRadioButton* m_radioBtnCliente;
		wxRadioButton* m_radioBtnProducto;
		wxStaticText* m_staticText17;
		wxTextCtrl* m_id_buscar;
		wxButton* m_button1;
		wxGrid* grilla_ventas;
		wxButton* m_button2;
		wxStaticText* m_staticText20;
		wxTextCtrl* m_text_total_filtro;
		wxPanel* m_panel2;
		wxTextCtrl* m_textCtrl121;
		wxButton* m_button4;
		wxGrid* grilla_cliente;
		wxButton* m_button5;
		wxButton* m_button7;
		wxPanel* m_panel3;
		wxTextCtrl* m_textCtrl122;
		wxButton* m_button8;
		wxGrid* grilla_productos;
		wxButton* m_button9;
		wxButton* m_button11;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnClickManual( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnClickLicencia( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnClickSobreMi( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnClickBuscarFactura( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnClickVender( wxCommandEvent& event ) { event.Skip(); }
		virtual void EnterBuscarCliente( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnClickBuscarCliente( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnDobleClickGrillaCliente( wxGridEvent& event ) { event.Skip(); }
		virtual void OnClickGrillaCliente( wxGridEvent& event ) { event.Skip(); }
		virtual void OnClickAgregarCliente( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnClickEliminarCliente( wxCommandEvent& event ) { event.Skip(); }
		virtual void EnterBuscarProducto( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnClickBuscarProducto( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnClickDobleClickGrillaProducto( wxGridEvent& event ) { event.Skip(); }
		virtual void OnClickGrillaProducto( wxGridEvent& event ) { event.Skip(); }
		virtual void OnClickAgregarProducto( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnClickEliminarProducto( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		PanelPrincipal( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("WxSistema"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 964,492 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
		
		~PanelPrincipal();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class VCliente
///////////////////////////////////////////////////////////////////////////////
class VCliente : public wxDialog 
{
	private:
	
	protected:
		wxStaticText* m_staticText2;
		wxTextCtrl* m_text_dni;
		wxStaticText* m_staticText3;
		wxTextCtrl* m_text_nombre;
		wxStaticText* m_staticText31;
		wxTextCtrl* m_text_apellido;
		wxStaticText* m_staticText311;
		wxTextCtrl* m_text_direccion;
		wxStaticText* m_staticText3111;
		wxTextCtrl* m_text_telefono;
		wxStaticText* m_staticText14;
		wxTextCtrl* m_text_dia;
		wxTextCtrl* m_text_mes;
		wxTextCtrl* m_text_anio;
		wxButton* m_button6;
		wxButton* m_button7;
		
		// Virtual event handlers, overide them in your derived class
		virtual void ClickCancelar( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickGuardar( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		VCliente( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Cliente"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 580,357 ), long style = wxDEFAULT_DIALOG_STYLE ); 
		~VCliente();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class VProducto
///////////////////////////////////////////////////////////////////////////////
class VProducto : public wxDialog 
{
	private:
	
	protected:
		wxStaticText* m_staticText9;
		wxTextCtrl* m_text_codigo;
		wxStaticText* m_staticText91;
		wxTextCtrl* m_text_nombre;
		wxStaticText* m_staticText92;
		wxTextCtrl* m_text_precio;
		wxButton* m_button8;
		wxButton* m_button9;
		
		// Virtual event handlers, overide them in your derived class
		virtual void ClickCancelar( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickGuardar( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		VProducto( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Producto"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 436,161 ), long style = wxDEFAULT_DIALOG_STYLE ); 
		~VProducto();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class VFactura
///////////////////////////////////////////////////////////////////////////////
class VFactura : public wxDialog 
{
	private:
	
	protected:
		wxStaticText* m_id;
		wxStaticText* m_staticText10;
		wxTextCtrl* m_text_Cargar_cliente;
		wxButton* m_button15;
		wxListBox* m_lista_cliente;
		wxStaticLine* m_staticline1;
		wxStaticText* m_staticText11;
		wxTextCtrl* m_text_Cargar_producto;
		wxStaticText* m_staticText12;
		wxTextCtrl* m_text_Cargar_cantidad;
		wxButton* m_button16;
		wxListBox* m_lista_productos;
		wxStaticText* m_total;
		wxStaticLine* m_staticline11;
		wxButton* m_button17;
		wxButton* m_button18;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnClickCargarCliente( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnClickCargarCarrito( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnClickCancelarVenta( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnClickVender( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		VFactura( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Factura"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 451,487 ), long style = wxDEFAULT_DIALOG_STYLE ); 
		~VFactura();
	
};

#endif //__WXFBWINDOWS_H__
