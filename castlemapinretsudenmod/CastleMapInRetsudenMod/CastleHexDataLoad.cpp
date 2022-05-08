#include "CastleMapInRetsudenImplement.h"

void CastleMapInRetsudenViewerImplement::LoadHexMap()
{
	csAllHexMapArray = gcnew ArrayList();
	int result = LS11DotNet::Ls11::DecodePack("CastleMapInRetsudenMod.nb6", csAllHexMapArray);

	if (result != 0)
	{
	}
}