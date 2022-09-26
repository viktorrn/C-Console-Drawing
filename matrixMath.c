#include "structs.h"
#include "matrixMath.h"


void setMatrix4x4Values(Matrix4x4* matrix,  
    double p11, double p12, double p13, double p14, 
    double p21, double p22, double p23, double p24,
    double p31, double p32, double p33, double p34,
    double p41, double p42, double p43, double p44)
{
    matrix->m[0][0] = p11; matrix->m[0][1] = p12; matrix->m[0][2] = p13; matrix->m[0][3] = p14;
    matrix->m[1][0] = p21; matrix->m[1][1] = p22; matrix->m[1][2] = p23; matrix->m[1][3] = p24;
    matrix->m[2][0] = p31; matrix->m[2][1] = p32; matrix->m[2][2] = p33; matrix->m[2][3] = p34;
    matrix->m[3][0] = p41; matrix->m[3][1] = p42; matrix->m[3][2] = p43; matrix->m[3][3] = p44; 
};

void setVector4(Vec4*vec, double s_x, double s_y, double s_z, double s_w)
{
    vec->x = s_x;
    vec->y = s_y;
    vec->z = s_z;
    vec->w = s_w;
};


void transformVec3(Vertex*vec, Matrix3x3* matrix)
{
    Vec4 result;
    result.x = vec->x * matrix->m[0][0] + vec->y * matrix->m[0][1] + vec->z * matrix->m[0][2];
    result.y = vec->x * matrix->m[1][0] + vec->y * matrix->m[1][1] + vec->z * matrix->m[1][2];
    result.z = vec->x * matrix->m[2][0] + vec->y * matrix->m[2][1] + vec->z * matrix->m[2][2];
    memcpy(vec,&result,sizeof(Vertex));
}

void transformVec4(Vec4*vec, Matrix4x4* matrix)
{
    Vec4 result;
    result.x = vec->x * matrix->m[0][0] + vec->y * matrix->m[0][1] + vec->z * matrix->m[0][2] + vec->w * matrix->m[0][3];
    result.y = vec->x * matrix->m[1][0] + vec->y * matrix->m[1][1] + vec->z * matrix->m[1][2] + vec->w * matrix->m[1][3];
    result.z = vec->x * matrix->m[2][0] + vec->y * matrix->m[2][1] + vec->z * matrix->m[2][2] + vec->w * matrix->m[2][3];
    result.w = vec->x * matrix->m[3][0] + vec->y * matrix->m[3][1] + vec->z * matrix->m[3][2] + vec->w * matrix->m[3][3];
    memcpy(vec,&result,sizeof(Vec4));
}

Matrix3x3 multiplyMatricies3x3(Matrix3x3 *matrix_1,  Matrix3x3 *matrix_2)
{
    Matrix3x3 resultMatrix;
    //row 1
    resultMatrix.m[0][0] = matrix_1->m[0][0] * matrix_2->m[0][0];
    resultMatrix.m[0][1] = matrix_1->m[0][1] * matrix_2->m[1][0];
    resultMatrix.m[0][2] = matrix_1->m[0][2] * matrix_2->m[2][0];
    //row 2
    resultMatrix.m[1][0] = matrix_1->m[1][0] * matrix_2->m[0][1];
    resultMatrix.m[1][1] = matrix_1->m[1][1] * matrix_2->m[1][1];
    resultMatrix.m[1][2] = matrix_1->m[1][2] * matrix_2->m[2][1];
    //row 3
    resultMatrix.m[2][0] = matrix_1->m[2][0] * matrix_2->m[0][2];
    resultMatrix.m[2][1] = matrix_1->m[2][1] * matrix_2->m[1][2];
    resultMatrix.m[2][2] = matrix_1->m[2][2] * matrix_2->m[2][2];
    //row 4
    resultMatrix.m[3][0] = matrix_1->m[3][0] * matrix_2->m[0][3];
    resultMatrix.m[3][1] = matrix_1->m[3][1] * matrix_2->m[1][3];
    resultMatrix.m[3][2] = matrix_1->m[3][2] * matrix_2->m[2][3];

    return resultMatrix;
}

