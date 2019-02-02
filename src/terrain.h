#include "main.h"

#ifndef TERRAIN_H
#define TERRAIN_H


class Terrain {
public:
    Terrain() {}
    Terrain(float x, float y,int height, int widht,float range,float level);
    glm::vec3 position;
    float rotation;
    int height;
    int width;
    double sample(int x, int y);
    void setSample(int x, int y , double value);
    void sampleSquare(int x, int y, int value, double size);
    void sampleDiamond(int x, int y, int size, double value);
    void draw(glm::mat4 VP);
    void set_position(float x, float y);
    void tick();
    double speed;
private:
    VAO *object;
};

#endif 
