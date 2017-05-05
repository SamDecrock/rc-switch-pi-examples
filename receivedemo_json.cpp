#include <stdio.h>
#include <time.h>
#include "rc-switch/RCSwitch.h"


int main(int argc, char *argv[]) {

    printf("{\"timestamp\":%d,\"status\":\"starting\"}\n", (int)time(NULL));

    int PIN = 2; // this is pin 13, aka GPIO22 on the PI3, see https://www.element14.com/community/servlet/JiveServlet/previewBody/73950-102-10-339300/pi3_gpio.png

    if (wiringPiSetup () == -1) {
        printf("{\"timestamp\":%d,\"error\":\"WiringPi not installed.\"}\n", (int)time(NULL));
        return 1;
    }

    // put the PIN into no-pull/up down state:
    // see https://github.com/ninjablocks/433Utils/issues/21
    pullUpDnControl(PIN, PUD_OFF);

    RCSwitch mySwitch = RCSwitch();

    mySwitch.enableReceive(PIN);

    printf("{\"timestamp\":%d,\"status\":\"listening\"}\n", (int)time(NULL));

    while(true) {

        if (mySwitch.available()) {
            
            int value = mySwitch.getReceivedValue();
            
            if (value == 0) {
                printf("{\"timestamp\":%d,\"error\":\"unknown encoding\"}\n", (int)time(NULL));
            } else {
                printf("{\"timestamp\":%d,\"value\":%lu,\"bitlength\":%i,\"delay\":%i,\"protocol\":%i}\n", (int)time(NULL), mySwitch.getReceivedValue(), mySwitch.getReceivedBitlength(), mySwitch.getReceivedDelay(), mySwitch.getReceivedProtocol() );
            }

            mySwitch.resetAvailable();
        }

        delay(100);
    }
}
