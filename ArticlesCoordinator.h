#ifndef ARTICLES_COORDINATOR_H
#define ARTICLES_COORDINATOR_H
#include "User.h"
#include "Tienda.h"
#include "linkedlist.h"

#include <string>
#include <iostream>
using namespace std;

class ArticlesCoordinator : public User
{
public:
    ArticlesCoordinator();
    void imprimir(linkedlist &inv);
    void addArticulo(linkedlist &inv);
    void modifyArticulo(linkedlist &inv);
    void deleteArticulo(linkedlist &inv);
};

ArticlesCoordinator::ArticlesCoordinator()
{
    Menu = "Bienvenido Admin. \n Seleccione una opcion: \n 1. Anadir un articulo \n 2. Modificar un articulo \n 3. Eliminar un articulo \n 4. Visualizar Articulos \n 5. Cambiar de usuario \n 6. Cerrar el programa \n";
}

void ArticlesCoordinator::imprimir(linkedlist &inv)
{
    inv.traverse();
}

void ArticlesCoordinator::addArticulo(linkedlist &inv)
{
    string nombre;
    int id;
    float precio;
    int cantidad;
    string tipo;

    cout << "Ingrese el tipo Tecnologico = T o Sport = S o Foreign = F ";
    cin >> tipo;
    cout << "Ingrese el nombre: ";
    cin >> nombre;
    cout << "Ingrese el ID (int): ";
    cin >> id;
    cout << "Ingrese el precio (int): ";
    cin >> precio;
    cout << "Ingrese la cantidad (float): ";
    cin >> cantidad;

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
    else
    {
        cout << "Tipo de articulo invalido" << endl;
    }
}

void ArticlesCoordinator::modifyArticulo(linkedlist &inv)
{
    string valoramodificar;
    int id;
    cout << "Ingrese el ID que desea modificar (int): ";
    cin >> id;
    cout << "Ingrese el valor a modificar: Nombre(N), ID(ID), Precio(P), Cantidad(C) ";
    cin >> valoramodificar;

    if (valoramodificar == "N" || valoramodificar == "C" || valoramodificar == "ID" || valoramodificar == "P" || valoramodificar == "C")
    {
        inv.modify_element(id, valoramodificar);
    }
    else
    {
        cout << "Valor a modificar invalido" << endl;
    }
}

void ArticlesCoordinator::deleteArticulo(linkedlist &inv)
{
    string valoramodificar;
    int id;
    cout << "Ingrese el ID que desea eliminar (int): ";
    cin >> id;
    inv.delete_element(id);
}

#endif // ARTICLES_COORDINATOR_H