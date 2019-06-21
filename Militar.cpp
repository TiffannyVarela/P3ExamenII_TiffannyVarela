#include "Militar.h"
#include <string>
using std::string;

Militar::Militar(){

}

Militar::Militar(string pnombre, string pcodigo, string pedad, string prango){
    this -> nombre = pnombre;
    this -> codigo = pcodigo;
    this -> edad = pedad;
    this -> rango = prango;
}

string Militar::getNombre(){
    return nombre;
}

void Militar::setNombre(string pnombre){
    nombre = pnombre;
}

string Militar::getCodigo(){
    return codigo;
}

void Militar::setCodigo(string pcodigo){
    codigo = pcodigo;
}

string Militar::getEdad(){
    return edad;
}

void Militar::setEdad(string pedad){
    edad = pedad;
}

string Militar::getRango(){
    return rango;
}

void Militar::setRango(string prango){
    rango = prango;
}
