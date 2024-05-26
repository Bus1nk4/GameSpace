#include "Player.h"

void Player::playerMove(float time)
{
    if (Keyboard::isKeyPressed(Keyboard::A)) {
        if (x <= 5) x = winWidth - 5;
        else x -= (speed * time);
    }
    if (Keyboard::isKeyPressed(Keyboard::D)) {
        if (x >= (winWidth - 5)) x = 5;
        else x += (speed * time);
    }
    if (Keyboard::isKeyPressed(Keyboard::S)) {
        if (y >= (winHeight - 5)) y = 5;
        else y += (speed * time);
    }
    if (Keyboard::isKeyPressed(Keyboard::W)) {
        if (y <= 5) y = winHeight + 5;
        else y -= (speed * time);
    }

    sprite.setPosition(x, y);
}