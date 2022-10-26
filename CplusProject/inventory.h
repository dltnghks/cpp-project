#pragma once
#include <iostream>
#include <string>

#include "item.h"

using namespace std;

/******************************************

			인벤토리에 대한 정보들

*******************************************/

class Inventory {
	int size; // 아이템 개수
	Item* root;
public:
	Inventory() {
		size = 0;
		root = new Item("root");;
	}
	void set(int size);
	void insert_item(string item);
	// 수환
	void delete_item(string item);
	Item* find_item(string item); // get_check_item으로 있는지 확인하고 넣기

	bool get_check_item(string name); // 아이템을 가지고 있는지 확인
};
