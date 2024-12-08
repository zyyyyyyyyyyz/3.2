#include "perso.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

void initPerso(Personne *p) {
    p->image = IMG_LoadTexture(renderer, "perso.png");
    p->position.x = 0;
    p->position.y = 520;
    p->frame.w = 100;
    p->frame.h = 100;
    p->frame.x = 0;
    p->frame.y = 0;
    p->curframe = 0;
    p->running = 1;
    p->direction = 0;
    p->previousmvt = 0;
    p->v_x = 4;
    p->v_grav = 0.3;
    p->v_saut = -6.5;
    p->v_y = p->v_saut;
    p->acceleration = 1;
    p->vitesse = 0;
}

void afficherPerso(Personne p, SDL_Renderer *renderer) {
    SDL_RenderCopy(renderer, p.image, &p.frame, &p.position);
}

void deplacerPerso(Personne *p, SDL_Renderer *renderer, int dt) {
    if (dt == 1) {
        p->position.x += p->vitesse;
    } else if (dt == 2) {
        p->position.x -= p->vitesse;
    } else if (dt == 0) {
        while (p->position.y < 520) {
            p->position.y += 3;
        }
    } else if (dt == 3) {
        p->position.y -= 2;
    }
    animerPerso(p);
}

void animerPerso(Personne *p) {
    if (p->direction == 1) {
        p->frame.y = 0;
        p->curframe++;
        if (p->curframe >= 4) {
            p->curframe = 0;
        }
        p->frame.x = p->curframe * p->frame.w;
    } else if (p->direction == 2) {
        p->frame.y = 100;
        p->curframe++;
        if (p->curframe >= 4) {
            p->curframe = 0;
        }
        p->frame.x = p->curframe * p->frame.w;
    } else if (p->direction == 0) {
        p->frame.x = 0;
    }
}
