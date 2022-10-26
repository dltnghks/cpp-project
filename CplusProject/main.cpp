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
	player.set(map.find_room("�ݸ� ��Ȱ��"));
	event.set(&player, &map);
	game.set(&player, &map);

	//player.get_bag()->insert_item("[ĭ���� ����]");

	// ��ȯ
	game.print_intro(); // ����ȭ�� ���
	//event.intro();	// ��Ʈ�� ���
	while (1) {
		
		Screen::print_frame();
		event.current_room_event();
		int input = game.selection();
		// ����
		if (input == 0) {
			event.search_event();
		}
		//�̵�
		else if (input == 1) {
			event.event();
		}
		system("cls");
	}
}
