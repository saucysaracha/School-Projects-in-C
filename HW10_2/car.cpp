// Q2a: Define displayVehicle() for Car class (5 points)
// Define the function displayVehicle() that you declared within the Car class in the header file
// See expected output in question file.
#include "car.h"
#include "vehicle.h"
#include <iostream>
#include <string>

using namespace std;

Car::Car(string id, string owner, vehicleType type)
    : Vehicle(id, owner, type) 
{

}
// (displayList() function in hw10.cpp should call this function.)
// Include necessary header files

void Car::displayVehicle()
{
    std::cout << "\nRegistration Id: " << getId();
    std::cout << "\nOwner Name: " << getOwner();
    std::cout << "\nThis vehicle is a Car\n" /* << getVehicleType() */ << endl;
}