#pragma once

#include <SFML/Graphics.hpp>

class Timer {
public:
    // Constructor: Timer i�in s�reyi belirler (saniye cinsinden)
    Timer(float duration);

    // Zaman� g�nceller
    void update();

    // Zamanlay�c� s�resi dolmu�sa true d�ner
    bool isTimeUp() const;

    // Zamanlay�c�y� s�f�rlar
    void reset();

private:
    float m_duration;      // Zamanlay�c�n�n s�resi (saniye cinsinden)
    float m_elapsedTime;   // Ge�en s�reyi takip eder
    sf::Clock m_clock;     // Zaman� �l�mek i�in SFML Clock
};



