#include "load_camera.h"

void loadCamera(SDL_Rect& camera, Figure Figure, const int& LEVEL_WIDTH, const int& LEVEL_HEIGHT)
{
    //Center the camera over the figure
    camera.x = ( Figure.getBoxX() + Figure::FIGURE_WIDTH / 2 ) - SCREEN_WIDTH / 2;
    camera.y = ( Figure.getBoxY() + Figure::FIGURE_HEIGHT / 2 ) - SCREEN_HEIGHT / 2;

    //Keep the camera in bounds
    if( camera.x < 0 )
    {
        camera.x = 0;
    }
    if( camera.y < 0 )
    {
        camera.y = 0;
    }
    if( camera.x > LEVEL_WIDTH - camera.w )
    {
        camera.x = LEVEL_WIDTH - camera.w;
    }
    if( camera.y > LEVEL_HEIGHT - camera.h )
    {
        camera.y = LEVEL_HEIGHT - camera.h;
    }

}
