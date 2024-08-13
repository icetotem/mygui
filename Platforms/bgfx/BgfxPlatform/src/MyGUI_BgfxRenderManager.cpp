#include "MyGUI_BgfxRenderManager.h"
#include "MyGUI_BgfxDiagnostic.h"
#include "MyGUI_Gui.h"
#include "MyGUI_Timer.h"

namespace MyGUI
{

	BgfxRenderManager::BgfxRenderManager()
	{
	}

	void BgfxRenderManager::initialise()
	{
		MYGUI_PLATFORM_LOG(Info, "* Initialise: " << getClassTypeName());

		MYGUI_PLATFORM_LOG(Info, getClassTypeName() << " successfully initialized");
	}

	void BgfxRenderManager::shutdown()
	{
		MYGUI_PLATFORM_LOG(Info, "* Shutdown: " << getClassTypeName());

		MYGUI_PLATFORM_LOG(Info, getClassTypeName() << " successfully shutdown");
	}

	IVertexBuffer* BgfxRenderManager::createVertexBuffer()
	{
		return nullptr;
	}

	void BgfxRenderManager::destroyVertexBuffer(IVertexBuffer* _buffer)
	{
	}

	void BgfxRenderManager::doRender(IVertexBuffer* _buffer, ITexture* _texture, size_t _count)
	{
	}

	void BgfxRenderManager::drawOneFrame()
	{
		Gui* gui = Gui::getInstancePtr();
		if (gui == nullptr)
			return;

		static Timer timer;
		static unsigned long last_time = timer.getMilliseconds();
		unsigned long now_time = timer.getMilliseconds();
		unsigned long time = now_time - last_time;

		onFrameEvent(time / 1000.0f);

		last_time = now_time;

		begin();
		onRenderToTarget(this, false);
		end();
	}

	void BgfxRenderManager::begin()
	{
	}

	void BgfxRenderManager::end()
	{
	}

	ITexture* BgfxRenderManager::createTexture(const std::string& _name)
	{
		return nullptr;
	}

	void BgfxRenderManager::destroyTexture(ITexture* _texture)
	{
	}

	ITexture* BgfxRenderManager::getTexture(const std::string& _name)
	{
		return nullptr;
	}

	bool BgfxRenderManager::isFormatSupported(PixelFormat _format, TextureUsage _usage)
	{
		return false;
	}

	void BgfxRenderManager::setViewSize(int _width, int _height)
	{
		mViewSize.set(_width, _height);
		onResizeView(mViewSize);
	}

} // namespace MyGUI
