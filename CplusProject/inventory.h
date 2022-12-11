#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "item.h"

using namespace std;

/******************************************

			인벤토리에 대한 정보들

*******************************************/

class Inventory {
	//int size; // 아이템 개수
	//Item* root; // 인벤토리 root
	vector<string> inven;

public:
	Inventory() {
		//size = 0;
		//root = new Item("Root");;
	}

	void set(int size);

	// root의 link에 item을 연결
	void insert_item(string item);

	// 아이템 지우기
	void delete_item(string item);

	int find_item(string item); // get_check_item으로 있는지 확인하고 넣기

	void print_inventory(); //현재 인벤토리 상태를 확인하는 함수

	bool get_check_item(string name); // 아이템을 가지고 있는지 확인


};
