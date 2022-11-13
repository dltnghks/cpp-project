#pragma once
#include <iostream>
#include <string>

using namespace std;
// "[칸막이 열쇠]","[부러진 대걸레]","[차갑게 식은 냉동 만두]","[옥상 열쇠]","[손전등]",
//"[야채 건빵]" ,"[몽키 스패너]","[붕대]","[터보 라이터]","[손 소독제]","[총기함 키]",
//"[주임원사실 열쇠]","[권총과 탄알집]","[K2 소총]","[노트북과 연결 포트]","[어딘가 중요해 보이는 열쇠]"

/******************************************

			아이템 정보

*******************************************/
class Item {
	string name; // 이름
	Item* link; // 다음 아이템(인벤토리에서 연결리스트로 찾기 위함.)
	Item* pre;
public:
	Item() : Item("None"){}
	Item(string name) {
		this->name = name;
		this->link = this;
		this->pre = this;
	}

	void set_pre(Item* pre) {
		this->pre = pre;
	}

	void set_link(Item* link) {
		this->link = link;
	}

	string get_name() {
		return this->name;
	}

	Item* get_link() {
		return this->link;
	}

	Item* get_pre() {
		return this->pre;
	}
};