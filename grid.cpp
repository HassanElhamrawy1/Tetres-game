#include "grid.h"
#include "colors.h"
#include <iostream>


/* the constructor where we will initialize all the attributes */

Grid::Grid()
{
    /* Initialize the private variables */
    numRows = 20;
    numCols = 10;
    cellSize = 30;
    /* Initialize the grid */
    Initialize();
    colors = GetCellsColors();
}

void Grid::Initialize()
{
    for(int row = 0; row < numRows; row++)
    {
        for(int column = 0; column < numCols; column++)
        {
            grid[row][column] = 0;
        }
    }
}

void Grid::Print()
{
    for(int row = 0; row < numRows; row++)
    {
        for(int column = 0; column < numCols; column++)
        {
            std::cout << grid[row][column] << " ";
        }
        std::cout << std::endl;
    }

}

bool Grid::IsRowFull(int row)
{
    for(int column = 0; column< numCols; column++)
    {
        if(grid[row][column] == 0)
        {
            return false;
        }
    }
    return true;
}

void Grid::ClearRow(int row)
{
    for(int column = 0; column< numCols; column++)
    {
        grid[row][column] = 0;
    }

}

void Grid::MoveRowDown(int row, int numRows)
{
    for(int column = 0; column< numCols; column++)
    {
        grid[row + numRows][column] = grid[row][column];                /* move the row current down*/
        grid[row][column] = 0;                                          /* clear the current row */
    }
}

void Grid::Draw()
{
    for(int row = 0; row < numRows; row++)
    {
        for(int column = 0; column < numCols; column++)
        {
            /* get each cell value */
            int cellValue  = grid[row][column];
            /**DrawRectangle(x, y, w, h, color) used to deaw square on the cell
               Note here x is the column and y is the rows in computer geafics (0, 0) is on the top left of the canvas
              *indexing the colors with cellValue 
              * the one + and - here is to make a margin to see the cells
              * we add 10 to the margin one as offset to make the place of the grid centralised better
            */
            DrawRectangle(column*cellSize+11, row*cellSize+11 , cellSize-1, cellSize-1, colors[cellValue]); 
        }
    }
}

bool Grid::IsCellOutside(int row, int column)
{
    if(row >= 0 &&  row < numRows && column >= 0  && column < numCols )
    {
        return false;
    }
    else
    {
        return true;
    }
    
}

bool Grid::IsCellEmpty(int row, int column)
{
    if(grid[row][column] == 0)
    {
        return true;
    }
    return false;
}

int Grid::ClearFullRows()
{
    int completed = 0;
    for(int row = numRows-1; row >=0; --row)         /* loop on all rows */
    {
        if(IsRowFull(row))                           /* check if the row is full or not */
        {
            ClearRow(row);                          /* clear the row if it is compeleted */
            completed++;                            /* increment the compeleted flag to keep track of the completed rows */
        }
        else if(completed > 0)                      /* if the row is not completed and completed is > 0 then move the rows down */
        {
            MoveRowDown(row, completed);
        }

    }
    return completed;
}
