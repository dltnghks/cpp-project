#include <iostream>
#include <stdlib.h>

#include "map.h"
#include "player.h"
#include "event.h"
#include "game.h"
#include "screen.h"
using namespace std;

int main() {
	system("mode con cols=100 lines=38");
	Game game;
	Map map;
	Player player;
	Event event;

	map.set();
	player.set(map.find_room("격리 생활관"));
	event.set(&player, &map);
	game.set(&player, &map);

	player.get_bag()->insert_item("[칸막이 열쇠]");
	player.get_bag()->insert_item("[옥상 열쇠]");
	//player.get_bag()->insert_item("[노트북과 연결 포트]");
	// 수환
	game.print_intro(); // 시작화면 출력
	//event.intro();	// 인트로 출력
	while (1) {
		
		Screen::print_frame();
		event.current_room_event();
		int input = game.selection();
		// 수색
		if (input == 0) {
			event.search_event();
		}
		//이동
		else if (input == 1) {
			event.event();
		}
		else if (input == MAP) {
			Screen::print_map();
		}
		system("cls");
	}
}

