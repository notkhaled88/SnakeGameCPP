#pragma once

namespace SnakeGame {

	struct Position {
		int x{ 0 };
		int y{ 0 };
		bool operator == (const Position& other) const {
			return (x == other.x && y == other.y);
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