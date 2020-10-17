#define _CRT_SECURE_NO_WARNINGS
#include <bangtal>
#include <iostream>

using namespace bangtal;
using namespace std;

int main() {
	setGameOption(GameOption::GAME_OPTION_INVENTORY_BUTTON, false);
	setGameOption(GameOption::GAME_OPTION_MESSAGE_BOX_BUTTON, false);

	auto scene0 = Scene::create("", "Images/시작화면.png");
	auto scene = Scene::create("COVID-19", "Images/세계지도.png");
	auto scene1 = Scene::create("COVID-19", "Images/세계지도.png");

	auto bgm = Sound::create("Sounds/bgm.mp3");
	bgm->play();
	auto kill = Sound::create("Sounds/kill.mp3");

	ObjectPtr board_1[16];
	ObjectPtr board_2[16];
	int mix_1 = 10;
	int mix_2 = 10;
	for (int i = 0; i < 16; i++) {
		string covid = "Images/" + to_string(i + 1) + ".png";
		board_1[i] = Object::create(covid, scene, 40 + (i % 4) * 150, 510 - (i / 4) * 150);
		board_1[i]->setOnMouseCallback([=](ObjectPtr object, int, int, MouseAction)->bool {
			int j;
			for (j = 0; j < 16; j++) {
				if (board_1[j] == object)
					break;
			}
			if (j == i) {
				object->hide();
				kill->play();
			}
			return true;
			});
		board_2[i] = Object::create(covid, scene, 640 + (i % 4) * 150, 510 - (i / 4) * 150);
		board_2[i]->setOnMouseCallback([=](ObjectPtr object, int, int, MouseAction)->bool {
			int j;
			for (j = 0; j < 16; j++) {
				if (board_2[j] == object)
					break;
			}
			if (j == i) {
				object->hide();
				kill->play();
			}
			return true;
			});
	}

	auto count = 0;
	auto timer = Timer::create(0.01f);
	timer->setOnTimerCallback([&](TimerPtr timer1)->bool {
		int j = 0, k = 0;
		do {
			switch (rand() % 4) {
			case 0: j = mix_1 - 1, k = mix_2 - 1; break;
			case 1: j = mix_1 + 1, k = mix_2 + 1; break;
			case 2: j = mix_1 - 4, k = mix_2 - 4; break;
			case 3: j = mix_1 + 4, k = mix_2 + 4; break;
			}
		} while (j < 0 || j > 15 || !((j % 4 > 0 && j - 1 == mix_1) || (j % 4 < 3 && j + 1 == mix_1) || (j > 3 && j - 4 == mix_1) || (j < 12 && j + 4 == mix_1)));
		board_1[j]->locate(scene, 40 + (mix_1 % 4) * 150, 510 - (mix_1 / 4) * 150);
		board_1[mix_1]->locate(scene, 40 + (j % 4) * 150, 510 - (j / 4) * 150);
		auto object_1 = board_1[j];
		board_1[j] = board_1[mix_1];
		board_1[mix_1] = object_1;
		mix_1 = j;
		while (k < 0 || k > 15 || !((k % 4 > 0 && k - 1 == mix_2) || (k % 4 < 3 && k + 1 == mix_2) || (k > 3 && k - 4 == mix_2) || (k < 12 && k + 4 == mix_2)));
		board_2[k]->locate(scene, 640 + (mix_2 % 4) * 150, 510 - (mix_2 / 4) * 150);
		board_2[mix_2]->locate(scene, 640 + (k % 4) * 150, 510 - (k / 4) * 150);
		auto object_2 = board_2[k];
		board_2[k] = board_2[mix_2];
		board_2[mix_2] = object_2;
		mix_2 = k;

		count++;
		if (count < 100000) {
			timer1->set(0.01f);
			timer1->start();
		}
		return true;
		});

	auto start_button = Object::create("Images/start.png", scene0, 1100, 50);
	start_button->setScale(1.5f);
	start_button->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		scene->enter();
		showMessage("세계에 퍼진 코로나를 잡아라!");
		bgm->stop();
		timer->start();
		return true;
		});

	ObjectPtr board_3[25];
	ObjectPtr board_4[25];
	int mix_3 = 18;
	int mix_4 = 18;
	for (int i = 0; i < 25; i++) {
		string covid_1 = "Images1/" + to_string(i + 1) + ".png";
		board_3[i] = Object::create(covid_1, scene1, 40 + (i % 5) * 120, 540 - (i / 5) * 120);
		board_3[i]->setOnMouseCallback([=](ObjectPtr object, int, int, MouseAction)->bool {
			int j;
			for (j = 0; j < 25; j++) {
				if (board_3[j] == object)
					break;
			}
			if (j == i) {
				object->hide();
				kill->play();
			}
			return true;
			});
		board_4[i] = Object::create(covid_1, scene1, 640 + (i % 5) * 120, 540 - (i / 5) * 120);
		board_4[i]->setOnMouseCallback([=](ObjectPtr object, int, int, MouseAction)->bool {
			int j;
			for (j = 0; j < 25; j++) {
				if (board_4[j] == object)
					break;
			}
			if (j == i) {
				object->hide();
				kill->play();
			}
			return true;
			});
	}

	auto count_1 = 0;
	auto timer_1 = Timer::create(0.01f);
	timer_1->setOnTimerCallback([&](TimerPtr timer1)->bool {
		int j = 0, k = 0;
		do {
			switch (rand() % 4) {
			case 0: j = mix_3 - 1, k = mix_4 - 1; break;
			case 1: j = mix_3 + 1, k = mix_4 + 1; break;
			case 2: j = mix_3 - 4, k = mix_4 - 4; break;
			case 3: j = mix_3 + 4, k = mix_4 + 4; break;
			}
		} while (j < 0 || j > 24 || !((j % 5 > 0 && j - 1 == mix_3) || (j % 5 < 4 && j + 1 == mix_3) || (j > 4 && j - 4 == mix_3) || (j < 20 && j + 4 == mix_3)));
		board_3[j]->locate(scene1, 40 + (mix_3 % 5) * 120, 540 - (mix_3 / 5) * 120);
		board_3[mix_3]->locate(scene1, 40 + (j % 5) * 120, 540 - (j / 5) * 120);
		auto object_3 = board_3[j];
		board_3[j] = board_3[mix_3];
		board_3[mix_3] = object_3;
		mix_3 = j;
		while (k < 0 || k > 24 || !((k % 5 > 0 && k - 1 == mix_4) || (k % 5 < 4 && k + 1 == mix_4) || (k > 4 && k - 4 == mix_4) || (k < 20 && k + 4 == mix_4)));
		board_4[k]->locate(scene1, 640 + (mix_4 % 5) * 120, 540 - (mix_4 / 5) * 120);
		board_4[mix_4]->locate(scene1, 640 + (k % 5) * 120, 540 - (k / 5) * 120);
		auto object_4 = board_4[k];
		board_4[k] = board_4[mix_4];
		board_4[mix_4] = object_4;
		mix_4 = k;

		count_1++;
		if (count_1 < 100000) {
			timer1->set(0.01f);
			timer1->start();
		}
		return true;
		});

	auto next_button = Object::create("Images/next.png", scene, 1200, 30);
	next_button->setScale(0.5f);
	next_button->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		scene1->enter();
		showMessage("더 강해진 코로나를 모두 잡아라!");
		timer_1->start();
		return true;
		});

	auto finish_button = Object::create("Images/finish.png", scene1, 1200, 30);
	finish_button->setScale(0.5f);
	finish_button->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		cout << "I want the COVID-19 to end" << endl;
		endGame();
		return true;
		});

	startGame(scene0);

	return 0;
}