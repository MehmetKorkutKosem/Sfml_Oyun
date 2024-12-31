#include "kale.hpp"

Kale::Kale(sf::Vector2f place)
{
	this->place = place;
}

void Kale::playdraw(window& window)
{   
	kare.setSize(size);
	kare.setPosition(place);
	window.draw(kare, sf::Color::Yellow);
}

sf::RectangleShape& Kale::getShape()
{
	return kare;
}
bool Kale::checkCollisionWithWall(const sf::CircleShape& goal)
{
	sf::FloatRect playerBounds = kare.getGlobalBounds();  // Player'ýn bounding box'ý
	sf::FloatRect goalBounds = goal.getGlobalBounds();    // Wall'ýn bounding box'ý

	return playerBounds.intersects(goalBounds);
}

void Kale::set(sf::Vector2f a, sf::Vector2f b)
{
	size = a;
	place = b;
	
}