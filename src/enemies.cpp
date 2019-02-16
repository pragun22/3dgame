#include "enemies.h"
Parachute::Parachute(float x, float y, float z, float r) {
    this->position = glm::vec3(x, y, z);
    this->rotation = 0;
    speed = 1;
    float yc = 0.0f;
    float delta = 0.1f;
    GLfloat ropes_data[]={
        -1*r, 0, 0,
        -1*(r/6.0f), -1*r, -0.2f,
        -1*(r/6.0f), -1*r, 0.2f,

        r, 0, 0,
        (r/6.0f), -1*r, -0.2f,
        (r/6.0f), -1*r, 0.2f,
    };
    GLfloat person_data[]={
        -1*(r/6.0f), -1*r , 0,
        -1*(r/6.0f), -1*r*1.5f , 0,
        (r/6.0f), -1*r , 0,
        
        (r/6.0f), -1*r , 0,
        (r/6.0f), -1*r*1.5f , 0,
        -1*(r/6.0f), -1*r*1.5f , 0, //body

        -1*(r/6.0f), -1*r*1.2f , 0,
        (r/6.0f), -1*r*1.2f , 0,
        (r/6.0f), -1.8f*r , 0,

        -1*(r/6.0f), -1*r*1.2f , 0,
        (r/6.0f), -1*r*1.2f , 0,
        -1*(r/6.0f), -1.8f*r , 0, //pants

        -1*(r/9.0f), -1*r, 0,
        (r/9.0f), -1*r , 0,
        (r/9.0f), -0.8f*r , 0,

        -1*(r/9.0f), -1*r , 0,
        (r/9.0f), -1*r , 0,
        -1*(r/9.0f), -0.8f*r , 0, //body
    };
    while(yc <= r){
        float ycor = yc;
        float theta = sqrt(1-float(yc/r));
        float r0 = r*theta;        
        yc += delta;
        theta = sqrt(1 - float(yc/r));
        float r1 = r * theta;
        this->para.push_back(make_c(0,ycor,0,r0,r1,0.0f,delta,COLOR_SEA_GREEN));
        // this->para.push_back(make_c(0,-1.0f*ycor,0,r0,r1,0.0f,delta,COLOR_REAL_BLACK));
    }
    this->ropes = create3DObject(GL_TRIANGLES, 6, ropes_data, COLOR_REAL_BLACK, GL_FILL); 
    this->person = create3DObject(GL_TRIANGLES, 18, person_data, COLOR_WOOD_GREEN, GL_FILL); 

}

void Parachute::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    glm::mat4 scale = glm::scale(glm::vec3(2,2,2));
    glm::mat4 rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(1, 0, 0));
    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    // rotate          = rotate * glm::translate(glm::vec3(0, -0.6, 0));
    Matrices.model *= (translate * rotate*scale);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    for(int i = 0 ; i < para.size() ; i++){
        draw3DObject(this->para[i]);
    }
    draw3DObject(this->ropes);
    draw3DObject(this->person);
}


Ring::Ring(float x, float y, float z,float r) {
    this->position = glm::vec3(x, y, z);
    this->rotation = 0.0f;
    int n= 40;
    int inc = 0;
    GLfloat vertex_buffer_data[18*n];
    float R = r + 0.1f;
    float h = 0.0f;
    float h1 = 0.7f;
    for (int i = 0; i < 9*n; i+=9)
    {
        float angle = 2*M_PI*inc/n;
        // if(inc==n) angle = 0;
        float r1 = R + float(rand()%3)/6.0f;
        vertex_buffer_data[i]=r*cos(angle);
        vertex_buffer_data[i+2]=h;
        vertex_buffer_data[i+1]=r*sin(angle);
        vertex_buffer_data[i+3]=r1*cos(angle);
        vertex_buffer_data[i+5]=h1;
        vertex_buffer_data[i+4]=r1*sin(angle);
        vertex_buffer_data[i+6]=r*cos(2*M_PI*+(inc+1)/n);
        vertex_buffer_data[i+8]=h;
        vertex_buffer_data[i+7]=r*sin(2*M_PI*+(inc+1)/n);
        inc++;
    }
    inc = 0;
    for (int i = 0; i < 9*n; i+=9)
    {
        float angle = 2*M_PI*inc/n;
        float angle2 = 2*M_PI*(inc+1)/n;
        float r1 = R + float(rand()%3)/6.0f;
        vertex_buffer_data[9*n+i]=r1*cos(angle);
        vertex_buffer_data[9*n+i+2]=h1;
        vertex_buffer_data[9*n+i+1]=r1*sin(angle);
        vertex_buffer_data[9*n+i+3]=r*cos(angle2);
        vertex_buffer_data[9*n+i+5]=h;
        vertex_buffer_data[9*n+i+4]=r*sin(angle2);
        vertex_buffer_data[9*n+i+6]=r1*cos(2*M_PI*+(inc+1)/n);
        vertex_buffer_data[9*n+i+8]=h1;
        vertex_buffer_data[9*n+i+7]=r1*sin(2*M_PI*+(inc+1)/n);
        inc++;
    }
    this->object = create3DObject(GL_TRIANGLES, 6*n, vertex_buffer_data, COLOR_SMOKE, GL_FILL);
}
void Ring::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    glm::mat4 rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(0, 0, 1));
    Matrices.model *= (translate * rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object);
}

void Ring::set_position(float x, float y) {
    this->position = glm::vec3(x, y, 0);
}

void Ring::tick() {
    this->rotation += 1.0f;
    if(this->rotation > 360.0f) this->rotation = 0.0f;
}