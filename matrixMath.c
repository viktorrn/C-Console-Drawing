#include "structs.h"
#include "matrixMath.h"


void setMatrix4x4Values(Matrix* matrix,  
    double p11, double p12, double p13, double p14, 
    double p21, double p22, double p23, double p24,
    double p31, double p32, double p33, double p34,
    double p41, double p42, double p43, double p44)
{
    printf("%d \n",(int)matrix);
    matrix->m[0][0] = p11; matrix->m[0][1] = p12; matrix->m[0][2] = p13; matrix->m[0][3] = p14;
    matrix->m[1][0] = p21; matrix->m[1][1] = p22; matrix->m[1][2] = p23; matrix->m[1][3] = p24;
    matrix->m[2][0] = p31; matrix->m[2][1] = p32; matrix->m[2][2] = p33; matrix->m[2][3] = p34;
    matrix->m[3][0] = p41; matrix->m[3][1] = p42; matrix->m[3][2] = p43; matrix->m[3][3] = p44; 
};

Matrix multiplyMatricies(Matrix *matrix_1,  Matrix *matrix_2)
{
    Matrix resultMatrix;
    //row 1
    resultMatrix.m[0][0] = matrix_1->m[0][0] * matrix_2->m[0][0];
    resultMatrix.m[0][1] = matrix_1->m[0][1] * matrix_2->m[1][0];
    resultMatrix.m[0][2] = matrix_1->m[0][2] * matrix_2->m[2][0];
    resultMatrix.m[0][3] = matrix_1->m[0][3] * matrix_2->m[3][0];
    //row 2
    resultMatrix.m[1][0] = matrix_1->m[1][0] * matrix_2->m[0][1];
    resultMatrix.m[1][1] = matrix_1->m[1][1] * matrix_2->m[1][1];
    resultMatrix.m[1][2] = matrix_1->m[1][2] * matrix_2->m[2][1];
    resultMatrix.m[1][3] = matrix_1->m[1][3] * matrix_2->m[3][1];
    //row 3
    resultMatrix.m[2][0] = matrix_1->m[2][0] * matrix_2->m[0][2];
    resultMatrix.m[2][1] = matrix_1->m[2][1] * matrix_2->m[1][2];
    resultMatrix.m[2][2] = matrix_1->m[2][2] * matrix_2->m[2][2];
    resultMatrix.m[2][3] = matrix_1->m[2][3] * matrix_2->m[3][2];
    //row 4
    resultMatrix.m[3][0] = matrix_1->m[3][0] * matrix_2->m[0][3];
    resultMatrix.m[3][1] = matrix_1->m[3][1] * matrix_2->m[1][3];
    resultMatrix.m[3][2] = matrix_1->m[3][2] * matrix_2->m[2][3];
    resultMatrix.m[3][3] = matrix_1->m[3][3] * matrix_2->m[3][3];

    return resultMatrix;
}


