#include "SampleBase.hpp"

SampleBase::SampleBase(struct sample_info &info_)
{
	info = info_;
}

SampleBase::~SampleBase()
{

}

void SampleBase::Init()
{
	
}

void SampleBase::Render()
{

}

void SampleBase::RenderLoop()
{
#if defined(_WIN32)
	MSG msg;
	while (true)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT)
				break;

			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}
#elif defined(VK_USE_PLATFORM_ANDROID_KHR)
#elif defined(_DIRECT2DISPLAY)
#elif defined(VK_USE_PLATFORM_WAYLAND_KHR)
#elif defined(VK_USE_PLATFORM_XCB_KHR)
#endif

	// Flush device to make sure all resources can be freed
	if (info.device != VK_NULL_HANDLE) {
		vkDeviceWaitIdle(info.device);
	}
}

void SampleBase::Destroy()
{

}