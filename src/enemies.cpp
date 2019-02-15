#include "enemies.h"
Parachute::Parachute(float x, float y, float z, float r) {
    this->position = glm::vec3(x, y, z);
    this->rotation = 0;
    speed = 1;
    // Our vertices. Three consecutive floats give a 3D vertex; Three consecutive vertices give a triangle.
    // A cube has 6 faces with 2 triangles each, so this makes 6*2=12 triangles, and 12*3 vertices
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
    // draw3DObject(this->object);
    // draw3DObject(this->object1);
    for(int i = 0 ; i < para.size() ; i++){
        draw3DObject(this->para[i]);
    }
    draw3DObject(this->ropes);
    draw3DObject(this->person);
}


