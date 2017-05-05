#include <stdio.h>
#include "rc-switch/RCSwitch.h"


int main(int argc, char *argv[]) {

    printf("Starting receivedemo\n");
    printf("Make sure you have connected the 433Mhz receiver data pin to WiringPi pin 2 (real pin 13). See: https://pinout.xyz/pinout/pin13_gpio27\n");
    printf("\n");
    
    int PIN = 2; // this is pin 13, aka GPIO22 on the PI3, see https://www.element14.com/community/servlet/JiveServlet/previewBody/73950-102-10-339300/pi3_gpio.png

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

    // put the PIN into no-pull/up down state:
    // see https://github.com/ninjablocks/433Utils/issues/21
    pullUpDnControl(PIN, PUD_OFF);

    RCSwitch mySwitch = RCSwitch();

    mySwitch.enableReceive(PIN);

    printf("Listening\n");

    while(true) {

        if (mySwitch.available()) {
            
            int value = mySwitch.getReceivedValue();
            
            if (value == 0) {
                printf("Unknown encoding\n");
            } else {
                printf("Received %lu / %i bit Protocol: %i\n", mySwitch.getReceivedValue(), mySwitch.getReceivedBitlength(), mySwitch.getReceivedProtocol());
            }

            mySwitch.resetAvailable();
        }

        delay(100);
    }
}
