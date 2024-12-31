#include "window.hpp"
#include <SFML/Graphics.hpp>
#pragma once
class Kale {

	sf::RectangleShape kare;
	sf::Vector2f place;
	sf::Vector2f size = { 10, 300 };
public: 
	Kale() { place = { 65, 350 }; }
	Kale(sf::Vector2f place);
   void playdraw(window& window);
   sf::RectangleShape & getShape();
   bool checkCollisionWithWall(const sf::CircleShape& goal);
   void set(sf::Vector2f a, sf::Vector2f b);
};
