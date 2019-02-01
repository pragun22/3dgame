#define GLM_ENABLE_EXPERIMENTAL
#include "plane.h"
#include "main.h"

Plane::Plane(float x, float y, color_t color) {
    this->position = glm::vec3(x, y, 0);
    this->rotation = 0;
    this->pro = 0.0f;
    speed = 1;
    int n = 60;
    int inc = 0;
    float r = 0.6f;
    float r1 = 1.5f;
	GLfloat vertex_buffer_data[18*n];
    float h1 = 3.0f;
    float h2 = 9.0f;
	for (int i = 0; i < 9*n; i+=9)
	{
		float angle = 2*M_PI*inc/n;
		// if(inc==n) angle = 0;
		vertex_buffer_data[i]=r*cos(angle);
		vertex_buffer_data[i+1]=r*sin(angle);
		vertex_buffer_data[i+2]=0;
		vertex_buffer_data[i+3]=r1*cos(angle);;
		vertex_buffer_data[i+4]=r1*sin(angle);;
		vertex_buffer_data[i+5]=h1;
		vertex_buffer_data[i+6]=r*cos(2*M_PI*+(inc+1)/n);
		vertex_buffer_data[i+7]=r*sin(2*M_PI*+(inc+1)/n);
		vertex_buffer_data[i+8]=0;
		inc++;
	}
    inc = 0;
	for (int i = 0; i < 9*n; i+=9)
	{
		float angle = 2*M_PI*inc/n;
        float angle2 = 2*M_PI*(inc+1)/n;
		vertex_buffer_data[9*n+i]=r1*cos(angle);
		vertex_buffer_data[9*n+i+1]=r1*sin(angle);
		vertex_buffer_data[9*n+i+2]=h1;
		vertex_buffer_data[9*n+i+3]=r*cos(angle2);
		vertex_buffer_data[9*n+i+4]=r*sin(angle2);
		vertex_buffer_data[9*n+i+5]=0;
		vertex_buffer_data[9*n+i+6]=r1*cos(2*M_PI*+(inc+1)/n);
		vertex_buffer_data[9*n+i+7]=r1*sin(2*M_PI*+(inc+1)/n);
		vertex_buffer_data[9*n+i+8]=h1;
		inc++;
	}
    inc = 0;
	GLfloat vertex_buffer_data1[18*n];
    r = 1.5f;
    r1 = 1.1f;
	for (int i = 0; i < 9*n; i+=9)
	{
		float angle = 2*M_PI*inc/n;
		vertex_buffer_data1[i]=r*cos(angle);
		vertex_buffer_data1[i+1]=r*sin(angle);
		vertex_buffer_data1[i+2]=h1;
		vertex_buffer_data1[i+3]=r1*cos(angle);;
		vertex_buffer_data1[i+4]=r1*sin(angle);;
		vertex_buffer_data1[i+5]=h2;
		vertex_buffer_data1[i+6]=r*cos(2*M_PI*+(inc+1)/n);
		vertex_buffer_data1[i+7]=r*sin(2*M_PI*+(inc+1)/n);
		vertex_buffer_data1[i+8]=h1;
		inc++;
	}
    inc = 0;
	for (int i = 0; i < 9*n; i+=9)
	{
		float angle = 2*M_PI*inc/n;
        float angle2 = 2*M_PI*(inc+1)/n;
		vertex_buffer_data1[9*n+i]=r1*cos(angle);
		vertex_buffer_data1[9*n+i+1]=r1*sin(angle);
		vertex_buffer_data1[9*n+i+2]=h2;
		vertex_buffer_data1[9*n+i+3]=r*cos(angle2);
		vertex_buffer_data1[9*n+i+4]=r*sin(angle2);
		vertex_buffer_data1[9*n+i+5]=h1;
		vertex_buffer_data1[9*n+i+6]=r1*cos(2*M_PI*+(inc+1)/n);
		vertex_buffer_data1[9*n+i+7]=r1*sin(2*M_PI*+(inc+1)/n);
		vertex_buffer_data1[9*n+i+8]=h2;
		inc++;
	}
        inc = 0;
	GLfloat vertex_tail[18*n];
    r = r1;
    r1 = 1.7f;
    h1 = h2;
    h2 = 11;
	for (int i = 0; i < 9*n; i+=9)
	{
		float angle = 2*M_PI*inc/n;
		vertex_tail[i]=r*cos(angle);
		vertex_tail[i+1]=r*sin(angle);
		vertex_tail[i+2]=h1;
		vertex_tail[i+3]=r1*cos(angle);;
		vertex_tail[i+4]=r1*sin(angle);;
		vertex_tail[i+5]=h2;
		vertex_tail[i+6]=r*cos(2*M_PI*+(inc+1)/n);
		vertex_tail[i+7]=r*sin(2*M_PI*+(inc+1)/n);
		vertex_tail[i+8]=h1;
		inc++;
	}
    inc = 0;
	for (int i = 0; i < 9*n; i+=9)
	{
		float angle = 2*M_PI*inc/n;
        float angle2 = 2*M_PI*(inc+1)/n;
		vertex_tail[9*n+i]=r1*cos(angle);
		vertex_tail[9*n+i+1]=r1*sin(angle);
		vertex_tail[9*n+i+2]=h2;
		vertex_tail[9*n+i+3]=r*cos(angle2);
		vertex_tail[9*n+i+4]=r*sin(angle2);
		vertex_tail[9*n+i+5]=h1;
		vertex_tail[9*n+i+6]=r1*cos(2*M_PI*+(inc+1)/n);
		vertex_tail[9*n+i+7]=r1*sin(2*M_PI*+(inc+1)/n);
		vertex_tail[9*n+i+8]=h2;
		inc++;
	}
    float mov = 3.5f;
    float len = 1.5f;
	const GLfloat vertex_wing_data[] ={
        0.0f, 0.0f, 0.0f+mov,
        0.0f, 0.0f, len+mov,
        5.0f, 0.0f, -1.0f+mov,
        
        5.0f, 0.0f, len+mov,
        0.0f, 0.0f, len+mov,
        5.0f, 0.0f, -1.0f+mov,

        0.0f, 0.0f, 0.0f+mov,
        0.0f, 0.0f, len+mov,
        -5.0f, 0.0f, -1.0f+mov,

        -5.0f, 0.0f, len+mov,
        0.0f, 0.0f, len+mov,
        -5.0f, 0.0f, -1.0f+mov, //lower y

        0.0f, 0.6f, 0.0f+mov,
        0.0f, 0.6f, len+mov,
        5.0f, 0.6f, -1.0f+mov,
        
        5.0f, 0.6f, len+mov,
        0.0f, 0.6f, len+mov,
        5.0f, 0.6f, -1.0f+mov,

        0.0f, 0.6f, 0.0f+mov,
        0.0f, 0.6f, len+mov,
        -5.0f, 0.6f, -1.0f+mov,

        -5.0f, 0.6f, len+mov,
        0.0f, 0.6f, len+mov,
        -5.0f, 0.6f, -1.0f+mov, //upper  y

        0.0f, 0.0f, len+mov,
        5.0f, 0.6f, len+mov,
        5.0f, 0.0f, len+mov,
        
        0.0f, 0.0f, len+mov,
        0.0f, 0.6f, len+mov,
        5.0f, 0.6f, len+mov,

        0.0f, 0.0f, len+mov,
        -5.0f, 0.6f, len+mov,
        -5.0f, 0.0f, len+mov,
        
        0.0f, 0.0f, len+mov,
        0.0f, 0.6f, len+mov,
        -5.0f, 0.6f, len+mov,  // fill in between in front

        0.0f, 0.0f, 0.0f+mov,
        5.0f, 0.0f, -1.0f+mov,
        5.0f, 0.6f, -1.0f+mov,
        
        0.0f, 0.0f, 0.0f+mov,
        0.0f, 0.6f, 0.0f+mov,
        5.0f, 0.6f, -1.0f+mov,

        0.0f, 0.0f, 0.0f+mov,
        0.0f, 0.6f, 0.0f+mov,
        -5.0f, 0.6f, -1.0f+mov,
        
        0.0f, 0.0f, 0.0f+mov,
        0.0f, 0.6f, 0.0f+mov,
        -5.0f, 0.0f, -1.0f+mov,  // fill in between in back

    };
    mov = 9;
    len = 1.2f;
    GLfloat vertex_tail_wing[] ={
        0.0f, 0.0f, 0.0f+mov,
        0.0f, 0.0f, len+mov,
        3.1f, 0.0f, -1.0f+mov,
        
        3.1f, 0.0f, len+mov,
        0.0f, 0.0f, len+mov,
        3.1f, 0.0f, -1.0f+mov,

        0.0f, 0.0f, 0.0f+mov,
        0.0f, 0.0f, len+mov,
        -3.1f, 0.0f, -1.0f+mov,

        -3.1f, 0.0f, len+mov,
        0.0f, 0.0f, len+mov,
        -3.1f, 0.0f, -1.0f+mov, //lower y

        0.0f, 0.6f, 0.0f+mov,
        0.0f, 0.6f, len+mov,
        3.1f, 0.6f, -1.0f+mov,
        
        3.1f, 0.6f, len+mov,
        0.0f, 0.6f, len+mov,
        3.1f, 0.6f, -1.0f+mov,

        0.0f, 0.6f, 0.0f+mov,
        0.0f, 0.6f, len+mov,
        -3.1f, 0.6f, -1.0f+mov,

        -3.1f, 0.6f, len+mov,
        0.0f, 0.6f, len+mov,
        -3.1f, 0.6f, -1.0f+mov, //upper  y

        0.0f, 0.0f, len+mov,
        3.1f, 0.6f, len+mov,
        3.1f, 0.0f, len+mov,
        
        0.0f, 0.0f, len+mov,
        0.0f, 0.6f, len+mov,
        3.1f, 0.6f, len+mov,

        0.0f, 0.0f, len+mov,
        -3.1f, 0.6f, len+mov,
        -3.1f, 0.0f, len+mov,
        
        0.0f, 0.0f, len+mov,
        0.0f, 0.6f, len+mov,
        -3.1f, 0.6f, len+mov,  // fill in between in front

        0.0f, 0.0f, 0.0f+mov,
        3.1f, 0.0f, -1.0f+mov,
        3.1f, 0.6f, -1.0f+mov,
        
        0.0f, 0.0f, 0.0f+mov,
        0.0f, 0.6f, 0.0f+mov,
        3.1f, 0.6f, -1.0f+mov,

        0.0f, 0.0f, 0.0f+mov,
        0.0f, 0.6f, 0.0f+mov,
        -3.1f, 0.6f, -1.0f+mov,
        
        0.0f, 0.0f, 0.0f+mov,
        0.0f, 0.6f, 0.0f+mov,
        -3.1f, 0.0f, -1.0f+mov,  // fill in between in back

    };
    GLfloat vertex_prop[3*n];
    inc = 0;
    r = 2.0f;
	for (int i = 0; i < 3*n; i+=9)
	{
		float angle = 2*M_PI*inc/n;
		// if(inc==n) angle = 0;
		vertex_buffer_data[i]=0;
		vertex_buffer_data[i+1]=0;
		vertex_buffer_data[i+2]=0;
		vertex_buffer_data[i+3]=r*cos(angle);
		vertex_buffer_data[i+4]=r*sin(2*M_PI*+(inc+2)/n);
		vertex_buffer_data[i+5]=0;
		vertex_buffer_data[i+6]=r*cos(2*M_PI*+(inc+3)/n);
		vertex_buffer_data[i+7]=r*sin(2*M_PI*+(inc+5)/n);
		vertex_buffer_data[i+8]=0;
		inc+=6;
	}

    this->propelar = create3DObject(GL_TRIANGLES, 2*n, vertex_buffer_data, color, GL_FILL);
    this->object = create3DObject(GL_TRIANGLES, 6*n, vertex_buffer_data, color, GL_FILL);
    this->object1 = create3DObject(GL_TRIANGLES, 6*n, vertex_buffer_data1, color, GL_FILL);
    this->tail = create3DObject(GL_TRIANGLES, 6*n, vertex_tail, color, GL_FILL);
    this->tail_wing = create3DObject(GL_TRIANGLES, 16*3, vertex_tail_wing, color, GL_FILL);
    this->wing = create3DObject(GL_TRIANGLES, 16*3, vertex_wing_data, color, GL_FILL);
}

void Plane::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    glm::mat4 rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(1, 1, 1));
    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    // rotate          = rotate * glm::translate(glm::vec3(0, -0.6, 0));
    Matrices.model *= (translate * rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object);
    draw3DObject(this->object1);
    draw3DObject(this->wing);
    draw3DObject(this->tail);
    draw3DObject(this->tail_wing);
    draw3DObject(this->propelar);

}

// void Plane::set_position(float x, float y) {
//     this->position = glm::vec3(x, y, 0);
// }

void Plane::tick() {
    this->rotation += speed;
    this->pro += 5.0f;
    // this->position.x -= speed;
    // this->position.y -= speed;
}

