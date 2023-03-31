#ifndef Tienda_H
#define Tienda_H
#include "linkedlist.h"

#include <string>
#include <iostream>
using namespace std;


class Tienda
{
public:
    linkedlist inv;

public:
    Tienda();
    void crearArticulo(string, int, float, int, string);
    void modificarArticulo(int, string);
    void imprimir();
};

Tienda::Tienda()
{
    inv = linkedlist();
}

void Tienda::crearArticulo(string nombre,int id,float precio, int cantidad,string tipo)
{

    if (tipo == "T")
    {
        TechnologyArticle a(nombre, id, precio, cantidad, tipo);
        inv.add_head(a);
    }
    else if (tipo == "S")
    {
        SportArticle a(nombre, id, precio, cantidad, tipo);
        inv.add_head(a);
    }
    else if (tipo == "F")
    {
        ForeignArticle a(nombre, id, precio, cantidad, tipo);
        inv.add_head(a);
    }
    else{
        cout <<"Tipo de articulo invalido"<< endl;  
    }
}

void Tienda::imprimir(){
    inv.traverse();
}

void Tienda::modificarArticulo(int id, string valoramodificar){
    if (valoramodificar == "N" || valoramodificar == "C" || valoramodificar == "ID" || valoramodificar == "P" || valoramodificar == "C")
    {
        inv.modify_element(id, valoramodificar);
    }
    else{
        cout <<"Valor a modificar invalido"<< endl;  
    }
}






#endif // tienda