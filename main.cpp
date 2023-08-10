#include <SFML/Graphics.hpp>
#include <iostream>

#include "header/map.hpp"
#include "header/element.hpp"
#include "header/solid.hpp"


int main () {

	sf::RenderWindow window(sf::VideoMode(1000, 900), "");

	std::cout << "Hello World\n";

	map world(20,18 , 50,50);

	bool t = true;

	sf::Time elapsedTime;
	sf::Clock clock;
	sf::Time deltaTime = sf::milliseconds(100);


	while (window.isOpen()) {
		
		sf::Event e;
		while (window.pollEvent(e)) {
			if (e.type == sf::Event::Closed)
				window.close();
		}

		elapsedTime += clock.restart();

		if (elapsedTime < deltaTime)
			continue;

		elapsedTime -= deltaTime;

		element* el = new solid(&world, ElementTypes::solid, sf::Color(225,210,15), {10, 0}, 5);
		
		if (world.isFree(10,0))
			world.set(10,0, el);
		else
			delete el;
		world.update(t);
		t = !t;

		window.clear(sf::Color(124,124,124));
		world.draw(&window);
		window.display();
	}

	return 0;
}
