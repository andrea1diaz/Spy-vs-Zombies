//
//  KeyboardController.hpp
//  GAME
//
//  Created by Andrea Diaz ♡ on 11/5/18.
//  Copyright © 2018 Andrea Diaz ♡. All rights reserved.
//

#ifndef KeyboardController_hpp
#define KeyboardController_hpp

#include "../Game.h"
#include "ECS.hpp"
#include "Components.hpp"

class KeyboardController : public Component {
public:
    TransformComponent *transform;
    Sprite *animation;
    
    bool passLevel = true ;
    
    void init() override {
        transform  = &entity -> GetComponent<TransformComponent>();
        animation = &entity -> GetComponent<Sprite>();

    }
    
    void Hurt() {
        animation -> play("hurt");
    }
    
    void update() override {
        if (Game::event.type == SDL_KEYDOWN) {
            switch (Game::event.key.keysym.sym) {
                case SDLK_UP:
                    transform -> velocity.y = -4;
                    transform -> jump = true;
                    animation -> play("run");
                    break;
                    
                case SDLK_DOWN:
                    transform -> velocity.y = 1;
                    transform -> jump = false;
                    animation -> play("run");
                    break;
                    
                default:
                    break;
            }
        }
        
        if (Game::event.type == SDL_KEYUP) {
            switch (Game::event.key.keysym.sym) {
                case SDLK_UP:
                    if(transform -> velocity.y < -4) {
                        transform -> velocity.y = 0;
                        transform -> jump = false;
                        transform -> position.y = 295;
                    }
                    animation -> play("run");
                    break;
                    
                case SDLK_DOWN:
                    transform -> velocity.y = 0;
                    transform -> jump = false;
                    animation -> play("rest");
                    break;
                    
                default:
                    break;
            }
        }
    }
};
#endif /* KeyboardController_hpp */
