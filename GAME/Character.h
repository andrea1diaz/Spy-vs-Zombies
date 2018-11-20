//
// Created by massi on 10/10/2018.
//

#ifndef PROYECTO_PLAYER_H
#define PROYECTO_PLAYER_H

#include "Game.h"
#include "Weapon.h"
#include "ScoreManager.h"
#include "AnimationController.h"

class Character {
    private:
    int position_x;
    int position_y;
    int CharacterSpeed;
    int CharacterDirection;
    int CharacterHealth;
    
    SDL_Texture* texture;
    SDL_Rect srcRect, dstRect;
    
public:
    Character(const char* sheet, int x, int y);
    ~Character();
    
    void Update();
    void Render();
    
    
    void DoFire();
    void DoJump();
    void WeapReload();
    void CharacterDamage();
    void CharacterHealthIncrease();

};


#endif //PROYECTO_PLAYER_H
