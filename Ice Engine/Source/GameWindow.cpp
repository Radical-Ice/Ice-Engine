#include "Game Window.h"

 void initD3D(HWND hWnd)
{
	d3d = Direct3DCreate9(D3D_SDK_VERSION);    // create the Direct3D interface

	D3DPRESENT_PARAMETERS d3dpp;    // create a struct to hold various device information

	ZeroMemory(&d3dpp, sizeof(d3dpp));    // clear out the struct for use
	d3dpp.Windowed = TRUE;    // program windowed, not fullscreen
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;    // discard old frames
	d3dpp.hDeviceWindow = hWnd;    // set the window to be used by Direct3D

	// create a device class using this information and information from the d3dpp stuct
	d3d->CreateDevice(D3DADAPTER_DEFAULT,
		D3DDEVTYPE_HAL,
		hWnd,
		D3DCREATE_SOFTWARE_VERTEXPROCESSING,
		&d3dpp,
		&d3ddev);

	init_graphics();
}
void render_frame(void)
{
	// clear the window to a deep blue
	d3ddev->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0, 40, 100), 1.0f, 0);

	d3ddev->BeginScene();    // begins the 3D scene

	// do 3D rendering on the back buffer here

	// select which vertex format we are using
	d3ddev->SetFVF(CUSTOMFVF);

	// select the vertex buffer to display
	d3ddev->SetStreamSource(0, v_buffer, 0, sizeof(CUSTOMVERTEX));

	// copy the vertex buffer to the back buffer
	d3ddev->DrawPrimitive(D3DPT_TRIANGLELIST, 0, 1);
	
	d3ddev->EndScene();    // ends the 3D scene

	d3ddev->Present(NULL, NULL, NULL, NULL);    // displays the created frame
}
void cleanD3D(void)
{
	v_buffer->Release();    // close and release the vertex buffer


	d3ddev->Release();    // close and release the 3D device
	d3d->Release();    // close and release Direct3D
}
// this is the function that puts the 3D models into video RAM
void init_graphics(void)
{
	// create the vertices using the CUSTOMVERTEX struct
	CUSTOMVERTEX vertices[] =
	{
		{ 400.0f, 62.5f, 0.5f, 1.0f, D3DCOLOR_XRGB(0, 0, 255), },
		{ 650.0f, 500.0f, 0.5f, 1.0f, D3DCOLOR_XRGB(0, 255, 0), },
		{ 150.0f, 500.0f, 0.5f, 1.0f, D3DCOLOR_XRGB(255, 0, 0), },
	};

	// create a vertex buffer interface called v_buffer
	d3ddev->CreateVertexBuffer(3 * sizeof(CUSTOMVERTEX),
		0,
		CUSTOMFVF,
		D3DPOOL_MANAGED,
		&v_buffer,
		NULL);

	VOID* pVoid;    // a void pointer

	// lock v_buffer and load the vertices into it
	v_buffer->Lock(0, 0, (void**)&pVoid, 0);
	memcpy(pVoid, vertices, sizeof(vertices));
	v_buffer->Unlock();
}





//~~~~~~~~~~~~~~~~~~~~~

