#include "User.h"
#include "ArticlesCoordinator.h"
#include "Client.h"
#include "MenuManager.h"
#include "Article.h"
#include "Node.h"
#include "linkedlist.h"
#include "Tienda.h"
#include "ShoppingCart.h"
#include "ConsolidarCompra.h"


#include <string>
#include <iostream>
using namespace std;

class Controlador
{
public:
    MenuManager MenuMan;
    ArticlesCoordinator Acoor;
    Client Cliente;
    Tienda myTienda;
    ConsolidarCompra ConCompra;
    

public:
    Controlador();
    void Run();
    string gestorAccionesClientes();
    string gestorAccionesCoordinator();
};

Controlador::Controlador()
{
    myTienda = Tienda();
    Acoor = ArticlesCoordinator();
    Cliente = Client();
    MenuMan = MenuManager();
    ConCompra = ConsolidarCompra();
}

string Controlador::gestorAccionesCoordinator()
{

    int opcion;
    do
    {
        cout << "\n" << endl;
        MenuMan.showMenu(Acoor);
        opcion = MenuMan.getAnswer();   
        cout << "\n" << endl;

        switch (opcion)
        {
        case 1:
            cout << "Ha seleccionado anadir un articulo" << endl;
            Acoor.addArticulo(myTienda.inv);
            break;
        case 2:
            cout << "Ha seleccionado modificar un articulo" << endl;
            Acoor.modifyArticulo(myTienda.inv);
            break;
        case 3:
            cout << "Ha seleccionado eliminar un articulo" << endl;
            Acoor.deleteArticulo(myTienda.inv);
            break;
        case 4:
            cout << "Ha seleccionado imprimir articulos" << endl;
            Acoor.imprimir(myTienda.inv);
            break;
        case 5:
            cout << "Ha seleccionado cambiar de usuario" << endl;
            return "cambiar";
            break;
        case 6:
            cout << "Ha seleccionado cerrar el programa" << endl;
            return "salir";
            break;
        default:
            cout << "Opcion invalida. Seleccione una opcion valida." << endl;
            break;
        }
    } while (true);
}

string Controlador::gestorAccionesClientes()
{
    int opcion;
    do
    {
        cout << "\n" << endl;
        MenuMan.showMenu(Cliente);
        opcion = MenuMan.getAnswer();
        cout << "\n" << endl;

        switch (opcion)
        {
        case 1:
            cout << "Ha seleccionado comprar un articulo" << endl;
            Cliente.imprimir(myTienda.inv);
            Cliente.comprarArticulo(myTienda.inv);
            break;
        case 2:
            cout << "Ha seleccionado ver carrito de compras" << endl;
            Cliente.imprimirCarrito();
            break;
        case 3:
            cout << "Ha seleccionado pagar articulos" << endl;
            ConCompra.Pago(myTienda.inv,Cliente.shopCart.prod); 
            break;
        case 4:
            cout << "Ha seleccionado cambiar de usuario" << endl;
            return "cambiar";
            break;
        case 5:
            cout << "Ha seleccionado cerrar el programa" << endl;
            return "salir";
            break;
        default:
            cout << "Opcion invalida. Seleccione una opcion valida." << endl;
            break;
        }
    } while (true);
}

void Controlador::Run()
{

    bool run = true;
    string salida;
    char chr = MenuMan.selectUser();

    // segun el usuario ejecuto el gestor accion correspondiente
    while (run)
    {
        if (chr == 'A')
        {
            salida = gestorAccionesCoordinator();
            if (salida == "salir")
            {
                run = false;
            }
            else if (salida == "cambiar")
            {
                chr = 'C';
            }
        }
        else
        {
            salida = gestorAccionesClientes();
            if (salida == "salir")
            {
                run = false;
            }
            else if (salida == "cambiar")
            {
                chr = 'A';
            }
        }
    }
}

int main()
{
    Controlador sys;
    sys.Run();
    return 0;
}