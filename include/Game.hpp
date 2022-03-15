#ifndef _GAME_HPP_
#define _GAME_HPP_

#include <SFML/Graphics.hpp>
#include <iostream>
#include <array>

#include "Defines.hpp"

namespace Game
{
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
		Game() noexcept;

		~Game() noexcept;
	public:
		virtual eGameErrors init();

		virtual void draw(sf::RenderWindow& _window);

		virtual void clear_field(const class Snake& _snake);
	private:
		std::array<std::array<int, field_size_y>, field_size_x> field = { 0 };
		std::pair<sf::Texture, sf::Sprite> game_objects[2];
	};
}

#endif // _GAME_HPP_
