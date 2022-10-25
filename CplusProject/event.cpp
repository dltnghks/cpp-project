#include "event.h"


// 이벤트 (조건 설정)
void Event::event() {
	//칸막이 이벤트
	if (this->player->get_current_room()->get_name() == "2층 동편") {
		partition_event();
	}
}

/**************************************************
				이벤트
***************************************************/
//칸막이 이벤트
//칸막이 열쇠를 가지고 있으면 "2층 동편"으로 이동 가능
void Event::partition_event() {
	if (this->player->get_bag()->get_check_item("[칸막이 열쇠]")) {
		cout << "문이 열렸습니다." << endl;
	}
	else {
		cout << "열쇠가 필요할 것 같다." << endl;
	}
}