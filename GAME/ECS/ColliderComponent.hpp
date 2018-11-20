//
//  ColliderComponent.hpp
//  GAME
//
//  Created by Andrea Diaz ♡ on 11/5/18.
//  Copyright © 2018 Andrea Diaz ♡. All rights reserved.
//

#ifndef ColliderComponent_hpp
#define ColliderComponent_hpp

#include <string>
#include <SDL2/SDL.h>

#include "Components.hpp"

class ColliderComponent : public Component {
public:
    SDL_Rect collider;
    std::string tag;
    
    TransformComponent* transform;
    
    ColliderComponent(std::string t) {
        tag = t;
    }
    
    void init() override {
        if (!entity -> HasComponent<TransformComponent>()) {
            entity -> add_component<TransformComponent>();
        }
        
        transform = &entity -> GetComponent<TransformComponent>();
    }
    
    void update() override {
        collider.x = static_cast<int>(transform -> position.x);
        collider.y = static_cast<int>(transform -> position.y);
        collider.w = transform -> width;
        collider.h = transform -> height;
    }
};
#endif /* ColliderComponent_hpp */
