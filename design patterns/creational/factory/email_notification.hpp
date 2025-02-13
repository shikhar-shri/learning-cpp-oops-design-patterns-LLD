#include "notification.hpp"
#include <iostream>
using namespace std;

class EmailNotification: public Notification{
    public:
        void sendNotification();
};