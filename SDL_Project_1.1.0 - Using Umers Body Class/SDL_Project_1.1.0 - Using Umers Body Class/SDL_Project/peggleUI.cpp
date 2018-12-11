#include "peggleUI.h"
#include "Vector.h"
#include "VMath.h"
#include <math.h>
#include <SDL_image.h>
#include "MMath.h"

peggleUI::peggleUI(SDL_Window* sdlWindow_)
{
	window = sdlWindow_;
}

peggleUI::~peggleUI()
{
}

bool peggleUI::OnCreate() 
{
	//window height and width
	int w, h;
	SDL_GetWindowSize(window, &w, &h);
	//matrix to change orientation of grid (0, 0) is at bottom left
	projectionMatrix = MMath::viewportNDC(w, h) * MMath::orthographic(0.0f, 40.0f, 0.0f, 40.0f, 0.0f, 1.0f);
	
	//image initialize
	IMG_Init(IMG_INIT_PNG);

	char *imageName = "gir_round_small.png";
	ballImage = IMG_Load(imageName);
	IMG_Quit();

	return true;
}
void peggleUI::OnDestroy() 
{
}
void peggleUI::Update() 
{
	//not sure how to update based on game since the game will not always be active screen
	balls = 10;
}

void peggleUI::Render() 
{
	SDL_Rect imageRectangle;
	SDL_Surface *screenSurface = SDL_GetWindowSurface(window);
	//image coordinates
	float x, y;
	x = 0.0f;
	y = 40.0f;
	
	//draw each ball on the screen
	for (int i = 0; i < balls; i++)
	{
		//alter x coordinate
		x = i * 3;
		//convert coordinates for screen
		Vec3 screenCoords = projectionMatrix * Vec3(x, y, 0.0f);
		//set up image rectange properties
		imageRectangle.h = ballImage->h;
		imageRectangle.w = ballImage->w;
		imageRectangle.x = screenCoords.x; /// implicit type conversions BAD - probably causes a compiler warning
		imageRectangle.y = screenCoords.y; /// implicit type conversions BAD - probably causes a compiler warning
		//add imageto screen
		SDL_BlitSurface(ballImage, nullptr, screenSurface, &imageRectangle);
	}

	//update the screen
	SDL_UpdateWindowSurface(window);
}

