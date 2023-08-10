#pragma once

#include <SFML/Graphics.hpp>
#include "map.hpp"

class map;

enum class ElementTypes {
	NUL = 0,
	solid,
	gas,
	liquid
};

class element {
	public:
		element(map*,ElementTypes ,sf::Color ,sf::Vector2u, int);

		virtual void draw(sf::RenderWindow*);
	
		virtual void update (bool);

		sf::Vector2f getPosition ();
		sf::Vector2u getMPosition();
		void setMPosition(sf::Vector2u);
		void setMPosition(uint32_t,uint32_t);
	
		ElementTypes getType();

	protected:
		ElementTypes type;
		int weight;

		sf::Vector2u MapPosition;
		sf::RectangleShape rec;
		bool UpdateToggle;

		map* Map;
};
