//
//  LoaderManager.cpp
//  GAME
//
//  Created by Andrea Diaz ♡ on 10/16/18.
//  Copyright © 2018 Andrea Diaz ♡. All rights reserved.
//

#include "LoaderManager.hpp"

SDL_Texture* LoaderManager::LoadTexture(const char* texture) {
    SDL_Surface* temp_surface = IMG_Load(texture);
    SDL_Texture* new_texture = SDL_CreateTextureFromSurface(Game::renderer, temp_surface);
    SDL_FreeSurface(temp_surface);

    return new_texture;
}

void LoaderManager::Draw(SDL_Texture *tex, SDL_Rect src, SDL_Rect dst, SDL_RendererFlip flip) {
    SDL_RenderCopyEx(Game::renderer, tex, &src, &dst, NULL, NULL, flip);
}

void LoaderManager::Delete(SDL_Texture *tex) {
    SDL_DestroyTexture(tex);
}
