#include "player1.hpp"



void player1::hareket()
{
    sf::Vector2f a = kare.getSize();

    if (!moving) return;

    std::cout << a.x << "----" << a.y << std::endl;

    switch (yon) {
    case Yon::sag:
        std::cout << "Right" << std::endl;
      if(place.x+ a.x < 1000){
          place.x += 3.f;
        
        }
        break;

    case Yon::sol:

        if (place.x > 0) {
            place.x -= 3.f;
        }
        break;

    case Yon::yukari:

        if (place.y > 0) {
            place.y -= 5.f;
        }
        break;

    case Yon::asagi:

        if (place.y + a.y < 1000) {
            place.y += 5.f;
        }
        break;
    }
    kare.setPosition(place);

}

void player1::setMoving(bool state)
{
    std::cout << "calisiyor" << std::endl;
    moving = state;
}

bool player1::isMoving()
{
    return moving;
}

void player1::resolveCollision(const sf::RectangleShape& wall)
{
    sf::FloatRect playerBounds = kare.getGlobalBounds();
    sf::FloatRect wallBounds = wall.getGlobalBounds();


    if (playerBounds.intersects(wallBounds)) {

        float overlapLeft = playerBounds.left + playerBounds.width - wallBounds.left;
        float overlapRight = wallBounds.left + wallBounds.width - playerBounds.left;
        float overlapTop = playerBounds.top + playerBounds.height - wallBounds.top;
        float overlapBottom = wallBounds.top + wallBounds.height - playerBounds.top;

        if (overlapLeft < overlapRight && overlapLeft < overlapTop && overlapLeft < overlapBottom) {
            place.x -= overlapLeft;  // sola  iter
        }
        else if (overlapRight < overlapLeft && overlapRight < overlapTop && overlapRight < overlapBottom) {
            place.x += overlapRight;  // sa�a  iter
        }
        else if (overlapTop < overlapLeft && overlapTop < overlapRight && overlapTop < overlapBottom) {
            place.y -= overlapTop;  // yukar� iter
        }
        else if (overlapBottom < overlapLeft && overlapBottom < overlapRight && overlapBottom < overlapTop) {
            place.y += overlapBottom;  // a�a�� iter
        }
    }
}

bool player1::checkCollisionWithWall(const sf::RectangleShape& wall)
{
    sf::FloatRect playerBounds = kare.getGlobalBounds();  // Player'�n bounding box'�
    sf::FloatRect wallBounds = wall.getGlobalBounds();    // Wall'�n bounding box'�

    return playerBounds.intersects(wallBounds);
}
bool player1::checkCollisionWitCircle(const sf::CircleShape& wall)
{
    sf::FloatRect playerBounds = kare.getGlobalBounds();  // Player'�n bounding box'�
    sf::FloatRect wallBounds = wall.getGlobalBounds();    // Wall'�n bounding box'�

    return playerBounds.intersects(wallBounds);
}

void player1::resolveCollisioncircle(const sf::CircleShape& wall)
{
    sf::FloatRect playerBounds = kare.getGlobalBounds();
    sf::FloatRect wallBounds = wall.getGlobalBounds();


    if (playerBounds.intersects(wallBounds)) {

        float overlapLeft = playerBounds.left + playerBounds.width - wallBounds.left;
        float overlapRight = wallBounds.left + wallBounds.width - playerBounds.left;
        float overlapTop = playerBounds.top + playerBounds.height - wallBounds.top;
        float overlapBottom = wallBounds.top + wallBounds.height - playerBounds.top;

        if (overlapLeft < overlapRight && overlapLeft < overlapTop && overlapLeft < overlapBottom) {
            place.x -= 1;  // sola  iter
        }
        else if (overlapRight < overlapLeft && overlapRight < overlapTop && overlapRight < overlapBottom) {
            place.x += 1;  // sa�a  iter
        }
        else if (overlapTop < overlapLeft && overlapTop < overlapRight && overlapTop < overlapBottom) {
            place.y -= 1; // yukar� iter
        }
        else if (overlapBottom < overlapLeft && overlapBottom < overlapRight && overlapBottom < overlapTop) {
            place.y += 1;  // a�a�� iter
        }
    }
}



void player1::playdraw(window& window)
{
    kare.setPosition(place);
    kare.setSize(sf::Vector2f(30, 50));
	window.draw(kare, sf::Color::Blue);
	
	
	
}

void player1::setYon(Yon newyon)
{   
	yon = newyon;
}

sf::RectangleShape& player1::getShape()
{
	return kare;
}

Yon player1::getYon()
{
	return yon;
}

void player1::resetPosition(Ball& top) {
    if (top.trf) {
        // Ball has entered the goal area, reset it to the starting position
        place = { 924,475 };
        kare.setPosition(place);
        moving = false;
        
    }
}