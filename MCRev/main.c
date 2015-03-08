#include "main.h"
#include "constants.h"
//#include <Windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
//#include <mysql.h>

char RUN = 1;

int main() {
	printf("Revision [Version: %s]\n", VERSION);

	if (AUTO_START) {
		printf("Autostart enabled!");
		handle_input("START");
	}
	
	printf("Waiting for commands ...\n");
	watch_input();

	if (DEBUG) getchar();// Leave window open
	return 0;
}

void watch_input() {
	
	char row[MAX_CMD_LEN + 1];// + '\0'
	
	while (RUN) {
		fgets(row, MAX_CMD_LEN + 1, stdin);
		handle_input(row);
		memset(row, 0, sizeof row);
		fflush(stdin);
	}
}

void handle_input(char row[]) {
	if (strncmp(row, "START", 5) == 0 || strncmp(row, "start", 5) == 0) {
		funct_start();
	} else
	if (strncmp(row, "STOP", 4) == 0 || strncmp(row, "stop", 4) == 0) {
		funct_stop();
	} else
	if (strncmp(row, "EXIT", 4) == 0 || strncmp(row, "exit", 4) == 0) {
		funct_exit();
	} else
	if (strncmp(row, "HELP", 4) == 0 || strncmp(row, "help", 4) == 0) {
		funct_help();
	} else {
		printf("Unknown command.\n");
	}
}

void funct_start() {
	printf("Caught\n");
}

void funct_stop() {
	printf("Caught\n");
}

void funct_exit() {
	exit(0);
}

void funct_help() {
	printf("==\n");
	printf(" START - Start server handler\n");
	printf(" STOP	- Stop server handler\n");
	printf(" EXIT  - Exit application\n");
	printf("==\n");
}