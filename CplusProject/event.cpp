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
/**************************************************
				현재 방 텍스트 출력
***************************************************/
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



	// 2층 서편
	else if (room_name == "2층 서편") {
		Screen::print("[2층 서편]");
		Screen::print("1소대와 2소대 생활관들이 보인다.");
		Screen::print("쓸만한 물건들이 남아 있을지도 모른다.");
		Screen::print("어쩌면 다른 생존자가 있을 수도 있을 것 같다.");
	}
	// 1-1
	else if (room_name == "1-1") {
      // 손전등
      Screen::print("[1-1 생활관]");
      Screen::print("복도 제일 끝 생활관이라 그런지 햇볕이 잘 들어오지 않는다.");
      Screen::print("벽 군데군데 곰팡이가 피어있다.");
   }
	// 1-2
   else if (room_name == "1-2") {
      // 야채 건빵
      Screen::print("[1-2 생활관]");
      Screen::print("항상 물만 묻히고 안씻는 이혜성 상병이 있던 곳이다.");
      Screen::print("들어서자마자 꼬랑내 때문에 구역질이 난다.");
   }
	// 1-3
   else if (room_name == "1-3") {
      Screen::print("[1-3 생활관]");
      Screen::print("항상 시끄러운 반이었지만 지금은 매우 조용하다.");
      Screen::print("이상할 정도로 조용한 것이 좀비가 있는 것 같다.");
      Screen::print("좀비가 구석 한켠에 쳐박혀 앉아있다.");
   }
	// 2-1
   else if (room_name == "2-1") {
      Screen::print("[2-1 생활관]");
      Screen::print("기독교 신자가 유난히 많았던 방...");
      Screen::print("아무리 둘러봐도 성경과 십자가는 안보인다.");
      Screen::print("하느님이 아니라 싸이버거를 굳게 믿었던 것 같다.");
   }
   // 2-2
   else if (room_name == "2-2") {
      Screen::print("[2-2 생활관]");
      Screen::print("끼-----------이이이이이익----------");
      Screen::print("문을 열자마자 숨어있던 좀비가 공격해온다!");
   }
   // 2-3
   else if (room_name == "2-3") {
      Screen::print("[2-3 생활관]");
      Screen::print("알코올 냄새가 코를 뻥 뚫어주는 것 같다.");
      Screen::print("항상 청결한 생활관이다.");
   }



   // 1층 중앙복도
   else if (room_name == "1층 중앙복도") {
		Screen::print("[1층 중앙복도]");
		Screen::print("곳곳에 혈흔 자국들이 보인다.");
		Screen::print("아까부터 계속 미세한 기계음이 반복적으로 들린다..");
		Screen::print("그 외에는 침묵이 가득하다.");
	}
	// 총기함실
   else if (room_name == "총기함실") {
      Screen::print("[총기함실]");
      Screen::print("총기함실이다.");
      Screen::print("WD냄새와 쇳덩이 냄새들이 난다.");
   }
   // 인사과
   else if (room_name == "인사과") {
	  Screen::print("[인사과]");
      Screen::print("인사과장이 1년 동안 결산하지 않은 부대 체육 리그 점수표가 정면에 보인다.");
      Screen::print("한켠에는 아직 개봉되지 않은 택배 상자들이 쌓여있다.");
      Screen::print("어딘가에 [총기함 키]가 있을 것이다.");
   }
   // 지휘통제실
   else if (room_name == "지휘통제실") {
      Screen::print("[지휘 통제실]");
      Screen::print("...매우 조용하다");
      Screen::print("아무 인기척도 느껴지지 않는다,");
      Screen::print("더 이상 좀비는 없는 것 같다");
   }
   // 군수과
   else if (room_name == "군수과") {
      Screen::print("[군수과]");
      Screen::print("대대장의 총애를 받던 군수과장이 있던 곳이다.");
      Screen::print("지독한 사람이었다.");
      Screen::print("책상 위에는 군수과장의 아들내미 사진이 보인다.");
      Screen::print("옆에는 달력이 있다.");
      Screen::print("[*8월 10일, 대대장님 생신*]");
   }
   // 대대장실
   else if (room_name == "대대장실") {
      Screen::print("[대대장실]");
      Screen::print("문이 잠겨있다.... [부재중]...");
   }
   // 주임원사실
   else if (room_name == "주임원사실") {
   // 처음 : 부재중, 한바탕 소란이 끝나고 다시 갔을 때 열림
      Screen::print("철컥,,,,드르륵,,,탁,,쿵,,");
	  Screen::print("좀비의 여파로 더 이상 문이 열리지 않는다.");
	  player->move(_map->find_room("1층 중앙복도"));
   }

   else if (room_name == "옥상") {
		end_event();
	}
}
/**************************************************
				탐색 이벤트
***************************************************/
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
		// 전투 식량 파운드 케이크 발견
		Screen::line_print("[전투 식량 파운트 케이크]를 발견했다.");
		player->get_bag()->insert_item("[전투 식량 파운드 케이크]");
	}
	else if (room_name == "1-2") {
		// 야채 건빵
		Screen::line_print("[야채 건빵 한 봉지]를 발견했다.");
		player->get_bag()->insert_item("[야채 건빵 한 봉지]");
	}
	else if (room_name == "1-3") {
		// 몽키 스패너
		Screen::line_print("[몽키 스패너]를 발견했다.");
		player->get_bag()->insert_item("[몽키 스패너]");
	}
	else if (room_name == "2-1") {
		// 성경책
		Screen::line_print("[두꺼운 성경책]를 발견했다.");
		player->get_bag()->insert_item("[두꺼운 성경책]");
	}
	else if (room_name == "2-2") {
		// 붕대
		Screen::line_print("[붕대]를 발견했다.");
		player->get_bag()->insert_item("[붕대]");
	}
	else if (room_name == "2-3") {
		// 손소독제
		Screen::line_print("[손 소독제]를 발견했다.");
		player->get_bag()->insert_item("[손 소독제]");
	}



	// 1층 중앙복도
	else if (room_name == "총기함실") {
		// 탐색 이벤트 X
		Screen::line_print("딱히 무언가 보이지 않는다.");
	}
	// 총기함실
	else if (room_name == "총기함실") {
		// 총기함 키가 있는 경우 K2소총 발견
		if (player->get_bag()->get_check_item("[총기함 키]")) {
			Screen::print("훈련 때문에 탄약은 없는 것 같다.");
			Screen::line_print("[K2 소총]을 얻었다.");
			player->get_bag()->insert_item("[K2 소총]");
		}
		else {
			Screen::print("총기함은 굳게 잠겨있다.");
		}
	}
	// 인사과
	else if (room_name == "인사과") {
		// 총기함 키, 구급약 키트
		Screen::line_print("[총기함 키]를 발견했다.");
		Screen::line_print("[구급약 키트]를 발견했다.");
		player->get_bag()->insert_item("[총기함 키]");
		player->get_bag()->insert_item("[구급약 키트]");
	}
	// 지휘통제실
	else if (room_name == "지휘통제실") {
		Screen::line_print("좀비가 입고있던 전투복에서 [주임원사실 열쇠]를 발견했다.");
		Screen::line_print("주임원사실에 들어갈 수 있을 것이다.");
		player->get_bag()->insert_item("[주임원사실 열쇠]");
	}
	// 군수과
	else if (room_name == "군수과") {
		Screen::line_print("[어딘가 중요해 보이는 열쇠]를 발견했다.");
		player->get_bag()->insert_item("[어딘가 중요해 보이는 열쇠]");
	}
	// 대대장실
	else if (room_name == "대대장실") {
		// 탐색 이벤트 X
		Screen::line_print("딱히 무언가 보이지 않는다.");
	}
	// 주임원사실
	else if (room_name == "주임원사실") {
		// 탐색 이벤트 X
		Screen::line_print("딱히 무언가 보이지 않는다.");
	}
	// 통신물자 창고
	else if (room_name == "통신물자 창고") {
		Screen::line_print("[노트북과 연결 포트]를 발견했다.");
		player->get_bag()->insert_item("[노트북과 연결 포트]");
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
		// 이동이벤트 X
	}



	// 2층 중앙 복도
	else if (room_name == "2층 중앙복도") {
		// 윤모 이벤트
		mid_way_2();
	}




	else if (room_name == "1-1") {
		// 이동이벤트 X
	}
	else if (room_name == "1-2") {
		// 이동이벤트 X
	}
	else if (room_name == "1-3") {
		// 나를 눈치 채지 못한 좀비
		zombie_event1_3();
	}
	else if (room_name == "2-1") {
		// 이동이벤트 X
	}
	else if (room_name == "2-2") {
		// 숨어있던 좀비의 공격
		zombie_event2_2();
	}
	else if (room_name == "2-3") {
		// 이동이벤트 X
	}


	
	// 1층 중앙복도
	else if (room_name == "1층 중앙복도") {
		// 이동이벤트 X
	}
	else if (room_name == "총기함실") {
		// 이동이벤트 X
	}
	else if (room_name == "인사과") {
		// 이동이벤트 X
	}
	else if (room_name == "지휘통제실") {
		// 지휘통제실 이벤트
		control_center_room();
	}
	else if (room_name == "군수과") {
		// 이동이벤트 X
	}
	else if (room_name == "대대장실") {
		// 이동이벤트 X
	}
	else if (room_name == "주임원사실") {
		// 금고와 경비 시스템 이벤트
		sergeant_major();
	}
	else if (room_name == "통신물자 창고") {
		// 이동이벤트 X
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
			Screen::line_print("이제 다른 곳으로 이동해야 할 것 같다.");
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

// 1-3 눈치 채지 못한 좀비
void Event::zombie_event1_3() {
	Screen::print("1 - 3반..항상 시끄러운 반이었지만 지금은 매우 조용하다.");
	Screen::print("이상할 정도로 조용한 것이 좀비가 있는 것 같다.");
	Screen::print("좀비가 구석 한켠에 처박혀 앉아 있다.");

	Screen::clear();
	Screen::print("[1] 맞서 싸운다.");
	Screen::print("[2] 도망간다");
	int input = Game::choose(2);
	// 맞서 싸운다
	Screen::text_clear();
	if (input == 0) {
		Screen::print("살...금...살...금...");
		Screen::print("푸드드득 우직 꾸엑!");
		Screen::print("좀비의 목을 힘껏 비틀어 제껴버렸다.");
		Screen::line_print("사시나무처럼 떨고 있다.");
		player->move(_map->find_room("2층 서편"));
		this->is_move_event["1-3"] = true;
	}
	// 도망간다.
	else if (input == 1) {
		Screen::print("조용히 나가야겠다.");
		Screen::print("한이 많이 쌓인 좀비임이 분명하다.");
		Screen::line_print("최대한 소리가 안나게 문을 닫고 나왔다.");
	}
}


// 2-2 눈치 채지 못한 좀비
void Event::zombie_event2_2() {
	Screen::print("2-2반이라.....");
	Screen::print("끼-----------이이이이이익--------------");
	Screen::print("문을 열자마자 숨어있던 좀비가 공격해온다!");

	Screen::clear();
	Screen::print("[1] 맞서 싸운다.");
	Screen::print("[2] 도망간다");
	int input = Game::choose(2);
	Screen::text_clear();
	// 맞서 싸운다
	if (input == 0) {
		Screen::print("좀비가 멍청해서 그대로 벽에 머리를 박고 죽었다.");
		Screen::print("반사신경으로 재빠르게 공격을 피했다.");
		Screen::line_print("잘못하면 목을 내어주고 좀비로 진급할 뻔했다.");
		this->is_move_event["2-2"] = true;
	}
	// 도망간다.
	else if (input == 1) {
		Screen::print("잘못하면 목을 내어주고 좀비로 진급할 뻔했다.");
		Screen::print("바로 문을 닫고 나왔다.");
		Screen::print("공격을 피하느라 벽에 몸을 부딛혔다.");
		Screen::print("더 이상 쫓아오지는 않는 것 같다.");
		Screen::line_print("경미한 부상을 입었다.");
		player->take_damage(2); // 부상
		player->move(_map->find_room("2층 서편"));
		this->is_move_event["2-2"] = true;
	}
}

// 지휘통제실 강력한 좀비
void Event::control_center_room() {
	Screen::print("항상 간부들이 북적거리던 곳이다.");
	Screen::print("CCTV 감시 화면 곳곳에 좀비들 모습이 보인다..");
	Screen::print("옥상에는 좀비가 없는 것 같다.");
	Screen::print("2-2반이라.....");
	Screen::print("그런데... 뭔가 이상하다.");
	Screen::print("내가 보이는 화면에 이상한 형체가 같이 있다.");
	Screen::print("쿠당탕!");
	Screen::print("갑자기 뒤에서 좀비 한 마리가 달려든다.");
	Screen::clear();
	Screen::print("[1] 맞서 싸운다.");
	Screen::print("[2] 도망간다");
	int input = Game::choose(2);
	Screen::text_clear();
	// 맞서 싸운다.
	if (input == 0) {
		//무기가 있는 경우
		if (player->get_bag()->get_check_item("[부러진 대걸레]") ||
			player->get_bag()->get_check_item("[몽키 스패너]") ||
			player->get_bag()->get_check_item("[K2 소총]") ||
			player->get_bag()->get_check_item("[권총과 탄창]") ||
			player->get_bag()->get_check_item("[두꺼운 성경책]")
			) {
			// 큰 부상을 당함(체력 감소)
			Screen::print("좀비가 매우 강력해보인다.");
			Screen::print("간신히 제압했다.");
			Screen::print("하마터면 엔딩도 보기전에 죽을 뻔했다.");
			Screen::print("머리가 조금 찢어진 것 같다.");
			Screen::line_print("큰 부상을 입었다.");
			player->take_damage(5);
			is_move_event["지휘통제실"] = true;
		}
		// 무기가 없는 경우
		else {
			Screen::print("헉,,,헉,,,역시 맨손으로는 무리였다.");
			Screen::print("자세히 보니 주임원사님의 얼굴을 꼭 빼닮은 것 같다.");
			Screen::print("지금이라도 도망쳐야 할 것 같다.");
			Screen::print("어라..?점점 의식이 흐려진다.");
			Screen::line_print("쿨럭,,");
			// 사망
			player_die();
		}
	}
	// 도망간다
	else if (input == 1) {
		Screen::line_print("1층 중앙복도로 도망갔다.");
		player->move(_map->find_room("1층 중앙복도"));
	}
}

// 주임원사실 이벤트
void Event::sergeant_major() {
	int input = 0;
	// 열쇠가 없는 경우
	Screen::text_clear();
	Screen::clear();
	Screen::print("[주임원사실]");
	Screen::print("철컥 철컥 문이 잠겨있다.");
	Screen::print("열쇠가 필요하다.");
	Screen::text_clear();
	if (!player->get_bag()->get_check_item("[주임원사실 열쇠]")) {
		emergecy_event();
	}
	// 열쇠가 있는 경우
	else {
		Screen::text_clear();
		Screen::clear();
		Screen::print("[주임원사실]");
		Screen::print("달그락 슈루룩 철컥!");
		Screen::print("좀비에게서 얻은 열쇠로 문이 열렸다.");
		Screen::print("안으로 들어갈 수록 커피 원두향이 진하게 난다.");
		Screen::print("잡다한 용접 도구들이 눈에 띈다.");
		Screen::print("위엄있어 보이는 장검 진열대 사이로 [금고]가 보인다.");
		Screen::print("오오,,이것은 정말 영롱하다..!");
		Screen::clear();
		Screen::print("[1] 금고를 열어본다.");
		Screen::print("[2] 건들지 않고 떠난다.");
		input = Game::choose(2);
		Screen::text_clear();
		Screen::clear();
		// 금고 열기
		if (input == 0) {
			// [어딘가 중요해 보이는 열쇠]가 있는 경우
			if (player->get_bag()->get_check_item("[어딘가 중요해 보이는 열쇠]")) {
				// 권총 탄창 발견
				Screen::print("...........");
				Screen::print("드륽 철컥!");
				Screen::print("금고가 열렸다!!!");
				Screen::print("중요해보이는 기밀 문서들이 잔뜩 있다.");
				Screen::line_print("[권총과 탄알집]을 발견했다.");
				// 경비 시스템 이벤트
				emergecy_event();
				is_move_event["주임원사실"] = true;
			}
			// [어딘가 중요해 보이는 열쇠]가 없는 경우
			else {
				// 돌아가기
				Screen::print("열쇠가 필요하다.");
				Screen::print("아무 반응이 없다.");
				Screen::line_print("철커덕...철커덕...");
				player->move(_map->find_room("1층 중앙복도"));
			}
		}
		// 건들지않고 떠난다.
		else if (input == 1) {
			player->move(_map->find_room("1층 중앙복도"));
		}
	}
}

// 경비시스템 이벤트
void Event::emergecy_event() {
	Screen::text_clear();
	Screen::print("삐--용--삐--용--삐--용--삐--용--");
	Screen::print("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
	Screen::print("갑자기 비상벨이 울린다.");
	Screen::print("좀비들이 몰려오는 소리가 들린다.");
	Screen::print("빨리 도망치거나 숨어야 할 것 같다.");
	Screen::clear();
	Screen::print("[1] 주변에 몸을 숨긴다.");
	Screen::print("[2] 도망간다.");
	int input = Game::choose(2);
	Screen::text_clear();
	// 주변에 몸을 숨긴다.
	if (input == 0) {
		Screen::print("일단 락커에 몸을 숨겼다.");
		Screen::print("좀비들의 발소리가 점점 가까워진다.");
		Screen::print("숨을 참아도 심장 소리는 더 커지는 것 같다....");
		Screen::print("쿵쾅쿵쾅쿵쾅쿵쾅쿵쾅쿵쿵쾅쾅....");
		Screen::print("쿵쾅..쿵쾅..쿵..쿵..쿵...쾅...쾅....");
		Screen::print("쿵...쾅...쿵...쾅...쿵..........");
		Screen::print("휴 다행히 좀비 소리가 다시 멀어졌다.");
		Screen::line_print("이제 밖으로 나가서 동태를 살펴봐야겠다.");
		player->move(_map->find_room("1층 중앙복도"));
	}
	// 도망간다.
	else if (input == 1) {
		Screen::print("황급히 주임원사실 밖으로 뛰쳐나왔다.");
		Screen::print("하지만 이미 늦었다..");
		Screen::print("좀비들이 나의 앞을 가로막고 있다.");
		Screen::print("으드득으드득..으드득으드득.....");
		Screen::print("혈관을 타고 뜨거운 수증기가 발 끝부터 머리 끝까지 차오르는 느낌이 든다.");
		Screen::line_print("세상이 불그노르스름해졌다. 그를ㄹㄹㄹㄹ");
		// 사망
		player_die();
	}
}

// 엔딩
void Event::end_event() {
	Screen::text_clear();
	Screen::print("옥상 문이 닫혀있다.");
	Screen::print("[ 관계자 외 출입금지 ]");
	Screen::print("철컥, 철컥");
	Screen::print("[옥상 열쇠]가 필요할 것 같다.");


	// 옥상 열쇠가 있는 경우
	if (player->get_bag()->get_check_item("[옥상 열쇠]")) {
		while (1) {
			Screen::text_clear();
			Screen::print("[옥상]");
			Screen::print("옥상에 설치된 안테나 통신 장치들이 반복적인 기계음을 내고 있다.");
			Screen::print("다행히 통신 장비가 작동중인 것 같다.");
			Screen::print("통신망만 개통하면 외부와 연락이 가능할 것이다.");
			Screen::print("우우웅...우우웅...(반복적인 기계음)");

			Screen::clear();
			Screen::print("[1] 통신망을 개통한다.");
			Screen::print("[2] 2층 중앙 복도로 내려간다.");
			int input = Game::choose(2);
			Screen::text_clear();
			if (input == 0) {
				Screen::print("혹시 연결되어 있을 수도..?");
				Screen::line_print("우우웅...우우웅...(반복적인 기계음)");
				Screen::text_clear();
				// 노트북과 연결 포트가 있는 경우
				if (player->get_bag()->get_check_item("[노트북과 연결 포트]")) {
					// 통신망 개통
					Screen::line_print("[...이더넷 연결중...]");
					Screen::line_print("[...국방망 연결중...]");
					Screen::line_print("[...무선 통신 체계 접속중...]");
					Screen::line_print("[접속 상태: 양호 ]");
					Screen::line_print("또로로로로로로...또로로로로로로...(신호 대기음)");
					Screen::print("본부대 상병 김상명, 전화받았습니다~");

					// 해피엔딩
					Screen::clear();
					Screen::print("[1] 통신보안, 여기는 11사단 정보통신대대,  생존자 1명 건물 옥상에서 구조 대기중 구조 바람. ");
					Screen::print("[2] 여보세요? 살려주세요! 여기 사람이 있다구요! ");
					// 배드엔딩
					Screen::print("[3] 제발 구해주세요! 저 내일 모레면 전역이라고! ");
					Screen::print("[4] 아아, 들리세요? 여보세요? 개새끼야 받았으면 대답을 해!");
					int input = Game::choose(4);
					Screen::text_clear();
					
					Screen::line_print("뚜...뚜...뚜...");
					Screen::line_print("연결이 끊어졌다..");
					Screen::line_print("통신 장비 노드가 노후되어 연결이 불안정한 것 같다.");
					Screen::line_print("더 이상 신호가 잡히지 않는다.");
					// 선택지 갱신
					if (input == 0 || input == 1) {
						// 해피엔딩
						happy_end();
					}
					else {
						// 배드엔딩
						bad_end();
					}
					break;
				}

				Screen::print("역시 통신망 연결이 끊겨있다.");
				Screen::print("통신망 개통을 위한 장비는 1층 [통신물자 창고]에 있을 것이다.");
				Screen::line_print("우우웅...우우웅...(반복적인 기계음)");

				// 없는 경우
				// 다시 현재 선택지로
			}
			else {
				player->move(_map->find_room("2층 중앙복도"));
				break;
			}
		}
	}
}

// 해피 엔딩 텍스트 출력 , 게임 종료
void Event::happy_end() {
	Screen::clear();
	Screen::text_clear();
	Screen::line_print("어느정도 시간이 흐른 것 같다.");
	Screen::line_print("점점 석양이 지고, 태양빛이 붉게 무르익어 간다.");
	Screen::line_print("산 기슭을 훑고 지나오는 바람은 머나먼 곳으로 떠나는 것 같다.");
	Screen::line_print("여기에 존재하는 것은 나 자신과 좀비...");
	Screen::line_print("그리고 이제는 성가신 기계음의 반복적인 소음...");
	Screen::line_print("자신의 영역을 침범하는 낯선 소음과 경쟁하듯 간섭을 이룬다.");
	Screen::line_print("처음에는 이방인이 열세했지만 시간이 갈 수록 원주민을 압도한다.");
	Screen::line_print("이제는 더 이상 본래 원주민의 모습은 온데 간데 없고 이방인이 주인 자리를 차지했다.");
	Screen::line_print(".....도도도도도도도도도도도두도두도두도두도두두두");
	Screen::line_print("두두두두두두두두두두두두두두두두두두두두두두");
	Screen::line_print("눈을 떠보니 저 멀리 산 골짜기 위로 희망이 날아오고 있다.");
	Screen::line_print("구조 헬기다!");
	Screen::line_print("나는 살았다..");
	Screen::text_clear();
	Screen::line_print("[게임 클리어]");
	exit(1);
}

// 배드 엔딩 텍스트 출력 , 게임 종료
void Event::bad_end() {
	Screen::clear();
	Screen::text_clear();
	Screen::line_print("어느정도 시간이 흐른 것 같다.");
	Screen::line_print("점점 석양이 지고, 태양빛이 붉게 무르익어 간다.");
	Screen::line_print("산 기슭을 훑고 지나오는 바람은 머나먼 곳으로 떠나는 것 같다.");
	Screen::line_print("여기에 존재하는 것은 나 자신과 좀비...");
	Screen::line_print("그리고 이제는 성가신 기계음의 반복적인 소음...");

	Screen::line_print("며칠이나 지났을까...좀비들이 옥상 문 앞까지 들랑거리는 소리가 들린다.");
	Screen::line_print("문은 통신장비들로 막아놔서 들어올 수는 없을 것이다.");
	Screen::line_print("하지만 나 또한 마찬가지다.");
	Screen::line_print("그렇다. 정말 빠져나갈 길이 없는 것이다.");
	Screen::line_print("차라리 폭격을 당해서 시원한 불 비를 맞고 작렬하게 불타고 싶을 정도다.");
	Screen::line_print("의식은 점점 메말라가는 느낌이다.");
	Screen::line_print("차라리 좀비한테 먹히는게 더 의미있을 것 같다.");
	Screen::line_print("하지만 이제는 문을 막아놓은 통신 장비조차 옮길 힘이 없다.");
	Screen::line_print("이럴때 옥상이라는 장점을 이용하면 되는 것을 깨달았다.");
	Screen::line_print("머리부터 자유 낙하를 했다.");
	Screen::line_print("콰직!");
	Screen::text_clear();
	Screen::line_print("[게임 클리어]");
	exit(1);
}

void Event::player_die() {
	Screen::clear();
	Screen::text_clear();
	Screen::line_print("[게임 오버]");
	exit(1);
}