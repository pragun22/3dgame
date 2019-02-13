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
    void draw(glm::mat4 VP);
    void tick();
private:
    VAO *speed;
    VAO *pointer;
    VAO *fuel;
};

#endif 