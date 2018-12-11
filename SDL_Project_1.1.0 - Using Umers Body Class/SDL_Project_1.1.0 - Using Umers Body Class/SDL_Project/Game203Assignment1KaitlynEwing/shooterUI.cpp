#include "shooterUI.h"
#include "Vector.h"
#include "VMath.h"
#include <math.h>
#include <SDL_image.h>
#include "MMath.h"

shooterUI::shooterUI(SDL_Window* sdlWindow_)
{
	window = sdlWindow_;
}

shooterUI::~shooterUI()
{
}

bool shooterUI::OnCreate()
{
	//window height and width
	int w, h;
	SDL_GetWindowSize(window, &w, &h);
	//matrix to change orientation of grid (0, 0) is at bottom left
	projectionMatrix = MMath::viewportNDC(w, h) * MMath::orthographic(0.0f, 40.0f, 0.0f, 40.0f, 0.0f, 1.0f);

	//image initialize
	IMG_Init(IMG_INIT_PNG);

	char *imageName = "hud.png";
	HUDImage = IMG_Load(imageName);
	IMG_Quit();

	return true;
}
void shooterUI::OnDestroy() {}
void shooterUI::Update()
{
}

void shooterUI::Render()
{
	SDL_Rect imageRectangle;
	SDL_Surface *screenSurface = SDL_GetWindowSurface(window);
	//where to print HUD image
	float x, y;
	x = 0.0f;
	y = 40.0f;
	//converting location to screen location
	Vec3 screenCoords = projectionMatrix * Vec3(x, y, 0.0f);

	//setting up image rectangle
	imageRectangle.h = HUDImage->h;
	imageRectangle.w = HUDImage->w;
	imageRectangle.x = screenCoords.x; /// implicit type conversions BAD - probably causes a compiler warning
	imageRectangle.y = screenCoords.y; /// implicit type conversions BAD - probably causes a compiler warning
	//add image to screen surface
	SDL_BlitSurface(HUDImage, nullptr, screenSurface, &imageRectangle);

	//update the screen
	SDL_UpdateWindowSurface(window);
}

