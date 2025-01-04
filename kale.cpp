#include "kale.hpp"
// Yapıcı fonksiyon Kale'nin konumunu ayarlar
Kale::Kale(sf::Vector2f place)
{
	this->place = place;
}
// Kale'yi çizen fonksiyon
void Kale::playdraw(window& window)
{   
	kare.setSize(size);// Boyutu ayarla
	kare.setPosition(place);// Konumu ayarla
	window.draw(kare, sf::Color::Yellow);// Sarı renkte çiz
}
// Kale'nin şeklini döndüren fonksiyon
sf::RectangleShape& Kale::getShape()
{
	return kare;
}
// Kale ile bir hedef arasında çarpışma kontrolü
bool Kale::checkCollisionWithWall(const sf::CircleShape& goal)
{
	sf::FloatRect playerBounds = kare.getGlobalBounds(); // Kale'nin alanı
	sf::FloatRect goalBounds = goal.getGlobalBounds();   // Hedefin alanı
 

	return playerBounds.intersects(goalBounds); // Çarpışma kontrolü
}
// Kale'nin boyutunu ve konumunu ayarlayan fonksiyon
void Kale::set(sf::Vector2f a, sf::Vector2f b)
{
	size = a; // Boyutu ayarla
	place = b; // Konumu ayarla
	
}
