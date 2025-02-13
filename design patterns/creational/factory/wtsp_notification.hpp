#include "notification.hpp"
#include <iostream>
using namespace std;

class WhatsAppNotification:public Notification{
    public:
        void sendNotification();
};