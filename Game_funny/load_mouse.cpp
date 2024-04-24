#include "load_mouse.h"

load_Mouse::load_Mouse()
{
    startMenu = {257, 150, 111, 56};
    levelMenu = {258, 198, 102, 54};
    howToPlay = {208, 285, 214, 62};
    quitMenu  = {271, 364,  81, 51};
    soundHome = {0, 0, 50, 50};
    nextMenu  = {SCREEN_WIDTH - 75, SCREEN_HEIGHT - 35, 75, 35};
    againMenu = {SCREEN_WIDTH - 75, SCREEN_HEIGHT - 35, 75, 35};


    someLevelsMenu[ 1 ] = {64, 184, 91, 33};
    someLevelsMenu[ 2 ] = {165, 184, 91, 33};
    someLevelsMenu[ 3 ] = {274, 184, 91, 33};
    someLevelsMenu[ 4 ] = {384, 184, 91, 33};
    someLevelsMenu[ 5 ] = {496, 184, 91, 33};

    someLevelsMenu[ 6 ] = {64, 258, 91, 33};
    someLevelsMenu[ 7 ] = {165, 258, 91, 33};
    someLevelsMenu[ 8 ] = {274, 258, 91, 33};
    someLevelsMenu[ 9 ] = {384, 258, 91, 33};
    someLevelsMenu[ 10 ] = {496, 258, 91, 33};

    someLevelsMenu[ 11 ] = {64, 328, 91, 33};
    someLevelsMenu[ 12 ] = {165, 328, 91, 33};
    someLevelsMenu[ 13 ] = {274, 328, 91, 33};
    someLevelsMenu[ 14 ] = {384, 328, 91, 33};
    someLevelsMenu[ 15 ] = {496, 328, 91, 33};

    buttonX = {568, 47, 25, 25};

    backHome = {SCREEN_WIDTH - 50, 20, 32, 32};

    mCurrentSprite = BUTTON_SPRITE_MOUSE_OUT;
    nextLevel = false;
    rightLeft = false;
    levelAgain = false;
    checkButtonDownLevel = false;

}

