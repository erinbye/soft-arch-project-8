
#pragma once
#include "AppPartOpsExports.h"
#include <string>
#include "..\Core\GuidObject.h"



class APPPARTOPS_API CatModelFile : public GuidObject
{
public:
	/// <summary>
	/// Initializes a cat model file to begin the journaling process
	/// </summary>
	/// <param name="catModelFilePath">path to the file created by function</param>
	/// <returns>pointer to cat model file object</returns>
	static CatModelFile* CreateCatModelFile(std::string catModelFilePath);
	/// <summary>
	/// Opens a previously created cat model file to continue journaling
	/// </summary>
	/// <param name="catModelFilePath">path to the file previously created</param>
	/// <returns>pointer to cat model file object</returns>
	static CatModelFile* OpenCatModelFile(std::string catModelFilePath);
	/// <summary>
	/// Assigns the name to cat model file and journals it
	/// </summary>
	/// <param name="s">name of cat</param>
	void SetName(std::string s);
	/// <summary>
	/// Assigns the color of fur to cat model file and journals it
	/// </summary>
	/// <param name="s">color of cat fur</param>
	void SetColor(std::string s);
	/// <summary>
	/// Assigns the pattern of fur to cat model file and journals it
	/// </summary>
	/// <param name="s">pattern of cat fur</param>
	void SetFurPattern(std::string s);

private:
	/// <summary>
	/// Private. Sets up CatModelFile object used in public functions
	/// </summary>
	/// <param name="catModelFilePath">path to the file created by function</param>
	/// <param name="guid">unique id number</param>
	CatModelFile(std::string catModelFilePath, int guid);
	std::string m_partFilePath;
};

/// <summary>
/// Creates a naked cat model and journals it to cat model file
/// </summary>
/// <param name="">catModelFilePath</param>
/// <returns>pointer to cat model file object</returns>
extern APPPARTOPS_API CatModelFile* Journaling_NakedCat(std::string);

/// <summary>
/// Creates a furry cat model and journals it to cat model file
/// </summary>
/// <param name="">catModelFilePath</param>
/// <returns>pointer to cat model file object</returns>
extern APPPARTOPS_API CatModelFile* Journaling_FurryCat(std::string);

/// <summary>
/// Assigns name to cat model, journals it, and saves to cat model file
/// </summary>
/// <param name="catModelFile">path to the file previously created</param>
/// <param name="">name of cat</param>
extern APPPARTOPS_API void Journaling_CatModel_SetName(CatModelFile* catModelFile, std::string);

/// <summary>
/// Assigns color to cat model, journals it, and saves to cat model file
/// </summary>
/// <param name="catModelFile">path to the file previously created</param>
/// <param name="">color of cat</param>
extern APPPARTOPS_API void Journaling_CatModel_SetColor(CatModelFile* catModelFile, std::string);

/// <summary>
/// Assigns fur pattern to cat model, journals it, and saves to cat model file
/// </summary>
/// <param name="catModelFile">path to the file previously created</param>
/// <param name="">fur pattern of cat</param>
extern APPPARTOPS_API void Journaling_CatModel_SetFurPattern(CatModelFile* catModelFile, std::string);



