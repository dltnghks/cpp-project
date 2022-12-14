#pragma once
#include "room.h"

class Floor : public Room {
	string floor;
public:
	Floor(string floor, string room):Room(room) {
		this->floor = floor;
	}
	string get_floor();
	virtual void print_myfloor();
};