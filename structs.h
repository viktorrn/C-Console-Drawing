#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#ifndef structs_H
#define structs_H

typedef struct S_Vec3
{
    double x;
    double y;
    double z;
} Vec3;

typedef struct S_Triangle
{
    Vec3 p[3];
} Triangle;

typedef struct S_Mesh
{
    u_int8_t lenght;
    Triangle tris[256];
} Mesh;

typedef struct S_Vec4
{
    double x;
    double y;
    double z;
    double w;
} Vec4;


typedef struct S_Camera
{
    Vec3 postion;
    Vec3 rotation;
} Camera;

typedef struct S_Matrix4x4
{
    double m[4][4];
} Matrix4x4;

typedef struct S_Matrix3x3
{
    double m[3][3];
} Matrix3x3;

#endif /* _structs_ */