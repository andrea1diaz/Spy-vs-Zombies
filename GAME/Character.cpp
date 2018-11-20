//
// Created by massi on 10/10/2018.
//

#include "Character.h"
#include "LoaderManager.hpp"

Character::Character(const char* texture_sheet, int x, int y) {
    texture = LoaderManager::LoadTexture(texture_sheet);
    
    position_x = x;
    position_y = y;
}

Character::~Character(){}

void Character::Update(){
    
    position_x ++;
    position_y ++;
    
    srcRect.w = 63;
    srcRect.h = 90;
    srcRect.x = 0;
    srcRect.y = 0;
    
    dstRect.x = position_x;
    dstRect.y = position_y;
    dstRect.w = srcRect.w;
    dstRect.h = srcRect.h;
    
}

void Character::Render() {
    
    SDL_RenderCopy(Game::renderer, texture, &srcRect, &dstRect);
}

void Character::DoFire() {

}

void Character::DoJump() {

}

void Character::WeapReload() {

}

void Character::CharacterDamage() {

}

void Character::CharacterHealthIncrease() {

}
