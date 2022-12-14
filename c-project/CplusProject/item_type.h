#pragma once
#include "item.h"


//[야채 건빵][차갑게 식은 냉동 만두]
class Food :public Item {
public:
	Food(string name) :Item(name, FOOD) {};
	void use_item() {
		Screen::line_print(this->get_name() + "를 먹었다.");
		//Item::player->take_food(3);
		//Screen::line_print("기력이 3만큼 증가했다.");
	}
};

//[칸막이 열쇠][주임원사실 열쇠][어딘가 중요해 보이는 열쇠][총기함 키][옥상 열쇠]
class Key :public Item {
public:
	Key(string name) :Item(name, KEY) {};
	void use_item() {
		Screen::line_print(this->get_name()+ "로 문을 열었다!");
		//해당하는 문 열기 이벤트
		//아이템 삭제
	}

};

//[붕대][손 소독제]
class Medecine :public Item {
public:
	Medecine(string name) :Item(name, MEDECINE) {};
	void use_item() {
		Screen::line_print(this->get_name() + "를 사용했다.");
		//Item::player->heal(3);
		//Screen::line_print("체력이 회복됐다.");
	}
};

//[손전등][터보 라이터][노트북과 연결 포트]
class Others :public Item {
public:
	Others(string name) :Item(name, OTHERS) {};
	void use_item() {
		Screen::line_print(this->get_name()+ "를 사용했다.");
	}
};

//[부러진 대걸레][권총과 탄알집][K2 소총][몽키 스패너]
class Weapon :public Item {
public:
	Weapon(string name) :Item(name, WEAPON) {};
	void use_item() {
		Screen::line_print(this->get_name() + "를 잃었다.");
	}
};