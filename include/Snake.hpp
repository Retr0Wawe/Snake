#ifndef _SNAKE_HPP_
#define _SNAKE_HPP_

#include "Game.hpp"

namespace Game
{
	class Snake
	{
	public:
		Snake();

		~Snake();
	public:
		friend void Game::clear_field(const Snake& _snake);
	private:
		int snake_position_x, snake_position_y;
		int snake_length;
	};
}

#endif // _SNAKE_HPP_
