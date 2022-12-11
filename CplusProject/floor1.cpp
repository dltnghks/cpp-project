#include "room.h"
#include "floor1.h"

void Floor1::print_myfloor() {
	Screen::print("현재 1층입니다.");
	Screen::print("현 위치 : " + get_name());
}