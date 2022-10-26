#pragma once
#include <iostream>
#include <string>
#include "room.h"
#include "inventory.h"
#include "screen.h"

using namespace std;

/************************************************************************************

						플레이어 정보

************************************************************************************/

class Player {
	int hp;		//체력
	int energy;	//기력
	int damage; //공격력
	Room* current_room; // 현재 위치한 방
	Inventory* bag;	// 가방
	// 수환
	Room* pre_room; // 이동 전 방

public:
	Player() {
		hp = 0;
		energy = 0;
		damage = 0;
		current_room = NULL;
		bag = NULL;
		// 수환
		pre_room = NULL;
	}
	// set
	void set(Room* room); // 플레이어 세팅

	// get
	Room* get_current_room(); // 현재 방 위치 get
	void get_print_move_room(); // 이동가능한 방 출력
	Inventory* get_bag() {	// 가방 get
		return this->bag;
	}

	// 수환
	Room* get_pre_room(); // 이동 전 방 위치 get
	void take_damage(int damage);

	// 기능
	void move(Room* room); // 방 이동
};

