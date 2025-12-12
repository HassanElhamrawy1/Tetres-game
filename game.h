#pragma once
#include "grid.h"
#include "blocks.cpp"


/* this class will be central class for our game */

class Game
{
    public: 
        Game();                              /* class constructor */
        void Draw();                         /* method will be responsible to draw the objecs on the screen */
        void HandleInput();                  /* method to handle the inputs from the user n the keyboard */
        void MoveBlocDown();                 /* method to move the block to the down*/
        bool gameOver;                       /* flag to end the game*/
        int score;                           /* the score of the game */
    private:
        Block GetRandomBlock();              /* method to get random block*/
        std::vector<Block> GetAllBlocks();   /* method will return a vector with all blocks in it (refill the blocks vector) */
        bool IsBlockOutSide();               /* this method will use the IsCellOutside to check if the block is outside the grid or not*/  
        void MoveBlockLeft();                /* method to move the block to the left*/
        void MoveBlockRight();               /* method to move the block to the right*/
        void RotateBlock();                  /* method to rotate the block */  
        void LockBlock();                    /* method lock the block when it reach the bottom*/ 
        bool Blockfits();                    /* method to ckeck if everycell in the grid is on top of an empty cell or not*/    
        void Reset();                        /* method to reset the game */  
        /* method to update the score of the game*/
        void UpdateScore(int linesCleared, int moveDownPoints);                       
        std::vector<Block> blocks;           /* vector which wil hold all the blocks */
        Block currentBlock;                   
        Block nextBlock;  
        Grid grid;                           /* grid class object*/

};








