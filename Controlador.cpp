#include "User.h"
#include "ArticlesCoordinator.h"
#include "Client.h"
#include "MenuManager.h"
#include "Article.h"
#include "Node.h"
#include "linkedlist.h"
#include "Tienda.h"

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
}

string Controlador::gestorAccionesClientes()
{
    MenuMan.showMenu(Cliente);
    int opcion;
    do
    {
        opcion = MenuMan.getAnswer();
        switch (opcion)
        {
        case 1:
            cout << "Ha seleccionado comprar un artículo" << endl;
            // Aquí va el código para comprar un artículo
            break;
        case 2:
            cout << "Ha seleccionado pagar artículos" << endl;
            // Aquí va el código para pagar artículos
            break;
        case 3:
            cout << "Ha seleccionado cambiar de usuario" << endl;
            return "cambiar";
            break;
        case 4:
            cout << "Ha seleccionado cerrar el programa" << endl;
            return "salir";
            break;
        default:
            cout << "Opcion invalida. Seleccione una opcion valida." << endl;
            break;
        }
    } while (true);
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

void Controlador::Run()
{

    bool run = true;
    string salida;
    // solicito el tipo de usuario
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