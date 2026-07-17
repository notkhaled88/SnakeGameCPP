#pragma once

#include"ModelsLib.h"
#include"Snake.h"
namespace SnakeGame {
	class Game
	{
	public :
		Game() {
			renderFoodPosition();
		}
		Position BoardSize;
		Snake snake;
		Position FoodPosition;
		void Render();
	private:
		void renderSnakeMovement();
		void renderFoodPosition();
		void Print();
	};
}