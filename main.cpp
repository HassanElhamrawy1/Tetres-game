#include <iostream>
#include <raylib.h>
#include "game.h"
#include "colors.h"

/* this variavle will keep track of the time at which the last update of the game occured*/
double lastUpdateTime = 0; 
/* function to see if some interval had passed*/
bool EventTriggered(double interval)
{
    double currentTime = GetTime();                      /* get the time in seconds*/
    if((currentTime - lastUpdateTime) >= interval)
    {
        lastUpdateTime = currentTime;
        return true;
    }
    return false;
}


int main () 
{
    char scoreText[10];
    Vector2 textsize;
    /* This function initialize the window for the game */ 
    InitWindow(500, 620, "Raylib Tetris");

    /* Defining how fast the canvas should run 
       This function takes int which define the frame per second
       and it need to be called before the Game Loop 
       if we did not specify this number of frame the computer will fun the game as fast as it can
    */
   SetTargetFPS(60);

    /* Load the font which we will use */
    Font font = LoadFontEx("Font/ShadeBlue.ttf", 64, 0, 0);
    /*  create a game object */
    Game game = Game();


    /* Game Loop*/
    while(WindowShouldClose() == false)
    {
        
        /*this API is to handle the input from the keyboard */
        game.HandleInput();
        /* move block down for periodically as per the logic of the game  every 200 ms*/
        if(EventTriggered(0.2))
        {
            game.MoveBlocDown();
        }
        /* this function will create a blank canvas which we will draw our game object on it */
        BeginDrawing();
        /* when we call this function we will clear the backGround of the window with the color we gave to it
           this will be done at the begin of the game loop
        */
        ClearBackground(darkBlue);
        /* draw text score on the canvas */
        DrawTextEx(font, "Score", {365, 15}, 38, 2, WHITE);
        DrawTextEx(font, "Next", {370, 175}, 38, 2, WHITE);
        if(game.gameOver)
        {
            DrawTextEx(font, "GAME OVER", {320, 500}, 38, 2, WHITE);
        }
        /* add rounded revtangler to draw the score on it*/
        DrawRectangleRounded({320, 55, 170, 60}, 0.3, 6, lightBlue);
        /* draw the score */
        sprintf(scoreText, "%d", game.score);                                       /* convert score value into text*/     
        textsize = MeasureTextEx(font, scoreText, 38, 2);                           /* measure the text size*/
        DrawTextEx(font, scoreText, {320 + (170 - textsize.x)/2, 65}, 38, 2, WHITE);    /* the equation is to draw the score in the middle of the rectanguler*/ 
         /* add rounded revtangler to draw the next block on it*/
         DrawRectangleRounded({320, 215, 170, 180}, 0.3, 6, lightBlue);

        /* call the draw method to draw the cells on the grid  and also will draw a random block*/
        game.Draw();
  
        
         /* this function will end the canvas drawing  */
        EndDrawing();

    }

    /* This function is to destroy the window after finishing */
    CloseWindow();
}