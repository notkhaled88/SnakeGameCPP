#include "Snake.h"
#include <stdexcept>
#include <iostream>

void SnakeGame::Snake::Move(Direction direction)
{
	// new node Position
	// (0,0) -> (1,0) -> (2,0)
	// (1,0) -> (2,0) -> new Position
	if (this->Head.Next != nullptr)
	{
		this->Head.Next->PassValue(this->Head.position.x, this->Head.position.y);
	}
	// new Position of the head based on the direction
	switch (direction)
	{
		case Right:
			this->Head.position.x++;
			break;
		case Left:
			this->Head.position.x--;
			break;
		case Up:
			this->Head.position.y--;
			break;
		case Down:
			this->Head.position.y++;
			break;
	}
	if (IsSnake(this->Head.position.x, this->Head.position.y))
	{
		this->IsAlive = false;
	}
	this->MovingDirection = direction;
}
void SnakeGame::Snake::Grow()
{
	SnakeGame::SnakeNode* newTail = new SnakeGame::SnakeNode{};
	switch (this->MovingDirection)
	{
	case Right:
		newTail->position.x = this->Tail->position.x - 1;
		newTail->position.y = this->Tail->position.y;
		break;
	case Left:
		newTail->position.x = this->Tail->position.x +1;
		newTail->position.y = this->Tail->position.y;
		break;
	case Up:
		newTail->position.x = this->Tail->position.x;
		newTail->position.y = this->Tail->position.y +1;
		break;
	case Down:
		newTail->position.x = this->Tail->position.x;
		newTail->position.y = this->Tail->position.y - 1;
		break;
	default:
		throw std::invalid_argument("un valid direction");
	}

	this->Tail->Next = newTail;
	this->Tail = newTail;

}
bool SnakeGame::Snake::IsSnake(int x, int y)
{
	if (this->Head.Next == nullptr)
	{
		return false;
	}
	SnakeNode* node = this->Head.Next;
	while (node != nullptr)
	{
		if (node->position.x == x && node->position.y == y)
		{
			return true;
		}
		node = node->Next;
	}
	return false;
}