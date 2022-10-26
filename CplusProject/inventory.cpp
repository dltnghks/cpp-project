#include "inventory.h"

void Inventory::set(int size) {
	this->size = size;
}

void Inventory::insert_item(string item) {
	this->size++;
	Item* new_item = new Item(item);
	//수환
	if (this->root->get_link() == this->root) {
		new_item->set_link(this->root);
		new_item->set_pre(this->root);
		this->root->set_link(new_item);
		this->root->set_pre(new_item);
	}
	else {
		this->root->get_link()->set_pre(new_item);
		new_item->set_link(this->root->get_link());
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

bool Inventory::get_check_item(string name) {
	for (Item* tmp = this->root->get_link(); tmp != this->root; tmp = tmp->get_link()) {
		if (tmp->get_name() == name)
			return true;
	}
	return false;
}