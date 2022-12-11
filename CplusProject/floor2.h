#pragma once
#include "room.h"

class Floor2 : public Room {
public :
	Floor2() : Room("None") {}
	Floor2(string name) : Room(name) {}

	virtual void print_myfloor();
};