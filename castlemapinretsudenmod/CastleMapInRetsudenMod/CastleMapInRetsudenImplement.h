#pragma once

#include "LS11DotNet.h"

using namespace System;
using namespace System::Collections;
using namespace System::Drawing;


public ref class CastleMapInRetsudenViewerImplement : System::Windows::Forms::Form
{

	// ----------------------- CastleForm ------------------------------
private:
	void SetFormAtrr();

public:
	CastleMapInRetsudenViewerImplement();

	Image ^OnBeginPaint(int iCastleID, String ^strCastleName, int iCastleRank);

	Image ^OnUpdatePaint();

	Image ^OnEndPaint();
	// ----------------------- CastleForm ------------------------------


	// ----------------------- CastleHexDataLoad -----------------------
private:
	ArrayList ^csAllHexMapArray; // hexmap.nb6のデータ(の解凍したもの)の全て


	// hexmap.nb6の読み込み
	void LoadHexMap();
	// ----------------------- CastleHexDataLoad -----------------------


	// ----------------------- CastleComboBox -----------------------
private:
	System::Windows::Forms::ComboBox ^CastleListComboBox; // コンボボックス


	void AddCastleList();

	void SetAddComboBox();

	int GetSelectedHexMapID();

	int GetSelectedRoleMapID();

	int GetSelectedHighMapID();

	// 選択項目が変更されたときのイベントハンドラ
	void CastleListComboBox_SelectedIndexChanged(Object ^sender, EventArgs ^e);
	// ----------------------- CastleComboBox -----------------------



	// ----------------------- CastleHexPictureBox -----------------------
private:
	
	cli::array<Image^> ^basePictureImg;
	cli::array<Image^> ^wallPictureImg;
	cli::array<Image^> ^ridePictureImg;

	Image ^resultPicture;

	literal int iColMax = 18;
	literal int iRowMax = 16;

	literal int iTipImageSize = 16;

	literal int iLeftStandingPos = 12;
	literal int iTopStandingPos = 24;

	literal int iCastleNum = 214;

	literal int iHexmapCastleStartID = 952;

	// ピクチャーボックスの配置。
	// 下地・城壁・さらに上に乗るものの３層
	void RegistPictureBoxes();

	Point GetPicturePos(int col, int row);

	void RePaintBaseTips();
	void RePaintWallTips();
	void RePaintRideTips();
	void RePaintResultTips();

	String^ GetHDImagesPath();

	void RePaintAllTips();
	// ----------------------- CastleHexPictureBox -----------------------


	// ----------------------- CastleTipImageCache -----------------------
private:
	System::Resources::ResourceManager^ rm;

	Image ^imgDialogBackground;

	cli::array<Image^> ^baseImages;
	cli::array<Image^> ^wallImages;
	cli::array<Image^> ^rideImages;

	void RegistImages();
	// ----------------------- CastleTipImageCache -----------------------

};