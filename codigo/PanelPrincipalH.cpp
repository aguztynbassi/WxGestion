#include "PanelPrincipalH.h"
#include "ArchivoCliente.h"
#include "ArchivoProducto.h"
#include "ArchivoFactura.h"
#include "Cliente.h"
#include "Utils.h"
#include "Producto.h"
#include <wx/string.h>
#include <wx/msgdlg.h>
#include "VEditarProducto.h"
#include "VAgregarCliente.h"
#include "VEditarCliente.h"
#include "VAgregarProducto.h"
#include "Factura.h"
#include "wxfbWindows.h"
#include <iomanip>
#include <sstream>
#include "VAgregarFactura.h"
#include <windows.h>
#include "Fecha.h"

using namespace std;

void PanelPrincipalH::OnAbout( wxCommandEvent& event )  {event.Skip();}

PanelPrincipalH::~PanelPrincipalH() {
	archi_cliente.Guardar();
	archi_producto.Guardar();
	archi_factura.Guardar();
}

///---------------------Filtrado Factura-----------------------
void PanelPrincipalH::EnterBuscarFactura( wxCommandEvent& event )  {OnClickBuscarFactura(event);}

void PanelPrincipalH::OnClickBuscarFactura( wxCommandEvent& event )  {
	grilla_ventas->ClearGrid();
	grilla_ventas->DeleteRows(0,archi_factura.Cantidad());
	m_text_total_filtro->Clear();
	long dia1, dia2, mes1, mes2, anio1, anio2;
	m_f1dia->GetValue().ToLong(&dia1);
	m_f2dia->GetValue().ToLong(&dia2);
	m_f1mes->GetValue().ToLong(&mes1);
	m_f2mes->GetValue().ToLong(&mes2);
	m_f1anio->GetValue().ToLong(&anio1);
	m_f2anio->GetValue().ToLong(&anio2);
	Fecha f1(dia1,mes1,anio1);
	Fecha f2(dia2,mes2,anio2);
	//nada puede estar vacio
	if ((m_f1dia->IsEmpty() and m_f2dia->IsEmpty())
		and (m_f1mes->IsEmpty() and m_f2mes->IsEmpty())
		and (m_f1anio->IsEmpty() and m_f2anio->IsEmpty()) and m_id_buscar->IsEmpty()){
		wxMessageBox((c_to_wx("Los campos estan vacios o las Fechas son incorrectas.")));
		return;
	//busca Factura
	}else if (((m_f1dia->IsEmpty() and m_f2dia->IsEmpty())
			and (m_f1mes->IsEmpty() and m_f2mes->IsEmpty())
			and (m_f1anio->IsEmpty() and m_f2anio->IsEmpty())) 
			and (m_radioBtnFactura->GetValue() == true)){
				CargarFiltrado(m_id_buscar->GetValue());
//	busca Cliente
	}else if (m_radioBtnCliente->GetValue() == true){
				CargarFiltrado(m_id_buscar->GetValue());
//	busca Producto
	}else if(m_radioBtnProducto->GetValue() == true){
				CargarFiltrado(m_id_buscar->GetValue());
//	buscar por Fecha
	}else if (m_id_buscar->IsEmpty()){
				CargarFiltrado(f1,f2);
//	buscar por Fecha y factura
	}else if(!((m_f1dia->IsEmpty() and m_f2dia->IsEmpty())
			and (m_f1mes->IsEmpty() and m_f2mes->IsEmpty())
			and (m_f1anio->IsEmpty() and m_f2anio->IsEmpty())) 
			 and (!m_id_buscar->IsEmpty()) and (m_radioBtnFactura->GetValue() == true)){
				CargarFiltrado(m_id_buscar->GetValue(),f1,f2);
//	buscar por Fecha y Cliente
	}else if(m_radioBtnCliente->GetValue() == true){
				CargarFiltrado(m_id_buscar->GetValue(),f1,f2);
//	buscar por Fecha y Producto
	}else if(m_radioBtnProducto->GetValue() == true){
				 CargarFiltrado(m_id_buscar->GetValue(),f1,f2);
	}
	m_id_buscar->Clear();
}

