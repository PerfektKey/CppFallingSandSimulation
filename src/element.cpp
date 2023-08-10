#include "../header/element.hpp"


element::element(map* Map, ElementTypes t ,sf::Color c, sf::Vector2u p , int w) {
	this->type = t;
	this->rec.setFillColor(c);
	this->MapPosition = p;
	sf::Vector2f pf = Map->MapToWorld(p.x,p.y);
	this->rec.setPosition(pf.x , pf.y);
	sf::Vector2u su = Map->getTileSize();
	sf::Vector2f sf = {(float)su.x,(float)su.y};
	this->rec.setSize(sf);
	this->weight = w;
	this->UpdateToggle = false;
	this->Map = Map;
}

void element::draw(sf::RenderWindow* w) {
	w->draw(rec);
}

void element::update(bool toggle) {
	if (UpdateToggle == toggle)
		return;
	UpdateToggle = toggle;
}

sf::Vector2f element::getPosition() {
	return rec.getPosition();
}
sf::Vector2u element::getMPosition() {
	return MapPosition;
}
void element::setMPosition(sf::Vector2u mpos) {
	MapPosition = mpos;
	rec.setPosition(Map->MapToWorld(mpos));
}
void element::setMPosition(uint32_t x , uint32_t y) {
	setMPosition({x,y});
}

ElementTypes element::getType() {
	return this->type;
}
