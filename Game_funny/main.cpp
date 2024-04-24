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
    bool checkSound = true;
    string pathMaze;
    int LEVEL_WIDTH;
    int LEVEL_HEIGHT;
    int TOTAL_TILES;
    int TOTAL_DRAGON;

    //The window we'll be rendering to
    SDL_Window* aWindow = NULL;

    //The window renderer
    SDL_Renderer* aRenderer = NULL;

    //The music that will be played
    Mix_Music *soundTrackMusic = NULL;

    //The sound effects that will be used
    Mix_Chunk *iceDamageChuck = NULL;
    Mix_Chunk *fireDragonChuck = NULL;

    // Figure
    LTexture figureTexture[ANIMATION_STATUS_TOTAL];
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

    // sound on
    LTexture soundOnTexture;

    // sound off
    LTexture soundOffTexture;

    //Next level
    LTexture nextLevelTexture;

    //Again
    LTexture levelAgainTexture;

    //Home
    LTexture backHomeTexture;

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

    //used font
    TTF_Font* aFont = NULL;

    LText textMenu[TOTAL_TEXT];

    //Rendered texture
    LTexture textMenuTexture[TOTAL_TEXT];

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


    //Init window, renderer

    if(init(aWindow, aRenderer) == false)
    {
        return 1;
    }

    if(!loadSound(soundTrackMusic, iceDamageChuck, fireDragonChuck))
    {
        return 2;
    }

    if(!loadText(aRenderer,textMenuTexture, aFont))
    {
        return 2;
    }

    if( !loadMedia(aRenderer, figureTexture,wallTexture ,floorTexture, lavaTexture, iceTexture, cakeTexture, iceImageTexture,
     fireDragonTexture, fireTexture, startTexture, finishTexture, victoryTexture, defeatTexture, princessTexture, nextLevelTexture,
     menuTexture, arrowrightMenuTexture, arrowleftMenuTexture, levelAgainTexture, arrowdownMenuTexture, chooseLevelTexture,
     howToPlayTexture, backHomeTexture, soundOnTexture, soundOffTexture))
    {
        return 2;
    }


    while(choose <= TOTAL_LEVEL && quit == false)
    {
        loadLevel(choose, pathMaze, LEVEL_WIDTH, LEVEL_HEIGHT, TOTAL_TILES, TOTAL_DRAGON);

        //mouse
        load_Mouse mouse;

        // ice bullet damage
        LIce iceDamage;

        //fire dragon
        dragon dragon[TOTAL_DRAGON];
        //The level tiles
        Tile* tileSet[ TOTAL_TILES ];

        if( !setTiles( tileSet, TOTAL_TILES, LEVEL_WIDTH, LEVEL_HEIGHT, pathMaze ) )
        {
            cout << "Failed to load tile set!\n" ;
            return 2;
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
                //cout << "checkSound = " << checkSound << endl;
                makeSound(checkSound, soundTrackMusic);
                //cout << "Chua quit" << endl;
                //Handle events on queue
                while( SDL_PollEvent( &e ) != 0 )
                {
                    //cout << "checkSound = " << checkSound << endl;
                    mouse.handleEvent(e, Figure, arrowrightMenuRect, arrowleftMenuRect, aRenderer, start, checkChooseLevel, checkHowToPlay, quit,
                                      choose, arrowdownMenuRect, checkSound);
                    mouse.render(arrowrightMenuTexture, arrowleftMenuTexture, arrowrightMenuRect, arrowleftMenuRect, menuTexture,
                                 chooseLevelTexture, howToPlayTexture, aRenderer, start, quit, checkChooseLevel, checkHowToPlay,
                                 arrowdownMenuTexture, arrowdownMenuRect,checkSound, soundOnTexture, soundOffTexture);
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

                    backHomeTexture.render(SCREEN_WIDTH - 50, 20, NULL, 0, NULL, SDL_FLIP_NONE, aRenderer);

                    if(Figure.getVictory() == false)
                    {
                        for(int i = 0; i < TOTAL_DRAGON; i++)
                        {
                            //Render ice bullet
                            iceDamage.moveIce(Figure, iceImageTexture, dragon[i], aRenderer, camera.x, camera.y, tileSet,
                                              TOTAL_TILES, TOTAL_DRAGON, iceDamageChuck, checkSound);
                            if(dragon[i].getBloodDragon() != 0 && checkCollision(camera, dragon[i].getBox()))
                            {
                                dragon[i].render(fireDragonTexture, clipsDragon, aRenderer, camera.x, camera.y);
                                dragon[i].fireMove(Figure, fireTexture, aRenderer, camera.x, camera.y, tileSet, TOTAL_TILES, fireDragonChuck, checkSound);
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
    close(aWindow, aRenderer, aFont, soundTrackMusic, iceDamageChuck, fireDragonChuck);
	return 0;
}