void PanelPrincipalH::OnClickVender( wxCommandEvent& event )  {
	VAgregarFactura nuevo(this,archi_factura, archi_cliente, archi_producto);
	if(nuevo.ShowModal()==1){
		wxMessageBox("Se realizo la venta","Vendido",wxOK,this);
		return;
	}
}

/// --------------------Panel Cliente--------------------------
void PanelPrincipalH::EnterBuscarCliente( wxCommandEvent& event )  {OnClickBuscarCliente(event);}
void PanelPrincipalH::OnClickBuscarCliente( wxCommandEvent& event )  {
	
	if(m_textCtrl121->IsEmpty()){
		wxMessageBox(c_to_wx("Debe ingresar DNI o nombre de Cliente."));
		grilla_cliente->ClearGrid();
		grilla_cliente->DeleteRows(0, archi_cliente.VerClienteFiltrado());
		for(int i=0;i<archi_cliente.Cantidad();i++) { CargarFilaCliente(i); }
	}else{
		grilla_cliente->ClearGrid();
		grilla_cliente->DeleteRows(0, archi_cliente.VerClienteFiltrado());
		CargarFiltrado_Cliente(m_textCtrl121->GetValue());
	}
	
}

void PanelPrincipalH::OnClickAgregarCliente( wxCommandEvent& event )  {
	VAgregarCliente nuevo(this,archi_cliente);
	grilla_cliente->ClearGrid();
	if(nuevo.ShowModal()==1){
		grilla_cliente->AppendRows(1);
		int pos=archi_cliente.Cantidad()-1;
		CargarFilaCliente(pos);
		grilla_cliente->SetGridCursor(pos,0);
		grilla_cliente->SelectRow(pos);
	}
	for(int i=0;i<archi_cliente.Cantidad();i++) { 
		CargarFilaCliente(i);
	}
}

void PanelPrincipalH::OnClickVerCliente( wxCommandEvent& event )  {
	int fila_actual = grilla_cliente->GetGridCursorRow();
	VEditarCliente nueva(this,fila_actual,archi_cliente);
	if(nueva.ShowModal())
		CargarFilaCliente(fila_actual);
}

void PanelPrincipalH::OnClickEliminarCliente( wxCommandEvent& event )  {
	int fila_actual = grilla_cliente->GetGridCursorRow();
	int res = wxMessageBox(c_to_wx("¿Eliminar el registro?"), grilla_cliente->GetCellValue(fila_actual,0),wxYES_NO);
	if (res==wxYES) {
		grilla_cliente->DeleteRows(fila_actual,1);
		archi_cliente.EliminarCliente(fila_actual);
		archi_cliente.Guardar();
	}
}

///---------------------Panel Producto-------------------------
void PanelPrincipalH::EnterBuscarProducto( wxCommandEvent& event )  {OnClickBuscarProducto(event);}

void PanelPrincipalH::OnClickBuscarProducto( wxCommandEvent& event )  {
	if(m_textCtrl122->IsEmpty()){
		wxMessageBox(c_to_wx("Debe ingresar un codigo o nombre de Producto."));
		grilla_productos->ClearGrid();
		grilla_productos->DeleteRows(0, archi_producto.VerProductoFiltrado());
		for(int i=0;i<archi_producto.Cantidad();i++) { CargarFilaProducto(i); }
	}else{
		grilla_productos->ClearGrid();
		grilla_productos->DeleteRows(0, archi_producto.VerProductoFiltrado());
		CargarFiltrado_Producto(m_textCtrl122->GetValue());
	}
}

