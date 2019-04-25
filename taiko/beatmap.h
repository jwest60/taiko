#pragma once

#include "SFML/Graphics.hpp"

#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>

struct Beatmap
{
	Beatmap(const std::string& directory);

	std::string audio_filename;
	std::string title;
	std::string background;

	std::vector<unsigned int> hit_objects;
};