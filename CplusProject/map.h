#pragma once
#include <map>
#include <string>
#include <iostream>
#include <typeinfo>
#include <windows.h>
#include <vector>

#include "define.h"
#include "room.h"
using namespace std;

/************************************************************************************

						맵에 대한 정보들(방들의 집합 느낌)

************************************************************************************/

class Map {
	//int size; // 사이즈 ( 방 개수 )
	//Room* list[ROOMSIZE1 + ROOMSIZE2]; // 방 리스트 (1층 방 개수 + 2층 방 개수)
	vector<Room*> list;

public:
	// set
	void set();			// 방, 연결된 방 셋팅
	void set_link_rooms(Room* room1, Room* room2);//이동가능한 방 셋팅

	// get
	Room* find_room(string name); // 방 찾기

	// 방 추가
	void insert_list(Room* room); // 리스트에 방넣기

	// 출력
	void print_map();	// 맵 출력
};



/*
* 방 리스트
*
* 리스트에 방 넣기
* 리스트에 방 빼기
* 방 연결
* 맵 출력
*/