#include "Obstacles.h"

void Obstacles::update(Player& player, RenderWindow& window, float time, Score& score)
{
    for (coordinates& obstacle : obstacles) {
        if (player.x <= obstacle.x + 60 && 
            player.x >= obstacle.x - 60 &&
            player.y < obstacle.y + 60 &&
            player.y > obstacle.y - 60)
        {
            loser = true;
        }

        if (obstacle.y < obstacles[obstacles.size() - 1].y + 500)
        {
            coordinates newObstacles;
            newObstacles.x = rand() % windowWidth;
            newObstacles.y = obstacles[obstacles.size() - 1].y - (windowHeight / 3);
            obstacles.push_back(newObstacles);
        }

        for (vector<coordinates>::iterator it = obstacles.begin(); it != obstacles.end(); ++it)
        {
            if (player.y < obstacle.y - 320)
            {
                score.updateScore();
                obstacles.erase(it);
                break;
            }
        }

        obstacle.y += (gravity * time);
        sprite.setPosition(obstacle.x, obstacle.y);
        window.draw(sprite);
    }
}