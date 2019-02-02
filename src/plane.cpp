#define GLM_ENABLE_EXPERIMENTAL
#include "plane.h"
#include "main.h"

Plane::Plane(float x, float y, color_t color) {
    this->position = glm::vec3(x, y, 0);
    this->rotation = 0;
    this->pro = 0.0f;
    this->counter = 0.0f;
    this->tilt = 0.0f;
    this->speedx = 0.0f;
    this->speedy = 0.0f;
    this->speedz = 2.0f;
    this->flag = false;
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
    GLfloat vertex_fire[18*n];
    r = 0.6f;
    r1 = 0.2f;
    h1 = h2;
    h2 = 15;
	for (int i = 0; i < 9*n; i+=9)
	{
		float angle = 2*M_PI*inc/n;
		vertex_fire[i]=r*cos(angle);
		vertex_fire[i+1]=r*sin(angle);
		vertex_fire[i+2]=h1;
		vertex_fire[i+3]=r1*cos(angle);;
		vertex_fire[i+4]=r1*sin(angle);;
		vertex_fire[i+5]=h2;
		vertex_fire[i+6]=r*cos(2*M_PI*+(inc+1)/n);
		vertex_fire[i+7]=r*sin(2*M_PI*+(inc+1)/n);
		vertex_fire[i+8]=h1;
		inc++;
	}
    inc = 0;
	for (int i = 0; i < 9*n; i+=9)
	{
		float angle = 2*M_PI*inc/n;
        float angle2 = 2*M_PI*(inc+1)/n;
		vertex_fire[9*n+i]=r1*cos(angle);
		vertex_fire[9*n+i+1]=r1*sin(angle);
		vertex_fire[9*n+i+2]=h2;
		vertex_fire[9*n+i+3]=r*cos(angle2);
		vertex_fire[9*n+i+4]=r*sin(angle2);
		vertex_fire[9*n+i+5]=h1;
		vertex_fire[9*n+i+6]=r1*cos(2*M_PI*+(inc+1)/n);
		vertex_fire[9*n+i+7]=r1*sin(2*M_PI*+(inc+1)/n);
		vertex_fire[9*n+i+8]=h2;
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
    GLfloat vertex_prop[]={
        0.0f, 0.0f, 0.0f,
        -1.0f, 2.5f, 0.0f,
        1.0f, 2.5f, 0.0f,

        0.0f, 0.0f, 0.0f,
        1.0f, -2.5f, 0.0f,
        -1.0f, -2.5f, 0.0f,

    };
    this->wing = create3DObject(GL_TRIANGLES, 16*3, vertex_wing_data, COLOR_SILVER, GL_FILL);
    this->propelar = create3DObject(GL_TRIANGLES, 6, vertex_prop, COLOR_RED, GL_FILL);
    this->tail_wing = create3DObject(GL_TRIANGLES, 16*3, vertex_tail_wing, COLOR_JET, GL_FILL);
    this->object1 = create3DObject(GL_TRIANGLES, 6*n, vertex_buffer_data1, COLOR_JET, GL_FILL);
    this->object = create3DObject(GL_TRIANGLES, 6*n, vertex_buffer_data, COLOR_JET, GL_FILL);
    this->tail = create3DObject(GL_TRIANGLES, 6*n, vertex_tail, COLOR_JET, GL_FILL);
    this->fire = create3DObject(GL_TRIANGLES, 6*n, vertex_fire, COLOR_FIRE, GL_FILL);
}

void Plane::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    glm::mat4 rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(1, 0, 0));
    glm::mat4 til    = glm::rotate((float) (this->tilt * M_PI / 180.0f), glm::vec3(0, 0, 1));
    glm::mat4 count    = glm::rotate((float) (this->counter * M_PI / 180.0f), glm::vec3(0, 1, 0));
    glm::mat4 rotate1    = glm::rotate((float) (this->pro * M_PI / 180.0f), glm::vec3(0, 0, 1));
    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    // rotate          = rotate * glm::translate(glm::vec3(0, -0.6, 0));
    Matrices.model *= (translate * rotate * til * count);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object);
    draw3DObject(this->object1);
    draw3DObject(this->wing);
    draw3DObject(this->tail);
    draw3DObject(this->tail_wing);
    Matrices.model *= (rotate1);
    MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->propelar);
    if(this->flag)  draw3DObject(this->fire);

}

// void Plane::set_position(float x, float y) {
//     this->position = glm::vec3(x, y, 0);
// }
void Plane::tilt_fn(int a,float value){
    if(a){
        this->tilt += value;
        this->position.x -= this->tilt/200.0f;
        if(this->tilt > 75.0f) this->tilt= 75.0f;
        if(this->tilt < -75.0f) this->tilt= -75.0f;        
    }
    else{
        if(this->tilt > 0.0f){
            this->tilt -= 1.0f;
            if(this->tilt < 0.0f) this->tilt = 0.0f;
        }
        else if(this->tilt < 0.0f){
            this->tilt += 1.0f;
            if(this->tilt > 0.0f) this->tilt = 0.0f;
        }

    }
}
void Plane::rotate(int a,float value){
    if(a){
        this->counter += value;
        if(this->counter > 60.0f) this->counter= 60.0f;
        if(this->counter < -60.0f) this->counter= -60.0f;        
    }
    else{
        if(this->counter > 0.0f){
            this->counter -= 1.0f;
            if(this->counter < 0.0f) this->counter = 0.0f;
        }
        else if(this->counter < 0.0f){
            this->counter += 1.0f;
            if(this->counter > 0.0f) this->counter = 0.0f;
        }

    }
}
void Plane::forward(int a){
    if(a){
        this->flag = true;
        this->speedz += 0.5f;
        if(this->speedz>10.0f) this->speedz = 10.0f;
    } 
    else {
        this->flag = false;
        this->speedz -= 0.4f;
        if(this->speedz<2.0f) this->speedz = 2.0f;
    }

}
void Plane::Up(int a){
    if(a){
        if(this->rotation>22.0f) this->rotation = 22.0f;
        else if(this->rotation<22.0f){   
            this->rotation += 0.6f;
        }
        this->speedy = 0.3f;
    } 
    else {
        this->speedy = 0.0f;
        if(this->rotation<0.0f) this->rotation = 0.0f;
        else if(this->rotation>0.0f) this->rotation -= 1.2f;
    }
}
void Plane::tick() {
    // this->rotation += speed;
    this->pro += 8.0f;
    if(this->pro > 360.0f) this->pro = 0.0f;
    this->position.z += this->speedz;
    this->position.x += this->speedx;
    this->position.y += this->speedy;
    // this->position.x -= speed;
    // this->position.y -= speed;
}

