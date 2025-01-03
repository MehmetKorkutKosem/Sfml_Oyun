#include "Timer.hpp"

Timer::Timer(float duration)
    : m_duration(duration), m_elapsedTime(0.0f) {
    m_clock.restart(); // Zamanlay�c�y� ba�lat
}

void Timer::update() {
    m_elapsedTime = m_clock.getElapsedTime().asSeconds(); // Ge�en s�reyi al
}

bool Timer::isTimeUp() const {
    return m_elapsedTime >= m_duration; // S�re dolduysa true d�nd�r
}

void Timer::reset() {
    m_clock.restart(); // Zamanlay�c�y� s�f�rla
    m_elapsedTime = 0.0f; // Ge�en s�reyi s�f�rla
}
