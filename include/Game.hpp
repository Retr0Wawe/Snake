#ifndef _GAME_HPP_
#define _GAME_HPP_

#include <SFML/Graphics.hpp>
#include <iostream>
#include <array>

#include "Defines.hpp"

namespace Main
{
	using field_array = std::array<std::array<int, field_size_y>, field_size_x>;

	class Game;		//declaration

	class Snake
	{
		friend class Game;
	public:
		enum class eSnakeMove
		{
			MOVE_RIGHT, MOVE_LEFT, MOVE_UP, MOVE_DOWN
		};
	public:
		Snake() noexcept;

		Snake(const Snake& _snake);

		Snake(int _length, int _xpos, int _ypos, eSnakeMove _snake_direction) noexcept;

		virtual ~Snake() noexcept;
	public:
		virtual Snake& operator=(const Snake& _snake) noexcept;
	public:
		int get_length() const noexcept;

		void move(Game& _game);
	protected:
		eSnakeMove snake_direction;
		int snake_xpos, snake_ypos;
		int snake_length;
	};

	class Game
	{
		using game_objects = std::pair<sf::Texture, sf::Sprite>;
		using game_event = sf::Event;
	public:
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

		void handle_keyboard() noexcept;
		
		virtual void draw(sf::RenderWindow& _window);

		friend void Snake::move(Game& _game);

		void spawn_apple();

		void clear_field();
	protected:
		game_objects cell_types[2];
		field_array field = { 0 };
		game_event event;
		Snake snake_obj;
	};
}

#endif // _GAME_HPP_
