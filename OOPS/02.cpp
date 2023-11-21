#include <iostream>
#include<string.h>
using namespace std;

class Hero
{

public:
    int health;
    char level;
    char *name = new char[100];
    // char name[100];
    static int count;

    Hero()
    {
        cout << "Constructor called\n";
        
    }
    Hero(int h, char l,char n[])
    {
        health = h;
        level = l;
        strcpy(name,n);
    }

    Hero(Hero &temp)
    {
        char *ch = new char[strlen(temp.name)];
        strcpy(ch,temp.name);
        this->health = temp.health;
        this->level = temp.level;
        this->name = ch;
        cout << "\ncopy constructor called";
    }

    void display() { cout << "\nHealth = " << health << " Level = " << level<<" name = "<<name<<endl; }


    void staticFunc(){ cout<<count; }
};


int Hero :: count  = 100;

int main()
{
    cout << "---------------------------\n";
    // char name[5] = "ravi";
    // Hero ravi(10, 'A',name);
    // ravi.display();

    // Hero saurav(ravi);
    // saurav.display();

    // ravi.name[1] = 'O';
    // ravi.display();
    // saurav.display();

    // copy assigmemnt
    // char name[5] = "ravi";
    // Hero a(10,'A',name);
    // a.display();

    // char name2[7] = "saurav";
    // Hero b(20,'B',name2);
    // b.display();
    // a = b;
    // a.display();


    // static---
    // cout<<count;
    // Hero a;
    // a.staticFunc();
    cout<<Hero::count;

    cout << "\n---------------------------\n";
}