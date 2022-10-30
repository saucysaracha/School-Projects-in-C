#include "motorcycle.h"
#include "vehicle.h"
#include <iostream>
#include <string>

using namespace std;

// Q2-b: Define displayVehicle() for Motorcycle class (5 points)
// Define the function displayVehicle() that you declared within the Motorcycle class in the header file
// See expected output in question file.

// (displayList() function in hw10.cpp should call this function.)
// Include necessary header files

Motorcycle::Motorcycle(string id, string owner, vehicleType type)
    : Vehicle(id, owner, type)
{

}

void Motorcycle::displayVehicle()
{
    std::cout << "\nRegistration Id: " << getId();
    std::cout << "\nOwner Name: " << getOwner();
    std::cout << "\nThis vehicle is a motorcycle\n" /*(vehicleType)getVehicleType()*/ << endl;
}
