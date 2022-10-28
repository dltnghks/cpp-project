#include "screen.h"

COORD Screen::pos = { INIT_X, INIT_Y };

void Screen::set(int x, int y) {
	pos.X = x;
	pos.Y = y;
}

int Screen::get_y() {
	return pos.Y;
}
int Screen::get_x() {
	return pos.X;
}


void Screen::gotoxy() {
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos); //朕辞 竺舛
}
void Screen::line_print(string str) {
	gotoxy();
	cout << str << endl;
	getchar();
	pos.Y++;
}

void Screen::print(string str) {
	gotoxy();
	cout << str << endl;
	pos.Y++;
}


void Screen::clear() {
	pos.X = INIT_X-1;
	pos.Y = INIT_Y;
	for (int i = 0; i < 9; i++) {
		print("                                                                                           ");
	}
	set(INIT_X, INIT_Y);
	gotoxy();
}

//呪発
// 覗傾績 窒径
void Screen::print_frame() {
	system("cls");
	cout << "＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝" << endl;
	cout << "＝　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　＝" << endl;
	cout << "＝　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　＝" << endl;
	cout << "＝　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　＝" << endl;
	cout << "＝　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　＝" << endl;
	cout << "＝　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　＝" << endl;
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
	cout << "＝　　　　　　　　　　　　　　　　　　　　　　　　　　                         　　 　　　　　　＝" << endl;
	cout << "＝　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　＝" << endl;
	cout << "＝　　　　　　　　　　　　　　　　　　　　　　　　　　                         　　 　　　　　　＝" << endl;
	cout << "＝　　　　　　　　　　　　　　　　　　　　　　　　　　                         　　 　　　　　　＝" << endl;
	cout << "＝　　　　　　　　　　　　　　　　　　　　　　　　　　                         　　 　　　　　　＝" << endl;
	cout << "＝　　　　　　　　　　　　　　　　　　　　　　　　　　                         　　 　　　　　　＝" << endl;
	cout << "＝　　　　　　　　　　　　　　　　　　　　　　　　　　                         　　 　　　　　　＝" << endl;
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
}
// 努什闘 但 走酔奄
void Screen::text_clear() {
	pos.X = TEXT_INIT_X;
	pos.Y = TEXT_INIT_Y;
	for (int i = 0; i < 20; i++) {
		print("                                                                                           ");
	}
	set(TEXT_INIT_X, TEXT_INIT_Y);
	gotoxy();
}

int Screen::KeyIn() {
	while (true) {
		int key = _getch(); // 徹 脊径閤奄
		if (key == 224) {
			key = _getch();
			switch (key) {
			case UP:
				return UP;
				break;
			case DOWN:
				return DOWN;
				break;
			}
		}
		else if (key == 13) {
			return ENTER;
		}
	}
}

