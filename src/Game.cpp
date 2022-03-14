#include "Game.hpp"

#include "Snake.hpp"

namespace Game
{
	Game::eGameErrors Game::init()
	{
		//write load textures names from json or xml for load textures with loop
		//for (int i = 0; i < count_objects; i++) {
			if (!game_objects[0].first.loadFromFile("none.png")) {
				return eGameErrors::TEXTURE_NOT_LOAD;
			}

			if (!game_objects[1].first.loadFromFile("snake.png")) {
				return eGameErrors::TEXTURE_NOT_LOAD;
			}

			game_objects[0].second.setTexture(game_objects[0].first);
			game_objects[1].second.setTexture(game_objects[1].first);
		//}

		return eGameErrors::SUCCES;
	}

	void Game::clear_field(const Snake& _snake)
	{
		for (int i = 0; i < field_size_x; i++) {
			for (int j = 0; i < field_size_y; i++) {
				field[i][j] = int(eFieldType::FIELD_CELL_NULL);
			}
		}

		for (int i = 0; i < _snake.snake_length; i++) {
			field[_snake.snake_position_y][_snake.snake_position_x - 1] = _snake.snake_length - i;
		}
	}

	void Game::draw(sf::RenderWindow& _window)
	{
		for (int i = 0; i < field_size_x; i++) {
			for (int j = 0; j < field_size_y; j++) {
				switch (field[i][j])
				{
					case static_cast<int>(eFieldType::FIELD_CELL_NULL):
						game_objects[0].second.setPosition(sf::Vector2f(float(i * cell_size), float(j * cell_size)));
						_window.draw(game_objects[0].second);
						break;
					default:
						game_objects[1].second.setPosition(sf::Vector2f(float(i * cell_size), float(j * cell_size)));
						_window.draw(game_objects[1].second);
				}
			}
		}
	}
}