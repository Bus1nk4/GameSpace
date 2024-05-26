#pragma once

#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

class Player
{
private:
	Texture texture;
	int winWidth = 700;
	int winHeight = 900;
public:
	Sprite sprite;
	float x, y;
	float speed;

	Player(float startX, float startY, const string& textureFile) : x(startX), y(startY), speed(0.6f) {
		texture.loadFromFile(textureFile);
		sprite.setTexture(texture);
		sprite.setPosition(startX, startY);
	}

	//Ship movement 
	void playerMove(float time);
};