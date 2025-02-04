#include <iostream>
using namespace std;

class A
{
public:
    virtual void foo() { cout << "A::foo" << endl; }
};

class B
{
public:
    virtual void bar() { cout << "B::bar" << endl; }
};

class C : public A, public B
{
public:
    void foo() override { cout << "C::foo" << endl; }
    void bar() override { cout << "C::bar" << endl; }
};

int main()
{
    C obj;
    A *aPtr = &obj;
    B *bPtr = &obj;

    aPtr->foo(); // ✅ Calls C::foo()
    bPtr->bar(); // ✅ Calls C::bar()
    // bPtr->foo();
}

/*

Assuming C's memory layout is:

Address	Data
1000	vptr for A
1008	Other A members
1016	vptr for B
1024	Other B members
aPtr (of type A*) points to 1000.
bPtr (of type B*) should point to 1016.
dynamic_cast<B*>(aPtr) knows the offset between A and B subobjects and adjusts the pointer correctly.
🔹 What Happens Internally?
When dynamic_cast<B*>(aPtr) is executed:

It checks the type of the actual object (C) at runtime.
It computes the correct memory offset to get the B subobject inside C.
It returns the correct pointer (pointing to 1016 instead of 1000).
If the conversion is not valid, it returns nullptr safely.
🔹 Summary
Casting Method	Behavior
(B*)aPtr;	❌ Unsafe – May crash because it does not adjust the pointer correctly.
dynamic_cast<B*>(aPtr);	✅ Safe – Performs runtime check and adjusts pointer properly.

*/