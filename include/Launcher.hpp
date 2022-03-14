#ifndef _LAUNCHER_HPP_
#define _LAUNCHER_HPP_

#include <SFML/Graphics.hpp>
#include <memory>

namespace Game 
{
	class Launcher
	{
	public:
		Launcher() noexcept{};

		virtual ~Launcher() noexcept{};
	public:
		virtual int start_game(const char* _title = "Snake");
	protected:
		std::unique_ptr<sf::RenderWindow> pWindow;
	};
}
#endif // _LAUNCHER_HPP_
