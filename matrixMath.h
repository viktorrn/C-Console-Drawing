#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "structs.h"

#ifndef matrixMath_H
#define matrixMath_H

void setMatrix4x4Values(Matrix4x4* mat,  
    float p11, float p12, float p13, float p14, 
    float p21, float p22, float p23, float p24,
    float p31, float p32, float p33, float p34,
    float p41, float p42, float p43, float p44
);


void setMatrix3x3Values(Matrix3x3* mat,  
    float p11, float p12, float p13, 
    float p21, float p22, float p23,
    float p31, float p32, float p33
);

void setVector4(Vec4*vec, float s_x, float s_y, float s_z, float s_w);

void transformVec4(Vec4*v_i,Vec4*v_o, Matrix4x4* matrix);
void multiplyMatricies4x4(Matrix4x4 *matrix_1, Matrix4x4 *matrix_2, Matrix4x4* resultMatrix);

void transformVec3(Vec3*v_i,Vec3*v_o, Matrix3x3* matrix);
void multiplyMatricies3x3(Matrix3x3 *matrix_1, Matrix3x3 *matrix_2, Matrix3x3* resultMatrix);

void projectionMatrixCalc(Vec3*v_i,Vec3*v_o, Matrix4x4* matrix);

Matrix3x3 getRotationMatrixXYZ(float a, float b, float y);
Matrix3x3 getRotationMatrixX(float a);
Matrix3x3 getRotationMatrixY(float a);
Matrix3x3 getRotationMatrixZ(float a);

#endif /* _matrixMath_H */