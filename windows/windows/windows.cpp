/*-----------------------------------------
   BLOKOUT1.C -- Mouse Button Demo Program
				 (c) Charles Petzold, 1998
  -----------------------------------------*/

#include <windows.h>
#include <windowsx.h>
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	PSTR szCmdLine, int iCmdShow)
{
	static TCHAR szAppName[] = TEXT("BlokOut1");
	HWND         hwnd;
	MSG          msg;
	WNDCLASS     wndclass;

	wndclass.style = CS_HREDRAW | CS_VREDRAW;
	wndclass.lpfnWndProc = WndProc;
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.hInstance = hInstance;
	wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wndclass.lpszMenuName = NULL;
	wndclass.lpszClassName = szAppName;

	if (!RegisterClass(&wndclass))
	{
		MessageBox(NULL, TEXT("Program requires Windows NT!"),
			szAppName, MB_ICONERROR);
		return 0;
	}

	hwnd = CreateWindow(szAppName, TEXT("Mouse Button Demo"),
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT,
		CW_USEDEFAULT, CW_USEDEFAULT,
		NULL, NULL, hInstance, NULL);

	ShowWindow(hwnd, iCmdShow);
	UpdateWindow(hwnd);

	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.wParam;
}

void DrawBoxOutline(HWND hwnd, POINT ptBeg, POINT ptEnd)
{
	HDC hdc;

	hdc = GetDC(hwnd);

	SetROP2(hdc, R2_NOT);
	SelectObject(hdc, GetStockObject(NULL_BRUSH));
	Rectangle(hdc, ptBeg.x, ptBeg.y, ptEnd.x, ptEnd.y);

	ReleaseDC(hwnd, hdc);
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	static BOOL  fBlocking, fValidBox;
	static POINT ptBeg, ptEnd, ptBoxBeg, ptBoxEnd, d;
	static int mx, my;
	int b, s;
	TCHAR c[20];
	HDC          hdc;
	PAINTSTRUCT  ps;
	static RECT re;

	switch (message)
	{
	case WM_CREATE:

		re.top = 0;
		re.left = 0;
		re.bottom = 500;
		re.right = 500;

		return 0;

	case WM_LBUTTONDOWN:
		ptBeg.x = ptEnd.x = GET_X_LPARAM(lParam);
		ptBeg.y = ptEnd.y = GET_Y_LPARAM(lParam);

		SetCursor(LoadCursor(NULL, IDC_CROSS));

		return 0;

	case WM_MOUSEMOVE:
		SetCursor(LoadCursor(NULL, IDC_CROSS));

		ptEnd.x = GET_X_LPARAM(lParam);
		ptEnd.y = GET_Y_LPARAM(lParam);

		d.x = mx - GET_X_LPARAM(lParam);
		d.y = my - GET_Y_LPARAM(lParam);
		mx = LOWORD(lParam);
		my = HIWORD(lParam);

		InvalidateRect(hwnd, &re, TRUE);

		hdc = BeginPaint(hwnd, &ps);

		s = wsprintf(c, TEXT("鼠标位置x%d,y%d"), mx, my);
		TextOut(hdc, 10, 10, c, s);
		s = wsprintf(c, TEXT("鼠标变化x%d,y%d"), d.x, d.y);
		TextOut(hdc, 10, 50, c, s);

		EndPaint(hwnd, &ps);

		return 0;

	case WM_LBUTTONUP:
		if (fBlocking)
		{

			ptBoxBeg = ptBeg;
			ptBoxEnd.x = GET_X_LPARAM(lParam);
			ptBoxEnd.y = GET_Y_LPARAM(lParam);

			SetCursor(LoadCursor(NULL, IDC_ARROW));

			fBlocking = FALSE;
			fValidBox = TRUE;

			InvalidateRect(hwnd, NULL, TRUE);
		}
		return 0;

	case WM_PAINT:

		return 0;

	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hwnd, message, wParam, lParam);
}