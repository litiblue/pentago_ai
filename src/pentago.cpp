#include <windows.h>
#include "const.h"
#include "game.h"
#include "ai.h"
#include "ready.h"

LRESULT CALLBACK WndProc(HWND,UINT,WPARAM,LPARAM);
HINSTANCE g_hInst;
HWND hWndMain, hWndProc;
LPCTSTR lpszClass=TEXT("MatrixMethod");

#include <gdiplus.h>
using namespace Gdiplus;
#pragma comment(lib, "gdiplus")
class CGdiPlusStarter
{
private:
	ULONG_PTR m_gpToken;

public:
	bool m_bSuccess;
	CGdiPlusStarter() {
		GdiplusStartupInput gpsi;
		m_bSuccess=(GdiplusStartup(&m_gpToken,&gpsi,NULL) == Ok);
	}
	~CGdiPlusStarter() {
		GdiplusShutdown(m_gpToken);
	}
};
CGdiPlusStarter g_gps;

int ChkLine[32][5];
int ChkLim=0;

int StoneCnt=0;
int LevelLimit=0;

__int64 HashS1[HASHM], HashS2[HASHM];
int HashV[HASHM], HashT[HASHM], HashDepth[HASHM], HashCnt[HASHM];
int CallCnt=0, HashAtomCnt=0;

char id[BUFSIZE];

int StartTime, EndTime;
int GameEndChk;
int initChk;
int iSave, jSave, drSave;

__int64 gl_s1, gl_s2;

#define MAX_LOADSTRING 100

// 보드의 크기
#define N 6

// 버튼 상태
#define OFF 0
#define ON  1
#define ROTATING 2
#define AI 3

#define BOARD	1
#define BUTTON	2
#define OUTSIDE  -1

// 회번 방향
#define LEFT 0
#define RIGHT 1

// 전역 변수:
HINSTANCE hInst;								// 현재 인스턴스입니다.

int Board[N][N];
int BoardLeft = 100;
int BoardRight = 400;
int BoardTop = 100;
int BoardBottom = 400;

int ButtonSpace = 30;
int ButtonSizeShort = 25;
int ButtonSizeLong  = 60;

RECT ButtonRect[8];

int ClickType;

int Turn;
int ButtonState;

int RotatingSmallBoard;
int RotatingDirection;

int angle;
int PushedButton;

int EndMsg;
int SavedTurn;

void SetBoard(void)
{
	int i, j;

	for (i=0; i<N; i++)
		for (j=0; j<N; j++)
			Board[i][j] = NONE;
	
	Turn = BLACK;
}

void SetButtonRect(void)
{
	SetRect ( &ButtonRect[0], BoardLeft-ButtonSpace-ButtonSizeShort, BoardTop, BoardLeft-ButtonSpace, BoardTop+ButtonSizeLong);	
	SetRect ( &ButtonRect[1], BoardLeft, BoardTop-ButtonSpace-ButtonSizeShort, BoardLeft+ButtonSizeLong, BoardTop-ButtonSpace);
	SetRect ( &ButtonRect[2], BoardRight-ButtonSizeLong, BoardTop-ButtonSpace-ButtonSizeShort, BoardRight, BoardTop-ButtonSpace);
	SetRect ( &ButtonRect[3], BoardRight+ButtonSpace, BoardTop, BoardRight+ButtonSpace+ButtonSizeShort, BoardTop+ButtonSizeLong);
	SetRect ( &ButtonRect[4], BoardRight+ButtonSpace, BoardBottom-ButtonSizeLong, BoardRight+ButtonSpace+ButtonSizeShort, BoardBottom);
	SetRect ( &ButtonRect[5], BoardRight-ButtonSizeLong, BoardBottom+ButtonSpace, BoardRight, BoardBottom+ButtonSpace+ButtonSizeShort);
	SetRect ( &ButtonRect[6], BoardLeft, BoardBottom+ButtonSpace, BoardLeft+ButtonSizeLong, BoardBottom+ButtonSpace+ButtonSizeShort);
	SetRect ( &ButtonRect[7], BoardLeft-ButtonSpace-ButtonSizeShort, BoardBottom-ButtonSizeLong, BoardLeft-ButtonSpace, BoardBottom);
}

