#ifndef USERINTERFACE_H
#define USERINTERFACE_H
class UserInterface 
{
public:
	virtual bool OnCreate() = 0;
	virtual void OnDestroy() = 0;
	virtual void Update() = 0;
	virtual void Render() = 0;
};
#endif