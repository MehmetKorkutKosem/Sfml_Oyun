

#include <SFML/Graphics.hpp>
#include <iostream>
#include "window.hpp"
class TextureManager {
private:
    sf::Texture texture;
    sf::Sprite sprite;

public:
    // Constructor
    TextureManager();

    // Texture y�kleme
    bool loadFromFile(const std::string& filepath);

    void scaleToWindow(const window& window, sf::Vector2f textureSize, sf::Vector2f windowSize);

    // Texture'u �l�eklendirme
    

    // Texture'u �izme
    void draw(window& window);
};



