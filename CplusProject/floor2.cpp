#include "room.h"
#include "floor2.h"

void Floor2::print_myfloor() {
	Screen::print("현재 2층입니다.");
	Screen::line_print("현 위치 : " + get_name());
}