void PanelPrincipalH::OnClickAgregarProducto( wxCommandEvent& event )  {
	VAgregarProducto nuevo(this,archi_producto);
	if(nuevo.ShowModal()==1){
		grilla_productos->AppendRows(1);
		int pos=(archi_producto.Cantidad()-1);
		CargarFilaProducto(pos);
		grilla_productos->SetGridCursor(pos,0);
		grilla_productos->SelectRow(pos);
	}
}

void PanelPrincipalH::OnClickVerProducto( wxCommandEvent& event )  {
	int fila_actual = grilla_productos->GetGridCursorRow();
	VEditarProducto nueva(this,fila_actual,archi_producto);
	if(nueva.ShowModal())
		CargarFilaProducto(fila_actual);
}

void PanelPrincipalH::OnClickEliminarProducto( wxCommandEvent& event )  {
	int fila_actual = grilla_productos->GetGridCursorRow();
	int res = wxMessageBox(c_to_wx("¿Eliminar el registro?"), grilla_productos->GetCellValue(fila_actual,0),wxYES_NO);
	if (res==wxYES) {
		grilla_productos->DeleteRows(fila_actual,1);
		archi_producto.EliminarProducto(fila_actual);
		archi_producto.Guardar();
	}
}

///---------------------Panel Principal------------------------
PanelPrincipalH::PanelPrincipalH (ArchivoCliente & archi1, ArchivoProducto & archi2, ArchivoFactura & archi3):PanelPrincipal(nullptr), archi_cliente(archi1), archi_producto(archi2), archi_factura(archi3) {	
	int c_cli = archi_cliente.Cantidad();
	grilla_cliente->AppendRows(c_cli);
	for(int i=0;i<c_cli;i++)CargarFilaCliente(i);
	grilla_cliente->SetSelectionMode(wxGrid::wxGridSelectRows);
	
	int c_pro = archi_producto.Cantidad();
	grilla_productos->AppendRows(c_pro);
	for(int i=0;i<c_pro;i++) CargarFilaProducto(i);
	grilla_productos->SetSelectionMode(wxGrid::wxGridSelectRows);
}

void PanelPrincipalH::OnButtonClose (wxCommandEvent & evt) {
	archi_cliente.Guardar();
	archi_producto.Guardar();
	archi_factura.Guardar();
	Close();
}

void PanelPrincipalH::CargarFilaCliente (int i) {
	Cliente c=(archi_cliente)[i];
	if(c.VerExistencia()==true){
		grilla_cliente->SetCellValue( i, 0, (wxString()<<c.VerDni()) );
		grilla_cliente->SetCellValue( i, 1, std_to_wx(c.VerNombre()+", "+c.VerApellido()) );
		grilla_cliente->SetCellValue( i, 2, std_to_wx(c.VerDireccion()) );
		grilla_cliente->SetCellValue( i, 3, std_to_wx(c.VerTelefono())  );
	}
}

void PanelPrincipalH::CargarFilaProducto (int i) {
	Producto p=(archi_producto)[i];
	if(p.VerExistencia()==true){
		grilla_productos->SetCellValue( i, 0, (wxString()<<p.VerCodigo()) );
		grilla_productos->SetCellValue( i, 1, std_to_wx(p.VerNombre()) );
		grilla_productos->SetCellValue( i, 2, (wxString()<<p.VerPrecio()) );
	}
}

void PanelPrincipalH::OnDobleClickGrillaCliente( wxGridEvent& event )  {
	int fila_actual=grilla_cliente->GetGridCursorRow();
	VEditarCliente nueva(this,fila_actual,archi_cliente);
	if(nueva.ShowModal())
		CargarFilaCliente(fila_actual);
}

void PanelPrincipalH::OnClickGrillaCliente( wxGridEvent& event )  {
	int columna=event.GetCol(), c=archi_cliente.Cantidad();
	switch(columna){
	case 0: archi_cliente.Ordenar(ORDEN_DNI); break;
	case 1: archi_cliente.Ordenar(ORDEN_APELLIDO_Y_NOMBRE); break;
	case 2: archi_cliente.Ordenar(ORDEN_DIRECCION); break;
	case 3: archi_cliente.Ordenar(ORDEN_TELEFONO); break;
	}
	for(int j=0;j<c;j++) { CargarFilaCliente(j); }
}

