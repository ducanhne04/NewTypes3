#include "supmain.h"

void khoitaoSDL(SDL_Window * &newWindow , SDL_Renderer * &newRender){
    if(SDL_Init(SDL_INIT_EVERYTHING) != 0)
        cout << "loi o supmain.cpp , ham khoitaoSDL , dong 5\n" ;

    if(! SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY , "1"))
        cout << "loi o supmain.cpp , ham khoitaoSDL, dong 8\n" ;

    newWindow = SDL_CreateWindow(WINDOW_TITLE.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT , SDL_WINDOW_SHOWN);

    if(newWindow == NULL)
        cout << "loi o supmain.cpp , ham khoitaoSDL , dong 13\n" ;

    newRender = SDL_CreateRenderer(newWindow , -1 , SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC) ;

    if(newRender == NULL)
        cout << "loi o supmain.cpp , ham khoitaoSDL , dong 18\n" ;

    int imgFlags = IMG_INIT_PNG ;
    if(!(IMG_Init(imgFlags) & imgFlags))
        cout << "loi o supmain.cpp, ham khoitaoSDL , dong 22\n" ;

    if(TTF_Init() == -1)
        cout << "loi o supmain.cpp , ham khoitaoSDL , dong 25\n" ;

    if(Mix_OpenAudio(44100 , MIX_DEFAULT_FORMAT , 2, 2048) < 0)
        cout << "loi o supmain.cpp , ham khoitaoSDL , dong 28\n" ;
}

void thoatSDL(SDL_Window * &newWindow , SDL_Renderer * &newRender) {
    SDL_DestroyRenderer(newRender);
    SDL_DestroyWindow(newWindow);

    TTF_Quit();
    IMG_Quit();
    Mix_Quit();
    SDL_Quit();
}

void renderGamePlay(SDL_Renderer * &newRender, Game * &g) {
    g->render();

    SDL_RenderPresent(newRender);
}

void solEvent(SDL_Event &e,bool & runGame,Game * &g){
    while( SDL_PollEvent( &e ) != 0 ){
        if(e.type == SDL_QUIT)
            runGame = 0;
        else if( e.type == SDL_KEYDOWN ){
            switch( e.key.keysym.sym ){
                case SDLK_UP :{
                    g->a->dichuyen(0, -5);
                    break ;
                }
                case SDLK_DOWN :{
                    g->a->dichuyen(0, 5);
                    break ;
                }
                case SDLK_LEFT :{
                    g->a->dichuyen(-5, 0);
                    break ;
                }
                case SDLK_RIGHT :{
                    g->a->dichuyen(5, 0);
                    break ;
                }
                case SDLK_ESCAPE :{
                    runGame = 0;
                    break ;
                }
                case SDLK_RETURN :{
                    runGame = 0;
                    break ;
                }
                case SDLK_a :{
                    g->solKey('a');
                    break ;
                }
                case SDLK_b :{
                    g->solKey('b');
                    break ;
                }
                case SDLK_c :{
                    g->solKey('c');
                    break ;
                }
                case SDLK_d :{
                    g->solKey('d');
                    break ;
                }
                case SDLK_e :{
                    g->solKey('e');
                    break ;
                }
                case SDLK_f :{
                    g->solKey('f');
                    break ;
                }
                case SDLK_g :{
                    g->solKey('g');
                    break ;
                }
                case SDLK_h :{
                    g->solKey('h');
                    break ;
                }
                case SDLK_i :{
                    g->solKey('i');
                    break ;
                }
                case SDLK_j :{
                    g->solKey('j');
                    break ;
                }
                case SDLK_k :{
                    g->solKey('k');
                    break ;
                }
                case SDLK_l :{
                    g->solKey('l');
                    break ;
                }
                case SDLK_m :{
                    g->solKey('m');
                    break ;
                }
                case SDLK_n :{
                    g->solKey('n');
                    break ;
                }
                case SDLK_o :{
                    g->solKey('o');
                    break ;
                }
                case SDLK_p :{
                    g->solKey('p');
                    break ;
                }
                case SDLK_q :{
                    g->solKey('q');
                    break ;
                }
                case SDLK_r :{
                    g->solKey('r');
                    break ;
                }
                case SDLK_s :{
                    g->solKey('s');
                    break ;
                }
                case SDLK_t :{
                    g->solKey('t');
                    break ;
                }
                case SDLK_u :{
                    g->solKey('u');
                    break ;
                }
                case SDLK_v :{
                    g->solKey('v');
                    break ;
                }
                case SDLK_w :{
                    g->solKey('w');
                    break ;
                }
                case SDLK_x :{
                    g->solKey('x');
                    break ;
                }
                case SDLK_y :{
                    g->solKey('y');
                    break ;
                }
                case SDLK_z :{
                    g->solKey('z');
                    break ;
                }
                default : {
                    break;
                }
            }
        }
    }
}

