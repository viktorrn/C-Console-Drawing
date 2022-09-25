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
} vertex;

typedef struct S_Vec4
{
    double x;
    double y;
    double z;
    double w;
} Vec4;

typedef struct S_Camera
{
    vertex postion;
    vertex rotation;
} Camera;

typedef struct S_RoadPiece
{
    vertex postion;
} roadPiece;

typedef struct S_Matrix
{
    double m[4][4];
} Matrix;

#endif /* _structs_ */