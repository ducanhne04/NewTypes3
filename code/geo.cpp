#include "geo.h"

mPoint::mPoint(){
    x = y = 0 ;
}

mPoint::mPoint(const int &x2,const int &y2){
    x = x2 , y = y2 ;
}

int mPoint::kc2(mPoint &other){
    return (x - other.x) * (x - other.x) + (y - other.y) * (y - other.y) ;
}

double mPoint::kc(mPoint &other){
    return sqrt(kc2(other));
}

double mPoint::goc(mPoint * &other){
    return acos(double(other->y - y) / kc(* other)) * 180.0 / M_PI;
}

bool mPoint::isInside(const int &w ,const  int &h){
    return 1 - (x < 0 || x + w > SCREEN_WIDTH || y < 0 || y + h > SCREEN_HEIGHT);
}
