#include "Ball.hpp"
#include <iostream>
#include "kale.hpp"


Ball::Ball()
{
}

// Yap�c� fonksiyon
Ball::Ball(float maxSpeed) : maxSpeed(maxSpeed){
    

    velocity = { 0.f, 0.f };
}

// �arp��ma kontrol�
bool Ball::checkCollision(const sf::RectangleShape& wall) {
    sf::FloatRect ballBounds = ballShape.getGlobalBounds();
    sf::FloatRect wallBounds = wall.getGlobalBounds();
    return ballBounds.intersects(wallBounds); // �arp��ma varsa true d�ner
}

// Topu ekranda hareket ettirme
void Ball::move() {
    // Pozisyonu h�z vekt�r�ne g�re g�ncelle
    int a = ballShape.getRadius();
  
    position.x += velocity.x;
    position.y += velocity.y;

    // Ekran s�n�rlar�nda topu tutma
    if (position.x - a < 50) {
   
        position.x = 65;
	    
        setspeed(maxSpeed * 0.5);
        setDirection(BYon::sag);
        
        
        

    }
    if (position.x + a > 950) {
        
        position.x = 935;
        
        setspeed(maxSpeed * 0.5);
        setDirection(BYon::sol);
        
       
    }
    if (position.y - a < 50) {
        
        position.y = 65;
        setspeed(maxSpeed * 0.5);
        setDirection(BYon::asagi);
    }
    if (position.y + a > 950) {

        position.y = 935;
        setspeed(maxSpeed * 0.5);
        setDirection(BYon::yukari);
    }
}

// Y�n ayarlama
void Ball::setDirection(BYon yon) {
    switch (yon) {
    case BYon::sag:
        velocity = { maxSpeed, 0.5f };  // X ekseninde sa�a hareket
        break;
    case BYon::sol:
        velocity = { -maxSpeed, -0.5f }; // X ekseninde sola hareket
        break;
    case BYon::yukari:
        velocity = { 0.5f, -maxSpeed }; 
        break;
    case BYon::asagi:
        velocity = { -0.5f, maxSpeed }; 
        break;
    }
}

// �arp��ma kontrol�
void Ball::checkCollisionWithWall(const sf::RectangleShape& wall) {
    sf::FloatRect ballBounds = ballShape.getGlobalBounds();
    sf::FloatRect wallBounds = wall.getGlobalBounds();

    if (ballBounds.intersects(wallBounds)) {
        // �arp��ma miktar�n� hesapla
        float overlapLeft = ballBounds.left + ballBounds.width - wallBounds.left;
        float overlapRight = wallBounds.left + wallBounds.width - ballBounds.left;
        float overlapTop = ballBounds.top + ballBounds.height - wallBounds.top;
        float overlapBottom = wallBounds.top + wallBounds.height - ballBounds.top;

        if (overlapLeft < overlapRight && overlapLeft < overlapTop && overlapLeft < overlapBottom) {
            position.x -= 2.f;
            
            setDirection(BYon::sol);
            velocity.y = 0;
           
            // Sola �arpt���nda sa�a git
        }
        else if (overlapRight < overlapLeft && overlapRight < overlapTop && overlapRight < overlapBottom) {
            position.x += 2.f;
            setDirection(BYon::sag);
            velocity.y = 0;
            // Sa�a �arpt���nda sola git
        }
        else if (overlapTop < overlapLeft && overlapTop < overlapRight && overlapTop < overlapBottom) {
            position.y -= 2.f;
            setDirection(BYon::yukari);
            velocity.x = 0;// Yukar� �arpt���nda a�a�� git
        }
        else if (overlapBottom < overlapLeft && overlapBottom < overlapRight && overlapBottom < overlapTop) {
            position.y += 2.f;
            setDirection(BYon::asagi);
			velocity.x = 0; 
            // A�a�� �arpt���nda yukar� git
        }

        maxSpeed*= 0.90f;  // X ekseninde h�z azal�r
        
        
    }
}

// Getter fonksiyonu
sf::CircleShape Ball::getShape() const {
    return ballShape;
}

// Setter fonksiyonu
void Ball::setspeed(int newSpeed) {
    maxSpeed = newSpeed;
}

// Topu �izen fonksiyon
void Ball::bdraw(window& window) {
    ballShape.setRadius(8.0f);
    ballShape.setPosition(position);
    window.draw(ballShape,sf::Color::White);  // Topu render window'una �iz
}
void Ball::resetPosition(sf::Vector2f respawnPosition) {
    position = respawnPosition;
    // Reset other necessary parameters, such as speed or velocity
    velocity = { 0.f, 0.f };
    setspeed(0);
}
void Ball::checkGoalCollision(const sf::RectangleShape& goal) {
    sf::FloatRect ballBounds = ballShape.getGlobalBounds();
    sf::FloatRect goalBounds = goal.getGlobalBounds();

    if (ballBounds.intersects(goalBounds)) {
        // �arp��ma miktar�n� hesapla
        float overlapLeft = ballBounds.left + ballBounds.width - goalBounds.left;
        float overlapRight = goalBounds.left + goalBounds.width - ballBounds.left;
        float overlapTop = ballBounds.top + ballBounds.height - goalBounds.top;
        float overlapBottom = goalBounds.top + goalBounds.height - ballBounds.top;



        if (overlapTop < overlapLeft && overlapTop < overlapRight && overlapTop < overlapBottom) {
            position.y -= 0.2f;
            setDirection(BYon::yukari);
            velocity.x = 0;// Yukar� �arpt���nda a�a�� git
        }
        else if (overlapBottom < overlapLeft && overlapBottom < overlapRight && overlapBottom < overlapTop) {
            position.y += 0.2f;
            setDirection(BYon::asagi);
            velocity.x = 0;
            // A�a�� �arpt���nda yukar� git
        }
        else {
            resetPosition(sf::Vector2f(500.f, 500.f));
            trf = true;

            
        }

        maxSpeed *= 0.99f;  // X ekseninde h�z azal�r


    }
    
   
   
    
}

void Ball::rstTrf()
{ 
    trf = false;
}

