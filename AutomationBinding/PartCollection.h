#pragma once
#include "AutomationBindingExports.h"
namespace AutomationAPI
{
	class CatModelBuilder;
	class CatModel;

	class AUTOMATIONBINDING_API PartCollection
	{
	public:
		/// <summary>
		/// Sets up part collection with a specific guid
		/// </summary>
		/// <param name="guid">unique id number</param>
		PartCollection(int guid);
		/// <summary>
		/// Destroys previous set up part collection
		/// </summary>
		virtual ~PartCollection();
		/// <summary>
		/// Sets up a cat cad model builder
		/// </summary>
		/// <param name="catModel">pointer to a CatModel object</param>
		/// <returns>pointer to CatModelBuilder object</returns>
		CatModelBuilder* CreateCatModelBuilder(CatModel* catModel);

	private:
		int m_guid;
	};
}

