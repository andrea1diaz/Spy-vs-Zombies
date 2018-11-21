//
// Created by massi on 10/6/2018.
//

#ifndef PROYECTO_GAME_H
#define PROYECTO_GAME_H


#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <iostream>

class Game {
protected:
    bool running_game;
    SDL_Window* window;
    int life = 6000;
    
public:
    static SDL_Renderer* renderer;
    static SDL_Event event;
    
    Game();
    ~Game();
    void init(const char* title, int x_pos, int y_pos, int width, int height);
    
    void GameStart();
    
    void events();
    void update(); //here is gonna be all the game objects ex. player and enemies
    void render();
    void clean();
    
    bool running(){
        return running_game;
    };
    bool loadMedia();
    
    void Hurt();
    void GameOver();
};


#endif //PROYECTO_GAME_H
