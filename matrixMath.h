#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "structs.h"

#ifndef matrixMath_H
#define matrixMath_H

void setMatrix4x4Values(Matrix* mat,  
    double p11, double p12, double p13, double p14, 
    double p21, double p22, double p23, double p24,
    double p31, double p32, double p33, double p34,
    double p41, double p42, double p43, double p44
);

Matrix multiplyMatricies(Matrix *matrix_1, Matrix *matrix_2);


#endif /* _matrixMath_H */