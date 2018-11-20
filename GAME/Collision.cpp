//
//  Collision.cpp
//  GAME
//
//  Created by Andrea Diaz ♡ on 11/5/18.
//  Copyright © 2018 Andrea Diaz ♡. All rights reserved.
//

#include "Collision.hpp"

bool Collision::AABB(const SDL_Rect& rectA, const SDL_Rect& rectB) {
    if ( rectA.x + rectA.w >= rectB.x &&
         rectB.x + rectB.w >= rectA.x &&
         rectA.y + rectA.h >= rectB.y &&
         rectB.y + rectB.h >= rectA.y) {
        
        return true;
    }
    
    return false;
}
