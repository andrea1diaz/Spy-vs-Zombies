#include <iostream>
#include "Game.h"

Game *game = nullptr;

int main(int argc, char* args[]) {
    
    const int FPS = 60; //frames per second
    const int frame_delay = 1000 / FPS;
    
    Uint32 frame_start;
    int frame_time;
    
    game = new Game();
    
    game -> init("spy vs zombies", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 680, 480);
    
    while (game -> running()) {
        
        frame_start = SDL_GetTicks();
        
        game -> events();
        game -> update();
        game -> render();
        
        frame_time = SDL_GetTicks() - frame_start;
        
        if (frame_delay > frame_time) {
            SDL_Delay(frame_delay - frame_time);
        }
    }
    
    game -> clean();
    delete game;
    return 0;
}
