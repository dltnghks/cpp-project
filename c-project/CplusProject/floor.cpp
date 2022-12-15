#include "floor.h"
string Floor::get_floor() {
	return this->floor;
}
void Floor::print_myfloor() {
	Screen::print("현재 "+get_floor()+"입니다.");
	Screen::print("현 위치 : " + get_name());
}