#pragma once
#include "room.h"

class Floor1 : public Room {
public:
	Floor1() : Room("None") {}
	Floor1(string name) : Room(name) {}

	virtual void print_myfloor();
};