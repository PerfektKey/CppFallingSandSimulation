#include <SFML/Graphics.hpp>
#include <iostream>

int main () {

	sf::RenderWindow window(sf::VideoMode(1000, 900), "");

	std::cout << "Hello World\n";

	while (window.isOpen()) {
		
		sf::Event e;
		while (window.pollEvent(e)) {
			if (e.type == sf::Event::Closed)
				window.close();
		} 
		
		window.clear(sf::Color(255,255,255));
		window.display();
	}

	return 0;
}
