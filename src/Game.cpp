#include "Game.hpp"

namespace Main
{
	Snake::Snake() noexcept : snake_length(10), snake_xpos(field_size_x / 2),
		snake_ypos(field_size_y / 2), snake_direction(eSnakeMove::MOVE_RIGHT)
	{	}

	Snake::Snake(const Snake& _snake)
	{
		snake_direction = _snake.snake_direction;
		snake_length = _snake.snake_length;
		snake_xpos = _snake.snake_xpos;
		snake_ypos = _snake.snake_ypos;
	}

	Snake::Snake(int _length, int _xpos, int _ypos, eSnakeMove _snake_direction = eSnakeMove::MOVE_RIGHT) noexcept :
		snake_length(_length), snake_xpos(_xpos), snake_ypos(_ypos), snake_direction(_snake_direction)
	{	}

	Snake::~Snake() noexcept
	{	}

	Snake& Snake::operator=(const Snake& _snake) noexcept
	{
		if (this != &_snake) {
			snake_direction = _snake.snake_direction;
			snake_length = _snake.snake_length;
			snake_xpos = _snake.snake_xpos;
			snake_ypos = _snake.snake_ypos;
		}

		return *this;
	}

	void Snake::move(Game& _game)
	{
		switch (_game.snake_obj.snake_direction)
		{
		case eSnakeMove::MOVE_RIGHT:
			snake_xpos++;
			if (snake_xpos > field_size_x - 1) {
				snake_xpos = 0;
			}
			break;
		case eSnakeMove::MOVE_LEFT:
			snake_xpos--;
			if (snake_xpos < 0) {
				snake_xpos = field_size_x - 1;
			}
			break;
		case eSnakeMove::MOVE_UP:
			snake_ypos--;
			if (snake_ypos < 0) {
				snake_ypos = field_size_y - 1;
			}
			break;
		case eSnakeMove::MOVE_DOWN:
			snake_ypos++;
			if (snake_ypos < 0) {
				snake_ypos = field_size_y - 1;
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
		if (!cell_types[0].first.loadFromFile("none.png")) {
			return eGameErrors::TEXTURE_NOT_LOAD;
		}

		if (!cell_types[1].first.loadFromFile("snake.png")) {
			return eGameErrors::TEXTURE_NOT_LOAD;
		}

		cell_types[0].second.setTexture(cell_types[0].first);
		cell_types[1].second.setTexture(cell_types[1].first);

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
						cell_types[0].second.setPosition(sf::Vector2f(float(i * cell_size), float(j * cell_size)));
						_window.draw(cell_types[0].second);
						break;
					default:
						cell_types[1].second.setPosition(sf::Vector2f(float(i * cell_size), float(j * cell_size)));
						_window.draw(cell_types[1].second);
				}
			}
		}
	}

	void Game::handle_keyboard() noexcept
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
			snake_obj.snake_direction = Snake::eSnakeMove::MOVE_UP;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
			snake_obj.snake_direction = Snake::eSnakeMove::MOVE_DOWN;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
			snake_obj.snake_direction = Snake::eSnakeMove::MOVE_LEFT;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
			snake_obj.snake_direction = Snake::eSnakeMove::MOVE_RIGHT;
		}
	}
}