#ifndef _CAR_H
#define _CAR_H
#include "vehicle.h"
// Q1a: Create Car class (5 points)
// Part 1: Create a child class of the Vehicle class named 'Car'
class Car : public Vehicle {
	
    // Part2: Declare constructor which accepts the same 3 parameters as the parent class Vehicle's constructor.
    // Pass the 3 parameters to the super constructor of the Vehicle class.

    public:
        Car(string id, string owner, vehicleType type);

        // Part 3: Re-declare the method displayVehicle (virtual method found inside of parent class Vehicle)
        void displayVehicle() override;

};



#endif // _CAR_H