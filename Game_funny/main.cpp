#include "header.h"
#include "init_and_close.h"
#include "load_texture.h"
#include "figure.h"
#include "check_collision.h"
#include "load_camera.h"
#include "load_maze.h"
#include "ice.h"
int main( int argc, char* args[] )
{

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

    // Load wall, floor
    LTexture wallTexture;
    LTexture floorTexture;
    // Load lava, ice, cake
    LTexture lavaTexture;
    LTexture iceTexture;
    LTexture cakeTexture;
    // Image ice bullet
    LTexture iceImageTexture;

    // ice bullet damage
    LIce iceDamge;


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
		if( !loadMedia(aRenderer, figureTexture,wallTexture ,floorTexture, lavaTexture, iceTexture, cakeTexture, iceImageTexture, tileSet) )
		{
			cout << "Failed to load media!\n" ;
		}
		else
		{
		    // Load Rec Animation
		    loadRectAnimation(clipsIdle, clipsRun, clipsDie, clipsAttack);

			//Main loop flag
			bool quit = false;

             //Event handler
            SDL_Event e;

			//The figure that will be moving around on the screen
			Figure Figure;
            //cout << "Mo dau" << endl;

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
                        //cout << "Vao" << endl;
                    }
                    else
                    {
                        Figure.resetVel();
                    }
                    cout << "Figure.getStatus() = " << Figure.getStatus() << endl;
				}

				//Move the figure
                Figure.move(tileSet);

                //Load camera:
                loadCamera(camera, Figure);

				//Clear screen
				SDL_SetRenderDrawColor( aRenderer, 255, 255, 255, 255 );
				SDL_RenderClear( aRenderer );

                //Render level
				for( int i = 0; i < TOTAL_TILES; i++ )
				{
					tileSet[ i ]->render( camera, floorTexture, wallTexture, aRenderer,lavaTexture,iceTexture,cakeTexture );

				}

                //Render objects
				Figure.render(clipsIdle, clipsRun, clipsDie, clipsAttack, frameIdle, frameRun, frameDie, frameAttack, figureTexture, aRenderer, camera.x, camera.y);

                //Render ice bullet
                iceDamge.moveIce(Figure, iceImageTexture, aRenderer, camera.x, camera.y);

				//Update screen
				SDL_RenderPresent( aRenderer );


			}
		}
	}

	//Free resources and close SDL
	close(aWindow, aRenderer,figureTexture, wallTexture, floorTexture,lavaTexture, iceTexture,cakeTexture);

	return 0;
}
