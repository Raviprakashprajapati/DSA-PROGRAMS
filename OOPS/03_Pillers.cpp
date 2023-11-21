#include <iostream>
using namespace std;

class Human
{
protected:
    int height;

public:
    int weight;

    int getHeight() { return this->height; }
    int getWeight() { return this->weight; }
    int setHeight(int h) { this->height = h; }
    int setWeight(int w) { this->weight = w; }
};

class Male : public Human
{
public:
    int color;

    void sleep() { cout << "Male sleeping\n"; }

    void display() { cout << this->height << "  " << this->weight; }
};

int main()
{

    Male ravi;
    ravi.sleep();
    ravi.setHeight(45);
    ravi.setWeight(100);
    ravi.display();
    // ravi.height = 120;
    // cout<<ravi.getHeight();

    return 0;
}