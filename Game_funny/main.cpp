
#include "header.h"
#include "init_and_close.h"
#include "load_texture.h"
#include "figure.h"
#include "check_collision.h"
#include "load_camera.h"

int main( int argc, char* args[] )
{

    //The window we'll be rendering to
    SDL_Window* aWindow = NULL;

    //The window renderer
    SDL_Renderer* aRenderer = NULL;

    // Figure
    LTexture figureTexture;

    // Maze map

    LTexture mazeMapTexture;

    //Idle animation
    SDL_Rect clipsIdle[ IDLE_ANIMATION_FRAMES ];

    //Run animation
    SDL_Rect clipsRun[ RUN_ANIMATION_FRAMES ];

    // Flip animation
    SDL_RendererFlip flipType = SDL_FLIP_NONE;

    //Current animation frame Idle
    int frameIdle = 0;

    //Current animation frame Run
    int frameRun = 0;

    // Idle or Moving
    bool moving = false;

	//Start up SDL and create window
	if( !init(aWindow, aRenderer) )
	{
		printf( "Failed to initialize!\n" );
	}
	else
	{
		//Load media
		if( !loadMedia(aRenderer, figureTexture, mazeMapTexture) )
		{
			printf( "Failed to load media!\n" );
		}
		else
		{
		    // Load Rec Animation
		    loadRectAnimation(clipsIdle, clipsRun);

			//Main loop flag
			bool quit = false;

             //Event handler
            SDL_Event e;

			//The figure that will be moving around on the screen
			Figure Figure;
            cout << "Mo dau" << endl;

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
					Figure.handleEvent(e, flipType, moving);
				}

                //Move the figure
				Figure.move();

                //Load camera:
                loadCamera(camera, Figure);

				//Clear screen
				SDL_SetRenderDrawColor( aRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
				SDL_RenderClear( aRenderer );

                //Render background
                mazeMapTexture.render(0, 0, &camera, 0, NULL, SDL_FLIP_NONE, aRenderer);

                //Render objects
				Figure.render(clipsIdle, clipsRun, frameIdle, frameRun, figureTexture, aRenderer, flipType, moving, camera.x, camera.y);

				//Update screen
				SDL_RenderPresent( aRenderer );

			}
		}
	}

	//Free resources and close SDL
	close(aWindow, aRenderer,figureTexture, mazeMapTexture);

	return 0;
}
