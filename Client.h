#ifndef CLIENT_H
#define CLIENT_H
#include "User.h"

#include <string>
#include <iostream>
using namespace std;

class Client:public User{
    public:
        Client();
        // Buy(Inventory);
        // Pay(ShoppingCart);   
};

Client::Client(){
    Menu = "Bienvenido Cliente. \n Seleccione una opcion: \n 1. Comprar un articulo\n 2. Pagar articulos \n 3. Cambiar de usuario \n 4. Cerrar el programa\n";
}


#endif // CLIENT_H