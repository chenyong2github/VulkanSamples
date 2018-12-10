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

	void RenderLoop();

private:

};