#include "game.hpp"
#include "player.hpp"
#include "player1.hpp"
#include "player2.hpp"
#include "ball.hpp"
#include "kale.hpp"
#include "timer.hpp"
#include"texture.hpp"
//Oyuncu nesnelerinin tanımlanması
player* oyuncu1 = new player1({ 924, 475 });
player* oyuncu2 = new player2({ 90, 475 });
// Kale nesnelerinin tanımlanması
Kale* kale1 = new Kale();
Kale* kale2 = new Kale(sf::Vector2f(935, 350));
// Zamanlayıcıların tanımlanması
Timer sayac(5.f);
Timer sayac1(5.f);
Timer enlargeCooldown(10.f);
Timer enlargeCooldown1(10.f);
Timer enlargeCooldown2(10.f);
Timer enlargeCooldown3(10.f);
// Arka plan ve yazı fontu tanımlamaları
TextureManager backgroundTexture;
sf::Font font;
sf::Text scoreText1;
sf::Text winnerText;   // Kazananı gösteren yazı  
// Player 1 score

;// New cooldown timer for goal enlargement
// Top nesnesi
Ball ball(0);

sf::RectangleShape dortgen;
// Uygulama sınıfı kurucusu
uygulama::uygulama() {
try{
    enlargeCooldown.reset();  // Bekleme süresi sıfırlanıyor
    enlargeCooldown1.reset();
     std::srand(static_cast<unsigned>(std::time(0))); // Rastgelelik için zaman ayarı
     if (!backgroundTexture.loadFromFile("D:/saha.png")) {
          throw std::runtime_error("Arka plan dokusu yüklenemedi!");
          // Hata işleme
     }
     if (!font.loadFromFile("C:/Windows/fonts/arial.ttf")) {
         throw std::runtime_error("Font yüklenemedi!");
     }

     // Oyuncu 1 skoru için yazı ayarları
	// Oyuncu 2 skoru için yazı ayarlar
     scoreText1.setFont(font);
     scoreText1.setCharacterSize(30);
     scoreText1.setFillColor(sf::Color::Magenta);
     scoreText1.setPosition(50, 20); // Position on the screen
}
	
     catch (const std::exception& e) {
     std::cerr << "Hata: " << e.what() << std::endl;
     exit(EXIT_FAILURE);
 }
   
}
// Uygulama sınıfı yıkıcısı
uygulama::~uygulama() {
    delete oyuncu1;
    delete oyuncu2;
    delete kale1;
    delete kale2;
}
// Klavye tuşlarına basılma işlemleri
void uygulama::pressKey(sf::Keyboard::Key tus) {
try{	
    if (tus == sf::Keyboard::Numpad1) {
        if (enlargeCooldown2.isTimeUp()) {
            int minX = 110, maxX = 900;
            int minY = 100, maxY = 900;

            // Rastgele X ve Y koordinatlarý
            float randomX = static_cast<float>(std::rand() % (maxX - minX + 1) + minX);  // X koordinatýný rastgele belirle
            float randomY = static_cast<float>(std::rand() % (maxY - minY + 1) + minY);  // Y koordinatýný rastgele belirle
            // Y koordinatýný rastgele belirle

            // Topun yeni pozisyonunu ayarla
            ball.resetPosition(sf::Vector2f(randomX, randomY));
            
            enlargeCooldown2.reset();

           
        }
    }
    if (tus == sf::Keyboard::T) {
        if (enlargeCooldown3.isTimeUp()) {
            int minX = 110, maxX = 900;
            int minY = 100, maxY = 900;

            // Rastgele X ve Y koordinatlarý
            float randomX = static_cast<float>(std::rand() % (maxX - minX + 1) + minX);  // X koordinatýný rastgele belirle
            float randomY = static_cast<float>(std::rand() % (maxY - minY + 1) + minY);  // Y koordinatýný rastgele belirle
            // Y koordinatýný rastgele belirle

            // Topun yeni pozisyonunu ayarla
            ball.resetPosition(sf::Vector2f(randomX, randomY));
            
            enlargeCooldown3.reset();


        }
    }

    if (tus == sf::Keyboard::Numpad0) {
        if (enlargeCooldown.isTimeUp()) {
            kale1->set({ 10, 600 }, { 65, 200 });
            sayac.reset();// Kale büyütme iþlemi
            enlargeCooldown.reset();
            // Bekleme süresi sýfýrlanýyor
        }// Check cooldown
          // Reset cooldown after enlargement
    }

    if (tus == sf::Keyboard::R) {  // Check cooldown
        if (enlargeCooldown1.isTimeUp()) {
            kale2->set({ 10, 600 }, { 935, 200 });
            sayac1.reset();// Kale büyütme iþlemi
            enlargeCooldown1.reset();
            // Bekleme süresi sýfýrlanýyor
        }  // Reset cooldown after enlargement
    }

    if (tus == sf::Keyboard::Space) {
        if ((oyuncu1->checkCollisionWithCircle(ball.getShape()) && oyuncu2->checkCollisionWithCircle(ball.getShape())) != true) {
            if (oyuncu1->checkCollisionWithCircle(ball.getShape())) {
                ball.setspeed(10);
            }
        }
    }
	// "F" tuşu ile oyuncu 2 topa vuruyor
    if (tus == sf::Keyboard::F) {
        if ((oyuncu1->checkCollisionWithCircle(ball.getShape()) && oyuncu2->checkCollisionWithCircle(ball.getShape())) != true) {
            if (oyuncu2->checkCollisionWithCircle(ball.getShape())) {
                ball.setspeed(10);
            }
        }
    }
	// Oyuncu 2 yönlendirme tuşları (WASD)
    if (tus == sf::Keyboard::D) {
        
        oyuncu2->setYon(Yon::sag);
        
    }
    if (tus == sf::Keyboard::A) {
        oyuncu2->setYon(Yon::sol);
        
       
    }
    if (tus == sf::Keyboard::W) {
        oyuncu2->setYon(Yon::yukari);
        
       
    }
    if (tus == sf::Keyboard::S) {
        oyuncu2->setYon(Yon::asagi);
        ;
       
    }
	 // Oyuncu 1 yönlendirme tuşları (Ok tuşları)
    if (tus == sf::Keyboard::Right) {
        oyuncu1->setYon(Yon::sag);
        
        
    }
    if (tus == sf::Keyboard::Left) {
        oyuncu1->setYon(Yon::sol);
       
       
    }
    if (tus == sf::Keyboard::Up) {
        oyuncu1->setYon(Yon::yukari);
        
      
    }
    if (tus == sf::Keyboard::Down) {
       
        oyuncu1->setYon(Yon::asagi);
      
    }
}
	 catch (...) {
     std::cerr << "Bir tuş işlemi sırasında hata oluştu!" << std::endl;
 }
}
// Klavye tuşları serbest bırakıldığında yapılacak işlemler
void uygulama::depressKey(sf::Keyboard::Key tus) {

}
// Mouse tıklama olayları
void uygulama::pressClick(sf::Mouse::Button button) {}

