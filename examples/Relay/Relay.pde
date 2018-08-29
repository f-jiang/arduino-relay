/*
 * Relay example program:
 *
 * This is a simple program that switches the relay on and off repeatedly.
 */

#include <Relay.h>

#define RELAY_PIN           4   // This is the digital pin used for the relay signal
#define SWITCHING_DELAY_MS  500 // Switch the relay every 500 ms

Relay relay(RELAY_PIN, Relay::Mode::NORMALLY_OPEN); // Instantiate our relay

void printStatus() {
    Serial.print("isClosed(): ");
    Serial.print(relay.isClosed());
    Serial.print("\n");
}

void setup()
{
    pinMode(RELAY_PIN, OUTPUT); // Set up the pin used to control the relay
    Serial.begin(9600);
    relay.begin();              // Initialize the relay

    Serial.print("Relay mode is ");
    Serial.print(relay.getMode());
    Serial.print(" (0: NORMALLY_OPEN, 1: NORMALLY_CLOSED)\n");
}

void loop()
{
    // Close the relay and complete the circuit
    delay(SWITCHING_DELAY_MS);
    relay.close();
    printStatus();

    // Open the relay
    delay(SWITCHING_DELAY_MS);
    relay.open();
    printStatus();
}

