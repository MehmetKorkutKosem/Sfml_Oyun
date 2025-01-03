#pragma once

#include <SFML/Graphics.hpp>

class Timer {
public:
    // Constructor: Timer için süreyi belirler (saniye cinsinden)
    Timer(float duration);

    // Zamaný günceller
    void update();

    // Zamanlayýcý süresi dolmuþsa true döner
    bool isTimeUp() const;

    // Zamanlayýcýyý sýfýrlar
    void reset();

private:
    float m_duration;      // Zamanlayýcýnýn süresi (saniye cinsinden)
    float m_elapsedTime;   // Geçen süreyi takip eder
    sf::Clock m_clock;     // Zamaný ölçmek için SFML Clock
};



