#ifndef FECHA_H
#define FECHA_H

class Fecha {
private:
	int seg, minu, hora, dia, mes, anio;
public:
	/// @brief Destructor
	~Fecha();
	/**
	* @brief
	*	costructor para fecha compuesto por anio, mes, dia, ...
	*	tiene la libreria ctime para que use la fecha y hora de la pc
	*	ya tiene modificado los parametros para que empiece del 
	*	01/01/1900 - 00:00:00 
	*/
	Fecha();
	/**
	* @brief
	*	costructor
	* @param d dia de nacimiento
	* @param m mes de nacimiento
	* @param a anio de nacimiento
	*/
	Fecha(int, int, int);
	/**
	* @brief
	*	costructor
	* @param d dia de nacimiento
	* @param m mes de nacimiento
	* @param a anio de nacimiento
	* @param h anio de nacimiento
	* @param mm anio de nacimiento
	* @param s anio de nacimiento
	*/
	Fecha(int, int, int, int, int, int);
	/**
	* @brief  
	*	funcion que solo muestra el anio del computador
	* @return muestra el anio
	*/
	int VerAnio() const;
	/**
	* @brief 
	*	funcion que solo muestra el mes del computador
	* @return muestra el mes
	*/
	int VerMes() const;
	/**
	* @brief 
	*	funcion que solo muestra el dia del computador
	* @return muestra el dia
	*/
	int VerDia() const;
	/**
	* @brief 
	*	funcion que solo muestra la hora del computador
	* @return muestra la hora
	*/
	int VerHora() const;
	/**
	* @brief
	*	funcion que solo muestra los minutos del computador
	* @return muestra los minutos
	*/
	int VerMinuto() const;
	/**
	* @brief 
	*	funcion que solo muestra los segundos del computador
	* @return muestra los segundos
	*/
	int VerSegundo() const;
	bool operator<(const Fecha &f)const;///sobrecarga del operator<
	bool operator==(const Fecha &f)const;///sobrecarga del operator==
};

#endif
