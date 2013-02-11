#ifndef MY_RENDERCOMPONENT_H
#define MY_RENDERCOMPONENT_H

#include <sstream>
#include <string>

#include "myComponent.h"
#include "mySprite.h"
#include "mySpriteSheet.h"

class myRenderComponent: public myComponent {
public:

    myRenderComponent(std::string Id, std::shared_ptr<mySprite> mySprite, bool Enabled);
    myRenderComponent(std::string Id, std::shared_ptr<mySpriteSheet> Sprite_Sheet, bool Enabled);
    ~myRenderComponent();

    std::shared_ptr<mySprite> GetSprite() {
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
    std::shared_ptr<mySprite> sprite;
    std::shared_ptr<mySpriteSheet> spriteSheet;

	unsigned long updateSpriteSheet;

	void Render(unsigned long Dt);

	void RenderSprite();

	void RenderSpriteSheet(unsigned long Dt);
};

#endif
