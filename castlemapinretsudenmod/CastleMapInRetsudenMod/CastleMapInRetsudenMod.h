// CastleMapInRetsudenMod.h

#pragma once
#include "CastleMapInRetsudenImplement.h"

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;
using namespace System::IO;


ref class CastleMapInRetsudenModForm : Form
{
	static CastleMapInRetsudenViewerImplement^ form;
	static Bitmap^ bmp;
	static Image^ img;
	static Image^ imgDialogBackground;
	static Image^ imgDialogForeground;
	static Graphics^ g;
public:

	static void Initialize();
	static void OnBeginPaint(int iCastleID, String^ strCastleName, int x, int y, int iCastleRank);
	static void OnUpdatePaint(int x, int y);
	static void OnEndPaint();
	static void Finish();

};
