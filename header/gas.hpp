#pragma once

#include "element.hpp"
#include <iostream>

class gas : public element {
	public:

		gas(map*,ElementTypes ,sf::Color ,sf::Vector2u, int);

		virtual void update (bool toogle);
};
