//
//  Collision.hpp
//  GAME
//
//  Created by Andrea Diaz ♡ on 11/5/18.
//  Copyright © 2018 Andrea Diaz ♡. All rights reserved.
//

#ifndef Collision_hpp
#define Collision_hpp

#include <SDL2/SDL.h>

class Collision {
    
public:
    static bool AABB(const SDL_Rect &rectA, const SDL_Rect &rectB);
};

#endif /* Collision_hpp */
