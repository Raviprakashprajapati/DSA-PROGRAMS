#include<iostream>
using namespace std;

class Hero{

    int health;
    public:
    int level;

    int getHealth(){ return health; }
    int getLevel(){ return level; }
    void setHealth(int h){ health = h; }

    Hero(){
        cout<<"Constructor called\n";
    }

    Hero(int health,int level){
        this->health = health;
        this->level = level;
    }
};

int main(){
    cout<<"-----------------------"<<endl;

    // STATIC
    Hero ravi(11,10);
    cout<<ravi.getHealth()<<endl;
    cout<<ravi.getLevel()<<endl;

    // dynamic
    Hero *saurav = new Hero(44,45);
    // (*saurav).level = 600;
    cout<<saurav->getHealth()<<endl;
    cout<<saurav->getLevel()<<endl;

    // ravi.health = 100;
    // ravi.level = 50;
    // // cout<<&ravi<<endl;
    // // cout<<sizeof(ravi)<<endl;
    // // cout<<ravi.health<<endl;
    // ravi.setHealth(100);
    // // cout<<ravi.getHealth()<<endl;
    // cout<<"HEALTH = "<<ravi.getHealth()<<endl;
    // cout<<"LEVEL = "<<ravi.level;

  
    cout<<"\n-----------------------"<<endl;
}



// Class:

// In object-oriented programming, a class is a blueprint or template for creating objects.
// It defines the structure and behavior of objects, including their attributes (data members) and methods (functions).
// Objects are instances of a class, and each object created from a class has its own unique set of attributes and can perform actions defined in the class's methods.
// Object:

// An object is a real-world entity that is created from a class. It is an instance of a class.
// Objects have state (attributes) and behavior (methods) defined by their class.
// They can interact with each other by invoking methods and accessing attributes of other objects.
// this:

// this is a keyword in many object-oriented programming languages, including C++.
// It is a reference to the current object within a class's member functions.
// It is used to differentiate between the local variables (parameters) and the class's data members that have the same name.
// By using this, you can access or modify the current object's attributes and call its methods.
// Constructor:

// A constructor is a special member function in a class that is automatically called when an object is created.
// It is used to initialize the object's data members or perform any setup tasks necessary for the object to be in a valid state.
// Constructors have the same name as the class and do not have a return type (not even void).
// There are two types of constructors: default constructor (takes no arguments) and parameterized constructor (takes one or more arguments).