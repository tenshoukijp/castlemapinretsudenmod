#include "CastleMapInRetsudenImplement.h"

void CastleMapInRetsudenViewerImplement::RegistPictureBoxes()
{
	// ���n
	this->basePictureImg = gcnew cli::array<Image^>(iColMax * iRowMax);

	// ���
	this->wallPictureImg = gcnew cli::array<Image^>(iColMax * iRowMax);

	// �{�ہE�ȗցE�΂� ��
	this->ridePictureImg = gcnew cli::array<Image^>(iColMax * iRowMax);

}

Point CastleMapInRetsudenViewerImplement::GetPicturePos(int col, int row)
{
	if (row % 2 == 0)
	{
		return Point(iLeftStandingPos + col * iTipImageSize, iTopStandingPos + row * iTipImageSize);
	}
	else
	{
		return Point(iLeftStandingPos + (iTipImageSize / 2) + col * iTipImageSize, iTopStandingPos + row * iTipImageSize);
	}
}

void CastleMapInRetsudenViewerImplement::RePaintBaseTips()
{

	// �R���{�{�b�N�X�őI��������́u�`�b�v���X�g�v���擾
	ArrayList ^csOneHexMapTipsList = safe_cast<ArrayList^>(csAllHexMapArray[GetSelectedHexMapID()]);

	for (int i = 0; i < iRowMax * iColMax; i++)
	{
		// �x�[�X
		Byte tip = safe_cast<Byte>(csOneHexMapTipsList[i]);
		Image ^baseImage = baseImages[tip];
		this->basePictureImg[i] = baseImage;
	}

}

void CastleMapInRetsudenViewerImplement::RePaintWallTips()
{

	// �R���{�{�b�N�X�őI��������́u�`�b�v���X�g�v���擾
	ArrayList ^csOneHexMapTipsList = safe_cast<ArrayList^>(csAllHexMapArray[GetSelectedHexMapID()]);

	for (int i = 0; i < iRowMax * iColMax; i++)
	{

		// �E�H�[��
		Byte tip = safe_cast<Byte>(csOneHexMapTipsList[i + (iColMax * iRowMax) * 1]);
		Image ^wallImage = wallImages[tip];
		this->wallPictureImg[i] = wallImage;
	}
}

void CastleMapInRetsudenViewerImplement::RePaintRideTips()
{

	// �R���{�{�b�N�X�őI��������́u�`�b�v���X�g�v���擾
	ArrayList ^csOneHexMapTipsList = safe_cast<ArrayList^>(csAllHexMapArray[GetSelectedHexMapID()]);

	for (int i = 0; i < iRowMax * iColMax; i++)
	{

		// ���C�h
		Byte tip = safe_cast<Byte>(csOneHexMapTipsList[i + (iColMax * iRowMax) * 2]);
		Image ^rideImage = rideImages[tip];
		this->ridePictureImg[i] = rideImage;
	}
}

void CastleMapInRetsudenViewerImplement::RePaintResultTips()
{
	Bitmap ^result = gcnew Bitmap(imgDialogBackground, 320, 304);

	// �x�[�X�ƂȂ�C���[�W
	Graphics ^g = Graphics::FromImage(result);

	String^ HDImagePath = GetHDImagesPath();
	if (HDImagePath != nullptr) {
		try {
			if (rm == nullptr) {
				System::Reflection::Assembly^ prj_assebmly = System::Reflection::Assembly::GetExecutingAssembly();
				rm = gcnew System::Resources::ResourceManager(String::Format("{0}.ResourceRes", prj_assebmly->GetName()->Name), prj_assebmly);
			}
			Image^ castleImg = Image::FromFile(HDImagePath);
			g->DrawImage(castleImg, (320 - 256) / 2, (304 - 256) / 2, 256, 256);
			delete  castleImg;
		}
		catch (Exception^ e) {

		}
	}

	// �m�[�}���łł̏���
	if (HDImagePath == nullptr) {
		int i = 0;
		for (int row = 0; row < iRowMax; row++)
		{
			for (int col = 0; col < iColMax; col++)
			{

				Point pos = GetPicturePos(col, row);
				//------------- �d�˕\��
				// �y�n�d��
				g->DrawImage(this->basePictureImg[i], pos.X, pos.Y, iTipImageSize, iTipImageSize);

				if (safe_cast<int>(this->wallPictureImg[i]->Tag) != 0xFF)
				{ // �����ł͂Ȃ�
					// �Ǐd��
					g->DrawImage(this->wallPictureImg[i], pos.X, pos.Y, iTipImageSize, iTipImageSize);
				}
				if (safe_cast<int>(this->ridePictureImg[i]->Tag) != 0xFF)
				{ // �����ł͂Ȃ�
					// ���d��
					g->DrawImage(this->ridePictureImg[i], pos.X, pos.Y, iTipImageSize, iTipImageSize);
				}

				i++;
			}
		}
	}

	// �g�c�摜�Ƃ̃u�����h�łł̏���
	if (HDImagePath != nullptr) {
		int i = 0;
		for (int row = 0; row < iRowMax; row++)
		{
			for (int col = 0; col < iColMax; col++)
			{

				Point pos = GetPicturePos(col, row);
				/*
				//------------- �d�˕\��
				// �y�n�d��
				g->DrawImage(this->basePictureImg[i], pos.X + 4, pos.Y, iTipImageSize, iTipImageSize);

				if (safe_cast<int>(this->wallPictureImg[i]->Tag) != 0xFF)
				{ // �����ł͂Ȃ�
					// �Ǐd��
					g->DrawImage(this->wallPictureImg[i], pos.X + 4, pos.Y, iTipImageSize, iTipImageSize);
				}
				*/
				int tag = safe_cast<int>(this->ridePictureImg[i]->Tag);
				// �����v�f�ƁA�X���J�b�g
				if (tag != 0xFF && !(0xCC <= tag && tag <= 0xD1) /* && !(0x9E <= tag && tag <= 0x9F) && !(0xD2 <= tag && tag <= 0xD6) && !(0xA8 <= tag && tag <= 0xC5) && tag != 0xA0 && tag != 0xA2 && tag != 0xA4 && tag != 0xA5 && tag != 0xA7*/)
				{ 
					// ���d��
					g->DrawImage(this->ridePictureImg[i], pos.X + 4, pos.Y, iTipImageSize, iTipImageSize);
				}

				i++;
			}
		}
	}

	// �d�˂��̂Ŕj��
	delete g;

	this->resultPicture = result;
}

String^ CastleMapInRetsudenViewerImplement::GetHDImagesPath()
{
	String^ dir = "CastleMapInRetsudenMod/HD";

	try {
		if (rm == nullptr) {
			System::Reflection::Assembly^ prj_assebmly = System::Reflection::Assembly::GetExecutingAssembly();
			rm = gcnew System::Resources::ResourceManager(String::Format("{0}.ResourceRes", prj_assebmly->GetName()->Name), prj_assebmly);
		}
		String^ target_file = String::Format(dir + "/c_{0:000}.png", CastleListComboBox->SelectedIndex);

		if (System::IO::File::Exists(target_file)) {
			return target_file;
		}
	}
	catch (Exception^ e) {

	}

	return nullptr;
}

void CastleMapInRetsudenViewerImplement::RePaintAllTips()
{
	RePaintBaseTips();
	RePaintWallTips();
	RePaintRideTips();
	RePaintResultTips();

}
