#pragma once
#include <SFML/Window/Event.hpp>
#include <vector>
#include<functional>

typedef std::function<void(sf::Keyboard::Key)>  keyboardFunc;
typedef std::vector< keyboardFunc> keyboardFuncList;
typedef std::function<void(sf::Event::MouseMoveEvent)> mouseFunc;
typedef std::vector< mouseFunc> mouseFuncList;
typedef std::function<void(sf::Mouse::Button)> mouseButtonFunc;
typedef std::vector< mouseButtonFunc> mouseButtonList;