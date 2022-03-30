#pragma once
#include "AutomationBindingExports.h"

namespace AutomationAPI
{

	class CatModelImpl {
	public:
		/// <summary>
		/// 
		/// </summary>
		virtual ~CatModelImpl();
		/// <summary>
		/// 
		/// </summary>
		CatModelImpl() = delete;
		/// <summary>
		/// 
		/// </summary>
		/// <param name="guid"></param>
		CatModelImpl(int guid);
		int m_guid;
	};

	class AUTOMATIONBINDING_API CatModel
	{
	public:
		/// <summary>
		/// Sets up cat cad model with a specific guid
		/// </summary>
		/// <param name="guid">unique id number</param>
		/// <returns>pointer to a CatModel object</returns>
		static CatModel* CreateCatModel(int guid);
		/// <summary>
		/// Destroys previous set up cat model
		/// </summary>
		virtual ~CatModel();
		CatModel() = delete;
	private:
		/// <summary>
		/// Private. Sets up CatModel object used in public functions
		/// </summary>
		/// <param name="guid">unique id number</param>
		CatModel(int guid);
		CatModelImpl* m_catImpl;
	};

}

