#include <iostream>
#include <windows.h>
#include <random>
#include "Game.h"

void SnakeGame::Game::Render() {
    renderSnakeMovement();
    Print();
    if (snake.Head.position == FoodPosition)
    {
        snake.SnakeLen++;
        snake.Grow();
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
        std::cout << "( " << snake.Head.position.x << " , " << snake.Head.position.y << " )      ";
        std::cout << "( " << FoodPosition.x << " , " << FoodPosition.y << " )\n";
    }

}

void SnakeGame::Game::renderFoodPosition() {
    FoodPosition.x = 1 + rand() % (BoardSize.x - 1);
    FoodPosition.y = 1 + rand() % (BoardSize.y - 1);
}

void SnakeGame::Game::Print() {
    system("cls");
    std::cout << "Snake Length = " << snake.SnakeLen << "\n";
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
            else if (snake.Head.position.x == j && snake.Head.position.y == i)
            {
                std::cout << " O ";
            }
            else if (snake.IsSnake(j, i))
            {
                std::cout << " o ";
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