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


void transformVec3(Vec3*v_i, Vec3*v_o, Matrix3x3* matrix)
{
   
    v_o->x = v_i->x * matrix->m[0][0] + v_i->y * matrix->m[0][1] + v_i->z * matrix->m[0][2];
    v_o->y = v_i->x * matrix->m[1][0] + v_i->y * matrix->m[1][1] + v_i->z * matrix->m[1][2];
    v_o->z = v_i->x * matrix->m[2][0] + v_i->y * matrix->m[2][1] + v_i->z * matrix->m[2][2];

}

void transformVec4(Vec4*v_i,Vec4*v_o, Matrix4x4* matrix)
{
 
    v_o->x = v_i->x * matrix->m[0][0] + v_i->y * matrix->m[0][1] + v_i->z * matrix->m[0][2] + v_i->w * matrix->m[0][3];
    v_o->y = v_i->x * matrix->m[1][0] + v_i->y * matrix->m[1][1] + v_i->z * matrix->m[1][2] + v_i->w * matrix->m[1][3];
    v_o->z = v_i->x * matrix->m[2][0] + v_i->y * matrix->m[2][1] + v_i->z * matrix->m[2][2] + v_i->w * matrix->m[2][3];
    v_o->w = v_i->x * matrix->m[3][0] + v_i->y * matrix->m[3][1] + v_i->z * matrix->m[3][2] + v_i->w * matrix->m[3][3];

}

void projectionMatrixCalc(Vec3*v_i,Vec3*v_o, Matrix4x4* m)
{
    v_o->x = v_i->x * m->m[0][0] + v_i->y * m->m[0][1] + v_i->z * m->m[0][2];
    v_o->y = v_i->x * m->m[1][0] + v_i->y * m->m[1][1] + v_i->z * m->m[1][2];
    v_o->z = v_i->x * m->m[2][0] + v_i->y * m->m[2][1] + v_i->z * m->m[2][2];

    double w = v_i->x * m->m[0][3] + v_i->y * m->m[1][3] + v_i->z * m->m[2][3] + m->m[3][3];

    if(w != 0.0f)
    {
        v_o->x /= w;  v_o->y /= w;  v_o->z /= w;
    }
}

Matrix3x3 multiplyMatricies3x3(Matrix3x3 *m_1,  Matrix3x3 *m_2)
{
    Matrix3x3 resultMatrix;
    //row 1
 //row 1
    resultMatrix.m[0][0] = m_1->m[0][0] * m_2->m[0][0] + m_1->m[0][1] * m_2->m[1][0] + m_1->m[0][2] * m_2->m[2][0];
    resultMatrix.m[0][1] = m_1->m[0][0] * m_2->m[0][1] + m_1->m[0][1] * m_2->m[1][1] + m_1->m[0][2] * m_2->m[2][1];
    resultMatrix.m[0][2] = m_1->m[0][0] * m_2->m[0][2] + m_1->m[0][1] * m_2->m[1][2] + m_1->m[0][2] * m_2->m[2][2];
    //row 2
    resultMatrix.m[1][0] = m_1->m[1][0] * m_2->m[0][0] + m_1->m[1][1] * m_2->m[1][0] + m_1->m[1][2] * m_2->m[2][0];
    resultMatrix.m[1][1] = m_1->m[1][0] * m_2->m[0][1] + m_1->m[1][1] * m_2->m[1][1] + m_1->m[1][2] * m_2->m[2][1];
    resultMatrix.m[1][2] = m_1->m[1][0] * m_2->m[0][2] + m_1->m[1][1] * m_2->m[1][2] + m_1->m[1][2] * m_2->m[2][2];
    //row 3
    resultMatrix.m[2][0] = m_1->m[2][0] * m_2->m[0][0] + m_1->m[2][1] * m_2->m[1][0] + m_1->m[2][2] * m_2->m[2][0];
    resultMatrix.m[2][1] = m_1->m[2][0] * m_2->m[0][1] + m_1->m[2][1] * m_2->m[1][1] + m_1->m[2][2] * m_2->m[2][1];
    resultMatrix.m[2][2] = m_1->m[2][0] * m_2->m[0][2] + m_1->m[2][1] * m_2->m[1][2] + m_1->m[2][2] * m_2->m[2][2];
    //row 4
    resultMatrix.m[3][0] = m_1->m[3][0] * m_2->m[0][0] + m_1->m[3][1] * m_2->m[1][0] + m_1->m[3][2] * m_2->m[2][0];
    resultMatrix.m[3][1] = m_1->m[3][0] * m_2->m[0][1] + m_1->m[3][1] * m_2->m[1][1] + m_1->m[3][2] * m_2->m[2][1];
    resultMatrix.m[3][2] = m_1->m[3][0] * m_2->m[0][2] + m_1->m[3][1] * m_2->m[1][2] + m_1->m[3][2] * m_2->m[2][2];


    return resultMatrix;
}

