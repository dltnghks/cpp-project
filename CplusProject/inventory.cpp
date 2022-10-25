#include "inventory.h"

void Inventory::set(int size) {
	this->size = size;
}

void Inventory::insert_item(string item) {
	this->size++;
	Item* new_item = new Item(item);
	if (this->root == NULL) {
		this->root = new_item;
	}
	else {
		this->root = new_item;
		new_item->set_link(this->root->get_link());
	}
}

bool Inventory::get_check_item(string name) {
	for (Item* tmp = this->root; tmp != NULL; tmp = tmp->get_link()) {
		if (tmp->get_name() == name)
			return true;
	}
	return false;
}