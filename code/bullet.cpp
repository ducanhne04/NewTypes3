#include "bullet.h"

bullet::bullet(SDL_Renderer * &newRender, mPoint &other){
    a = new Dot(bullet_pic, other, newRender, BLACK.r, BLACK.g, BLACK.b);
}

bullet::~bullet(){
    a->~Dot();
}

void bullet::dichuyen(Dot * &other){
    a->td.x += ((okx) ? vantoc_bullet : - vantoc_bullet) ;
    a->td.y = a->vx * a->td.x + a->vy;

    if(okx) a->td.x = min(a->td.x , other->td.x + enemy_w - bullet_w + 5);
    else a->td.x = max(a->td.x , other->td.x - 5);

    if(oky) a->td.y = min(a->td.y , other->td.y + enemy_h - bullet_h + 5);
    else a->td.y = max(a->td.y , other->td.y - 5);

    if((a->vx != 0.0) && (a->td.x >= other->td.x - 5) && (a->td.x <= other->td.x + enemy_w - bullet_w + 5))
        a->td.y =  ((a->td.y <= other->td.y) ? other->td.y - bullet_h + 5 : other->td.y + enemy_h - 5);
}

void bullet::render(){
    a->render(0.0);
}

void bullet::playSound(){
    static LSound * amthanh = new LSound(bullet_sou);
    amthanh->playSound();
}
