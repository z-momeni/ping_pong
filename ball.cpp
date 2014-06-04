#include "SDL/SDL.h"
#include <iostream>
#include <SDL/SDL_gfxPrimitives.h>
using namespace std;

SDL_Event event;

int main()
{
	SDL_Surface*screen=SDL_SetVideoMode(1200,800,32,0);
	int xa1=1170,xa2=1200,xb1=0,xb2=30;
	int x=10,y=10,dx=1,dy=1,j=50,ya1=200,ya2=350,yb1=200,yb2=350;
	int score_a=0,score_b=0;
	char running=true;
	boxRGBA(screen,xb1,yb1,xb2,yb2,100,132,219,255);
	boxRGBA(screen,xa1,ya1,xa2,ya2,100,132,219,255);
	while(running)
	{
		if (SDL_PollEvent(&event))
		{
			if(event.type==SDL_QUIT)
				return 0;
 			if(event.type==SDL_KEYDOWN)
			{
				if(event.key.keysym.sym == SDLK_UP && ya1>0)
				{
					 boxRGBA(screen,1170,ya1,1200,ya2,0,0,0,255);
					 ya1-=j;
					 ya2-=j;
					 boxRGBA(screen,1170,ya1,1200,ya2,100,132,219,255);
					 SDL_Flip(screen);
					 SDL_Delay(1);
				}
			        if(event.key.keysym.sym == SDLK_DOWN && ya2<800)
                                {
                                         boxRGBA(screen,1170,ya1,1200,ya2,0,0,0,255);
					 ya1+=j;
					 ya2+=j;
                                         boxRGBA(screen,1170,ya1,1200,ya2,100,132,219,255);
                                         SDL_Flip(screen);
                                         SDL_Delay(1);
                                }
                                if(event.key.keysym.sym == SDLK_s && yb2<800)
                                {
                                         boxRGBA(screen,0,yb1,30,yb2,0,0,0,255);
                                         yb1+=j;
                                         yb2+=j;
                                         boxRGBA(screen,0,yb1,30,yb2,100,132,219,255);
                                         SDL_Flip(screen);
                                         SDL_Delay(1);
                                }
                                if(event.key.keysym.sym == SDLK_w && yb1>0)
                                {
                                         boxRGBA(screen,0,yb1,30,yb2,0,0,0,255);
                                         yb1-=j;
                                         yb2-=j;
                                         boxRGBA(screen,0,yb1,30,yb2,100,132,219,255);
                                         SDL_Flip(screen);
                                         SDL_Delay(1);
                                }
			}
		}
		filledEllipseRGBA(screen,x,y,10,10,0,0,0,255);
		x+=dx;
		y+=dy;
		filledEllipseRGBA(screen,x,y,10,10,200,100,70,255);
		if ((x == xb2+10) && (y>yb1 && y < yb2))
		{
			dx*=-1;
			dy*=-1;
		}
		if ((x == xa1-10) && (y>ya1 && y < ya2))
		{
			dx*=-1;
			dy*=-1;
		}
		if (x==0 && (y>0 && y<800))
		{
			score_a+=1;
			cout<<"score_a : "<<score_a<<endl;
		}
		if (x==1200 && (y>0 && y<800))
		{
			score_b+=1;
			cout<<"score_b : "<<score_b<<endl;
		}
		if(x==0 || x==1200)
			dx *= -1;
		if(y==0 ||y==800)
			dy *= -1;
		if ((y==yb1-10 || y==yb2+10 ) && (x>0 && x<xb2))
		{
			dx*=-1;
			dy*=-1;
		}
		if ((y==ya1-10 || y==ya2+10) && (x<1200 && x>xa1))
		{
			dx*=-1;
			dy*=-1;
		}
		if (score_a == 11 || score_b == 11)
			running=false;
		SDL_Flip(screen);
		SDL_Delay(1);
	}
	if (score_a ==11)
		cout <<"winner is a"<<endl;
	if (score_b == 11)
		cout <<"winner is b"<<endl;
	SDL_Delay(5000);
	return 0;
}
