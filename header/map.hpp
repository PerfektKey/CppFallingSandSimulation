#pragma once

#include <inttypes.h>
#include <vector>
#include <math.h>
#include <assert.h>

#include <SFML/Graphics.hpp>
#include <iostream>

#include "element.hpp"

enum class ElementTypes;
class element;// element needs map , map needs element, so this as a define

class map {
	public:
		map(uint32_t , uint32_t , uint32_t , uint32_t);

		sf::Vector2u getMapSize();
		sf::Vector2u getTileSize();

		sf::Vector2u WorldToMap(uint32_t , uint32_t);
		sf::Vector2u WorldToMap(sf::Vector2u);

		sf::Vector2f MapToWorld(uint32_t , uint32_t);
		sf::Vector2f MapToWorld(sf::Vector2u);

		uint32_t MapToIndex(uint32_t , uint32_t); 
		uint32_t MapToIndex(sf::Vector2u); 

		bool inBounds(uint32_t , uint32_t);
		bool isFree(uint32_t , uint32_t);
		void set(uint32_t,uint32_t , element*);
		element* get(uint32_t,uint32_t);
		ElementTypes getET(uint32_t , uint32_t);
		void move(uint32_t, uint32_t, element*);

		void draw(sf::RenderWindow*);
		void update(bool);

	private:
		sf::Vector2u MapSize;
		sf::Vector2u TileSize;
		std::vector<element*> Tiles;
};
