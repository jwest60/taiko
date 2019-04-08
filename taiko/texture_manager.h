#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <map>
#include <fstream>
#include <iostream>

class Texture_Manager
{
public:

	void create_texture(const std::string& name, const std::string& file_name);

	sf::Texture& get_texture(const std::string& name);

private:

	std::map<std::string, sf::Texture> textures;
};