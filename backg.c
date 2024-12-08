
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "backg.h"



void initialiser_background(background *b)
{
b->img_b=IMG_Load("day1 copie.jpg");
b->img_b2=IMG_Load("day1 copie.jpg");

b->position_b.x=0;
b->position_b.y=-1;

b->scroll.x=0;
b->scroll.y=0;
b->scroll.w=1200;
b->scroll.h=1200;




b->position_b2.x=0;
b->position_b2.y=0;
b->position_b2.h=1200;
b->position_b2.w=600;

b->pos_camera2.x=600;
b->pos_camera2.y=0;



/////animation

	b->pos_crow.x=0;
	b->pos_crow.y=50;

	
	b->pos_crow2.x=600;
	b->pos_crow2.y=50;



	b->num_animation=0;//indice

//n3abiw l tableau 
	b->crow[0]=IMG_Load("crow0.png");
	b->crow[1]=IMG_Load("crow1.png");
	b->crow[2]=IMG_Load("crow2.png");
	b->crow[3]=IMG_Load("crow3.png");
	b->crow[4]=IMG_Load("crow4.png");
	b->crow[5]=IMG_Load("crow5.png");
	b->crow[6]=IMG_Load("crow6.png");
	b->crow[7]=IMG_Load("crow7.png");
	b->crow[8]=IMG_Load("crow8.png");
	




}


void afficher_background(background b, SDL_Surface *ecran,int numero)
{

	SDL_BlitSurface(b.img_b,&b.scroll,ecran,NULL);//background orgl
	if(numero==2)
	SDL_BlitSurface(b.img_b2,&b.position_b2,ecran,&b.pos_camera2);
}



void scrolling(background *b, int dire , int *pasavancement,int numero)
{
	if(numero==1){
	 if(dire==1)//droite
	{
		b->scroll.x=*pasavancement;
	}	
	
	else if(dire==2)//gauche
	{	
		b->scroll.x=*pasavancement;						
	}
    

	else if(dire==3)//
	{
		
		b->scroll.y=-10;

		
	}

	else if (dire == 0)
	{
		b->scroll.y=+10;
              
	}

}
	if(numero==2){
		 if(dire==1)//droite
	{
		b->position_b2.x=*pasavancement;
	}	
	
	else if(dire==2)//gauche
	{	
		b->position_b2.x=*pasavancement;						
	}
    

	else if(dire==3)//
	{
		
		b->position_b2.y=-10;

		
	}

	else if (dire == 0)
	{
		b->position_b2.y=+10;
              
	}






}



	
}





void animerBackground(background *e,SDL_Surface *ecran,int numero){
if(numero==1){
for(int j=0;j<5;j++)
{	
switch (j)
{
case 0:
	
	e->img_b=IMG_Load("night copie.jpg");	
break;
case 1:
	
	e->img_b=IMG_Load("night1 copie.jpg");
case 2:
	
	e->img_b=IMG_Load("night2 copie.jpg");
break;
case 3:
	
	e->img_b=IMG_Load("night3 copie.jpg");
break;
case 4:
	
	e->img_b=IMG_Load("night4 copie.jpg");
break;

}
SDL_BlitSurface(e->img_b,&e->scroll,ecran,NULL);
SDL_Flip (ecran);
SDL_Delay(200);}}




else if(numero==2){
for(int j=0;j<5;j++)
{	
switch (j)
{
case 0:
	
	e->img_b2=IMG_Load("night copie.jpg");	
break;
case 1:
	
	e->img_b2=IMG_Load("night1 copie.jpg");
case 2:
	
	e->img_b2=IMG_Load("night2 copie.jpg");
break;
case 3:
	
	e->img_b2=IMG_Load("night3 copie.jpg");
break;
case 4:
	
	e->img_b2=IMG_Load("night4 copie.jpg");
break;

}
SDL_BlitSurface(e->img_b2,&e->position_b2,ecran,&e->pos_camera2);
SDL_Flip (ecran);
SDL_Delay(200);}


}






}


