#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#ifndef structs_H
#define structs_H

typedef struct S_Vertex
{
    double x;
    double y;
    double z;
} Vertex;

typedef struct S_Triangle
{
    Vertex p0;
    Vertex p1;
    Vertex p2;
} Triangle;

typedef struct S_Vec4
{
    double x;
    double y;
    double z;
    double w;
} Vec4;

typedef struct S_Vec2
{
    double x;
    double y;
} Vec2;

typedef struct S_Camera
{
    Vertex postion;
    Vertex rotation;
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