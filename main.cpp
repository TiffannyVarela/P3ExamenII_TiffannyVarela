
#include <ncurses.h>
#include "Militar.h"
#include "NodoArbol.h"
#include <typeinfo>
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::getline;
#include <string>
using std::string;
#include <vector>
using std::vector;
#include <fstream>
using std::ifstream;
using std::ofstream;

int menu();
int menu2();
void AgregarMilitar();
void limpiarVector();
void PreOrden(NodoArbol *);
void Revisar(vector<Militar *>, string);
int Contar(vector<Militar *>, string);

int main()
{ //inicio main
    Militar *milraiz = new Militar("Yagabarish Skrobernov", "M_17", "72", "general");
    Militar *militar;
    vector<NodoArbol *> nuevo;
    NodoArbol *raiz = new NodoArbol(milraiz, nuevo);
    vector<NodoArbol *> militaresTipoActual;
    vector<Militar *> militares;
    int opc = 0, c;
    int posMilitar=0;
    string nombre, codigo, edad, rango;
    int opc2;
    char letra;
    string nombreArchivo, ruta = "Listados/";
    ofstream outfile;
    do
    {
        switch (opc = menu())
        {
        case 1:
            cout << "Ingrese el nombre: " << endl;
            getline(cin, nombre);
            getline(cin, nombre);
            cout << "Ingrese el codigo: " << endl;
            getline(cin, codigo);
            cout << "Ingrese la edad: " << endl;
            getline(cin, edad);
            cout << "Ingrese el rango: " << endl;
            opc2 = menu2();
            if (opc2 == 1)
            {
                rango = "coronel";
                Revisar(militares, "general");
            }

            else if (opc2 == 2)
            {
                if (Contar(militares, "coronel") != 0)
                {
                    rango = "mayor";
                    Revisar(militares, "coronel");
                    cout<<"Seleccione la posicion"<<endl;
                    cin>>posMilitar;
                    militaresTipoActual.push_back(new NodoArbol(;))
                }
            }

            else if (opc2 == 3)
            {
                rango = "capitan";
                Revisar(militares, "mayor");
            }

            else if (opc2 == 4)
            {
                rango = "teniente";
                Revisar(militares, "capitan");
            }

            else if (opc2 == 5)
            {
                rango = "sargento";
                Revisar(militares, "teniente");
            }

            else if (opc2 == 6)
            {
                rango = "cabo";
                Revisar(militares, "sargento");
            }

            else
            {
                rango = "soldado";
                Revisar(militares, "cabo");
            }
            militar = new Militar(nombre, codigo, edad, rango);

            break;

        case 2:
            cout << "Ingrese el nombre del archivo: " << endl;
            cin >> nombreArchivo;
            //abrir
            outfile.open(ruta + nombreArchivo + ".txt", std::ios::app);
            //escribir
            //for (int i = 0; i < animales.size(); i++)
            // {
            //    outfile << "El " << animales[i]->toString() << " hace " << animales[i]->Sonido() << "." << endl;
            // }
            //cerrar
            outfile.close();
            initscr();
            noecho();
            start_color();
            init_pair(1, COLOR_GREEN, COLOR_BLACK);
            init_pair(2, COLOR_BLACK, COLOR_WHITE);
            init_pair(3, COLOR_BLUE, COLOR_RED);
            init_pair(4, COLOR_BLUE, COLOR_WHITE);
            while ((c = getch()) != 120)
            {
                if ((c = getch()) == 110)
                {
                    attrset(COLOR_PAIR(1));
                    bkgd(COLOR_PAIR(1));
                }

                if ((c = getch()) == 105)
                {
                    attrset(COLOR_PAIR(2));
                    bkgd(COLOR_PAIR(2));
                }

                if ((c = getch()) == 99)
                {
                    attrset(COLOR_PAIR(3));
                    bkgd(COLOR_PAIR(3));
                }

                if ((c = getch()) == 108)
                {
                    attrset(COLOR_PAIR(4));
                    bkgd(COLOR_PAIR(4));
                }
                refresh();
            }
            endwin();
            break;

        case 3:
            cout << "Saliendo" << endl;
            //limpiarVector(nuevo);
            //limpiarVector(militaresTipoActual);
            break;
        }
    } while (opc != 3);

    return 0;
} //fin main

int menu()
{
    while (true)
    {
        cout << "MENU" << endl
             << "1.- Agregar Militar" << endl
             << "2.- Vizualizar Ejercito" << endl
             << "3.- Salir" << endl;
        cout << "Ingrese una opcion: ";
        int opcion = 0;
        cin >> opcion;
        if (opcion >= 1 && opcion <= 3)
        {
            return opcion;
        }
        else
        {

            cout << "La opcion elegida no es valida, ingrese un valor entre 1 y 3" << endl;
        }
    } //end del while
    return 0;
}

int menu2()
{
    while (true)
    {
        cout << "MENU" << endl
             << "1.- Coronel" << endl
             << "2.- Mayor" << endl
             << "3.- Capitan" << endl
             << "4.- Teniente" << endl
             << "5.- Sargento" << endl
             << "6.- Cabo" << endl
             << "7.- Soldado" << endl;
        cout << "Ingrese una opcion: ";
        int opcion = 0;
        cin >> opcion;
        if (opcion >= 1 && opcion <= 7)
        {
            return opcion;
        }
        else
        {

            cout << "La opcion elegida no es valida, ingrese un valor entre 1 y 7" << endl;
        }
    } //end del while
    return 0;
}

void limpiarVector(vector<NodoArbol *> limpiar)
{
    for (int i = 0; i < limpiar.size(); i++)
    {
        delete limpiar[i];
        limpiar[i] = NULL;
    }
    limpiar.clear();
}

void PreOrden(NodoArbol *n)
{
    cout << n->getMilitar()->getNombre() << endl;
    for (int i = 0; i < n->getnodoArbol().size(); i++)
    {
        //cout<<"Militar: "<<i<<endl;
        PreOrden(n->getnodoArbol().at(i));
    }
}

void Revisar(vector<Militar *> v, string anterior)
{
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i]->getRango() == anterior)
        {
            cout << i + ": " + v[i]->getNombre() << endl;
        }
    }
}

int Contar(vector<Militar *> v, string anterior)
{
    int cont = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i]->getRango() == anterior)
        {
            cont++;
        }
    }
    return cont;
}