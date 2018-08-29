#ifndef RELAY_H
#define RELAY_H

class Relay {
    public:
        enum Mode {
            NORMALLY_OPEN,
            NORMALLY_CLOSED
        };

        Relay(int, Mode);

        int getPin() const;
        Mode getMode() const;
        bool isActivated() const;
        bool isClosed() const;

        void activate();
        void deactivate();
        void open();
        void close();

    private:
        int m_pin;
        Mode m_mode;
        bool m_isActivated;

};

#endif

