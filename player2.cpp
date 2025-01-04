#include "player2.hpp"
#include "ball.hpp"

// Oyuncunun hareket mantığı
void player2::hareket()
{
    sf::Vector2f a = kare.getSize();// Oyuncunun şeklinin boyutlarını al
 // Hareket yönüne göre pozisyonu güncelle
    switch (yon) {
    case Yon::sag:
        if (place.x + a.x < 1000) {// Sağ sınır kontrolü
            place.x +=2;// Sağa hareket
        }
        break;

    case Yon::sol:

        if (place.x > 0) {// Sol sınır kontrolü
            place.x -= 2;// Sola hareket
        }
        break;

    case Yon::yukari:

        if (place.y > 0) {// Üst sınır kontrolü
            place.y -= 2; // Yukarı hareket
        }
        break;

    case Yon::asagi:

        if (place.y + a.y < 1000) {// Alt sınır kontrolü
            place.y += 2;// Aşağı hareket
        }
        break;
    }


}


// Dikdörtgen duvar ile çarpışmayı çözme
void player2::resolveCollision(const sf::RectangleShape& wall)
{
    sf::FloatRect playerBounds = kare.getGlobalBounds();// Oyuncunun şekil sınırları
    sf::FloatRect wallBounds = wall.getGlobalBounds();// Duvarın şekil sınırları

// Çarpışma varsa
    if (playerBounds.intersects(wallBounds)) {
// Çakışma miktarlarını hesapla
        float overlapLeft = playerBounds.left + playerBounds.width - wallBounds.left;
        float overlapRight = wallBounds.left + wallBounds.width - playerBounds.left;
        float overlapTop = playerBounds.top + playerBounds.height - wallBounds.top;
        float overlapBottom = wallBounds.top + wallBounds.height - playerBounds.top;
// En küçük çakışmaya göre pozisyonu düzelt
        if (overlapLeft < overlapRight && overlapLeft < overlapTop && overlapLeft < overlapBottom) {
            place.x -= overlapLeft;  // sola  iter
        }
        else if (overlapRight < overlapLeft && overlapRight < overlapTop && overlapRight < overlapBottom) {
            place.x += overlapRight;  // sağa  iter
        }
        else if (overlapTop < overlapLeft && overlapTop < overlapRight && overlapTop < overlapBottom) {
            place.y -= overlapTop;  // yukarı iter
        }
        else if (overlapBottom < overlapLeft && overlapBottom < overlapRight && overlapBottom < overlapTop) {
            place.y += overlapBottom;  // asagı iter
        }
    }
}
// Dikdörtgen bir duvar ile çarpışmayı kontrol et
bool player2::checkCollisionWithWall(const sf::RectangleShape& wall)
{
    sf::FloatRect playerBounds = kare.getGlobalBounds();  // Oyuncunun sınırları
    sf::FloatRect wallBounds = wall.getGlobalBounds();     // Duvarın sınırları

    return playerBounds.intersects(wallBounds);// Çarpışma durumu
}
// Daire ile çarpışmayı kontrol et
bool player2::checkCollisionWithCircle(const sf::CircleShape& wall)
{
    sf::FloatRect playerBounds = kare.getGlobalBounds();  // oyuncunun sınırları
    sf::FloatRect wallBounds = wall.getGlobalBounds();    // duvarın sınırları

    return playerBounds.intersects(wallBounds);// Çarpışma durumu
}
// Daire ile çarpışmayı çözme
void player2::resolveCollisioncircle(const sf::CircleShape& wall)
{
    sf::FloatRect playerBounds = kare.getGlobalBounds();// oyuncunun sınırları
    sf::FloatRect wallBounds = wall.getGlobalBounds();// duvarın sınırları

// Çarpışma varsa
    if (playerBounds.intersects(wallBounds)) {
 // Çakışma miktarlarını hesapla
        float overlapLeft = playerBounds.left + playerBounds.width - wallBounds.left;
        float overlapRight = wallBounds.left + wallBounds.width - playerBounds.left;
        float overlapTop = playerBounds.top + playerBounds.height - wallBounds.top;
        float overlapBottom = wallBounds.top + wallBounds.height - playerBounds.top;
// En küçük çakışmaya göre pozisyonu düzelt
        if (overlapLeft < overlapRight && overlapLeft < overlapTop && overlapLeft < overlapBottom) {
            place.x -= 1;  // sola  iter
        }
        else if (overlapRight < overlapLeft && overlapRight < overlapTop && overlapRight < overlapBottom) {
            place.x += 1;  // saga  iter
        }
        else if (overlapTop < overlapLeft && overlapTop < overlapRight && overlapTop < overlapBottom) {
            place.y -= 1; // yukari iter
        }
        else if (overlapBottom < overlapLeft && overlapBottom < overlapRight && overlapBottom < overlapTop) {
            place.y += 1;  // asagı iter
        }
    }
}
// Oyuncunun görünümünü çiz
void player2::playdraw(window& window)
{
    window.draw(kare, sf::Color::Red);// Şekli kırmızı renkte çiz
    kare.setPosition(place);// Şeklin pozisyonunu ayarla
    kare.setSize(sf::Vector2f(30, 50));// Şeklin boyutunu ayarla

}
// Hareket yönünü ayarla
void player2::setYon(Yon newyon)
{
    yon = newyon;
}
// Oyuncunun şekil referansını döndür
sf::RectangleShape& player2::getShape()
{
    return kare;
}
// Hareket yönünü döndür
Yon player2::getYon()
{
    return yon;
}
// Top gol alanına girerse oyuncunun pozisyonunu sıfırla
void player2::resetPosition(Ball& top) {
    if (top.trf) {
        place = { 90,475};// Oyuncunun başlangıç pozisyonu
        kare.setPosition(place);// Şekli yeni pozisyona ayarla
        setYon(Yon::sol);// Hareket yönünü sola ayarla

    }
}


