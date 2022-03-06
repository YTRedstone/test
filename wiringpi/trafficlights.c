#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>

static void interruptHandler(const int);


static void interruptHandler(const int signal) {
	exit(0);
}

int main(void) {
	signal(SIGINT, interruptHandler);

	if (-1 == wiringPiSetup()) {
		printf("Failed to setup Wiring Pi!\n");
		return 1;
	}

	pinMode(21, INPUT);
	pinMode(40, INPUT);
	// 19 and 26
	while(1) {
		digitalRead(21);
		digitalRead(40);
	}

	// Never reached, keeps the compiler happy.
	return 0;
}
