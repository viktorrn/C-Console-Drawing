
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "structs.h"
#include "matrixMath.h"

#define ScreenWidth 64
#define ScreenHeight 32
#define PI 3.142f

const int BufferSize = ScreenWidth*ScreenHeight;

void setValueOfBuffer(int x, int y, char*buffer);
void drawBuffer(int w, int h, char* buffer);
void clearBuffer(int size, char*buffer);
void printVec4(Vec4*vec);
void printVec3(Vec3*vec);
void printMatrix(Matrix4x4 *mat);
void initTestCube(Mesh*GameMesh);
void drawLine(int x0, int y0, int x1, int y1);


void init_camera(Camera* cam)
{
    cam->postion.x = 0.0f;
    cam->postion.y = 0.0f;
    cam->postion.z = 0.0f;

    cam->rotation.x = 0.0f;
    cam->rotation.y = 0.0f;
}


int main()
{
    char ScreenBuffer[BufferSize];
    clearBuffer(BufferSize, ScreenBuffer);

    //perspective projection matrix

    double far = 2;
    double near = 0.1;
    double nf = near-far;
    double fov = PI/2;

    double top = 1;
    double e = 1/( sin(fov/2) / cos(fov/2) );
    printf("%lf \n", e);

    double aspect = ScreenWidth/ScreenHeight;

     printf("%lf \n", aspect);

    Matrix4x4 ppm; 
    setMatrix4x4Values(&ppm,e/aspect,0.0f,     0.0f,         0.0f,
                             0.0f,      e,      0.0f,         0.0f,
                             0.0f,    0.0f,  far+near/(nf), 2*far/(nf),
                             0.0f,    0.0f,     -1.0f,           0.0f
                        ); 

    printMatrix(&ppm);



    Mesh GameMesh; 
    GameMesh.lenght = 0;
    memset(&GameMesh.tris,0,sizeof(GameMesh.tris));
    initTestCube(&GameMesh);


    //while(1)
    {
        Triangle tri, triP; 

        for(int i = 0; i < GameMesh.lenght;i++ )
        {
        
            tri = GameMesh.tris[i];
        
            triP.p[0].z += 2;
            triP.p[1].z += 2;
            triP.p[2].z += 2;

            projectionMatrixCalc(&tri.p[0],&triP.p[0],&ppm);
            projectionMatrixCalc(&tri.p[1],&triP.p[1],&ppm);
            projectionMatrixCalc(&tri.p[2],&triP.p[2],&ppm);

            // move
            triP.p[0].x += 1.0f; triP.p[0].y += 1.0f;
            triP.p[1].x += 1.0f; triP.p[1].y += 1.0f;
            triP.p[2].x += 1.0f; triP.p[2].y += 1.0f;

            // scale
            triP.p[0].x *= 0.5f*(double)ScreenWidth; 
            triP.p[0].y *= 0.5f*(double)ScreenHeight; 
            triP.p[1].x *= 0.5f*(double)ScreenWidth; 
            triP.p[1].y *= 0.5f*(double)ScreenHeight; 
            triP.p[2].x *= 0.5f*(double)ScreenWidth; 
            triP.p[2].y *= 0.5f*(double)ScreenHeight; 

            //printVec3(&triP.p[0]);
            //printVec3(&triP.p[1]);
            //printVec3(&triP.p[2]);
            
            setValueOfBuffer((int)(triP.p[0].x+0.5f),(int)(triP.p[0].y+0.5f),ScreenBuffer);
            setValueOfBuffer((int)(triP.p[1].x+0.5f),(int)(triP.p[1].y+0.5f),ScreenBuffer);
            //setValueOfBuffer((int)(triP.p[2].x+0.5f),(int)(triP.p[2].y+0.5f),ScreenBuffer);

        }
 
    drawBuffer(ScreenWidth,ScreenHeight,ScreenBuffer);

    }
    
    return 0;
}

void drawLine(int x0, int y0, int x1, int y1)
{

}

void clearBuffer(int size, char* buffer)
{
    
    for(int i = 0; i < size; i++)
    {
        buffer[i] = ' ';
    }
}

