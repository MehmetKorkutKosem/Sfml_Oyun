#include"window.hpp"
void window::create(unsigned int weight, unsigned int height, const sf::String& title) {
	window.create(sf::VideoMode(weight, height), title);
}
void window::draw(sf::Drawable& shape, sf::Color color) {
	
	if (auto* shapePtr = dynamic_cast<sf::Shape*>(&shape)) {
		shapePtr->setFillColor(color); 
	}
	window.draw(shape); 
}

void window::eventControl() {
	sf::Event olay;

	while (window.pollEvent(olay))
	{

		if (olay.type == sf::Event::Closed) {
			window.close();
		}
		if (olay.type == sf::Event::KeyPressed) {
			for (auto sonraki : press) {
				sonraki(olay.key.code);
			}
		}
		if (olay.type == sf::Event::KeyReleased) {
			for (auto sonraki : depress) {
				sonraki(olay.key.code);
			}
		}
		if (olay.type == sf::Event::MouseButtonPressed) {

			for (auto sonraki : press1) {
				sonraki(olay.mouseButton.button);
			}
		}
		if (olay.type == sf::Event::MouseButtonPressed) {

			for (auto sonraki : depress1) {
				sonraki(olay.mouseButton.button);
			}
		}

		if (olay.type == sf::Event::MouseMoved) {

			for (auto sonraki : move) {
				sonraki(olay.mouseMove);
			}
		}
	}

}

bool window::iswindowOpen()
{
	return window.isOpen();
}

void window::clear()
{
	window.clear();
}

void window::display()
{
	window.display();
}

void window::addpress(keyboardFunc key)
{
	press.push_back(key);
}

void window::addDepress(keyboardFunc key)
{
	depress.push_back(key);
}

void window::mouseAddpress(mouseButtonFunc button)
{
	press1.push_back(button);
}

void window::mouseAddDepress(mouseButtonFunc button)
{
	depress1.push_back(button);
}

void window::mouseMove(mouseFunc moves)
{
	move.push_back(moves);
}

sf::VideoMode& window::screen(unsigned int weight, unsigned int height)
{
	sf::VideoMode ekran = sf::VideoMode(weight, height);
	return ekran;
}


