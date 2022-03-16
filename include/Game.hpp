#ifndef _GAME_HPP_
#define _GAME_HPP_

#include <SFML/Graphics.hpp>
#include <iostream>
#include <array>

#include "Defines.hpp"
#include "Snake.hpp"

namespace Main
{
	using field_array = std::array<std::array<int, field_size_y>, field_size_x>;

	class Snake
	{
	public:
		friend class Game;

		enum class eSnakeMove
		{
			MOVE_RIGHT, MOVE_LEFT, MOVE_UP, MOVE_DOWN
		};
	public:
		Snake() noexcept;

		Snake(int length, int _xpos, int _ypos) noexcept;

		virtual ~Snake() noexcept;
	public:
		void move(field_array& _field) noexcept;

		int get_length() const noexcept;
	public:
		eSnakeMove snake_direction = eSnakeMove::MOVE_RIGHT;
		int snake_xpos, snake_ypos;
		int snake_length;
	};

	class Game
	{
		enum class eGameErrors
		{
			TEXTURE_NOT_LOAD = -1, SUCCES = 1
		};

		enum class eFieldType
		{
			FIELD_CELL_NULL, FIELD_CELL_ONE
		};
	public:
		Game(const Snake& _snake);

		~Game() noexcept;
	public:
		virtual eGameErrors init();

		virtual void clear_field();

		virtual void draw(sf::RenderWindow& _window);
	private:
		std::pair<sf::Texture, sf::Sprite> game_objects[2];
		field_array field = { 0 };
		Snake snake_obj;
	};
}

#endif // _GAME_HPP_
