#include "MyMainWindow.h"
#include "VSobreMi.h"
#include "VAgregarCliente.h"
#include "ArchivoCliente.h"
#include "Application.h"
#include "Cliente.h"
#include <wx/msgdlg.h>
#include "Utils.h"
using namespace std;

void MyMainWindow::OnButtonClose( wxCommandEvent& event ) { 
	Close();
}

void MyMainWindow::OnAbout( wxCommandEvent& event )  {
	VSobreMi(this).ShowModal();
}

void MyMainWindow::ClickAgregar( wxCommandEvent& event )  {
	VAgregarCliente nuevo(this,archi_cliente);
	if(nuevo.ShowModal()==1){
		m_grid->AppendRows(1);
		int pos=archi_cliente.Cantidad()-1;
		CargarFila(pos);
		m_grid->SetGridCursor(pos,0);
		m_grid->SelectRow(pos);
	}
}

void MyMainWindow::ClickVer( wxCommandEvent& event )  {
	event.Skip();
}

void MyMainWindow::ClickEliminar( wxCommandEvent& event )  {
	int fila_actual = m_grid->GetGridCursorRow();
	int res = wxMessageBox(c_to_wx("¿Eliminar el registro?"), m_grid->GetCellValue(fila_actual,0),wxYES_NO);
	if (res==wxYES) {
		m_grid->DeleteRows(fila_actual,1);
		archi_cliente.Eliminar(fila_actual);
		archi_cliente.Guardar();
	}
}

void MyMainWindow::ClickBuscar( wxCommandEvent& event ){
	int fila_actual = m_grid->GetGridCursorRow();
	int res = archi_cliente.BuscarApellidoYNombre(wx_to_std(m_text_buscar->GetValue()),fila_actual);
	if (res==NO_SE_ENCUENTRA) {
		wxMessageBox(c_to_wx("No se encontraron más coincidencias"));
	} else {
		m_grid->SetGridCursor(res,0); // seleccionar celda
		m_grid->SelectRow(res); // marcar toda la fila
		m_grid->MakeCellVisible(res,0); // asegurarse de que se ve
	}
}

void MyMainWindow::ClickGrilla( wxGridEvent& event )  {
	int columna = event.GetCol(), c = archi_cliente.Cantidad();
	switch(columna) {
	case 0: archi_cliente.Ordenar(ORDEN_DNI); break;
	case 1: archi_cliente.Ordenar(ORDEN_APELLIDO_Y_NOMBRE); break;
	case 2: archi_cliente.Ordenar(ORDEN_TELEFONO); break;
	case 3: archi_cliente.Ordenar(ORDEN_DIRECCION); break;
	}
	for (int i=0;i<c;i++) CargarFila(i);
}

MyMainWindow::MyMainWindow (ArchivoCliente &archi):FBMainWindow(NULL),archi_cliente(archi) {
	int c_cli = archi_cliente.Cantidad();
	m_grid->AppendRows(c_cli);
	for(int i=0;i<c_cli;i++) CargarFila(i);
	m_grid->SetSelectionMode(wxGrid::wxGridSelectRows);
	
}

void MyMainWindow::CargarFila (int i) {
	Cliente &c=(archi_cliente)[i];
	m_grid->SetCellValue( i, 0, std_to_wx(c.VerNombre()+", "+c.VerApellido()) );
	m_grid->SetCellValue( i, 1, std_to_wx(c.VerDireccion()) );
	m_grid->SetCellValue( i, 2, std_to_wx(c.VerTelefono()) );
}

