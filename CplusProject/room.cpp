#include <iostream>
#include <string>

using namespace std;

#include "room.h"
#include "screen.h"
#include "player.h"

// set 값 세팅
// 현재 방의 링크 방 설정
void Room::set_link_room(Room* link) {
	if (this->link_rooms == NULL) { cout << "링크 방 사이즈 세팅이 안되어있습니다!" << endl; }
	for (int i = 0; i < this->link_size; i++) {
		if (this->link_rooms[i] == link)
			return;
	}
	this->link_rooms[this->link_size++] = link;
	link->parent = this; // 링크방의 부모를 현재 방으로 설정
}
// 현재 방의 링크 방 사이즈 설정
void Room::set_link_size(int size) {
	this->link_rooms = new Room * [size];
}

// get 값 얻기
// 현재 방 이름 얻기
string Room::get_name() {
	if (this != NULL) {
		return this->name;
	}
	return "false";
}
// 현재 방 링크 사이즈 얻기
int Room::get_link_size() {
	return this->link_size;
}
// 현재 방 링크 방 인덱스로 얻기 ( 인덱스가 사이즈를 벗어나는 경우 "error"를 리턴
string Room::get_link_room(int index) {
	// 인덱스를 벗어나면 "error"를 반환
	if (index >= this->link_size + 1 || index < 0) {
		cout << "인덱스가 잘못입력되었습니다." << endl;
		return "error";
	}
	else {
		if (index == this->link_size)
			return this->parent->get_name();
		return (*(link_rooms[index])).get_name();
	}
}
// 현재 방의 부모 방 얻기
string Room::get_parent_room() {
	if (this->parent != NULL) {
		return this->parent->get_name();
	}
	cout << "부모노드가 없는데 가져가려고 함." << endl;
}

// check 여부 확인
// 현재 방의 링크 룸에 해당 방이 있는지 확인
bool Room::check_link_room(Room* room) {
	if (room == this->parent) return true;
	for (int i = 0; i < this->link_size; i++) {
		if (this->link_rooms[i] == room) return true;
	}
	return false;
}
// 현재 방의 부모 방이 있는지 확인 (없으면 false)
bool Room::check_parent_room() {
	if (this->parent != NULL) return true;
	return false;
}

void Room::print_myfloor() {
	Screen::line_print("현재 1층입니다.");
	Screen::line_print("현 위치 : " + get_name());
}

/*
"총기함실", "인사과", "지휘통제실",
"군수과", "대대장실", "주임원사실", "통신물자 창고",
"1층 중앙복도"
"1-1", "1-2", "1-3", "2-1", "2-2", "2-3", "2층 서편",
"2층 중앙복도",
"2층 동편", "화장실" , "세탁실", "격리 생활관", "2중대 행정반", "통신물자 창고"
*/

