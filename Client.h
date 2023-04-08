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
    ShoppingCart shopCart;
    Client();
    void imprimirCarrito();
    void imprimir(linkedlist &inv);
    void comprarArticulo(linkedlist &inv);
};

Client::Client()
{
    Menu = "Bienvenido Cliente. \n Seleccione una opcion: \n 1. Comprar un articulo\n 2. Ver carrito de compras \n 3. Pagar articulos \n 4. Cambiar de usuario \n 5. Cerrar el programa\n";
    shopCart = ShoppingCart();
}

void Client::imprimir(linkedlist &inv)
{
    inv.traverse();
}
void Client::imprimirCarrito()
{
    shopCart.prod.traverse();
}

void Client::comprarArticulo(linkedlist &inv)
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

        bool idEnElCarrito = shopCart.prod.id_find(id);
        if (idEnElCarrito == true)
        {
            cout << "Este articulo ya se encuentra en su carrito de compras, esta seguro que desea modificarlo? SI (1) O NO (0)" << endl;
            int modificar;
            cin >> modificar;
            bool valido1 = false;
            while (!valido1)
            {
                if ( modificar == 1 || modificar == 0)
                {
                    valido1 = true;
                    break;
                }
                cout << "Ingrese un valor correcto SI (1) O NO (0) : ";
                cin >> modificar;
            }

            if (modificar == 1)
            {
                shopCart.prod.delete_element(id);
            }
            else
            {
                return;
            }
        }

        Article a = inv.returnArtById(id);
        int cantidadmax = a.quantity;
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
        shopCart.prod.add_head(a);
    }
}

#endif // CLIENT_H