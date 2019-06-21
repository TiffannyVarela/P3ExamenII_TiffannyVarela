#pragma once 
#include <string>
using std::string;

class Militar
{
public:
string nombre, codigo, edad, rango;
    Militar();
    Militar(string, string, string, string);

    string getNombre();
    void setNombre(string);

    string getCodigo();
    void setCodigo(string);

    string getEdad();
    void setEdad(string);

    string getRango();
    void setRango(string);
};
