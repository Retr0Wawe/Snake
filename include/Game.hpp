#ifndef _GAME_HPP_
#define _GAME_HPP_

#include <SFML/Graphics.hpp>
#include <iostream>
#include <array>

namespace Game
{
	constexpr int field_size_x = 35;
	constexpr int field_size_y = 25;
	constexpr int cell_size = 30;

	constexpr int window_width = field_size_x * cell_size;
	constexpr int window_height = field_size_y * cell_size;
	constexpr int count_objects = 1;

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
		Game() noexcept {};

		~Game() noexcept {};
	public:
		virtual eGameErrors init();

		virtual void draw(sf::RenderWindow& _window);

		virtual void clear_field(const class Snake& _snake);
	private:
		std::array<std::array<int, field_size_y>, field_size_x> field = { 0 };
		std::pair<sf::Texture, sf::Sprite> game_objects[count_objects];
	};
}

#endif // _GAME_HPP_
