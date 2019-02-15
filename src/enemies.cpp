#include "enemies.h"
VAO* make_c(float x, float y, float z, float r, float r1, float h, float h1,color_t color){
        int n= 40;
        int inc = 0;
        GLfloat vertex_buffer_data[18*n];
        for (int i = 0; i < 9*n; i+=9)
        {
            float angle = 2*M_PI*inc/n;
            // if(inc==n) angle = 0;
            vertex_buffer_data[i]=x+r*cos(angle);
            vertex_buffer_data[i+1]=y+h;
            vertex_buffer_data[i+2]=z+r*sin(angle);
            vertex_buffer_data[i+3]=x+r1*cos(angle);
            vertex_buffer_data[i+4]=y+h1;
            vertex_buffer_data[i+5]=z+r1*sin(angle);
            vertex_buffer_data[i+6]=x+r*cos(2*M_PI*+(inc+1)/n);
            vertex_buffer_data[i+7]=y+h;
            vertex_buffer_data[i+8]=z+r*sin(2*M_PI*+(inc+1)/n);
            inc++;
        }
        inc = 0;
        for (int i = 0; i < 9*n; i+=9)
        {
            float angle = 2*M_PI*inc/n;
            float angle2 = 2*M_PI*(inc+1)/n;
            vertex_buffer_data[9*n+i]=x+r1*cos(angle);
            vertex_buffer_data[9*n+i+1]=y+h1;
            vertex_buffer_data[9*n+i+2]=z+r1*sin(angle);
            vertex_buffer_data[9*n+i+3]=x+r*cos(angle2);
            vertex_buffer_data[9*n+i+4]=y+h;
            vertex_buffer_data[9*n+i+5]=z+r*sin(angle2);
            vertex_buffer_data[9*n+i+6]=x+r1*cos(2*M_PI*+(inc+1)/n);
            vertex_buffer_data[9*n+i+7]=y+h1;
            vertex_buffer_data[9*n+i+8]=z+r1*sin(2*M_PI*+(inc+1)/n);
            inc++;
        }
        return create3DObject(GL_TRIANGLES, 6*n, vertex_buffer_data, color, GL_FILL);
        // return create3DObject(GL_TRIANGLES_ADJACENCY, 6*n, vertex_buffer_data, color, GL_FILL);
        // return create3DObject(GL_TRIANGLE_STRIP, 6*n, vertex_buffer_data, color, GL_FILL);
        // return create3DObject(GL_TRIANGLE_LIST_SUN, 6*n, vertex_buffer_data, color, GL_FILL);
        // return create3DObject(GL_TRIANGLE_MESH_SUN, 6*n, vertex_buffer_data, color, GL_FILL);
}
Parachute::Parachute(float x, float y, float z, float r) {
    this->position = glm::vec3(x, y, z);
    this->rotation = 0;
    speed = 1;
    // Our vertices. Three consecutive floats give a 3D vertex; Three consecutive vertices give a triangle.
    // A cube has 6 faces with 2 triangles each, so this makes 6*2=12 triangles, and 12*3 vertices
    float yc = 0.0f;
    float delta = 0.1f;
    GLfloat ropes_data[]={
        -1-1
    };
    while(yc <= r){
        float ycor = yc;
        float theta = sqrt(1-float(yc/r));
        float r0 = r*theta;        
        yc += delta;
        theta = sqrt(1 - float(yc/r));
        float r1 = r * theta;
        this->para.push_back(make_c(0,ycor,0,r0,r1,0.0f,delta,COLOR_REAL_BLACK));
        // this->para.push_back(make_c(0,-1.0f*ycor,0,r0,r1,0.0f,delta,COLOR_REAL_BLACK));
    }

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
}


