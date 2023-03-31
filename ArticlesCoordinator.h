#ifndef ARTICLES_COORDINATOR_H
#define ARTICLES_COORDINATOR_H
#include "User.h"
#include "Tienda.h"

#include <string>
#include <iostream>
using namespace std;

class ArticlesCoordinator : public User
{   
public:
    Tienda mitienda;
    ArticlesCoordinator();
    void addArticulo();
    void modifyArticulo();
    void deleteArticulo();
    // Modify(int, Inventory);
    // Delete(int, Inventory);
};

ArticlesCoordinator::ArticlesCoordinator()
{
    Menu = "Bienvenido Admin. \n Seleccione una opcion: \n 1. Anadir un articulo \n 2. Modificar un articulo \n 3. Eliminar un articulo \n 4. Cambiar de usuario \n 5. Cerrar el programa \n";
    mitienda = Tienda();
}

void ArticlesCoordinator::addArticulo(){

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

    mitienda.crearArticulo(nombre, id, precio, cantidad, tipo);
}

void ArticlesCoordinator::modifyArticulo(){

    string valoramodificar;
    int id;
    cout << "Ingrese el ID que desea modificar (int): ";
    cin >> id;
    cout << "Ingrese el valor a modificar: Nombre(N), ID(ID), Precio(P), Cantidad(C) ";
    cin >> valoramodificar;

    mitienda.modificarArticulo(id, valoramodificar);
}

void ArticlesCoordinator::deleteArticulo(){
    
    string valoramodificar;
    int id;
    cout << "Ingrese el ID que desea eliminar (int): ";
    cin >> id;

}



#endif // ARTICLES_COORDINATOR_H