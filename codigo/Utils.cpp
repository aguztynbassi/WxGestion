#include "Utils.h"
#include <cctype>
#include <string>
#include <wx/string.h>
using namespace std;

string &pasar_a_minusculas(string &s) {
	for(size_t i=0;i<s.length();i++) 
		s[i]=tolower(s[i]);
	return s;
}
wxString c_to_wx(const char *c_str) {
	return wxString::From8BitData(c_str);
}
wxString std_to_wx(const string &std_str) {
	return wxString::From8BitData(std_str.c_str());
}
/// para convertir wxString a std::string
string wx_to_std(const wxString &wx_str) {
	return static_cast<const char*>(wx_str.To8BitData());
}
