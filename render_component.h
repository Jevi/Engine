#ifndef RENDERCOMPONENT_H
#define RENDERCOMPONENT_H

#include <sstream>
#include <string>

#include "component.h"
#include "sprite.h"

class RenderComponent: public Component {
public:

	RenderComponent(std::string Id);
	RenderComponent(std::string Id, Sprite* Sprite);
	RenderComponent(std::string Id, Sprite* Sprite, bool Enabled);
	~RenderComponent();

	Sprite* GetSprite() {
		return sprite;
	}

	/*
	 Override base class Start()
	 */
	void Start();
	/*
	 Override base class Update()
	 */
	void Update(unsigned long Dt);

	std::string ToString();

private:

	/*
	 Texture2D to render to screen
	 */
	Sprite* sprite;

	void Render();
};

#endif
