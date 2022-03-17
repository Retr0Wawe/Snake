#include "Launcher.hpp"

#include "Snake.hpp"
#include "Game.hpp"

namespace Main
{
	int Launcher::start_game(const char* _title)
	{
		Snake my_snake;

		Game game_obj(my_snake);

		pWindow = std::make_unique<sf::RenderWindow>(sf::VideoMode(window_width, window_height), _title);

		if (int(game_obj.init()) < 0) {
			return -1;
		}
		
		pWindow->setFramerateLimit(60);

		game_obj.clear_field();

		while (pWindow->isOpen())
		{
			sf::Event event;
			while (pWindow->pollEvent(event))
			{
				if (event.type == sf::Event::Closed) {
					pWindow->close();
				}
			}
			my_snake.move(game_obj);
			pWindow->clear(sf::Color(020, 100, 0));
			
			game_obj.draw(*pWindow);
			pWindow->display();

			sf::sleep(sf::milliseconds(render_delay));
		}

		return 0;
	}
}