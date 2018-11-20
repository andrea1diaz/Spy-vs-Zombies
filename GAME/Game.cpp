//
// Created by massi on 10/6/2018.
//

#include "Game.h"
#include "LoaderManager.hpp"
#include "ECS/Components.hpp"
#include "Vector2D.hpp"
#include "Collision.hpp"

SDL_Renderer* Game::renderer = nullptr;

SDL_Event Game::event;

Manager manager;
auto& background_level(manager.addEntity());
auto& zombie(manager.addEntity());
auto& spy(manager.addEntity());
auto& hurt(manager.addEntity());
auto& floor_limit(manager.addEntity());
auto& game_start(manager.addEntity());
auto& game_over(manager.addEntity());


Game::Game() {}
Game::~Game() {}

void Game::init(const char *title, int x_pos, int y_pos, int width, int height) {
    
    int flags = 0;
    
    if (SDL_Init(SDL_INIT_VIDEO) == 0) {
        window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, flags);
        renderer = SDL_CreateRenderer(window, -1, 0);
        std::cout << "window created" << std::endl;
        
        if (renderer) {
            GameStart();
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); //window color
            background_level.add_component<TransformComponent>(0.0f, 0.0f, 680, 480);
            background_level.add_component<BackgroundController>("background.png", true);
            background_level.add_component<ScrollingController>();
            life = 4000;
        }
        
        running_game = true;
    }
    else {
        running_game = false;
        
    }
 
    // ------------------- P L A Y E R -------------------
    spy.add_component<TransformComponent>(286.0f, 295.0f);
    spy.add_component<Sprite>("spy.png", true);
    spy.add_component<KeyboardController>();
    spy.add_component<ColliderComponent>("player");
    
    // -------------------- E N E M Y --------------------
    zombie.add_component<TransformComponent>(600.f, 310.0f, 54, 81);
    zombie.add_component<Sprite>("zombie.png", true);
    zombie.add_component<MovingController>();
    zombie.add_component<ColliderComponent>("touched_zombie");
    
    // -------------------- F L O O R --------------------
    floor_limit.add_component<TransformComponent>(0.0f, 392.0f, 680, 88);
    floor_limit.add_component<Sprite>("floor.png");
    floor_limit.add_component<ColliderComponent>("floor_limit");
}


void Game::GameStart() {
    game_start.add_component<TransformComponent>(0.0f, 0.0f, 680, 480);
    game_start.add_component<Sprite>("title.png");
    game_start.add_component<KeyboardController>();
}


void Game::events() {
    SDL_PollEvent(&event);
    
    switch (event.type) {
        case SDL_QUIT:
            running_game = false;
            std::cout << "game quitted" << std::endl;
            break;
            
        default:
            break;
    }
}

void Game::update() {
    manager.refresh();
    manager.update();
    
    if (Collision::AABB(spy.GetComponent<ColliderComponent>().collider, floor_limit.GetComponent<ColliderComponent>().collider)) {
        spy.GetComponent<TransformComponent>().velocity * -1;
    }
    
    if (spy.GetComponent<TransformComponent>().position.y < 0) {
        spy.GetComponent<TransformComponent>().velocity * -5;
    }
    
    if (Collision::AABB(spy.GetComponent<ColliderComponent>().collider, zombie.GetComponent<ColliderComponent>().collider)) {
        spy.GetComponent<KeyboardController>().Hurt();
        Hurt();
    }
}

void Game::render() { //here you are gonna put the things you wanna show on the screen
    SDL_RenderClear(renderer);
    manager.draw();
    SDL_RenderPresent(renderer); //add things to window
}

void Game::clean() {
    std::cout << "game clean" << std::endl;
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}


void Game::Hurt() {
    life -= 50;
    
    if (life == 0) {
        GameOver();
    }
}


void Game::GameOver() {
    std::cout << "window #2 created" << std::endl;
    if (renderer) {
        game_over.add_component<TransformComponent>(0.0f, 0.0f, 680, 480);
        game_over.add_component<Sprite>("gameover.png");
        game_over.add_component<KeyboardController>();
    }
    life = 6000;
}
