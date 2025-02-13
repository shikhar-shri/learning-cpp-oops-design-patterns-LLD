#include <iostream>
#include "notification_factory.hpp"
using namespace std;



int main(){
    
    string input;
    cout << "Enter notification type (email/wtsp): ";
    cin >> input;

    Notification *notification = NotificationFactory::createNotificationInstance(input);

    notification->sendNotification();

    return 0;
}