#include "NodoArbol.h"
#include "Militar.h"
#include <vector>
using std::vector;

NodoArbol::NodoArbol(){

}

NodoArbol::NodoArbol(Militar* pmilitar, vector <NodoArbol*> pnodoArbol ){
    this -> militar = pmilitar;
    this -> nodoArbol = pnodoArbol;
}

Militar* NodoArbol::getMilitar(){
    return militar;
}

void NodoArbol::setMilitar( Militar* pmilitar){
    militar = pmilitar;
}

vector <NodoArbol*> NodoArbol::getnodoArbol(){
    return nodoArbol;
}

void NodoArbol::setnodoArbol( vector <NodoArbol*> pnodoArbol){
    nodoArbol = pnodoArbol;
}

void NodoArbol::agregarHijo(NodoArbol* na){
    nodoArbol.push_back(na)
}