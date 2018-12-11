#ifndef SHOOTERUI_H
#define SHOOTER_UI
#include <SDL.h>
#include "UserInterface.h"
#include "MMath.h"
#include "Matrix.h"

using namespace MATH;

class shooterUI: public UserInterface
{
private:
	SDL_Window * window;
	SDL_Surface* HUDImage;
	Matrix4 projectionMatrix;

public:
	shooterUI(SDL_Window* sdlWindow);
	~shooterUI();
	bool OnCreate();
	void OnDestroy();
	void Update();
	void Render();
};
#endif
