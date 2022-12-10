#include "map.h"

using namespace std;

void Map::set() {
	// 1층, 2층 방 이름 리스트 생성
	string room_1[ROOMSIZE1] = { "총기함실", "인사과", "지휘통제실",
						"군수과", "대대장실", "주임원사실", "통신물자 창고",
						"1층 중앙복도" };
	string room_2[ROOMSIZE2] = { "1-1", "1-2", "1-3", "2-1", "2-2", "2-3", "2층 서편",
						"2층 중앙복도",
						"2층 동편", "화장실" , "세탁실", "격리 생활관", "간부 연구실" ,"2중대 행정반" };
	string end = "옥상";

	/****************************
			방 생성
	*****************************/
	// 1층 방 객체 생성
	for (int i = 0; i < ROOMSIZE1; i++) {
		Room* room = new Room(room_1[i]);
		insert_list(room);
	}
	// 2층 방 객체 생성
	for (int i = 0; i < ROOMSIZE2; i++) {
		Room* room = new Room(room_2[i]);
		insert_list(room);
	}
	// 옥상 방 객체 생성
	Room* room = new Room(end);
	insert_list(room);
	/****************************
			방 연결
	*****************************/
	// 1층 중앙 복도
	int link_size = 7;
	Room* tmp = find_room("1층 중앙복도");
	string* floor1_list = new string[link_size]{ "총기함실", "인사과", "지휘통제실", "군수과",
												"대대장실", "주임원사실", "통신물자 창고" };
	// 1층 중앙 복도 링크 방 사이즈 설정
	tmp->set_link_size(link_size);
	for (int i = 0; i < link_size; i++) {
		// 1층 중앙복도 기준 7개 방 연결
		//7개 방의 부모 방을 1층 중앙복도로 설정
		set_link_rooms(tmp, find_room(floor1_list[i]));
	}

	// 2층 중앙복도, 4개 방
	link_size = 4;
	tmp = find_room("2층 중앙복도");
	string* floor2_list = new string[link_size]{ "2층 서편", "2층 동편", "1층 중앙복도", "옥상" };
	tmp->set_link_size(link_size);
	for (int i = 0; i < link_size; i++) {
		set_link_rooms(tmp, find_room(floor2_list[i]));
	}

	// 2층 서편, 6개 방
	link_size = 6;
	tmp = find_room("2층 서편");
	string* floor2_west_list = new string[link_size]{ "1-1", "1-2", "1-3", "2-1", "2-2", "2-3" };

	tmp->set_link_size(link_size);
	for (int i = 0; i < link_size; i++) {
		set_link_rooms(tmp, find_room(floor2_west_list[i]));
	}

	// 2층 동편, 5개 방
	link_size = 5;
	tmp = find_room("2층 동편");
	string* floor2_east_list = new string[link_size]{ "화장실" , "세탁실", "격리 생활관","간부 연구실",
													  "2중대 행정반" };

	tmp->set_link_size(link_size);
	for (int i = 0; i < link_size; i++) {
		set_link_rooms(tmp, find_room(floor2_east_list[i]));
	}
}
// 방 연결 room1의 링크 방에 room2를 넣고, room2의 부모방에 room1을 넣음
void Map::set_link_rooms(Room* room1, Room* room2) {
	if (room1 != NULL && room2 != NULL) {
		room1->set_link_room(room2);
	}
}

// get
// 방 찾기 input의 이름을 가진 방 찾기 (없으면 NULL반환)
Room* Map::find_room(string input) {
	if (input != "error") {
		vector<Room*>::iterator it;
		for (it = list.begin(); it != list.end(); it++) {
			Room* room = *it;
			string tmp = room->get_name();
			if (tmp == input) {
				return room;
			}
		}
	}
	return NULL;
}


// 방 리스트에 추가
void Map::insert_list(Room* room) {
	//list[size++] = room;
	list.push_back(room);
}

