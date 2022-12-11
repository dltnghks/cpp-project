#pragma once
#include "room.h"

class Rooftop : public Room {
public:
	Rooftop() : Room("None") {}
	Rooftop(string name) : Room(name) {}

	virtual void print_myfloor();
};

