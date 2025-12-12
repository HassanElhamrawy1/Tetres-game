#pragma once
#include <vector>
#include <map>
#include "position.h"
#include "colors.h"

class Block
{
    public:
        Block();                                    /* Constructor */
        void Draw(int offsetX, int offsetY);        /* method to draw blocks*/
        void Move(int rows, int columns);           /* method to move the block*/
        std::vector<Position> GetCellPositions();   /* method to calculate the new cell position of the block */
        void Rotate();                              /* method to rotate the block */
        void UnDoRotation();                        /* method to undo the rotation if it is outside the boundries*/

        int id; /* Block ID */
        /* here we are creating a map called cells and the key is int and the values for each key will be vector*/
        std::map<int, std::vector<Position>> cells;

    private:
        int cellSize;                   /* the size of each cell */
        int rotationState;              /* the rotation state of each block*/ 
        int rowOffset;                  /* offset will be used to move the blocks right or left */
        int columnOffset;                  /* offset will be used to move the blocks up or down */
        std::vector<Color> colors;


};















