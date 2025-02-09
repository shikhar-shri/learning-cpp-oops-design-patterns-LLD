#include <iostream>
using namespace std;

template <typename T>
class UniquePtr{

    public:
        UniquePtr(T* a = nullptr){
            cout << "ctor called\n";
            res = a;
        }

        UniquePtr(const UniquePtr<T> &ptr) = delete;
        UniquePtr<T>& operator=(const UniquePtr<T> &ptr) = delete;

        UniquePtr<T> &operator=(T *a){
            cout << "copy = operator called\n";
            res = a;
            return *this;
        }

        UniquePtr(UniquePtr<T> &&ptr)
        {
            cout << "move ctor called\n";
            res = ptr.res;
            ptr.res = nullptr;
        }

        T& operator*(){
            if(res)
                return *res;
        }

        ~UniquePtr(){
            cout << "dtor called\n";
            if(res){
                delete res;
                res = nullptr;
            }
        }

    private:
        T* res;
};



int main(){

    UniquePtr<int> ptr1;
    ptr1 = new int(100);
    // UniquePtr<int> ptr2(ptr1); //ensure exclusive ownership of int . So throw a compilation error
    // UniquePtr<int> ptr3 = ptr2; //compilation error
    // UniquePtr<int> ptr4(new int(200));
    // ptr4 = ptr1; //compilation error

    UniquePtr<int> ptr4 = std::move(ptr1); //valid, move ctor
    //ptr1 will no longer point to its resource

    cout<<*ptr4<<endl; //200

    return 0;
}