void uygulama::depressClick(sf::Mouse::Button button) {}
// Mouse hareket olayları
void uygulama::move(sf::Event::MouseMoveEvent move) {
    
}
// Oyun çerçevesi oluşturma
void uygulama::createFreame() {
    update();
    draw();
}
// Çizim işlemleri
void uygulama::draw() {
try{   
    window.clear();
    backgroundTexture.draw(window);
    oyuncu2->playdraw(window);
    oyuncu1->playdraw(window);
    kale1->playdraw(window);
    kale2->playdraw(window);
    ball.bdraw(window);
    window.draw(scoreText1);
   
    window.display();
}
	  catch (...) {
      std::cerr << "Çizim sırasında bir hata oluştu!" << std::endl;
  }
  
}
// Güncelleme işlemleri
void uygulama::update() {
try{
     backgroundTexture.scaleToWindow(window,{500,500}, { 1000,1000 });
     scoreText1.setString("Red " + std::to_string(score2)+"-" + std::to_string(score1)+" Blue");
    

     oyuncu1->hareket();
     oyuncu2->hareket();
     ball.move();
}
	catch (...) {
    std::cerr << "Güncelleme sırasında bir hata oluştu!" << std::endl;
}
}
// Pencere oluşturma
void uygulama::create(int weight, int height) {
try{
    window.create(weight, height);
    window.mouseMove(std::bind(&uygulama::move, this, std::placeholders::_1));
    window.mouseAddDepress(std::bind(&uygulama::pressClick, this, std::placeholders::_1));
    window.mouseAddDepress(std::bind(&uygulama::depressClick, this, std::placeholders::_1));
    window.addpress(std::bind(&uygulama::pressKey, this, std::placeholders::_1));
    window.addDepress(std::bind(&uygulama::depressKey, this, std::placeholders::_1));
}
	  catch (...) {
      std::cerr << "Pencere oluşturulurken bir hata oluştu!" << std::endl;
  }
}

