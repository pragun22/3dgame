#include "display.h"
#define GLM_ENABLE_EXPERIMENTAL
#include "main.h"
#include "score.h"
// VAO* make_cylinder(float x, float z, float r, float r1, float h, float h1,color_t color){
//         int n= 40;
//         int inc = 0;
//         GLfloat vertex_buffer_data[18*n];
//         for (int i = 0; i < 9*n; i+=9)
//         {
//             float angle = 2*M_PI*inc/n;
//             // if(inc==n) angle = 0;
//             vertex_buffer_data[i]=x+r*cos(angle);
//             vertex_buffer_data[i+1]=h;
//             vertex_buffer_data[i+2]=z+r*sin(angle);
//             vertex_buffer_data[i+3]=x+r1*cos(angle);
//             vertex_buffer_data[i+4]=h1;
//             vertex_buffer_data[i+5]=z+r1*sin(angle);
//             vertex_buffer_data[i+6]=x+r*cos(2*M_PI*+(inc+1)/n);
//             vertex_buffer_data[i+7]=h;
//             vertex_buffer_data[i+8]=z+r*sin(2*M_PI*+(inc+1)/n);
//             inc++;
//         }
//         inc = 0;
//         for (int i = 0; i < 9*n; i+=9)
//         {
//             float angle = 2*M_PI*inc/n;
//             float angle2 = 2*M_PI*(inc+1)/n;
//             vertex_buffer_data[9*n+i]=x+r1*cos(angle);
//             vertex_buffer_data[9*n+i+1]=h1;
//             vertex_buffer_data[9*n+i+2]=z+r1*sin(angle);
//             vertex_buffer_data[9*n+i+3]=z+r*cos(angle2);
//             vertex_buffer_data[9*n+i+4]=h;
//             vertex_buffer_data[9*n+i+5]=z+r*sin(angle2);
//             vertex_buffer_data[9*n+i+6]=x+r1*cos(2*M_PI*+(inc+1)/n);
//             vertex_buffer_data[9*n+i+7]=h1;
//             vertex_buffer_data[9*n+i+8]=z+r1*sin(2*M_PI*+(inc+1)/n);
//             inc++;
//         }
//         return create3DObject(GL_TRIANGLES, 6*n, vertex_buffer_data, color, GL_FILL);
// }
Display::Display(float x, float y) {
    this->position = glm::vec3(x, y, 0);
    this->rotation = 0;
    this->speedo = 45.0f;
    this->fuelo = 0.3f;
    this->alt = 0.0f;
    int n = 40;
    GLfloat vertex_buffer_data[9*n];
    float r1 = 3.3f;
    float r = 3.0f;
    float h1 = 2.0f;
    int inc = 0;
	for (int i = 0; i < 9*n/2; i+=9)
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
	for (int i = 0; i < 9*n/2; i+=9)
	{
		float angle = 2*M_PI*inc/n;
        float angle2 = 2*M_PI*(inc+1)/n;
		vertex_buffer_data[9*n/2+i]=r1*cos(angle);
		vertex_buffer_data[9*n/2+i+1]=r1*sin(angle);
		vertex_buffer_data[9*n/2+i+2]=h1;
		vertex_buffer_data[9*n/2+i+3]=r*cos(angle2);
		vertex_buffer_data[9*n/2+i+4]=r*sin(angle2);
		vertex_buffer_data[9*n/2+i+5]=0;
		vertex_buffer_data[9*n/2+i+6]=r1*cos(2*M_PI*+(inc+1)/n);
		vertex_buffer_data[9*n/2+i+7]=r1*sin(2*M_PI*+(inc+1)/n);
		vertex_buffer_data[9*n/2+i+8]=h1;
		inc++;
	}
    GLfloat color[9*n];
    for (int i = 0; i < 9*n/2; i+=9)
	{
        float red = 1.0f -(40 + float(i))/256.0f;
        float green = 1.0f - (240.0f - float(i))/256.0f;
        float blue = 60.0f / 256.0f;
		color[i]= red;
		color[i+1]= green;
		color[i+2]= blue;
		color[i+3]= red;
		color[i+4]= green;
		color[i+5]= blue;
		color[i+6]= red;
		color[i+7]= green;
		color[i+8]= blue;
        color[9*n/2 + i]= red;
		color[9*n/2 + i+1]= green;
		color[9*n/2 + i+2]= blue;
		color[9*n/2 + i+3]= red;
		color[9*n/2 + i+4]= green;
		color[9*n/2 + i+5]= blue;
		color[9*n/2 + i+6]= red;
		color[9*n/2 + i+7]= green;
		color[9*n/2 + i+8]= blue;
	
    }
    const GLfloat pointer_data[]={
        -0.3f, 0, 0,
         0.3f, 0, 0,
         0, 2.8f, 0
    };
    const GLfloat cover_fuel[]={
        0.0f, -0.3f, 0.0f,
        0.0f, -0.5f, 0.0f,
        6.7f, -0.3f, 0.0f,
          
        6.7f, -0.3f, 0.0f,
        6.7f, -0.3f, 0.0f,
        0.0f, -0.5f, 0.0f,// up
        
        0.0f, -0.9f, 0.0f,
        0.0f, -1.1f, 0.0f,
        6.7f, -0.9f, 0.0f,
          
        6.7f, -1.1f, 0.0f,
        6.7f, -0.9f, 0.0f,
        0.0f, -1.1f, 0.0f,// bottom

        
    };
    const GLfloat fuel_data[]={
        0.0f, -0.5f, 0.0f,
        0.0f, -0.9f, 0.0f,
        6.6f, -0.5f, 0.0f,
        
        6.6f, -0.5f, 0.0f,
        0.0f, -0.9f, 0.0f,
        6.6f, -0.9f, 0.0f
    };
    const GLfloat cover_altitude[]={
        -0.2, 0 ,0,
        -0.2, -0.2, 0,
        3.2, -0.2, 0,

        3.2, 0 ,0,
        -0.2, -0.2, 0,
        3.2, -0.2, 0,  // down

         -0.2, 6.2 ,0,
        -0.2, 6.0, 0,
        3.2, 6.0, 0,

        3.2, 6.2 ,0,
        -0.2, 6.0, 0,
        3.2, 6.0, 0,  // up

        -0.2, 0, 0,
        0, 0, 0,
        0, 6, 0,

        -0.2, 0, 0,
        -0.2, 6, 0,
        0, 0, 0,  //left

        3, 0, 0,
        3.2, 0, 0,
        3.2, 6, 0,

        3, 0, 0,
        3, 6, 0,
        3.2, 0, 0,  //right
        
    };

    this->speed = create3DObject(GL_TRIANGLES, 3*n, vertex_buffer_data, color, GL_FILL);
    this->pointer = create3DObject(GL_TRIANGLES, 3, pointer_data,COLOR_YELLOW,GL_FILL);
    this->fuel =  create3DObject(GL_TRIANGLES, 6, fuel_data,COLOR_FUEL,GL_FILL);
}

