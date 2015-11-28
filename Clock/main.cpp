#include <SFML/Graphics.hpp>
#include "Clock.h"
#include "Constants.h"

using namespace sf;

int main()
{
	ContextSettings settings;
	settings.antialiasingLevel = 8;
	
	RenderWindow window(sf::VideoMode(SIZE_CLOCK_WINDOW, SIZE_CLOCK_WINDOW), "Clock!", Style::Default, settings);
	
	SYSTEMTIME currTime;
	
	MyClock clock;
	iniClock(clock);
	
	while (window.isOpen())
	{
		sf::Event event;
		GetLocalTime(&currTime);
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		
		updateClock(clock,currTime);
		window.clear();
		drawClock(window, clock);
		window.display();
	}
	dispClock(clock);
	return 0;
}