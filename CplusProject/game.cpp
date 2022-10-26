#include "game.h"

int Game::getch() {
	int data;
	cin >> data;
	getchar();
	return data;
}


void Game::selection() {
	Screen::clear();
	Screen::set(INIT_X, INIT_Y);
	Screen::gotoxy();
	Screen::print("[1] 수색하기");
	Screen::print("[2] 이동하기");
	int input = 0;
	input = choose(2);
	if (input == 0) { // 수색하기
		selection_search();
	}
	else if (input == 1) { // 이동하기
		selection_move();
	}
}

int Game::choose(int max) {
	int input = 0;
	int x = INIT_X - 1, y = INIT_Y;
	while (true) {
		Screen::set(x, y);
		Screen::gotoxy();
		cout << ">";
		int key = Screen::KeyIn();
		if (key == ENTER)
			return input;
		else if (key == UP && Screen::get_y() > INIT_Y) {
			Screen::gotoxy();
			cout << " ";
			y--;
			input--;
		}
		// 링크 방 개수를 넘어가버리면 안됨
		else if (key == DOWN && Screen::get_y() < INIT_Y+max-1) {
			Screen::gotoxy();
			cout << " ";
			y++;
			input++;
		}
	}
}

void Game::selection_search() {

}

void Game::selection_move() {
	Screen::clear();
	Screen::set(INIT_X, INIT_Y);
	Screen::gotoxy();
	this->player->get_print_move_room();

	int max = player->get_current_room()->get_link_size(); // 링크 방 개수 구하기
	if (player->get_current_room()->check_parent_room()) max++; // 부모 방 있으면 +1

	int input = choose(max);
	this->player->move(map->find_room(player->get_current_room()->get_link_room(input)));
}
