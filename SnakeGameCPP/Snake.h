#pragma once
#include "ModelsLib.h"
namespace SnakeGame
{
	class Snake
	{
		public:
			Position HeadPosition;
			Direction MovingDirection = Right;
			int SnakeLen = 0;
			void Move(Direction direction);
	
	};
}