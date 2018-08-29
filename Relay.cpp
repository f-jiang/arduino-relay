#include "Relay.h"
#include "Arduino.h"

Relay::Relay(int p, Relay::Mode m) : m_pin(p), m_mode(m), m_isActivated(false) { }

void Relay::begin()
{
    pinMode(m_pin, OUTPUT);
    deactivate();
}

int Relay::getPin() const
{
    return m_pin;
}

Relay::Mode Relay::getMode() const
{
    return m_mode;
}

bool Relay::isActivated() const
{
    return m_isActivated;
}

bool Relay::isClosed() const
{
    return (m_mode == NORMALLY_OPEN && isActivated()) ||
           (m_mode == NORMALLY_CLOSED && !isActivated());
}

void Relay::activate()
{
    digitalWrite(m_pin, LOW);
    m_isActivated = true;
}

void Relay::deactivate()
{
    digitalWrite(m_pin, HIGH);
    m_isActivated = false;
}

void Relay::open()
{
    (m_mode == NORMALLY_OPEN) ? deactivate() : activate();
}

void Relay::close()
{
    (m_mode == NORMALLY_OPEN) ? activate() : deactivate();
}

