#ifndef GEO_H
#define GEO_H

#include <const.h>

class mPoint{
public :

    int x , y;

    mPoint() ;

    mPoint(const int &x2 ,const int &y2) ;

    int kc2( mPoint  &other);

    double kc(mPoint &other);

    bool isInside(const int &w ,const  int &h );

    double goc(mPoint * &other);
};

#endif
