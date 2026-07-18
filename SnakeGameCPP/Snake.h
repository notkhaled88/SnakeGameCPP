#pragma once
#include "ModelsLib.h"
namespace SnakeGame
{
	class Snake
	{
		public:
			SnakeNode Head;
			SnakeNode* Tail = &Head;
			int SnakeLen = 0;
			bool IsAlive = true;
			Direction MovingDirection = Right;
			void Grow();
			bool IsSnake(int x, int y);
			void Move(Direction direction);
	
	};
}