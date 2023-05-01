#ifndef MAINCHARACTER_H
#define MAINCHARACTER_H

#include <media.h>
#include <bullet.h>

class mainCha{
public :

    Dot * a;
    bullet * b[sl_bullet];
    vector<int>  chuaBan;

    mainCha(SDL_Renderer * &newRender,mPoint &other);

    ~mainCha();

    void render(const double &angle);

    void dichuyen(const int &x,const int &y);

    void bandan(const double &ha,const double &hb,const bool &okx ,const bool &oky); /// goc tu mainCha den enemy

    static void playSound();
};

#endif
