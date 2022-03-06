#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>

static void allLightsOff();
static void interruptHandler(const int);


static void interruptHandler(const int signal) {
	allLightsOff();
	exit(0);
}

int main(void) {
	signal(SIGINT, interruptHandler);

	if (-1 == wiringPiSetup()) {
		printf("Failed to setup Wiring Pi!\n");
		return 1;
	}

	pinMode(19, INPUT);
	pinMode(26, INPUT);
	// 19 and 26
	while(true) {
		digitalRead(19)
		digitalRead(19)
	}

	// Never reached, keeps the compiler happy.
	return 0;
}
