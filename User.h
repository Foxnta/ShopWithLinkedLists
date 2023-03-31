#ifndef User_H
#define User_H

#include <string>
#include <iostream>
using namespace std;

class User
{
public:
    string Menu;

public:
    string getMenu();
};

string User::getMenu()
{
    return Menu;
}

#endif // User_H
