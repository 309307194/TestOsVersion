#include <stdio.h>
#include <stdlib.h>

#include <windows.h>
//#include <VersionHelpers.h>

int main(int argc, char* argv[])
{
	//printf("hello world!!!\n");
	OSVERSIONINFO vs = { sizeof(vs) };
	GetVersionEx(&vs);
	if (vs.dwPlatformId == VER_PLATFORM_WIN32_WINDOWS)
	{
		printf("This is windows 98...\n");
	}
	else if (vs.dwPlatformId == VER_PLATFORM_WIN32_NT)
	{
		printf("This is windows NT...\n");
	}

	//if(!IsWindows7OrGreater())
	//{

	//}

	system("pause");
	return 0;
}