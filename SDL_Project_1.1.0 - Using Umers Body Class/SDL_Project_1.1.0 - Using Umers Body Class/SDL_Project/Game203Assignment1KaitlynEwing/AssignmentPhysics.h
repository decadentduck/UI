#ifndef ASSIGNMENTPHYSICS_H
#define ASSIGNMENTPHYSICS_H

#include "MMath.h"
#include "Scene.h"
#include <SDL.h>
#define NUM_BODIES 2

using namespace MATH;

class AssignmentPhysics : public Scene
{
private:
	SDL_Window * window;
	Matrix4 projectionMatrix;
	class Body* bodies[NUM_BODIES];
	float elapsedTime;
	float gravity;
	unsigned long frameCount;
public:
	AssignmentPhysics(SDL_Window* sdlWindow);
	~AssignmentPhysics();
	bool OnCreate();
	void OnDestroy();
	void Update(const float time);
	void Render();
	virtual void HandleEvents(const SDL_Event &event);
};

#endif