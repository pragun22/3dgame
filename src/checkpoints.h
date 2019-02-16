#include "main.h"

#ifndef CHECKPOINTS_H
#define CHECKPOINTS_H

class Arrow {
public:
    Arrow() {}
    Arrow(float x, float y,float z);
    glm::vec3 position;
    bool flag;
    float value;
    float rotation;
    float alt;
    void draw(glm::mat4 VP);
    void tick();
private:
    VAO *object;
};
#endif 
