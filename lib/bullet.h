#ifndef BULLET_H
#define BULLET_H

#include <media.h>

class bullet{
public :

    Dot * a;
    bool okx, oky;

    bullet(SDL_Renderer * &newRender,mPoint &other);

    ~bullet();

    void render();

    void dichuyen(Dot * &other);

    static void playSound();
};

#endif
