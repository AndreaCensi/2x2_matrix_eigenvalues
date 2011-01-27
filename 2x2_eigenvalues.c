#include <math.h>

#define tolerance 0.1e-20
 
void solve_eig(double A, double B, double C, double D, 
    double* lambda1, double *v1x, double*v1y, 
    double* lambda2, double *v2x, double*v2y ) 
{
    if(B*C <= tolerance  ) {
        *lambda1 = A; *v1x = 1; *v1y = 0;
        *lambda2 = D; *v2x = 0; *v2y = 1;
        return;
    }

    double tr = A + D;
    double det = A * D - B * C;
    double S = sqrt( square(tr/2) - det );
    *lambda1 = tr/2 + S;
    *lambda2 = tr/2 - S;

    double SS = sqrt( max(square((A-D)/2) + B * C, 0.0) );
    if( A - D < 0 ) {
        *v1x = C;
        *v1y = - (A-D)/2 + SS;
        *v2x = + (A-D)/2 - SS;
        *v2y = B;
    } else {
        *v2x = C;
        *v2y = - (A-D)/2 - SS;
        *v1x = + (A-D)/2 + SS;
        *v1y = B;
    }

    double n1 = sqrt(square(*v1x)+square(*v1y));
    *v1x /= n1; *v1y /= n1;
    double n2 = sqrt(square(*v2x)+square(*v2y));
    *v2x /= n2; *v2y /= n2;
}