void PanelPrincipalH::OnClickDobleClickGrillaProducto( wxGridEvent& event )  {
	int fila_actual=grilla_productos->GetGridCursorRow();
	VEditarProducto nueva(this,fila_actual,archi_producto);
	if(nueva.ShowModal())
		CargarFilaProducto(fila_actual);
}

void PanelPrincipalH::OnClickGrillaProducto( wxGridEvent& event )  {
	int columna=event.GetCol(), c=archi_producto.Cantidad();
	switch(columna){
	case 0: archi_producto.Ordenar(ORDEN_CODIGO); break;
	case 1: archi_producto.Ordenar(ORDEN_NOMBRE); break;
	}
	for(int j=0;j<c;j++) { CargarFilaProducto(j); }
}

void PanelPrincipalH::OnClickSobreMi( wxCommandEvent& event )  {ShellExecute(nullptr,"open","acerca_de.html","acerca_de.html",nullptr,SW_NORMAL);}

void PanelPrincipalH::OnClickLicencia( wxCommandEvent& event )  {ShellExecute(nullptr,"open","GNU.html","GNU.html",nullptr,SW_NORMAL);}

void PanelPrincipalH::OnClickManual( wxCommandEvent& event )  {ShellExecute(nullptr,"open","manual.pdf","manual.pdf",nullptr,SW_NORMAL);}

void PanelPrincipalH::CargarFiltrado (wxString filtrado) {
	int contador= 0, indice= 0, total= 0;
	if (m_radioBtnFactura->GetValue() == true){
		indice= archi_factura.BuscarCodigoFactura(wx_to_std(filtrado),indice);
		total= archi_factura.FiltrarCantidadFactura(wx_to_std(filtrado));
		grilla_ventas->AppendRows(total);
	}if (m_radioBtnCliente->GetValue()== true){
		indice= archi_factura.BuscarCodigoCliente(wx_to_std(filtrado),indice);
		total= archi_factura.FiltrarCantidadCliente(wx_to_std(filtrado));
		grilla_ventas->AppendRows(total);
	}if (m_radioBtnProducto->GetValue()== true){
		indice= archi_factura.BuscarCodigoProducto(wx_to_std(filtrado),indice);
		total= archi_factura.FiltrarCantidadProducto(wx_to_std(filtrado));
		grilla_ventas->AppendRows(total);
	}
	while (indice >=0 and contador<total){
		nodo_venta aux= archi_factura.Ver(indice);
//		int pos= archi_producto.BuscarCodigo(aux.NOMBRE_P,0);
		total_factura = total_factura + (aux.PRECIO*aux.CANTIDAD);
		grilla_ventas->SetCellValue( contador, 0, std_to_wx(aux.ID));
		grilla_ventas->SetCellValue( contador, 1, wxString()<<(aux.DIA));
		grilla_ventas->SetCellValue( contador, 2, wxString()<<(aux.MES));
		grilla_ventas->SetCellValue( contador, 3, wxString()<<(aux.ANIO));
		grilla_ventas->SetCellValue( contador, 4, wxString()<<(aux.NOMBRE)<<", "<<(aux.APELLIDO));
		grilla_ventas->SetCellValue( contador, 5, wxString()<<(aux.NOMBRE_P));
		grilla_ventas->SetCellValue( contador, 6, wxString()<<(aux.PRECIO));
		grilla_ventas->SetCellValue( contador, 7, wxString()<<(aux.CANTIDAD));
		m_text_total_filtro->SetLabel(wxString()<<total_factura);
		indice++;
		contador++;
		if (m_radioBtnFactura->GetValue() == true)
			indice= archi_factura.BuscarCodigoFactura(wx_to_std(filtrado),indice);
		if(m_radioBtnCliente->GetValue() == true)
			indice= archi_factura.BuscarCodigoCliente(wx_to_std(filtrado),indice);
		if (m_radioBtnProducto->GetValue() == true)
			indice= archi_factura.BuscarCodigoProducto(wx_to_std(filtrado),indice);
		
	}
	total_factura = 0;
}

