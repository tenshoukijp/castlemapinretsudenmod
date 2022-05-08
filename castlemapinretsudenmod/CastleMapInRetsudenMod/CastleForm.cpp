#include "CastleMapInRetsudenImplement.h"

void CastleMapInRetsudenViewerImplement::SetFormAtrr()
{

	// フォームのサイズ
	this->Width = 480;
	this->Height = 320;
	// this.FormBorderStyle = FormBorderStyle.FixedSingle;
	this->AutoScroll = true;
}

CastleMapInRetsudenViewerImplement::CastleMapInRetsudenViewerImplement()
{

	if (!System::IO::File::Exists("CastleMapInRetsudenMod.nb6"))
	{
	}
	if (!System::IO::File::Exists("CastleMapInRetsudenMod.dll"))
	{
	}

	// SetCastleImgTmpFileName();

	// フォームサイズ
	SetFormAtrr();

	// コンボボックス系処理
	SetAddComboBox();

	// イメージの登録(キャッシュ的な)
	RegistImages();

	// イメージインスタンスを確保。
	RegistPictureBoxes();

	// ヘックスマップの読み込み
	LoadHexMap();

	RePaintAllTips();
}

Image ^CastleMapInRetsudenViewerImplement::OnBeginPaint(int iCastleID, String ^strCastleName, int iCastleRank)
{
	// 大居城であり、
	if (iCastleRank == 2)
	{

		// 大坂城もしくは、安土城であれば、
		const int kCastleOosaka = 167;
		const int kCastleAzuchi = 136;
		if (iCastleID == kCastleOosaka || iCastleID == kCastleAzuchi)
		{

			// 城マップとしては214番目である。
			iCastleID = 214;
		}
	}

	CastleListComboBox->SelectedIndex = iCastleID;
	// 全て一端描画
	RePaintAllTips();
	return resultPicture;
}

Image ^CastleMapInRetsudenViewerImplement::OnUpdatePaint()
{
	return resultPicture;
}

Image ^CastleMapInRetsudenViewerImplement::OnEndPaint()
{
	try
	{
		// 用がなくなるので削除を試みる
		// System::IO::File::Delete(GetCastleImgTmpFileName());
	}
	catch (Exception ^e1)
	{
	}
	return resultPicture;
}