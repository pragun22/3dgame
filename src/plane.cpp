#define GLM_ENABLE_EXPERIMENTAL
#include "plane.h"
#include "main.h"
//this makes cylinder along z axis
// while make_c makes cylinder along y axis
VAO* make_cyl(float x, float z, float r, float r1, float h, float h1,color_t color){
        int n= 40;
        int inc = 0;
        GLfloat vertex_buffer_data[18*n];
        for (int i = 0; i < 9*n; i+=9)
        {
            float angle = 2*M_PI*inc/n;
            // if(inc==n) angle = 0;
            vertex_buffer_data[i]=x+r*cos(angle);
            vertex_buffer_data[i+2]=h;
            vertex_buffer_data[i+1]=z+r*sin(angle);
            vertex_buffer_data[i+3]=x+r1*cos(angle);
            vertex_buffer_data[i+5]=h1;
            vertex_buffer_data[i+4]=z+r1*sin(angle);
            vertex_buffer_data[i+6]=x+r*cos(2*M_PI*+(inc+1)/n);
            vertex_buffer_data[i+8]=h;
            vertex_buffer_data[i+7]=z+r*sin(2*M_PI*+(inc+1)/n);
            inc++;
        }
        inc = 0;
        for (int i = 0; i < 9*n; i+=9)
        {
            float angle = 2*M_PI*inc/n;
            float angle2 = 2*M_PI*(inc+1)/n;
            vertex_buffer_data[9*n+i]=x+r1*cos(angle);
            vertex_buffer_data[9*n+i+2]=h1;
            vertex_buffer_data[9*n+i+1]=z+r1*sin(angle);
            vertex_buffer_data[9*n+i+3]=x+r*cos(angle2);
            vertex_buffer_data[9*n+i+5]=h;
            vertex_buffer_data[9*n+i+4]=z+r*sin(angle2);
            vertex_buffer_data[9*n+i+6]=x+r1*cos(2*M_PI*+(inc+1)/n);
            vertex_buffer_data[9*n+i+8]=h1;
            vertex_buffer_data[9*n+i+7]=z+r1*sin(2*M_PI*+(inc+1)/n);
            inc++;
        }
        return create3DObject(GL_TRIANGLES, 6*n, vertex_buffer_data, color, GL_FILL);
}
Plane::Plane(float x, float y, color_t color) {
    this->position = glm::vec3(x , y, 7.5f);
    this->rotation = 0;
    this->pro = 0.0f;
    this->counter = 0.0f;
    this->tilt = 0.0f;
    this->shoot_timer = clock();
    this->speedx = 0.0f;
    this->speedy = 0.0f;
    this->speedz = 0.0f;
    this->flag = false;
    this->acc = 0.0f;
    speed = 1;
    int n = 60;
    int inc = 0;
    float r = 0.6f;
    float r1 = 1.5f;
	GLfloat vertex_buffer_data[18*n];
    float h1 = 3.0f-7.5f;
    float h2 = 9.0f-7.5f;
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
    h2 = 11-7.5f;
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
    h2 = 15-7.5f;
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
    float mov = 3.5f-7.5f;
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
    mov = 9.0f-7.5f;
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
    // GLfloat vertex_prop[]={
    //     0.0f, 0.0f, 0.0f,
    //     -1.0f, 2.5f, 0.0f,
    //     1.0f, 2.5f, 0.0f,

    //     0.0f, 0.0f, 0.0f,
    //     1.0f, -2.5f, 0.0f,
    //     -1.0f, -2.5f, 0.0f,

    // };

    GLfloat vertex_prop[]={
        0.0f, 0.0f, -7.5f,
        -1.0f, 2.5f, -7.5f,
        1.0f, 2.5f, -7.5f,

        0.0f, 0.0f, -7.5f,
        1.0f, -2.5f, -7.5f,
        -1.0f, -2.5f, -7.5f,

    };
    this->pitch = true;
    this->wing = create3DObject(GL_TRIANGLES, 16*3, vertex_wing_data, COLOR_SILVER, GL_FILL);
    this->propelar = create3DObject(GL_TRIANGLES, 6, vertex_prop, COLOR_RED, GL_FILL);
    this->tail_wing = create3DObject(GL_TRIANGLES, 16*3, vertex_tail_wing, COLOR_JET, GL_FILL);
    this->object1 = create3DObject(GL_TRIANGLES, 6*n, vertex_buffer_data1, COLOR_JET, GL_FILL);
    this->object = create3DObject(GL_TRIANGLES, 6*n, vertex_buffer_data, COLOR_JET, GL_FILL);
    this->tail = create3DObject(GL_TRIANGLES, 6*n, vertex_tail, COLOR_JET, GL_FILL);
    this->fire = create3DObject(GL_TRIANGLES, 6*n, vertex_fire, COLOR_FIRE, GL_FILL);
}

