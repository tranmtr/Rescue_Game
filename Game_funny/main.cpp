#include "header.h"
#include "init_and_close.h"
#include "load_texture.h"
#include "figure.h"
#include "check_collision.h"
#include "load_camera.h"
#include "load_maze.h"
#include "ice.h"
#include "dragon.h"
#include "chooseLevel.h"
#include "loadText.h"
#include "load_mouse.h"

int main( int argc, char* args[] )
{
    int choose = 1;
    bool quit = false;
    string pathMaze;
    int LEVEL_WIDTH;
    int LEVEL_HEIGHT;
    int TOTAL_TILES;

    while(choose <= 2 && quit == false)
    {

        loadLevel(choose, pathMaze, LEVEL_WIDTH, LEVEL_HEIGHT, TOTAL_TILES);
        //The window we'll be rendering to
        SDL_Window* aWindow = NULL;

        //The window renderer
        SDL_Renderer* aRenderer = NULL;

        // Figure
        LTexture figureTexture[ANIMATION_STATUS_TOTAL];

        //Clip idle
        SDL_Rect clipsIdle[ANIMATION_FRAMES_IDLE];

        //Clip run
        SDL_Rect clipsRun[ANIMATION_FRAMES_RUN];

        //Clip die
        SDL_Rect clipsDie[ANIMATION_FRAMES_DIE];

        //Clip attack
        SDL_Rect clipsAttack[ANIMATION_FRAMES_ATTACK];

        //Clip DRAGON
        SDL_Rect clipsDragon[ANIMATION_FRAMES_DRAGON];

        //blood
        SDL_Rect bloodDragon;

        //mouse
        load_Mouse mouse;

        //Globally used font
        TTF_Font* aFont = NULL;

        LText textMenu[TOTAL_TEXT];

        //Rendered texture
        LTexture textMenuTexture[TOTAL_TEXT];

        //Next level
        LTexture nextLevelTexture;

        // Load wall, floor
        LTexture wallTexture;
        LTexture floorTexture;
        // Load lava, ice, cake
        LTexture lavaTexture;
        LTexture iceTexture;
        LTexture cakeTexture;
        // Image ice bullet
        LTexture iceImageTexture;

        // Dragon
        LTexture fireDragonTexture;

        //fire
        LTexture fireTexture;

        //start
        LTexture startTexture;
        //finish
        LTexture finishTexture;
        //Victory
        LTexture victoryTexture;
        //Defeat
        LTexture defeatTexture;

        //princess
        LTexture princessTexture;

        // ice bullet damage
        LIce iceDamage;

        //fire dragon
        dragon dragon[TOTAL_DRAGON];

        // animation fire
        int frameFireDragon = 0;

        //Current animation frame Idle
        int frameIdle = 0;

        //Current animation frame Run
        int frameRun = 0;

        //Current animation frame Die
        int frameDie = 0;

        //Current animation frame Attack
        int frameAttack = 0;


        //Start up SDL and create window
        if( !init(aWindow, aRenderer) )
        {
            cout <<  "Failed to initialize!\n" ;
        }
        else
        {
            //The level tiles
            Tile* tileSet[ TOTAL_TILES ];

            //Load media
            if( !loadMedia(aRenderer, figureTexture,wallTexture ,floorTexture, lavaTexture, iceTexture, cakeTexture, iceImageTexture,
                     fireDragonTexture, fireTexture, tileSet, TOTAL_TILES, LEVEL_WIDTH, LEVEL_HEIGHT, pathMaze, startTexture, finishTexture,
                     victoryTexture, defeatTexture, princessTexture, nextLevelTexture) || !loadText(aRenderer,textMenuTexture, aFont))
            {
                cout << "Failed to load media!\n" ;
            }
            else
            {
                // Load Rec Animation
                loadRectAnimation(clipsIdle, clipsRun, clipsDie, clipsAttack, clipsDragon);

                //Main loop flag
                //bool quit = false;

                 //Event handler
                SDL_Event e;

                //The figure that will be moving around on the screen
                Figure Figure;
                //cout << "Mo dau" << endl;

                Figure.setBoxFigure(choose);

                //The camera area
                SDL_Rect camera = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };


                //While application is running
                while( mouse.getNextLevel()== false  && quit == false )
                {
                    //cout << "Chua quit" << endl;
                    //Handle events on queue
                    while( SDL_PollEvent( &e ) != 0 )
                    {
                        mouse.handleEvent(e, Figure);
                        //User requests quit
                        if( e.type == SDL_QUIT )
                        {
                            quit = true;
                            cout << "QUIT" << endl;
                        }
                        if(Figure.getStatus() != ANIMATION_STATUS_DIE && Figure.getVictory() != true)
                        {
                            Figure.handleEvent(e);
                            //cout << "Vao" << endl;
                        }
                        else if(Figure.getStatus() == ANIMATION_STATUS_DIE)
                        {
                            Figure.resetVel();
                            //cout << "1" << endl;
                        }
                        else if(Figure.getVictory() == true)
                        {
                            Figure.resetVel();
                            //choose = choose + 1;
                        }
                        //cout << "Figure.getStatus() = " << Figure.getStatus() << endl;
                        //cout << mouse.getNextLevel() << endl;

                    }

                    //Move the figure
                    Figure.move(tileSet, LEVEL_WIDTH, LEVEL_HEIGHT, TOTAL_TILES);

                    //Load camera:
                    loadCamera(camera, Figure, LEVEL_WIDTH, LEVEL_HEIGHT);

                    //Clear screen
                    SDL_SetRenderDrawColor( aRenderer, 255, 255, 255, 255 );
                    SDL_RenderClear( aRenderer );

                    //Render level

                    for( int i = 0; i < TOTAL_TILES; i++ )
                    {
                        tileSet[ i ]->render( camera, floorTexture, wallTexture, aRenderer,lavaTexture,iceTexture,cakeTexture, startTexture, finishTexture );
                    }

                    setDragon(tileSet, dragon, TOTAL_TILES);

                    //Render objects
                    Figure.render(clipsIdle, clipsRun, clipsDie, clipsAttack, frameIdle, frameRun, frameDie, frameAttack, figureTexture, aRenderer, camera.x, camera.y);

                    if(Figure.getVictory() == false)
                    {
                        for(int i = 0; i < TOTAL_DRAGON; i++)
                        {
                            //Render ice bullet
                            iceDamage.moveIce(Figure, iceImageTexture, dragon[i], aRenderer, camera.x, camera.y, tileSet, TOTAL_TILES);
                            if(dragon[i].getBloodDragon() != 0 && checkCollision(camera, dragon[i].getBox()))
                            {
                                dragon[i].render(fireDragonTexture, clipsDragon, aRenderer, camera.x, camera.y);
                                dragon[i].fireMove(Figure, fireTexture, aRenderer, camera.x, camera.y, tileSet, TOTAL_TILES);
                            }
                        }

                    }


                    princessTexture.render(Figure.getPrincessBox().x - camera.x, Figure.getPrincessBox().y - camera.y, NULL, 0, NULL, SDL_FLIP_NONE, aRenderer);
                    for(int i = 0; i < TOTAL_TEXT; i++)
                    {
                        textMenu[i].setText(i, Figure, camera.x, camera.y);
                        textMenu[i].renderText(aRenderer, textMenuTexture[i], camera.x, camera.y);
                    }
                    if(Figure.getVictory() == true)
                    {
                        victoryTexture.render(161,167,NULL, 0, NULL, SDL_FLIP_NONE, aRenderer);
                    }

                    if(Figure.getStatus() == ANIMATION_STATUS_DIE)
                    {
                        defeatTexture.render(161,167,NULL, 0, NULL, SDL_FLIP_NONE, aRenderer);
                    }
                    nextLevelTexture.render(SCREEN_WIDTH - 75, SCREEN_HEIGHT - 35, NULL, 0, NULL, SDL_FLIP_NONE, aRenderer );

                    SDL_RenderPresent( aRenderer );
                }
            }
        }

        //Free resources and close SDL
        close(aWindow, aRenderer,figureTexture, wallTexture, floorTexture,lavaTexture, iceTexture,cakeTexture, aFont);
        choose = choose + 1;
    }
	return 0;
}
