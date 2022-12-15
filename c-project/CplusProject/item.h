#pragma once
#include <string>
#define KEY 1
#define FOOD 2
#define WEAPON 3
#define MEDECINE 4
#define OTHERS 5

using namespace std;
// "[칸막이 열쇠]","[부러진 대걸레]","[차갑게 식은 냉동 만두]","[옥상 열쇠]","[손전등]",
//"[야채 건빵]" ,"[몽키 스패너]","[붕대]","[터보 라이터]","[손 소독제]","[총기함 키]",
//"[주임원사실 열쇠]","[권총과 탄알집]","[K2 소총]","[노트북과 연결 포트]","[어딘가 중요해 보이는 열쇠]"

/******************************************

			아이템 정보

*******************************************/
class Item {
	string name; // 이름
	int type;
//protected:
//	Player* player;
public:
	Item() {
		this->name = "NONE";
		this->type = 0;
	}
	Item(string name, int type) {
		this->name = name;
		this->type = type;
	}
	string get_name() {
		return this->name;
	}
	//void set_info(Player* player) {
	//	this->player = player;
	//}
	virtual void use_item() = 0;
};