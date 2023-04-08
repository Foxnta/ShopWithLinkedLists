#ifndef ARTICLE_H
#define ARTICLE_H


#include <string>
#include <iostream>
using namespace std;

class Article
{
public:
    string name;
    int id;
    float price;
    int quantity;
    string type;

public:
    void showArticle();
};

void Article::showArticle()
{
    cout << "Nombre: " << name << " / ";
    cout << "ID: " << id << " / ";
    cout << "Price: " << price << " / ";
    cout << "Quantity: " << quantity << " / ";
    cout << "Type: " << type << endl;
}

class SportArticle : public Article
{
public:
    SportArticle(string, int, float, int, string);
};

SportArticle::SportArticle(string _name, int _id, float _price, int _quantity, string _type) : Article{_name, _id, _price, _quantity, _type}
{
    name = _name;
    id = _id;
    price = _price;
    quantity = _quantity;
    type = _type;
}


class TechnologyArticle : public Article
{
public:
    TechnologyArticle(string, int, float, int, string);
};

TechnologyArticle::TechnologyArticle(string _name, int _id, float _price, int _quantity, string _type) : Article{_name, _id, _price, _quantity}
{
    name = _name;
    id = _id;
    price = _price;
    quantity = _quantity;
    type = _type;
}


class ForeignArticle : public Article
{
public:
    float impuesto = 0.1;
    ForeignArticle(string, int, float, int, string);
};

ForeignArticle::ForeignArticle(string _name, int _id, float _price, int _quantity, string _type) : Article{_name, _id, _price, _quantity}
{
    name = _name;
    id = _id;
    price = _price;
    quantity = _quantity;
    type = _type;
}

#endif // ARTICLES_COORDINATOR_H