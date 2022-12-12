#include "Driver.h"

Driver::Driver(unsigned int idDriver, const string &nameDriver) : driverId(idDriver), driverName(nameDriver) {}

unsigned int Driver::getIdDriver() const {
    return driverId;
}

const string &Driver::getNameDriver() const {
    return driverName;
}

const stack<Order> &Driver::getToDeliver() const {
    return toDeliver;
}

void Driver::insertOrder(Order order) {
    toDeliver.push(order);
}

//=============================================================================

// TODO
bool Driver::operator<(const Driver &d1) const {
    if(this->getToDeliver().size() == d1.getToDeliver().size())
    {
        return this->getIdDriver() < d1.getIdDriver();
    }
    return this->getToDeliver().size() > d1.getToDeliver().size();
    return true;
}

// TODO
vector<string> Driver::checkCommonClients(const Driver &d2) {
    vector<string> result;
    stack<Order> thisStackCopy = this->toDeliver;
    stack<Order> d2StackCopy = d2.toDeliver;
    stack<Order> d2AuxStack;

    while (!thisStackCopy.empty())
    {
        while (!d2StackCopy.empty())
        {
            if (thisStackCopy.top().getClient() == d2StackCopy.top().getClient())
            {
                result.push_back(thisStackCopy.top().getClient());
            }
            d2AuxStack.push(d2StackCopy.top());
            d2StackCopy.pop();
        }

        while (!d2AuxStack.empty())
        {
            d2StackCopy.push(d2AuxStack.top());
            d2AuxStack.pop();
        }
        thisStackCopy.pop();
    }
    return result;
}

