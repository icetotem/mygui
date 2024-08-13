#ifndef MYGUI_BGFX_PLATFORM_H_
#define MYGUI_BGFX_PLATFORM_H_

#include "MyGUI_Prerequest.h"
#include "MyGUI_BgfxRenderManager.h"
#include "MyGUI_BgfxDataManager.h"
#include "MyGUI_BgfxDiagnostic.h"
#include "MyGUI_LogManager.h"

namespace MyGUI
{

	class BgfxPlatform
	{
	public:
		BgfxPlatform() :
			mLogManager(nullptr),
			mRenderManager(nullptr),
			mDataManager(nullptr)
		{
			mLogManager = new LogManager();
			mRenderManager = new BgfxRenderManager();
			mDataManager = new BgfxDataManager();
		}

		~BgfxPlatform()
		{
			delete mRenderManager;
			mRenderManager = nullptr;
			delete mDataManager;
			mDataManager = nullptr;
			delete mLogManager;
			mLogManager = nullptr;
		}

		void initialise(std::string_view _logName = MYGUI_PLATFORM_LOG_FILENAME)
		{
			if (!_logName.empty())
				LogManager::getInstance().createDefaultSource(_logName);

			mRenderManager->initialise();
			mDataManager->initialise();
		}

		void shutdown()
		{
			mRenderManager->shutdown();
			mDataManager->shutdown();
		}

		BgfxRenderManager* getRenderManagerPtr()
		{
			return mRenderManager;
		}

		BgfxDataManager* getDataManagerPtr()
		{
			return mDataManager;
		}

	private:
		BgfxRenderManager* mRenderManager;
		BgfxDataManager* mDataManager;
		LogManager* mLogManager;
	};

} // namespace MyGUI

#endif // MYGUI_BGFX_PLATFORM_H_
