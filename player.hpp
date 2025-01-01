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
	bool moving = false;
	sf::RectangleShape kare;
	Yon yon = Yon::sag;
	sf::Vector2f place;
public:
	
	
	virtual void hareket();
	void setMoving(bool state);
	virtual bool isMoving();
	
	void setYon(Yon newyon);
	Yon getYon();
	virtual bool checkCollisionWithWall(const sf::RectangleShape& wall) = 0;
	virtual sf::RectangleShape& getShape() = 0;
	virtual void playdraw(window& window) = 0;
	virtual void resolveCollision(const sf::RectangleShape& wall) = 0;
	
	void resetPosition(Ball& top);
	
};