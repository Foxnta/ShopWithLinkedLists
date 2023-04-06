#ifndef Tienda_H
#define Tienda_H
#include "linkedlist.h"

#include <string>
#include <iostream>
using namespace std;

class Tienda
{
public:
    linkedlist inv;

public:
    Tienda();
};
Tienda::Tienda()
{
    inv = linkedlist();
}

#endif // tienda