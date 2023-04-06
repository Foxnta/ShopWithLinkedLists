#ifndef CLIENT_H
#define CLIENT_H
#include "User.h"
#include "Tienda.h"
#include "ShoppingCart.h"
#include "linkedlist.h"

#include <string>
#include <iostream>
using namespace std;

class Client : public User
{
public:
    Client();
    void imprimir(linkedlist &inv);
    void comprarArticulo(linkedlist &inv, linkedlist &prod);
};

Client::Client()
{
    Menu = "Bienvenido Cliente. \n Seleccione una opcion: \n 1. Comprar un articulo\n 2. Ver carrito de compras \n 3. Pagar articulos \n 4. Cambiar de usuario \n 5. Cerrar el programa\n";
}

void Client::imprimir(linkedlist &inv)
{
    inv.traverse();
}

void Client::comprarArticulo(linkedlist &inv, linkedlist &prod)
{
    bool value = inv.is_empty();
    if (value)
    {
        cout << "Vuelva pronto" << endl;
    }
    else
    {
        int id;
        cout << "Ingrese el ID (int): ";
        cin >> id;

        bool valido = false;

        while (!valido)
        {
            bool findid = inv.id_find(id);
            if (findid == true)
            {
                valido = true;
                break;
            }
            cout << "Ingrese ID existente (int): ";
            cin >> id;
        }

        Article a = inv.returnArtById(id);
        int cantidadmax=a.quantity;
        int cantidad;
        cout << "Ingrese la cantidad (int): ";
        cin >> cantidad;

        bool valido2 = false;
        while (!valido2)
        {
            if (cantidad <= cantidadmax)
            {
                valido2 = true;
                break;
            }
            cout << "Ingrese una cantidad disponible (int): ";
            cin >> cantidad;
        }
        a.quantity = cantidad;
        prod.add_head(a);

    }
}

#endif // CLIENT_H