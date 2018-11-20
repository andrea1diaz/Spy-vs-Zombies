//
//  Sprite.hpp
//  GAME
//
//  Created by Andrea Diaz ♡ on 10/17/18.
//  Copyright © 2018 Andrea Diaz ♡. All rights reserved.
//

#ifndef Sprite_hpp
#define Sprite_hpp

#include <SDL2/SDL.h>
#include <map>

#include "Components.hpp"
#include "../LoaderManager.hpp"
#include "AnimationController.h"

class Sprite: public Component {
private:
    TransformComponent *transform;
    SDL_Texture *texture;
    //SDL_Rect srcRect, dstRec;
    
    bool animation = false;
    bool moving = false;
    int speed;
    
public:
    SDL_Rect srcRect, dstRec;
    int pos = 0;
    
    SDL_RendererFlip flip = SDL_FLIP_NONE;
    
    std::map<const char*, Animation> animations;
    
    Sprite() = default;
    
    Sprite(const char* path) {
        setTex(path);
    }
    
    Sprite(const char* path, bool animationStatus) {
        setTex(path);
        animation = animationStatus;
        
        Animation rest = Animation(0, 600);
        Animation run = Animation(1, 200);
        Animation walk = Animation(1, 400);
        Animation hurt = Animation(2,200);
        
        animations.emplace("rest", rest);
        animations.emplace("run", run);
        animations.emplace("walk", walk);
        animations.emplace("hurt", hurt);
        
        play("rest");
        
    }
    
    ~Sprite() {
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
            srcRect.x = (static_cast<int>((SDL_GetTicks()/ speed) % 2)) * srcRect.w;
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
#endif /* Sprite_hpp */
