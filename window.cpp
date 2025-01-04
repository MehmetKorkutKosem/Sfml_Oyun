#include"window.hpp"
// Pencere oluşturma fonksiyonu
void window::create(unsigned int weight, unsigned int height, const sf::String& title) {
	 // SFML penceresini belirtilen genişlik, yükseklik ve başlık ile oluşturur
	window.create(sf::VideoMode(weight, height), title);
}
// Çizim fonksiyonu
void window::draw(sf::Drawable& shape, sf::Color color) {
	 // Eğer çizilen şekil bir "sf::Shape" türü ise rengini ayarla
	if (auto* shapePtr = dynamic_cast<sf::Shape*>(&shape)) {
		shapePtr->setFillColor(color); 
	}
	// Şekli pencereye çizer
	window.draw(shape); 
}
// Olay kontrol fonksiyonu
void window::eventControl() {
	sf::Event olay;

	while (window.pollEvent(olay))// Pencere kapatma olayı
	{

		if (olay.type == sf::Event::Closed) {
			window.close();
		}
		 // Klavye tuşuna basılma olay
		if (olay.type == sf::Event::KeyPressed) {
			for (auto sonraki : press) {// Tüm kayıtlı işlevleri çağır
				sonraki(olay.key.code);
			}
		}
		 // Klavye tuşu bırakılma olayı
		if (olay.type == sf::Event::KeyReleased) {
			for (auto sonraki : depress) {// Tüm kayıtlı işlevleri çağır
				sonraki(olay.key.code);
			}
		}
		 // Fare butonuna basılma olayı
		if (olay.type == sf::Event::MouseButtonPressed) {

			for (auto sonraki : press1) {// Tüm kayıtlı işlevleri çağır
				sonraki(olay.mouseButton.button);
			}
			
		}
		// Fare butonunun bırakılma olayı
		if (olay.type == sf::Event::MouseButtonPressed) {

			for (auto sonraki : depress1) {// Tüm kayıtlı işlevleri çağır
				sonraki(olay.mouseButton.button);
			}
		}
		
             // Fare hareketi olayı
		if (olay.type == sf::Event::MouseMoved) {

			for (auto sonraki : move) { // Tüm kayıtlı işlevleri çağır
				sonraki(olay.mouseMove);
			}
		}
	}

}
// Pencerenin açık olup olmadığını kontrol eder
bool window::iswindowOpen()
{
	return window.isOpen();
}
// Pencereyi temizler (önceki çerçeve görüntüsünü siler)
void window::clear()
{
	window.clear();
}
// Pencerenin içeriğini ekrana yansıtır
void window::display()
{
	window.display();
}
// Klavye tuşu basılma olayı için bir işlev ekler
void window::addpress(keyboardFunc key)
{
	press.push_back(key);
}
// Klavye tuşu bırakılma olayı için bir işlev ekler
void window::addDepress(keyboardFunc key)
{
	depress.push_back(key);
}
// Fare butonuna basılma olayı için bir işlev ekler
void window::mouseAddpress(mouseButtonFunc button)
{
	press1.push_back(button);
}
// Fare butonu bırakılma olayı için bir işlev ekler
void window::mouseAddDepress(mouseButtonFunc button)
{
	depress1.push_back(button);
}
// Fare hareketi için bir işlev ekler
void window::mouseMove(mouseFunc moves)
{
	move.push_back(moves);
}
// Ekran boyutlarını döndüren bir VideoMode referansı döner
sf::VideoMode& window::screen(unsigned int weight, unsigned int height)
{
	sf::VideoMode ekran = sf::VideoMode(weight, height);
	return ekran;
}


