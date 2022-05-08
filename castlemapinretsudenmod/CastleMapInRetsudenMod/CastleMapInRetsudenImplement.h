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
	ArrayList ^csAllHexMapArray; // hexmap.nb6�̃f�[�^(�̉𓀂�������)�̑S��


	// hexmap.nb6�̓ǂݍ���
	void LoadHexMap();
	// ----------------------- CastleHexDataLoad -----------------------


	// ----------------------- CastleComboBox -----------------------
private:
	System::Windows::Forms::ComboBox ^CastleListComboBox; // �R���{�{�b�N�X


	void AddCastleList();

	void SetAddComboBox();

	int GetSelectedHexMapID();

	int GetSelectedRoleMapID();

	int GetSelectedHighMapID();

	// �I�����ڂ��ύX���ꂽ�Ƃ��̃C�x���g�n���h��
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

	// �s�N�`���[�{�b�N�X�̔z�u�B
	// ���n�E��ǁE����ɏ�ɏ����̂̂R�w
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