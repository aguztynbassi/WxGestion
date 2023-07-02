#ifndef VEDITARCLIENTE_H
#define VEDITARCLIENTE_H
#include "wxfbWindows.h"
#include "ArchivoCliente.h"

class VEditarCliente : public VCliente {
public:
	VEditarCliente(wxWindow *parent, int cual, ArchivoCliente &archi);
	~VEditarCliente();
protected:
	void ClickCancelar (wxCommandEvent & event);
	void ClickGuardar (wxCommandEvent & event);
private:
	ArchivoCliente &archi_cliente;
	int indice;
};

#endif

