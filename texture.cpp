#include "texture.hpp"

// Constructor
TextureManager::TextureManager() {}

// Texture dosyas�n� y�kleme
bool TextureManager::loadFromFile(const std::string& filepath) {
    if (!texture.loadFromFile(filepath)) {
        std::cerr << "Texture y�klenemedi: " << filepath << std::endl;
        return false;
    }
    sprite.setTexture(texture);  // Sprite'a texture'u ba�la
    return true;
}

// Texture'u pencere boyutuna g�re �l�eklendirme
void TextureManager::scaleToWindow(const window& window, sf::Vector2f textureSize, sf::Vector2f windowSize) {
    // Texture'un geni�lik ve y�ksekli�ini pencereye g�re �l�ekle
    float scaleX = windowSize.x / textureSize.x;
    float scaleY = windowSize.y / textureSize.y;

    sprite.setScale(scaleX, scaleY);
}


// Texture'u pencereye �izme
void TextureManager::draw(window& window) {
    window.draw(sprite);
}

