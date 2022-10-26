#pragma once
#include <iostream>
#include <string>

#include "player.h"
#include "map.h"
#include "define.h"
#include "screen.h"
using namespace std;

/******************************************

			게임 시스템

*******************************************/

class Game {
	Player* player;
	Map* map;
public:
	void set(Player* player, Map* map) {
		this->player = player;
		this->map = map;
	}
	int getch(); // 입력받고 버퍼 제거

	void selection(); // 선택지
	int choose(int max);
	void selection_search(); // 수색 선택
	void selection_move(); // 이동 선택

};