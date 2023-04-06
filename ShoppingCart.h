#ifndef ShoppingCart_H
#define ShoppingCart_H
#include "linkedlist.h"

#include <string>
#include <iostream>
using namespace std;

class ShoppingCart
{
public:
    linkedlist prod;

public:
    ShoppingCart();
};

ShoppingCart::ShoppingCart()
{
    prod = linkedlist();
}

#endif // tienda