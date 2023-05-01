#ifndef GAME_H
#define GAME_H

#include <enemy.h>
#include <mainCharacter.h>

class Game{
public :

    mainCha * a;
    enemy * b[sl_enemy] ;
    Dot * c[sl_gai];
    LTexture * pBg ;
    LMusic * mBg;
    TTF_Font * gFont;

    deque<int> V[sl_enemy] ; /// moi enemy luu cac chi so dan ban den no
    vector<string> v;
    vector<mPoint> initTd ;
    vector<int> daBanGai , chuaBanGai;

    int true_type , total_type, sl_die, idPri , tgian[sl_enemy] , tgian2[sl_gai];/// do do chinh xac go phim
    /// score = true_type ,
    /// game over thi cout ra true_type / total_type * 100% , score
    /// idPri la chi so thg dang tieu diet (mac dinh = -1) , neu = -1 thi tim thg gan nhat

    Game(SDL_Renderer * &newRender);

    ~Game();

    void solKey(const char &c);

    void render();

    void reset_enemy(const int &id);

    bool isGameOver();

    void banGai(const int &id);

    void auto_adjust_mainCha();
};

#endif
