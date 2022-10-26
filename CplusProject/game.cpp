#include "game.h"

int Game::getch() {
	int data;
	cin >> data;
	getchar();
	return data;
}

// 呪発
void Game::print_intro() {
	cout << "＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝" << endl;
	cout << "＝　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　＝" << endl;
	cout << "＝　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　＝" << endl;
	cout << "＝　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　＝" << endl;
	cout << "＝　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　＝" << endl;
	cout << "＝　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　＝" << endl;
	cout << "＝　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　＝" << endl;
	cout << "＝　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　＝" << endl;
	cout << "＝　　　　　　　＝＝＝　　　　＝＝　　　＝　　＝　　　＝＝　　　＝　　＝　　＝＝＝　　　　　　　＝" << endl;
	cout << "＝　　　　　　　＝　　＝　　＝　　＝　　＝　　＝　　＝　　＝　　＝＝　＝　　＝　　　　　　　　　＝" << endl;
	cout << "＝　　　　　　　＝　　＝　　＝＝＝＝　　　＝＝　　　＝　　＝　　＝　＝＝　　＝＝＝　　　　　　　＝" << endl;
	cout << "＝　　　　　　　＝　　＝　　＝　　＝　　　＝＝　　　＝　　＝　　＝　　＝　　＝　　　　　　　　　＝" << endl;
	cout << "＝　　　　　　　＝＝＝　　　＝　　＝　　　＝＝　　　　＝＝　　　＝　　＝　　＝＝＝　　　　　　　＝" << endl;
	cout << "＝　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　＝" << endl;
	cout << "＝　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　＝" << endl;
	cout << "＝　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　＝" << endl;
	cout << "＝　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　＝" << endl;
	cout << "＝　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　＝" << endl;
	cout << "＝　　　　　　　　　　　　　　　　　　　　　　　　　　                         　　 　　　　　　＝" << endl;
	cout << "＝　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　＝" << endl;
	cout << "＝　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　＝" << endl;
	cout << "＝　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　＝" << endl;
	cout << "＝　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　＝" << endl;
	cout << "＝　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　＝" << endl;
	cout << "＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝" << endl;
	cout << "＝  　　　　　　　                                                                              ＝" << endl;
	cout << "＝     　　                                                                                     ＝" << endl;
	cout << "＝                                                                                              ＝" << endl;
	cout << "＝                                                                                              ＝" << endl;
	cout << "＝                                                                                              ＝" << endl;
	cout << "＝                                                                                              ＝" << endl;
	cout << "＝                                                                                              ＝" << endl;
	cout << "＝                                                                                              ＝" << endl;
	cout << "＝                                                                                              ＝" << endl;
	cout << "＝                                                                                              ＝" << endl;
	cout << "＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝" << endl;
	Screen::set(INIT_X, INIT_Y);
	Screen::print("[1] 獣拙馬奄");
	Screen::print("[2] 曽戟馬奄");
	int input = choose(2);
	// 獣拙馬奄
	if (input == 0) {
		return;
	}
	// 曽戟馬奄
	else if (input == 1) {
		exit(1);
	}
}

// 呪発
int Game::selection() {
	Screen::clear();
	Screen::set(INIT_X, INIT_Y);
	Screen::gotoxy();
	Screen::print("[1] 呪事馬奄");
	Screen::print("[2] 戚疑馬奄");
	int input = 0;
	input = choose(2);
	if (input == 0) { // 呪事馬奄
		return 0;
	}
	else if (input == 1) { // 戚疑馬奄
		selection_move();
		return 1;
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
		else if (key == UP && Screen::get_y() >= INIT_Y) {
			// 呪発
			if (Screen::get_y() == INIT_Y) {
				Screen::gotoxy();
				cout << " ";
				y = INIT_Y + max - 1;
				input = max-1;
			}
			else {
				Screen::gotoxy();
				cout << " ";
				y--;
				input--;
			}
		}
		// 元滴 号 鯵呪研 角嬢亜獄軒檎 照喫
		else if (key == DOWN && Screen::get_y() <= INIT_Y + max - 1) {
			// 呪発
			if (Screen::get_y() == INIT_Y + max-1) {
				Screen::gotoxy();
				cout << " ";
				y = INIT_Y;
				input = 0;
			}
			else {
				Screen::gotoxy();
				cout << " ";
				y++;
				input++;
			}
		}
	}
}


void Game::selection_move() {
	Screen::clear();
	Screen::set(INIT_X, INIT_Y);
	Screen::gotoxy();
	this->player->get_print_move_room();

	int max = player->get_current_room()->get_link_size(); // 元滴 号 鯵呪 姥馬奄
	if (player->get_current_room()->check_parent_room()) max++; // 採乞 号 赤生檎 +1

	int input = choose(max);
	this->player->move(map->find_room(player->get_current_room()->get_link_room(input)));
}
