#include "PartCollection.h"

#include "CatModel.h"
#include "CatModelBuilder.h"
#include <iostream>

AutomationAPI::PartCollection::PartCollection(int guid) : m_guid(guid)
{

}

AutomationAPI::PartCollection::~PartCollection()
{

}

AutomationAPI::CatModelBuilder* AutomationAPI::PartCollection::CreateCatModelBuilder(AutomationAPI::CatModel* catModel)
{
	if (catModel == nullptr)
	{
		std::cout << "Cat in creation mode" << std::endl;
	}
	else
	{
		std::cout << "Cat in edit/query mode" << std::endl;
	}


	return nullptr;

}