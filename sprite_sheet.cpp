#include "sprite_sheet.h"

#include "debug.h"
#include "engine_math.h"

void SpriteSheet::Bind() {
	glBindTexture(GL_TEXTURE_2D, textureId);
}

bool SpriteSheet::Load() {
	SDL_Surface* image = IMG_Load(filename.c_str());

	if (image == NULL) {
		return false;
	}

	width = image->w;
	height = image->h;

	if ((width == 0) || (height == 0)) {
		return false;
	}

	GLuint tempId;
	glGenTextures(1, &tempId);
	textureId = tempId;

	glBindTexture(GL_TEXTURE_2D, textureId);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image->pixels);
	SDL_FreeSurface(image);
	loaded = true;
	return true;
}

void SpriteSheet::Unload() {
	if (loaded) {
		GLuint tempId;
		tempId = textureId;
		glDeleteTextures(1, &tempId);

		width = height = 0;
		filename = "";
		loaded = false;
	}
}

std::string SpriteSheet::ToString() {
	tinyxml2::XMLDocument doc;
	tinyxml2::XMLElement* root = doc.NewElement("Asset");
	root->SetAttribute("id", id.c_str());
	root->SetAttribute("filename", filename.c_str());
	root->SetAttribute("type", type);
	doc.LinkEndChild(root);
	return Debug::XMLDocumentToString(&doc);
}
