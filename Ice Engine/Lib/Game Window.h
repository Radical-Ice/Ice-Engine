#pragma once
#include <string>
#include <vector>
#include "..\Lib\InputProcesser.h"
#include <tchar.h>
#include <d3d9.h>

// include the Direct3D Library file
#pragma comment (lib, "d3d9.lib")

// global declarations
static LPDIRECT3D9 d3d;    // the pointer to our Direct3D interface
static LPDIRECT3DDEVICE9 d3ddev;    // the pointer to the device class
static LPDIRECT3DVERTEXBUFFER9 v_buffer = NULL;    // the pointer to the vertex buffer

void init_graphics(void);    // 3D declarations

struct CUSTOMVERTEX { FLOAT X, Y, Z, RHW; DWORD COLOR; };
#define CUSTOMFVF (D3DFVF_XYZRHW | D3DFVF_DIFFUSE)


// function prototypes
void initD3D(HWND hWnd);    // sets up and initializes Direct3D
void render_frame(void);    // renders a single frame
void cleanD3D(void);    // closes Direct3D and releases memory

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

using namespace std;
//Global variables

//LPCSTR toPrint = "Press Some Buttons :-) ";
//bool myBool = 0;
//LPCSTR value = "test";

static LPRECT rect = new RECT{ 110,0,1000,1000 };
//string storedKey = "a";

static TCHAR greeting[] = _T("Hello, World!");
static TCHAR T_Press[] = _T("Pressed : ");
static TCHAR Button[] = _T("Press Here");
static TCHAR ClearLast[] = _T("clear last line");
static TCHAR ColorB[] = _T("Make Lines Blue");
static TCHAR ColorBL[] = _T("Make Lines Black");

const int arraySize = 100;
static HGDIOBJ original = NULL;
static PAINTSTRUCT ps;
static HDC hdc;
static InputProcesser input;