void uygulama::ready(int fps) {
try{
    if (fps <= 0) {
        std::cerr << "FPS cannot be zero or negative. Setting default to 60." << std::endl;
        fps = 60;
    }

    float tfps = 1.0f / fps;
    freameTime = sf::seconds(tfps);
    while (window.iswindowOpen()) {
        window.eventControl();

        sf::Time elapsedTime = clock.getElapsedTime();
        if (elapsedTime >= freameTime) {
            createFreame();
            sayac.update();
            sayac1.update();
		// Eğer oyuncu 1'in skoru 4'e ulaştıysa oyunu bitir
            if (score1 == 4) {
                winnerText.setFont(font);
                winnerText.setCharacterSize(20);
                winnerText.setFillColor(sf::Color::Blue);
                winnerText.setString("Oyuncu 1 win!");
                winnerText.setPosition(450, 20);  // Kazanan mesajýný ekrana yerleþtir
                window.draw(winnerText);  // Kazananý ekrana yazdýr
                window.display();  // Ekraný güncelle
                sf::sleep(sf::seconds(2));  // 2 saniye boyunca kazananý göster
                window.closeWindow();  // Oyunu bitir
            }
		 // Eğer oyuncu 2'nin skoru 4'e ulaştıysa oyunu bitir
            if (score2 == 4) {
                winnerText.setFont(font);
                winnerText.setCharacterSize(20);
                winnerText.setFillColor(sf::Color::Red);
                winnerText.setString("Oyuncu 2 win!");
                winnerText.setPosition(450, 20);  // Kazanan mesajýný ekrana yerleþtir
                window.draw(winnerText);  // Kazananý ekrana yazdýr
                window.display();  // Ekraný güncelle
                sf::sleep(sf::seconds(2));  // 2 saniye boyunca kazananý göster
                window.closeWindow();  // Oyunu bitir
            }
            enlargeCooldown.update();// Kale genişletme sürelerini güncelle
            enlargeCooldown1.update();
            enlargeCooldown2.update();
            enlargeCooldown3.update();

            // 3 saniye geçtikten sonra kale eski boyutuna dönsün
            if (sayac.isTimeUp()) {
                kale1->set({ 10, 300 }, { 65, 350 }); // Eski boyut
            }
            if (sayac1.isTimeUp()) {
                kale2->set({ 10, 300 }, { 935, 350 }); // Eski boyut
            }
		// Oyuncu 1 top ile çarpıştıysa çarpışmayı çöz

            if (oyuncu1->checkCollisionWithCircle(ball.getShape())) {
                oyuncu1->resolveCollisioncircle(ball.getShape());
            }
		// Oyuncu 2 top ile çarpıştıysa çarpışmayı çöz
            if (oyuncu2->checkCollisionWithCircle(ball.getShape())) {
                oyuncu2->resolveCollisioncircle(ball.getShape());
            }
		// Oyuncular birbirleriyle çarpıştıysa çarpışmayı çöz
            if (oyuncu2->checkCollisionWithWall(oyuncu1->getShape())) {
                oyuncu2->resolveCollision(oyuncu1->getShape());
            }
            if (oyuncu1->checkCollisionWithWall(oyuncu2->getShape())) {
                oyuncu1->resolveCollision(oyuncu2->getShape());
            }
		 // Oyuncular kale ile çarpıştıysa çarpışmayı çöz

            if (oyuncu1->checkCollisionWithWall(kale1->getShape())) {
                oyuncu1->resolveCollision(kale1->getShape());
            }
            if (oyuncu2->checkCollisionWithWall(kale1->getShape())) {
                oyuncu2->resolveCollision(kale1->getShape());
            }
            if (oyuncu2->checkCollisionWithWall(kale2->getShape())) {
                oyuncu2->resolveCollision(kale2->getShape());
            }
            else {
                oyuncu1->resolveCollision(kale2->getShape());
            }
		 // Eğer top kale 1 ile çarpıştıysa skor artır

            if (kale1->checkCollisionWithWall(ball.getShape())) {
				if ((kale1->checkCollisionWithWall(ball.getShape()) && (oyuncu1->checkCollisionWithCircle(ball.getShape()) || oyuncu2->checkCollisionWithCircle(ball.getShape())))!=true) {
					score1 += 1;
					
				}
                
            }
		// Eğer top kale 2 ile çarpıştıysa skor artır
            if (kale2->checkCollisionWithWall(ball.getShape())) {
                if ((kale2->checkCollisionWithWall(ball.getShape()) && (oyuncu1->checkCollisionWithCircle(ball.getShape()) || oyuncu2->checkCollisionWithCircle(ball.getShape()))) != true) {
                    score1 += 1;
                    
                }

            }

            ball.checkGoalCollision(kale1->getShape());// Top kale 1 ile çarpıştı mı kontrol et
            ball.checkGoalCollision(kale2->getShape());// Top kale 2 ile çarpıştı mı kontrol et
            oyuncu1->resetPosition(ball);// Oyuncu 1'i yeniden konumlandır
            oyuncu2->resetPosition(ball);// Oyuncu 2'yi yeniden konumlandır
            ball.rstTrf();// Topun durumunu sıfırla
            ball.checkCollisionWithWall(oyuncu2->getShape());// Top, oyuncu 2 ile çarpıştı mı kontrol et
            ball.checkCollisionWithWall(oyuncu1->getShape());// Top, oyuncu 1 ile çarpıştı mı kontrol et

            clock.restart();// Zamanlayıcıyı yeniden başlat
        }
        else {
            sf::sleep(freameTime - elapsedTime);// Gerekli süre kadar bekle
        }
    }
	 catch (...) {
     std::cerr << "Oyun döngüsü sırasında bir hata oluştu!" << std::endl;
 }
}
