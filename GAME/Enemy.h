//
// Created by massi on 10/10/2018.
//

#ifndef PROYECTO_ENEMY_H
#define PROYECTO_ENEMY_H

#include "AnimationController.h"

class Enemy {
    protected:
    int EnemyPosition;
    int EnemySpeed;
    int EnemyDirection;
    int EnemyHealth;
public:
    Enemy(int eposition, int espeed, int edirection, int ehealth);
    void DoFollowPlayer();
    void EnemyDamage();
    void EnemyDeath();

};


#endif //PROYECTO_ENEMY_H
