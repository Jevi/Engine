#ifndef RENDERCOMPONENT_H
#define RENDERCOMPONENT_H

#include "Component.h"
#include "Texture2D.h"
#include "Graphics.h"

class RenderComponent: public Component
{
public:

	Texture2D* sprite;

	RenderComponent(string Name);
	RenderComponent(string Name, Texture2D* Sprite);
	RenderComponent(string Name, Texture2D* Sprite, bool Enabled);

	void OnStart();
	void OnUpdate(unsigned long dt);

private:

	void Render();

};

#endif
