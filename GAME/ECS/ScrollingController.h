//
//  LevelController.h
//  GAME
//
//  Created by Andrea Diaz ♡ on 11/16/18.
//  Copyright © 2018 Andrea Diaz ♡. All rights reserved.
//

#ifndef ScrollingController_h
#define ScrollingController_h

#include "ECS.hpp"
#include "Components.hpp"

class ScrollingController: public Component {
public:
    TransformComponent *transform;
    BackgroundController *animation;
    
    bool moving = true;
    
    void init() override {
        transform = &entity -> GetComponent<TransformComponent>();
        animation = &entity -> GetComponent<BackgroundController>();
    }
    
    void update() override {
        if (moving) {
            animation -> play("scrolling");
        }
    }
};

#endif /* ScrollingController_h */
