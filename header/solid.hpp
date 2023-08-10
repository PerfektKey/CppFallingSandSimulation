#pragma once

#include "element.hpp"
#include <iostream>

class solid : public element {
	public:

		solid(map*,ElementTypes ,sf::Color ,sf::Vector2u, int);

		virtual void update (bool toogle);
};
