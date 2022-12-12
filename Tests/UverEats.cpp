#include "UverEats.h"

UverEats::UverEats() {}

void UverEats::addClient(Client client){
    clients.push_back(client);
}

void UverEats::addRestaurant(Restaurant restaurant) {
    restaurants.push_back(restaurant);
}

vector<Client> UverEats::getClients() const {
    return clients;
}

const list<Restaurant> &UverEats::getRestaurants() const {
    return restaurants;
}

void UverEats::addDriver(Driver driver) {
    drivers.insert(driver);
}

const set<Driver> &UverEats::getDrivers() const {
    return drivers;
}

//=============================================================================

//TODO
bool lessThan(Client &c1, Client &c2)
{
    if (c1.getSeniority() == c2.getSeniority())
    {
        return c1.getName() < c2.getName();
    }
    return c1.getSeniority() > c2.getSeniority();
}

void UverEats::sortClients() {
    std::sort(clients.begin(), clients.end(), lessThan);
}


//TODO
float UverEats::averageRestaurantRating(int numMinOrders) const {
    float average = 0.0;
    float sum = 0.0;
    float numObs = 0.0;

    for (auto &restaurant : restaurants)
    {
        if (restaurant.getOrders().size() > numMinOrders)
        {
           sum += restaurant.getRating();
           numObs += 1.0;
        }
    }

    if (numObs == 0.0)
    {
        return 0.0;
    }

    average = sum / numObs;

    return average;
}


//TODO
void UverEats::removeRestaurants(float minRating) {
    auto restaurantIterator = restaurants.begin();

    while (restaurantIterator != restaurants.end())
    {
        if (restaurantIterator->getRating() < minRating)
            restaurantIterator = restaurants.erase(restaurantIterator);
        else
            restaurantIterator++;
    }
}


//TODO
vector<Driver> UverEats::getDriversWithOrders(int numOrders) const {
    vector<Driver> result;

    for (auto &driver : drivers)
    {
        if (driver.getToDeliver().size() < numOrders)
        {
            result.push_back(driver);
        }
    }

    return result;
}


//TODO:

void UverEats::createRestaurantBranch(string restMain, string restBranch) {
    Restaurant restaurantBranch = Restaurant(restBranch);
    for (auto &restaurant : restaurants)
    {
        if(restaurant.getName() == restMain)
        {
            int counter = 1;
            int queueSize = restaurant.getOrders().size();

            while (counter <= queueSize)
            {
                if (counter%2 == 0)
                {
                    restaurantBranch.insertOrder(restaurant.getOrders().front());
                    restaurant.removeFrontOrder();
                    counter++;
                }
                else
                {
                    restaurant.insertOrder(restaurant.getOrders().front());
                    restaurant.removeFrontOrder();
                    counter++;
                }
            }
            break;
        }
    }

    restaurants.push_back(restaurantBranch);
}