Matrix4x4 multiplyMatricies4x4(Matrix4x4 *matrix_1,  Matrix4x4 *matrix_2)
{
    Matrix4x4 resultMatrix;
    //row 1
    resultMatrix.m[0][0] = matrix_1->m[0][0] * matrix_2->m[0][0] + matrix_1->m[0][1] * matrix_2->m[1][0] + matrix_1->m[0][2] * matrix_2->m[2][0] + matrix_1->m[0][3] * matrix_2->m[3][0];
    resultMatrix.m[0][1] = matrix_1->m[0][0] * matrix_2->m[0][1] + matrix_1->m[0][1] * matrix_2->m[1][1] + matrix_1->m[0][2] * matrix_2->m[2][1] + matrix_1->m[0][3] * matrix_2->m[3][1];
    resultMatrix.m[0][2] = matrix_1->m[0][0] * matrix_2->m[0][2] + matrix_1->m[0][1] * matrix_2->m[1][2] + matrix_1->m[0][2] * matrix_2->m[2][2] + matrix_1->m[0][3] * matrix_2->m[3][2];
    resultMatrix.m[0][2] = matrix_1->m[0][0] * matrix_2->m[0][3] + matrix_1->m[0][1] * matrix_2->m[1][3] + matrix_1->m[0][2] * matrix_2->m[2][3] + matrix_1->m[0][3] * matrix_2->m[3][3];
    //row 2
    resultMatrix.m[1][0] = matrix_1->m[1][0] * matrix_2->m[0][0] + matrix_1->m[1][1] * matrix_2->m[1][0] + matrix_1->m[1][2] * matrix_2->m[2][0] + matrix_1->m[1][3] * matrix_2->m[3][0];
    resultMatrix.m[1][1] = matrix_1->m[1][0] * matrix_2->m[0][1] + matrix_1->m[1][1] * matrix_2->m[1][1] + matrix_1->m[1][2] * matrix_2->m[2][1] + matrix_1->m[1][3] * matrix_2->m[3][1];
    resultMatrix.m[1][2] = matrix_1->m[1][0] * matrix_2->m[0][2] + matrix_1->m[1][1] * matrix_2->m[1][2] + matrix_1->m[1][2] * matrix_2->m[2][2] + matrix_1->m[1][3] * matrix_2->m[3][2];
    resultMatrix.m[1][2] = matrix_1->m[1][0] * matrix_2->m[0][3] + matrix_1->m[1][1] * matrix_2->m[1][3] + matrix_1->m[1][2] * matrix_2->m[2][3] + matrix_1->m[1][3] * matrix_2->m[3][3];
    //row 3
    resultMatrix.m[2][0] = matrix_1->m[2][0] * matrix_2->m[0][0] + matrix_1->m[2][1] * matrix_2->m[1][0] + matrix_1->m[2][2] * matrix_2->m[2][0] + matrix_1->m[2][3] * matrix_2->m[3][0];
    resultMatrix.m[2][1] = matrix_1->m[2][0] * matrix_2->m[0][1] + matrix_1->m[2][1] * matrix_2->m[1][1] + matrix_1->m[2][2] * matrix_2->m[2][1] + matrix_1->m[2][3] * matrix_2->m[3][1];
    resultMatrix.m[2][2] = matrix_1->m[2][0] * matrix_2->m[0][2] + matrix_1->m[2][1] * matrix_2->m[1][2] + matrix_1->m[2][2] * matrix_2->m[2][2] + matrix_1->m[2][3] * matrix_2->m[3][2];
    resultMatrix.m[2][2] = matrix_1->m[2][0] * matrix_2->m[0][3] + matrix_1->m[2][1] * matrix_2->m[1][3] + matrix_1->m[2][2] * matrix_2->m[2][3] + matrix_1->m[2][3] * matrix_2->m[3][3];
    //row 4
    resultMatrix.m[3][0] = matrix_1->m[3][0] * matrix_2->m[0][0] + matrix_1->m[3][1] * matrix_2->m[1][0] + matrix_1->m[3][2] * matrix_2->m[2][0] + matrix_1->m[3][3] * matrix_2->m[3][0];
    resultMatrix.m[3][1] = matrix_1->m[3][0] * matrix_2->m[0][1] + matrix_1->m[3][1] * matrix_2->m[1][1] + matrix_1->m[3][2] * matrix_2->m[2][1] + matrix_1->m[3][3] * matrix_2->m[3][1];
    resultMatrix.m[3][2] = matrix_1->m[3][0] * matrix_2->m[0][2] + matrix_1->m[3][1] * matrix_2->m[1][2] + matrix_1->m[3][2] * matrix_2->m[2][2] + matrix_1->m[3][3] * matrix_2->m[3][2];
    resultMatrix.m[3][2] = matrix_1->m[3][0] * matrix_2->m[0][3] + matrix_1->m[3][1] * matrix_2->m[1][3] + matrix_1->m[3][2] * matrix_2->m[2][3] + matrix_1->m[3][3] * matrix_2->m[3][3];

    return resultMatrix;
}


