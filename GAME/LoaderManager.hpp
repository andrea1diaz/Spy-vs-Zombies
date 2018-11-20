//
//  LoaderManager.hpp
//  GAME
//
//  Created by Andrea Diaz ♡ on 10/16/18.
//  Copyright © 2018 Andrea Diaz ♡. All rights reserved.
//

#ifndef LoaderManager_hpp
#define LoaderManager_hpp

#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include "Game.h"

class LoaderManager {
public:
    static SDL_Texture* LoadTexture(const char* file_name);
    static void Draw(SDL_Texture* tex, SDL_Rect src, SDL_Rect dst, SDL_RendererFlip flip);
    static void Delete(SDL_Texture* tex);
};



#endif /* LoaderManager_hpp */