Matrix4x4 multiplyMatricies4x4(Matrix4x4 *m_1,  Matrix4x4 *m_2)
{
    Matrix4x4 resultMatrix;
    //row 1
    resultMatrix.m[0][0] = m_1->m[0][0] * m_2->m[0][0] + m_1->m[0][1] * m_2->m[1][0] + m_1->m[0][2] * m_2->m[2][0] + m_1->m[0][3] * m_2->m[3][0];
    resultMatrix.m[0][1] = m_1->m[0][0] * m_2->m[0][1] + m_1->m[0][1] * m_2->m[1][1] + m_1->m[0][2] * m_2->m[2][1] + m_1->m[0][3] * m_2->m[3][1];
    resultMatrix.m[0][2] = m_1->m[0][0] * m_2->m[0][2] + m_1->m[0][1] * m_2->m[1][2] + m_1->m[0][2] * m_2->m[2][2] + m_1->m[0][3] * m_2->m[3][2];
    resultMatrix.m[0][3] = m_1->m[0][0] * m_2->m[0][3] + m_1->m[0][1] * m_2->m[1][3] + m_1->m[0][2] * m_2->m[2][3] + m_1->m[0][3] * m_2->m[3][3];
    //row 2
    resultMatrix.m[1][0] = m_1->m[1][0] * m_2->m[0][0] + m_1->m[1][1] * m_2->m[1][0] + m_1->m[1][2] * m_2->m[2][0] + m_1->m[1][3] * m_2->m[3][0];
    resultMatrix.m[1][1] = m_1->m[1][0] * m_2->m[0][1] + m_1->m[1][1] * m_2->m[1][1] + m_1->m[1][2] * m_2->m[2][1] + m_1->m[1][3] * m_2->m[3][1];
    resultMatrix.m[1][2] = m_1->m[1][0] * m_2->m[0][2] + m_1->m[1][1] * m_2->m[1][2] + m_1->m[1][2] * m_2->m[2][2] + m_1->m[1][3] * m_2->m[3][2];
    resultMatrix.m[1][3] = m_1->m[1][0] * m_2->m[0][3] + m_1->m[1][1] * m_2->m[1][3] + m_1->m[1][2] * m_2->m[2][3] + m_1->m[1][3] * m_2->m[3][3];
    //row 3
    resultMatrix.m[2][0] = m_1->m[2][0] * m_2->m[0][0] + m_1->m[2][1] * m_2->m[1][0] + m_1->m[2][2] * m_2->m[2][0] + m_1->m[2][3] * m_2->m[3][0];
    resultMatrix.m[2][1] = m_1->m[2][0] * m_2->m[0][1] + m_1->m[2][1] * m_2->m[1][1] + m_1->m[2][2] * m_2->m[2][1] + m_1->m[2][3] * m_2->m[3][1];
    resultMatrix.m[2][2] = m_1->m[2][0] * m_2->m[0][2] + m_1->m[2][1] * m_2->m[1][2] + m_1->m[2][2] * m_2->m[2][2] + m_1->m[2][3] * m_2->m[3][2];
    resultMatrix.m[2][3] = m_1->m[2][0] * m_2->m[0][3] + m_1->m[2][1] * m_2->m[1][3] + m_1->m[2][2] * m_2->m[2][3] + m_1->m[2][3] * m_2->m[3][3];
    //row 4
    resultMatrix.m[3][0] = m_1->m[3][0] * m_2->m[0][0] + m_1->m[3][1] * m_2->m[1][0] + m_1->m[3][2] * m_2->m[2][0] + m_1->m[3][3] * m_2->m[3][0];
    resultMatrix.m[3][1] = m_1->m[3][0] * m_2->m[0][1] + m_1->m[3][1] * m_2->m[1][1] + m_1->m[3][2] * m_2->m[2][1] + m_1->m[3][3] * m_2->m[3][1];
    resultMatrix.m[3][2] = m_1->m[3][0] * m_2->m[0][2] + m_1->m[3][1] * m_2->m[1][2] + m_1->m[3][2] * m_2->m[2][2] + m_1->m[3][3] * m_2->m[3][2];
    resultMatrix.m[3][3] = m_1->m[3][0] * m_2->m[0][3] + m_1->m[3][1] * m_2->m[1][3] + m_1->m[3][2] * m_2->m[2][3] + m_1->m[3][3] * m_2->m[3][3];

    return resultMatrix;
}


