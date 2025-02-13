#include "email_notification.hpp"
#include "wtsp_notification.hpp"
#include <iostream>
using namespace std;

class NotificationFactory{

    public:
        static Notification* createNotificationInstance(string input);
};

