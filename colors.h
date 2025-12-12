#pragma once

#include<raylib.h>
#include <vector>

extern const Color darkGrey;
extern const Color green;
extern const Color red;
extern const Color orange;
extern const Color yellow;
extern const Color purple;
extern const Color cyan;
extern const Color blue;
extern const Color lightBlue;
extern const Color darkBlue;

/* method to return the vector of the colors which we will use for the blocks and the empty cells */
std::vector<Color> GetCellsColors();

