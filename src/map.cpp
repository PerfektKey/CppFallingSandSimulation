#include "../header/map.hpp"


map::map(uint32_t msx,uint32_t msy , uint32_t tsx,uint32_t tsy) {
	MapSize  = {msx , msy};
	TileSize = {tsx , tsy};
	Tiles    = std::vector<element*>(msx*msy+msx+1 , nullptr);
}

sf::Vector2u map::getMapSize() {return MapSize;}
sf::Vector2u map::getTileSize() {return TileSize;}

void map::draw(sf::RenderWindow* rw) {
	for (element* e : Tiles) {
		if (e == nullptr)
			continue;
		e->draw(rw);
	}
}

void map::update (bool toggle) {
	for (element* e : Tiles) {
		if (e == nullptr)
			continue;
		e->update(toggle);
	}
}

sf::Vector2u map::WorldToMap(uint32_t x , uint32_t y) {
	return sf::Vector2u( floor(x/TileSize.x) ,  floor(y/TileSize.y));	
}
sf::Vector2u map::WorldToMap(sf::Vector2u vec) {
	return WorldToMap(vec.x , vec.y);
}


sf::Vector2f map::MapToWorld(uint32_t x , uint32_t y) {
	return sf::Vector2f( x*TileSize.x ,  y*TileSize.y);	
}
sf::Vector2f map::MapToWorld(sf::Vector2u vec) {
	return MapToWorld(vec.x , vec.y);
}

uint32_t map::MapToIndex(uint32_t x, uint32_t y) {
	assert(x < TileSize.x);
	assert(y < TileSize.y);
	return y*MapSize.x+x;
}

bool map::inBounds(uint32_t x , uint32_t y) {
	return x < MapSize.x && y < MapSize.y;
}
bool map::isFree(uint32_t x , uint32_t y) {
	return ( (x < MapSize.x && y < MapSize.y) && (Tiles.at(MapToIndex(x,y)) == nullptr) );
}

void map::set(uint32_t x , uint32_t y , element* e) {
	assert((x < TileSize.x && y < TileSize.y));
	Tiles.at(MapToIndex(x,y)) = e;
	if (e != nullptr)
		e->setMPosition(x,y);
}

element* map::get(uint32_t x , uint32_t y) {
	assert((x < TileSize.x && y < TileSize.y));
	return Tiles.at(MapToIndex(x,y));
}
ElementTypes map::getET(uint32_t x, uint32_t y) {
	assert((x < TileSize.x && y < TileSize.y));
	element* e = Tiles.at(MapToIndex(x,y));
	if (e == nullptr)
		return ElementTypes::NUL;
	return e->getType();
}


void map::move(uint32_t x , uint32_t y , element* e) {
	element* m = get(x,y);// get the element e wants to move to 
	sf::Vector2u ePos = e->getMPosition();// get e's map position
	if (m != nullptr)
		std::cout << "exchange\n";
	set(ePos.x, ePos.y, m);// set the element of the position where e is to m
        set(x,y, e);// set the element where e wants to move to to e
}
