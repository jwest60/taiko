#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

#include "texture_manager.h"

enum class Note_Type { INNER, OUTER };

/*
 * Note class used by note_generator.cpp
 * Creates a CircleShape and associated Note_Type, velocity, and texture
 * and provides draw and move functions
 */
struct Note : public sf::Drawable
{
	Note_Type type;

	Note(float velocity, unsigned int radius, sf::Vector2f& pos, Note_Type type, Texture_Manager& tex_mgr);

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	sf::CircleShape model;

	// the speed at which the notes move
	float velocity;

	// moves the note across the screen
	void move(sf::Time t);

	//tex_mgr stores all possible textures; tex is needed to store the right texture for the entire life of the note
	Texture_Manager tex_mgr;

	sf::Texture tex;
};