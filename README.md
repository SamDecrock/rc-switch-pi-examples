# rc-switch-pi-examples
This repo contains examples showing you how to use [rc-switch](https://github.com/sui77/rc-switch) on a Raspberry Pi

rc-switch is a library to operate 433/315Mhz devices like power outlet sockets. It was first built for Arduino, but now works on Raspberry too. 

This github repo shows some simple examples that are very much like the Arduino examples.

**If you just want to run the examples without compiling, take a look inside the /bin folder.**

## Install Git

To clone the git repositories used in this project, install git:

	sudo apt-get install git

## Install WiringPI

To use rc-switch on the Pi, you need WiringPi

	cd ~/
	git clone git://git.drogon.net/wiringPi
	cd wiringPi
	./build

## Get these examples

If you haven't downloaded these examples yet, you can clone them using
	
	cd ~/
	git clone https://github.com/SamDecrock/rc-switch-pi-examples.git
	cd rc-switch-pi-examples

## Get rc-switch

To run compile these examples, you need the rc-switch library.

From this folder, run

	git clone https://github.com/sui77/rc-switch.git


## Compile the examples

From this folder, run

	make

This should leave you with the following executables:

	senddemo
	receivedemo
	receivedemo_json


## Running the examples

Make sure your receiver and sender are correctly connected:
- sender connected to WiringPi Pin 0 (real pin 11).
- receiver connected to WiringPi pin 2 (real pin 13).

See: https://pinout.xyz

### senddemo


To run the send demo:

	./senddemo

This examples sends a single message.

Sample output:

	Starting senddemo
	Make sure you have connected the 433Mhz sender data pin to WiringPi pin 0 (real pin 11). See: https://pinout.xyz/pinout/pin11_gpio17

	Sending something
	Done

### receivedemo

To run the receive demo:

	./receivedemo

This examples just listens for all incomming signals. If rc-switch can decode them, they will be shown here.
The output is similar to the ReceiveDemo_Simple.ino from Arduino


Sample output:

	Starting receivedemo
	Make sure you have connected the 433Mhz receiver data pin to WiringPi pin 2 (real pin 13). See: https://pinout.xyz/pinout/pin13_gpio27

	Listening
	Received 10 / 24 bit Protocol: 2
	Received 10 / 24 bit Protocol: 2
	Received 10 / 24 bit Protocol: 2
	Received 10 / 24 bit Protocol: 2
	Received 10 / 24 bit Protocol: 2
	Received 10 / 24 bit Protocol: 2



### receivedemo_json


To run the receive demo (json):

	./receivedemo_json

This example wraps every output in a JSON formatted message so you can easily use it in other projects.

Sample output:

	{"status":"starting"}
	{"status":"listening"}
	{"value":74,"bitlength":24,"delay":706,"protocol":2}
	{"value":74,"bitlength":24,"delay":706,"protocol":2}
	{"value":74,"bitlength":24,"delay":706,"protocol":2}
	{"value":74,"bitlength":24,"delay":706,"protocol":2}
	{"value":74,"bitlength":24,"delay":706,"protocol":2}