bool BoardOut (int i, int j)
{
	if (i<0 || i>N || j<0 || j>N) return 1;
	else return 0;
}


bool FiveCheck (int CenterI, int CenterJ)
{
	int dr[4][2]={{0,1},{1,0},{-1,1},{1,1}};
	int k, cnt;
	int i, j, ni, nj;
	int StoneColor = Board[CenterI][CenterJ];

	for (k=0; k<4; k++) {
		cnt = 1;
		
		i = CenterI;
		j = CenterJ;
		while (1) {
			ni = i - dr[k][0];
			nj = j - dr[k][1];
			if ( BoardOut(ni, nj) || Board[ni][nj]!=StoneColor ) break;
			else {
				cnt++;
				i = ni;
				j = nj;
			}			
		}
		
		i = CenterI;
		j = CenterJ;
		while (1) {
			ni = i + dr[k][0];
			nj = j + dr[k][1];
			if ( BoardOut(ni, nj) || Board[ni][nj]!=StoneColor ) break;
			else {
				cnt++;
				i = ni;
				j = nj;
			}			
		}

		if (cnt >= 5)
			return 1;
	}

	return 0;
}

bool FiveCheckGroup (int Starti, int Startj, int Endi, int Endj)
{
	int i, j;

	for (i = Starti; i <= Endi; i++) {
		for (j = Startj; j <= Endj; j++) {
			if ( Board[i][j]!=NONE && FiveCheck(i, j) ) 
				return 1;
		}
	}
	return 0;		
}

void MyPut(__int64 &s1, __int64 &s2)
{
	int r, c, Ar, Ac;

	StartTime = GetTickCount();
	GameEndChk = 0;
	initChk = 0;
	if (StoneCnt == 35) {
		Ending (s1, 2);
	}
	for (LevelLimit=1; LevelLimit<=36-StoneCnt-1; LevelLimit++) {
		ai (s1, s2);
		if (GameEndChk) {
			break;
		}
	}

	ai (s1, s2);

	r = iSave / 6;
	c = iSave % 6;
	
	Board[r][c] = Turn;

	if(jSave == 0)
	{
		if(drSave == 0) {
			PushedButton = 1;
		}
		else {
			PushedButton = 0;
		}
	}
	else if(jSave == 1)
	{
		if(drSave == 0) {
			PushedButton = 3;
		}
		else {
			PushedButton = 2;
		}
	}
	else if(jSave == 2)
	{
		if(drSave == 0) {
			PushedButton = 7;
		}
		else {
			PushedButton = 6;
		}
	}
	else if(jSave == 3)
	{
		if(drSave == 0) {
			PushedButton = 5;
		}
		else {
			PushedButton = 4;
		}
	}

	ButtonState = ROTATING;

	if ( FiveCheck (r,c) ) {
		EndMsg = 1;
		SavedTurn = Turn;
	}
/*
	for (i=0; i<N; i++)
	{
		for (j=0; j<N; j++)
		{
			if(Board[i][j] == NONE)
			{
				Board[i][j] = Turn;
				PushedButton=6;
				ButtonState = ROTATING;
			
				if ( FiveCheck (i,j) ) {
					EndMsg = 1;
					SavedTurn = Turn;
				}
				return;
			}
		}
	}*/
}

