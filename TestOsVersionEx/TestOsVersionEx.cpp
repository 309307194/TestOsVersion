///

#include <iostream>
#include <stdlib.h>
#include <string>

#include <Windows.h>

using namespace std;

#ifndef SM_SERVERR2 
#define SM_SERVERR2 89
#endif

#ifndef VER_SUITE_WH_SERVER
#define VER_SUITE_WH_SERVER 0x00008000	//AppServer mode is enabled. 
#endif


int main(int argc, char* argv[])
{
	printf("hello world!!!\n");

	string vname;

	SYSTEM_INFO info;
	GetSystemInfo(&info);
	OSVERSIONINFOEX os;
	os.dwOSVersionInfoSize = sizeof(OSVERSIONINFOEX);
	if (GetVersionEx((OSVERSIONINFO*)&os))
	{
		//string vname;
		switch (os.dwMajorVersion)
		{
		case 4:
			switch (os.dwMinorVersion)
			{
			case 0:
				if (os.dwPlatformId == VER_PLATFORM_WIN32_NT)
					vname = "Windows NT 4.0";
				else if (os.dwPlatformId == VER_PLATFORM_WIN32_WINDOWS)
					vname = "Windows 95";
				break;
			case 10:
				vname = "Windows 98";
				break;
			case 90:
				vname = "Windwos Me";
				break;
			}

			break;
		case 5:
			switch (os.dwMinorVersion)
			{
			case 0:
				vname = "Windows 2000";
				break;
			case 1:
				vname = "Windows xp";
				break;
			case 2:
				if ((os.wProductType == VER_NT_WORKSTATION) && (info.wProcessorArchitecture == PROCESSOR_ARCHITECTURE_AMD64))
					vname = "Windows XP Professional x64 Edition";
				else if (GetSystemMetrics(SM_SERVERR2) == 0)
					vname = "Windows Server 2003";
				else if (os.wSuiteMask & VER_SUITE_WH_SERVER)
					vname = "Windows Home Server";
				else if (GetSystemMetrics(SM_SERVERR2) != 0)
					vname = "Windows Server 2003 R2";
				break;
			}

			break;
		case 6:
			switch (os.dwMinorVersion)
			{
			case 0:
				vname = "Windows Server 2008";
				break;
			case 1:
				if (os.wProductType != VER_NT_WORKSTATION)
					vname = "Windows Server 2008 R2";
				else if (os.wProductType == VER_NT_WORKSTATION)
					vname = "Windows 7";
				break;
			case 2:
				if (os.wProductType != VER_NT_WORKSTATION)
					vname = "Windows Server 2012";
				else if (os.wProductType == VER_NT_WORKSTATION)
					vname = "Windows 8";
				break;
			case 3:
				if (os.wProductType != VER_NT_WORKSTATION)
					vname = "Windows Server 2012 R2";
				else if (os.wProductType == VER_NT_WORKSTATION)
					vname = "Windows 8.1";
				break;
			}

			break;

		case 10:
			switch (os.dwMinorVersion)
			{
			case 0:
				if (os.wProductType != VER_NT_WORKSTATION)
					vname = "Windows Server 2016";
				else if (os.wProductType == VER_NT_WORKSTATION)
					vname = "Windows 10";
				break;
			}

			break;

		}
	}

	//printf("%s\n", vname);
	cout << vname << endl;
	system("pause");
	return 0;
}