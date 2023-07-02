///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun 17 2015)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "wxfbWindows.h"

///////////////////////////////////////////////////////////////////////////

PanelPrincipal::PanelPrincipal( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	this->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BTNFACE ) );
	
	m_menubar1 = new wxMenuBar( 0 );
	m_ayuda = new wxMenu();
	wxMenuItem* m_libro_usuario;
	m_libro_usuario = new wxMenuItem( m_ayuda, wxID_ANY, wxString( wxT("Manual de Usuario") ) + wxT('\t') + wxT("F1"), wxEmptyString, wxITEM_NORMAL );
	m_ayuda->Append( m_libro_usuario );
	
	wxMenuItem* m_licencia;
	m_licencia = new wxMenuItem( m_ayuda, wxID_ANY, wxString( wxT("Licencia") ) + wxT('\t') + wxT("F2"), wxEmptyString, wxITEM_NORMAL );
	m_ayuda->Append( m_licencia );
	
	m_ayuda->AppendSeparator();
	
	wxMenuItem* m_yo;
	m_yo = new wxMenuItem( m_ayuda, wxID_ANY, wxString( wxT("Sobre Mi") ) + wxT('\t') + wxT("F3"), wxEmptyString, wxITEM_NORMAL );
	m_ayuda->Append( m_yo );
	
	m_menubar1->Append( m_ayuda, wxT("Ayuda") ); 
	
	this->SetMenuBar( m_menubar1 );
	
	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxVERTICAL );
	
	m_notebook = new wxNotebook( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	m_panel1 = new wxPanel( m_notebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer15;
	bSizer15 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer31;
	bSizer31 = new wxBoxSizer( wxVERTICAL );
	
	wxStaticBoxSizer* sbSizer1;
	sbSizer1 = new wxStaticBoxSizer( new wxStaticBox( m_panel1, wxID_ANY, wxT("Filtrar Fecha") ), wxHORIZONTAL );
	
	m_staticText15 = new wxStaticText( sbSizer1->GetStaticBox(), wxID_ANY, wxT("Desde: "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText15->Wrap( -1 );
	sbSizer1->Add( m_staticText15, 0, wxALIGN_CENTER_VERTICAL|wxTOP|wxBOTTOM, 5 );
	
	m_f1dia = new wxTextCtrl( sbSizer1->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer1->Add( m_f1dia, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_staticText19 = new wxStaticText( sbSizer1->GetStaticBox(), wxID_ANY, wxT("/"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText19->Wrap( -1 );
	sbSizer1->Add( m_staticText19, 0, wxALIGN_CENTER_VERTICAL|wxTOP|wxBOTTOM, 5 );
	
	m_f1mes = new wxTextCtrl( sbSizer1->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer1->Add( m_f1mes, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText201 = new wxStaticText( sbSizer1->GetStaticBox(), wxID_ANY, wxT("/"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText201->Wrap( -1 );
	sbSizer1->Add( m_staticText201, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_f1anio = new wxTextCtrl( sbSizer1->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer1->Add( m_f1anio, 0, wxALIGN_CENTER_VERTICAL|wxTOP|wxBOTTOM, 5 );
	
	
	sbSizer1->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_staticText16 = new wxStaticText( sbSizer1->GetStaticBox(), wxID_ANY, wxT("Hasta: "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText16->Wrap( -1 );
	sbSizer1->Add( m_staticText16, 0, wxALIGN_CENTER_VERTICAL|wxTOP|wxBOTTOM|wxLEFT, 5 );
	
	m_f2dia = new wxTextCtrl( sbSizer1->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer1->Add( m_f2dia, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText21 = new wxStaticText( sbSizer1->GetStaticBox(), wxID_ANY, wxT("/"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText21->Wrap( -1 );
	sbSizer1->Add( m_staticText21, 0, wxALIGN_CENTER_VERTICAL|wxTOP|wxBOTTOM, 5 );
	
	m_f2mes = new wxTextCtrl( sbSizer1->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer1->Add( m_f2mes, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText22 = new wxStaticText( sbSizer1->GetStaticBox(), wxID_ANY, wxT("/"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText22->Wrap( -1 );
	sbSizer1->Add( m_staticText22, 0, wxALIGN_CENTER_VERTICAL|wxTOP|wxBOTTOM, 5 );
	
	m_f2anio = new wxTextCtrl( sbSizer1->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer1->Add( m_f2anio, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer31->Add( sbSizer1, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer36;
	bSizer36 = new wxBoxSizer( wxHORIZONTAL );
	
	wxBoxSizer* bSizer39;
	bSizer39 = new wxBoxSizer( wxVERTICAL );
	
	m_radioBtnFactura = new wxRadioButton( m_panel1, wxID_ANY, wxT("Facturas"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer39->Add( m_radioBtnFactura, 0, wxALL, 5 );
	
	m_radioBtnCliente = new wxRadioButton( m_panel1, wxID_ANY, wxT("Clientes"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer39->Add( m_radioBtnCliente, 0, wxALL, 5 );
	
	m_radioBtnProducto = new wxRadioButton( m_panel1, wxID_ANY, wxT("Productos"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer39->Add( m_radioBtnProducto, 0, wxALL, 5 );
	
	
	bSizer36->Add( bSizer39, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer38;
	bSizer38 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText17 = new wxStaticText( m_panel1, wxID_ANY, wxT("ID "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText17->Wrap( -1 );
	bSizer38->Add( m_staticText17, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_id_buscar = new wxTextCtrl( m_panel1, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer38->Add( m_id_buscar, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer38->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_button1 = new wxButton( m_panel1, wxID_ANY, wxT("Buscar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer38->Add( m_button1, 0, wxALL|wxALIGN_RIGHT|wxALIGN_BOTTOM, 5 );
	
	
	bSizer36->Add( bSizer38, 1, wxEXPAND|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer31->Add( bSizer36, 1, wxEXPAND, 5 );
	
	
	bSizer15->Add( bSizer31, 0, wxEXPAND, 5 );
	
	grilla_ventas = new wxGrid( m_panel1, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	
	// Grid
	grilla_ventas->CreateGrid( 0, 8 );
	grilla_ventas->EnableEditing( false );
	grilla_ventas->EnableGridLines( false );
	grilla_ventas->EnableDragGridSize( false );
	grilla_ventas->SetMargins( 0, 0 );
	
	// Columns
	grilla_ventas->SetColSize( 0, 201 );
	grilla_ventas->SetColSize( 1, 152 );
	grilla_ventas->SetColSize( 2, 108 );
	grilla_ventas->SetColSize( 3, 80 );
	grilla_ventas->SetColSize( 4, 80 );
	grilla_ventas->SetColSize( 5, 80 );
	grilla_ventas->EnableDragColMove( false );
	grilla_ventas->EnableDragColSize( true );
	grilla_ventas->SetColLabelSize( 30 );
	grilla_ventas->SetColLabelValue( 0, wxT("ID Factura") );
	grilla_ventas->SetColLabelValue( 1, wxT("Dia") );
	grilla_ventas->SetColLabelValue( 2, wxT("Mes") );
	grilla_ventas->SetColLabelValue( 3, wxT("Año") );
	grilla_ventas->SetColLabelValue( 4, wxT("Nombre y Apellido") );
	grilla_ventas->SetColLabelValue( 5, wxT("Nombre de Producto") );
	grilla_ventas->SetColLabelValue( 6, wxT("Precio") );
	grilla_ventas->SetColLabelValue( 7, wxT("Cantidad") );
	grilla_ventas->SetColLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Rows
	grilla_ventas->EnableDragRowSize( true );
	grilla_ventas->SetRowLabelSize( 0 );
	grilla_ventas->SetRowLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Label Appearance
	
	// Cell Defaults
	grilla_ventas->SetDefaultCellAlignment( wxALIGN_LEFT, wxALIGN_TOP );
	bSizer15->Add( grilla_ventas, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	wxBoxSizer* bSizer17;
	bSizer17 = new wxBoxSizer( wxHORIZONTAL );
	
	m_button2 = new wxButton( m_panel1, wxID_ANY, wxT("Nueva Venta"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer17->Add( m_button2, 0, wxALL|wxEXPAND|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer17->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_staticText20 = new wxStaticText( m_panel1, wxID_ANY, wxT("total: "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText20->Wrap( -1 );
	bSizer17->Add( m_staticText20, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_text_total_filtro = new wxTextCtrl( m_panel1, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_text_total_filtro->Enable( false );
	
	bSizer17->Add( m_text_total_filtro, 0, wxALL, 5 );
	
	
	bSizer15->Add( bSizer17, 0, wxEXPAND|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	
	m_panel1->SetSizer( bSizer15 );
	m_panel1->Layout();
	bSizer15->Fit( m_panel1 );
	m_notebook->AddPage( m_panel1, wxT("Ventas"), true );
	m_panel2 = new wxPanel( m_notebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer151;
	bSizer151 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer161;
	bSizer161 = new wxBoxSizer( wxHORIZONTAL );
	
	m_textCtrl121 = new wxTextCtrl( m_panel2, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer161->Add( m_textCtrl121, 1, wxALL|wxEXPAND, 5 );
	
	m_button4 = new wxButton( m_panel2, wxID_ANY, wxT("Buscar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer161->Add( m_button4, 0, wxALL, 5 );
	
	
	bSizer151->Add( bSizer161, 0, wxEXPAND, 5 );
	
	grilla_cliente = new wxGrid( m_panel2, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	
	// Grid
	grilla_cliente->CreateGrid( 0, 4 );
	grilla_cliente->EnableEditing( false );
	grilla_cliente->EnableGridLines( false );
	grilla_cliente->EnableDragGridSize( false );
	grilla_cliente->SetMargins( 0, 0 );
	
	// Columns
	grilla_cliente->SetColSize( 0, 120 );
	grilla_cliente->SetColSize( 1, 213 );
	grilla_cliente->SetColSize( 2, 241 );
	grilla_cliente->SetColSize( 3, 80 );
	grilla_cliente->EnableDragColMove( false );
	grilla_cliente->EnableDragColSize( true );
	grilla_cliente->SetColLabelSize( 30 );
	grilla_cliente->SetColLabelValue( 0, wxT("Dni") );
	grilla_cliente->SetColLabelValue( 1, wxT("Nombre y Apellido") );
	grilla_cliente->SetColLabelValue( 2, wxT("Direccion") );
	grilla_cliente->SetColLabelValue( 3, wxT("Telefono") );
	grilla_cliente->SetColLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Rows
	grilla_cliente->EnableDragRowSize( true );
	grilla_cliente->SetRowLabelSize( 0 );
	grilla_cliente->SetRowLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Label Appearance
	
	// Cell Defaults
	grilla_cliente->SetDefaultCellAlignment( wxALIGN_LEFT, wxALIGN_TOP );
	bSizer151->Add( grilla_cliente, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	wxBoxSizer* bSizer171;
	bSizer171 = new wxBoxSizer( wxHORIZONTAL );
	
	m_button5 = new wxButton( m_panel2, wxID_ANY, wxT("Agregar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer171->Add( m_button5, 0, wxALL|wxEXPAND|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer171->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_button7 = new wxButton( m_panel2, wxID_ANY, wxT("Eliminar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer171->Add( m_button7, 0, wxALL|wxEXPAND|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer151->Add( bSizer171, 0, wxEXPAND|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	
	m_panel2->SetSizer( bSizer151 );
	m_panel2->Layout();
	bSizer151->Fit( m_panel2 );
	m_notebook->AddPage( m_panel2, wxT("Clientes"), false );
	m_panel3 = new wxPanel( m_notebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer152;
	bSizer152 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer162;
	bSizer162 = new wxBoxSizer( wxHORIZONTAL );
	
	m_textCtrl122 = new wxTextCtrl( m_panel3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer162->Add( m_textCtrl122, 1, wxALL|wxEXPAND, 5 );
	
	m_button8 = new wxButton( m_panel3, wxID_ANY, wxT("Buscar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer162->Add( m_button8, 0, wxALL, 5 );
	
	
	bSizer152->Add( bSizer162, 0, wxEXPAND, 5 );
	
	grilla_productos = new wxGrid( m_panel3, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	
	// Grid
	grilla_productos->CreateGrid( 0, 3 );
	grilla_productos->EnableEditing( false );
	grilla_productos->EnableGridLines( false );
	grilla_productos->EnableDragGridSize( false );
	grilla_productos->SetMargins( 0, 0 );
	
	// Columns
	grilla_productos->SetColSize( 0, 160 );
	grilla_productos->SetColSize( 1, 333 );
	grilla_productos->SetColSize( 2, 153 );
	grilla_productos->EnableDragColMove( false );
	grilla_productos->EnableDragColSize( true );
	grilla_productos->SetColLabelSize( 30 );
	grilla_productos->SetColLabelValue( 0, wxT("Codigo") );
	grilla_productos->SetColLabelValue( 1, wxT("Nombre") );
	grilla_productos->SetColLabelValue( 2, wxT("Precio x Unidad") );
	grilla_productos->SetColLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Rows
	grilla_productos->EnableDragRowSize( true );
	grilla_productos->SetRowLabelSize( 0 );
	grilla_productos->SetRowLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Label Appearance
	
	// Cell Defaults
	grilla_productos->SetDefaultCellAlignment( wxALIGN_LEFT, wxALIGN_TOP );
	bSizer152->Add( grilla_productos, 1, wxALL|wxEXPAND, 5 );
	
	wxBoxSizer* bSizer172;
	bSizer172 = new wxBoxSizer( wxHORIZONTAL );
	
	m_button9 = new wxButton( m_panel3, wxID_ANY, wxT("Agregar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer172->Add( m_button9, 0, wxALL|wxEXPAND|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer172->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_button11 = new wxButton( m_panel3, wxID_ANY, wxT("Eliminar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer172->Add( m_button11, 0, wxALL|wxEXPAND|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer152->Add( bSizer172, 0, wxEXPAND|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	
	m_panel3->SetSizer( bSizer152 );
	m_panel3->Layout();
	bSizer152->Fit( m_panel3 );
	m_notebook->AddPage( m_panel3, wxT("Productos"), false );
	
	bSizer1->Add( m_notebook, 1, wxEXPAND | wxALL, 5 );
	
	
	this->SetSizer( bSizer1 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	this->Connect( m_libro_usuario->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( PanelPrincipal::OnClickManual ) );
	this->Connect( m_licencia->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( PanelPrincipal::OnClickLicencia ) );
	this->Connect( m_yo->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( PanelPrincipal::OnClickSobreMi ) );
	m_button1->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( PanelPrincipal::OnClickBuscarFactura ), NULL, this );
	m_button2->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( PanelPrincipal::OnClickVender ), NULL, this );
	m_textCtrl121->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( PanelPrincipal::EnterBuscarCliente ), NULL, this );
	m_button4->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( PanelPrincipal::OnClickBuscarCliente ), NULL, this );
	grilla_cliente->Connect( wxEVT_GRID_CELL_LEFT_DCLICK, wxGridEventHandler( PanelPrincipal::OnDobleClickGrillaCliente ), NULL, this );
	grilla_cliente->Connect( wxEVT_GRID_LABEL_LEFT_CLICK, wxGridEventHandler( PanelPrincipal::OnClickGrillaCliente ), NULL, this );
	m_button5->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( PanelPrincipal::OnClickAgregarCliente ), NULL, this );
	m_button7->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( PanelPrincipal::OnClickEliminarCliente ), NULL, this );
	m_textCtrl122->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( PanelPrincipal::EnterBuscarProducto ), NULL, this );
	m_button8->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( PanelPrincipal::OnClickBuscarProducto ), NULL, this );
	grilla_productos->Connect( wxEVT_GRID_CELL_LEFT_DCLICK, wxGridEventHandler( PanelPrincipal::OnClickDobleClickGrillaProducto ), NULL, this );
	grilla_productos->Connect( wxEVT_GRID_LABEL_LEFT_CLICK, wxGridEventHandler( PanelPrincipal::OnClickGrillaProducto ), NULL, this );
	m_button9->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( PanelPrincipal::OnClickAgregarProducto ), NULL, this );
	m_button11->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( PanelPrincipal::OnClickEliminarProducto ), NULL, this );
}

PanelPrincipal::~PanelPrincipal()
{
	// Disconnect Events
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( PanelPrincipal::OnClickManual ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( PanelPrincipal::OnClickLicencia ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( PanelPrincipal::OnClickSobreMi ) );
	m_button1->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( PanelPrincipal::OnClickBuscarFactura ), NULL, this );
	m_button2->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( PanelPrincipal::OnClickVender ), NULL, this );
	m_textCtrl121->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( PanelPrincipal::EnterBuscarCliente ), NULL, this );
	m_button4->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( PanelPrincipal::OnClickBuscarCliente ), NULL, this );
	grilla_cliente->Disconnect( wxEVT_GRID_CELL_LEFT_DCLICK, wxGridEventHandler( PanelPrincipal::OnDobleClickGrillaCliente ), NULL, this );
	grilla_cliente->Disconnect( wxEVT_GRID_LABEL_LEFT_CLICK, wxGridEventHandler( PanelPrincipal::OnClickGrillaCliente ), NULL, this );
	m_button5->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( PanelPrincipal::OnClickAgregarCliente ), NULL, this );
	m_button7->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( PanelPrincipal::OnClickEliminarCliente ), NULL, this );
	m_textCtrl122->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( PanelPrincipal::EnterBuscarProducto ), NULL, this );
	m_button8->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( PanelPrincipal::OnClickBuscarProducto ), NULL, this );
	grilla_productos->Disconnect( wxEVT_GRID_CELL_LEFT_DCLICK, wxGridEventHandler( PanelPrincipal::OnClickDobleClickGrillaProducto ), NULL, this );
	grilla_productos->Disconnect( wxEVT_GRID_LABEL_LEFT_CLICK, wxGridEventHandler( PanelPrincipal::OnClickGrillaProducto ), NULL, this );
	m_button9->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( PanelPrincipal::OnClickAgregarProducto ), NULL, this );
	m_button11->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( PanelPrincipal::OnClickEliminarProducto ), NULL, this );
	
}

VCliente::VCliente( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer5;
	bSizer5 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText2 = new wxStaticText( this, wxID_ANY, wxT("DNI"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2->Wrap( -1 );
	bSizer5->Add( m_staticText2, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_text_dni = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer5->Add( m_text_dni, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer4->Add( bSizer5, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer6;
	bSizer6 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText3 = new wxStaticText( this, wxID_ANY, wxT("Nombre"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText3->Wrap( -1 );
	bSizer6->Add( m_staticText3, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_text_nombre = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer6->Add( m_text_nombre, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer4->Add( bSizer6, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer61;
	bSizer61 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText31 = new wxStaticText( this, wxID_ANY, wxT("Apellido"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText31->Wrap( -1 );
	bSizer61->Add( m_staticText31, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_text_apellido = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer61->Add( m_text_apellido, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer4->Add( bSizer61, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer611;
	bSizer611 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText311 = new wxStaticText( this, wxID_ANY, wxT("Direccion"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText311->Wrap( -1 );
	bSizer611->Add( m_staticText311, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_text_direccion = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer611->Add( m_text_direccion, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer4->Add( bSizer611, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer6111;
	bSizer6111 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText3111 = new wxStaticText( this, wxID_ANY, wxT("Telefono"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText3111->Wrap( -1 );
	bSizer6111->Add( m_staticText3111, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_text_telefono = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer6111->Add( m_text_telefono, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer4->Add( bSizer6111, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer16;
	bSizer16 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText14 = new wxStaticText( this, wxID_ANY, wxT("Nacimiento"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText14->Wrap( -1 );
	bSizer16->Add( m_staticText14, 0, wxALL|wxEXPAND|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_text_dia = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer16->Add( m_text_dia, 0, wxALL, 5 );
	
	m_text_mes = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer16->Add( m_text_mes, 0, wxALL, 5 );
	
	m_text_anio = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer16->Add( m_text_anio, 0, wxALL, 5 );
	
	
	bSizer4->Add( bSizer16, 1, wxEXPAND|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	wxBoxSizer* bSizer17;
	bSizer17 = new wxBoxSizer( wxHORIZONTAL );
	
	m_button6 = new wxButton( this, wxID_ANY, wxT("m_button6"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer17->Add( m_button6, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_button7 = new wxButton( this, wxID_ANY, wxT("m_button7"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer17->Add( m_button7, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer4->Add( bSizer17, 1, wxALIGN_CENTER_HORIZONTAL, 5 );
	
	
	this->SetSizer( bSizer4 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	m_button6->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VCliente::ClickCancelar ), NULL, this );
	m_button7->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VCliente::ClickGuardar ), NULL, this );
}

VCliente::~VCliente()
{
	// Disconnect Events
	m_button6->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VCliente::ClickCancelar ), NULL, this );
	m_button7->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VCliente::ClickGuardar ), NULL, this );
	
}

VProducto::VProducto( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer15;
	bSizer15 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer16;
	bSizer16 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText9 = new wxStaticText( this, wxID_ANY, wxT("Codigo"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText9->Wrap( -1 );
	bSizer16->Add( m_staticText9, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_text_codigo = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer16->Add( m_text_codigo, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer15->Add( bSizer16, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer161;
	bSizer161 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText91 = new wxStaticText( this, wxID_ANY, wxT("Nombre"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText91->Wrap( -1 );
	bSizer161->Add( m_staticText91, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_text_nombre = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer161->Add( m_text_nombre, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer15->Add( bSizer161, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer162;
	bSizer162 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText92 = new wxStaticText( this, wxID_ANY, wxT("Precio"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText92->Wrap( -1 );
	bSizer162->Add( m_staticText92, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_text_precio = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer162->Add( m_text_precio, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer15->Add( bSizer162, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer17;
	bSizer17 = new wxBoxSizer( wxHORIZONTAL );
	
	m_button8 = new wxButton( this, wxID_ANY, wxT("m_button8"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer17->Add( m_button8, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_button9 = new wxButton( this, wxID_ANY, wxT("m_button9"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer17->Add( m_button9, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer15->Add( bSizer17, 0, wxALIGN_CENTER_HORIZONTAL, 5 );
	
	
	this->SetSizer( bSizer15 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	m_button8->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VProducto::ClickCancelar ), NULL, this );
	m_button9->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VProducto::ClickGuardar ), NULL, this );
}

VProducto::~VProducto()
{
	// Disconnect Events
	m_button8->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VProducto::ClickCancelar ), NULL, this );
	m_button9->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VProducto::ClickGuardar ), NULL, this );
	
}

VFactura::VFactura( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer26;
	bSizer26 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer31;
	bSizer31 = new wxBoxSizer( wxHORIZONTAL );
	
	m_id = new wxStaticText( this, wxID_ANY, wxT("MyLabel"), wxDefaultPosition, wxDefaultSize, 0 );
	m_id->Wrap( -1 );
	bSizer31->Add( m_id, 1, wxALL|wxALIGN_CENTER_VERTICAL|wxEXPAND, 5 );
	
	
	bSizer26->Add( bSizer31, 0, wxALIGN_CENTER_HORIZONTAL|wxEXPAND, 5 );
	
	wxBoxSizer* bSizer27;
	bSizer27 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText10 = new wxStaticText( this, wxID_ANY, wxT("ID Cliente:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText10->Wrap( -1 );
	bSizer27->Add( m_staticText10, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_text_Cargar_cliente = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer27->Add( m_text_Cargar_cliente, 1, wxALL, 5 );
	
	m_button15 = new wxButton( this, wxID_ANY, wxT("Aceptar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer27->Add( m_button15, 0, wxALL, 5 );
	
	
	bSizer26->Add( bSizer27, 0, wxEXPAND, 5 );
	
	m_lista_cliente = new wxListBox( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 ); 
	bSizer26->Add( m_lista_cliente, 0, wxALL|wxEXPAND, 5 );
	
	m_staticline1 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer26->Add( m_staticline1, 0, wxEXPAND | wxALL, 5 );
	
	wxBoxSizer* bSizer28;
	bSizer28 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText11 = new wxStaticText( this, wxID_ANY, wxT("ID Producto"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText11->Wrap( -1 );
	bSizer28->Add( m_staticText11, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_text_Cargar_producto = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer28->Add( m_text_Cargar_producto, 1, wxALL, 5 );
	
	m_staticText12 = new wxStaticText( this, wxID_ANY, wxT("Cantidad"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText12->Wrap( -1 );
	bSizer28->Add( m_staticText12, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_text_Cargar_cantidad = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer28->Add( m_text_Cargar_cantidad, 1, wxALL, 5 );
	
	m_button16 = new wxButton( this, wxID_ANY, wxT("Cargar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer28->Add( m_button16, 0, wxALL, 5 );
	
	
	bSizer26->Add( bSizer28, 0, wxEXPAND, 5 );
	
	m_lista_productos = new wxListBox( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 ); 
	m_lista_productos->SetMinSize( wxSize( -1,200 ) );
	
	bSizer26->Add( m_lista_productos, 1, wxALL|wxEXPAND, 5 );
	
	wxBoxSizer* bSizer30;
	bSizer30 = new wxBoxSizer( wxHORIZONTAL );
	
	m_total = new wxStaticText( this, wxID_ANY, wxT("Total: "), wxDefaultPosition, wxDefaultSize, 0 );
	m_total->Wrap( -1 );
	bSizer30->Add( m_total, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer26->Add( bSizer30, 0, 0, 5 );
	
	m_staticline11 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer26->Add( m_staticline11, 0, wxEXPAND | wxALL, 5 );
	
	wxBoxSizer* bSizer29;
	bSizer29 = new wxBoxSizer( wxHORIZONTAL );
	
	m_button17 = new wxButton( this, wxID_ANY, wxT("MyButton"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer29->Add( m_button17, 0, wxALL, 5 );
	
	
	bSizer29->Add( 0, 0, 1, wxALIGN_CENTER_VERTICAL|wxEXPAND, 5 );
	
	m_button18 = new wxButton( this, wxID_ANY, wxT("MyButton"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer29->Add( m_button18, 0, wxALL, 5 );
	
	
	bSizer26->Add( bSizer29, 0, wxEXPAND, 5 );
	
	
	this->SetSizer( bSizer26 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	m_button15->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VFactura::OnClickCargarCliente ), NULL, this );
	m_button16->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VFactura::OnClickCargarCarrito ), NULL, this );
	m_button17->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VFactura::OnClickCancelarVenta ), NULL, this );
	m_button18->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VFactura::OnClickVender ), NULL, this );
}

VFactura::~VFactura()
{
	// Disconnect Events
	m_button15->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VFactura::OnClickCargarCliente ), NULL, this );
	m_button16->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VFactura::OnClickCargarCarrito ), NULL, this );
	m_button17->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VFactura::OnClickCancelarVenta ), NULL, this );
	m_button18->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( VFactura::OnClickVender ), NULL, this );
	
}
