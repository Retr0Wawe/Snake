#include "Launcher.hpp"

#include "Game.hpp"
#include "Snake.hpp"

namespace Game
{
	int Launcher::start_game(const char* _title)
	{
		Game game_obj;

		pWindow = std::make_unique<sf::RenderWindow>(sf::VideoMode(window_width, window_height), _title);

		if (static_cast<int>(game_obj.init()) < 0) {
			return -1;
		}

		while (pWindow->isOpen())
		{
			sf::Event event;
			while (pWindow->pollEvent(event))
			{
				if (event.type == sf::Event::Closed) {
					pWindow->close();
				}
			}
			pWindow->clear();
			game_obj.draw(*pWindow);
			pWindow->display();
		}

		return 0;
	}
}