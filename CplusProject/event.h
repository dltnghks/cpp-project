#pragma once

#include <iostream>
#include <string>
#include <map>
using namespace std;

#include "define.h"
#include "player.h"
#include "game.h"
#include "map.h"

/************************************************************************************

						이벤트 정보

************************************************************************************/


class Event {
	Player* player; // 플레이어 정보
	Map* _map; // 맵 정보
	// 수환
	map<string, bool> is_search_event;
	map<string, bool> is_move_event;

public:
	// set 
	// 플레이어 정보 가져오기
	void set(Player* player, Map* map) {
		this->player = player;
		this->_map = map;
		//수환
		string list[ROOMSIZE1 + ROOMSIZE2 + 1] = { "총기함실", "인사과", "지휘통제실",
										"군수과", "대대장실", "주임원사실",
										"1층 중앙복도",
										"1-1", "1-2", "1-3", "2-1", "2-2", "2-3", "2층 서편",
										"2층 중앙복도",
										"2층 동편", "화장실" , "세탁실", "격리 생활관", "2중대 행정반", "통신물자 창고", "간부 연구실",
										"옥상"};
		for (int i = 0; i < ROOMSIZE1 + ROOMSIZE2 + 1; i++) {
			is_search_event[list[i]] = false;
			is_move_event[list[i]] = false;
		}
	}


	// 이벤트 (조건 설정)
	void event();

	// 이벤트 (조건에 맞는 이벤트 가져오기)
	// 수환
	// 인트로 이벤트
	void intro();
	void search_event();
	void current_room_event(); // 현재 방 텍스트 출력

	// 현재 방 이벤트(텍스트)

	// 칸막이 이벤트
	void partition_event();
	// 2층 중앙복도 이벤트(윤모)
	void mid_way_2();
	// 1-3 눈치 채지 못한 좀비
	void zombie_event1_3();
	// 2-2 숨어있는 좀비
	void zombie_event2_2();
	// 지휘통제실 강력한 좀비
	void control_center_room();
	// 주임원사
	void sergeant_major();
	// 경비 이벤트
	void emergecy_event();
	// 옥상 이벤트
	void end_event();
	// 해피 엔딩
	void happy_end();
	// 배드드 엔딩
	void bad_end();
	// 플레이어 죽음
	void player_die();
};