void Display::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    glm::mat4 rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(1, 0, 0));
    glm::mat4 scale = glm::scale(glm::vec3(0.3,0.3,0.3));
    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    // rotate          = rotate * glm::translate(glm::vec3(0, -0.6, 0));
    Matrices.model *= (translate * rotate * scale);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->speed);
    glm::mat4 rotate1 = glm::rotate((float) (this->speedo * M_PI / 180.0f), glm::vec3(0, 0, 1));
    Matrices.model *= (rotate1);
    MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->pointer);
    glm::mat4 translate1 = glm::translate (glm::vec3(this->position.x-1.1f,this->position.y,this->position.z- 3.0f));    // glTranslatef
    glm::mat4 scale1 = glm::scale(glm::vec3(this->fuelo,0.3,0.3));    
    Matrices.model = (translate1  * rotate * scale1 );
    MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->fuel);
    
}

void Display::tick(float sp) {
    float var = 0.5f*sp - 1.5f;
    this->alt += 1.0f;
     this->speedo = -1.0f*90.0f*var;
    if(this->fuelo > 0.0f ) this->fuelo -= 0.00001f;
    
}

Altitude::Altitude(float x, float y){
    this->alt = 0.0f;
    this->position = glm::vec3(x, y, 0);
        const GLfloat cover_altitude[]={
        -0.2, 0 ,0,
        -0.2, -0.2, 0,
        3.2, -0.2, 0,

        3.2, 0 ,0,
        -0.2, 0.0, 0,
        3.2, -0.2, 0,  // down

         -0.2, 6.2 ,0,
        -0.2, 6.0, 0,
        3.2, 6.0, 0,

        3.2, 6.2 ,0,
        -0.2, 6.2, 0,
        3.2, 6.0, 0,  // up

        -0.2, 0, 0,
        0, 0, 0,
        0, 6, 0,

        -0.2, 0, 0,
        -0.2, 6, 0,
        0, 6, 0,  //left

        3, 0, 0,
        3.2, 0, 0,
        3.2, 6, 0,

        3, 0, 0,
        3, 6, 0,
        3.2, 6, 0,  //right
        
    };
    const GLfloat hght[]={
        0,0,0,
        3,0,0,
        0,0.1,0,

        3,0.1,0,
        3,0,0,
        0,0.1,0,

    };
    this->object =  create3DObject(GL_TRIANGLES, 6, hght,COLOR_FIRE,GL_FILL);
    this->cover =  create3DObject(GL_TRIANGLES, 24, cover_altitude,COLOR_REAL_BLACK,GL_FILL);
}

