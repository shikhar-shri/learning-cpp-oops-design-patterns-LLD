#include "notification_factory.hpp"

Notification* NotificationFactory::createNotificationInstance(string input){
    Notification *notification;
    if(input == "email"){
        notification = new EmailNotification();
    }else if(input == "whatsapp" || input == "wtsp"){
        notification = new WhatsAppNotification();
    }

    return notification;
}