#include "main.h"
#include "constants.h"
//#include <Windows.h>
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
	if (strcmp(row, "START") == 0 || strcmp(row, "start") == 0) {
		funct_start();
	} else
	if (strcmp(row, "STOP") == 0 || strcmp(row, "stop") == 0) {
		funct_stop();
	} else
	if (strcmp(row, "EXIT") == 0 || strcmp(row, "exit") == 0) {
		funct_exit();
	} else
	if (strcmp(row, "HELP") == 0 || strcmp(row, "help") == 0) {
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
	printf("Caught\n");
}

void funct_help() {
	printf("Caught\n");
}