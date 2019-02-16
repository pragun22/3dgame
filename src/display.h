#include "main.h"

#ifndef DISPLAY_H
#define DISPLAY_H


class Display {
public:
    Display() {}
    Display(float x, float y);
    glm::vec3 position;
    bool flag;
    float rotation;
    float speedo;
    float alt;
    float fuelo;
    void draw(glm::mat4 VP);
    void tick(float sp);
private:
    VAO *speed;
    VAO *pointer;
    VAO *fuel;
    VAO *cover;
};

class Altitude {
public:
    Altitude() {}
    Altitude(float x, float y);
    glm::vec3 position;
    bool flag;
    float rotation;
    float alt;
    void draw(glm::mat4 VP);
    void tick(float h);
private:
    VAO *object;
    VAO *cover;
};

class Compass {
public:
    Compass() {}
    Compass(float x, float y);
    glm::vec3 position;
    bool flag;
    float rotation;
    float alt;
    void draw(glm::mat4 VP);
    void tick(float yaw);
private:
    VAO *object;
    VAO *cover;
};
#endif 
