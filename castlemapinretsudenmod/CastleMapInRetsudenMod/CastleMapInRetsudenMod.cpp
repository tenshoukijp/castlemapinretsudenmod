#include <windows.h>
#include "CastleMapInRetsudenMod.h"

#pragma comment(lib, "user32.lib")
#pragma comment(lib, "gdi32.lib")

HWND hWnd = NULL;
HDC hDCTenshou95 = NULL;

HDC hDC = NULL;
HBITMAP hBitmap = NULL;
HGDIOBJ hOldBitmap = NULL;

void CastleMapInRetsudenModForm::Initialize() {
	// このプロジェクトのアセンブリのタイプを取得。
	System::Reflection::Assembly^ prj_assebmly = System::Reflection::Assembly::GetExecutingAssembly();;
	System::Resources::ResourceManager^ r = gcnew System::Resources::ResourceManager(String::Format("{0}.ResourceRes", prj_assebmly->GetName()->Name), prj_assebmly);

	// パネルの背景
	imgDialogBackground = (Image^)(r->GetObject("DialogBackgroundImage"));
	imgDialogForeground = (Image^)(r->GetObject("DialogBackgroundImage"));

	form = gcnew CastleMapInRetsudenViewerImplement();

}

void CastleMapInRetsudenModForm::OnBeginPaint(int iCastleID, String^ strCastleName, int x, int y, int iCastleRank) {

	hWnd = FindWindow("Tenshouki95", NULL);
	hDCTenshou95 = GetDC(hWnd);
	hDC = CreateCompatibleDC(hDCTenshou95);
	hBitmap = CreateCompatibleBitmap(hDCTenshou95, 320, 304);

	//	hOldBitmap = SelectObject(hDC, hBitmap);
	//	BitBlt(hDC, 0, 0, 100, 100, hDCTenshou95, 0, 0, SRCCOPY);
	//  SelectObject(hDC, hOldBitmap);

	bmp = Bitmap::FromHbitmap((IntPtr)hBitmap);
	img = Image::FromHbitmap((IntPtr)hBitmap);
	g = Graphics::FromHwnd((IntPtr)hWnd);

	// 99盤目の城のやつもらう
	imgDialogForeground = form->OnBeginPaint(iCastleID, strCastleName, iCastleRank);

	/*
	IO::FileStream ^fs = gcnew IO::FileStream(filename, IO::FileMode::Open, IO::FileAccess::Read);
	imgDialogForeground = Image::FromStream(fs);
	fs->Close();
	*/

	// Draw rectangle to screen.
	// g->DrawRectangle(gcnew Pen(Color::Blue, 3), x, y+152, 320, 304);
	// g->DrawImage(imgDialogBackground, x, y + 148, 320, 304);
	g->DrawImage(imgDialogForeground, x, y + 148, 320, 304);

}

void CastleMapInRetsudenModForm::OnUpdatePaint(int x, int y) {
	g->DrawImage(imgDialogForeground, x, y + 148, 320, 304);
}

void CastleMapInRetsudenModForm::OnEndPaint() {
	form->OnEndPaint();
	DeleteDC(hDC);
	DeleteObject(hBitmap);
}

void CastleMapInRetsudenModForm::Finish() {
	form = nullptr;
}
