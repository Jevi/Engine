#ifndef MY_SPRITE_SHEET_H
#define MY_SPRITE_SHEET_H

#include "myAsset.h"
#include "myGraphics.h"

class mySpriteSheet: public myAsset {
public:

	int totalRows, totalColumns;
	int width, height;
	int currentRow, currentColumn;
	unsigned long update;

    mySpriteSheet(std::string Id, std::string Filename, int TotalRows, int TotalColums, unsigned long Update) :
			myAsset(Id, Filename, myAsset::SPRITE_SHEET), totalRows(TotalRows), totalColumns(TotalColums), update(Update), width(0), height(0), currentRow(0), currentColumn(0), loaded(false) {

	}

    ~mySpriteSheet(void) {
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
