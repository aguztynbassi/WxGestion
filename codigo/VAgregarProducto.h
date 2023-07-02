#ifndef VAGREGARPRODUCTO_H
#define VAGREGARPRODUCTO_H
#include "wxfbWindows.h"
#include "ArchivoProducto.h"

class VAgregarProducto : public VProducto {
private:
	ArchivoProducto &archi_producto;
protected:
	void ClickCancelar( wxCommandEvent& event ) ;
	void ClickGuardar( wxCommandEvent& event) ;
public:
	VAgregarProducto(wxWindow *parent, ArchivoProducto &archi);
	~VAgregarProducto();
};

#endif

