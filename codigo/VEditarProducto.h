#ifndef VEDITARPRODUCTO_H
#define VEDITARPRODUCTO_H
#include "wxfbWindows.h"
#include "ArchivoProducto.h"

class VEditarProducto : public VProducto {
public:
	VEditarProducto(wxWindow *parent, int cual, ArchivoProducto &archi);
	~VEditarProducto();
protected:
	void ClickCancelar (wxCommandEvent & event);
	void ClickGuardar (wxCommandEvent & event);
private:
	int indice;
	ArchivoProducto &archi_producto;
};

#endif

