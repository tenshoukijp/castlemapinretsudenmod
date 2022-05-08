#include "CastleMapInRetsudenImplement.h"

void CastleMapInRetsudenViewerImplement::SetFormAtrr()
{

	// �t�H�[���̃T�C�Y
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

	// �t�H�[���T�C�Y
	SetFormAtrr();

	// �R���{�{�b�N�X�n����
	SetAddComboBox();

	// �C���[�W�̓o�^(�L���b�V���I��)
	RegistImages();

	// �C���[�W�C���X�^���X���m�ہB
	RegistPictureBoxes();

	// �w�b�N�X�}�b�v�̓ǂݍ���
	LoadHexMap();

	RePaintAllTips();
}

Image ^CastleMapInRetsudenViewerImplement::OnBeginPaint(int iCastleID, String ^strCastleName, int iCastleRank)
{
	// �勏��ł���A
	if (iCastleRank == 2)
	{

		// ����������́A���y��ł���΁A
		const int kCastleOosaka = 167;
		const int kCastleAzuchi = 136;
		if (iCastleID == kCastleOosaka || iCastleID == kCastleAzuchi)
		{

			// ��}�b�v�Ƃ��Ă�214�Ԗڂł���B
			iCastleID = 214;
		}
	}

	CastleListComboBox->SelectedIndex = iCastleID;
	// �S�Ĉ�[�`��
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
		// �p���Ȃ��Ȃ�̂ō폜�����݂�
		// System::IO::File::Delete(GetCastleImgTmpFileName());
	}
	catch (Exception ^e1)
	{
	}
	return resultPicture;
}