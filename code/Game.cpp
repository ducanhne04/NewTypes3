#include "Game.h"

Game::Game(SDL_Renderer * &newRender){
    mPoint init(SCREEN_WIDTH / 2 , SCREEN_HEIGHT / 2);
    a = new mainCha(newRender, init) ;

    ifstream ten(du_lieu);
    if(! ten.is_open() );
    else {
        while(! ten.eof()){
            string s; ten >> s;
            if(! ten) break;
            bool ok = 1 ;

            if(int(s.size()) < 7)
                ok = 0 ;

            for(char i : s)
                ok &= ((i >= 'a') && (i <= 'z'));
            if(ok)
                v.push_back(s);
        }
    }

    for(int i = 0 ; i < sl_enemy;i ++) initTd.push_back(mPoint(i * 300  , 1));

    random_shuffle(v.begin() , v.end());

    gFont = TTF_OpenFont(enemy_font.c_str(), 25);
    if(gFont == NULL)
        cout << "loi o game.cpp , ham game(...), dong 50\n" ;

    for(int i = 0;i < sl_enemy;i ++){
        b[i] = new enemy(v.back() , newRender, gFont, initTd[i], i );
        v.pop_back();
        tgian[i] = 0;
    }

    for(int i = 0;i < sl_gai;i ++){
        c[i] = new Dot(gai_pic , initTd[0], newRender, BLACK.r , BLACK.g, BLACK.b);
        chuaBanGai.push_back(i);
    }

    pBg = new LTexture(newRender, NULL);
    pBg->loadImage(back_in_pic, WHITE.r, WHITE.g, WHITE.b);

    mBg = new LMusic(back_in_sou);

    true_type = total_type = sl_die = 0;
    idPri = -1 ;
}

Game::~Game(){
    a->~mainCha();

    for(int i = 0;i < sl_enemy;i ++)
        b[i]->~enemy() , V[i].clear() , tgian[i] = 0;

    for(int i  = 0 ; i < sl_gai;i ++)
        c[i]->~Dot(), tgian2[i] = 0;

    pBg->~LTexture();
    mBg->~LMusic() ;

    TTF_CloseFont(gFont);

    v.clear() , initTd.clear() , daBanGai.clear() , chuaBanGai.clear();

    true_type = total_type = sl_die = idPri = 0 ;
}

void Game::reset_enemy(const int &id){
    b[id]->g = 0 ;
    b[id]->e = v.back() ; v.pop_back() ;
    b[id]->f = int(b[id]->e.size());
    b[id]->h = 3 + rand() % 3 ;
    b[id]->a->td = initTd[sl_die % sl_enemy];
}

void Game::solKey(const char &c){
    total_type ++ ;

    mPoint * x1 = new mPoint(a->a->td.x + main_w / 2 , a->a->td.y + main_h / 2) ;
    mPoint * x2 = new mPoint;

    if(idPri == -1) {
        int minDis = int(1e9);

        for(int i = 0 ;i < sl_enemy;i ++) if((! b[i]->e.empty() ) && ( b[i]->e.front() == c )){
            x2->x = b[i]->a->td.x + enemy_w / 2  ;
            x2->y = b[i]->a->td.y + enemy_h / 2;

            int lDis = x1->kc2(* x2);
            if(lDis < minDis){
                minDis = lDis ;
                idPri = i ;
            }
        }
    }
    if( b[idPri]->e.front() == c ) {
        true_type ++ ;
        b[idPri]->e.erase(0, 1);

        x2->x = b[idPri]->a->td.x + enemy_w / 2  ;
        x2->y = b[idPri]->a->td.y + enemy_h / 2;

        double ha , hb ;
        bool okx = bool(x1->x <= x2->x) , oky = bool(x1->y  <= x2->y);

        if(x2->x == x1->x)
            ha = 0.0 , hb = (oky ? vantoc_bullet : -vantoc_bullet);
        else
            ha = double(x2->y - x1->y) / (x2->x - x1->x) , hb = double(x1->y) - ha * double(x1->x);

        a->bandan(ha, hb , okx, oky);
        int id = a->chuaBan.back(); a->b[id]->playSound();
        V[idPri].push_back( id );
        a->chuaBan.pop_back() ;

        if(b[idPri]->e.empty())
            idPri = -1;
    }

    delete x1 , delete x2 ;
}

