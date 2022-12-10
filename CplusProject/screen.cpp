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

int Screen::get_y_enter() {
	return pos.Y;
	pos.Y++;
}


void Screen::gotoxy() {
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos); //커서 설정
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
	pos.X = INIT_X - 1;
	pos.Y = INIT_Y;
	for (int i = 0; i < 9; i++) {
		print("                                                                                           ");
	}
	set(INIT_X, INIT_Y);
	gotoxy();
}

//수환
// 프레임 출력
void Screen::print_frame() {
	system("cls");
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　                         　　 　　　　　　■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　                         　　 　　　　　　■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　                         　　 　　　　　　■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　                         　　 　　　　　　■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　                         　　 　　　　　　■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　                         　　 　　　　　　■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　　　　　                         　　 　　　　　　■" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■  　　　　　　　                                                                              ■" << endl;
	cout << "■     　　                                                                                     ■" << endl;
	cout << "■                                                                                              ■" << endl;
	cout << "■                                                                                              ■" << endl;
	cout << "■                                                                                              ■" << endl;
	cout << "■                                                                                              ■" << endl;
	cout << "■                                                                                              ■" << endl;
	cout << "■                                                                                              ■" << endl;
	cout << "■                                                                                              ■" << endl;
	cout << "■                                                                                              ■" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
}
// 텍스트 창 지우기
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
		int key = _getch(); // 키 입력받기
		if (key == 'M' || key == 'm') {
			return MAP;
		}
		else if (key == 'I' || key == 'i') {
			return INVEN;
		}
		else if (key == 'B' || key == 'b' || key == 'U' || key == 'u')
		{
			return CANCEL;
		}
		else if (key == 224) {
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

// 맵 출력
void Screen::print_map() {
	system("cls");
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■　　　　　　　　　　　　　　　　　　　　　　 옥상 　　　　　　　　　　　　　　　　　　　　　　■" << endl;
	cout << "■　■■■■■■■■■■■■■■■■■■■■　▲▲▲　■■■■■■■■■■■■■■■■■■■■  ■" << endl;
	cout << "■　■　　　　　■　　　　　■　　  　　■　　　　　　　■　　　  　■　　　　  ■　  　　　■　■" << endl;
	cout << "■　■　 1-1　　■　 1-2　　■　 1-3　　■　　　　　　　■　화장실　■　세탁실　■격리생활관■　■" << endl;
	cout << "■　■　　　　　■　　　　　■　　  　　■　　　　　　　■　　　　　■　　　　  ■　　　　　■　■" << endl;
	cout << "■  ■■■■■▲■■■■■▲■■■■■▲■　　　　　　　■▲■■■■■▲■■■■■▲■■■■■  ■" << endl;
	cout << "■　■　　　　　　2층 서편　　　　　　　　 2층 중앙 복도　  　2층 동편　　　칸막이　　　　　■　■" << endl;
	cout << "■　■■■■■▼■■■■■▼■■■■■▼■　　　　　　　■▼■■■■■■■■■■■▼■■■■■  ■" << endl;
	cout << "■　■　　　　　■　　　　　■　　　  　■　　　　　　　■　　  　　　　　  ■　　　　　　　■　■" << endl;
	cout << "■　■　 2-1　　■　 2-2　　■　 2-3  　■　　　　　　  ■ 　2중대 행정반 　■　간부연구실　■　■" << endl;
	cout << "■　■　　　　　■　　　　　■　　　  　■　　　　　　　■  　　　　　　　  ■　　　　　　　■　■" << endl;
	cout << "■  ■■■■■■■■■■■■■■■■■■■■　　　　　■■■■■■■■■■■■■■■■■■■■  ■" << endl;
	cout << "■　■　　　　　　　　　■　　　　  　　■　　　　　　　■　　　  　　　　■　  　　  　　　■　■" << endl;
	cout << "■　■　　총기함실　　　■　　인사과　　■　　　　　　　■　　군수과　　　■　통신물자창고　■　■" << endl;
	cout << "■　■　　　　　　　　　■　　　　  　　■　　　　　　　■　　　　　　　　■　  　　　　　　■　■" << endl;
	cout << "■  ■■■■■■■■■▲■■■■■■■▲■　　　　　　　■▲■■■■■■■■▲■■■■■■■■  ■" << endl;
	cout << "■　■　　　　　　　　　　　　　　　　　　 1층 중앙 복도　  　　　　　　　　　　　　　　　　■　■" << endl;
	cout << "■　■■■■■■■■■■■■■■■■■▼■　　　　　　　■▼■■■■■■■■▼■■■■■■■■  ■" << endl;
	cout << "■　■　　　　　　　　　　　　　　　  　■　　　　　　　■　　  　　　　　■　　　　　　　　■　■" << endl;
	cout << "■　■ 　　　　　지휘 통제실　　　　　　■　　　　　　  ■　주임 원사실 　■　　대대장실　　■　■" << endl;
	cout << "■　■　　　　　　　　　　　　　　　  　■　　　　　　　■  　　　　　　　■　　　　　　　　■　■" << endl;
	cout << "■  ■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■  ■" << endl;
	cout << "■                                                                                              ■" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	cout << "■  　　　　　　　                                                                              ■" << endl;
	cout << "■           　　                                                                               ■" << endl;
	cout << "■                                                                                              ■" << endl;
	cout << "■                                                                                              ■" << endl;
	cout << "■                                                                                              ■" << endl;
	cout << "■                                                                                              ■" << endl;
	cout << "■                                                                                              ■" << endl;
	cout << "■                                                                                              ■" << endl;
	cout << "■                                                                                              ■" << endl;
	cout << "■                                                                                              ■" << endl;
	cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■" << endl;
	Screen::line_print("");
}


