#ifndef MYGUI_BGFX_DATA_MANAGER_H_
#define MYGUI_BGFX_DATA_MANAGER_H_

#include "MyGUI_Prerequest.h"
#include "MyGUI_DataManager.h"

namespace MyGUI
{

	class BgfxDataManager : public DataManager
	{
	public:
		BgfxDataManager();

		void initialise();
		void shutdown();

		static BgfxDataManager& getInstance()
		{
			return *getInstancePtr();
		}
		static BgfxDataManager* getInstancePtr()
		{
			return static_cast<BgfxDataManager*>(DataManager::getInstancePtr());
		}

		/** @see DataManager::getData(const std::string& _name) */
		IDataStream* getData(const std::string& _name) const override;

		/** @see DataManager::freeData */
		void freeData(IDataStream* _data) override;

		/** @see DataManager::isDataExist(const std::string& _name) */
		bool isDataExist(const std::string& _name) const override;

		/** @see DataManager::getDataListNames(const std::string& _pattern) */
		const VectorString& getDataListNames(const std::string& _pattern) const override;

		/** @see DataManager::getDataPath(const std::string& _name) */
		std::string getDataPath(const std::string& _name) const override;
	};

} // namespace MyGUI

#endif // MYGUI_BGFX_DATA_MANAGER_H_
