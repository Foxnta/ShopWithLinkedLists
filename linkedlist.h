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

        if (actual != nullptr)
        {
            cout << "-------Listado De Articulos-------" << endl;

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
        else
        {
            cout << "El inventario esta vacio" << endl;
        }
    }

    void modify_element(int id, string valoramodificar)
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
        else
        {
            cout << "la lista se encuentra vacia" << endl;
        }
    }

    void delete_element(int id)
    {

        if (head != nullptr)
        {
            int index = 0;
            bool encontrado = false;
            Node *actual = head;

            while (actual != nullptr)
            {
                if (actual->value.id == id)
                {
                    encontrado = true;
                    break;
                }
                index++;
                actual = actual->next;
            }

            if (encontrado == false)
            {
                cout << "No se encontro el Articulo" << endl;
                return;
            }

            if (index == 0)
            {
                if (head != nullptr)
                {
                    Node *temp = head;
                    head = head->next;
                    delete temp;
                    size--;
                }
            }
            else
            {
                Node *actual = head;
                Node *anterior = nullptr;
                Node *siguiente = nullptr;
                Node *deletenode = nullptr;

                for (int i = 0; i <= index; i++)
                {
                    if (i == index - 1)
                    {
                        anterior = actual;
                    }
                    if (i == index)
                    {
                        siguiente = actual->next;
                        deletenode = actual;
                    }
                    actual = actual->next;
                }
                anterior->next = siguiente;
                delete deletenode;
                size--;
                cout << "Articulo elminado con exito" << endl;
            }
        }
        else
        {
            cout << "la lista se encuentra vacia" << endl;
        }
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

    bool is_empty()
    {
        if (head == nullptr)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool id_find(int ID)
    {
        if (head == nullptr)
        {
            return false;
        }
        else
        {
            Node *actual = head;
            bool find = false;
            while (actual != nullptr)
            {
                if (actual->value.id == ID)
                {
                    find = true;
                    break;
                }
                actual = actual->next;
            }
            return find;
        }
    }

    Article returnArtById(int id)
    {

        Node *actual = head;
        while (actual != nullptr)
        {
            if (actual->value.id == id)
            {
                break;
            }
            actual = actual->next;
        }
        return actual->value;
    }

    float returnTotal()
    {
        float total = 0;
        Node *actual = head;
        while (actual != nullptr)
        {
            if (actual->value.type == "F")
            {
                total = total + (actual->value.price * (1.1)) * actual->value.quantity;
            }
            else
            {
                total = total + actual->value.price * actual->value.quantity;
            }
            actual = actual->next;
        }
        return total;
    }

    void vaciar() {
        Node* temp = head;
        while (temp != nullptr) {
            Node* siguiente = temp->next;
            delete temp;
            temp = siguiente;
        }
        head = nullptr;
        size = 0;
    }



};

#endif // linkedlist