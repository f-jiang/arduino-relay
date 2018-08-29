#ifndef RELAY_H
#define RELAY_H

class Relay {
public:
    /*
     * NORMALLY_OPEN: Energizing the coil by calling activate()
     * completes the circuit controlled by the relay.
     *
     * NORMALLY_CLOSED: Energizing the coil by calling activate()
     * opens the circuit controlled by the relay.
     */
    enum Mode {
        NORMALLY_OPEN,
        NORMALLY_CLOSED
    };

    /*
     * Instatiate a Relay. Requires pin and mode to be set.
     */
    Relay(int, Mode);

    /*
     * Initialize the Relay by initializing its pin and de-energizing the coil.
     */
    void begin();

    /*
     * Returns the digital pin used by the Arduino to control the relay.
     */
    int getPin() const;

    /*
     * Returns the mode of the Relay (see Mode description).
     */
    Mode getMode() const;

    /*
     * Returns true if the relay coil is energized.
     */
    bool isActivated() const;

    /*
     * Returns true if the circuit controlled by the relay is closed.
     */
    bool isClosed() const;

    /*
     * Energize the relay coil.
     */
    void activate();

    /*
     * De-energize the relay coil.
     */
    void deactivate();

    /*
     * Open the circuit controlled by the relay.
     */
    void open();

    /*
     * Close the circuit controlled by the relay.
     */
    void close();

private:
    int m_pin;
    Mode m_mode;
    bool m_isActivated;
};

#endif

