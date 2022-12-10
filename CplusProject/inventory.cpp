#include "inventory.h"
#include "game.h"


void Inventory::set(int size) {
	//this->size = size;
}


void Inventory::insert_item(string item) {
	this->inven.push_back(item);
}

void Inventory::delete_item(string item) {
	if (get_check_item(item)) {
		this->inven.erase(inven.begin() + find_item(item));
	}
}
//수환
int Inventory::find_item(string name) {
	int index = 0;
	vector<string>::iterator it;
	for (it = this->inven.begin(); it != this->inven.end(); it++) {
		if (*it == name) {
			return index;
		}
		index++;
	}
}

void Inventory::print_inventory(){ //현재 인벤토리 상태를 확인 -> 아이템의 삽입은 플레이어 클래스에서 이뤄지므로 플레이어 클래스를 가져와야한다{
	
	Item* tmp;
	
	system("cls");

	Screen::print_frame();
	Screen::set(39, 3);
	Screen::print("<<현재 인벤토리>");

	vector<string>::iterator it;
	for (it = this->inven.begin(); it != this->inven.end(); it++) {
		cout << "\n" << "\t" << "\t" << "\t" << "\t" << *it << endl;
	}
	Screen::set(INIT_X, INIT_Y);
	Screen::gotoxy();
	Screen::print("돌아가기");

}

bool Inventory::get_check_item(string name) { 
	vector<string>::iterator it;
	for (it = this->inven.begin(); it != this->inven.end(); it++) {
		if (*it == name)
			return true;
	}
	/*
	for (Item* tmp = this->root->get_link(); tmp != this->root; tmp = tmp->get_link()) {
		if (tmp->get_name() == name)
			return true;
	}*/
	return false;
}

