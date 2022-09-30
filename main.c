
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include "structs.h"
#include "matrixMath.h"

#define ScreenWidth 48
#define ScreenHeight 32
#define PI 3.142f

const int BufferSize = (ScreenWidth+1)*ScreenHeight;

void setValueOfBuffer(int x, int y, char*buffer);
void drawBuffer(int w, int h, char* buffer);
void clearBuffer(int size, char*buffer);
void printVec4(Vec4*vec);
void printVec3(Vec3*vec);
void printMatrix(Matrix4x4 *mat);
void initTestCube(Mesh*GameMesh);
void drawLine(float x0, float y0, float x1, float y1, char*buffer);

int sign(int x) {
    return (x > 0) - (x < 0);
}


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
    double fov = PI/2;
    double fNear = 0.1f;
	double fFar = 750.0f;
	double aspect= (double)ScreenWidth / (double)ScreenHeight;
	double fFovRad = 1.0f / tanf(fov/2);


    Matrix4x4 ppm; 
    setMatrix4x4Values(&ppm,fFovRad*aspect,  0.0f,     0.0f,                0.0f,
                             0.0f,          fFovRad,   0.0f,                0.0f,
                             0.0f,           0.0f,  (fFar)/(fFar-fNear), (-fFar * fNear) / (fFar-fNear),
                             0.0f,           0.0f,     1.0f,                0.0f
                        ); 





    Mesh GameMesh; 
    GameMesh.lenght = 0;
    memset(&GameMesh.tris,0,sizeof(GameMesh.tris));
    initTestCube(&GameMesh);
    int active = 1;
    double time = 0;
    while(active)
    {
        Triangle tri, triRot, triP; 
        Matrix3x3 resultMatrix;
        Matrix3x3 rotationMatrix = getRotationMatrixXYZ(time,time,0);
        //sumRotaion = multiplyMatricies3x3(&sumRotaion)
        //Vec3

        /* for(int i = 0; i < GameMesh.lenght;i++ )
        {
        
            tri = GameMesh.tris[i];
        
            transformVec3( &tri.p[0],&triRot.p[0],&rotationMatrix);
            transformVec3( &tri.p[1],&triRot.p[1],&rotationMatrix);
            transformVec3( &tri.p[2],&triRot.p[2],&rotationMatrix);

            triRot.p[0].z += 20;
            triRot.p[1].z += 20;
            triRot.p[2].z += 20;

            projectionMatrixCalc(&triRot.p[0],&triP.p[0],&ppm);
            projectionMatrixCalc(&triRot.p[1],&triP.p[1],&ppm);
            projectionMatrixCalc(&triRot.p[2],&triP.p[2],&ppm);
            

            // move
            triP.p[0].x += 1.20f; triP.p[0].y += 1.0f;
            triP.p[1].x += 1.20f; triP.p[1].y += 1.0f;
            triP.p[2].x += 1.20f; triP.p[2].y += 1.0f; 

            // scale
            triP.p[0].x *= 16; 
            triP.p[0].y *= 16; 
            triP.p[1].x *= 16; 
            triP.p[1].y *= 16; 
            triP.p[2].x *= 16; 
            triP.p[2].y *= 16; 
            
            setValueOfBuffer((int)(triP.p[0].x+0.5f),(int)(triP.p[0].y+0.5f),ScreenBuffer);
            //setValueOfBuffer((int)(triP.p[1].x+0.5f),(int)(triP.p[1].y+0.5f),ScreenBuffer);
            setValueOfBuffer((int)(triP.p[2].x+0.5f),(int)(triP.p[2].y+0.5f),ScreenBuffer);
            //drawLine(triP.p[0].x,triP.p[0].y,triP.p[2].x,triP.p[2].y,ScreenBuffer);

        } */
    
    drawLine(3,7,13,7,ScreenBuffer);

    drawBuffer(ScreenWidth,ScreenHeight,ScreenBuffer);
    clearBuffer(ScreenHeight*ScreenWidth,ScreenBuffer);

    clock_t before = clock();
    int msec = 0;
    while((double)(clock() - before) / CLOCKS_PER_SEC < 1/16){};
    time+= 0.0125f;
    }
    
    return 0;
}

void drawLine(float x0, float y0, float x1, float y1, char*buffer)
{
    //printf("in draw line %f %f %f %f \n",x0,y0,x1,y0);
    float yk = 1, xk = 1;
    if(x1-x0 != 0)
        yk = (y1 - y0) / ( x1 - x0);
    if(y1-y0 != 0)
        xk = (x1 - x0) / (y1 - y0);
  
    if(yk > xk)
        for(float y = y0, x = x0; (int)(y+0.5f) != (int)(y1+0.5f); y+= sign(y1-y0))
        {   
            x = yk*(y - y1) + x1;
            setValueOfBuffer((int)(x+0.5f),(int)(y+0.5f),buffer);
        }
    else
        for(float y = y0, x = x0; (int)(x+0.5f) != (int)(x1+0.5f); x+= sign(x1-x0))
        {
            y = xk*(x - x1) + y1;
            setValueOfBuffer((int)(x+0.5f),(int)(y+0.5f),buffer);
        }
        //y = (xk*(x-x1) + y1);
        //x = (yk*(y-y1) + x1);
}

void clearBuffer(int size, char* buffer)
{
    
    for(int i = 0; i < size; i++)
    {
        buffer[i] = ' ';
        if(i%(ScreenWidth+1) == ScreenWidth) buffer[i] = '\n';
        
    }
}

void setValueOfBuffer(int x, int y, char* buffer)
{
    if(x >= 0 && x < ScreenWidth && y >= 0 && y < ScreenHeight)
    buffer[y*(ScreenWidth+1)+x] = '#';
}

void drawBuffer(int w, int h, char* buffer)
{
    system("clear");
    for(int i = 0; i <(w+1)*h; i++)
    {
        printf("%c",buffer[i]);
    }
    
    /*int i = 0;
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
    }*/
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