void load_Mouse::handleEvent( SDL_Event& e, Figure& Figure,  SDL_Rect& arrowrightMenuRect, SDL_Rect& arrowleftMenuRect,
                             SDL_Renderer*& aRenderer, bool& start, bool& checkChooseLevel, bool& checkHowToPlay, bool& quit,
                             int& choose, SDL_Rect& arrowdownMenuRect, bool& checkSound )
{
    arrowdownMenuRect.x = someLevelsMenu[choose].x + 15;
    arrowdownMenuRect.y = someLevelsMenu[choose].y - 35;
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
            && SDL_PointInRect(&p, &this->nextMenu) == false  && SDL_PointInRect(&p, &this->buttonX) == false
            && SDL_PointInRect(&p, &this->backHome) == false && SDL_PointInRect(&p, &this->soundHome) == false)
        {
            //cout << "LLLLLLLLLLLLLLLLLLLLLLLLLL" << endl;
            bool check = false;
            for(int i = 1; i <= TOTAL_LEVEL; i++)
            {
                //cout << "OOOOO = " << i << endl;
                //cout << this->someLevelsMenu[15].x << ' ' << this->someLevelsMenu[15].y << ' ' << this->someLevelsMenu[15].w <<" "<< this->someLevelsMenu[15].h<< endl;

                if(SDL_PointInRect(&p, &this->someLevelsMenu[i]) == true)
                {
                    //cout << "I = " << i << endl;
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
			//cout << "O ngoai" << endl;
		}

		else
		{
		    //cout << "checkChooseLevel = " << checkChooseLevel << endl;
		    //cout << "o trong" << endl;
			switch( e.type )
			{
				case SDL_MOUSEMOTION:
				mCurrentSprite = BUTTON_SPRITE_MOUSE_OVER_MOTION;
				//cout << "checkCHooseLevel = " << checkChooseLevel << endl;
                //cout <<"HOW TO PLAY = " << checkHowToPlay << endl;
				if(checkChooseLevel == false && checkHowToPlay == false)
                {
                    if(SDL_PointInRect(&p, &this->startMenu) == true)
                    {
                        rightLeft = true;
                        arrowrightMenuRect = {222, 155, 45, 35};
                        arrowleftMenuRect  = {368 , 155, 45, 35};
                        //cout << "start" << endl;
                    }
                    else if(SDL_PointInRect(&p, &this->levelMenu) == true)
                    {
                        rightLeft = true;
                        arrowrightMenuRect = {223, 218, 45, 35};
                        arrowleftMenuRect  = {360, 218, 45, 35};
                        //cout << "level " << endl;
                    }
                    else if(SDL_PointInRect(&p, &this->howToPlay) == true)
                    {
                        rightLeft = true;
                        arrowrightMenuRect = {163, 295, 45, 35};
                        arrowleftMenuRect  = {422, 295, 45, 35};
                        //cout << "how to play" << endl;
                    }
                    else if(SDL_PointInRect(&p, &this->quitMenu) == true)
                    {
                        rightLeft = true;
                        arrowrightMenuRect = {231, 369, 45, 35};
                        arrowleftMenuRect  = {357, 369, 45, 35};
                        //cout << "QUIT" << endl;
                    }
                }

				break;

				case SDL_MOUSEBUTTONDOWN:
				mCurrentSprite = BUTTON_SPRITE_MOUSE_DOWN;

				if(checkChooseLevel == false && checkHowToPlay == false)
                {
                    if(start == false)
                    {
                        cout << "START FALSE" << endl;
                        if(SDL_PointInRect(&p, &this->startMenu) == true)
                        {
                            //cout << "1" <<endl;
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
                        if(SDL_PointInRect(&p, &this->soundHome) == true)
                        {
                            if(checkSound == true)
                            {
                                checkSound = false;
                            }
                            else
                            {
                                checkSound = true;
                            }
                        }
                    }
                    if(start == true)
                    {
                        cout << "START TRUE" << endl;
                        if(Figure.getVictory() == true && SDL_PointInRect(&p, &this->nextMenu) == true)
                        {
                            //cout << "Ne " << endl;
                            this->nextLevel = true;
                        }
                        else if(Figure.getStatus() == ANIMATION_STATUS_DIE && SDL_PointInRect(&p, &this->againMenu) == true)
                        {
                            this->levelAgain = true;
                        }
                        if(SDL_PointInRect(&p, &this->backHome) == true)
                        {
                            start = false;
                            //cout << "HEHE" << endl;
                        }
                    }
                }
                else if(checkChooseLevel == true )
                {
                    //cout << "Nhan Vao" << endl;

                    if(SDL_PointInRect(&p, &this->buttonX) == true)
                    {
                        checkChooseLevel = false;
                        //cout << "LEVEL" << endl;
                    }
                    else
                    {
                        for(int i = 1; i <= TOTAL_LEVEL ; i++)
                        {
                            //cout << "IIII = " << i << endl;
                            //cout << p.x <<  " " << p.y << endl;
                            if(SDL_PointInRect(&p, &this->someLevelsMenu[i]) == true)
                            {
                                cout << "ne i = " << i << endl;
                                choose = i;
                                //cout << p.x <<  " " << p.y << endl;
                                //arrowdownMenuRect.x = someLevelsMenu[i].x + (someLevelsMenu[i].w)/2 ;
                                //arrowdownMenuRect.y = someLevelsMenu[i].y - arrowdownMenuRect.h;
                                this->checkButtonDownLevel = true;
                                start = true;
                                checkChooseLevel = false;
                                break;
                            }
                        }
                    }
                }
                else if(checkHowToPlay == true )
                {
                    if(SDL_PointInRect(&p, &this->buttonX) == true)
                    {
                        checkHowToPlay = false;
                        //cout << "HOW" << endl;
                    }
                }
				break;

				case SDL_MOUSEBUTTONUP:
				mCurrentSprite = BUTTON_SPRITE_MOUSE_UP;
				break;
			}
		}
	}
	//cout << "RightLeft = " << rightLeft << endl;
}

void load_Mouse::render(LTexture& arrowrightMenuTexture, LTexture& arrowleftMenuTexture, SDL_Rect& arrowrightMenuRect,
                        SDL_Rect& arrowleftMenuRect, LTexture& menuTexture, LTexture& chooseLevelTexture, LTexture& howToPlayTexture,
                        SDL_Renderer*& aRenderer, const bool& start, const bool& quit, const bool& checkChooseLevel,
                        const bool& checkHowToPlay, LTexture& arrowdownMenuTexture, SDL_Rect& arrowdownMenuRect,
                        bool& checkSound, LTexture& soundOnTexture, LTexture& soundOffTexture)
{
    //cout << "LLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLll" << endl;
    if(checkChooseLevel == false && checkHowToPlay == false && start == false )
    {
        //cout << "IN MENU" << endl << endl;;
        menuTexture.render(0, 0, NULL, 0, NULL, SDL_FLIP_NONE, aRenderer);
        if(this->rightLeft == true)
        {
            arrowrightMenuTexture.render(arrowrightMenuRect.x, arrowrightMenuRect.y, NULL, 0, NULL, SDL_FLIP_NONE, aRenderer);
            arrowleftMenuTexture.render(arrowleftMenuRect.x, arrowleftMenuRect.y, NULL, 0, NULL, SDL_FLIP_NONE, aRenderer);
        }
        if(checkSound == true)
        {
            soundOnTexture.render(0, 0, NULL, 0, NULL, SDL_FLIP_NONE, aRenderer);
        }

        else
        {
            //cout << "NE" << endl;
            soundOffTexture.render(0, 0, NULL, 0, NULL, SDL_FLIP_NONE, aRenderer);
        }
    }
    else if(checkChooseLevel == true)
    {
        //cout << "IN LEVEL" << endl;
        chooseLevelTexture.render(45, 47, NULL, 0, NULL, SDL_FLIP_NONE, aRenderer);
        arrowdownMenuTexture.render(arrowdownMenuRect.x, arrowdownMenuRect.y, NULL, 0, NULL, SDL_FLIP_NONE, aRenderer);
    }
    else if(checkHowToPlay == true)
    {
        //cout << "IN HOW" << endl;
        howToPlayTexture.render(45, 47, NULL, 0, NULL, SDL_FLIP_NONE, aRenderer);
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

bool load_Mouse::getButtonDownLevel()
{
    return this->checkButtonDownLevel;
}

void load_Mouse::setButtonDownLevel()
{
    this->checkButtonDownLevel = false;
}
