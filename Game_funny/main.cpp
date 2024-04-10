#include "header.h"
#include "init_and_close.h"
#include "load_texture.h"
#include "figure.h"
#include "check_collision.h"
#include "load_camera.h"
#include "load_maze.h"
#include "ice.h"
#include "dragon.h"
int main( int argc, char* args[] )
{

    //The dimensions of the level
//    int LEVEL_WIDTH = /*34*/22*80;
//    int LEVEL_HEIGHT = 33*80;
//    int TOTAL_TILES = 22*33;

    string pathMaze;
    srand(time(0));
    int choose;
    cout << "Hay chon me cung muon choi : " ;
    choose = rand()%2 + 1;

    int LEVEL_WIDTH = 22*80;
    int LEVEL_HEIGHT = 33*80;
    int TOTAL_TILES = 22*33;
    pathMaze = "secondmap.txt";

    if(choose == 1)
    {
        pathMaze = "firstmap.txt";
        LEVEL_WIDTH = 34*80;
        LEVEL_HEIGHT = 33*80;
        TOTAL_TILES = 34*33;
    }
    else if(choose == 2)
    {
        pathMaze = "secondmap.txt";
        LEVEL_WIDTH = 22*80;
        LEVEL_HEIGHT = 33*80;
        TOTAL_TILES = 22*33;
    }

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
                 fireDragonTexture, fireTexture, tileSet, TOTAL_TILES, LEVEL_WIDTH, LEVEL_HEIGHT, pathMaze) )
		{
			cout << "Failed to load media!\n" ;
		}
		else
		{
		    // Load Rec Animation
		    loadRectAnimation(clipsIdle, clipsRun, clipsDie, clipsAttack, clipsDragon);

			//Main loop flag
			bool quit = false;

             //Event handler
            SDL_Event e;

			//The figure that will be moving around on the screen
			Figure Figure;
            //cout << "Mo dau" << endl;

            Figure.setBoxFigure(choose);

            //The camera area
			SDL_Rect camera = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };

			//While application is running
			while( !quit )
			{
			    //cout << "Chua quit" << endl;
				//Handle events on queue
				while( SDL_PollEvent( &e ) != 0 )
				{
					//User requests quit
					if( e.type == SDL_QUIT )
					{
						quit = true;
					}
					if(Figure.getStatus() != ANIMATION_STATUS_DIE)
                    {
                        Figure.handleEvent(e);
                        cout << "Vao" << endl;
                    }
                    else
                    {
                        Figure.resetVel();
                    }
                    cout << "Figure.getStatus() = " << Figure.getStatus() << endl;
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
					tileSet[ i ]->render( camera, floorTexture, wallTexture, aRenderer,lavaTexture,iceTexture,cakeTexture );
				}

				setDragon(tileSet, dragon, TOTAL_TILES);

                //Render objects
				Figure.render(clipsIdle, clipsRun, clipsDie, clipsAttack, frameIdle, frameRun, frameDie, frameAttack, figureTexture, aRenderer, camera.x, camera.y);


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

				SDL_RenderPresent( aRenderer );
			}
		}
	}

	//Free resources and close SDL
	close(aWindow, aRenderer,figureTexture, wallTexture, floorTexture,lavaTexture, iceTexture,cakeTexture);

	return 0;
}
