#include "Timer.hpp"

Timer::Timer(float duration)
    : m_duration(duration), m_elapsedTime(0.0f) {
    m_clock.restart(); // Zamanlayýcýyý baþlat
}

void Timer::update() {
    m_elapsedTime = m_clock.getElapsedTime().asSeconds(); // Geçen süreyi al
}

bool Timer::isTimeUp() const {
    return m_elapsedTime >= m_duration; // Süre dolduysa true döndür
}

void Timer::reset() {
    m_clock.restart(); // Zamanlayýcýyý sýfýrla
    m_elapsedTime = 0.0f; // Geçen süreyi sýfýrla
}
