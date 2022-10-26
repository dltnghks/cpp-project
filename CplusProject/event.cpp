#include "event.h"
/*
"총기함실", "인사과", "지휘통제실",
"군수과", "대대장실", "주임원사실", "통신물자 창고",
"1층 중앙복도"
"1-1", "1-2", "1-3", "2-1", "2-2", "2-3", "2층 서편",
"2층 중앙복도",
"2층 동편", "화장실" , "세탁실", "격리 생활관", "2중대 행정반", "통신물자 창고"
*/

// 이벤트 (조건 설정)
void Event::event() {
	string room_name = this->player->get_current_room()->get_name();
	// 2층 동편
	if (room_name == "2층 동편") {
		//칸막이 이벤트
		partition_event();
	}
	else if (room_name == "화장실") {
		// 부러진 대걸레
	}
	else if (room_name == "세탁실") {
		// 차갑게 식은 냉동 만두
	}
	else if (room_name == "격리 생활관") {
		// 어딘가 중요해 보이는 열쇠
	}
	else if (room_name == "2중대 행정반") {

	}
	else if (room_name == "통신물자 창고") {

	}



	// 2층 중앙 복도
	else if (room_name == "2층 중앙복도") {
		// 윤모
	}




	else if (room_name == "1-1") {
		// 손전등
	}
	else if (room_name == "1-2") {
		// 야채 건빵
	}
	else if (room_name == "1-3") {
		// 몽키 스패너
	}
	else if (room_name == "2-1") {
		// 터보 라이터
	}
	else if (room_name == "2-2") {
		// 붕대
	}
	else if (room_name == "2-3") {
		// 손소독제
	}


	
	// 1층 중앙복도
	else if (room_name == "총기함실") {

	}
	else if (room_name == "인사과") {

	}
	else if (room_name == "지휘통제실") {

	}
	else if (room_name == "군수과") {

	}
	else if (room_name == "대대장실") {

	}
	else if (room_name == "주임원사실") {

	}
	else if (room_name == "통신물자 창고") {

	}
}

/**************************************************
				이벤트
***************************************************/
//칸막이 이벤트
//칸막이 열쇠를 가지고 있으면 "2층 동편"으로 이동 가능
void Event::partition_event() {
	Screen::clear();
	Screen::set(INIT_X, INIT_Y);
	Screen::gotoxy();
	if (this->player->get_bag()->get_check_item("[칸막이 열쇠]")) {
		Screen::line_print("문이 열렸습니다.");
	}
	else {
		Screen::line_print("열쇠가 필요할 것 같다.");
	}
}

