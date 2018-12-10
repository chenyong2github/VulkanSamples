#include "util_init.hpp"
class SampleBase
{
public:
	SampleBase(struct sample_info &info_);
	~SampleBase();

	sample_info info;
	
	virtual void Init();
	virtual void Render();
	virtual void Destroy();

#ifdef _WIN32
	LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
#endif

	void RenderLoop();

private:

};