#include "game.h"

int Game::getch() {
	int data;
	cin >> data;
	getchar();
	return data;
}

void Game::selection() {
	cout << "[1] 수색하기" << endl;
	cout << "[2] 이동하기" << endl;
	int input = 0;
	input = getch();
	if (input == 1) { // 수색하기
		selection_search();
	}
	else if (input == 2) { // 이동하기
		selection_move();
	}
	else {
		cout << "잘못입력했습니다."<< endl;
	}
}

void Game::selection_search() {

}

void Game::selection_move() {
	int input;
	this->player->get_print_move_room();
	cout << "이동할 방 번호를 입력하세요 : ";
	input = getch();
	this->player->move(map->find_room(player->get_current_room()->get_link_room(input - 1)));
}