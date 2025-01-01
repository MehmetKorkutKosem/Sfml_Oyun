#pragma once
#include "player.hpp"
#include "ball.hpp"

class player1 : public player {
	sf::Vector2f place = { 924,475 };
public:
	
	
	void playdraw(window& window);
	void setYon(Yon newyon);
	sf::RectangleShape& getShape();
	Yon getYon();
	void resetPosition(Ball& top);
	void hareket();
    void setMoving(bool state);
	bool isMoving();
	void resolveCollision(const sf::RectangleShape& wall);
	bool checkCollisionWithWall(const sf::RectangleShape& wall);

	bool checkCollisionWitCircle(const sf::CircleShape& wall);
   

	void resolveCollisioncircle(const sf::CircleShape& wall);
	
	

};