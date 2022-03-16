#include "Game.hpp"

namespace Main
{
	Snake::Snake() noexcept : snake_length(3), snake_xpos(field_size_x / 2), 
		snake_ypos(field_size_y / 2), snake_direction(eSnakeMove::MOVE_RIGHT)
	{	}

	Snake::Snake(int _length, int _xpos, int _ypos, eSnakeMove _snake_direction = eSnakeMove::MOVE_RIGHT) noexcept :
		 snake_length(_length), snake_xpos(_xpos), snake_ypos(_ypos), snake_direction(_snake_direction)
	{	}

	Snake::~Snake() noexcept
	{	}

	void Snake::move(Game& _game)
	{
		switch (snake_direction)
		{
		case Main::Snake::eSnakeMove::MOVE_RIGHT:
			snake_xpos++;
			if (snake_xpos > field_size_x - 1) {
				snake_xpos = 0;
			}
			break;
		case Main::Snake::eSnakeMove::MOVE_LEFT:
			snake_xpos--;
			if (snake_xpos < 0) {
				snake_xpos = field_size_x - 1;
			}
			break;
		case Main::Snake::eSnakeMove::MOVE_UP:
			snake_ypos--;
			if (snake_ypos < 0) {
				snake_ypos = field_size_y - 1;
			}
			break;
		case Main::Snake::eSnakeMove::MOVE_DOWN:
			snake_ypos++;
			if (snake_ypos > field_size_y - 1) {
				snake_xpos = 0;
			}
			break;
		default:
			break;
		}

		_game.field[snake_xpos][snake_ypos] = snake_length + 1;

		for (int i = 0; i < field_size_y; i++) {
			for (int j = 0; j < field_size_x; j++) {
				if (_game.field[i][j] > int(Game::eFieldType::FIELD_CELL_NULL)) {
					_game.field[i][j]--;
				}
			}
		}
	}

	int Snake::get_length() const noexcept
	{
		return snake_length;
	}

	Game::Game(const Snake& _snake) : snake_obj(_snake)
	{	}

	Game::~Game() noexcept
	{	}

	Game::eGameErrors Game::init()
	{
		if (!game_objects[0].first.loadFromFile("none.png")) {
			return eGameErrors::TEXTURE_NOT_LOAD;
		}

		if (!game_objects[1].first.loadFromFile("snake.png")) {
			return eGameErrors::TEXTURE_NOT_LOAD;
		}

		game_objects[0].second.setTexture(game_objects[0].first);
		game_objects[1].second.setTexture(game_objects[1].first);

		return eGameErrors::SUCCES;
	}

	void Game::clear_field()
	{
		for (int i = 0; i < field_size_x; i++) {
			for (int j = 0; j < field_size_y; j++) {
				field[i][j] = int(eFieldType::FIELD_CELL_NULL);
			}
		}

		for (int i = 0; i < snake_obj.snake_length; i++) {
			field[snake_obj.snake_ypos][snake_obj.snake_xpos - i] = snake_obj.snake_length - i;
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