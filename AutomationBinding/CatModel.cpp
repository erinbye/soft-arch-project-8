#include "CatModel.h"

AutomationAPI::CatModelImpl::~CatModelImpl(){};

AutomationAPI::CatModelImpl::CatModelImpl(int guid)
{
	m_guid = guid;
}

AutomationAPI::CatModel* AutomationAPI::CatModel::CreateCatModel(int guid)
{
	return new CatModel(guid);
}

AutomationAPI::CatModel::~CatModel()
{
	delete m_catImpl;
}
