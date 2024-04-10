//#include "load_mouse.h"
//
//load_Mouse::load_Mouse()
//{
//    mBox = {0, 0, 0, 0};
//    mCurrentSprite = BUTTON_SPRITE_MOUSE_OUT;
//}
//
//void load_Mouse::setBoxMouse(int x, int y, int w, int h)
//{
//    mBox = {x, y, w, h};
//}
//
//void load_Mouse::handleEvent( SDL_Event* e )
//{
//    //If mouse event happened
//	if( e->type == SDL_MOUSEMOTION || e->type == SDL_MOUSEBUTTONDOWN || e->type == SDL_MOUSEBUTTONUP )
//	{
//		//Get mouse position
//		int x, y;
//		SDL_GetMouseState( &x, &y );
//
//        SDL_Point p = {x, y};
//
//		//Check if mouse is in button
//		bool inside = true;
//
//		if(SDL_PointInRect(&p, &this->mBox) == false)
//        {
//            inside = false;
//////        }
//		//Mouse is outside button
//		if( !inside )
//		{
//			mCurrentSprite = BUTTON_SPRITE_MOUSE_OUT;
//		}
//		//Mouse is inside button
//		else
//		{
//			//Set mouse over sprite
//			switch( e->type )
//			{
//				case SDL_MOUSEMOTION:
//				mCurrentSprite = BUTTON_SPRITE_MOUSE_OVER_MOTION;
//				break;
//
//				case SDL_MOUSEBUTTONDOWN:
//				mCurrentSprite = BUTTON_SPRITE_MOUSE_DOWN;
//				break;
//
//				case SDL_MOUSEBUTTONUP:
//				mCurrentSprite = BUTTON_SPRITE_MOUSE_UP;
//				break;
//			}
//		}
//	}
//}
//
//void render();
