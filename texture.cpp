#include "texture.hpp"

// Constructor
TextureManager::TextureManager() {}

// Texture dosyasýný yükleme
bool TextureManager::loadFromFile(const std::string& filepath) {
    if (!texture.loadFromFile(filepath)) {
        std::cerr << "Texture yüklenemedi: " << filepath << std::endl;
        return false;
    }
    sprite.setTexture(texture);  // Sprite'a texture'u baðla
    return true;
}

// Texture'u pencere boyutuna göre ölçeklendirme
void TextureManager::scaleToWindow(const window& window, sf::Vector2f textureSize, sf::Vector2f windowSize) {
    // Texture'un geniþlik ve yüksekliðini pencereye göre ölçekle
    float scaleX = windowSize.x / textureSize.x;
    float scaleY = windowSize.y / textureSize.y;

    sprite.setScale(scaleX, scaleY);
}


// Texture'u pencereye çizme
void TextureManager::draw(window& window) {
    window.draw(sprite);
}

