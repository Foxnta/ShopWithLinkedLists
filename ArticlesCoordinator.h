#ifndef ARTICLES_COORDINATOR_H
#define ARTICLES_COORDINATOR_H
#include "User.h"
#include "Tienda.h"
#include "linkedlist.h"

#include <string>
#include <iostream>
#include <limits>
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

    bool valido = false;
    while (!valido)
    {
        if (tipo == "T" || tipo == "S" || tipo == "F")
        {
            valido = true;
            break;
        }
        cout << "Ingrese un tipo existente (String): ";
        cin >> tipo;
    }

    cout << "Ingrese el nombre: ";
    cin >> nombre;

    cout << "Ingrese el ID (int): ";

    while (!(cin >> id) || id <= 0)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Ingrese un numero entero valido: ";
    }

    bool valido1 = false;
    while (!valido1)
    {
        bool findid = inv.id_find(id);
        if (findid == false)
        {
            valido1 = true;
            break;
        }
        cout << "Ingrese un ID no existente (int): ";
        while (!(cin >> id) || id <= 0)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Ingrese un numero entero valido: ";
        }
    }

    cout << "Ingrese el precio (float): ";

    while (!(cin >> precio) || precio <= 0)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Ingrese un numero en punto flotante valido: ";
    }

    cout << "Ingrese la cantidad (int): ";

    while (!(cin >> cantidad) || cantidad <= 0)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Ingrese una cantidad entera positiva valida: ";
    }

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
    imprimir(inv);
    string valoramodificar;
    int id;

    cout << "Ingrese el ID que desea modificar (int): ";
    while (!(cin >> id))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Ingrese un numero entero valido: ";
    }

    if (inv.id_find(id))
    {
        do
        {
            cout << "Ingrese el valor a modificar ( Nombre(N), ID(ID), Precio(P), Cantidad(C)): ";
            cin >> valoramodificar;
        } while (valoramodificar != "N" && valoramodificar != "C" && valoramodificar != "ID" && valoramodificar != "P" && valoramodificar != "C");

        inv.modify_element(id, valoramodificar);
    }
    else
    {
        cout << "ID no encontrado" << endl;
    }

    cout << "Desea modificar otro articulo SI (1) O NO (0): " << endl;

    int modificarmas;
    cin >> modificarmas;

    bool valido = false;
    while (!valido)
    {
        if (modificarmas == 1 || modificarmas == 0)
        {
            valido = true;
            break;
        }
        cout << "Ingrese un valor correcto SI (1) O NO (0) : ";
        cin >> modificarmas;
    }

    if (modificarmas == 1)
    {
        modifyArticulo(inv);
    }
    else
    {
        return;
    }
}

void ArticlesCoordinator::deleteArticulo(linkedlist &inv)
{
    imprimir(inv);
    string valoramodificar;
    int id;
    cout << "Ingrese el ID que desea eliminar (int): ";
    cin >> id;
    inv.delete_element(id);

    bool value = inv.is_empty();
    if (!value)
    {
        cout << "Desea eliminar otro articulo SI (1) O NO (0): " << endl;

        int eliminarmas;
        cin >> eliminarmas;
        bool valido = false;

        while (!valido)
        {
            if (eliminarmas == 1 || eliminarmas == 0)
            {
                valido = true;
                break;
            }
            cout << "Ingrese un valor correcto SI (1) O NO (0) : ";
            cin >> eliminarmas;
        }

        if (eliminarmas == 1)
        {
            deleteArticulo(inv);
        }
        else
        {
            return;
        }
    }
}

#endif // ARTICLES_COORDINATOR_H