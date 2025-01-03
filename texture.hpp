

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

    // Texture yükleme
    bool loadFromFile(const std::string& filepath);

    void scaleToWindow(const window& window, sf::Vector2f textureSize, sf::Vector2f windowSize);

    // Texture'u ölçeklendirme
    

    // Texture'u çizme
    void draw(window& window);
};