void PanelPrincipalH::CargarFiltrado (Fecha f1, Fecha f2) {
	int contador= 0, indice= 0, total= 0;
	total = archi_factura.FiltrarCantidadFecha(f1, f2);
	indice= archi_factura.BuscarFecha(f1,f2, indice);
	grilla_ventas->AppendRows(total);
	while (indice>=0 and contador<total){
		nodo_venta aux= archi_factura.Ver(indice);
		total_factura = total_factura + (aux.PRECIO*aux.CANTIDAD);
		grilla_ventas->SetCellValue( contador, 0, std_to_wx(aux.ID));
		grilla_ventas->SetCellValue( contador, 1, wxString()<<(aux.DIA));
		grilla_ventas->SetCellValue( contador, 2, wxString()<<(aux.MES));
		grilla_ventas->SetCellValue( contador, 3, wxString()<<(aux.ANIO));
		grilla_ventas->SetCellValue( contador, 4, wxString()<<(aux.NOMBRE)<<", "<<(aux.APELLIDO));
		grilla_ventas->SetCellValue( contador, 5, wxString()<<(aux.NOMBRE_P));
		grilla_ventas->SetCellValue( contador, 6, wxString()<<(aux.PRECIO));
		grilla_ventas->SetCellValue( contador, 7, wxString()<<(aux.CANTIDAD));
		m_text_total_filtro->SetLabel(wxString()<<total_factura);
		contador++;
		indice++;
		indice= archi_factura.BuscarFecha(f1,f2,indice);
	}
	total_factura = 0;
}

void PanelPrincipalH::CargarFiltrado (wxString filtrado, Fecha f1, Fecha f2 ) {
	int contador= 0, indice= 0, total= 0;
	if (m_radioBtnFactura->GetValue() == true){
		total= archi_factura.FiltrarCantidadFacturaConFecha(wx_to_std(filtrado), f1, f2);
		grilla_ventas->AppendRows(total);
		indice= archi_factura.BuscarCodigoFactura(wx_to_std(filtrado),indice);
	}else if (m_radioBtnCliente->GetValue()== true){
		total= archi_factura.FiltrarCantidadClienteConFecha(wx_to_std(filtrado), f1, f2);
		grilla_ventas->AppendRows(total);
		indice= archi_factura.BuscarCodigoCliente(wx_to_std(filtrado),indice);
	}else if (m_radioBtnProducto->GetValue()== true){
		total= archi_factura.FiltrarCantidadProductoConFecha(wx_to_std(filtrado), f1, f2);
		grilla_ventas->AppendRows(total);
		indice= archi_factura.BuscarCodigoProducto(wx_to_std(filtrado),indice);
	}
	while (indice >=0 and contador<total){
		nodo_venta aux= archi_factura.Ver(indice);
		total_factura = total_factura + (aux.PRECIO*aux.CANTIDAD);
		grilla_ventas->SetCellValue( contador, 0, std_to_wx(aux.ID));
		grilla_ventas->SetCellValue( contador, 1, wxString()<<(aux.DIA));
		grilla_ventas->SetCellValue( contador, 2, wxString()<<(aux.MES));
		grilla_ventas->SetCellValue( contador, 3, wxString()<<(aux.ANIO));
		grilla_ventas->SetCellValue( contador, 4, wxString()<<(aux.NOMBRE)<<", "<<(aux.APELLIDO));
		grilla_ventas->SetCellValue( contador, 5, wxString()<<(aux.NOMBRE_P));
		grilla_ventas->SetCellValue( contador, 6, wxString()<<(aux.PRECIO));
		grilla_ventas->SetCellValue( contador, 7, wxString()<<(aux.CANTIDAD));
		m_text_total_filtro->SetLabel(wxString()<<total_factura);
		contador++;
		indice++;
		if (m_radioBtnFactura->GetValue() == true)
			indice= archi_factura.BuscarCodigoFactura(wx_to_std(filtrado),indice);
		if(m_radioBtnCliente->GetValue() == true)
			indice= archi_factura.BuscarCodigoCliente(wx_to_std(filtrado),indice);
		if (m_radioBtnProducto->GetValue() == true)
			indice= archi_factura.BuscarCodigoProducto(wx_to_std(filtrado),indice);
	}
	total_factura = 0;
}	

