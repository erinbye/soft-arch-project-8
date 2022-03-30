#pragma once
#include "AutomationBindingExports.h"
#include "IBuilder.h"
#include <string>
#include "CatModel.h"
using namespace std;

namespace AutomationAPI
{

	class AUTOMATIONBINDING_API CatModelBuilder : public IBuilder
	{
		enum CatModelBuilderTypes
		{
			NakedCat,
			FurryCat,
		};
		/// <summary>
		/// Assigns the type of cat model
		/// </summary>
		/// <param name="type">enum value of NakedCat or FurryCat</param>
		void SetType(CatModelBuilderTypes type);
		/// <summary>
		/// Retrieves the type of cat model for the set cat model
		/// </summary>
		/// <returns>enum value of NakedCat or FurryCat</returns>
		CatModelBuilderTypes GetType();

		/// <summary>
		/// Constructs the cat cad model according to the design pattern builder
		/// </summary>
		/// <param name="cat">pointer to CatModel object</param>
		void buildCatModel(CatModel* cat);
		/// <summary>
		/// Assigns the name of the cat model
		/// </summary>
		/// <param name="s">name of cat</param>
		void SetName(string s);
		/// <summary>
		/// Assigns the color of the fur of the cat model
		/// </summary>
		/// <param name="s">color of cat fur</param>
		void SetColor(string s);
		/// <summary>
		/// Assigns the pattern of the fur of the cat model
		/// </summary>
		/// <param name="s">pattern of cat fur</param>
		void SetFurPattern(string s);
	};

}

