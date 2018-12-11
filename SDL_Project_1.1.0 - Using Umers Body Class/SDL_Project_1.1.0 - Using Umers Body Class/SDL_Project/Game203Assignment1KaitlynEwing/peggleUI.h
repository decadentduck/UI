#ifndef PEGGLEUI_H
#define PEGGLEUI_H
#include <SDL.h>
#include "UserInterface.h"
#include "MMath.h"
#include "Matrix.h"

using namespace MATH;

class peggleUI : public UserInterface
{
private:
	SDL_Window *window;
	float balls;
	SDL_Surface* ballImage;
	Matrix4 projectionMatrix;
public:
	peggleUI(SDL_Window* sdlWindow);
	~peggleUI();
	bool OnCreate();
	void OnDestroy();
	void Update();
	void Render();
};
#endif // !PEGGLEUI_H
