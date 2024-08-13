#include "MyGUI_BgfxDataManager.h"
#include "MyGUI_BgfxDiagnostic.h"
#include "MyGUI_DataFileStream.h"

namespace MyGUI
{

	BgfxDataManager::BgfxDataManager()
	{
	}

	void BgfxDataManager::initialise()
	{
		MYGUI_PLATFORM_LOG(Info, "* Initialise: " << getClassTypeName());

		MYGUI_PLATFORM_LOG(Info, getClassTypeName() << " successfully initialized");
	}

	void BgfxDataManager::shutdown()
	{
		MYGUI_PLATFORM_LOG(Info, "* Shutdown: " << getClassTypeName());

		MYGUI_PLATFORM_LOG(Info, getClassTypeName() << " successfully shutdown");
	}

	IDataStream* BgfxDataManager::getData(const std::string& _name) const
	{
		return nullptr;
	}

	void BgfxDataManager::freeData(IDataStream* _data)
	{
		delete _data;
	}

	bool BgfxDataManager::isDataExist(const std::string& _name) const
	{
		return false;
	}

	const VectorString& BgfxDataManager::getDataListNames(const std::string& _pattern) const
	{
		static VectorString result;
		return result;
	}

	std::string BgfxDataManager::getDataPath(const std::string& _name) const
	{
		return {};
	}

} // namespace MyGUI
