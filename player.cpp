#include "player.hpp"
#include "window.hpp"






player::player(sf::Vector2f place)
{
	this->place = place;    
}






void player::setYon( Yon newyon)
{
	yon = newyon;

}

Yon player::getYon()
{
	return yon;
}



sf::RectangleShape& player::getShape()
{
    return kare;
}














void player::resetPosition(Ball& top)
{
    if (top.trf) {
        // Ball has entered the goal area, reset it to the starting position
        place = { 924,475 };
        kare.setPosition(place);
        moving = false;

    }
}








