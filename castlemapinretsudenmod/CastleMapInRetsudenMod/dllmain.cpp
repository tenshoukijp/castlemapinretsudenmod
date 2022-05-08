#include <windows.h>
#include "CastleMapInRetsudenMod.h"


void WINAPI OnInitialize(HANDLE hCallDLLHandle) {
	int result = CopyFile("hexmap.nb6", "CastleMapInRetsudenMod.nb6", FALSE);
	CastleMapInRetsudenModForm::Initialize();
}

int WINAPI OnBeginPaint(int iCastleID, char *szCastleName, int x, int y, int iCastleRank) {
	CastleMapInRetsudenModForm::OnBeginPaint(iCastleID, gcnew String(szCastleName), x, y, iCastleRank);
	return 1;
}

int WINAPI OnUpdatePaint(int x, int y) {
	CastleMapInRetsudenModForm::OnUpdatePaint(x, y);
	return 1;
}

int WINAPI OnEndPaint() {
	CastleMapInRetsudenModForm::OnEndPaint();
	return 1;
}


void WINAPI OnFinalize() {
	int result = DeleteFile("CastleMapInRetsudenMod.nb6");
}
