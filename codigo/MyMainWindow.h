#ifndef MYMAINWINDOW_H
#define MYMAINWINDOW_H
#include "wxfbWindows.h"
#include "ArchivoCliente.h"
#include "Application.h"
using namespace std;
class MyMainWindow:public FBMainWindow {
protected:
	void ClickBuscar( wxCommandEvent& event ) ;
	void ClickGrilla( wxGridEvent& event ) ;
	void ClickAgregar( wxCommandEvent& event ) ;
	void ClickVer( wxCommandEvent& event ) ;
	void ClickEliminar( wxCommandEvent& event ) ;
	void OnAbout( wxCommandEvent& event ) ;
public:
	MyMainWindow(ArchivoCliente &archi);
	void OnButtonClose(wxCommandEvent &evt);
	void CargarFila(int i);
private:
	ArchivoCliente &archi_cliente;
};

#endif