void Renew(void)
{
	int t1, t2;
	
	switch (PushedButton)
	{
	case 0:
		t1=Board[0][2]; t2=Board[0][1]; 
		Board[0][2]=Board[0][0]; Board[0][1]=Board[1][0];
		Board[0][0]=Board[2][0]; Board[1][0]=Board[2][1]; 
		Board[2][0]=Board[2][2]; Board[2][1]=Board[1][2]; 
		Board[2][2]=t1; Board[1][2]=t2;
		RotatingDirection = RIGHT;
		break;

	case 1:
		t1=Board[0][0]; t2=Board[0][1]; 
		Board[0][0]=Board[0][2]; Board[0][1]=Board[1][2];
		Board[0][2]=Board[2][2]; Board[1][2]=Board[2][1]; 
		Board[2][2]=Board[2][0]; Board[2][1]=Board[1][0]; 
		Board[2][0]=t1; Board[1][0]=t2;
		RotatingDirection = LEFT;
		break;
	
	case 2:
		t1=Board[0][5]; t2=Board[0][4]; 
		Board[0][5]=Board[0][3]; Board[0][4]=Board[1][3];
		Board[0][3]=Board[2][3]; Board[1][3]=Board[2][4]; 
		Board[2][3]=Board[2][5]; Board[2][4]=Board[1][5]; 
		Board[2][5]=t1; Board[1][5]=t2;
		RotatingDirection = RIGHT;
		break;

	case 3:
		t1=Board[0][3]; t2=Board[0][4]; 
		Board[0][3]=Board[0][5]; Board[0][4]=Board[1][5];
		Board[0][5]=Board[2][5]; Board[1][5]=Board[2][4]; 
		Board[2][5]=Board[2][3]; Board[2][4]=Board[1][3]; 
		Board[2][3]=t1; Board[1][3]=t2;
		RotatingDirection = LEFT;
		break;

	case 4:
		t1=Board[3][5]; t2=Board[3][4]; 
		Board[3][5]=Board[3][3]; Board[3][4]=Board[4][3];
		Board[3][3]=Board[5][3]; Board[4][3]=Board[5][4]; 
		Board[5][3]=Board[5][5]; Board[5][4]=Board[4][5]; 
		Board[5][5]=t1; Board[4][5]=t2; 
		RotatingDirection = RIGHT;
		break;

	case 5:
		t1=Board[3][3]; t2=Board[3][4]; 
		Board[3][3]=Board[3][5]; Board[3][4]=Board[4][5];
		Board[3][5]=Board[5][5]; Board[4][5]=Board[5][4]; 
		Board[5][5]=Board[5][3]; Board[5][4]=Board[4][3]; 
		Board[5][3]=t1; Board[4][3]=t2;
		RotatingDirection = LEFT;
		break;	

	case 6:
		t1=Board[3][2]; t2=Board[3][1]; 
		Board[3][2]=Board[3][0]; Board[3][1]=Board[4][0];
		Board[3][0]=Board[5][0]; Board[4][0]=Board[5][1]; 
		Board[5][0]=Board[5][2]; Board[5][1]=Board[4][2]; 
		Board[5][2]=t1; Board[4][2]=t2;
		RotatingDirection = RIGHT;
		break;

	case 7:
		t1=Board[3][0]; t2=Board[3][1]; 
		Board[3][0]=Board[3][2]; Board[3][1]=Board[4][2];
		Board[3][2]=Board[5][2]; Board[4][2]=Board[5][1]; 
		Board[5][2]=Board[5][0]; Board[5][1]=Board[4][0]; 
		Board[5][0]=t1; Board[4][0]=t2;
		RotatingDirection = LEFT;
		break;
	}

	angle = 0;
	
	if(Turn == BLACK)
	{
		Turn = WHITE;
		ButtonState = AI;
	
		gl_s1 = 0;
		gl_s2 = 0;
		StateToS(Board, gl_s1, gl_s2);
		MyPut(gl_s1, gl_s2);
		StoneCnt++;
	}
	else
	{
		Turn = BLACK;
		ButtonState = OFF;
	}

	if ( FiveCheckGroup (0, 0, 2, 2) ) {
		EndMsg = 2;
		SavedTurn = Turn;
	}
	if ( FiveCheckGroup (0, 3, 2, 5) ) {
		EndMsg = 3;
		SavedTurn = Turn;
	}
	if ( FiveCheckGroup (3, 0, 5, 2) ) {
		EndMsg = 4;
		SavedTurn = Turn;
	}
	if ( FiveCheckGroup (3, 3, 5, 5) ) {
		EndMsg = 5;
		SavedTurn = Turn;
	}
}

