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

		if (static_cast<int>(game_obj.init()) < 0) {
			return -1;
		}

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
			pWindow->clear(sf::Color(200, 250, 0));
			game_obj.draw(*pWindow);
			pWindow->display();
		}

		return 0;
	}
}