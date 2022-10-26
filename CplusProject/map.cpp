#include "map.h"

using namespace std;

// set
void Map::set() {
	size = 0;
	// 1Ãþ, 2Ãþ ¹æ ÀÌ¸§ ¸®½ºÆ® »ý¼º
	string room_1[ROOMSIZE1] = { "ÃÑ±âÇÔ½Ç", "ÀÎ»ç°ú", "ÁöÈÖÅëÁ¦½Ç",
						"±º¼ö°ú", "´ë´ëÀå½Ç", "ÁÖÀÓ¿ø»ç½Ç", "Åë½Å¹°ÀÚ Ã¢°í",
						"1Ãþ Áß¾Óº¹µµ" };
	string room_2[ROOMSIZE2] = { "1-1", "1-2", "1-3", "2-1", "2-2", "2-3", "2Ãþ ¼­Æí",
						"2Ãþ Áß¾Óº¹µµ",
						"2Ãþ µ¿Æí", "È­Àå½Ç" , "¼¼Å¹½Ç", "°Ý¸® »ýÈ°°ü", "°£ºÎ ¿¬±¸½Ç" ,"2Áß´ë ÇàÁ¤¹Ý"};

	/****************************
			¹æ »ý¼º
	*****************************/
	// 1Ãþ ¹æ °´Ã¼ »ý¼º
	for (int i = 0; i < ROOMSIZE1; i++) {
		Room* room = new Room(room_1[i]);
		insert_list(room);
	}
	// 2Ãþ ¹æ °´Ã¼ »ý¼º
	for (int i = 0; i < ROOMSIZE2; i++) {
		Room* room = new Room(room_2[i]);
		insert_list(room);
	}

	/****************************
			¹æ ¿¬°á
	*****************************/ 
	// 1Ãþ Áß¾Ó º¹µµ
	int link_size = 7;
	Room* tmp = find_room("1Ãþ Áß¾Óº¹µµ");
	string* floor1_list = new string[link_size]{ "ÃÑ±âÇÔ½Ç", "ÀÎ»ç°ú", "ÁöÈÖÅëÁ¦½Ç", "±º¼ö°ú", 
												"´ë´ëÀå½Ç", "ÁÖÀÓ¿ø»ç½Ç", "Åë½Å¹°ÀÚ Ã¢°í" };
	// 1Ãþ Áß¾Ó º¹µµ ¸µÅ© ¹æ »çÀÌÁî ¼³Á¤
	tmp->set_link_size(link_size);
	for (int i = 0; i < link_size; i++) {
		// 1Ãþ Áß¾Óº¹µµ ±âÁØ 7°³ ¹æ ¿¬°á
		//7°³ ¹æÀÇ ºÎ¸ð ¹æÀ» 1Ãþ Áß¾Óº¹µµ·Î ¼³Á¤
		set_link_rooms(tmp, find_room(floor1_list[i]));
	}

	// 2Ãþ Áß¾Óº¹µµ, 3°³ ¹æ
	link_size = 3;
	tmp = find_room("2Ãþ Áß¾Óº¹µµ");
	string* floor2_list = new string[link_size]{"2Ãþ ¼­Æí", "2Ãþ µ¿Æí", "1Ãþ Áß¾Óº¹µµ"};
	tmp->set_link_size(link_size);
	for (int i = 0; i < link_size; i++) {
		set_link_rooms(tmp, find_room(floor2_list[i]));
	}

	// 2Ãþ ¼­Æí, 6°³ ¹æ
	link_size = 6;
	tmp = find_room("2Ãþ ¼­Æí");
	string* floor2_west_list = new string[link_size]{"1-1", "1-2", "1-3", "2-1", "2-2", "2-3"};

	tmp->set_link_size(link_size);
	for (int i = 0; i < link_size; i++) {
		set_link_rooms(tmp, find_room(floor2_west_list[i]));
	}

	// 2Ãþ µ¿Æí, 5°³ ¹æ
	link_size = 5;
	tmp = find_room("2Ãþ µ¿Æí");
	string* floor2_east_list = new string[link_size]{ "È­Àå½Ç" , "¼¼Å¹½Ç", "°Ý¸® »ýÈ°°ü","°£ºÎ ¿¬±¸½Ç",
													  "2Áß´ë ÇàÁ¤¹Ý"};

	tmp->set_link_size(link_size);
	for (int i = 0; i < link_size; i++) {
		set_link_rooms(tmp, find_room(floor2_east_list[i]));
	}
}
// ¹æ ¿¬°á room1ÀÇ ¸µÅ© ¹æ¿¡ room2¸¦ ³Ö°í, room2ÀÇ ºÎ¸ð¹æ¿¡ room1À» ³ÖÀ½
void Map::set_link_rooms(Room* room1, Room* room2) {
	if (room1 != NULL && room2 != NULL) {
		room1->set_link_room(room2);
	}
}

