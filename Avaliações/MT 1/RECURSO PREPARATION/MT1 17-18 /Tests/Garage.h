/*
 * Garage.h
 *
 *  Created on: 24/10/2017
 *      Author: hlc
 */

#ifndef SRC_GARAGE_H_
#define SRC_GARAGE_H_

#include <vector>
#include <iostream>
using namespace std;
template <class Vehicle>
class Garage {
	std::vector<Vehicle *> vehicles;
	const unsigned int capacity;
public:
	Garage(int size);
	~Garage();
	std::vector<Vehicle *> getVehicles() const;
	void setVehicles(std::vector<Vehicle *> vehicles);
	int getCapacity() const;
	bool addVehicle(Vehicle *vehicle);
	Vehicle* removeVehicle(std::string brand, std::string model);
	float avgPrice(std::string brand) const;
	void sortVehicles();
};

class NoSuchVehicleException {
public:
	NoSuchVehicleException() { }
};

class NoSuchBrandException {
    string brand;
public:
    string getBrand() const{
        return  brand;
    };
    NoSuchBrandException(string b) : brand(b) {};
};
template <class Vehicle>
Garage<Vehicle>::Garage(int size) : capacity(size) {
}

template <class Vehicle>
Garage<Vehicle>::~Garage() {
	typename std::vector<Vehicle *>::const_iterator it;
	for (it=vehicles.begin(); it!=vehicles.end(); it++) {
		delete *it;
	}
}

template<class Vehicle>
std::vector<Vehicle *> Garage<Vehicle>::getVehicles() const {
	return vehicles;
}

template<class Vehicle>
void Garage<Vehicle>::setVehicles(std::vector<Vehicle*> vehicles) {
	this->vehicles = vehicles;
}

template<class Vehicle>
int Garage<Vehicle>::getCapacity() const {
	return capacity;
}

template<class Vehicle>
bool Garage<Vehicle>::addVehicle(Vehicle *vehicle){
    if(capacity == vehicles.size()){
        return false;
    }
    typename std::vector<Vehicle *>::const_iterator it = vehicles.begin();
    for (it; it != vehicles.end(); it++) {
        if(*(*it) == *vehicle){
            return false;
        }
    }
    vehicles.push_back(vehicle);
    return true;
}
template<class Vehicle>
bool sortRule(Vehicle* lhs, Vehicle* rhs) {
    if ((*lhs).getBrand() == (*rhs).getBrand()) {
        return (*lhs).getPrice() > (*rhs).getPrice();
    }
    else {
        return (*lhs).getBrand() < (*rhs).getBrand();
    }
}

template<class Vehicle>
void Garage<Vehicle>::sortVehicles(){
    sort(vehicles.begin(), vehicles.end(), sortRule<Vehicle>);
}

template<class Vehicle>
Vehicle* Garage<Vehicle>::removeVehicle(std::string brand, std::string model){
    Vehicle *removed;
    typename std::vector<Vehicle *>::const_iterator it = vehicles.begin();
    for (it; it != vehicles.end(); it++) {
        if((*it)->getBrand() == brand && (*it)->getModel() == model){
            removed = *it;
            vehicles.erase(it);
            return removed;
        }
    }
    throw NoSuchVehicleException();
}

template<class Vehicle>
float Garage<Vehicle>::avgPrice(std::string brand) const{
    int cont = 0;
    float priceSum = 0.0;
    typename std::vector<Vehicle *>::const_iterator it = vehicles.begin();
    for (it; it != vehicles.end(); it++){
        if((*it)->getBrand() == brand){
            cont++;
            priceSum += (*it)->getPrice();
        }
    }
    if(cont == 0)
        throw NoSuchBrandException(brand);
    else
        return priceSum/cont;
}

#endif /* SRC_GARAGE_H_ */
