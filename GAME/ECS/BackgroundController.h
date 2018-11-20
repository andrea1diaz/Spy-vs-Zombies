//
//  BackgroundController.h
//  GAME
//
//  Created by Andrea Diaz ♡ on 11/16/18.
//  Copyright © 2018 Andrea Diaz ♡. All rights reserved.
//

#ifndef BackgroundController_h
#define BackgroundController_h

#include <SDL2/SDL.h>
#include <map>

#include "Components.hpp"
#include "../LoaderManager.hpp"
#include "AnimationController.h"

class BackgroundController: public Component {
private:
    TransformComponent *transform;
    SDL_Texture *texture;
    
    bool animation = false;
    int speed;
    int scroll = 2;
    
public:
    SDL_Rect srcRect, dstRec;
    int pos = 0;
    
    SDL_RendererFlip flip = SDL_FLIP_NONE;
    
    std::map<const char*, Animation> animations;
    
    BackgroundController() = default;
    
    BackgroundController(const char* path, bool animationStatus) {
        setTex(path);
        animation = animationStatus;
        
        Animation scrolling = Animation(0, 1000);
        
        animations.emplace("scrolling", scrolling);
        
        play("scrolling");
        
    }
    
    ~BackgroundController() {
        SDL_DestroyTexture(texture);
    }
    
    
    void setTex(const char* path) {
        texture = LoaderManager::LoadTexture(path);
    }
    
    void init() override {
        transform = &entity -> GetComponent<TransformComponent>();
        
        srcRect.x = 0;
        srcRect.y = 0;
        srcRect.w = transform -> width;
        srcRect.h = transform -> height;
    }
    
    void update() override {
        if (animation) {
            srcRect.x += scroll;
            if(srcRect.x > 680) {
                srcRect.x = 0;
            }

        }
        
        srcRect.y = pos * transform -> height;
        dstRec.x = (int)transform -> position.x;
        dstRec.y = (int)transform -> position.y;
        dstRec.w = transform -> width;
        dstRec.h = transform -> height;
    }
    
    void draw() override {
        LoaderManager::Draw(texture, srcRect, dstRec, flip);
    }
    
    void play(const char* name) {
        pos = animations[name].index;
        speed = animations[name].speed;
    }
    
    
    
};

#endif /* BackgroundController_h */
