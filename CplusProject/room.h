#pragma once
#include <iostream>
#include <string>
#include "screen.h"

using namespace std;

/******************************************

			방에 대한 정보들

*******************************************/

class Room {
protected:
	string name;		//방 이름
	Room** link_rooms; //이동가능한 방
	Room* parent;	// 부모 방
	int link_size;	// 연결된 방의 수
public:
	// 방 이름 셋팅
	Room() : Room("None") {}
	Room(string name) {
		this->name = name;
		this->link_size = 0;
		this->link_rooms = NULL;
		this->parent = NULL;
	}

	// get
	string get_name();	// 방 이름 얻기
	int get_link_size(); // 이동가능한 방 사이즈 얻기
	string get_link_room(int index); // 이동가능한 방 얻기
	string get_parent_room();	// 부모 방 얻기

	// set
	void set_link_size(int size);	// 연결된 방 크기 세팅
	void set_link_room(Room* link); // 방 연결하기

	// check
	bool check_link_room(Room* room); // 방 연결되어 있는지 확인
	bool check_parent_room(); // 부모 방이 있는지 확인

	virtual void print_myfloor(); // 맵 print할 때 현 위치 출력
};



