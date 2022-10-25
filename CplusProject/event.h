#pragma once

#include <iostream>
#include <string>

using namespace std;

#include "player.h"

/************************************************************************************

						이벤트 정보

************************************************************************************/


class Event {
	Player* player; // 플레이어 정보
public:
	// set
	// 플레이어 정보 가져오기
	void set(Player* player) {
		this->player = player;
	}

	// 이벤트 (조건 설정)
	void event();

	// 이벤트 (조건에 맞는 이벤트 가져오기)
	// 칸막이 이벤트
	void partition_event();

};