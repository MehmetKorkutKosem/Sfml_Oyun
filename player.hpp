#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include"window.hpp"
#include "ball.hpp"

enum class Yon {
	sag,
	sol,
	asagi,
	yukari,
};
class player {
protected:
	
	sf::RectangleShape kare;
	Yon yon ;
	sf::Vector2f place;
public:
	
	player(sf::Vector2f place);
	virtual void hareket();
	
	
	void setYon(Yon newyon);
	Yon getYon();
	virtual bool checkCollisionWithWall(const sf::RectangleShape& wall) = 0;
	virtual sf::RectangleShape& getShape() = 0;
	virtual void playdraw(window& window) = 0;
	virtual void resolveCollision(const sf::RectangleShape& wall) = 0;
	
	virtual void resetPosition(Ball& top);
        virtual bool checkCollisionWithCircle(const sf::CircleShape& wall) = 0;
        virtual void resolveCollision(const sf::CircleShape& wall) = 0;
	
};
