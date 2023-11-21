// #include<iostream>
// using namespace std;

// class Ravi{
//     private:
//     int salary;

//     public:
//     Ravi(int s){ salary = s; }
//     void display(){ cout<<"salary = "<<salary<<endl; }
//     friend class Saurav;
// };

// class Saurav{
//     private:
//     int height;
//     public:
//     Saurav(int height){ this->height=height;}
//     void display(Ravi &temp){
//         cout<<"salary  = "<<temp.salary<<endl;
//         cout<<"height  = "<<height<<endl;
        
//      }
// };

// int main(){
//     Ravi r(120);
//     Saurav s(24);
//     s.display(r);
    
// }


















// Frined funciton

#include<iostream>
using namespace std;

class Base{
    private:
    int a;
    public:
    Base(int a){ this->a=a; }

    friend void friendFunction(Base &temp);

};


 void  friendFunction(Base &temp){
    cout<<"a = "<<temp.a<<endl;
 }

 int main(){
    Base b(100);
    friendFunction(b);
 }