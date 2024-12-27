#pragma once
#include <SFML/Graphics.hpp>
#include"functionDef.hpp"


class window {
public:
	void create(unsigned int weight, unsigned int height, const sf::String& title = "default");
    void draw(sf::Drawable& shape, sf::Color color);
	void eventControl();
	bool iswindowOpen();
	void clear();
	void display();
	void addpress(keyboardFunc);
	void addDepress(keyboardFunc);
	void mouseAddpress(mouseButtonFunc);
	void mouseAddDepress(mouseButtonFunc);
	void mouseMove(mouseFunc);
	sf::VideoMode& screen(unsigned int weight, unsigned int height);
private:

	keyboardFuncList press;
	keyboardFuncList depress;
	mouseFuncList move;
	mouseButtonList press1;
	mouseButtonList depress1;
	sf::RenderWindow window;

};