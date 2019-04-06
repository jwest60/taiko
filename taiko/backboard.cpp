#pragma once

#include "backboard.h"

Backboard::Backboard(unsigned int width, unsigned int height, const sf::Vector2f& pos)
	: width(width), height(height)
{
	this->model.setSize(sf::Vector2f(this->width, this->height));
	this->model.setOrigin(sf::Vector2f(0, this->height / 2));
	this->model.setFillColor(sf::Color::Blue);
	this->model.setPosition(pos);
}

void Backboard::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(this->model);
}