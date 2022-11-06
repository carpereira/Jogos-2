#include <SDL2/SDL.h>
#include <stdlib.h>
#include "references.c"

int main (int argc, char* args[])
{
    /* INICIALIZACAO */
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window* win = SDL_CreateWindow("Hello World!",
                         SDL_WINDOWPOS_UNDEFINED,
                         SDL_WINDOWPOS_UNDEFINED,
                         600, 500, SDL_WINDOW_SHOWN
                      );
    SDL_Renderer* ren = SDL_CreateRenderer(win, -1, 0);
    
    /* EXECUÇÃO */
    SDL_SetRenderDrawColor(ren, 0xFF,0xFF,0xFF,0x00);
    SDL_RenderClear(ren);
    roundedBoxRGBA(ren, 100,50, 450,400, 10, COLOR_BLUE_TRELLO[0],COLOR_BLUE_TRELLO[1],COLOR_BLUE_TRELLO[2], MAX_ALPHA);
    roundedBoxRGBA(ren, 150,120, 250,320, 10, COLOR_WHITE[0],COLOR_WHITE[1],COLOR_WHITE[2], MAX_ALPHA);
    roundedBoxRGBA(ren, 300,120, 400,250, 10, COLOR_WHITE[0],COLOR_WHITE[1],COLOR_WHITE[2], MAX_ALPHA);
    SDL_RenderPresent(ren); 

    SDL_Delay(6000);

    /* FINALIZACAO */
    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    SDL_Quit();
}