#ifndef VAGREGARCLIENTE_H
#define VAGREGARCLIENTE_H
#include "wxfbWindows.h"
#include "ArchivoCliente.h"

class VAgregarCliente : public VCliente {
protected:
	void ClickCancelar( wxCommandEvent& event ) ;
	void ClickGuardar( wxCommandEvent& event) ;

public:
	VAgregarCliente(wxWindow *parent, ArchivoCliente &archi);
	~VAgregarCliente();
private:
	ArchivoCliente &archi_cliente;
};

#endif

