#ifndef PERSO_H
#define PERSO_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

// Define the Personne structure
typedef struct {
    SDL_Texture* image; // Player image as texture
    SDL_Rect position; // Player position
    SDL_Rect frame; // Current frame for animation
    int curframe; // Current animation frame
    int direction; // Direction of movement
    int previousmvt; // Previous movement (direction)
    int running; // Whether the player is running
    float v_x; // Horizontal velocity
    float v_grav; // Gravity effect
    float v_saut; // Jump velocity
    float v_y; // Vertical velocity
    int vitesse; // Speed of player
    int acceleration; // Speed increase rate
    int vie; // Player health
    int score; // Player score
} Personne;

void initPerso(Personne *p);
void initPerso2(Personne *p);
void afficherPerso(Personne p, SDL_Renderer *renderer);
void deplacerPerso(Personne *p, SDL_Renderer *renderer, int dt);
void deplacerPerso2(Personne *p, SDL_Renderer *renderer, int dt2);
void animerPerso(Personne *p);
void saut(Personne *p);
void vitesseUP(Personne *p);
void vitesseDOWN(Personne *p);

#endif // PERSO_H
