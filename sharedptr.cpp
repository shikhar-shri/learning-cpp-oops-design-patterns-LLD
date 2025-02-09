#include <iostream>
using namespace std;

template <typename T>
class Sharedptr{

    public:
        Sharedptr(){
            cout << "default ctor called\n";
            res = nullptr;
            ref_count = new unsigned int(0); 
        }

        Sharedptr(T* a){
            cout << "param ctor called\n";
            res = a;
            ref_count = new unsigned int(1); //this is the 1st reference
        }

        Sharedptr(const Sharedptr<T>& ptr){
            cout << "copy ctor called\n";
            res = ptr.res;
            ref_count = ptr.ref_count;
            increment_ref_count();
        }

        Sharedptr<T>& operator=(const Sharedptr<T>& ptr){
            /*
                1. handle the case if the current ref count is 1
            */
            cout << "copy = operator called\n";
            decrement_ref_count();
            // if(*ref_count == 1){
            //     //if it was the last reference
            //     delete res;
            //     res = nullptr;
                
            //     delete ref_count;
            //     ref_count = nullptr;
            // }
            // else{
            //     //decrement the curr ref count
            //     (*ref_count)--;
            // }
            
            
            
            res = ptr.res;
            ref_count = ptr.ref_count;

            increment_ref_count();

            return *this;
        }

        unsigned int get_ref_count(){
            return *ref_count;
        }

        T& operator*(){
            return *res;
        }

        ~Sharedptr(){
            // if(*ref_count == 1){
            //     delete res;
            //     res = nullptr;

            //     delete ref_count;
            //     ref_count = nullptr;
            // }
            // else{
            //     (*ref_count)--;
            // }
            decrement_ref_count();
        }

    private:
        T *res;
        unsigned int* ref_count;
        void increment_ref_count(){
            (*(this->ref_count))++;
        }

        void decrement_ref_count(){
            unsigned int *ptr = this->ref_count;
            
            if(*ptr != 0)
                (*ptr)--;

            if(*ptr == 0){
                delete res;
                delete ref_count;

                res = nullptr;
                ref_count = nullptr;
            }
        }
};

int main(){

    // Sharedptr<int> ptr1 = new int(100); //param ctor
    // Sharedptr<int> ptr2(new int(20)); //param ctor
    // Sharedptr<int> ptr3(ptr2); //copy ctor

    // ptr1 = ptr3;

    // cout << ptr2.get_ref_count() << endl; //returns how many current references are there pointing to the resource to which the current pointer is pointing

    Sharedptr<char> ptr4; //default ctor
    ptr4 = new char('a'); //copy = operator

    cout << ptr4.get_ref_count() << endl;
    ;

    // ptr1 = ptr3; //copy = operator
    // cout << *ptr1 << *ptr2 << *ptr3 << endl; //overload * operator
    cout << *ptr4;
    return 0;
}
