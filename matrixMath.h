#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "structs.h"

#ifndef matrixMath_H
#define matrixMath_H

void setMatrix4x4Values(Matrix4x4* mat,  
    double p11, double p12, double p13, double p14, 
    double p21, double p22, double p23, double p24,
    double p31, double p32, double p33, double p34,
    double p41, double p42, double p43, double p44
);


void setMatrix3x3Values(Matrix3x3* mat,  
    double p11, double p12, double p13, 
    double p21, double p22, double p23,
    double p31, double p32, double p33
);

void setVector4(Vec4*vec, double s_x, double s_y, double s_z, double s_w);

void transformVec4(Vec4*v_i,Vec4*v_o, Matrix4x4* matrix);
Matrix4x4 multiplyMatricies4x4(Matrix4x4 *matrix_1, Matrix4x4 *matrix_2);

void transformVec3(Vec3*v_i,Vec3*v_o, Matrix3x3* matrix);
Matrix3x3 multiplyMatricies3x3(Matrix3x3 *matrix_1, Matrix3x3 *matrix_2);

void projectionMatrixCalc(Vec3*v_i,Vec3*v_o, Matrix4x4* matrix);

#endif /* _matrixMath_H */