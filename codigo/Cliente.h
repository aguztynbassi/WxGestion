#ifndef CLIENTE_H
#define CLIENTE_H
#include <fstream>
#include <string>

using namespace std;

struct nodo_cliente{
	//atributos
	unsigned int DNI, DIA, MES, ANIO;
	char NOMBRE[20];
	char APELLIDO[20];
	char DIRECCION[40];
	char TELEFONO[20];
	bool EXISTE;
};

class Cliente {
private:
	unsigned int dni, dia, mes ,anio;
	string nombre, apellido, direccion, telefono;
	bool existe;
public:
	/**
	* @brief
	*	costructor
	*/
	Cliente();
	/**
	* @brief
	*	costructor
	* @param dni
	* @param nombre
	* @param apellido
	* @param direccion
	* @param telefono
	* @param dia de nacimiento
	* @param mes de nacimiento
	* @param anio de nacimiento
	*/
	Cliente(unsigned int, string, string, string, string, int, int, int);
	/**
	* @brief
	*	destructor
	*/
	~Cliente();
	/**
	* @brief
	*	carga el DNI del nuevo cliente
	* @param i numero de documento del nuevo cliente
	*/
	void CargarDni(unsigned int i);
	/**
	* @brief
	*	carga el nombre del nuevo cliente
	* @param i nombre de documento del nuevo cliente
	*/
	void CargarNombre(string i);
	/**
	* @brief
	*	carga el apellido del nuevo cliente
	* @param i apellido del nuevo cliente
	*/
	void CargarApellido(string i);
	/**
	* @brief
	*	carga la direccion local del nuevo cliente
	* @param i nombre de la calle del nuevo cliente
	*/
	void CargarDireccion(string i);
	/**
	* @brief
	*	carga la fecha de nacimiento del nuevo cliente
	* @param x numero del dia de nacimiento del nuevo cliente
	* @param y numero del mes de nacimiento del nuevo cliente
	* @param z numero del anio de nacimiento del nuevo cliente
	*/
	void CargarFechaDeNacimiento(unsigned int x, unsigned int y, unsigned int z);
	/**
	* @brief
	*	carga telefono del nuevo cliente
	* @param c codigo de area de telefono del nuevo cliente
	*/
	void CargarTelefono(string c);
	/**
	* @brief
	*	muestra el dni del cliente seleccionado
	* @return el numero de dni
	*/
	unsigned int VerDni()const ;
	/**
	* @brief
	*	muestra el nombre del cliente seleccionado
	* @return el nombre
	*/
	string VerNombre()const;
	/**
	* @brief
	*	muestra el apellido del cliente seleccionado
	* @return el apellido
	*/
	string VerApellido()const;
	/**
	* @brief
	*	muestra la direccion del cliente seleccionado
	* @return la direccion
	*/
	string VerDireccion()const;
	/**
	* @brief
	*	muestra el telefono del cliente seleccionado
	* @return el telefono
	*/
	string VerTelefono()const;
	/**
	* @brief
	*	muestra el dia de nacimineto del cliente seleccionado
	* @return el dia
	*/
	unsigned int VerDia() const;
	/**
	* @brief
	*	muestra el mes de nacimiento del cliente seleccionado
	* @return el mes
	*/
	unsigned int VerMes() const;
	/**
	* @brief
	*	muestra el anio de nacimiento del cliente seleccionado
	* @return el anio
	*/
	unsigned int VerAnio() const;
	/**
	* @brief
	*	muestra si el cliente existe
	* @return true or false
	*/
	bool VerExistencia()const;
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
	*	sobrecarga del operator <
	* @param Cliente c
	* @return true si this->VerDni() < c.VerDni()
	*/
	bool operator< (Cliente c);
	/**
	* @brief
	*	sobrecarga del operator ==
	* @param Cliente c 
	* @return true si this->VerDni() == c.VerDni()
	*/
	bool operator== (Cliente c);
	/**
	* @brief
	*	sobrecarga del operator >
	* @param Cliente c 
	* @return true si this->VerDni() > c.VerDni()
	*/
	bool operator> (Cliente c);
	/**
	* @brief
	*	funsion que compara si el dni de c1 es menor que el de c2
	* @param Cliente n 
	* @param Cliente n+1
	* @return true si n < n+1
	*/
	static bool criterio_comparacion_dni(Cliente c1, Cliente c2);
	/**
	* @brief
	*	funsion que compara si la convinacion de nombre y apellido de c1 
	*	es menor que el de c2
	* @param Cliente n 
	* @param Cliente n+1
	* @return true si n < n+1
	*/
	static bool criterio_comparacion_apellido_y_nombre(Cliente c1, Cliente c2);
	/**
	* @brief
	*	funsion que compara si la direccion de c1 es menor que el de c2
	* @param Cliente n 
	* @param Cliente n+1
	* @return true si n < n+1
	*/
	static bool criterio_comparacion_direccion(Cliente c1, Cliente c2);
	/**
	* @brief
	*	funsion que compara si el telefono de c1 es menor que el de c2
	* @param Cliente n 
	* @param Cliente n+1
	* @return true si n < n+1
	*/
	static bool criterio_comparacion_telefono(Cliente c1, Cliente c2);
	/**
	* @brief
	*	funsion que compara si hay un dato que no cumple con los requisitos
	* @return mensaje de error o cadena vacia
	*/
	const string Validar ();
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
	using struct_binario = nodo_cliente;
};

#endif