void Game::render(){
    pBg->render(0, 0);

   for(int i = 0;i < sl_enemy;i ++) {
        bool ok = 0 ;
        while((! V[i].empty()) && ( a->b[V[i].front()]->a->vacham(b[i]->a) )){
            int id = V[i].front();
            ok = 1 ;

            mPoint x1 , x2 ;

            x1.x = b[i]->a->td.x + enemy_w / 2 , x1.y = b[i]->a->td.y + enemy_h / 2;
            x2.x = a->b[id]->a->td.x + bullet_w / 2 , x2.y = a->b[id]->a->td.y + bullet_h / 2;

            b[i]->a->td.x += max(vantoc_giat_enemy , abs(x1.x - x2.x)) * (a->b[id]->okx ? 1 : -1);
            b[i]->a->td.y += max(vantoc_giat_enemy , abs(x1.y - x2.y)) * (a->b[id]->oky ? 1 : -1);

            a->chuaBan.push_back(id) , V[i].pop_front() , b[i]->g ++;
        }

        if(ok && !tgian[i]){ /// lam mo anh doi thu sau khi va cham voi dan
            tgian[i] ++;
            b[i]->a->pic->setAlpha(128);
        }

        if(tgian[i] > 0){
            tgian[i] ++ ;
            if(tgian[i] >= 20){
                tgian[i] = 0;
                b[i]->a->pic->setAlpha(255);
            }
        }

        b[i]->render();

        for(int id : V[i])
            a->b[id]->render() , a->b[id]->dichuyen(b[i]->a);

        if(b[i]->isDead()){

            b[i]->playSound();
            sl_die ++ ;
            banGai(i);
            reset_enemy(i);

        } else {
            b[i]->dichuyen();
        }
   }

   for(int id : daBanGai){
        tgian2[id] ++ ;

        if(tgian2[id] % chuky == chuky / 2)
            c[id]->vx *= buff_speed , c[id]->vy *= buff_speed;
        if(tgian2[id] % chuky == 0)
            c[id]->vx /= buff_speed , c[id]->vy /= buff_speed;

        c[id]->pic->setColor(tgian2[id]  * rd_red % 256 , tgian2[id]  * rd_green % 256 , tgian2[id]  * rd_blue % 256 );
        c[id]->render(goc_xoay * tgian2[id] % 360 );
   }

   if(idPri != -1){
        mPoint * x1 = new mPoint(a->a->td.x + main_w / 2 , a->a->td.y + main_h / 2) ;
        mPoint * x2 = new mPoint(b[idPri]->a->td.x + enemy_w / 2  , b[idPri]->a->td.y + enemy_h / 2);
        double angle = (* x1).goc(x2);

        if((* x2).x >= (* x1).x)
            a->render(180.0 - angle);
        else
            a->render(angle - 180.0);

        delete x1 , delete x2 ;
   } else {
        a->render(0.0);
   }
}

bool Game::isGameOver(){
    for(int i = 0;i < sl_enemy;i ++)
        if(a->a->vacham(b[i]->a)){

            a->playSound();
            SDL_Delay(100);
            return 1;

        }

    for(int i = 0;i < int(daBanGai.size());i ++){
        int id = daBanGai[i];
        if(c[id]->vacham(a->a)){

            a->playSound();
            SDL_Delay(100);
            return 1;

        } else {
            if(! c[id]->dichuyen(gai_w, gai_h)){
                swap(daBanGai[i] , daBanGai.back());
                chuaBanGai.push_back(id) , daBanGai.pop_back();
                i -- ;
            }
        }
    }
    return 0;
}

void Game::banGai(const int &id){
    mPoint toado(b[id]->a->td.x + enemy_w / 2 , b[id]->a->td.y + enemy_h / 2);
    for(int i = 0;i < 8;i ++){
        int id = chuaBanGai.back();

        c[id]->td.x = toado.x , c[id]->td.y = toado.y;
        c[id]->vx = huong[i][0] , c[id]->vy = huong[i][1];
        tgian2[id] = 0;

        daBanGai.push_back(id) , chuaBanGai.pop_back();
    }
}

void Game::auto_adjust_mainCha(){
    double sVx = 0.0 , sVy = 0.0 ;
    bool ok = 0 ;

    mPoint x1 (a->a->td.x + main_w / 2 , a->a->td.y + main_h / 2) , x2 ;
    for(int i = 0;i < sl_enemy;i ++){
        x2.x = b[i]->a->td.x + enemy_w / 2 , x2.y = b[i]->a->td.y + enemy_h / 2;

        double dis =  x1.kc(x2);
        if(dis <= 50.0)
            sVx += double(x1.x - x2.x) * 50.0 / dis  , sVy += double(x1.y - x2.y) * 50.0 / dis , ok = 1;
    }
    for(int id : daBanGai){
        x2.x = c[id]->td.x + gai_w / 2 , x2.y = c[id]->td.y + gai_h / 2;

        double dis =  x1.kc(x2);
        if(dis <= 50.0)
            sVx += double(x1.x - x2.x) * 50.0 / dis  , sVy += double(x1.y - x2.y) * 50.0 / dis , ok = 1;
    }

    if(ok){
        if(a->a->td.y == 0 || a->a->td.y + main_h == SCREEN_HEIGHT){
            if(sVx < 0) sVx = min(sVx , -5.0);
            else sVx = max(sVx , 5.0);

            sVy *= -0.25;
        }
        if(a->a->td.x == 0 || a->a->td.x + main_w == SCREEN_WIDTH){
            if(sVy < 0) sVy = min(sVy, -5.0);
            else sVy = max(sVy, 5.0);

            sVx *= -0.25;
        }
    }

    a->dichuyen(int( sVx ), int( sVy ));
}

