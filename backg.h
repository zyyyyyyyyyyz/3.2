#define CAMERA_W 800   ///// la largeur/hauteur du screen dans setvideomod
#define CAMERA_H 1200
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <time.h>


typedef struct
{
SDL_Surface *img_b;
SDL_Surface *img_b2;//surface taa background 
SDL_Rect position_b;//position p/r ecran taa back1 camera1        

SDL_Rect position_b2;//scroll taa back2     
//hetouma zouz kifkif (ta scroll)
SDL_Rect scroll; //scroll taa back1

Mix_Music *music;

SDL_Surface *crow[10];//tabelau de surface

SDL_Rect pos_camera2;  //pos back2 p/r ecran

SDL_Rect pos_crow;//pos aal ecran
SDL_Rect pos_crow2;
int num_animation;// indice taa tableau







}background;

void initialiser_background(background *b);
void afficher_background(background b, SDL_Surface *ecran,int numero);
void animerBackground(background *e,SDL_Surface *ecran,int numero);//
void scrolling(background *b,int dire,int *pasavancement,int numero);



