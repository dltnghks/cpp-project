#include <iostream>
#include <stdlib.h>

#include "map.h"
#include "player.h"
#include "event.h"
#include "game.h"
using namespace std;

int main() {
	Game game;
	Map map;
	Player player;
	Event event;

	
	map.set();
	player.set(map.find_room("격리 생활관"));
	event.set(&player);
	game.set(&player, &map);

	player.get_bag()->insert_item("[칸막이 열쇠]");

	while (1) {
		map.print_map();
		game.selection();
		event.event();
		getchar();	
		system("cls");
	}
}