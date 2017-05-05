
# Defines the RPI variable which is needed by rc-switch/RCSwitch.h
CXXFLAGS=-DRPI

all: senddemo receivedemo receivedemo_json

senddemo: rc-switch/RCSwitch.o senddemo.o
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $+ -o $@ -lwiringPi

receivedemo: rc-switch/RCSwitch.o receivedemo.o
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $+ -o $@ -lwiringPi

receivedemo_json: rc-switch/RCSwitch.o receivedemo_json.o
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $+ -o $@ -lwiringPi

clean:
	$(RM) *.o senddemo receivedemo receivedemo_json

