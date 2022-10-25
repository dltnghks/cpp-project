#pragma once
#include <iostream>
#include <string>

#include "item.h"

using namespace std;

class Inventory {
	int size; // 아이템 개수
	Item* root;
public:
	Inventory() {
		size = 0;
		root = NULL;
	}
	void set(int size);
	void insert_item(string item);
	bool get_check_item(string name); // 아이템을 가지고 있는지 확인
};
