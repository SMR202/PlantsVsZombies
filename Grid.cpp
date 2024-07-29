#include "Grid.h"

Grid::Grid() : lastLineDefence(nullptr) {

    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {

            tiles[i][j].getTopLeft().x = 179 + j * 57;
            tiles[i][j].getTopLeft().y = 56 + i * 69;

            tiles[i][j].getBottomRight().x = 179 + j * 57 + 57;
            tiles[i][j].getBottomRight().y = 56 + i * 69 + 69;

            tiles[i][j].getBottomLeft().x = 179 + j * 57;
            tiles[i][j].getBottomLeft().y = 56 + i * 69 + 69;

            tiles[i][j].getTopRight().x = 179 + j * 57 + 57;
            tiles[i][j].getTopRight().y = 56 + i * 69;

            tiles[i][j].getCenter().x = 179 + j * 57 + 28;
            tiles[i][j].getCenter().y = 56 + i * 69 + 35;

            isPlantable[i][j] = true;
        }
    }
}

Tile& Grid::getTile(int x, int y) {
    return tiles[x][y];
}

coordinates& Grid::checkBounds(int x, int y) {
    coordinates temp;
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            if (x >= tiles[i][j].getTopLeft().x && x <= tiles[i][j].getBottomRight().x && y >= tiles[i][j].getTopLeft().y && y <= tiles[i][j].getBottomRight().y) {
				temp.x = i;
                temp.y = j;
				return temp;
			}
        }
    }
}

bool Grid::getIsPlantable(int x, int y) {
	return isPlantable[x][y];
}

void Grid::setIsPlantable(int x, int y, bool isPlantable) {
	this->isPlantable[x][y] = isPlantable;
}

Tile& Grid::getTile(coordinates& point) {
    return tiles[point.x][point.y];
}