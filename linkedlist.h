#ifndef linkedlist_H
#define linkedlist_H
#include "Node.h"

#include <string>
#include <iostream>
using namespace std;

class linkedlist
{
public:
    // attributes
    Node *head = nullptr;
    int size = 0;
    // methods
    linkedlist(){};

    void dimension()
    {
        cout << "the size of linkedlist is " << size << endl;
    }

    void traverse()
    {
        Node *actual = head;

        cout << "Articulos Tecnologicos:" << endl;

        while (actual != nullptr)
        {
            if (actual->value.type == "T")
            {
                actual->value.showArticle();
            }
            actual = actual->next;
        }

        actual = head;
        cout << "Articulos Deportivos:" << endl;
        while (actual != nullptr)
        {
            if (actual->value.type == "S")
            {
                actual->value.showArticle();
            }
            actual = actual->next;
        }
        actual = head;

        cout << "Articulos Extranjeros:" << endl;
        while (actual != nullptr)
        {
            if (actual->value.type == "F")
            {
                actual->value.showArticle();
            }
            actual = actual->next;
        }
    }

    modify_element(int id, string valoramodificar)
    {
        Node *actual = head;
        if (head != nullptr)
        {
            int intvalue;
            string stringvalue;
            float floatvalue;

            bool encontrado = false;

            while (actual != nullptr)
            {
                if (actual->value.id == id)
                {
                    encontrado = true;
                    break;
                }
                actual = actual->next;
            }

            if (encontrado == true)
            {
                if (valoramodificar == "N")
                {
                    cout << "Nuevo nombre: " << endl;
                    cin >> stringvalue;

                    actual->value.name = stringvalue;
                }
                else if (valoramodificar == "ID")
                {
                    cout << "Nuevo ID: " << endl;
                    cin >> intvalue;
                    actual->value.id = intvalue;
                }
                else if (valoramodificar == "P")
                {
                    cout << "Nuevo Precio: " << endl;
                    cin >> floatvalue;
                    actual->value.price = floatvalue;
                }
                else if (valoramodificar == "C")
                {
                    cout << "Nueva Cantidad: " << endl;
                    cin >> intvalue;
                    actual->value.quantity = intvalue;
                }
            }
            else
            {
                cout << "ID no encontrado: " << endl;
            }
        }
        return false;
    }

    void add_head(Article value)
    {
        Node *new_node = new Node(value);
        if (head == nullptr)
        {
            head = new_node;
        }
        else
        {
            Node *aux_node = head;
            head = new_node;
            new_node->next = aux_node;
        }
        size++;
    }


 };

#endif // linkedlist