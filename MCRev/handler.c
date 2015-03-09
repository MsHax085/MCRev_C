#include <Windows.h>
#include <stdio.h>
#include "constants.h"
#include "handler.h"

HANDLE thread = NULL;
char EXECUTE = FALSE,
	 STOPPED = TRUE;

DWORD WINAPI handler_execute(void* data) {
	STOPPED = FALSE;
	printf("Handler started.\n");
	{
		while (EXECUTE) {
			
			Sleep(DELAY);
		}
	}
	printf("Handler stopped.\n");
	STOPPED = TRUE;
	return 0;// Thread goes away when funct. returns
}

char handler_start() {
	if (EXECUTE || !STOPPED) return FALSE;
	EXECUTE = TRUE;
	thread = CreateThread(NULL, 0, handler_execute, NULL, 0, NULL);
	return 1;
}

void handler_stop()  {
	EXECUTE = FALSE;
}