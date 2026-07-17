#include <iostream>
#include <windows.h>
#include <random>
#include "Game.h"

void SnakeGame::Game::Render() {
    renderSnakeMovement();
    Print();
    if (snake.HeadPosition == FoodPosition)
    {
        snake.SnakeLen++;
        renderFoodPosition();
    }
    Sleep(500);
}

void SnakeGame::Game::renderSnakeMovement()
{
    if (GetKeyState('A') & 0x8000 && (snake.MovingDirection == Up || snake.MovingDirection == Down))
    {
        snake.Move(Left);
    }
    else if (GetKeyState('D') & 0x8000 && (snake.MovingDirection == Up || snake.MovingDirection == Down))
    {
        snake.Move(Right);
    }
    else if (GetKeyState('W') & 0x8000 && (snake.MovingDirection == Right || snake.MovingDirection == Left))
    {
        snake.Move(Up);
    }
    else if (GetKeyState('S') & 0x8000 && (snake.MovingDirection == Right || snake.MovingDirection == Left))
    {
        snake.Move(Down);
    }
    else
    {
        snake.Move(snake.MovingDirection);
    }

    if (false)
    {
        std::cout << "( " << snake.HeadPosition.x << " , " << snake.HeadPosition.y << " )      ";
        std::cout << "( " << FoodPosition.x << " , " << FoodPosition.y << " )\n";
    }

}

void SnakeGame::Game::renderFoodPosition() {
    FoodPosition.x = 1 + rand() % (BoardSize.x - 1);
    FoodPosition.y = 1 + rand() % (BoardSize.y - 1);
}

void SnakeGame::Game::Print() {
    system("cls");
    for (int i = 0; i < this->BoardSize.x+1; i++)
    {
        for (int j = 0; j < this->BoardSize.y+1; j++)
        {
            if (i == 0 || i == this->BoardSize.x)
            {
                std::cout << " - ";
            }
            else if (j == 0 || j == this->BoardSize.y)
            {
                std::cout << " | ";
            }
            else if (snake.HeadPosition.x == j && snake.HeadPosition.y == i)
            {
                std::cout << " O ";
            }
            else if (FoodPosition.x == j && FoodPosition.y == i)
            {
                std::cout << " x ";
            }
            else
            {
                std::cout << "   ";
            }

            if (j == this->BoardSize.y)
            {
                std::cout << '\n';
            }
        }
    }
}