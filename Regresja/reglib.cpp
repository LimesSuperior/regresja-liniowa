#include "reglib.h"
#include <cmath>

double* linearRegressionClassicCalculate( double x, double y, double xy, double xx, double yy, int points ) {
    //KH
    // final steps of regression extracted, in case of summing during data input handling

    double* result = new double[4];
    double n = double(points);

    // find a
    result[0] = ( n * xy - x * y ) / ( n * xx - std::pow( x, 2 ) );
    // find b
    result[1] = ( y - result[0] * x ) / n;
    // a error
    result[2] = std::sqrt( ( n * ( yy - result[0]*xy - result[1]*y ) ) / ( (n-2) * ( n*xx - std::pow(x, 2 ) ) ) );
    // b error
    result[3] = std::sqrt( std::pow( result[2], 2 ) * xx / n );

    return result;
}

double* linearRegressionClassic( double *xs, double *ys, int n ) {
    // KH
    // implementation of basic linear regression method (least squares)
    // based on http://fluid.itcmp.pwr.wroc.pl/~lewkow/regresja-liniowa.pdf


    double x = 0., y = 0., xy = 0., xx = 0., yy = 0.;

    // sum
    for( int i = 0; i < n; i ++ ) {
        x += xs[i];
        y += ys[i];
        xx += pow( xs[i], 2 );
        yy += pow( ys[i], 2 );
        xy += xs[i] * ys[i];
    }

    return linearRegressionClassicCalculate( x, y, xy, xx, yy, n );
}