pair<bool, bool> renderPreGame(SDL_Renderer * &newRender, SDL_Event &e, Game * &g){ /// co choi khong , co bat autopilot khong
    TTF_Font * f[2] , * ctitle;

    f[0] = TTF_OpenFont(preGame_font.c_str() , 30);
    f[1] = TTF_OpenFont(preGame_announce_font.c_str() , 30);
    ctitle = TTF_OpenFont(preGame_font.c_str(), 100);

    LTexture * pbg = new LTexture(newRender, NULL) , * gametitle = new LTexture(newRender, ctitle);

    pbg->loadImage(back_pre_pic , CYAN.r , CYAN.g , CYAN.b);
    gametitle->loadText("NewTypes" , GREEN);

    LButton * a[3] ;
    mPoint * b[3] ;

    b[0] = new mPoint(100 ,  150);
    b[1] = new mPoint(100 ,  350);
    b[2] = new mPoint(100,  550) ;

    vector<string> V[3] ;
    V[0] = {"NewGame", "NewGame", "Let's start <3"};
    V[1] = {"Settings", "Settings", "Press y / n to turn on / off music : ", "Press 1 / 0 to turn on / off autopilot mod : ", "ON", "OFF"};
    V[2] = {"How to play", "How to play",  "Press esc / enter to exit this game" , "Press the arrow buttons to adjust the character",
                "Press the letters to destroy the opponents", "Do not let other objects touch the character"};

    for(int i = 0;i < 3;i ++)
        a[i] = new LButton(newRender,  f , * b[i] , V[i]) ;/// 3, 6, 6 (0,1,2)

    a[0]->w = 210 , a[1]->w = 629 , a[2]->w = 671 ; /// code thu de tim ra kich thuoc nay
    a[0]->h = 32 , a[1]->h = 64 , a[2]->h = 128;

    bool ok = 1 , ok2 = 0; /// ok la play music , ok2 la autopilot
    do{
        if(ok)
            g->mBg->playMusic();
        else
            g->mBg->stopMusic();

        while(SDL_PollEvent(& e) != 0){
            if(e.type == SDL_QUIT)
                return {0, 0};
            if(e.type == SDL_KEYDOWN && (e.key.keysym.sym == SDLK_ESCAPE || e.key.keysym.sym == SDLK_RETURN))
                return {0, 0};
            for(int i = 0;i < 3;i ++)
                a[i]->handleEvent(e, ok, ok2) ;
        }

        pbg->render(0, 0);
        gametitle->render(300, 0);

        for(int i = 0;i < 3;i ++)
            a[i]->render(bool(i == 1)  , ok , ok2) ;

        SDL_RenderPresent(newRender);

        if(a[0]->a == mDown)
            SDL_Delay(1000);
    }while(a[0]->a != mDown);

    for(int i = 0;i < 3;i ++)
        a[i]->~LButton() , delete b[i],  V[i].clear();

    for(int i = 0 ;i < 2;i ++)
        TTF_CloseFont(f[i]);
    TTF_CloseFont(ctitle);

    pbg->~LTexture(), gametitle->~LTexture();

    return {1 , ok2};
}

void renderEndGame(int &finalScore, int &totalType, int &slDie, SDL_Renderer * &newRender,SDL_Event &e){
    LSound * amthanh = new LSound(back_end_sou);
    amthanh->playSound();

    string sFinalScore = "" , sAccurate = "%", sSlDie = "";

    int accurate = ((totalType == 0) ? 0 : finalScore * 10000 / totalType) ;

    while(finalScore > 0){
        sFinalScore = char('0' + finalScore % 10) + sFinalScore ;
        finalScore /= 10;
    }
    while(int(sFinalScore.size()) < 5)
        sFinalScore = "0" + sFinalScore ;

    while(accurate > 0){
        sAccurate = char('0' + accurate % 10) + sAccurate ;
        accurate /= 10;
        if(int(sAccurate.size()) == 3)
            sAccurate = "." + sAccurate ;
    }
    if(int(sAccurate.size()) < 3){
        while(int(sAccurate.size()) < 3)
            sAccurate = "0" + sAccurate ;
        sAccurate = "." + sAccurate ;
    }
    while(int(sAccurate.size()) < 7)
        sAccurate = "0" + sAccurate ;

    while(slDie > 0){
        sSlDie = char('0' + slDie % 10) + sSlDie ;
        slDie /= 10;
    }
    while(int(sSlDie.size()) < 4)
        sSlDie = "0" + sSlDie ;

    TTF_Font * f1 , * f2 ;
    f1 = TTF_OpenFont(endGame_chu.c_str() , 60) , f2 = TTF_OpenFont(endGame_so.c_str(), 45);

    LTexture * c1 = new LTexture(newRender, f1) , * c2 = new LTexture(newRender, f1) , * c3 = new LTexture(newRender, f1) ,
    * s1 = new LTexture(newRender, f2) , * s2 = new LTexture(newRender, f2) , * s3 = new LTexture(newRender, f2) ,
    * pbg = new LTexture(newRender, NULL);

    pbg->loadImage(back_end_pic , CYAN.r , CYAN.g , CYAN.b);

    c1->loadText("Final Score" , WHITE) , s1->loadText(sFinalScore , ORANGE);
    c2->loadText("Accuracy" , WHITE) , s2->loadText(sAccurate , GREEN);
    c3->loadText("Number of opponents killed" , WHITE) , s3->loadText(sSlDie , RED);

    pbg->render(0, 0);

    c1->render(350 , 5);
    s1->render(350 , 10 + c1->mHeight);

    c2->render(950 , 5) ;
    s2->render(950 , 10 + c2->mHeight);

    c3->render(500, c1->mHeight + s1->mHeight + 100);
    s3->render(500, c1->mHeight + s1->mHeight + c3->mHeight + 100) ;

    SDL_RenderPresent(newRender);

    bool quit = 0 ;
    int tgian = 0 ;
    while((! quit) && (tgian < 5000)){
        while(SDL_PollEvent(& e) != 0){
            if(e.type == SDL_QUIT)
                quit = 1;
            if(e.type == SDL_KEYDOWN && (e.key.keysym.sym == SDLK_ESCAPE || e.key.keysym.sym == SDLK_RETURN))
                quit = 1;
        }
        tgian ++ ;
        SDL_Delay(1);
    }

    amthanh->~LSound();
    TTF_CloseFont(f1) , TTF_CloseFont(f2) ;
    c1->~LTexture() , c2->~LTexture() , c3->~LTexture() , s1->~LTexture() , s2->~LTexture() , s3->~LTexture(), pbg->~LTexture();
}
