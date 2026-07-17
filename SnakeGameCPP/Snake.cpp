#include "Snake.h"

void SnakeGame::Snake::Move(Direction direction)
{
	switch (direction)
	{
		case Right:
			this->HeadPosition.x++;
			break;
		case Left:
			this->HeadPosition.x--;
			break;
		case Up:
			this->HeadPosition.y--;
			break;
		case Down:
			this->HeadPosition.y++;
			break;
	}
	this->MovingDirection = direction;
}