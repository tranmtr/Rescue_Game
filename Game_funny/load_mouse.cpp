#include "load_mouse.h"

load_Mouse::load_Mouse()
{
    startMenu = {257, 150, 111, 56};
    levelMenu = {258, 198, 102, 54};
    howToPlay = {208, 285, 214, 62};
    quitMenu  = {271, 364,  81, 51};
    nextMenu  = {SCREEN_WIDTH - 75, SCREEN_HEIGHT - 35, 75, 35};
    againMenu = {SCREEN_WIDTH - 75, SCREEN_HEIGHT - 35, 75, 35};
    someLevelsMenu[ 1 ] = {19, 137, 91, 33};
    someLevelsMenu[ 2 ] = {120, 137, 91, 33};
    someLevelsMenu[ 3 ] = {229, 137, 91, 33};
    someLevelsMenu[ 4 ] = {339, 137, 91, 33};
    someLevelsMenu[ 5 ] = {453, 137, 91, 33};

    someLevelsMenu[ 6 ] = {19, 211, 91, 33};
    someLevelsMenu[ 7 ] = {120, 211, 91, 33};
    someLevelsMenu[ 8 ] = {229, 211, 91, 33};
    someLevelsMenu[ 9 ] = {339, 211, 91, 33};
    someLevelsMenu[ 10 ] = {453, 211, 91, 33};

    someLevelsMenu[ 11 ] = {19, 283, 91, 33};
    someLevelsMenu[ 12 ] = {120, 283, 91, 33};
    someLevelsMenu[ 13 ] = {229, 283, 91, 33};
    someLevelsMenu[ 14 ] = {339, 283, 91, 33};
    someLevelsMenu[ 15 ] = {453, 283, 91, 33};

    buttonX = {0, 0, 50, 50};

    mCurrentSprite = BUTTON_SPRITE_MOUSE_OUT;
    nextLevel = false;
    rightLeft = false;
    levelAgain = false;
}

