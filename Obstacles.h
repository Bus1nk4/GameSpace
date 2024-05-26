#pragma once
#include "Player.h"
#include "Score.h"

class Obstacles
{
private:
    Texture platformTexture;
public:
    const int windowHeight = 900;
    const int windowWidth = 700;

    struct coordinates {
        int x, y;
    };

    vector <coordinates> obstacles;
    Sprite sprite;
    float gravity;
    bool loser = false;

    Obstacles(int initialX, int initialY, const string& TextureFile) : gravity(0.4f) {
        platformTexture.loadFromFile(TextureFile);
        sprite.setTexture(platformTexture);
        sprite.setPosition(initialX, initialY);

        coordinates obstacle;
        obstacle.x = 170;
        obstacle.y = 630;
        obstacles.push_back(obstacle);

        for (int i = 0; i < 6; i++) {
            obstacle.x = rand() % windowWidth;
            obstacle.y = windowHeight - (windowHeight / 3) * i + 60;
            obstacles.push_back(obstacle);
        }
    }

    void update(Player& player, RenderWindow& window, float time, Score& score);
};