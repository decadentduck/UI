#include "UIManager.h"
#include "peggleUI.h"
#include "shooterUI.h"

UIManager::UIManager(SDL_Window *window_)
{
	//currentUI = std::unique_ptr<UserInterface>(new UserInterface()); unique pointers dont work here
	currentUI = nullptr;
	window = window_;
}

UIManager::~UIManager()
{

}

void UIManager::DrawUI()
{
	if (currentUI == nullptr) //if there  is no ui active then create one
	{
		SwitchUI(1);
	}
	currentUI->Update();
	currentUI->Render();
}

void UIManager::SwitchUI(int ui_)
{
	if (currentUI != nullptr)//if scene is not already null
	{
		currentUI->OnDestroy(); //delete current scene
		delete currentUI;
		currentUI = nullptr;
	}
	switch (ui_)
	{
	case 0:
		currentUI = new peggleUI(window); //make new ui
		break;
	case 1:
		currentUI = new shooterUI(window);
		break;
	default://default option
		currentUI = new shooterUI(window);
		break;
	}
	currentUI->OnCreate(); //build scene
}
