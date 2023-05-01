#ifndef SUPMAIN_H
#define SUPMAIN_H

#include <Game.h>

void khoitaoSDL(SDL_Window * &newWindow , SDL_Renderer * &newRender);

void thoatSDL(SDL_Window * &newWindow , SDL_Renderer * &newRender ) ;

void renderGamePlay( SDL_Renderer * &newRender, Game * &g) ;

pair<bool, bool> renderPreGame( SDL_Renderer * &newRender,  SDL_Event &e,  Game * &g);

void renderEndGame( int &finalScore, int &totalType,  int &slDie,  SDL_Renderer * &newRender , SDL_Event &e) ;

void solEvent( SDL_Event &e,bool & runGame, Game * &g);

#endif
