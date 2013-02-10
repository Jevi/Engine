#ifndef SPRITE_SHEET_H
#define SPRITE_SHEET_H

#include "asset.h"
#include "graphics.h"

class SpriteSheet: public Asset {
public:

	int totalRows, totalColumns;
	int width, height;
	int currentRow, currentColumn;
	unsigned long update;

	SpriteSheet(std::string Id, std::string Filename, int TotalRows, int TotalColums, unsigned long Update) :
			Asset(Id, Filename, Asset::SPRITE_SHEET), totalRows(TotalRows), totalColumns(TotalColums), update(Update), width(0), height(0), currentRow(0), currentColumn(0), loaded(false) {

	}

	~SpriteSheet(void) {
		Unload();
	}

	void Bind();

	bool Load();

	void Unload();

	std::string ToString();

protected:

	GLuint textureId;
	bool loaded;
};

#endif