//	::SetWindowPos(hWnd, 0, 0, 0, 600, 300, SWP_NOMOVE | SWP_NOOWNERZORDER | SWP_NOZORDER);
//Window Layout

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
		//For Keydown and Keydown for CHAR based(A,a,B,b...)
	case WM_CHAR:
	case WM_KEYDOWN:
		input.ProcessInput(wParam);
		InvalidateRect(hWnd, rect, 1);
		break;
		//For Painting Main Window
	case WM_PAINT:
		//Paint Begins here
		hdc = BeginPaint(hWnd, &ps);

		input.arrayofRects.push_back(RECT{ 0,20,110,50 });
		input.arrayofRects.push_back(RECT{ 0,60,110,100 });
		input.arrayofRects.push_back(RECT{ 0,110,110,150 });

		FillRect(hdc, &input.arrayofRects[0], (HBRUSH)(COLOR_WINDOW + 2));
		FillRect(hdc, &input.arrayofRects[1], (HBRUSH)(COLOR_WINDOW + 3));
		SetDCBrushColor(hdc, RGB(0, 255, 0));
		FillRect(hdc, &input.arrayofRects[2], (HBRUSH)(COLOR_WINDOW + 3));
		//Just drawing some line
		//MoveToEx(hdc, 100, 100, 0); 
		//LineTo(hdc, 150, 150); 
		//LineTo(hdc, 300, 600); 

		//Printing Greetings and Pressed stuff
		//TextOut(hdc,0, 0,greeting, _tcslen(greeting));
		TextOut(hdc, 40, 0, T_Press, _tcslen(T_Press));
		//Setting color red to text.

		SetTextColor(hdc, RGB(255, 0, 0));
		TextOut(hdc, 0, 25, ClearLast, _tcslen(ClearLast));
		SetTextColor(hdc, RGB(0, 0, 255));

		TextOut(hdc, 0, 75, ColorB, _tcslen(ColorB));
		SetTextColor(hdc, RGB(255, 0, 0));


		TextOut(hdc, 0, 120, ColorBL, _tcslen(ColorBL));
		SetTextColor(hdc, RGB(255, 0, 0));

		DrawText(hdc, input.toPrint, _tcslen(input.toPrint), rect, DT_LEFT);
		original = SelectObject(hdc, GetStockObject(DC_PEN));
		switch (input.color)
		{
		case 1:
			SelectObject(hdc, GetStockObject(BLACK_PEN));
			break;
		case 2:
			SetDCPenColor(hdc, RGB(255, 0, 0));
			break;
		}


		//For first time run
		if (input.myBool) {
			SetTextColor(hdc, RGB(255, 0, 0));
			DrawText(hdc, input.toPrint, _tcslen(input.toPrint), rect, DT_LEFT);
			if (input.readyToDrawLine)
			{

				MoveToEx(hdc, input.storedPointBeginX, input.storedPointBeginY, NULL);
				LineTo(hdc, input.storedPointEndX, input.storedPointEndY);

				input.pointsBeginX.push_back(input.storedPointBeginX);
				input.pointsBeginY.push_back(input.storedPointBeginY);
				input.pointsEndX.push_back(input.storedPointEndX);
				input.pointsEndY.push_back(input.storedPointEndY);
			}
		}
		//deletes twice cuase apparently it takes the inital click on the button as a line
		if (input.deleteline == true)
		{
			input.pointsBeginX.pop_back();
			input.pointsBeginX.pop_back();
			input.pointsBeginY.pop_back();
			input.pointsBeginY.pop_back();
			input.pointsEndX.pop_back();
			input.pointsEndX.pop_back();
			input.pointsEndY.pop_back();
			input.pointsEndY.pop_back();
			input.deleteline = false;

		}

		for (int i = 0; i < input.pointsBeginX.size(); i++)
		{
			input.pointsBeginX[i];
			input.pointsBeginY[i];
			input.pointsEndX[i];
			input.pointsEndY[i];
			MoveToEx(hdc, input.pointsBeginX[i], input.pointsBeginY[i], NULL);
			LineTo(hdc, input.pointsEndX[i], input.pointsEndY[i]);
		}

		//Paint ends here
		EndPaint(hWnd, &ps);
		break;
		//For getting mouse coord per sec
	case WM_MOUSEMOVE:
		input.MouseMove(lParam);
		break;
		//On left click draw coord.
	case WM_LBUTTONDOWN:
		input.LeftMouseDown();

		break;
		//On left click up
	case WM_LBUTTONUP:
		input.LeftMouseUp();
		InvalidateRect(hWnd, rect, 1);
		break;
		//On right click draw coord.
	case WM_RBUTTONDOWN:
		input.RightButtonDown();

		InvalidateRect(hWnd, rect, 1);
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
		break;
	}

	return DefWindowProc(hWnd, message, wParam, lParam);
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
