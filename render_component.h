#ifndef RENDERCOMPONENT_H
#define RENDERCOMPONENT_H

#include "component.h"
#include "texture2D.h"
#include "graphics.h"

class RenderComponent: public Component
{
public:

	Texture2D* sprite;

	RenderComponent(string Name);
	RenderComponent(string Name, Texture2D* Sprite);
	RenderComponent(string Name, Texture2D* Sprite, bool Enabled);
	~RenderComponent();

	void Start();
	void Update(unsigned long dt);

private:

	void Render();

};

#endif