void DrawSmallBoard(HDC hdc, int num)
{
	int i, j;
	int CenterX, CenterY;
	int si, sj, ei, ej;

	Graphics G(hdc);

	Matrix M;
	
	Pen P(Color(0,0,0));

	if(ButtonState == ROTATING)
	{
		if(PushedButton==0 || PushedButton==2 || PushedButton==4 || PushedButton==6)
		{
			angle++;
			if(angle >= 91) {
				Renew();
			}
		}
		else/* if(RotatingDirection == RIGHT)*/
		{
			angle--;
			if(angle <= -91) {
				Renew();			
			}
		}
	}

	switch(num)
	{
		case 0 :
			si=0; sj=0; ei=2; ej=2;
			if(PushedButton == 0 || PushedButton == 1)
			M.RotateAt(angle,PointF(BoardLeft+75,BoardTop+75));
			break;
		case 1 :
			si=0; sj=3; ei=2; ej=5; 
			if(PushedButton == 2 || PushedButton == 3)
			M.RotateAt(angle,PointF(BoardLeft+225,BoardTop+75));
			break;
		case 2 :
			si=3; sj=3; ei=5; ej=5; 			
			if(PushedButton == 4 || PushedButton == 5)
			M.RotateAt(angle,PointF(BoardLeft+225,BoardTop+225));
			break;
		case 3 :
			si=3; sj=0; ei=5; ej=2;			
			if(PushedButton == 6 || PushedButton == 7)
			M.RotateAt(angle,PointF(BoardLeft+75,BoardTop+225));
			break;
	}

	G.SetTransform(&M);

	for (i=si; i<=ei; i++) {
		for (j=sj; j<=ej; j++) {

			// 행과 열을 그려질 돌의 중심 좌표로 변환
			CenterX = BoardLeft + j * 50 + 25;
			CenterY = BoardTop  + i * 50 + 25;
			// 돌의 색에 따른 브러시 설정

			Color C1(255,255,255);
			Color C2(200,200,200);
			Color C3(0,0,0);

			SolidBrush B1(C1);
			SolidBrush B2(C2);
			SolidBrush B3(C3);

			G.FillRectangle(&B1,CenterX-25, CenterY-25, 50, 50);

			Rect rect;
			rect.X = CenterX-25;
			rect.Y = CenterY-25;
			rect.Width = 50;
			rect.Height = 50;

			G.DrawRectangle(&P, rect);
/*
			G.DrawLine(&P,CenterX-25, CenterY-25,CenterX+25, CenterY-25);
			G.DrawLine(&P,CenterX-25, CenterY+25,CenterX+25, CenterY+25);
			G.DrawLine(&P,CenterX-25, CenterY-25,CenterX-25, CenterY+25);
			G.DrawLine(&P,CenterX+25, CenterY-25,CenterX+25, CenterY+25);
*/
			switch (Board[i][j]) 
			{
			case NONE:
//				BrushColor = WHITE_BRUSH;
				G.FillEllipse(&B1, CenterX-23, CenterY-23, 46, 46);
				break;
			case WHITE:
//				BrushColor = LTGRAY_BRUSH;
				G.FillEllipse(&B2, CenterX-23, CenterY-23, 46, 46);

				break;
			case BLACK:
//				BrushColor = BLACK_BRUSH;
				G.FillEllipse(&B3, CenterX-23, CenterY-23, 46, 46);
				break;
			}

//		    Graphics G(hdc);
//			SelectObject ( hdc, GetStockObject (BrushColor) );
//			Ellipse (hdc, CenterX-20, CenterY-20, CenterX+20, CenterY+20);
		}
	}	

	RECT rect;
	SetRect (&rect, 0, 0, BoardRight+100, BoardBottom+100);
	InvalidateRect (hWndMain, &rect, FALSE);
}

