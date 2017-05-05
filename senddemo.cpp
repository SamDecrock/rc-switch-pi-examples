#include <stdio.h>
#include "rc-switch/RCSwitch.h"

int main(int argc, char *argv[]) {
      
    printf("Starting senddemo\n");
    printf("Make sure you have connected the 433Mhz sender data pin to WiringPi pin 0 (real pin 11). See: https://pinout.xyz/pinout/pin11_gpio17\n");
    printf("\n");

    int PIN = 0;

    if (wiringPiSetup () == -1) {
        printf("ERROR: WiringPi not installed. Make sure you have WiringPi installed.\n");
        printf("Quick tutorial:\n\n");
        printf("    sudo apt-get install git\n");
        printf("    cd ~/\n");
        printf("    git clone git://git.drogon.net/wiringPi\n");
        printf("    cd wiringPi\n");
        printf("    ./build\n\n");
        return 1;
    }

    RCSwitch mySwitch = RCSwitch();

    // Transmitter is connected
    mySwitch.enableTransmit(PIN);

    // Optional set pulse length.
    // mySwitch.setPulseLength(320);
    
    // Optional set protocol (default is 1, will work for most outlets)
    mySwitch.setProtocol(1);
    
    // Optional set number of transmission repetitions.
    // mySwitch.setRepeatTransmit(15);

    printf("Sending something\n");
    mySwitch.send(4000, 24);

    printf("Done\n");

    return 0;
}
