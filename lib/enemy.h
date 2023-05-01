#ifndef ENEMY_H
#define ENEMY_H

#include <media.h>

class enemy{
public :

    Dot * a;
    bling * b[sl_bling];
    LTexture * d; /// chu ma no dai dien
    string e;
    int f , g, h ; /// g la so vien dan da va cham vao no , f la do dai xau ban dau , h la huong di chuyen

    enemy(const string &text, SDL_Renderer * &newRender , TTF_Font * &newFont,mPoint &other,int &h2);

    ~enemy();

    void render();

    void dichuyen();

    bool isDead();

    static void playSound();
};

#endif