int APIENTRY WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance
	  ,LPSTR lpszCmdParam,int nCmdShow)
{
	HWND hWnd;
	MSG Message;
	WNDCLASS WndClass;
	g_hInst=hInstance;

	if (g_gps.m_bSuccess == FALSE) {
		MessageBox(NULL,TEXT("GDI+ 라이브러리를 초기화할 수 없습니다."),
			TEXT("알림"),MB_OK);
		return 0;
	}

	WndClass.cbClsExtra=0;
	WndClass.cbWndExtra=0;
	WndClass.hbrBackground=(HBRUSH)(COLOR_WINDOW+1);
	WndClass.hCursor=LoadCursor(NULL,IDC_ARROW);
	WndClass.hIcon=LoadIcon(NULL,IDI_APPLICATION);
	WndClass.hInstance=hInstance;
	WndClass.lpfnWndProc=WndProc;
	WndClass.lpszClassName=lpszClass;
	WndClass.lpszMenuName=NULL;
	WndClass.style=CS_HREDRAW | CS_VREDRAW;
	RegisterClass(&WndClass);

	hWnd=CreateWindow(lpszClass,lpszClass,WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,CW_USEDEFAULT,BoardRight+100, BoardBottom+130,
		NULL,(HMENU)NULL,hInstance,NULL);
	ShowWindow(hWnd,nCmdShow);

	while (GetMessage(&Message,NULL,0,0)) {
		TranslateMessage(&Message);
		DispatchMessage(&Message);

		if(EndMsg > 0)
		{
			if(SavedTurn == BLACK)
			{
				MessageBox (hWnd, "Black Win!", "Black Win!", MB_OK);
			}
			else
			{
				MessageBox (hWnd, "WHITE Win!", "WHITE Win!", MB_OK);
			}
		
			break;
		}
	}
	return (int)Message.wParam;
}

#include <math.h>
TCHAR Mode=TEXT('1');

