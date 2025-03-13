#include <iostream>
#include <memory>
using namespace std;

class IButton{
    public:
        virtual void press() = 0;
};

class WindowsButton: public IButton{
    public:
        void press(){
            cout << "Windows btn pressed\n";
        }
};

class MacButton: public IButton{
    public:
        void press(){
            cout << "Mac btn pressed\n";
        }
};

class ITextBox{
    public:
       virtual void write(string msg) = 0;
};

class WindowsTextBox: public ITextBox{
    public:
        void write(string msg){
            cout << msg << " written on windows text box\n";
        }
};

class MacTextBox: public ITextBox{
    public:
     void write(string msg){
         cout << msg << " written on mac text box\n";
     }
};

class IFactory{
    public:
        virtual unique_ptr<IButton> CreateButton() = 0;
        virtual unique_ptr<ITextBox> CreateTextBox() = 0;
};

class WindowsFactory: public IFactory{
    public:
        unique_ptr<IButton> CreateButton(){
            return make_unique<WindowsButton>();
        }
        unique_ptr<ITextBox> CreateTextBox(){
            return make_unique<WindowsTextBox>();
        }
};

class MacFactory: public IFactory{
    public:
        unique_ptr<IButton> CreateButton(){
            return make_unique<MacButton>();
        }
        unique_ptr<ITextBox> CreateTextBox(){
            return make_unique<MacTextBox>();
        }
};

class GUIAbstractFactory{
    public: 
    static unique_ptr<IFactory> CreateFactory(string osType){
        if(osType == "windows"){
            return make_unique<WindowsFactory>();
        }
        else if(osType == "mac"){
            return make_unique<MacFactory>();
        }
    }
};

int main(){
    cout << "Enter your machine's OS: ";
    string osType;
    cin >> osType;

    auto factory = GUIAbstractFactory::CreateFactory(osType);

    auto btn = factory->CreateButton();
    btn->press();

    auto tb = factory->CreateTextBox();
    tb->write("hello");

    return 0;
}