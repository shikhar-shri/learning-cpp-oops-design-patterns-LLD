#include <iostream>
#include <memory>
#include <vector>
#include <string>
using namespace std;

// **Observer Interface (Traders & AI Bots)**
class IObserver {
    public:
        virtual ~IObserver() = default;
        virtual void update(float price,string stockName) = 0;
 };

 // **Concrete Observer: Trader**
class Trader : public IObserver {
    private:
        std::string name;
    public:
        Trader(const std::string& name) : name(name) {}
    
        void update(float price,string stockName) override {
            std::cout << "Trader " << name << " notified: Stock price of "<< stockName << "updated to Rs." << price << "\n";
        }
};

// **Concrete Observer: AI Bot**
class AIBot : public IObserver {
    public:
        void update(float price,string stockName) override {
            std::cout << "AI Bot detected price change: $" << price << "in stock:" <<stockName <<endl;
        }
};

// **Subject (Stock)**
class Stock {
    private:
        std::vector<std::shared_ptr<IObserver>> observers;
        float price;
        string name = "Apple";
    
    public:
        void addObserver(std::shared_ptr<IObserver> observer) {
            observers.push_back(observer);
        }
    
        void setPrice(float newPrice) {
            price = newPrice;
            notifyObservers();
        }
    
        void notifyObservers() {
            for (const auto& observer : observers) {
                observer->update(price,name);
            }
        }
    };
    

int main(){
    Stock appleStock;

    // Create Observers (Traders & AI Bots)
    auto trader1 = std::make_shared<Trader>("Alice");
    auto trader2 = std::make_shared<Trader>("Bob");
    auto aiBot = std::make_shared<AIBot>();

    // Register Observers
    appleStock.addObserver(trader1);
    appleStock.addObserver(trader2);
    appleStock.addObserver(aiBot);

    // Update stock price (Triggers notifications)
    appleStock.setPrice(150.75);
    appleStock.setPrice(155.30);

    return 0;
}