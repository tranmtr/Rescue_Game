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
    bool start = false;
    bool quit = false;
    bool checkChooseLevel = false;
    bool checkHowToPlay = false;
    string pathMaze;
    int LEVEL_WIDTH;
    int LEVEL_HEIGHT;
    int TOTAL_TILES;
    int TOTAL_DRAGON;

    while(choose <= TOTAL_LEVEL && quit == false)
    {
        loadLevel(choose, pathMaze, LEVEL_WIDTH, LEVEL_HEIGHT, TOTAL_TILES, TOTAL_DRAGON);
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

        //Clip princess run
        SDL_Rect clipsPrincessRun[ANIMATION_FRAMES_PRINCESS_RUN];

        //blood
        SDL_Rect bloodDragon;

        //Globally used font
        TTF_Font* aFont = NULL;

        LText textMenu[TOTAL_TEXT];

        //Rendered texture
        LTexture textMenuTexture[TOTAL_TEXT];

        //Next level
        LTexture nextLevelTexture;

        //Again
        LTexture levelAgainTexture;

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

        //Menu
        LTexture menuTexture;

        //mouse
        load_Mouse mouse;

        // arrowMenu
        LTexture arrowrightMenuTexture;
        LTexture arrowleftMenuTexture;
        LTexture arrowdownMenuTexture;

        SDL_Rect arrowrightMenuRect;
        SDL_Rect arrowleftMenuRect;
        SDL_Rect arrowdownMenuRect;

        //Menu
        LTexture chooseLevelTexture;
        LTexture howToPlayTexture;

        // ice bullet damage
        LIce iceDamage;

        //fire dragon
        dragon dragon[TOTAL_DRAGON];

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
                     victoryTexture, defeatTexture, princessTexture, nextLevelTexture, menuTexture, arrowrightMenuTexture, arrowleftMenuTexture,
                     levelAgainTexture, arrowdownMenuTexture, chooseLevelTexture, howToPlayTexture)
               || !loadText(aRenderer,textMenuTexture, aFont))
            {
                cout << "Failed to load media!\n" ;
            }
            else
            {
                // Load Rec Animation
                loadRectAnimation(clipsIdle, clipsRun, clipsDie, clipsAttack, clipsDragon, clipsPrincessRun);

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

                //choose level
                mouse.setButtonDownLevel();

                //While application is running
                while( mouse.getNextLevel()== false  && mouse.getLevelAgain() == false && quit == false && mouse.getButtonDownLevel() == false)
                {
                    //cout << "Chua quit" << endl;
                    //Handle events on queue
                    while( SDL_PollEvent( &e ) != 0 )
                    {
                        mouse.handleEvent(e, Figure, arrowrightMenuRect, arrowleftMenuRect, aRenderer, start, checkChooseLevel, checkHowToPlay, quit,
                                          choose, arrowdownMenuRect);
                        mouse.render(arrowrightMenuTexture, arrowleftMenuTexture, arrowrightMenuRect, arrowleftMenuRect, menuTexture,
                                     chooseLevelTexture, howToPlayTexture, aRenderer, start, quit, checkChooseLevel, checkHowToPlay,
                                     arrowdownMenuTexture, arrowdownMenuRect);
                        //cout << "NEXT LEVEL = " << mouse.getNextLevel() << endl;
                        //User requests quit
                        if( e.type == SDL_QUIT )
                        {
                            quit = true;
                            cout << "QUIT" << endl;
                        }
                        if(mouse.getButtonDownLevel() == true)
                        {
                            cout << "DAY" << endl;
                            break;
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
                        }

                    }

                    if(start == true)
                    {

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
                        Figure.render(clipsIdle, clipsRun, clipsDie, clipsAttack, figureTexture,
                                      aRenderer, camera.x, camera.y, tileSet, TOTAL_TILES, textMenu, textMenuTexture, princessTexture, clipsPrincessRun);

                        if(Figure.getVictory() == false)
                        {
                            for(int i = 0; i < TOTAL_DRAGON; i++)
                            {
                                //Render ice bullet
                                iceDamage.moveIce(Figure, iceImageTexture, dragon[i], aRenderer, camera.x, camera.y, tileSet, TOTAL_TILES, TOTAL_DRAGON);
                                if(dragon[i].getBloodDragon() != 0 && checkCollision(camera, dragon[i].getBox()))
                                {
                                    dragon[i].render(fireDragonTexture, clipsDragon, aRenderer, camera.x, camera.y);
                                    dragon[i].fireMove(Figure, fireTexture, aRenderer, camera.x, camera.y, tileSet, TOTAL_TILES);
                                }
                            }

                        }

                        if(Figure.getVictory() == true)
                        {
                            victoryTexture.render(161,167,NULL, 0, NULL, SDL_FLIP_NONE, aRenderer);
                            textMenu[NEXT_LEVEL].setText(NEXT_LEVEL);
                            textMenu[NEXT_LEVEL].renderText(aRenderer, textMenuTexture[NEXT_LEVEL]);
                            nextLevelTexture.render(SCREEN_WIDTH - 75, SCREEN_HEIGHT - 35, NULL, 0, NULL, SDL_FLIP_NONE, aRenderer );
                        }

                        if(Figure.getStatus() == ANIMATION_STATUS_DIE)
                        {
                            defeatTexture.render(161,167,NULL, 0, NULL, SDL_FLIP_NONE, aRenderer);
                            textMenu[PLAY_AGAIN].setText(PLAY_AGAIN);
                            textMenu[PLAY_AGAIN].renderText(aRenderer, textMenuTexture[PLAY_AGAIN]);
                            levelAgainTexture.render(SCREEN_WIDTH - 75, SCREEN_HEIGHT - 35, NULL, 0, NULL, SDL_FLIP_NONE, aRenderer );
                        }
                    }
                    SDL_RenderPresent( aRenderer );
                }
                if(mouse.getNextLevel() == true)
                {
                    choose = choose + 1;
                }
            }
        }

        //Free resources and close SDL
        close(aWindow, aRenderer,figureTexture, wallTexture, floorTexture,lavaTexture, iceTexture,cakeTexture, aFont);

    }

	return 0;
}
