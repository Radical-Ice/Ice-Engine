#include "Checking.h"
#pragma once


//For Instance Check
bool Checking::IsOnlyInstance(LPCSTR gameTitle) {
	HANDLE handle = CreateMutex(NULL, TRUE, gameTitle);
	if (GetLastError() != ERROR_SUCCESS) {
		HWND hWnd = FindWindow(gameTitle, NULL);
		if (hWnd) {
			// An instance of the game is already running.
			ShowWindow(hWnd, SW_SHOWNORMAL);
			SetFocus(hWnd);
			SetForegroundWindow(hWnd);
			SetActiveWindow(hWnd);
			return false;
		}
	}
	return true;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


//For Storage Check
bool Checking::CheckStorage(const DWORDLONG diskSpaceNeeded) {
	// Check for enough free disk space on the current disk.
	int const drive = _getdrive();
	struct _diskfree_t diskfree;
	_getdiskfree(drive, &diskfree);
	unsigned __int64 const neededClusters
		= diskSpaceNeeded /
		(diskfree.sectors_per_cluster *
			diskfree.bytes_per_sector);
	if (diskfree.avail_clusters < neededClusters) {
		//****Fail*******

		cout << "CheckStorage Failure: Not enough physical storage.";
		return false;
	}
	return true;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

//~~~~For Memory Check
bool Checking::CheckMemory(const DWORDLONG physicalRAMNeeded, const DWORDLONG virtualRAMNeeded) {
	MEMORYSTATUSEX status;
	status.dwLength = sizeof(status);
	GlobalMemoryStatusEx(&status);
	//RAM Check
	if (status.ullTotalPhys < physicalRAMNeeded) {
		//****Fail*******
		cout << ("CheckMemory Failure: Not enough physical memory.");
		return false;
	}

	//****Pass*******
	cout << "Total Ram = ";
	cout << (status.ullTotalPhys / 1024) / 1024 << " MB" << endl;


	//VRAM Check
	if (status.ullAvailVirtual < virtualRAMNeeded) {
		//****Fail*******
		cout << ("CheckMemory Failure: Not enough virtual memory.");
		return false;
	}

	//****Pass*******
	cout << "Total VirtualRam = ";
	cout << (status.ullAvailVirtual / 1024) / 1024 << " MB" << endl;

	char *buff = new char[virtualRAMNeeded];
	if (buff)
		delete[] buff;
	else {
		cout << ("CheckMemory Failure: Not enough contiguous memory.");
		return false;
	}
	cout << "enough memory" << endl;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

//~~~~For CPU Clock Speed
DWORD Checking::ReadCPUSpeed() {
	DWORD BufSize = sizeof(DWORD);
	DWORD dwMHz = 0;
	DWORD type = REG_DWORD;
	HKEY hKey;
	// open the key where the proc speed is hidden:
	long lError = RegOpenKeyEx(HKEY_LOCAL_MACHINE,
		"HARDWARE\\DESCRIPTION\\System\\CentralProcessor\\0",
		0,
		KEY_READ,
		&hKey);
	if (lError == ERROR_SUCCESS) {
		// query the key:
		RegQueryValueEx(hKey,
			"~MHz",
			NULL,
			&type,
			(LPBYTE)&dwMHz,
			&BufSize);
	}
	return dwMHz;
}
//
DWORD Checking::ReadCPUName()
{
	int CPUInfo[4] = { -1 };
	unsigned   nExIds, i = 0;
	char CPUBrandString[0x40];
	// Get the information associated with each extended ID.
	__cpuid(CPUInfo, 0x80000000);
	nExIds = CPUInfo[0];
	for (i = 0x80000000; i <= nExIds; ++i)
	{
		__cpuid(CPUInfo, i);
		// Interpret CPU brand string
		if (i == 0x80000002)
			memcpy(CPUBrandString, CPUInfo, sizeof(CPUInfo));
		else if (i == 0x80000003)
			memcpy(CPUBrandString + 16, CPUInfo, sizeof(CPUInfo));
		else if (i == 0x80000004)
			memcpy(CPUBrandString + 32, CPUInfo, sizeof(CPUInfo));
	}
	//string includes manufacturer, model and clockspeed
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "CPU Type: " << CPUBrandString << endl;
	return 0;



}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void Checking::initChecks(LPCSTR szWindowClass,int physicalRAMNeed, int virtualRAMNeed,int diskSpaceNeed) {
	//~~~Check For Multipl Instance~~~~
	if (!IsOnlyInstance(szWindowClass)) {
		cout << "Not the only instance" << endl;
		system("pause");
		return ;
	}
	cout << "the only instance" << endl;

	//~~~Check For Storage~~~~~~~~~~~~~~~ 
	CheckMemory(physicalRAMNeed, virtualRAMNeed);

	if (!CheckStorage(diskSpaceNeed)) {
		cout << "not enough disk space" << endl;
		system("pause");
		return ;
	}
	cout << "enough disk space" << endl;
	//~~For CPU Info~~~~~~~~~~~~~~~~~~~~
	SYSTEM_INFO siSysInfo;
	GetSystemInfo(&siSysInfo);
	//For CPU Name
	ReadCPUName();

	if (siSysInfo.wProcessorArchitecture == 0)
	{
		cout << "Processor Architecture : x86" << endl;
	}
	else if (siSysInfo.wProcessorArchitecture == 5)
	{
		cout << "Processor Architecture : ARM" << endl;
	}
	else if (siSysInfo.wProcessorArchitecture == 12)
	{
		cout << "Processor Architecture : ARM64" << endl;
	}
	else if (siSysInfo.wProcessorArchitecture == 6)
	{
		cout << "Processor Architecture : Intel Itanium-based" << endl;
	}
	else if (siSysInfo.wProcessorArchitecture == 9)
	{
		cout << "Processor Architecture : x64 (AMD or Intel)" << endl;
	}
	else
	{
		cout << "Processor Architecture : Unknown architecture" << endl;
	}
	//cout << "Processor Architecture : " << siSysInfo.wProcessorArchitecture << endl;
	cout << "Processor Speed : " << ReadCPUSpeed();
	//~~~For Memory Info~~~~~~~~~~~~~~~~
	MEMORYSTATUSEX statex;
	statex.dwLength = sizeof(statex);
	GlobalMemoryStatusEx(&statex);
	cout << "\nTotal System Memory: " << (statex.ullTotalPhys / 1024) << " MB" << endl;
	

}

