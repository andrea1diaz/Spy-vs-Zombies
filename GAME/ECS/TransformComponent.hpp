//
//  Position.hpp
//  GAME
//
//  Created by Andrea Diaz ♡ on 10/17/18.
//  Copyright © 2018 Andrea Diaz ♡. All rights reserved.
//

#ifndef Position_hpp
#define Position_hpp
#include "Components.hpp"
#include "../Vector2D.hpp"

class TransformComponent: public Component {
public:
    Vector2D position;
    Vector2D velocity;
    
    int speed = 3;
    int width = 67;
    int height = 95;
    float gravity = 0.1f;
    
    bool jump = false;
    bool moving = false;
    
    TransformComponent(){
        position.x = 0.0f;
        position.y = 0.0f;
    }
    
    TransformComponent(float x, float y) {
        position.x = x;
        position.y = y;
    }
    
    TransformComponent(float x, float y, int w, int h) {
        position.x = x;
        position.y = y;
        width = w;
        height = h;
    }
    
    void init() override {
        velocity.x = 0;
        velocity.y = 0;
    }
    
    void update() override {
        position.x += velocity.x * speed;
        position.y += velocity.y * speed;
        if (jump) {
            velocity.y += gravity * 1.3;
        }
    }
    
};
#endif /* Position_hpp */
