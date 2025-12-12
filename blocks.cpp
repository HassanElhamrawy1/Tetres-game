#include "block.h"
#include "position.h"


/* class for Lblock which will inhirite the Block class */
class LBlock : public Block
{
    public:
        LBlock()
        {
            id = 1;
            /* here we will define the occupied positions of the cell grid for the Lblock for rotationState 0 as the Lblock will be in a grid 3*3 */
            cells[0] = {Position(0,2), Position(1,0), Position(1,1), Position(1,2)};
            cells[1] = {Position(0,1), Position(1,1), Position(2,1), Position(2,2)};
            cells[2] = {Position(1,0), Position(1,1), Position(1,2), Position(2,0)};
            cells[3] = {Position(0,0), Position(0,1), Position(1,1), Position(2,1)};
            /* Move the blocks 3 cells to the right to start from the middle as per the online game*/
            Move(0,3);
        }

}; 

class JBlock : public Block
{
    public:
        JBlock()
        {
            id = 2;
            /* here we will define the occupied positions of the cell grid for the Lblock for rotationState 0 as the Lblock will be in a grid 3*3 */
            cells[0] = {Position(0,0), Position(1,0), Position(1,1), Position(1,2)};
            cells[1] = {Position(0,1), Position(0,2), Position(1,1), Position(2,1)};
            cells[2] = {Position(1,0), Position(1,1), Position(1,2), Position(2,2)};
            cells[3] = {Position(0,1), Position(1,1), Position(2,0), Position(2,1)};
            /* Move the blocks 3 cells to the right to start from the middle as per the online game*/
            Move(0,3);
        }

}; 

class IBlock : public Block
{
    public:
        IBlock()
        {
            id = 3;
            /* here we will define the occupied positions of the cell grid for the Lblock for rotationState 0 as the Lblock will be in a grid 3*3 */
            cells[0] = {Position(1,0), Position(1,1), Position(1,2), Position(1,3)};
            cells[1] = {Position(0,2), Position(1,2), Position(2,2), Position(3,2)};
            cells[2] = {Position(2,0), Position(2,1), Position(2,2), Position(2,3)};
            cells[3] = {Position(0,1), Position(1,1), Position(2,1), Position(3,1)};
            /* Move the blocks 3 cells to the right to start from the middle as per the online game
            -1 because it is a special case to put it in the first row
            */
            Move(-1,3);
        }

};

class OBlock : public Block
{
    public:
        OBlock()
        {
            id = 4;
            /* here we will define the occupied positions of the cell grid for the Lblock for rotationState 0 as the Lblock will be in a grid 3*3 */
            cells[0] = {Position(0,0), Position(0,1), Position(1,0), Position(1,1)};
            /* Move the blocks 4 cells to the right to start from the middle as per the online game*/
            Move(0,4);
        }

};

class SBlock : public Block
{
    public:
        SBlock()
        {
            id = 5;
            /* here we will define the occupied positions of the cell grid for the Lblock for rotationState 0 as the Lblock will be in a grid 3*3 */
            cells[0] = {Position(0,1), Position(0,2), Position(1,0), Position(1,1)};
            cells[1] = {Position(0,1), Position(1,1), Position(1,2), Position(2,2)};
            cells[2] = {Position(1,1), Position(1,2), Position(2,0), Position(2,1)};
            cells[3] = {Position(0,0), Position(1,0), Position(1,1), Position(2,1)};
            /* Move the blocks 3 cells to the right to start from the middle as per the online game*/
            Move(0,3);
        }

};

class TBlock : public Block
{
    public:
        TBlock()
        {
            id = 6;
            /* here we will define the occupied positions of the cell grid for the Lblock for rotationState 0 as the Lblock will be in a grid 3*3 */
            cells[0] = {Position(0,1), Position(1,0), Position(1,1), Position(1,2)};
            cells[1] = {Position(0,1), Position(1,1), Position(1,2), Position(2,1)};
            cells[2] = {Position(1,0), Position(1,1), Position(1,2), Position(2,1)};
            cells[3] = {Position(0,1), Position(1,0), Position(1,1), Position(2,1)};
            /* Move the blocks 3 cells to the right to start from the middle as per the online game*/
            Move(0,3);
        }

};

class ZBlock : public Block
{
    public:
        ZBlock()
        {
            id = 7;
            /* here we will define the occupied positions of the cell grid for the Lblock for rotationState 0 as the Lblock will be in a grid 3*3 */
            cells[0] = {Position(0,0), Position(0,1), Position(1,1), Position(1,2)};
            cells[1] = {Position(0,2), Position(1,1), Position(1,2), Position(2,1)};
            cells[2] = {Position(1,0), Position(1,1), Position(2,1), Position(2,2)};
            cells[3] = {Position(0,1), Position(1,0), Position(1,1), Position(2,0)};
            /* Move the blocks 3 cells to the right to start from the middle as per the online game*/
            Move(0,3);
        }

};










