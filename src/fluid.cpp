#include "../header/fluid.hpp"


fluid::fluid(map* m,ElementTypes t,sf::Color c,sf::Vector2u p, int w) : 
	element(m,t,c,p,w) {

}


void fluid::update(bool toggle) {
	if (UpdateToggle == toggle)
		return;
	UpdateToggle = toggle;

	if (Map == nullptr) {
		std::cout << " map is nullptr\n";
		exit(1);
	}

	sf::Vector2u TP = MapPosition;// Target Position
	TP.y = TP.y+1;

	if ( Map->inBounds(MapPosition.x,MapPosition.y+1) && 
	     Map->getET(MapPosition.x,MapPosition.y+1) != ElementTypes::solid)
		TP.y = TP.y;
	else if ( Map->inBounds(MapPosition.x+1,MapPosition.y+1) && 
		  Map->getET(MapPosition.x+1,MapPosition.y+1) != ElementTypes::solid)
		TP.x += 1;
	else if ( Map->inBounds(MapPosition.x-1,MapPosition.y+1) && 
		  Map->getET(MapPosition.x-1,MapPosition.y+1) != ElementTypes::solid)
		TP.x -= 1;
	else if ( Map->inBounds(MapPosition.x-1,MapPosition.y) && 
		  Map->getET(MapPosition.x-1,MapPosition.y) != ElementTypes::solid) {
		TP.x -= 1;
		TP.y -= 1;
	} else if ( Map->inBounds(MapPosition.x+1,MapPosition.y) && 
		  Map->getET(MapPosition.x+1,MapPosition.y) != ElementTypes::solid) {
		TP.x += 1;
		TP.y -= 1;
	} else {
		//std::cout << (Map->getET(MapPosition.x-1,MapPosition.y+1) != ElementTypes::solid) << " , " << (Map->inBounds(MapPosition.x-1,MapPosition.y+1)) << " " << MapPosition.x << "," << MapPosition.y << " " << this << "\n";
		return;
	}

	if (!Map->inBounds(TP.x,TP.y))
		return;

	if (Map->get(TP.x,TP.y) != nullptr)
		Map->get(TP.x,TP.y)->update(toggle);

	Map->move(TP.x,TP.y , this);
}
