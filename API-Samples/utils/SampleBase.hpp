#include <chrono>
#include "util_init.hpp"
#include "camera.hpp"
class SampleBase
{
public:
	SampleBase(struct sample_info &info_) { info = info_;};
	~SampleBase() {};

	sample_info info;
	
	virtual void init() {};
	virtual void render() {};
	virtual void destroy() {};

	// Called when view change occurs
	// Can be overriden in derived class to e.g. update uniform buffers 
	// Containing view dependant matrices
	virtual void viewChanged() {};

	// Start the main render loop
	void renderLoop();

	// Render one frame of a render loop on platforms that sync rendering
	void renderFrame();

#if defined(_WIN32)
	void handleMessages(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
#endif 

	Camera camera;
	glm::vec3 rotation = glm::vec3();
	glm::vec3 cameraPos = glm::vec3();

	glm::vec2 mousePos;
	struct {
		bool left = false;
		bool right = false;
		bool middle = false;
	} mouseButtons;

	// Use to adjust mouse rotation speed
	float rotationSpeed = 1.0f;
	// Use to adjust mouse zoom speed
	float zoomSpeed = 1.0f;
	float zoom = 0;

	void handleMouseMove(int32_t x, int32_t y);

	/** brief Indicates that the view (position, rotation) has changed and buffers containing camera matrices need to be updated */
	bool viewUpdated = false;

	/** @brief Last frame time measured using a high performance timer (if available) */
	float frameTimer = 1.0f;

private:

};