#include "block.h"

Block::Block()
{
    cellSize = 30;
    rotationState = 0;
    rowOffset = 0;                 
    columnOffset = 0;               
    colors = GetCellsColors();
}

void Block::Draw(int offsetX, int offsetY)
{
    /* this line will retrive the vector of positions for the current rotation of the tetromino
       as determined of the value of the rotation attribute but after calculating the nes cell positions using the offsets*/
    std::vector<Position> tiles = GetCellPositions();
    /* we will loop on the tiles and create rectangle for each cell */
    for(Position item: tiles)
    {
        /**DrawRectangle(x, y, w, h, color) used to deaw square on the cell
               Note here x is the column and y is the rows in computer geafics (0, 0) is on the top left of the canvas
              *indexing the colors with block id as the index 
              *we also need to add the margin of 10 and one as per the grid
            */
           DrawRectangle(item.column*cellSize+offsetX, item.row*cellSize +offsetY , cellSize-1, cellSize-1, colors[id]); 

    }
}

void Block::Move( int rows, int columns)
{
    /* we will just add the amount we need to move the block  to the offsets */
    rowOffset += rows; 
    columnOffset += columns;
}

/* method to calculate the new position of the block after applying the offsets
   the return of thos api will be vector of the new occupied position 
*/
std::vector<Position> Block::GetCellPositions()
{
    /* get the default position of the current rotation state*/
    std::vector<Position> tiles = cells[rotationState];
    /* new vector which will hold the moved tiles*/
    std::vector<Position> movedTiles;
    /* loop on all the tiles and add the offset to their positions */ 
    for(Position item: tiles)
    {
        Position newPos = Position(item.row + rowOffset, item.column + columnOffset);     /* calculate the new position */
        /* push back the new positions into movedTiles */
        movedTiles.push_back(newPos);
    }

    return movedTiles;
}

void Block::Rotate()
{
    rotationState++;
    /* here we will check if the rotationState = to the cell size  must be from 0 to (cells.size()-1) */
    if(rotationState == (int)cells.size())
    {
        rotationState = 0;
    }
}

void Block::UnDoRotation()
{
    rotationState--;
    if(rotationState == -1)
    {
        rotationState = cells.size()-1;
    }
}
