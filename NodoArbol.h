#pragma once 
#include "Militar.h"
#include <vector>
using std::vector;
class NodoArbol
{
public:
    Militar* militar;
    vector <NodoArbol*> nodoArbol;
    NodoArbol();
    NodoArbol(Militar*, vector<NodoArbol*>);

    Militar* getMilitar();
    void setMilitar(Militar*);

    vector <NodoArbol*> getnodoArbol();
    void setnodoArbol(vector <NodoArbol*>);

    void agregarHijo(NodoArbol*);
};
