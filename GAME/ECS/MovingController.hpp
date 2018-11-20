//
//  MovingController.hpp
//  GAME
//
//  Created by Andrea Diaz ♡ on 11/15/18.
//  Copyright © 2018 Andrea Diaz ♡. All rights reserved.
//

#ifndef MovingController_hpp
#define MovingController_hpp

#include "ECS.hpp"
#include "Components.hpp"

class MovingController: public Component {
public:
    TransformComponent *transform;
    Sprite *animation;
    
    bool moving = true;
    
    void init() override {
        transform  = &entity -> GetComponent<TransformComponent>();
        animation = &entity -> GetComponent<Sprite>();
        
    }
    
    void update() override {
        if (moving) {
            transform -> velocity.x = -0.9;
            if (transform -> position.x < 0) {
                transform -> position.x = 680;
            }
            
            animation -> play("walk");
            animation -> flip = SDL_FLIP_HORIZONTAL;
            
        }
    }
    
};

#endif /* MovingController_hpp */
