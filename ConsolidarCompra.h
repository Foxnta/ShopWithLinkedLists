#ifndef ConsolidarCompra_H
#define ConsolidarCompra_H
#include "linkedlist.h"
#include "Node.h"

#include <string>
#include <iostream>
using namespace std;

class ConsolidarCompra
{
public:
    ConsolidarCompra();
    void Pago(linkedlist &inv, linkedlist &carrito);
};

ConsolidarCompra::ConsolidarCompra()
{
}

void ConsolidarCompra::Pago(linkedlist &inv, linkedlist &carrito)
{

    Node *actualcarrito = carrito.head;
    if(actualcarrito==nullptr){
        cout << "Su carrito de compras esta vacio" << endl;
        return;
    }

    cout << " \n Por favor verifique los productos a comprar \n"
         << endl;
    carrito.traverse();
    cout << " \n TOTAL DE LA COMPRA ";
    cout << carrito.returnTotal() << endl;

    cout << "Desea hacer esta compra? SI (1) O NO (0)" << endl;
    int pagar;
    cin >> pagar;
    bool valido = false;
    while (!valido)
    {
        if (pagar == 1 || pagar == 0)
        {
            valido = true;
            break;
        }
        cout << "Ingrese un valor correcto SI (1) O NO (0) : ";
        cin >> pagar;
    }

    if(pagar==1){
        //codigo para actualizar el inv 
        //
        Node *actualcarrito = carrito.head;
        Node *actualinv = inv.head;
        while (actualcarrito != nullptr)
        {
            while (actualinv != nullptr)
            {
                if (actualinv->value.id == actualcarrito->value.id)
                {
                    break;
                }
                actualinv = actualinv->next;
            }

            actualinv->value.quantity=actualinv->value.quantity-actualcarrito->value.quantity;

            if(actualinv->value.quantity==0){
                inv.delete_element(actualinv->value.id);
            }
            
            actualinv = inv.head;
            actualcarrito = actualcarrito->next;
        }

        carrito.vaciar();
        
    }else{
        return;
    }
}

#endif // consolidar compra