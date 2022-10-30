#include "vehicle.h"


// definitions of Vehicle member functions

Vehicle::Vehicle(string id_input, string owner_input, vehicleType type_input)
{
	id = id_input;
	owner = owner_input;
	type = type_input;
}


string Vehicle::getId()
{
	return id;
}

string Vehicle::getOwner()
{
	return owner;
}

vehicleType Vehicle::getVehicleType()
{
	return type;
}

//void changeOwner(Vehicle* vehicle, string newOwner)
//{
//	vehicle->owner = newOwner;
//}
//define in hw10.cpp instead