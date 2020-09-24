
#ifndef TESTE_2017_GARAGE_H
#define TESTE_2017_GARAGE_H


#include <vector>
#include <string>
#include <algorithm>

using namespace std;

template <class Vehicle>
class Garage {
    vector<Vehicle *> vehicles;
    const unsigned int capacity;
public:
    Garage(int size);
    ~Garage();
    vector<Vehicle *> getVehicles() const;
    void setVehicles(vector<Vehicle *> vehicles);
    int getCapacity() const;
    bool addVehicle(Vehicle *vehicle);
    Vehicle* removeVehicle(string brand, string model);
    float avgPrice(string brand) const;
    void sortVehicles();
};

class NoSuchVehicleException {
public:
    NoSuchVehicleException() { }
};

class NoSuchBrandException {
    string brand;
public:
    NoSuchBrandException(const string &brand);
    string getBrand() const;
};

template <class Vehicle>
Garage<Vehicle>::Garage(int size) : capacity(size) {
}

template <class Vehicle>
Garage<Vehicle>::~Garage() {
    typename vector<Vehicle *>::const_iterator it;
    for (it=vehicles.begin(); it!=vehicles.end(); it++) {
        delete *it;
    }
}

template<class Vehicle>
std::vector<Vehicle *> Garage<Vehicle>::getVehicles() const {
    return vehicles;
}

template<class Vehicle>
void Garage<Vehicle>::setVehicles(vector<Vehicle*> vehicles) {
    this->vehicles = vehicles;
}

template<class Vehicle>
int Garage<Vehicle>::getCapacity() const {
    return capacity;
}

template<class Vehicle>
bool Garage<Vehicle>::addVehicle(Vehicle *vehicle) {
    if (vehicles.size() >= capacity)
        return false;
    for (auto &x: vehicles) {
        if (*x == *vehicle)
            return false;
    }
    vehicles.push_back(vehicle);
    return true;
}

template<class Vehicle>
bool compareVehicle(Vehicle* v1, Vehicle* v2) {
    if (v1->getBrand() == v2->getBrand())
        return v1->getPrice > v2->getPrice();
    return v1->getBrand() < v2->getBrand();
}


template<class Vehicle>
void Garage<Vehicle>::sortVehicles() {
    sort(vehicles.begin(), vehicles.end(), compareVehicle<Vehicle>);
}

template<class Vehicle>
Vehicle *Garage<Vehicle>::removeVehicle(string brand, string model) {
    typename vector<Vehicle *>::iterator it;
    for (it = vehicles.begin(); it != vehicles.end(); it++) {
        if (((*it)->getBrand() == brand) && ((*it)->getModel() == model)) {
            Vehicle *v = *it;
            vehicles.erase(it);
            return v;
        }
    }
    throw NoSuchVehicleException();
}


template<class Vehicle>
float Garage<Vehicle>::avgPrice(string brand) const {
    float total = 0;
    unsigned int counter = 0;
    for (auto &x: vehicles) {
        if (x->getBrand() == brand) {
            total += x->getPrice();
            counter++;
        }
    }
    if (counter > 0)
        return total / counter;
    throw NoSuchBrandException(brand);
}


#endif //TESTE_2017_GARAGE_H
