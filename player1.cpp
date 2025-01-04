#include "player1.hpp"


// Oyuncunun hareket mantığı
void player1::hareket()
{
    sf::Vector2f a = kare.getSize();// Oyuncunun şeklinin boyutlarını al

// Hareket yönüne göre pozisyon güncelle
    switch (yon) {
    case Yon::sag:
        std::cout << "Right" << std::endl;
      if(place.x+ a.x < 1000){// Sağ sınır kontrolü
          place.x += 2.f;// Sağa hareket
        
        }
        break;

    case Yon::sol:

        if (place.x > 0) {// Sol sınır kontrolü
            place.x -= 2.f; // Sola hareket
        }
        break;

    case Yon::yukari:

        if (place.y > 0) {// Üst sınır kontrolü
            place.y -= 2.f;// Yukarı hareket
        }
        break;

    case Yon::asagi:

        if (place.y + a.y < 1000) {// Alt sınır kontrolü
            place.y += 2.f; // Aşağı hareket
        }
        break;
    }
    kare.setPosition(place);// Şeklin yeni pozisyonunu ayarla

}




// Dikdörtgen duvar ile çarpışma çözümü
void player1::resolveCollision(const sf::RectangleShape& wall)
{
    sf::FloatRect playerBounds = kare.getGlobalBounds();// Oyuncunun şekil sınırları
    sf::FloatRect wallBounds = wall.getGlobalBounds();// Duvarın şekil sınırları

// Çarpışma varsa
    if (playerBounds.intersects(wallBounds)) {

        float overlapLeft = playerBounds.left + playerBounds.width - wallBounds.left;
        float overlapRight = wallBounds.left + wallBounds.width - playerBounds.left;
        float overlapTop = playerBounds.top + playerBounds.height - wallBounds.top;
        float overlapBottom = wallBounds.top + wallBounds.height - playerBounds.top;
// En küçük çakışmaya göre pozisyonu düzelt
        if (overlapLeft < overlapRight && overlapLeft < overlapTop && overlapLeft < overlapBottom) {
            place.x -= overlapLeft;  // sola  iter
        }
        else if (overlapRight < overlapLeft && overlapRight < overlapTop && overlapRight < overlapBottom) {
            place.x += overlapRight;  // saga  iter
        }
        else if (overlapTop < overlapLeft && overlapTop < overlapRight && overlapTop < overlapBottom) {
            place.y -= overlapTop;  // yukarı iter
        }
        else if (overlapBottom < overlapLeft && overlapBottom < overlapRight && overlapBottom < overlapTop) {
            place.y += overlapBottom;  // asağı iter
        }
    }
}
// Dikdörtgen bir duvar ile çarpışma kontrolü
bool player1::checkCollisionWithWall(const sf::RectangleShape& wall)
{
    sf::FloatRect playerBounds = kare.getGlobalBounds();  // oyuncunun sınırları
    sf::FloatRect wallBounds = wall.getGlobalBounds();    // duvarın sınırları

    return playerBounds.intersects(wallBounds);//çarpışma durumu
}
// Daire ile çarpışma kontrolü
bool player1::checkCollisionWitCircle(const sf::CircleShape& wall)
{
    sf::FloatRect playerBounds = kare.getGlobalBounds();  // oyuncunun sınırları
    sf::FloatRect wallBounds = wall.getGlobalBounds();    //dairenin sınırları

    return playerBounds.intersects(wallBounds);//çarpışma durumu
}
// Daire ile çarpışmayı çözme
void player1::resolveCollisioncircle(const sf::CircleShape& wall)
{
    sf::FloatRect playerBounds = kare.getGlobalBounds();// oyuncunun sınırları
    sf::FloatRect wallBounds = wall.getGlobalBounds();//dairenin sınırları

   // Çarpışma varsa
    if (playerBounds.intersects(wallBounds)) {
// Çakışma miktarını hesapla
        float overlapLeft = playerBounds.left + playerBounds.width - wallBounds.left;
        float overlapRight = wallBounds.left + wallBounds.width - playerBounds.left;
        float overlapTop = playerBounds.top + playerBounds.height - wallBounds.top;
        float overlapBottom = wallBounds.top + wallBounds.height - playerBounds.top;
// En küçük çakışmaya göre pozisyonu düzelt
        if (overlapLeft < overlapRight && overlapLeft < overlapTop && overlapLeft < overlapBottom) {
            place.x -= 1;  // sola  iter
        }
        else if (overlapRight < overlapLeft && overlapRight < overlapTop && overlapRight < overlapBottom) {
            place.x += 1;  // saða  iter
        }
        else if (overlapTop < overlapLeft && overlapTop < overlapRight && overlapTop < overlapBottom) {
            place.y -= 1; // yukarý iter
        }
        else if (overlapBottom < overlapLeft && overlapBottom < overlapRight && overlapBottom < overlapTop) {
            place.y += 1;  // aþaðý iter
        }
    }
}


// Oyuncuyu çizer
void player1::playdraw(window& window)
{
    kare.setPosition(place);// Şeklin pozisyonunu ayarla
    kare.setSize(sf::Vector2f(30, 50)); // Şeklin boyutunu ayarla
	window.draw(kare, sf::Color::Blue);// Şekli çiz ve rengini mavi yap
	
	
	
}
// Hareket yönünü ayarlar
void player1::setYon(Yon newyon)
{   
	yon = newyon;
}
// Oyuncunun şekil referansını döndürür
sf::RectangleShape& player1::getShape()
{
	return kare;
}
// Hareket yönünü döndürür
Yon player1::getYon()
{
	return yon;
}
// Top gol alanına girerse oyuncunun pozisyonunu sıfırlar
void player1::resetPosition(Ball& top) {
    if (top.trf) {
        place = { 922,475 };// Oyuncunun başlangıç pozisyonu
        kare.setPosition(place);// Şekli yeni pozisyona ayarla
       setYon(Yon::sag);// Hareket yönünü sağa ayarla
        
    }
}
