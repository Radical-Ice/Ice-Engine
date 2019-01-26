#pragma once
#include <windows.h>  
#include <stdlib.h>  
#include <string.h>  
#include <tchar.h>  
#include <direct.h>
#include<iostream>
#include <intrin.h>
using namespace std;

// Global variables
class Checking
{
public:
	bool IsOnlyInstance(LPCSTR gameTitle);
	bool CheckStorage(const DWORDLONG diskSpaceNeeded);
	bool CheckMemory(const DWORDLONG physicalRAMNeeded, const DWORDLONG virtualRAMNeeded);
	DWORD ReadCPUSpeed();
	DWORD ReadCPUName();
	void initChecks(LPCSTR szWindowClass, int physicalRAMNeed, int virtualRAMNeed, int diskSpaceNeed);
};