void PanelPrincipalH::CargarFiltrado_Cliente (wxString filtradoC) {
	int total =0, indice = 0, cont = 0;
	if (wx_to_std(filtradoC)>='0' && wx_to_std(filtradoC) <='9'){
		total = archi_cliente.Filtrar_cant_DniCliente(wx_to_std(filtradoC));
		grilla_cliente->AppendRows(total);
		indice = archi_cliente.BuscarDNI(wx_to_std(filtradoC), indice);
	}else if(wx_to_std(filtradoC)>= 'a'){
		total = archi_cliente.Filtrar_cant_NomCliente(wx_to_std(filtradoC));
		grilla_cliente->AppendRows(total);
		indice = archi_cliente.BuscarApellidoYNombre(wx_to_std(filtradoC), indice);
	}
	while (indice >= 0 and cont < total){
		Cliente C = archi_cliente.Ver(indice);
		grilla_cliente->SetCellValue(cont, 0, wxString()<<(C.VerDni()));
		grilla_cliente->SetCellValue(cont, 1, std_to_wx(C.VerNombre()+", "+C.VerApellido()));
		grilla_cliente->SetCellValue(cont, 2, std_to_wx(C.VerDireccion()));
		grilla_cliente->SetCellValue(cont, 3, std_to_wx(C.VerTelefono()));
		cont++;
		indice++;
		if (wx_to_std(filtradoC)>='0' && wx_to_std(filtradoC) <='9')
			indice = archi_cliente.BuscarDNI(wx_to_std(filtradoC), indice);
		else
			indice = archi_cliente.BuscarApellidoYNombre(wx_to_std(filtradoC), indice);
	}
}

void PanelPrincipalH::CargarFiltrado_Producto (wxString filtradoP) {
	int cont= 0, indice= 0, total= 0;
	if (wx_to_std(filtradoP)>='0' && wx_to_std(filtradoP)<= '9'){
		total = archi_producto.Filtrar_cant_CodProducto(wx_to_std(filtradoP));
		grilla_productos->AppendRows(total);
		indice = archi_producto.BuscarCodigo(wx_to_std(filtradoP), indice);
	}else{
		total = archi_producto.Filtrar_cant_NomProducto(wx_to_std(filtradoP));
		grilla_productos->AppendRows(total);
		indice = archi_producto.BuscarNombre(wx_to_std(filtradoP), indice);
	}
	while( indice>=0 and cont<total){
		Producto P= archi_producto.Ver(indice);
		grilla_productos->SetCellValue(cont, 0, wxString()<<(P.VerCodigo()));
		grilla_productos->SetCellValue(cont, 1, std_to_wx(P.VerNombre()));
		grilla_productos->SetCellValue(cont, 2, wxString()<<(P.VerPrecio()));
		cont++; indice++;
		if (wx_to_std(filtradoP)>='0' && wx_to_std(filtradoP)<= '9')
			indice = archi_producto.BuscarCodigo(wx_to_std(filtradoP), indice);
		else
			indice = archi_producto.BuscarNombre(wx_to_std(filtradoP), indice);
	}
}

