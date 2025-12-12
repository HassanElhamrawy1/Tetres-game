#include "game.h"
#include <random>

Game::Game()
{
    Grid grid;                                /* creating grid object */
    blocks = GetAllBlocks();                  /* create vector which will contain all blocks in it */
    currentBlock = GetRandomBlock();
    nextBlock = GetRandomBlock();
    gameOver = false;
    score = 0;
}

Block Game::GetRandomBlock()
{
    /* check if the block is empty to refill it */
    if(blocks.empty())
    {
        blocks = GetAllBlocks();
    }
    int randomIndex = rand() % blocks.size();                      /* get random number between 0 and blocks.size*/
    Block block = blocks[randomIndex];                             /* get the block which index is the randomIndex*/
    blocks.erase(blocks.begin() + randomIndex);                    /* remove the block we got from the blocks vector*/
    
    return block;
}

std::vector<Block> Game::GetAllBlocks()
{
    return {IBlock(), JBlock(), LBlock(), OBlock(), SBlock(), TBlock(), ZBlock()};
}

void Game::Draw()
{
    grid.Draw();
    currentBlock.Draw(11, 11);
    switch (nextBlock.id)
    {
    case 3:                         /* I block */
        nextBlock.Draw(255, 290);
        break;
    case 4:                         /* O block */
        nextBlock.Draw(255, 280);
        break;
    default:
        nextBlock.Draw(270, 270);
        break;
    }
}

void Game::HandleInput()
{
    int keyPressed = GetKeyPressed();   /* method to get the key pressed by the user */
    if(gameOver && keyPressed != 0)     /* restart the game of the user press any key after the game is over*/
    {
        gameOver = false;
        Reset();
    }

    switch(keyPressed)
    {
        case KEY_LEFT:
            MoveBlockLeft();
            break;
        case KEY_RIGHT:
            MoveBlockRight();
            break;
        case KEY_DOWN:
            MoveBlocDown();
            UpdateScore(0, 1);                                  /* Update score values each move down by 1*/
            break; 
        case KEY_UP:
            RotateBlock();
            break;      
    }

}

void Game:: MoveBlockLeft()
{
    if(!gameOver)
    {
        currentBlock.Move(0,-1);
        if(IsBlockOutSide() || (Blockfits() == false))
        {
            currentBlock.Move(0, 1);
        }  
    }
     
}

void Game:: MoveBlockRight()
{
    if(!gameOver)
    {
        currentBlock.Move(0,1);
        if(IsBlockOutSide() || (Blockfits() == false))
        {
            currentBlock.Move(0, -1);
        }  
    }      
}

void Game:: MoveBlocDown()
{
    if(!gameOver)
    {
        currentBlock.Move(1,0);
        if(IsBlockOutSide() || (Blockfits() == false))    /* we cannot move the block down if the block is outside we will undo the move of if there is another block below it */
        {
            currentBlock.Move(-1, 0);
            LockBlock();
        } 
    }       
}

bool Game::IsBlockOutSide()
{
    std::vector<Position> tiles = currentBlock.GetCellPositions();                       /* get all cell positions */
    for(Position item: tiles)
    {
        if(grid.IsCellOutside(item.row, item.column))
        {
            return true;
        }
    }
    return false;

}

void Game::RotateBlock()
{
    if(!gameOver)
    {
        currentBlock.Rotate();
        /* check if the block is outside the grid and undo the rotatuin if true*/
        if(IsBlockOutSide() || (Blockfits() == false))
        {
            currentBlock.UnDoRotation();
        }
    }    
}

void Game::LockBlock()
{
    std::vector<Position> tiles = currentBlock.GetCellPositions(); 
    for(Position item: tiles)
    {
        grid.grid[item.row][item.column] = currentBlock.id;     /* assign the id of the current block to the grid cells */      
    } 
    currentBlock = nextBlock;                                   /* update the current block with next block */
    if(Blockfits() == false)                                    /* check if the block fits or not and the game is over  */
    {
        gameOver = true;
    }
    nextBlock = GetRandomBlock();                               /* get rundom block into nextBlock */
    
    int rowsCleared = grid.ClearFullRows();                     /* check if there is full rows and clear them*/

    UpdateScore(rowsCleared, 0);                                /* Update score values incase if any lines cleared*/

}

bool Game::Blockfits()
{
    std::vector<Position> tiles = currentBlock.GetCellPositions();
    for(Position item: tiles)
    {
        if(grid.IsCellEmpty(item.row, item.column) == false)
        {
            return false;
        }      
    }
    return true;
}

void Game::Reset()
{
    grid.Initialize();                        /* clear the grid */
    blocks = GetAllBlocks();                  /* reset the blocks vector to hold all blocks again*/
    currentBlock = GetRandomBlock();
    nextBlock = GetRandomBlock();
    score = 0;
}

void Game::UpdateScore(int linesCleared, int moveDownPoints)
{
    switch(linesCleared)
    {
        case 1:
            score+= 100;
            break;
        case 2:
            score+= 300;
            break;
        case 3:
            score+= 500; 
            break;
        default:
            break;       
    }
    score += moveDownPoints;

}
