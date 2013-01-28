#ifndef RENDERCOMPONENT_H
#define RENDERCOMPONENT_H

#include <sstream>
#include <string>

#include "engine_math.h"
#include "component.h"
#include "sprite.h"
#include "graphics.h"
#include "tinyxml2.h"
#include "debug.h"
#include "physics_component.h"

using namespace std;

class RenderComponent: public Component
{
public:

	RenderComponent(string Id);
	RenderComponent(string Id, Sprite* Sprite);
	RenderComponent(string Id, Sprite* Sprite, bool Enabled);
	~RenderComponent();

	Sprite* GetSprite()
	{
		return sprite;
	}

	/*
	 Override base class Start()
	 */
	void Start();
	/*
	 Override base class Update()
	 */
	void Update(unsigned long dt);

	string ToString();

private:

	/*
	 Texture2D to render to screen
	 */
	Sprite* sprite;
	void Render();
};

#endif
