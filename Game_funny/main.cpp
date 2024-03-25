/*This source code copyrighted by Lazy Foo' Productions 2004-2024
and may not be redistributed without written permission.*/

#include "header.h"
#include "init_and_close.h"
#include "load_texture.h"
#include "figure.h"
#include "check_collision.h"

int main( int argc, char* args[] )
{

    //The window we'll be rendering to
    SDL_Window* gWindow = NULL;

    //The window renderer
    SDL_Renderer* gRenderer = NULL;

    // Figure
    LTexture figureTexture;

    //Idle animation
    SDL_Rect gSpriteClipsIdle[ IDLE_ANIMATION_FRAMES ];

    //Run animation
    SDL_Rect gSpriteClipsRun[ RUN_ANIMATION_FRAMES ];

    // Flip animation
    SDL_RendererFlip flipType = SDL_FLIP_NONE;

    //Current animation frame Idle
    int frameIdle = 0;

    //Current animation frame Run
    int frameRun = 0;

    // Idle or Moving
    bool moving = false;

	//Start up SDL and create window
	if( !init(gWindow, gRenderer) )
	{
		printf( "Failed to initialize!\n" );
	}
	else
	{
		//Load media
		if( !loadMedia(gRenderer, figureTexture, gSpriteClipsIdle, gSpriteClipsRun) )
		{
			printf( "Failed to load media!\n" );
		}
		else
		{
			//Main loop flag
			bool quit = false;

             //Event handler
            SDL_Event e;

			//The figure that will be moving around on the screen
			Figure Figure;
            cout << "Mo dau" << endl;
			//While application is running
			while( !quit )
			{
			    cout << "Chua quit" << endl;
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

				//Clear screen
				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
				SDL_RenderClear( gRenderer );

				//Render current frame
				//SDL_Rect* currentClip = &gSpriteClips[ frame / 2 ];
				//gSpriteSheetTexture.render( 0, 0, &gSpriteClips[ frame / 2 ], 0, NULL, SDL_FLIP_NONE, gRenderer  );

                //Render objects
				Figure.render(gSpriteClipsIdle, gSpriteClipsRun, frameIdle, frameRun, figureTexture, gRenderer, flipType, moving);

				//Update screen
				SDL_RenderPresent( gRenderer );

				if(moving == true)
                {
                    ++frameRun;
                    if(frameRun / 4 >= RUN_ANIMATION_FRAMES)
                    {
                        frameRun = 0;
                    }
                }
                else
                {
                    ++frameIdle;
                    if( frameIdle / 4 >= IDLE_ANIMATION_FRAMES )
                    {
                        frameIdle = 0;
                    }
                }
			}
		}
	}

	//Free resources and close SDL
	close(gWindow, gRenderer,figureTexture);

	return 0;
}

