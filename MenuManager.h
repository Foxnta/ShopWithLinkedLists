#ifndef MenuManager_H
#define MenuManager_H

#include <string>
#include <iostream>
using namespace std;

class MenuManager{
public:
    char selectUser();
    void showMenu(User);
    int getAnswer();
};

char MenuManager::selectUser()
{
    char user;
    do
    {
        cout << "Seleccione su usuario: " << endl;
        cout << "Admin (A) o Cliente (C)" << endl;
        cin >> user;
        if (user != 'A' && user != 'C')
        {
            cout << "Opcion no valida. Por favor seleccione A o C." << endl;
        }
    } while (user != 'A' && user != 'C');

    if (user == 'A')
    {
        return 'A';
    }
    
    return 'C';
}

void MenuManager::showMenu(User user){
    cout << user.getMenu() << endl;
}

int  MenuManager::getAnswer(){
    int valor;
    cout << "Opcion: " << endl;
    cin >> valor; 
    return valor;
}


#endif // MenuManager_H