glm::mat4 rotationMatrix(glm::vec3 axis, float angle)
{
    axis = glm::normalize(axis);
    float s = sin(angle);
    float c = cos(angle);
    float oc = 1.0 - c;
    
    return glm::mat4(oc * axis.x * axis.x + c,           oc * axis.x * axis.y - axis.z * s,  oc * axis.z * axis.x + axis.y * s,  0.0,
                oc * axis.x * axis.y + axis.z * s,  oc * axis.y * axis.y + c,           oc * axis.y * axis.z - axis.x * s,  0.0,
                oc * axis.z * axis.x - axis.y * s,  oc * axis.y * axis.z + axis.x * s,  oc * axis.z * axis.z + c,           0.0,
                0.0,                                0.0,                                0.0,                                1.0);
}

void Plane::draw(glm::mat4 VP) {
    // glRotatef(this->tilt, sin(this->counter * M_PI / 180.0f), 0, cos(this->counter * M_PI / 180.0f));
    float ang = this->counter * M_PI / 180.0f;
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    glm::mat4 rotate    = rotationMatrix(glm::vec3(-1*cos(ang),0,sin(ang)),(this->rotation * M_PI / 180.0f));
    glm::mat4 til = rotationMatrix(glm::vec3(sin(ang),0,cos(ang)),(this->tilt * M_PI / 180.0f));
    glm::mat4 count    = glm::rotate((float) (this->counter * M_PI / 180.0f), glm::vec3(0, 1, 0));
    glm::mat4 rotate1    = glm::rotate((float) (this->pro * M_PI / 180.0f), glm::vec3(0, 0, 1));
    Matrices.model *= (translate * til* rotate * count );
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

    for(int i = 0 ; i < this->ammo.size() ; i++){
        this->ammo[i].draw(VP);
    }
    for(int i = 0 ; i < this->bomb.size() ; i++){
        this->bomb[i].draw(VP);
    }

}

void Plane::tilt_fn(int a,float value){
    if(a){
        this->tilt += value;
        float ang = this->counter * M_PI / 180.0f;
        this->position.x += (this->tilt/70.0f)*cos(ang);
        this->position.z -= (this->tilt/70.0f)*sin(ang);
        if(this->tilt > 35.0f) this->tilt= 35.0f;
        if(this->tilt < -35.0f) this->tilt= -35.0f;        
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
        // if(this->counter > 60.0f) this->counter= 60.0f;
        // if(this->counter < -60.0f) this->counter= -60.0f;        
    }
}
void Plane::forward(int a){
    float angle1 = cos((this->counter * M_PI / 180.0f));
    float angle2 = sin((this->counter * M_PI / 180.0f));
    if(a){
        glm::vec3 dir = glm::vec3(-1*angle2,0 ,-1*angle1);
        if(this->acc < 5.0f ) this->acc += 0.01f;
        this->position.z += 0.7f*dir.z*this->acc;
        this->position.x += 0.7f*dir.x*this->acc;
        this->flag = true;
    } 
    else {
        this->flag = false;
        if(this->acc > 1.0f){
            this->acc -= 0.03f;
        }
    if(this->acc < 1.0f) this->acc = 1.0f;
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
    else if(this->pitch){
        this->speedy = 0.0f;
        if(this->rotation<0.0f) this->rotation = 0.0f;
        else if(this->rotation>0.0f) this->rotation -= 1.2f;
    }
}
void Plane::Down(int a){
    if(a){
        this->pitch = false;
        if(this->rotation<-22.0f) this->rotation = -22.0f;
        else if(this->rotation>-22.0f){   
            this->rotation -= 0.6f;
        }
        this->speedy = -0.3f;
    } 
    else if(!this->pitch) {
        this->speedy = 0.0f;
        if(this->rotation>0.0f) this->pitch = true,this->rotation = 0.0f;
        else if(this->rotation<0.0f) this->rotation += 1.2f;
    }
}
void Plane::tick(std::vector<Parachute> &para) {
    this->pro += 8.0f;
    if(this->pro > 360.0f) this->pro = 0.0f;
    // this->position.z -= this->speedz;
    // this->position.x += this->speedx;
    this->position.y += this->speedy;
    for(int i = 0 ; i < this->ammo.size() ; i++){
        if(this->ammo[i].tick(para)){
            this->ammo.erase(this->ammo.begin()+i);
            break;
        }
    }
    for(int i = 0 ; i < this->bomb.size() ; i++){
        this->bomb[i].tick();
    }
}
void Plane::shoot(glm::vec3 dir){
    clock_t end = clock();
    float t =  (float)(end - this->shoot_timer)/CLOCKS_PER_SEC;
    if(t > 0.3){
        this->ammo.push_back(Missile(this->position.x, this->position.y - 2.0f, this->position.z + 2.0f,dir,this->counter));
        this->shoot_timer = clock();
    } 
}
void Plane::drop(){
    clock_t end = clock();
    float t =  (float)(end - this->shoot_timer)/CLOCKS_PER_SEC;
    if(t > 0.3){
        this->bomb.push_back(Bomb(this->position.x, this->position.y - 2.0f, this->position.z + 2.0f,1.0f));
        this->shoot_timer = clock();
    } 
}
Missile::Missile(float x, float y,float z,glm::vec3 yaw,float rot) {
    this->position = glm::vec3(x, y, z);
    this->rotation = rot;
    this->dir = yaw;
    this->object = make_cyl(0,0,3.0f,2.8f,0.0f,-6.0f,COLOR_OLIVE);
    this->object1 = make_cyl(0,0,2.8f,0.4f,-6.0f,-10.0f,COLOR_OLIVE);
}

void Missile::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    glm::mat4 rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(0, 1, 0));
    glm::mat4 scale = glm::scale(glm::vec3(0.3,0.3,0.3));
    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    // rotate          = rotate * glm::translate(glm::vec3(0, -0.6, 0));
    Matrices.model *= (translate * rotate * scale);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object);
    draw3DObject(this->object1);
}

