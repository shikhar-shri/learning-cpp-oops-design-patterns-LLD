#include <iostream>
#include <cstring>
#include <stdexcept>
using namespace std;

class String{

public:

    String() : res(nullptr), len(0){}
    String(const char* ch);
    String(const String& str);
    String(String&& str);
    
    String& operator=(const String& str);
    char operator[](int index);
    friend ostream& operator<<(ostream& out, String& str);
    friend istream& operator>>(istream& in, String& str);
    
    unsigned int length();
    
    ~String();

private:

    char* res;
    unsigned int len;

};

ostream& operator<<(ostream& out, String& str){
    
    out<<str.res;
    return out;

}

istream& operator>>(istream& in, String& str){
    
    in>>str.res;
    return in;

}

String::String(const char* ch){ //parameterized ctor
    len=strlen(ch);
    res= new char[len + 1];
    strcpy(res,ch);
}

String::String(const String& str){ //copy ctor
    cout<<"copy ctor called\n";
    this->len = str.len;
    this->res = new char[(this->len) + 1];
    strcpy(this->res,str.res);
} 

String& String::operator=(const String& str){ //copy assignment operator
    
    if(this!=&str){

        char* temp = this->res;
        
        //copy the contents
        this->len=str.len;
        this->res=new char[(this->len)+1];
        strcpy(this->res,str.res);
        delete[] temp;
    }
    return *this;
}

String::String(String&& str){//move ctor
    
    cout<<"move ctor called\n";
    this->res=str.res;
    this->len=str.len;

    str.len=0;
    str.res=nullptr;
}

unsigned int String::length(){
    return len;
}

char String::operator[](int index){
    if(index<0 || index>=this->len){
        throw std::out_of_range("Index out of string's range!");
    }

    return (this->res)[index];
}

String::~String(){ //destructor implementation
    
    if(res){
        delete[] res;
        res=nullptr;
        len=0;
    }
    
    
}

int main(){

    // String str; //default constructor

    // String str1("Hello"); //parameterized constructor
    // cout<<str1<<endl;

    // str = str1;
    // cout << str.length() << endl;

    String str2 = "World"; //parameterized constructor
    // String str3 ="Shikhar!"; //param ctor

    // String str2 = str1; //copy constructor
    // str3=str2; //copy assignment operator

    // int len = str1.length(); //returns the length of the string

    // cout<<str1[0]; //returns the character at the given index
    // cout<<str1; //prints the string (overloading << operator)

    // cin>>str; //takes the input string (overloading >> operator)

    String str3 = std::move(str2); //move resources into str and str3 dies
    cout << str3 << endl;

    return 0;
}