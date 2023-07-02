#include "Fecha.h"
#include <ctime>

Fecha::Fecha() {
	time_t actual = time(NULL);
	struct tm fechaHoy = *(localtime(&actual));
	seg= fechaHoy.tm_sec-1; // Segundos pasados del minuto (0-61) le resto un segundo
	minu= fechaHoy.tm_min; // Minutos pasados de la hora (0-59)
	hora= fechaHoy.tm_hour; // Horas desde medianoche (0-23)
	dia= fechaHoy.tm_mday;// Dia del mes (1-31)
	mes= fechaHoy.tm_mon+1; // Número del mes (0-11) le sumo un mes
	anio= fechaHoy.tm_year+1900; // Años transcurridos desde 1900 le sumo un anio
}

Fecha::~Fecha() { }

Fecha::Fecha (int d, int m, int a) {
	seg=minu=hora=0;
	dia=d;
	mes=m;
	anio=a;
}

bool Fecha::operator== (const Fecha & f) const {
	if(this->VerAnio()==f.VerAnio() && this->VerMes()==f.VerMes() && this->VerDia()==f.VerDia() && this->VerHora()==f.VerHora() && this->VerMinuto()==f.VerMinuto() && this->VerSegundo()==f.VerSegundo()) {
		return true;
	} else {
		return false;
	}
}

bool Fecha::operator< (const Fecha & f) const {
	if(this->VerAnio()<f.VerAnio() && this->VerMes()<f.VerMes() && this->VerDia()<f.VerDia() && this->VerHora()<f.VerHora() && this->VerMinuto()<f.VerMinuto() && this->VerSegundo()<f.VerSegundo()){
		return true;
	} else {
		return false;
	}
}

int Fecha::VerAnio ( ) const {return anio;}

int Fecha::VerMes ( ) const {return mes;}

int Fecha::VerDia ( ) const {return dia;}

int Fecha::VerHora ( ) const {return hora;}

int Fecha::VerMinuto ( ) const {return minu;}

int Fecha::VerSegundo ( ) const {return seg;}

Fecha::Fecha (int d, int m, int a, int h, int mm, int s) {
	dia=d;
	mes=m;
	anio=a;
	hora=h;
	minu=mm;
	seg=s;
}

