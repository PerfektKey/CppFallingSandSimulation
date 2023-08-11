#pragma once

#include "element.hpp"
#include <iostream>

class fluid : public element {
	public:

		fluid(map*,ElementTypes ,sf::Color ,sf::Vector2u, int);

		virtual void update (bool toogle);
};
