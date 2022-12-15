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

class Game{
	Player* player;
	Map* map;
public:
	void set(Player* player, Map* map) {
		this->player = player;
		this->map = map;
	}

	int getch(); // 입력받고 버퍼 제거

	// 수환
	void print_intro(); //인트로 출력

	//수환
	int selection(); // 선택지

	static int choose(int max); // 0~max-1 중 하나 선택
	void selection_move(); // 이동 선택

};