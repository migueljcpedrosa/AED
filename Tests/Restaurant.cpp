#include "Restaurant.h"

void Restaurant::insertOrder(Order* order) {
    orders.push(order);
}

void Restaurant::removeFrontOrder() {
    orders.pop();
}

const string &Restaurant::getName() const {
    return name;
}

float Restaurant::getRating() const {
    return rating;
}

const queue<Order *> &Restaurant::getOrders() const {
    return orders;
}


//=============================================================================

//TODO
void Restaurant::removeOrder(string client, string orderNumber) {
    int queueOrdersSize = orders.size();
    int counter = 0;

    while (counter < queueOrdersSize)
    {
        if (orders.front()->getClient() == client && orders.front()->getOrderNumber() == orderNumber)
        {
            orders.pop();
        }
        else
        {
            orders.push(orders.front());
            orders.pop();
        }
        counter++;
    }
}
