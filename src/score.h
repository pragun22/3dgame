#include "main.h"
#ifndef SCORE_H
#define SCORE_H


class Zero {
public:
    Zero() {}
    Zero(float x, float y);
    glm::vec3 position;
    float rotation;
    void draw(glm::mat4 VP);
    void move();
    void tick();
    void set_position(float x, float y);
    bool detect_collision(bounding_box_t a);
private:
    VAO *object;
};

class One {
public:
    One() {}
    One(float x, float y);
    glm::vec3 position;
    float rotation;
    void draw(glm::mat4 VP);
    void move();
    void tick();
    void set_position(float x, float y);
    bool detect_collision(bounding_box_t a);
private:
    VAO *object;
};

class Two {
public:
    Two() {}
    Two(float x, float y);
    glm::vec3 position;
    float rotation;
    void draw(glm::mat4 VP);
    void move();
    void tick();
    void set_position(float x, float y);
    bool detect_collision(bounding_box_t a);
private:
    VAO *object;
};

class Three {
public:
    Three() {}
    Three(float x, float y);
    glm::vec3 position;
    float rotation;
    void draw(glm::mat4 VP);
    void move();
    void tick();
    void set_position(float x, float y);
    bool detect_collision(bounding_box_t a);
private:
    VAO *object;
};

class Four {
public:
    Four() {}
    Four(float x, float y);
    glm::vec3 position;
    float rotation;
    void draw(glm::mat4 VP);
    void move();
    void tick();
    void set_position(float x, float y);
    bool detect_collision(bounding_box_t a);
private:
    VAO *object;
};

class Five {
public:
    Five() {}
    Five(float x, float y);
    glm::vec3 position;
    float rotation;
    void draw(glm::mat4 VP);
    void move();
    void tick();
    void set_position(float x, float y);
    bool detect_collision(bounding_box_t a);
private:
    VAO *object;
};

class Six {
public:
    Six() {}
    Six(float x, float y);
    glm::vec3 position;
    float rotation;
    void draw(glm::mat4 VP);
    void move();
    void tick();
    void set_position(float x, float y);
    bool detect_collision(bounding_box_t a);
private:
    VAO *object;
};

class Seven {
public:
    Seven() {}
    Seven(float x, float y);
    glm::vec3 position;
    float rotation;
    void draw(glm::mat4 VP);
    void move();
    void tick();
    void set_position(float x, float y);
    bool detect_collision(bounding_box_t a);
private:
    VAO *object;
};

class Eight {
public:
    Eight() {}
    Eight(float x, float y);
    glm::vec3 position;
    float rotation;
    void draw(glm::mat4 VP);
    void move();
    void tick();
    void set_position(float x, float y);
    bool detect_collision(bounding_box_t a);
private:
    VAO *object;
};
class Nine {
public:
    Nine() {}
    Nine(float x, float y);
    glm::vec3 position;
    float rotation;
    void draw(glm::mat4 VP);
    void move();
    void tick();
    void set_position(float x, float y);
    bool detect_collision(bounding_box_t a);
private:
    VAO *object;
};

#endif // BALL_H
