#ifndef Node_H
#define Node_H
#include "Article.h"

#include <string>
#include <iostream>
using namespace std;

class Node
{
public:
    // attributes
    Article value{};
    Node *next{};
    // contructor
    Node(Article value) { this->value = value; }
};

#endif // Node