void load_Mouse::handleEvent( SDL_Event& e, Figure& Figure,  SDL_Rect& arrowrightMenuRect, SDL_Rect& arrowleftMenuRect,
                             SDL_Renderer*& aRenderer, bool& start, bool& checkChooseLevel, bool& checkHowToPlay, bool& quit )
{
    rightLeft = false ;
    //If mouse event happened
	if( e.type == SDL_MOUSEMOTION || e.type == SDL_MOUSEBUTTONDOWN || e.type == SDL_MOUSEBUTTONUP )
	{

		int x, y;
		SDL_GetMouseState( &x, &y );

        SDL_Point p = {x, y};

		bool inside = true;

		if(SDL_PointInRect(&p, &this->startMenu) == false && SDL_PointInRect(&p, &this->levelMenu) == false
            &&SDL_PointInRect(&p, &this->howToPlay) == false && SDL_PointInRect(&p, &this->quitMenu) == false
            && SDL_PointInRect(&p, &this->nextMenu) == false  && SDL_PointInRect(&p, &this->buttonX) == false)
        {
            bool check = false;
            for(int i = 1; i < TOTAL_LEVEL; i++)
            {
                if(SDL_PointInRect(&p, &this->someLevelsMenu[i]) == true)
                {
                    cout << "I = " << i << endl;
                    check = true; // o trong
                    break;
                }

            }
            if(check == false)
            {
                inside = false; // o ngoai
            }
        }
		//Mouse is outside button

		if( inside == false )
		{
			mCurrentSprite = BUTTON_SPRITE_MOUSE_OUT;
			cout << "O ngoai" << endl;
		}

		else
		{
		    cout << "o trong" << endl;
			switch( e.type )
			{
				case SDL_MOUSEMOTION:
				mCurrentSprite = BUTTON_SPRITE_MOUSE_OVER_MOTION;
				cout << "checkCHooseLevel = " << checkChooseLevel << endl;
                cout <<"HOW TO PLAY = " << checkHowToPlay << endl;
				if(checkChooseLevel == false && checkHowToPlay == false)
                {
                    if(SDL_PointInRect(&p, &this->startMenu) == true)
                    {
                        rightLeft = true;
                        arrowrightMenuRect = {257 - 45 + 10, 155,45,35};
                        arrowleftMenuRect  = {257 + 111 , 155,45,35};
                        cout << "start" << endl;
                    }
                    else if(SDL_PointInRect(&p, &this->levelMenu) == true)
                    {
                        rightLeft = true;
                        arrowrightMenuRect = {258 - 45 + 10, 198 + 20,45,35};
                        arrowleftMenuRect  = {258 + 102 , 198 + 20,45,35};
                        cout << "level " << endl;
                    }
                    else if(SDL_PointInRect(&p, &this->howToPlay) == true)
                    {
                        rightLeft = true;
                        arrowrightMenuRect = {208 - 45 , 285 + 10,45,35};
                        arrowleftMenuRect  = {208 + 214 , 285 + 10,45,35};
                        cout << "how to play" << endl;
                    }
                    else if(SDL_PointInRect(&p, &this->quitMenu) == true)
                    {
                        rightLeft = true;
                        arrowrightMenuRect = {271 - 45 + 5, 364 + 5,45,35};
                        arrowleftMenuRect  = {271 + 81 + 5, 364 + 5,45,35};
                        cout << "QUIT" << endl;
                    }
                }

				break;

				case SDL_MOUSEBUTTONDOWN:
				mCurrentSprite = BUTTON_SPRITE_MOUSE_DOWN;
				cout << "Nhan" << endl;
                cout << "checkCHooseLevel = " << checkChooseLevel << endl;
                cout <<"HOW TO PLAY = " << checkHowToPlay << endl;

				if(checkChooseLevel == false && checkHowToPlay == false)
                {
                    if(start == false)
                    {
                        if(SDL_PointInRect(&p, &this->startMenu) == true)
                        {
                            cout << "1" <<endl;
                            start = true;
                            if(Figure.getVictory() == true && SDL_PointInRect(&p, &this->nextMenu) == true)
                            {
                                this->nextLevel = true;
                            }
                            if(Figure.getStatus() == ANIMATION_STATUS_DIE && SDL_PointInRect(&p, &this->againMenu) == true)
                            {
                                this->levelAgain = true;
                            }
                        }
                        //cout << "Day" << endl;
                        else if(SDL_PointInRect(&p, &this->levelMenu) == true)
                        {
                            //cout << "vao" << endl;
                            checkChooseLevel = true;
                            //cout << "CHECK LEVEL = " << checkChooseLevel << endl;
                        }
                        else if(SDL_PointInRect(&p, &this->howToPlay) == true)
                        {
                            checkHowToPlay = true;
                        }
                        else if(SDL_PointInRect(&p, &this->quitMenu) == true)
                        {
                            quit = true;
                        }
                    }
                    if(start == true)
                    {
                        if(Figure.getVictory() == true && SDL_PointInRect(&p, &this->nextMenu) == true)
                        {
                            this->nextLevel = true;
                        }
                        else if(Figure.getStatus() == ANIMATION_STATUS_DIE && SDL_PointInRect(&p, &this->againMenu) == true)
                        {
                            this->levelAgain = true;
                        }
                    }
                }
                if(checkChooseLevel == true )
                {
                    cout << "Vao" << endl;
                    if(SDL_PointInRect(&p, &this->buttonX) == true)
                    {
                        checkChooseLevel = false;
                        cout << "LEVEL" << endl;
                    }
                }
                if(checkHowToPlay == true )
                {
                    if(SDL_PointInRect(&p, &this->buttonX) == true)
                    {
                        checkHowToPlay = false;
                        cout << "HOW" << endl;
                    }
                }
				break;

				case SDL_MOUSEBUTTONUP:
				mCurrentSprite = BUTTON_SPRITE_MOUSE_UP;
				break;
			}
		}
	}
	cout << "RightLeft = " << rightLeft << endl;
}

void load_Mouse::render(LTexture& arrowrightMenuTexture, LTexture& arrowleftMenuTexture, SDL_Rect& arrowrightMenuRect,
                        SDL_Rect& arrowleftMenuRect, LTexture& menuTexture, LTexture& chooseLevelTexture, LTexture& howToPlayTexture,
                        SDL_Renderer*& aRenderer, const bool& start, const bool& quit, const bool& checkChooseLevel, const bool& checkHowToPlay)
{
    //cout << "LLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLll" << endl;
    if(checkChooseLevel == false && checkHowToPlay == false && start == false )
    {
        cout << "IN MENU" << endl << endl;;
        menuTexture.render(0, 0, NULL, 0, NULL, SDL_FLIP_NONE, aRenderer);
        if(this->rightLeft == true)
        {
            arrowrightMenuTexture.render(arrowrightMenuRect.x, arrowrightMenuRect.y, NULL, 0, NULL, SDL_FLIP_NONE, aRenderer);
            arrowleftMenuTexture.render(arrowleftMenuRect.x, arrowleftMenuRect.y, NULL, 0, NULL, SDL_FLIP_NONE, aRenderer);
        }
    }
    else if(checkChooseLevel == true)
    {
        //cout << "IN LEVEL" << endl;
        chooseLevelTexture.render(0, 0, NULL, 0, NULL, SDL_FLIP_NONE, aRenderer);
    }
    else if(checkHowToPlay == true)
    {
        //cout << "IN HOW" << endl;
        howToPlayTexture.render(0, 0, NULL, 0, NULL, SDL_FLIP_NONE, aRenderer);
    }
}

bool load_Mouse::getNextLevel()
{
    return this->nextLevel;
}
bool load_Mouse::getLevelAgain()
{
    return this->levelAgain;
}
