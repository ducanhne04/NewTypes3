#ifndef CONST_H
#define CONST_H

#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <bits/stdc++.h>

using namespace std;

enum kichthuoc{
    SCREEN_WIDTH = 1500, SCREEN_HEIGHT = 800,
    main_w = 50, main_h = 36,
    enemy_w = 20, enemy_h = 20,
    bullet_w = 10, bullet_h = 10,
    gai_w = 16, gai_h = 16,
};

enum soluong{
    sl_bling = 10, sl_enemy = 5,
    sl_bullet = 10, sl_gai = 56
};

enum mouseStatus{
    mOut = 0, mIn = 1 , mDown = 2
};

enum gai_chiso{
    chuky  = 20 , rd_red = 17 , rd_green = 23, rd_blue = 29, buff_speed = 4, goc_xoay = 20
};

const int vantoc_bullet = 30;
const int vantoc_giat_enemy = 2;
const int huong[8][2] = {0, -1 , 1, -1, 1, 0 , 1, 1, 0, 1 , -1, 1, -1, 0, -1, -1};

const string WINDOW_TITLE = "22021102_NguyenDucAnh";
const string du_lieu = "data/vocab.txt";

const string bullet_sou = "data/sound/bullet.wav";
const string bullet_pic = "data/image/bullet.png";

const string main_pic = "data/image/main.png";
const string main_sou = "data/sound/endgame.wav";

const string enemy_pic = "data/image/ene" ;
const string enemy_sou = "data/sound/die.wav" ;
const string gai_pic = "data/image/gai.png";

const string back_pre_pic = "data/image/back-pre2.png";

const string back_in_pic = "data/image/back-in.png";
const string back_in_sou = "data/sound/background.wav";

const string back_end_pic = "data/image/back-end.png";
const string back_end_sou = "data/sound/endgame2.wav";

const string preGame_font = "data/font/chu5.ttf";
const string preGame_announce_font = "data/font/chu1.ttf";
const string enemy_font = "data/font/chu.ttf";
const string endGame_chu = "data/font/chu8.ttf";
const string endGame_so = "data/font/chu2.ttf";

const SDL_Color CYAN = {0, 255, 255};
const SDL_Color BLUE = {0, 0, 255};
const SDL_Color ORANGE = {255, 165, 0};
const SDL_Color YELLOW = {255, 255, 0};
const SDL_Color LIME = {0, 255, 0};
const SDL_Color PURPLE = {128, 0, 128};
const SDL_Color RED = {255, 0, 0};
const SDL_Color WHITE = {255, 255, 255};
const SDL_Color BLACK = {0, 0, 0};
const SDL_Color GREEN = {0, 128, 0};
const SDL_Color GRAY = {128, 128, 128};
const SDL_Color PINK = {240, 128, 128};

#endif
