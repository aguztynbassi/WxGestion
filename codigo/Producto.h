#ifndef PRODUCTO_H
#define PRODUCTO_H
#include <fstream>
#include <string>
using namespace std;

struct nodo_producto{
	unsigned int CODIGO;
	char NOMBRE[32];
	float PRECIO;
	bool EXISTE;
};

class Producto {
private:
	unsigned int codigo;
	string nombre;
	float precio;
	bool existe;
public:
	/**
	* @brief constructor
	*/
	Producto();
	/**
	* @brief
	*	carga el DNI del nuevo cliente
	* @param codigo del Producto
	* @param nombre del Producto
	* @param precio del Producto
	*/
	Producto(unsigned int, string, float);
	/**
	* @brief destructor
	*/
	~Producto();
	/**
	* @brief
	*	carga el codigo del Producto
	* @return codigo
	*/
	void CargarCodigo(unsigned int);
	/**
	* @brief
	*	carga el nombre del Producto
	* @return nombre
	*/
	void CargarNombre(string);
	/**
	* @brief
	*	carga el precio del producto
	* @param precio
	*/
	void CargarPrecio(float);
	/**
	* @brief
	*	muestra el codigo del Producto
	* @return unsigned int
	*/
	unsigned int VerCodigo()const;
	/**
	* @brief
	*	muestra el nombre del Producto
	* @return string
	*/
	string VerNombre()const;
	/**
	* @brief
	*	muestra el precio del Producto
	* @return float
	*/
	float VerPrecio()const;
	/**
	* @brief
	*	muestra si el Producto existe
	* @return true or false
	*/
	bool VerExistencia()const;
	/**
	* @brief
	*	funsion que compara si hay un dato que no cumple con los requisitos
	* @return mensaje de error o cadena vacia
	*/
	string Validar()const;
	/**
	* @brief
	*	sobrecarga del operator ==
	* @param Producto p
	* @return true si this->VerCodigo() < p.VerCodigo()
	*/
	bool operator< (Producto p);
	/**
	* @brief
	*	sobrecarga del operator ==
	* @param Producto p
	* @return true si this->VerCodigo() == p.VerCodigo()
	*/
	bool operator== (Producto p);
	/**
	* @brief
	*	sobrecarga del operator ==
	* @param Producto p
	* @return true si this->VerCodigo() > p.VerCodigo()
	*/
	bool operator> (Producto p);
	/**
	* @brief
	*	funsion que compara si el codigo de p1 es menor que el de p2
	* @param Producto p1
	* @param Producto p2
	* @return true si p1 < p2
	*/
	static bool criterio_comparacion_codigo(Producto p1, Producto p2);
	/**
	* @brief
	*	funsion que compara si el nombre de p1 es menor que el de p2
	* @param Producto p1
	* @param Producto p2
	* @return true si p1 < p2
	*/
	static bool criterio_comparacion_nombre(Producto p1, Producto p2);
	/**
	* @brief
	*	lee datos desde el archivo al vector
	* @param Archivo
	*/
	void LeerDesdeBinario(ifstream &i);
	/**
	* @brief
	*	escribe datos desde el vector al Archivo
	* @param Archivo
	*/
	void GuardarDesdeBinario(ofstream &o);
	/**
	* @brief
	*	poner en true existe
	*/
	void Cargar();
	/**
	* @brief
	*	poner en false existe
	*/
	void Borrar();
	using struct_binario = nodo_producto;
};

#endif

