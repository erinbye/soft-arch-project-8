#include "CatModelJournaling.h"
#include <iostream>
#include "..\Journaling\Journaling.h"
#include "..\Journaling\JournalHelpers.h"
#include "..\Core\GuidObject.h"
#include "..\AppLibrary\Feature.h"
#include "..\Core\StringUtils.h"
#include "..\Core\CoreSession.h"
#include "..\Core\Observer.h"

using namespace std;

CatModelFile* CatModelFile::CreateCatModelFile(std::string catModelFilePath)
{
	int guid = 123424;

	CatModelFile* catModelFile = new CatModelFile(catModelFilePath, guid);
	GuidObjectManager::GetGuidObjectManager().SetObjectFromGUID(guid, catModelFile);
	CoreSession::GetInstance().CreateMessage("CreateCatModel");
	return catModelFile;
}

CatModelFile* CatModelFile::OpenCatModelFile(std::string catModelFilePath)
{
	int guid = -1;

	ReadInCatModelFile(guid, catModelFilePath);


	CatModelFile* catModelFile = new CatModelFile(catModelFilePath, guid);
	GuidObjectManager::GetGuidObjectManager().SetObjectFromGUID(guid, catModelFile);


	CoreSession::GetInstance().CreateMessage("OpenCatModel");
	return catModelFile;
}

void CatModelFile::SetName(string s)
{
	cout << "SetName called with " << s << endl;
}

void CatModelFile::SetColor(string s)
{
	cout << "SetColor called with " << s << endl;
}

void CatModelFile::SetFurPattern(string s)
{
	cout << "SetFurPattern called with " << s << endl;
}

void Journaling_CatModel_SetName(CatModelFile* catModelFile, string name)
{

	if (IsJournaling())
	{
		JournalStartCall("SetName", catModelFile);
		JournalStringInParam(name, "name");
	}
	catModelFile->SetName(name);

	if (IsJournaling())
	{
		JournalEndCall();
	}

}

void Journaling_CatModel_SetColor(CatModelFile* catModelFile, string color)
{

	if (IsJournaling())
	{
		JournalStartCall("SetColor", catModelFile);
		JournalStringInParam(color, "color");
	}
	catModelFile->SetColor(color);

	if (IsJournaling())
	{
		JournalEndCall();
	}

}

void Journaling_CatModel_SetFurPattern(CatModelFile* catModelFile, string pattern)
{

	if (IsJournaling())
	{
		JournalStartCall("SetFurPattern", catModelFile);
		JournalStringInParam(pattern, "pattern");
	}
	catModelFile->SetFurPattern(pattern);

	if (IsJournaling())
	{
		JournalEndCall();
	}

}


std::string PartFileNameToken = "PartFileName:";
std::string SchemaVersionToken = "SchemaVersion:";

void ReadInCatModelFile(int& guid, std::string catModelFilePath)
{
	guid = 54321;
	string line;
	ifstream localPartFile(catModelFilePath);
	if (localPartFile.is_open())
	{
		while (getline(localPartFile, line))
		{
			cout << line << '\n';

			if (startsWith(line, PartFileNameToken))
			{
				std::string partFileName = line.substr(PartFileNameToken.size(), line.size() - PartFileNameToken.size());
				cout << "    " << PartFileNameToken << " " << partFileName << endl;
			}
			else if (startsWith(line, SchemaVersionToken))
			{
				std::string partFileName = line.substr(SchemaVersionToken.size(), line.size() - SchemaVersionToken.size());
				cout << "    " << SchemaVersionToken << " " << partFileName << endl;
			}
			else if (startsWith(line, FeatureToken))
			{
				std::string featureType = line.substr(FeatureToken.size(), line.size() - FeatureToken.size());
				ProcessFeature(featureType, localPartFile);
			}


		}
		localPartFile.close();
	}


}