#pragma once
#include <iostream>
#include <string>
#include <conio.h>
#include <windows.h>

#include "define.h"

using namespace std;

/******************************************

			화면 출력

*******************************************/

class Screen {
	// 커서 위치 정보
	static COORD pos;
public:
	static void set(int x, int y);
	static int get_y();
	static int get_x();
	static void line_print(string str); // 한 줄씩 출력
	static void print(string str); // 출력
	static void gotoxy();	// 커서 이동
	static void clear();	// 선택지 지우기
	static int KeyIn();	// 키 입력
};