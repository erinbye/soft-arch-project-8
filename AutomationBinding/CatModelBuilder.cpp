#include "CatModelBuilder.h"

void AutomationAPI::CatModelBuilder::buildCatModel(CatModel* catModel) {};

void AutomationAPI::CatModelBuilder::SetType(CatModelBuilderTypes type)
{
}

AutomationAPI::CatModelBuilder::CatModelBuilderTypes AutomationAPI::CatModelBuilder::GetType()
{
	return CatModelBuilder::NakedCat;
}

void AutomationAPI::CatModelBuilder::SetName(string s) {};
void AutomationAPI::CatModelBuilder::SetColor(string s) {};
void AutomationAPI::CatModelBuilder::SetFurPattern(string s) {};