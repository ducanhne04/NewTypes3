#include "enemy.h"

enemy::enemy(const string &text,SDL_Renderer * &newRender , TTF_Font * &newFont,mPoint &other, int &h2){
    a = new Dot(string(enemy_pic + char('0' + h2) + ".png"), other, newRender, BLACK.r, BLACK.g, BLACK.b);

    for(int i = 0;i < sl_bling;i ++)
        b[i] = new bling() , b[i]->render(newRender, other, 1);

    d = new LTexture(newRender, newFont);

    e = text;

    f = int(e.size());

    g = 0;

    h = 3 + h2 % 3;
}

enemy::~enemy(){
    a->~Dot();
    for(int i = 0 ; i < sl_bling;i ++)
        delete b[i];
    d->~LTexture();
    e = "" , f = g = h = 0;
}

void enemy::render(){
    a->render(0.0);

    for(int i = 0;i < sl_bling;i ++)
        b[i]->render(NULL, a->td, 0);

    if(e != ""){
        d->loadText(e, (f == int(e.size())) ? WHITE : YELLOW);
        d->render(a->td.x  , a->td.y + enemy_h ) ;
        d->~LTexture();
    }
}

void enemy::dichuyen(){
    if(a->td.y == 0){
        if(h == 0) h = 4;
        else if(h == 1) h = 3;
        else h = 5;
    }
    if(a->td.x == 0){
        if(h == 5) h = 3;
        else if(h == 6) h = 2;
        else h = 1;
    }
    if(a->td.x + enemy_w == SCREEN_WIDTH){
        if(h == 1) h = 7;
        else if(h == 2) h = 6;
        else h = 5;
    }
    if(a->td.y + enemy_h == SCREEN_HEIGHT){
        if(h == 3) h = 1;
        else if(h == 4) h = 0;
        else h = 7;
    }
    a->td.x += huong[h][0] , a->td.y += huong[h][1];

    a->td.x = max(0 , min(a->td.x , SCREEN_WIDTH - enemy_w));
    a->td.y = max(0, min(a->td.y, SCREEN_HEIGHT - enemy_h));
}

bool enemy::isDead(){
    return (g == f);
}

void enemy::playSound(){
    static LSound * amthanh = new LSound(enemy_sou);
    amthanh->playSound();
}
