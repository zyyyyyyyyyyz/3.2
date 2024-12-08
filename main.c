#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include <stdio.h>
#include "perso.h"
#include "collision.h"

// Declare the screen and renderer for SDL2
SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;

int main(int argc, char* argv[]) {
    // Initialize SDL2, SDL2_image, SDL2_ttf, SDL2_mixer
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER) != 0) {
        printf("SDL_Init Error: %s\n", SDL_GetError());
        return 1;
    }

    if (TTF_Init() == -1) {
        printf("SDL_ttf Initialization Error: %s\n", TTF_GetError());
        return 1;
    }

    if (Mix_Init(MIX_INIT_MP3 | MIX_INIT_OGG) != MIX_INIT_MP3) {
        printf("Mix_Init Error: %s\n", Mix_GetError());
        return 1;
    }

    if (Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096) == -1) {
        printf("Mix_OpenAudio Error: %s\n", Mix_GetError());
        return 1;
    }

    // Create SDL Window and Renderer
    window = SDL_CreateWindow("My Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!window || !renderer) {
        printf("Window or Renderer Creation Error: %s\n", SDL_GetError());
        return 1;
    }

    // Initialize Player
    Personne player1, player2;
    initPerso(&player1);
    initPerso2(&player2);

    // Main game loop
    int running = 1;
    while (running) {
        SDL_Event e;
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                running = 0;
            }
        }

        // Game logic: Handle player movement, etc.
        // For simplicity, assume dt is already set to proper direction (e.g., 1 for right, 2 for left)
        int dt = 1; // This should come from actual input like key states
        deplacerPerso(&player1, renderer, dt);
        deplacerPerso2(&player2, renderer, dt);

        // Clear the screen
        SDL_RenderClear(renderer);

        // Draw player
        afficherPerso(player1, renderer);
        afficherPerso(player2, renderer);

        // Present the renderer to the screen
        SDL_RenderPresent(renderer);

        // Delay to control frame rate
        SDL_Delay(16);  // Roughly 60 FPS
    }

    // Cleanup
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    Mix_Quit();
    TTF_Quit();
    SDL_Quit();

    return 0;
}
