#include "Score.h"

void Score::updateScore()
{
	score += 50;
	scoreText.setString("Score: " + to_string(score));
}