LRESULT CALLBACK WndProc(HWND hWnd,UINT iMessage,WPARAM wParam,LPARAM lParam)
{
	int wmId, wmEvent;
	int i, j;
	int CenterX, CenterY;
	int ClickX, ClickY;
	int BrushColor ;

	static int cxClient, cyClient;

	PAINTSTRUCT ps;
	HDC hdc;

	static HDC  hdcBackBuffer;
	static HBITMAP hBitmap;
	static HBITMAP hOldBitmap;
	
	RECT rect;

	hWndProc = hWnd;

	switch (iMessage)
	{
	case WM_CREATE:
		hWndMain=hWnd;

		MakeChkLine();

		SetBoard();
		SetButtonRect();

		SetTimer(hWnd, 1, 20, NULL);

		RECT rect;
		GetClientRect(hWnd, &rect);

		cxClient = rect.right;
		cyClient = rect.bottom;

		hdcBackBuffer = CreateCompatibleDC(NULL);

		hdc = GetDC(hWnd);

		hBitmap = CreateCompatibleBitmap(hdc, cxClient, cyClient);

		hOldBitmap = (HBITMAP)SelectObject(hdcBackBuffer, hBitmap);

		ReleaseDC(hWnd, hdc);
		return 0;

	case WM_TIMER :
		hdc=GetDC(hWnd);
		DrawSmallBoard(hdc, RotatingSmallBoard);
		ReleaseDC(hWnd,hdc);
		return 0;

	case WM_LBUTTONUP:
		ClickX = LOWORD(lParam);
		ClickY = HIWORD(lParam);

		ClickType = OUTSIDE;
		// 클릭한 위치가 보드 안쪽이고 돌을 누를 차례일 경우
		if (ClickX >= BoardLeft && ClickX <= BoardRight &&  ClickY >= BoardTop  && ClickY <= BoardBottom 
					&& ButtonState == OFF) {

			ClickType = BOARD;

			// 클릭한 곳에 해당하는 행과 열 구하기
			j = ( ClickX - BoardLeft ) / 50;
			i = ( ClickY - BoardTop  ) / 50;
			// 돌 놓기
			if (Board[i][j] != NONE) break;
			Board[i][j] = Turn;
			StoneCnt++;
			//Turn = !Turn;

			ButtonState = ON;
			// 놓여진 돌을 적용하여 그림 다시 그리기
			CenterX = BoardLeft + ( j * 50 + 25 );
			CenterY = BoardTop  + ( i * 50 + 25 );

			SetRect (&rect, CenterX-25, CenterY+25, CenterX+25, CenterY-25);
			InvalidateRect (hWnd, &rect, TRUE);
			SendMessage (hWnd, WM_PAINT, NULL, NULL);
		
			// 5개 이상의 돌이 나란히 놓였는지 확인
			if ( FiveCheck (i,j) ) {
				EndMsg = 1;
				SavedTurn = Turn;
		//		MessageBox (hWnd, "The End", "The End", MB_OK);
			}
		}
		else {
			for (i=0; i<8; i++) {
				// 클릭한 위치가 버튼에 해당하며 버튼을 누를 차례일 경우
				if ( ClickX >= ButtonRect[i].left && ClickX <= ButtonRect[i].right && ClickY >= ButtonRect[i].top && ClickY <= ButtonRect[i].bottom
							&& ButtonState == ON) {
					
					//ClickType = BUTTON;

					PushedButton = i;
/*
					SetRect (&rect, 0, 0, BoardRight, BoardBottom);
					InvalidateRect (hWnd, &rect, TRUE);
					SendMessage (hWnd, WM_PAINT, NULL, NULL);
*/
	
					//ButtonState = OFF;
					ButtonState = ROTATING;
					
					break;
				}
			}
		}

		SetRect (&rect, BoardLeft, BoardTop, BoardRight, BoardBottom);
		InvalidateRect (hWnd, &rect, TRUE);
		SendMessage (hWnd, WM_PAINT, NULL, NULL);

		break;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);

		BitBlt(hdcBackBuffer, 0, 0, cxClient, cyClient, NULL, NULL, NULL, WHITENESS);

		// TODO: 여기에 그리기 코드를 추가합니다.

		if(PushedButton==0 || PushedButton==1)
		{
			RotatingSmallBoard = 0;
		}
		else if(PushedButton==2 || PushedButton==3)
		{
			RotatingSmallBoard = 1;
		}
		else if(PushedButton==4 || PushedButton==5)
		{
			RotatingSmallBoard = 2;
		}
		else if(PushedButton==6 || PushedButton==7)
		{
			RotatingSmallBoard = 3;
		}

		for(i=0; i<=3; i++)
		{
			if(i == RotatingSmallBoard)
			{
				continue;
			}
			DrawSmallBoard(hdcBackBuffer, i);
		}
		DrawSmallBoard(hdcBackBuffer, RotatingSmallBoard);
		

		// 8개의 사각형을 출력한다
		SelectObject ( hdcBackBuffer, GetStockObject (LTGRAY_BRUSH) );
		for (i=0; i<9; i++) {
			Rectangle (hdcBackBuffer, ButtonRect[i].left, ButtonRect[i].top, ButtonRect[i].right, ButtonRect[i].bottom);
		}

		switch (ClickType) 
		{
		case OUTSIDE:
			TextOut (hdcBackBuffer, 0, 0, "OUTSIDE", 7);
			break;
		case BOARD:
			TextOut (hdcBackBuffer, 0, 0, "BOARD", 5);
			break;
		case BUTTON:
			TextOut (hdcBackBuffer, 0, 0, "BUTTON", 6);
			break;
		}

		BitBlt(ps.hdc, 0, 0, cxClient, cyClient, hdcBackBuffer, 0, 0, SRCCOPY);

		EndPaint(hWnd, &ps);

		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}
	return(DefWindowProc(hWnd, iMessage, wParam, lParam));
}