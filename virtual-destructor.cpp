#include <iostream>
using namespace std;

class Base
{
public:
    Base() { cout << "Base Constructor" << endl; }
    virtual ~Base() { cout << "Base Destructor" << endl; }
};

class Derived : public Base
{
public:
    Derived() { cout << "Derived Constructor" << endl; }
    ~Derived() { cout << "Derived Destructor" << endl; }
};

int main()
{
    Base *bPtr = new Derived();
    delete bPtr;
    return 0;
}