void setValueOfBuffer(int x, int y, char* buffer)
{
    if(y*ScreenWidth+x < ScreenHeight*ScreenWidth && y*ScreenWidth+x >= 0)
    buffer[y*ScreenWidth+x] = '#';
}

void drawBuffer(int w, int h, char* buffer)
{
    system("clear");
    int i = 0;
    for(int y = 0; y < h; y++)
    {
        printf("|");
         for(int x = 0; x < w; x++)
        {
            printf("%c",buffer[i]);
            i++;
        }
        printf("|");
        printf("\n"); 
    }
}

void printVec4(Vec4*vec)
{
    printf("vec: (%lf, %lf, %lf, %lf ) \n",vec->x,vec->y,vec->z,vec->w);
}

void printVec3(Vec3*vec)
{
    printf("vec: (%lf, %lf, %lf ) \n",vec->x,vec->y,vec->z);
}

void printMatrix(Matrix4x4 *mat)
{
    for(int y = 0; y < 4; y++)
    {
        for(int x = 0; x < 4; x++)
        {
            printf("%lf ",mat->m[y][x]);
        }
        printf("\n");
    }
}

void initTestCube(Mesh*GameMesh)
{
        // SOUTH
    Triangle tri0 ={ 0.0f, 0.0f, 0.0f,    0.0f, 1.0f, 0.0f,    1.0f, 1.0f, 0.0f };
    Triangle tri1 ={ 0.0f, 0.0f, 0.0f,    1.0f, 1.0f, 0.0f,    1.0f, 0.0f, 0.0f };

    // EAST                                                      
    Triangle tri2 = { 1.0f, 0.0f, 0.0f,    1.0f, 1.0f, 0.0f,    1.0f, 1.0f, 1.0f }; 
    Triangle tri3 = { 1.0f, 0.0f, 0.0f,    1.0f, 1.0f, 1.0f,    1.0f, 0.0f, 1.0f };

    // NORTH                                                     
    Triangle tri4 = { 1.0f, 0.0f, 1.0f,    1.0f, 1.0f, 1.0f,    0.0f, 1.0f, 1.0f };
    Triangle tri5 = { 1.0f, 0.0f, 1.0f,    0.0f, 1.0f, 1.0f,    0.0f, 0.0f, 1.0f };

    // WEST                                                      
    Triangle tri6 = { 0.0f, 0.0f, 1.0f,    0.0f, 1.0f, 1.0f,    0.0f, 1.0f, 0.0f };
    Triangle tri7 = { 0.0f, 0.0f, 1.0f,    0.0f, 1.0f, 0.0f,    0.0f, 0.0f, 0.0f };

    // TOP                                                       
    Triangle tri8 = { 0.0f, 1.0f, 0.0f,    0.0f, 1.0f, 1.0f,    1.0f, 1.0f, 1.0f };
    Triangle tri9 = { 0.0f, 1.0f, 0.0f,    1.0f, 1.0f, 1.0f,    1.0f, 1.0f, 0.0f };

    // BOTTOM                                                    
    Triangle tri10 = { 1.0f, 0.0f, 1.0f,    0.0f, 0.0f, 1.0f,    0.0f, 0.0f, 0.0f };
    Triangle tri11 = { 1.0f, 0.0f, 1.0f,    0.0f, 0.0f, 0.0f,    1.0f, 0.0f, 0.0f }; 
    
    GameMesh->tris[0] = tri0;
    GameMesh->tris[1] = tri1;
    GameMesh->tris[2] = tri2;
    GameMesh->tris[3] = tri3;
    GameMesh->tris[4] = tri4;
    GameMesh->tris[5] = tri5;
    GameMesh->tris[6] = tri6;
    GameMesh->tris[7] = tri7;
    GameMesh->tris[8] = tri8;
    GameMesh->tris[9] = tri9;
    GameMesh->tris[10] = tri10;
    GameMesh->tris[11] = tri11;

    GameMesh->lenght = 12;
}
