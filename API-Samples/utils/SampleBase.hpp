#include "util_init.hpp"
#include "camera.hpp"
class SampleBase
{
public:
	SampleBase(struct sample_info &info) { this->info = info;};
	~SampleBase() {};

	sample_info info;
	
	virtual void init() {};
	virtual void update(float deltaTime) {};
	virtual void render() {};
	virtual void destroy() {};

	// Start the main render loop
	void renderLoop();

	// Render one frame of a render loop on platforms that sync rendering
	void renderFrame();

#if defined(_WIN32)
	void handleMessages(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
#endif 

	Camera camera;

	glm::vec2 mousePos;
	struct {
		bool left = false;
		bool right = false;
		bool middle = false;
	} mouseButtons;

	void handleMouseMove(int32_t x, int32_t y);

private:

};