#include "mainCharacter.h"

mainCha::mainCha(SDL_Renderer * &newRender, mPoint &other){
    a = new Dot(main_pic, other, newRender, BLACK.r, BLACK.g, BLACK.b);
    other.x = a->td.x + main_w / 2 , other.y = a->td.y + main_h / 2 ;
    for(int i = 0;i < sl_bullet;i ++)
       b[i] = new bullet(newRender, other) , chuaBan.push_back(i);
}

mainCha::~mainCha(){
    a->~Dot();
    for(int i = 0;i < sl_bullet;i ++)
        b[i]->~bullet();
    chuaBan.clear() ;
}

void mainCha::dichuyen(const int &x,const int &y){
    a->td.x += x , a->td.y += y;

    a->td.x = max(0, min(a->td.x , SCREEN_WIDTH - main_w));
    a->td.y = max(0, min(a->td.y , SCREEN_HEIGHT - main_h));
}

void mainCha::render(const double &angle){
    a->render(angle);
}

void mainCha::bandan(const double &ha,const double &hb,const bool &okx,const bool &oky){ /// ok la tien hay lui
    int id =  chuaBan.back() ;

    b[id]->a->td.x = a->td.x + main_w / 2 , b[id]->a->td.y = a->td.y + main_h / 2 ;
    b[id]->a->vx = ha; b[id]->a->vy = hb; b[id]->okx = okx, b[id]->oky = oky;
}

void mainCha::playSound(){
    static LSound * amthanh = new LSound(main_sou);
    amthanh->playSound();
}
