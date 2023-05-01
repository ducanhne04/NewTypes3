#include "supmain.h"

int main(int argc , char * argv[]){
    srand(time(0));

    SDL_Window * newWindow;
    SDL_Renderer * newRender;
    SDL_Event e;

    khoitaoSDL(newWindow, newRender);

    Game * g = new Game(newRender);

    pair<bool, bool> p = renderPreGame(newRender, e, g);
    if(p.first){
        bool runGame = 1;
        do{
            if(p.second) g->auto_adjust_mainCha();

            renderGamePlay(newRender, g);
            solEvent(e, runGame, g);

        }while(runGame && !( g->isGameOver() ));
    }

    g->mBg->stopMusic();
    renderEndGame(g->true_type, g->total_type, g->sl_die, newRender, e);

    g->~Game();
    thoatSDL(newWindow, newRender);

    return 0;
}
