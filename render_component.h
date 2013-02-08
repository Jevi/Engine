#ifndef RENDERCOMPONENT_H
#define RENDERCOMPONENT_H

#include <sstream>
#include <string>

#include "component.h"
#include "sprite.h"

class RenderComponent: public Component {
public:

	RenderComponent(std::string Id, std::shared_ptr<Sprite> Sprite, bool Enabled);
	~RenderComponent();

	std::shared_ptr<Sprite> GetSprite() {
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
	std::shared_ptr<Sprite> sprite;

	void Render();
};

#endif
