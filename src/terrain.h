#include "main.h"

#ifndef TERRAIN_H
#define TERRAIN_H


class Terrain {
public:
    Terrain() {}
    Terrain(float x, float y,int height, int widht);
    glm::vec3 position;
    float rotation;
    float speedz = 2.0f;
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
    VAO *object1;
    VAO *object2;
};

class Lava {
public:
    Lava() {}
    Lava(float x, float y);
    glm::vec3 position;
    float rotation;
    float speedz = 2.0f;
    int height;
    float s;
    int width;
    void draw(glm::mat4 VP);
    void set_position(float x, float y);
    bool tick(int a);
    double speed;
private:
    VAO *object;
    VAO *object1;
    VAO* tope;
    VAO *object2;
};
class Tapu {
public:
    Tapu() {}
    Tapu(float x, float y);
    glm::vec3 position;
    clock_t timer;
    float rotation;
    std::vector<Lava> lava; 
    float speedz = 2.0f;
    int height;
    int width;
    void draw(glm::mat4 VP);
    void set_position(float x, float y);
    void tick();
    double speed;
private:
    VAO *object;
    VAO *object1;
    VAO* tope;
    VAO *object2;
};
#endif 
