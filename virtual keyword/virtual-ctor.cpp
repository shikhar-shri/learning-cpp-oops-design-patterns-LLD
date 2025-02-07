#include <iostream>
using namespace std;

// Step 1: Define Base Class
class Base {
public:
    virtual void show() { cout << "Base class" << endl; }

    // Step 2: Declare Static Factory Method
    static Base* create();  

    virtual ~Base() {}  // Virtual destructor
};

// Step 3: Define Derived Class
class Derived : public Base {
public:
    void show() override { cout << "Derived class" << endl; }

    // Step 4: Define Factory Method in Derived Class
    static Base* create() { return new Derived(); }
};

// Step 5: Implement Factory Method in Base Class
Base* Base::create() {
    return new Derived();  // Could be extended to return different objects
}

// Step 6: Client Code
int main() {
    Base* obj = Base::create();  // Calls Derived's factory method
    obj->show();  // Output: "Derived class"
    delete obj;  // Clean up memory
    return 0;
}
