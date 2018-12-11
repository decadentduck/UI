#ifndef UIMANAGER_H
#define UIMANAGER_H
#include "UserInterface.h"
#include <SDL.h>

class UIManager
{
private:
	UserInterface *currentUI;
	SDL_Window *window;
public:
	UIManager(SDL_Window *window_);
	~UIManager();
	void DrawUI();
	void SwitchUI(int ui_);
};

#endif