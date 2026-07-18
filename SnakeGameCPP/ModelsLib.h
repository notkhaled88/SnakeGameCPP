#pragma once

namespace SnakeGame {

	struct Position {
		int x{ 0 };
		int y{ 0 };
		bool operator == (const Position& other) const {
			return (x == other.x && y == other.y);
		}
	};
	struct SnakeNode
	{
		Position position;
		SnakeNode* Next;
		void PassValue(int x, int y)
		{
			if (Next == nullptr)
			{
				position.x = x;
				position.y = y;
				return;
			}
			else {
				Next->PassValue(position.x, position.y);
				position.x = x;
				position.y = y;
				return;
			}
		}
	};
	
	enum Direction
	{
		Left,
		Right,
		Up,
		Down
	};
}