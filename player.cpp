#include "player.hpp"
#include "window.hpp"





// Oyuncu sınıfının constructor'ı, başlangıç konumunu belirler
player::player(sf::Vector2f place)
{
	this->place = place;    
}





// Oyuncunun hareket yönünü ayarlar
void player::setYon( Yon newyon)
{
	yon = newyon;

}

Yon player::getYon()
{
	return yon;
}


// Oyuncunun şekil referansını döndürür
sf::RectangleShape& player::getShape()
{
    return kare;
}













// Top gol bölgesine girdiğinde oyuncunun pozisyonunu sıfırlar
void player::resetPosition(Ball& top)
{
    if (top.trf) {
       // Top gol alanına girdi, başlangıç pozisyonuna sıfırla
        place = { 924,475 };
        kare.setPosition(place);
        moving = false;

    }
}








