#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <cstring>
#include <wx/string.h>
using namespace std;
/**
* @brief pasar_a_minusculas convierte una cadena en minusculas
* @param s cadena de string que se des referencia para pasar a minusculas
* @return retorna la misma cadena en ninusculas
*/
string &pasar_a_minusculas(string &s);
/// para convertir un c-string, o una constante, a wxString
wxString c_to_wx(const char *c_str);
/// para convertir un std::string a wxString
wxString std_to_wx(const string &std_str);
/// para convertir wxString a std::string
string wx_to_std(const wxString &wx_str);
#endif
