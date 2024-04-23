#pragma once

#include"header.h"
#include"load_texture.h"
#include"figure.h"

class load_Mouse
{
    public:
        load_Mouse();

        void handleEvent( SDL_Event& e, Figure& Figure, SDL_Rect& arrowrightMenuRect, SDL_Rect& arrowleftMenuRect,
                         SDL_Renderer*& aRenderer, bool& start, bool& checkChooseLevel, bool& checkHowToPlay,
                         bool& quit, int& choose, SDL_Rect& arrowdownMenuRect );

        void render(LTexture& arrowrightMenuTexture, LTexture& arrowleftMenuTexture, SDL_Rect& arrowrightMenuRect,
                    SDL_Rect& arrowleftMenuRect, LTexture& menuTexture, LTexture& chooseLevelTexture, LTexture& howToPlayTexture, SDL_Renderer*& aRenderer,
                    const bool& start, const bool& quit, const bool& checkChooseLevel, const bool& checkHowToPlay,
                    LTexture& arrowdownMenuTexture, SDL_Rect& arrowdownMenuRect);

        bool getNextLevel();

        bool getLevelAgain();

        bool getButtonDownLevel();

        void setButtonDownLevel();

    private:
        SDL_Rect startMenu, levelMenu, howToPlay, quitMenu, nextMenu, againMenu, buttonX, backHome;

        SDL_Rect someLevelsMenu[TOTAL_LEVEL + 1];

		int mCurrentSprite;

		bool nextLevel;

		bool levelAgain;

		bool rightLeft;

		bool checkButtonDownLevel;

};