// get
// ¹æ Ã£±â inputÀÇ ÀÌ¸§À» °¡Áø ¹æ Ã£±â (¾øÀ¸¸é NULL¹ÝÈ¯)
Room* Map::find_room(string input) {
	if (input != "error") {
		for (int i = 0; i < size; i++) {
			Room* room = this->list[i];
			string tmp = room->get_name();
			if (tmp == input) {
				return list[i];
			}
		}
	}
	return NULL;
}


// ¹æ ¸®½ºÆ®¿¡ Ãß°¡
void Map::insert_list(Room* room) {
	list[size++] = room;
}

// ¸Ê Ãâ·Â
void Map::print_map() {
	system("cls");
	cout << "¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á" << endl;
	cout << "¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡ ¿Á»ó ¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡á" << endl;
	cout << "¡á¡¡¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡¡¡ã¡ã¡ã¡¡¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á  ¡á" << endl;
	cout << "¡á¡¡¡á¡¡¡¡¡¡¡¡¡¡¡á¡¡¡¡¡¡¡¡¡¡¡á¡¡¡¡  ¡¡¡¡¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡á¡¡¡¡¡¡  ¡¡¡á¡¡¡¡¡¡¡¡  ¡á¡¡  ¡¡¡¡¡¡¡á¡¡¡á" << endl;
	cout << "¡á¡¡¡á¡¡ 1-1¡¡¡¡¡á¡¡ 1-2¡¡¡¡¡á¡¡ 1-3¡¡¡¡¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡á¡¡È­Àå½Ç¡¡¡á¡¡¼¼Å¹½Ç¡¡¡á°Ý¸®»ýÈ°°ü¡á¡¡¡á" << endl;
	cout << "¡á¡¡¡á¡¡¡¡¡¡¡¡¡¡¡á¡¡¡¡¡¡¡¡¡¡¡á¡¡¡¡  ¡¡¡¡¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡á¡¡¡¡¡¡¡¡¡¡¡á¡¡¡¡¡¡¡¡  ¡á¡¡¡¡¡¡¡¡¡¡¡á¡¡¡á" << endl;
	cout << "¡á  ¡á¡á¡á¡á¡á¡ã¡á¡á¡á¡á¡á¡ã¡á¡á¡á¡á¡á¡ã¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡á¡ã¡á¡á¡á¡á¡á¡ã¡á¡á¡á¡á¡á¡ã¡á¡á¡á¡á¡á  ¡á" << endl;
	cout << "¡á¡¡¡á¡¡¡¡¡¡¡¡¡¡¡¡2Ãþ ¼­Æí¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡ 2Ãþ Áß¾Ó º¹µµ¡¡  ¡¡2Ãþ µ¿Æí¡¡¡¡¡¡Ä­¸·ÀÌ¡¡¡¡¡¡¡¡¡¡¡á¡¡¡á" << endl;
	cout << "¡á¡¡¡á¡á¡á¡á¡á¡å¡á¡á¡á¡á¡á¡å¡á¡á¡á¡á¡á¡å¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡á¡å¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡å¡á¡á¡á¡á¡á  ¡á" << endl;
	cout << "¡á¡¡¡á¡¡¡¡¡¡¡¡¡¡¡á¡¡¡¡¡¡¡¡¡¡¡á¡¡¡¡¡¡  ¡¡¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡á¡¡¡¡  ¡¡¡¡¡¡¡¡¡¡  ¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡á¡¡¡á" << endl;
	cout << "¡á¡¡¡á¡¡ 2-1¡¡¡¡¡á¡¡ 2-2¡¡¡¡¡á¡¡ 2-3  ¡¡¡á¡¡¡¡¡¡¡¡¡¡¡¡  ¡á ¡¡2Áß´ë ÇàÁ¤¹Ý ¡¡¡á¡¡°£ºÎ¿¬±¸½Ç¡¡¡á¡¡¡á" << endl;
	cout << "¡á¡¡¡á¡¡¡¡¡¡¡¡¡¡¡á¡¡¡¡¡¡¡¡¡¡¡á¡¡¡¡¡¡  ¡¡¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡á  ¡¡¡¡¡¡¡¡¡¡¡¡¡¡  ¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡á¡¡¡á" << endl;
	cout << "¡á  ¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡¡¡¡¡¡¡¡¡¡¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á  ¡á" << endl;
	cout << "¡á¡¡¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡á¡¡¡¡¡¡¡¡  ¡¡¡¡¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡á¡¡¡¡¡¡  ¡¡¡¡¡¡¡¡¡á¡¡  ¡¡¡¡  ¡¡¡¡¡¡¡á¡¡¡á" << endl;
	cout << "¡á¡¡¡á¡¡¡¡ÃÑ±âÇÔ½Ç¡¡¡¡¡¡¡á¡¡¡¡ÀÎ»ç°ú¡¡¡¡¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡á¡¡¡¡±º¼ö°ú¡¡¡¡¡¡¡á¡¡Åë½Å¹°ÀÚÃ¢°í¡¡¡á¡¡¡á" << endl;
	cout << "¡á¡¡¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡á¡¡¡¡¡¡¡¡  ¡¡¡¡¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡á¡¡  ¡¡¡¡¡¡¡¡¡¡¡¡¡á¡¡¡á" << endl;
	cout << "¡á  ¡á¡á¡á¡á¡á¡á¡á¡á¡á¡ã¡á¡á¡á¡á¡á¡á¡á¡ã¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡á¡ã¡á¡á¡á¡á¡á¡á¡á¡á¡ã¡á¡á¡á¡á¡á¡á¡á¡á  ¡á" << endl;
	cout << "¡á¡¡¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡ 1Ãþ Áß¾Ó º¹µµ¡¡  ¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡á¡¡¡á" << endl;
	cout << "¡á¡¡¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡å¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡á¡å¡á¡á¡á¡á¡á¡á¡á¡á¡å¡á¡á¡á¡á¡á¡á¡á¡á  ¡á" << endl;
	cout << "¡á¡¡¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡  ¡¡¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡á¡¡¡¡  ¡¡¡¡¡¡¡¡¡¡¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡á¡¡¡á" << endl;
	cout << "¡á¡¡¡á ¡¡¡¡¡¡¡¡¡¡ÁöÈÖ ÅëÁ¦½Ç¡¡¡¡¡¡¡¡¡¡¡¡¡á¡¡¡¡¡¡¡¡¡¡¡¡  ¡á¡¡ÁÖÀÓ ¿ø»ç½Ç ¡¡¡á¡¡¡¡´ë´ëÀå½Ç¡¡¡¡¡á¡¡¡á" << endl;
	cout << "¡á¡¡¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡  ¡¡¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡á  ¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡á¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡á¡¡¡á" << endl;
	cout << "¡á  ¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á  ¡á" << endl;
	cout << "¡á                                                                                              ¡á" << endl;
	cout << "¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á" << endl;
	cout << "¡á  ¡¡¡¡¡¡¡¡¡¡¡¡¡¡                                                                              ¡á" << endl;
	cout << "¡á           ¡¡¡¡                                                                               ¡á" << endl;
	cout << "¡á                                                                                              ¡á" << endl;
	cout << "¡á                                                                                              ¡á" << endl;
	cout << "¡á                                                                                              ¡á" << endl;
	cout << "¡á                                                                                              ¡á" << endl;
	cout << "¡á                                                                                              ¡á" << endl;
	cout << "¡á                                                                                              ¡á" << endl;
	cout << "¡á                                                                                              ¡á" << endl;
	cout << "¡á                                                                                              ¡á" << endl;
	cout << "¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á" << endl;
}

