#include <SDL2/SDL.h>
#include <stdlib.h>
#include "references.c"

int main (int argc, char* args[])
{
    /* INICIALIZACAO */
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window* win = SDL_CreateWindow("Exercício 3",
                         SDL_WINDOWPOS_UNDEFINED,
                         SDL_WINDOWPOS_UNDEFINED,
                         600, 500, SDL_WINDOW_SHOWN
                      );
    SDL_Renderer* ren = SDL_CreateRenderer(win, -1, 0);
    
    /* EXECUÇÃO */
    
    int counter = 10 * 20;
    int newAlpha = MAX_ALPHA;
    int alphaSign = 1;

    int positionSign = 1;
    int positionMod = 0;
    while (counter > 0) {
        SDL_SetRenderDrawColor(ren, 0xFF,0xFF,0xFF,0x00);
        SDL_RenderClear(ren);
        roundedBoxRGBA(ren, 100,50+positionMod, 450,400+positionMod, 10, COLOR_BLUE_TRELLO[0],COLOR_BLUE_TRELLO[1],COLOR_BLUE_TRELLO[2], MAX_ALPHA);
        roundedBoxRGBA(ren, 150,120+positionMod, 250,320+positionMod, 10, COLOR_WHITE[0],COLOR_WHITE[1],COLOR_WHITE[2], newAlpha);
        roundedBoxRGBA(ren, 300,120+positionMod, 400,250+positionMod, 10, COLOR_WHITE[0],COLOR_WHITE[1],COLOR_WHITE[2], newAlpha);
        SDL_RenderPresent(ren); 
        if(newAlpha >= MAX_ALPHA - 20){
            alphaSign = -1;
            newAlpha = MAX_ALPHA - 20;
        }
        if(newAlpha <= 20){
            alphaSign = 1;
            newAlpha = 20;
        }

        if(positionMod >= 100){
            positionSign = -1;
            positionMod = 100;
        }
        if(positionMod <= -100){
            positionSign = 1;
            positionMod = -100;
        }
        newAlpha = newAlpha + (alphaSign * 15);
        positionMod = positionMod + (positionSign * 5);
        SDL_Delay(50);
        counter--;
    }

    /* FINALIZACAO */
    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    SDL_Quit();
}