void Altitude::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    glm::mat4 rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(1, 0, 0));
    glm::mat4 scale = glm::scale(glm::vec3(0.1,0.4,1));
    Matrices.model *= (translate * rotate * scale);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->cover);

    glm::mat4 scale1 = glm::scale(glm::vec3(0.1,this->alt,1));
    Matrices.model = (translate * rotate * scale1);
    MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object);
    
}

void Altitude::tick(float h){
    this->alt = (h/1000.0f)*12.0f;
}

Compass::Compass(float x, float y){
    this->alt = 0.0f;
    this->position = glm::vec3(x, y, 0);
    const GLfloat hght[]={
        -0.2,0,0,
        0.2,0,0,
        0,1,0,
        -0.2,0,0,
        0.2,0,0,
        0,-1,0 
    };
    GLfloat color[]={
        COLOR_FIRE.r/256.0f,COLOR_FIRE.g/256.0f, COLOR_FIRE.b/256.0f,
        COLOR_FIRE.r/256.0f,COLOR_FIRE.g/256.0f, COLOR_FIRE.b/256.0f,
        COLOR_FIRE.r/256.0f,COLOR_FIRE.g/256.0f, COLOR_FIRE.b/256.0f,

        COLOR_SILVER.r/256.0f,COLOR_SILVER.g/256.0f, COLOR_SILVER.b/256.0f,
        COLOR_SILVER.r/256.0f,COLOR_SILVER.g/256.0f, COLOR_SILVER.b/256.0f,
        COLOR_SILVER.r/256.0f,COLOR_SILVER.g/256.0f, COLOR_SILVER.b/256.0f,
    };
    this->object =  create3DObject(GL_TRIANGLES, 6, hght,color,GL_FILL);
}

void Compass::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    glm::mat4 rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(0, 0, 1));
    glm::mat4 scale = glm::scale(glm::vec3(0.8,1,1));
    Matrices.model *= (translate * rotate * scale);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object);
    
}

void Compass::tick(float yaw){
    this->rotation = -1*yaw;
}