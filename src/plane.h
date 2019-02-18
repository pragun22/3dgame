#include "main.h"
#include "enemies.h"
#ifndef PLANE_H
#define PLANE_H

class Missile {
public:
    Missile() {}
    Missile(float x, float y, float z,glm::vec3 yaw,float rot);
    glm::vec3 position;
    bool flag;
    float rotation;
    glm::vec3 dir;
    float pro;
    float counter;
    float tilt;
    float speedx;
    float speedy;
    float speedz;
    void draw(glm::mat4 VP);
    void set_position(float x, float y);
    bool tick(std::vector<Parachute> &para);

    double speed;
private:
    VAO *object;
    VAO *object1;
};
class Bomb {
public:
    Bomb() {}
    Bomb(float x, float y, float z,float yaw);
    glm::vec3 position;
    bool flag;
    float rotation;
    float pro;
    float counter;
    float rad;
    float tilt;
    float speedx;
    float speedy;
    float speedz;
    void draw(glm::mat4 VP);
    void set_position(float x, float y);
    bool tick();

    double speed;
private:
    std::vector<VAO*> object;
    VAO *object1;
};
class Plane {
public:
    Plane() {}
    Plane(float x, float y, color_t color);
    glm::vec3 position;
    bool flag;
    float rotation;
    clock_t shoot_timer;
    float pro;
    std::vector<Missile> ammo;
    std::vector<Bomb> bomb;
    float counter;
    float tilt;
    float speedx;
    float speedy;
    float acc;
    float speedz;
    bool pitch;
    void draw(glm::mat4 VP);
    void Up(int a);
    void Down(int a);
    void forward(int a);
    void tilt_fn(int a,float value);
    void rotate(int a,float v);    
    void set_position(float x, float y);
    void tick(std::vector<Parachute> &para);
    void shoot(glm::vec3 dir);
    void drop();
    double speed;
private:
    VAO *object;
    VAO *object1;
    VAO *wing;
    VAO *tail;
    VAO *tail_wing;
    VAO *propelar;
    VAO *fire;
};

#endif 
