#pragma once
#pragma once
#include "player.hpp"
#include "ball.hpp"

class player2 : public player {
	sf::Vector2f place;
public:
	
	void playdraw(window& window);
	void setYon(Yon newyon);
	sf::RectangleShape& getShape();
	Yon getYon();
	void resetPosition(Ball& top);
	void hareket();
	
	void resolveCollision(const sf::RectangleShape& wall);
	bool checkCollisionWithWall(const sf::RectangleShape& wall);
    bool checkCollisionWithCircle(const sf::CircleShape& wall);
    void resolveCollisioncircle(const sf::CircleShape& wall);

};
