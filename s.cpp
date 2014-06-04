#include "SDL/SDL.h"
#include <SDL/SDL_gfxPrimitives.h>

int main()
{
	SDL_Surface* screen = SDL_SetVideoMode(800,600,32,0);

	lineRGBA(screen,100,100,200,100,0,0,255,255);

	lineRGBA(screen,100,100,100,200,0,0,255,255);

	lineRGBA(screen,100,200,200,200,0,0,255,255);

	lineRGBA(screen,200,100,200,200,0,0,255,255);
	
	lineRGBA(screen,150,50,100,100,0,0,255,255);

	lineRGBA(screen,150,50,200,100,0,0,255,255);


	SDL_Flip(screen);

	SDL_Delay(10000);

	return 0;
}
