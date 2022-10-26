#include "event.h"
/*
"총기함실", "인사과", "지휘통제실",
"군수과", "대대장실", "주임원사실", "통신물자 창고",
"1층 중앙복도"
"1-1", "1-2", "1-3", "2-1", "2-2", "2-3", "2층 서편",
"2층 중앙복도",
"2층 동편", "화장실" , "세탁실", "격리 생활관", "2중대 행정반", "통신물자 창고", "간부 연구실"
*/

// 수환
// 현재 방 텍스트 출력
void Event::current_room_event() {
	string room_name = this->player->get_current_room()->get_name();
	Screen::text_clear();
	Screen::set(TEXT_INIT_X, TEXT_INIT_Y);
	Screen::gotoxy();
	// 2층 동편
	if (room_name == "2층 동편") {
		// 2층 중앙복도 좀비 이벤트를 아직 하지 않은 경우
		if (!is_move_event.at("2층 중앙복도")) {
			Screen::print("[2층 동편]");
			Screen::print("저 멀리 복도 중앙에 사람 형체들이 보인다.");
			Screen::print("역광 때문에 어둡게 보이지만 정상은 아닌 것 같다.");
			Screen::print("왼쪽에는 행정반이 보인다.");
			Screen::print("오른쪽에는 화장실과 세탁실이 있다.");
		}
		else {
			Screen::print("[2층 동편]");
			Screen::print("지나올 때 좀비는 없었으니 안심해도 될 것 같다.");
			Screen::print("오른쪽에는 행정반이 보인다.");
			Screen::print("왼쪽에는 화장실과 세탁실이 있다.");
		}
	}
	// 화장실
	else if (room_name == "화장실") {
		Screen::print("[화장실]");
		Screen::print("퀴퀴한 냄새가 진동한다.");
		Screen::print("몇일 동안 청소를 못한 모양이다");
	}
	// 세탁실
	else if (room_name == "세탁실") {
		Screen::print("[세탁실]");
		Screen::print("세탁기 위에 빨랫감이 그대로 쌓여있다.");
		Screen::print("창문 밖으로 좀비들이 돌아다니는 모습이 보인다.");
	}
	// 격리 생활관
	else if (room_name == "격리 생활관") {
		Screen::print("[격리 생활관 앞 복도]");
		Screen::print("격리 생활관 앞이다.");
		Screen::print("복도 방향으로 칸막이가 막고 있다.");
		Screen::print("옆에는 간부 연구실이 보인다.");
	}
	// 간부 연구실
	else if (room_name == "간부 연구실") {
		Screen::print("[간부 연구실]");
		Screen::print("간부 연구실이다.");
		Screen::print("매우 비좁은 1인 격리실이지만 있을 건 다 있는 모양새다.");
		Screen::print("하지만 지금은 먼지만 쌓여있다.");
		Screen::print("코로나 사태 이후 창고로 사용되는 것 같다.");
	}
	// 2중대 행정반
	else if (room_name == "2중대 행정반") {
		Screen::print("[2중대 행정반]");
		Screen::print("아무 인기척도 느껴지지 않는다.");
		Screen::print("어디선가 라디오 소리가 작게 들린다.");
		Screen::print("...당국은 내일인 6월 14일부터 대대적인...");
		Screen::print("...좀비 사태 대응하여 좀비와의 전쟁을 선포...");
		Screen::print("...예상 발원지인 홍천군부터 폭격 예정...");
		Screen::print("불길한 예감이 든다...빨리 움직여야 할 것 같다.");
	}



	// 2층 중앙 복도
	else if (room_name == "2층 중앙복도") {
		Screen::print("[2층 중앙복도]");
		Screen::print("좀비는 더 이상 보이지 않는다.");
		Screen::print("이상한 소리만 제외하면 매우 고요하다.");
		Screen::print("우웅ㅡ우웅ㅡ우웅ㅡ우웅ㅡ");
		Screen::print("어디선가 반복적인 기계음이 계속 들린다.");
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
}

// 탐색 이벤트
void Event::search_event() {
	string room_name = this->player->get_current_room()->get_name();
	Screen::text_clear();
	Screen::clear();
	Screen::set(TEXT_INIT_X, TEXT_INIT_Y);
	Screen::gotoxy();
	if (is_search_event.at(room_name)) {
		Screen::line_print("여기서 더 이상 할 수 있는 일은 없는 것 같다..");
		return;
	}
	// 2층 동편
	if (room_name == "2층 동편") {
		// 탐색 이벤트 없음.
		Screen::line_print("딱히 무언가 보이지 않는다.");
	}
	else if (room_name == "화장실") {
		Screen::print("[부러진 대걸레]를 발견했다.");
		Screen::line_print("무기로 사용할 수 있을 것 같다.");
		player->get_bag()->insert_item("[부러진 대걸레]");
	}
	else if (room_name == "세탁실") {
		Screen::line_print("[차갑게 식은 냉동 만두]를 발견했다.");
		player->get_bag()->insert_item("[차갑게 식은 냉동 만두]");
	}
	else if (room_name == "격리 생활관") {
		Screen::line_print("[칸막이 열쇠]를 발견했다.");
		player->get_bag()->insert_item("[칸막이 열쇠]");
	}
	else if (room_name == "간부 연구실") {
		// 탐색 이벤트 X
		Screen::line_print("딱히 무언가 보이지 않는다.");
	}
	else if (room_name == "2중대 행정반") {
		Screen::print("[*상 열쇠]를 발견했다.");
		Screen::line_print("주기가 되어있지만 글씨가 번져서 잘 안보인다.'...상'");
		player->get_bag()->insert_item("[옥상 열쇠]");
	}



	// 2층 중앙 복도
	else if (room_name == "2층 중앙복도") {
		// 탐색 이벤트 X
		Screen::line_print("딱히 무언가 보이지 않는다.");
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
	is_search_event[room_name] = true;
}


// 이벤트 (조건 설정)
void Event::event() {
	string room_name = this->player->get_current_room()->get_name();
	Screen::text_clear();
	Screen::clear();
	Screen::set(TEXT_INIT_X, TEXT_INIT_Y);
	Screen::gotoxy();

	if (is_move_event.at(room_name)) {
		// 이동 이벤트를 했음.
		return;
	}

	// 2층 동편
	else if (room_name == "2층 동편") {
		//칸막이 이벤트
		partition_event();
	}
	else if (room_name == "화장실") {
		// 이동이벤트 X
	}
	else if (room_name == "세탁실") {
		// 이동이벤트 X
	}
	else if (room_name == "격리 생활관") {
		// 이동이벤트 X
	}
	else if (room_name == "2중대 행정반") {
		// 이동이벤트 X
	}else if (room_name == "간부 연구실") {

	}



	// 2층 중앙 복도
	else if (room_name == "2층 중앙복도") {
		// 윤모 이벤트
		mid_way_2();
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
				이동 이벤트
***************************************************/
// 수환
// 인트로 이벤트
void Event::intro() {
	Screen::text_clear();
	Screen::clear();
	Screen::set(TEXT_INIT_X, TEXT_INIT_Y);
	Screen::gotoxy();
	Screen::line_print("2주 동안의 극락을 맛보고 다시 지옥으로 돌아왔다.");
	Screen::line_print("전역 전 말출(마지막 휴가)은 순식간이었다.");
	Screen::line_print("다행히도 말년에 극악무도한 KCTC훈련에서 벗어났기 때문에 후회는 없다.");
	Screen::line_print("불쌍한 놈들,,얼마나 뺑이를 치고 있을지 생각하면 입가에 미소가 저절로 나왔다.");
	Screen::line_print("게다가 코로나 시국에 휴가를 나갔다오면 격리를 당하니, 이 좋은 세상인가!");
	Screen::line_print("개꿀같은 1인 격리 생활로 꿀빨다가 전역이라니,,,기다려라 사회야..!");
	Screen::line_print("다음>>");
	Screen::text_clear();

	Screen::set(TEXT_INIT_X, TEXT_INIT_Y);
	Screen::gotoxy();
	Screen::line_print("몇 시간이나 지났을까,,,");
	Screen::line_print("평소보다 잠을 푹 잔 것같이 개운한 기분이다.");
	Screen::line_print("시계를 보니 시침은 이미 7을 넘어간지 오래다.");
	Screen::line_print("뭐지 여태까지 기상송을 못들은 적이 없는데,,,");
	Screen::line_print("잠귀가 예민해서 말년이 되도록 6시 30분에 눈이 안 떠진적이 없었다.");
	Screen::line_print("너무 무리하게 마셨나,,,");
	Screen::line_print("[아아아ㅏ아아아아아ㅏ아아아ㅏㄱ악!]");
	Screen::line_print("어디선가 조용한 아침의 평화를 깨는 날카로운 비명이 들렸다.");
	Screen::line_print("...???");
	Screen::line_print("밖으로 나가서 무슨 일인지 확인해봐야겠다.");
	Screen::line_print("다음>>");
	Screen::text_clear();

	Screen::set(TEXT_INIT_X, TEXT_INIT_Y);
	Screen::gotoxy();
	Screen::line_print("복귀 첫 날은 항상 피곤하기 때문에 금방 잠이 들었던 것 같다.");
	Screen::line_print("전날에 마신 술 때문에 갈증이 몹시 났기 때문에 잠에서 깬 것 같다.");
	Screen::line_print("물을 마시려면 문 밖에 있는 정수기까지 가야한다.");
	Screen::line_print("격리 구역은 칸막이로 외부로부터 단절되어있다.");
	Screen::line_print("그저 반투명 비닐막 문으로 대충 막아놓은 것이지만,,,");
	Screen::line_print("꼭두 새벽같은 시간에도 불침번은 잘 수가 없는 법.");
	Screen::line_print("형체의 움직임은 느릿하면서도 껄렁대는 느낌이다.");
	Screen::line_print("왠지 모르게 기괴한 느낌에 약간 오싹했다.");
	Screen::line_print("에,,,에,,휴 개빠졌네 말세다 말세야,,벌컥 벌컥");
	Screen::line_print("목을 축이고 다시 침대라고 하기 부끄러운 매트리스 위에 몸을 던졌다.");
	Screen::line_print("다음>>");
	Screen::text_clear();
}

//칸막이 이벤트
//칸막이 열쇠를 가지고 있으면 "2층 동편"으로 이동 가능
void Event::partition_event() {
	if (this->player->get_bag()->get_check_item("[칸막이 열쇠]")) {
		Screen::print("철커덕!");
		Screen::line_print("[칸막이 열쇠를] 사용했다.");
		player->get_bag()->delete_item("[칸막이 열쇠]");
		Screen::print("오래된 나무끼리 마찰되는 소리와 함께 문이 힘없이 열렸다.");
		Screen::line_print("밖으로 나가자.");
		is_move_event["2층 동편"] = true;
	}
	else {
		Screen::print("문에 자물쇠가 걸려있다.");
		Screen::line_print("열쇠를 찾아보자.");
		player->move(player->get_pre_room());
	}
}

// 2층 중앙복도 이벤트(윤모)
void Event::mid_way_2() {
	if (!is_move_event.at("2층 중앙복도")) {
		Screen::print("[2층 중앙복도]");
		Screen::print("복도 중앙에 좀비 무리가 있다.");
		Screen::print("익숙한 얼굴이 보인다..");
		Screen::print("설마 ㅅ서..성...윤모..?");
		Screen::print("내 알동기 윤모..어쩌다 이렇게...");
		Screen::print("하지만 아는 척 할 수는 없을 것 같다.");
		Screen::print("저쪽에서 먼저 나의 존재를 알아챈 것 같다.");
	}
	Screen::clear();
	Screen::print("[1] 맞서 싸운다.");
	Screen::print("[2] 도망간다");
	int input = Game::choose(2);
	// 맞서 싸운다
	Screen::text_clear();
	if (input == 0) {
		Screen::print("윤모는 인간이었을 때도 나약했으니 충분히 승산이 있을 것 같다.");
		if (this->player->get_bag()->get_check_item("[부러진 대걸레]")) {
			// 좀비 물리침, 대걸레 소모
			Screen::print("윤모야 미안하다..하지만 어쩔 수 없었다.");
			Screen::print("[부러진 대걸레]로 숨통을 끊었다.");
			Screen::print("대걸레가 꽂힌 채로 쓰러졌다.");
			Screen::line_print("[부러진 대걸레]를 잃었다.");
			player->get_bag()->delete_item("[부러진 대걸레]");
			Screen::print("더 이상 미동이 없다.");
			Screen::print("이제 다른 곳으로 이동해야 할 것 같다.");
		}
		else {
			// 2층 서편으로 도망, HP 감소
			Screen::print("헉,,,헉,,,무기 없이는 무리인 것 같다.");
			Screen::print("내가 알 던 윤모가 아니다.");
			Screen::print("지금이라도 도망가야 할 것 같다.");
			Screen::line_print("간신히 2층 서편으로 도망쳐 왔다.");
			player->take_damage(5);
			player->move(_map->find_room("2층 서편"));
		}
	}
	// 도망간다.
	else if (input == 1) {
		Screen::print("이건 절대 도망치는게 아니다.");
		Screen::print("작전상 후퇴일뿐.");
		Screen::print("아무튼 아니다.");
		Screen::clear();
		Screen::print("[1] 1층으로 도망간다.");
		Screen::print("[2] 2층 서편으로 도망간다.");
		int input = Game::choose(2);
		if(input == 0){
			player->move(_map->find_room("1층 중앙복도"));
		}
		else if (input == 1) {
			player->move(_map->find_room("2층 서편"));
		}
	}
	this->is_move_event["2층 중앙복도"] = true;
}