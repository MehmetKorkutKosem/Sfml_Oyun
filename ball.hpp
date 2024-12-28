#pragma once
#include <SFML/Graphics.hpp>
#include "window.hpp"
enum class BYon {
	sag,
	sol,
	asagi,
	yukari,
};



class Ball {
private:
    sf::CircleShape ballShape;  
    sf::Vector2f velocity = { 0.f, 0.f };   
    float maxSpeed = 0;

    sf::Vector2f position = { 500, 500 }; 

public:
    bool trf=false;
    
    Ball();
    Ball(float maxSpeed);

    bool checkCollision(const sf::RectangleShape& wall);

    
    void move();

    void setDirection(BYon yon);

    
    void checkCollisionWithWall(const sf::RectangleShape& wall);

    

    
    sf::CircleShape getShape() const;

    
    void setspeed( int newSpeed);

   
    void bdraw(window& window);

    void resetPosition(sf::Vector2f respawnPosition);

    void checkGoalCollision(const sf::RectangleShape& goal);


    
    

    
    void rstTrf();

};



