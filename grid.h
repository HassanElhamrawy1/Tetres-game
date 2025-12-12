/* This pragma is to ensure that this file will be included once in compilation to avoid duplicate definitions */
#pragma once
#include <vector>
#include <raylib.h>


class Grid 
{
    public:      /* public methods will be defined hetre */
        Grid();                                      /* class constructor */
        void Initialize();                           /* this will intialize the grid array */
        int grid[20][10];                            /* 2D array to represent the grid itself */
        void Draw();                                 /* method to draw the grid*/
        bool IsCellOutside(int row, int column);     /* method to check if the cell is outside the grod ir not */
        bool IsCellEmpty(int row, int column);       /* method to check if the cell is empty or not */
        int ClearFullRows();                         /* method to clear full rows*/

         /* Testing method */
         void Print();


    private:     /* private methods will be defined hetre */
        bool IsRowFull(int row);                                     /* method to check if the row is full of cells or not */
        void ClearRow(int row);                                      /* method to clear a row */
        void MoveRowDown(int row, int numRows);                     /* method to move the row down with an amount of the removed rows*/
        int numRows;
        int numCols;
        int cellSize;
        std::vector<Color> colors;

};








