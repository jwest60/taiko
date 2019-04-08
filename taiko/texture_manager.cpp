#include "texture_manager.h"

void Texture_Manager::create_texture(const std::string& name, const std::string& file_name)
{
	sf::Texture texture;
	if (!texture.loadFromFile(file_name)) { std::cerr << "warning: could not find file " << file_name << std::endl; return; }

	this->textures[name] = texture;
}

sf::Texture& Texture_Manager::get_texture(const std::string& name)
{
	try
	{
		return this->textures.at(name);
	}
	catch (const std::out_of_range& e)
	{
		std::cerr << "FATAL EXCEPTION: failed to get texture because texture does not exist: " << name << std::endl;
		exit(EXIT_FAILURE);
	}
}