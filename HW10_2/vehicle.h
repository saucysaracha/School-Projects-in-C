#ifndef _VEHICLE_H_
#define _VEHICLE_H_

#include <string>
using namespace std;

enum vehicleType { car = 0, motorcycle };	// definition of vehicleType

class Vehicle {
private:
	string id; // private data members
	string owner;
	vehicleType type;

public:
	Vehicle(string id, string owner, vehicleType type); // constructor

	// accessor methods
	string getId();
	string getOwner();
	vehicleType getVehicleType();

	virtual void displayVehicle()
	{}

	// Q3-a: Declare Friend Function changeOwner()  (1 point)
	// Declare a friend function named changeOwner() which has 2 parameters and no return value.
	// The first parameter is a pointer to Vehicle class, and the second is a string which is the new owner name.
	// You need to define this function in hw10.cpp and call this function in case 'c' of executeAction() in hw10.cpp file
	friend void changeOwner(Vehicle* vehicle, string newOwner);

};

#endif // _VEHICLE_H_