// void Missile::tick() {
//     this->position.x += 1.5f*this->dir.x;
//     this->position.y += 1.5f*this->dir.y;
//     this->position.z += 1.5f*this->dir.z;

// }
bool Missile::tick(std::vector<Parachute> &para) {
    this->position.x += 1.5f*this->dir.x;
    this->position.y += 1.5f*this->dir.y;
    this->position.z += 1.5f*this->dir.z;
    bounding_box_t p;
    p.x = this->position.x - 1.0f;
    p.y = this->position.y - 1.0f;
    p.z = this->position.z;
    p.width = 2.0f;
    p.height = 2.0f;
    p.depth = -3.3f;
    for(int  i = 0; i < para.size(); i++){
        // std::cout<<p.x<<" "<<p.y<<" "<<p.z<<std::endl;
        // std::cout<<para[i].attk.x<<" "<<para[i].attk.y<<" "<<para[i].attk.z<<std::endl;
        if(detect_collision(p,para[i].attk)){
            std::cout<<"pra ke sth"<<std::endl;
            para.erase(para.begin()+i);
            return true;
        }
    }
    return false;
}

Bomb::Bomb(float x, float y,float z,float r) {
    this->position = glm::vec3(x, y, z);
    this->rotation = 0.0f;
    this->rad = r;
    float yc = 0.0f;
    float delta = 0.1f;
     this->object1 =  make_cylinder(0,0,0.1f,0.1f,r,r+0.4f,COLOR_RED);
    while(yc <= r){
        float ycor = yc;
        float theta = sqrt(1-float(yc/r));
        float r0 = r*theta;        
        yc += delta;
        theta = sqrt(1 - float(yc/r));
        float r1 = r * theta;
        this->object.push_back(make_c(0,ycor,0,r0,r1,0.0f,delta,COLOR_REAL_BLACK));
        this->object.push_back(make_c(0,-1.0f*ycor,0,r0,r1,0.0f,delta,COLOR_REAL_BLACK));
    }
}

void Bomb::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    glm::mat4 rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(0, 1, 0));
    glm::mat4 scale = glm::scale(glm::vec3(1,1,1));
    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    // rotate          = rotate * glm::translate(glm::vec3(0, -0.6, 0));
    Matrices.model *= (translate * rotate * scale);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    for(int i = 0 ; i < this->object.size() ; i++){
        draw3DObject(this->object[i]);
    }
    draw3DObject(this->object1);
}

bool Bomb::tick() {
    this->position.y -= 0.2f;
    return false;
}



