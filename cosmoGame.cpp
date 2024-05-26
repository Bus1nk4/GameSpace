#include "Player.h"
#include "Obstacles.h"
#include "Score.h"

#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

enum class Game {
	menu,
	game,
	win,
	lose
};

int main()
{
	RenderWindow window(VideoMode(700, 900), L"Звёздный защитник!"); //Создание окна
	Image icon; //Установка иконки для окна
	icon.loadFromFile("Image/icon.png");
	window.setIcon(33, 32, icon.getPixelsPtr());

	//Фон
	Texture textureSpace;
	textureSpace.loadFromFile("Image/kosmo.png");
	RectangleShape gamingBackground(Vector2f(700, 900));
	gamingBackground.setTexture(&textureSpace);

	//Победа
	Texture textWin;
	textWin.loadFromFile("Image/youWin.png");
	RectangleShape gamingWin(Vector2f(700, 900));
	gamingWin.setTexture(&textWin);
	//Поражение
	Texture textLose;
	textLose.loadFromFile("Image/youLose.png");
	RectangleShape gamingLose(Vector2f(700, 900));
	gamingLose.setTexture(&textLose);
	//Меню
	//Texture textMenu;
	//textMenu.loadFromFile("Image/youLose.png");
	//RectangleShape gamingMenu(Vector2f(700, 900));
	//gamingMenu.setTexture(&textMenu);

	Player player(330, 500, "Image/ship.png");
	Obstacles obstacles(330, 500, "Image/obstacles.png");
	Score score;

	Clock clock;
	Game state = Game::game;

	while (window.isOpen())
	{
		float time = clock.getElapsedTime().asMicroseconds(); //Время 
		time /= 800;
		clock.restart();

		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed || Keyboard::isKeyPressed(Keyboard::Escape)) //Закрытие окна
				window.close();
			if (Keyboard::isKeyPressed(Keyboard::R)) {
				state = Game::game;
			}
		}

		switch (state)
		{
		case Game::game:
			if (score.score == 1000) {
				state = Game::win;
			}
			if (obstacles.loser) {
				state = Game::lose;
				obstacles.loser = false;
			}
			window.clear();
			window.draw(gamingBackground);
			player.playerMove(time);
			window.draw(player.sprite);
			obstacles.update(player, window, time, score);
			window.draw(score.scoreText);
			score.scoreText.setPosition(10, 10);
			window.display();
			break;

		case Game::win:
			if (Keyboard::isKeyPressed(Keyboard::R)) {
				state = Game::game;
			}
			score.score = 0;
			window.clear();
			window.draw(gamingWin);
			window.display();
			break;

		case Game::lose:
			if (Keyboard::isKeyPressed(Keyboard::R)) {
				state = Game::game;
			}
			window.clear();
			window.draw(gamingLose);
			window.draw(score.scoreText);
			score.scoreText.setPosition(275, 730);
			window.display();
			score.score = 0;
			break;
		}
	}

	return 0;
}