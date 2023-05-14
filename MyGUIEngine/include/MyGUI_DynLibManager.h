/*
 * This source file is part of MyGUI. For the latest info, see http://mygui.info/
 * Distributed under the MIT License
 * (See accompanying file COPYING.MIT or copy at http://opensource.org/licenses/MIT)
 */

#ifndef MYGUI_DYN_LIB_MANAGER_H_
#define MYGUI_DYN_LIB_MANAGER_H_

#include "MyGUI_Prerequest.h"
#include "MyGUI_Singleton.h"
#include "MyGUI_DynLib.h"
#include <map>

namespace MyGUI
{

	/*!	\brief Manager of dynamic libraries
	*/
	class MYGUI_EXPORT DynLibManager
	{
		MYGUI_SINGLETON_DECLARATION(DynLibManager);
	public:
		DynLibManager();

		void initialise();
		void shutdown();

		//!	Load library
		DynLib* load(std::string_view fileName);
		//!	Unload library
		void unload(DynLib* library);

		void unloadAll();

		/*internal:*/
		void _unloadDelayDynLibs();

	private:
		void notifyEventFrameStart(float _time);

	private:
		//! Dynamic libraries map
		using StringDynLibMap = std::map<std::string, DynLib*, std::less<>>;
		//!	Loaded libraries
		StringDynLibMap mLibsMap;

		bool mIsInitialise;

		using VectorDynLib = std::vector<DynLib*>;
		VectorDynLib mDelayDynLib;
	};

} // namespace MyGUI

#endif // MYGUI_DYN_LIB_MANAGER_H_
