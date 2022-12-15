#include "inventory.h"
#include "game.h"


void Inventory::set(int size) {
	this->size = size;
}


void Inventory::insert_item(string item) {
	this->size++;
	// 새로운 아이템 생성
	Item* new_item = new Item(item);
	//수환
	// root->link가 아무것도 없다면 = 인벤토리에 들어온 아이템이 없다면
	if (this->root->get_link() == this->root) {
		// 새로운 아이템의 pre와 link를 root로 세팅
		new_item->set_link(this->root);
		new_item->set_pre(this->root);

		// root의 link와 pre를 item으로 세팅
		this->root->set_link(new_item);
		this->root->set_pre(new_item);
	}
	else {
		// 기존에 root에 연결되어 있던 link의 아이템의 pre를 새로운 아이템으로 세팅
		this->root->get_link()->set_pre(new_item);
		// 기존에 root에 연결되어 있던 link의 아이템을 새로운 아이템의 link로 세팅
		new_item->set_link(this->root->get_link());
		new_item->set_pre(this->root);
		// root의 link를 새로운 아이템으로 세팅
		this->root->set_link(new_item);
	}
}

void Inventory::delete_item(string item) {
	if (get_check_item(item)) {
		Item* del_item = find_item(item);
		del_item->get_pre()->set_link(del_item->get_link());
		del_item->get_link()->set_pre(del_item->get_pre());
	}
}
//수환
Item* Inventory::find_item(string name) {
	for (Item* tmp = this->root; tmp != NULL; tmp = tmp->get_link()) {
		if (tmp->get_name() == name)
			return tmp;
	}
}

void Inventory::print_inventory(){ //현재 인벤토리 상태를 확인 -> 아이템의 삽입은 플레이어 클래스에서 이뤄지므로 플레이어 클래스를 가져와야한다{
	
	Item* tmp;
	
	system("cls");

	Screen::print_frame();
	Screen::set(39, 3);
	Screen::print("<<현재 인벤토리>");

	for (tmp = this->root->get_link(); tmp != this->root; tmp = tmp->get_link())
	{
		cout << "\n" << "\t" << "\t" << "\t" << "\t" << tmp->get_name() << endl;
	}
	Screen::set(INIT_X, INIT_Y);
	Screen::gotoxy();
	Screen::print("돌아가기");

}

bool Inventory::get_check_item(string name) { 
	for (Item* tmp = this->root->get_link(); tmp != this->root; tmp = tmp->get_link()) {
		if (tmp->get_name() == name)
			return true;
	}
	return false;
}

