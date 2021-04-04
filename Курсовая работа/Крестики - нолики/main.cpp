#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include "Box.h"
#include "Laticce.h"
#include "Menu.h"
#include "GameState.h"
using namespace sf;
using namespace std;

int main()
{
	srand(time(0));
	RenderWindow win(VideoMode(300, 200), "ZeroGame");
	win.setFramerateLimit(120);
	// ===
	GameState game_state = GameState::MENU;
	Texture texture;
	texture.loadFromFile("background.jpg");
	Sprite sprite(texture);
	sprite.setScale(0.14, 0.1);
	SoundBuffer buffer;
	buffer.loadFromFile("click.ogg");// тут загружаем в буфер что то
	Sound sound;
	sound.setBuffer(buffer);

	Music sound_back;
	sound_back.openFromFile("background_music.ogg");
	sound_back.play();

	const int SET_BOX[8][3]{
		{0, 1, 2},
		{3, 4, 5},
		{6, 7, 8},
		{0, 3, 6},
		{1, 4, 7},
		{2, 5, 8},
		{0, 4, 8},
		{2, 4, 6}
	};

	// ===
	Laticce laticce;
	Box::Type user_box = Box::CROSS;
	Box::Type player_box = Box::ZERO;
	int event_time = 0;

	// vector box
	vector<Box> vector_box;
	for (int y = 0; y < 3; y++) {
		for (int x = 0; x < 3; x++) {
			vector_box.push_back(Box(70 + (x * 60), 20 + (y * 60)));
		}
	}
	
	Menu menu;
	while (win.isOpen()) {
		Event event;
		while (win.pollEvent(event)) {
			if (event.type == Event::Closed) {
				win.close();
			}
			if (event.type == Event::MouseButtonPressed) {
				sound.play();
			}
		}
		switch (game_state) {
		case GameState::MENU:
		{
			menu.setParam(game_state, user_box, win);
		}
		break;
		case GameState::RUN:
		{			
			if (player_box == user_box && Mouse::isButtonPressed(Mouse::Left)) {
				Vector2i pos = Mouse::getPosition(win);
				for (int i = 0, n = vector_box.size(); i < n; i++) {
					if (vector_box[i].getType() == Box::DEFAULT && vector_box[i].isMouseClick(pos)) {
						vector_box[i].setType(user_box);
						player_box = (player_box == Box::ZERO) ? Box::CROSS : Box::ZERO;
					}
				}
			}

			// Full box
			bool full_box = true;
			for (int i = 0, z = 1, c = 1; i < 8; i++) {
				for (int j = 0; j < 3; j++) {
					if (vector_box[SET_BOX[i][j]].getType() != Box::CROSS) c = 0;
					if (vector_box[SET_BOX[i][j]].getType() != Box::ZERO) z = 0;
					if (vector_box[SET_BOX[i][j]].getType() == Box::DEFAULT) full_box = false;
				}
				if (z == 1 || c == 1) {
					for (int j : SET_BOX[i])
						vector_box[j].setAnim();
					game_state = GameState::ANIM;
					event_time = 120;
					full_box = false;
					break;
				}
				z = c = 1;
			}

			if (full_box) {
				for (Box& box : vector_box) {
					box.setAnim();
				}
				game_state = GameState::ANIM;
				event_time = 120;
			}

			// PC
			if (player_box != user_box) {
				int arr[9];
				int count = 0;
				for (int i = 0, n = vector_box.size(); i < n; i++) {
					if (vector_box[i].getType() == Box::DEFAULT) {
						arr[count++] = i;
					}
				}

				// logic pc game
				switch (count) {
				case 2:
				{
					int flag = 0;
					for (int i = 0; i < 8; i++) {
						int user_value = 0, pc_value = 0, default_value = -1; // пк не между противника
						for (int j = 0; j < 3; j++) {
							if (vector_box[SET_BOX[i][j]].getType() == user_box) { user_value++; }
							if (vector_box[SET_BOX[i][j]].getType() == player_box) { pc_value++; }
							if (vector_box[SET_BOX[i][j]].getType() == Box::DEFAULT) { default_value = SET_BOX[i][j]; }
						}
						printf("default = %d\nuser_value = %d\npc_value = %d\n\n", default_value, user_value, pc_value);
						if (user_value == 0 && pc_value == 2 && default_value != -1) {
							vector_box[default_value].setType(player_box);
							flag = 1;
							break;
						}
					}
					if (flag == 0) {
						for (int i = 0; i < 8; i++) {
							int user_value = 0, pc_value = 0, default_value = -1; // пк не между противника
							for (int j = 0; j < 3; j++) {
								if (vector_box[SET_BOX[i][j]].getType() == user_box) { user_value++; }
								if (vector_box[SET_BOX[i][j]].getType() == player_box) { pc_value++; }
								if (vector_box[SET_BOX[i][j]].getType() == Box::DEFAULT) { default_value = SET_BOX[i][j]; }
							}
							printf("default = %d\nuser_value = %d\npc_value = %d\n\n", default_value, user_value, pc_value);
							if (user_value == 2 && pc_value == 0 && default_value != -1) {
								vector_box[default_value].setType(player_box);
								flag = 2;
								break;
							}
						}
					}
					if (flag == 0) {
						vector_box[arr[static_cast<int>(rand() % count)]].setType(player_box);
					}
				}
				break;

				case 4:
				{
					int flag = 0;
					for (int i = 0; i < 8; i++) {
						int user_value = 0, pc_value = 0, default_value = -1; // пк не между противника
						for (int j = 0; j < 3; j++) {
							if (vector_box[SET_BOX[i][j]].getType() == user_box) { user_value++; }
							if (vector_box[SET_BOX[i][j]].getType() == player_box) { pc_value++; }
							if (vector_box[SET_BOX[i][j]].getType() == Box::DEFAULT) { default_value = SET_BOX[i][j]; }
						}
						printf("default = %d\nuser_value = %d\npc_value = %d\n\n", default_value, user_value, pc_value);
						if (user_value == 0 && pc_value == 2 && default_value != -1) {
							vector_box[default_value].setType(player_box);
							flag = 1;
							break;
						}
					}
					if (flag == 0) {
						for (int i = 0; i < 8; i++) {
							int user_value = 0, pc_value = 0, default_value = -1; // пк не между противника
							for (int j = 0; j < 3; j++) {
								if (vector_box[SET_BOX[i][j]].getType() == user_box) { user_value++; }
								if (vector_box[SET_BOX[i][j]].getType() == player_box) { pc_value++; }
								if (vector_box[SET_BOX[i][j]].getType() == Box::DEFAULT) { default_value = SET_BOX[i][j]; }
							}
							if (user_value == 2 && pc_value == 0 && default_value != -1) {
								vector_box[default_value].setType(player_box);
								flag = 2;
								break;
							}
						}
					}
					if (flag == 0) {
						for (int i = 0; i < 8; i++) {
							int user_value = 0, pc_value = 0, default_value = -1; // пк не между противника
							for (int j = 0; j < 3; j++) {
								if (vector_box[SET_BOX[i][j]].getType() == user_box) { user_value++; }
								if (vector_box[SET_BOX[i][j]].getType() == player_box) { pc_value++; }
								if (vector_box[SET_BOX[i][j]].getType() == Box::DEFAULT) { default_value = SET_BOX[i][j]; }
							}
							if (user_value == 0 && pc_value == 1 && default_value != -1) {
								vector_box[default_value].setType(player_box);
								break;
							}
						}
					}

				}
				break;

				case 6:
				{
					int flag = 0;
					for (int i = 0; i < 8; i++) {
						int user_value = 0, pc_value = 0, default_value = -1; // пк не между противника
						for (int j = 0; j < 3; j++) {
							if (vector_box[SET_BOX[i][j]].getType() == user_box) { user_value++; }
							if (vector_box[SET_BOX[i][j]].getType() == player_box) { pc_value++; }
							if (vector_box[SET_BOX[i][j]].getType() == Box::DEFAULT) { default_value = SET_BOX[i][j]; }
						}
						if (user_value == 2 && pc_value == 0 && default_value != -1) {
							vector_box[default_value].setType(player_box);
							flag = 1;
							break;
						}
						if (user_value == 2 && pc_value == 1) {
							flag = 2;
							break;
						}
					}
					if (flag == 2 || flag == 0) {
						for (int i = 0; i < 8; i++) {
							int user_value = 0, pc_value = 0, default_value = -1; // пк не между противника
							for (int j = 0; j < 3; j++) {
								if (vector_box[SET_BOX[i][j]].getType() == user_box) { user_value++; }
								if (vector_box[SET_BOX[i][j]].getType() == player_box) { pc_value++; }
								if (vector_box[SET_BOX[i][j]].getType() == Box::DEFAULT) { default_value = SET_BOX[i][j]; }
							}
							printf("default = %d\nuser_value = %d\npc_value = %d\n\n", default_value, user_value, pc_value);
							if (user_value == 0 && pc_value == 1 && default_value != -1) {
								vector_box[default_value].setType(player_box);
								break;
							}
						}
					}
				}
				break;

				case 8:
				{
					vector_box[arr[static_cast<int>(rand() % count)]].setType(player_box);
				}
				break;
				default:
					break;
				}
				player_box = user_box;
			}
		}
		break;
		case GameState::ANIM:
		{
			if (event_time == 0) {
				for (Box& box : vector_box) {
					box.restart();
				}
				game_state = GameState::RUN;
			}
			else {
				event_time--;
			}
		}
		break;
		}

		win.clear(Color(206, 230, 242));
		win.draw(sprite);
		if (game_state == GameState::MENU) {
			menu.draw(win);
		}
		else {
			laticce.draw(win);
			for (Box& box : vector_box) {
				box.draw(win);
			}
		}

		win.display();
	}

	return 0;
}