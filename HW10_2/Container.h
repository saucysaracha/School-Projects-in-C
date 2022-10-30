#ifndef _CONTAINER_H_
#define _CONTAINER_H_

#include "vehicle.h"

class Container {
public:
	Vehicle* vehicle;
	Container* next;
	Container();			// constructor
};

#endif // _CONTAINER_H_