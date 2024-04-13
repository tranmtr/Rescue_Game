#pragma once

#include"header.h"
#include"load_texture.h"
#include"figure.h"

class load_Mouse
{
    public:
        load_Mouse();

        void handleEvent( SDL_Event& e, Figure& Figure, SDL_Rect& arrowrightMenuRect, SDL_Rect& arrowleftMenuRect, SDL_Renderer*& aRenderer, bool& start );

        void render(LTexture& arrowrightMenuTexture, LTexture& arrowleftMenuTexture, SDL_Rect& arrowrightMenuRect, SDL_Rect& arrowleftMenuRect, SDL_Renderer*& aRenderer);

        bool getNextLevel();

        bool getLevelAgain();

    private:
        SDL_Rect startMenu, levelMenu, howToPlay, quitMenu, nextMenu, againMenu;

		int mCurrentSprite;

		bool nextLevel;

		bool levelAgain;

		bool rightLeft;

};
