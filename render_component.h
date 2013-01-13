#ifndef RENDERCOMPONENT_H
#define RENDERCOMPONENT_H

#include "component.h"
#include "sprite.h"
#include "graphics.h"

class RenderComponent: public Component
{
public:

	RenderComponent(string Name);
	RenderComponent(string Name, Sprite* Sprite);
	RenderComponent(string Name, Sprite* Sprite, bool Enabled);
	~RenderComponent();
	/*
	 Override base class Start()
	 */
	void Start();
	/*
	 Override base class Update()
	 */
	void Update(unsigned long dt);

private:

	/*
	 Texture2D to render to screen
	 */
	Sprite* sprite;
	void Render();
};

#endif
