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
                         600, 400, SDL_WINDOW_SHOWN
                      );
    SDL_Renderer* ren = SDL_CreateRenderer(win, -1, 0);
    
    /* EXECUÇÃO */
    SDL_SetRenderDrawColor(ren, 0xFF,0xFF,0xFF,0x00);
    SDL_RenderClear(ren);

    for (int startingIdx = 0; startingIdx < MAX_STARTING_POINTS; startingIdx++) {
        int colorIdx = rand() % MAX_COLORS;
        int sizeIdx = rand() % MAX_SIZES;
        printf("=================== \n");
        printf("startingIdx: %d \n",startingIdx);
        printf("colorIdx: %d \n",colorIdx);
        printf("size: %d \n",sizeIdx);
        SDL_SetRenderDrawColor(ren, colors[colorIdx][0],colors[colorIdx][1],colors[colorIdx][2],0);
        if(sizes[sizeIdx][0] == sizes[sizeIdx][1]){
            SDL_RenderDrawPoint(ren, startingPoints[startingIdx][0], startingPoints[startingIdx][1]);
        } else if(sizes[sizeIdx][0] == 0 || sizes[sizeIdx][1] == 0){
             SDL_RenderDrawLine(ren, startingPoints[startingIdx][0], startingPoints[startingIdx][1], sizes[sizeIdx][0],sizes[sizeIdx][1]);
        } else {
            SDL_Rect r = { startingPoints[startingIdx][0], startingPoints[startingIdx][1], sizes[sizeIdx][0],sizes[sizeIdx][1] };
            SDL_RenderFillRect(ren, &r);    
        }
        SDL_RenderPresent(ren);        
    }

    SDL_Delay(6000);

    /* FINALIZACAO */
    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    SDL_Quit();
}
