#include "room.h"
#include "rooftop.h"

void Rooftop::print_myfloor() {
	Screen::print("현재 옥상입니다.");
	Screen::line_print("현 위치 : " + get_name());
}