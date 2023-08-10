#pragma once

#include "element.hpp"

#include "../Depend/Pparser.h"

#include <filesystem>
namespace fs = std::filesystem;

class ElementLoader {
	public:
		element* NewElement(fs::path);
};
