#include "terrain.h"
#include "main.h"
Terrain::Terrain(float x, float y, int height, int width) {
        float w = width;
        float h = height;
        float span = 5.0f;
        this->position = glm::vec3(x, -7.0f, y);
        this->rotation = 0.0f;
        this->height = height;
        this->width = width;
        this->speedz = 2.0f;
        const GLfloat vertex[]={
            0.0f,0.0f,0.0f,
            w, 0.0f, 0.0f,
            0.0f, span, 0.0f,

            w, 0.0f, 0.0f,
            0.0f, span, 0.0f,
            w, span, 0.0f,

            0.0f,0.0f,-h,
            w, 0.0f, -h,
            0.0f, span, -h,

            w, 0.0f, -h,
            0.0f, span, -h,
            w, span, -h, // front view

            0.0f, span, 0.0f,
            w, span, -h,
            0.0f, span, -h,

            0.0f, span, 0.0f,
            w, span, -h,
            w, span, 0.0f,
            
            0.0f, 0.0f, 0.0f,
            w, 0.0f, -h,
            0.0f, 0.0f, -h,

            0.0f, 0.0f, 0.0f,
            w, 0.0f, -h,
            w, 0.0f, 0.0f, // upper view

            0.0f, span, 0.0f,
            0.0f, 0.0f, 0.0f,
            0.0f, span, -h,

            0.0f, 0.0f, 0.0f,
            0.0f, span, -h,
            0.0f, 0.0f, -h, 

            w, span, 0.0f,
            w, 0.0f, 0.0f,
            w, span, -h,

            w, 0.0f, 0.0f,
            w, span, -h,
            w, 0.0f, -h             
        };
        GLfloat normal[36*3];
        for(int i = 0; i < 36*3; i+=3)
        {
            normal[i] = 0.0f;
            normal[i+1] = 0.0f;
            normal[i+2] = 0.0f;
        }
    
    this->object = create3DObject(GL_TRIANGLES, 12*3, vertex, COLOR_TEAL, normal, GL_FILL);
}
void Terrain::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    glm::mat4 rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(1, 1, 1));
    Matrices.model *= (translate * rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object);
}

void Terrain::set_position(float x, float y) {
    this->position = glm::vec3(x, y, 0);
}

void Terrain::tick() {
    this->position.z -= this->speedz;
}

VAO* make_cylinder(float x, float z, float r, float r1, float h, float h1,color_t color){
        int n= 40;
        int inc = 0;
        GLfloat vertex_buffer_data[18*n];
        for (int i = 0; i < 9*n; i+=9)
        {
            float angle = 2*M_PI*inc/n;
            // if(inc==n) angle = 0;
            vertex_buffer_data[i]=x+r*cos(angle);
            vertex_buffer_data[i+1]=h;
            vertex_buffer_data[i+2]=z+r*sin(angle);
            vertex_buffer_data[i+3]=x+r1*cos(angle);
            vertex_buffer_data[i+4]=h1;
            vertex_buffer_data[i+5]=z+r1*sin(angle);
            vertex_buffer_data[i+6]=x+r*cos(2*M_PI*+(inc+1)/n);
            vertex_buffer_data[i+7]=h;
            vertex_buffer_data[i+8]=z+r*sin(2*M_PI*+(inc+1)/n);
            inc++;
        }
        inc = 0;
        for (int i = 0; i < 9*n; i+=9)
        {
            float angle = 2*M_PI*inc/n;
            float angle2 = 2*M_PI*(inc+1)/n;
            vertex_buffer_data[9*n+i]=x+r1*cos(angle);
            vertex_buffer_data[9*n+i+1]=h1;
            vertex_buffer_data[9*n+i+2]=z+r1*sin(angle);
            vertex_buffer_data[9*n+i+3]=x+r*cos(angle2);
            vertex_buffer_data[9*n+i+4]=h;
            vertex_buffer_data[9*n+i+5]=z+r*sin(angle2);
            vertex_buffer_data[9*n+i+6]=x+r1*cos(2*M_PI*+(inc+1)/n);
            vertex_buffer_data[9*n+i+7]=h1;
            vertex_buffer_data[9*n+i+8]=z+r1*sin(2*M_PI*+(inc+1)/n);
            inc++;
        }
        return create3DObject(GL_TRIANGLES, 6*n, vertex_buffer_data, color, GL_FILL);
}
Tapu::Tapu(float x, float y){
        this->speedz = 2.0f;
        this->position = glm::vec3(x, -1.0f, y);
        this->rotation = 0.0f;
        int n= 50;
        int inc = 0;
        this->timer = clock();
        float r1 = 19.0f;
        GLfloat vertex_buffer_data[9*n];
        float h1 = 1.0f;
        inc = 0;
        for (int i = 0; i < 9*n; i+=9){
            float angle = 2*M_PI*inc/n;
            // if(inc==n) angle = 0;
            // float r = (((rand()+1)%2)/4.0f)* (r1);
            vertex_buffer_data[i]=r1*cos(angle);
            vertex_buffer_data[i+1]=h1;
            vertex_buffer_data[i+2]=r1*sin(angle);
            vertex_buffer_data[i+3]=0;
            vertex_buffer_data[i+4]=h1;
            vertex_buffer_data[i+5]=0;
            vertex_buffer_data[i+6]=r1*cos(2*M_PI*+(inc+1)/n);
            vertex_buffer_data[i+7]=h1;
            vertex_buffer_data[i+8]=r1*sin(2*M_PI*+(inc+1)/n);
            inc++;
	    }
        this->object1 = make_cylinder(0, 0, 25.5f, 15.0f, 0 , 1.0f,COLOR_GROUND);
        this->object = create3DObject(GL_TRIANGLES, 3*n, vertex_buffer_data, COLOR_GRAY, GL_FILL);
        this->tope = make_cylinder(0.0f,0.0f,15.0f,2.0f, 3.0f, 15.0f,COLOR_VOL);

}
void Tapu::draw(glm::mat4 VP) {
    for(int i = 0; i < this->lava.size(); i++){
        this->lava[i].draw(VP);
    }
    Matrices.model = glm::mat4(1.0);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    glm::mat4 rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(1, 1, 1));
    Matrices.model *= (translate * rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object);
    draw3DObject(this->tope);
    draw3DObject(this->object1);
}

void Tapu::set_position(float x, float y) {
    this->position = glm::vec3(x, y, 0);
}

void Tapu::tick(bounding_box_t air) {
    clock_t end = clock();
    int elape = (int)(end-this->timer)/CLOCKS_PER_SEC;
    if(elape > 4){
        this->lava.push_back(Lava(this->position.x, this->position.z));
        this->timer = clock();
    } 
    for(int i = 0; i < this->lava.size(); i++){
        if(this->lava[i].tick(rand()%2)){
            this->lava.erase(this->lava.begin()+i);
        }
    }
    bounding_box_t box;
    box.x = this->position.x-15.0f;
    box.y = this->position.y;
    box.z = this->position.z+15.0f;
    box.width = 30.0f;
    box.depth = -30.0f;
    box.height = 60.0f;
    // if(detect_collision(air,box)) std::cout<<" hel = int main "<<rand() << std::endl;
}

Lava::Lava(float x, float y){
        this->position = glm::vec3(x, 15.0f, y);
        this->rotation = 0.0f;
        this->s = 0.5;
    this->object = make_cylinder(0.0f,0.0f,3.0f,3.0f,0.0f,1.5f,COLOR_SLATE_GRAY);

}
void Lava::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    glm::mat4 scale = glm::scale(glm::vec3(this->s,0.4,this->s));
    glm::mat4 rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(1, 1, 1));
    Matrices.model *= (translate * rotate*scale);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object);
}

bool Lava::tick(int a) {
    this->position.y += 0.05f;
    this->s += 0.016f;
    if(this->s>4.0f) return true;
    return false;
}

Canon::Canon(float x, float y){
        this->speedz = 2.0f;
        this->position = glm::vec3(x, -1.0f, y);
        this->rotation = glm::vec3(0.0f, 0.0f, 0.0f);
        this->shoot_timer = clock();
        int n= 50;
        int inc = 0;
        this->timer = clock();
        float r1 = 20.0f;
        GLfloat vertex_buffer_data[9*n];
        float h1 = 1.0f;
        inc = 0;
        for (int i = 0; i < 9*n; i+=9){
            float angle = 2*M_PI*inc/n;
            vertex_buffer_data[i]=r1*cos(angle);
            vertex_buffer_data[i+1]=h1;
            vertex_buffer_data[i+2]=r1*sin(angle);
            vertex_buffer_data[i+3]=0;
            vertex_buffer_data[i+4]=h1;
            vertex_buffer_data[i+5]=0;
            vertex_buffer_data[i+6]=r1*cos(2*M_PI*+(inc+1)/n);
            vertex_buffer_data[i+7]=h1;
            vertex_buffer_data[i+8]=r1*sin(2*M_PI*+(inc+1)/n);
            inc++;
	    }
        GLfloat wheel_buffer_data[18*n];
        inc = 0;
        float r = 2.0f;
        float y_offset = 1.0f;
        float x_offset = 3.5f;
        for (int i = 0; i < 9*n; i+=9){
            float angle = 2*M_PI*inc/n;
            wheel_buffer_data[i]=-1*x_offset;
            wheel_buffer_data[i+1]=y_offset+r*sin(angle);
            wheel_buffer_data[i+2]=r*cos(angle);
            wheel_buffer_data[i+3]=-1*x_offset;
            wheel_buffer_data[i+4]=y_offset+0;
            wheel_buffer_data[i+5]=0;
            wheel_buffer_data[i+6]=-1*x_offset;
            wheel_buffer_data[i+7]=y_offset+r*sin(2*M_PI*+(inc+1)/n);
            wheel_buffer_data[i+8]=r*cos(2*M_PI*+(inc+1)/n);
            inc++;
	    }
        inc = 0;
        for (int i = 0; i < 9*n; i+=9){
            float angle = 2*M_PI*inc/n;
            // if(inc==n) angle = 0;
            // float r = (((rand()+1)%2)/4.0f)* (r1);
            wheel_buffer_data[9*n+i]=x_offset;
            wheel_buffer_data[9*n+i+1]=y_offset+r*sin(angle);
            wheel_buffer_data[9*n+i+2]=r*cos(angle);
            wheel_buffer_data[9*n+i+3]=x_offset;
            wheel_buffer_data[9*n+i+4]=y_offset+0;
            wheel_buffer_data[9*n+i+5]=0;
            wheel_buffer_data[9*n+i+6]=x_offset;
            wheel_buffer_data[9*n+i+7]=y_offset+r*sin(2*M_PI*+(inc+1)/n);
            wheel_buffer_data[9*n+i+8]=r*cos(2*M_PI*+(inc+1)/n);
            inc++;
	    }
        this->object1 = make_cylinder(0, 0, 25.5f, 20.0f, 0 , 1.0f,COLOR_GROUND);
        this->object = create3DObject(GL_TRIANGLES, 3*n, vertex_buffer_data, COLOR_GREE, GL_FILL);
        this->object2 = create3DObject(GL_TRIANGLES, 6*n, wheel_buffer_data, COLOR_BROWN, GL_FILL);
        this->tope = make_cylinder(0.0f,0.0f,3.5f,2.0f, 1.0f, 15.0f,COLOR_REAL_BLACK);


}
void Canon::draw(glm::mat4 VP) {
    for(int i = 0; i < this->gola.size(); i++){
        this->gola[i].draw(VP);
    }
    Matrices.model = glm::mat4(1.0);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    glm::mat4 rotate_x    = glm::rotate((float) (this->rotation.x), glm::vec3(1, 0, 0));
    glm::mat4 rotate_y    = glm::rotate((float) (this->rotation.y), glm::vec3(0, 1, 0));
    glm::mat4 rotate_z    = glm::rotate((float) (this->rotation.z), glm::vec3(0, 0, 1));
    Matrices.model *= (translate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object);
    draw3DObject(this->object1);
    glm::mat4 scale = glm::scale(glm::vec3(1.5,1.5,1.5));
    Matrices.model = ( translate * scale);
    MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object2);
    Matrices.model *= ( rotate_z * rotate_y * rotate_x );
    MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->tope);
}

void Canon::set_position(float x, float y) {
    this->position = glm::vec3(x, y, 0);
}
void Canon::shoot(Plane* plane){
    clock_t end = clock();
    float t =  (float)(end - this->shoot_timer)/CLOCKS_PER_SEC;
    float dis = glm::distance(plane->position,this->position);
    if(t > 5.3f && dis <250.0f){
        float b = plane->position.y - this->position.y;
        float a = plane->position.x - this->position.x;
        float c = plane->position.z - this->position.z;
        // std::cout<<"shooting begins"<<std::endl;
        // std::cout<<a<<"//"<<b<<"//"<<c<<std::endl;
        glm::vec3 dir = glm::vec3(a,b,c);
        dir = normalize(dir);
        // std::cout<<dir.x<<"  "<<dir.y<<"  "<<dir.z<<" this is the direction"<<std::endl;
        this->gola.push_back(Gola(this->position.x, this->position.y + 2.0f, this->position.z ,2.8f,dir));
        this->shoot_timer = clock();
    } 
}
// float min(int a,int b)
// {
//     return a>b?b:a;
// }
float maxu(float a,float b)
{
    return a>b?a:b;
}

bool Canon::tick(Plane* plane,bounding_box_t air) {
        bounding_box_t box;
    box.x = this->position.x-25.0f;
    box.y = this->position.y;
    box.z = this->position.z+25.0f;
    box.width = 50.0f;
    box.depth = -50.0f;
    box.height = 2.0f;
    float a = plane->position.y - this->position.y;
    float b = plane->position.x - this->position.x;
    float c = plane->position.z - this->position.z;
    this->rotation.y = atan(float(b/c));
    this->rotation.x = atan(float(c/a));
    // this->rotation.z = atan(-1*float(b/a));
    // std::cout<<this->rotation.x<<"-this is position x"<<std::endl;
    for(int  i = 0; i < this->gola.size(); i++){
            if(this->gola[i].tick(air)){
                this->gola.erase(this->gola.begin()+i);
                break;
            }
    }
    for(int i = 0 ; i < plane->bomb.size() ; i++){
            bounding_box_t barod;
            barod.x = plane->bomb[i].position.x-plane->bomb[i].rad;
            barod.y = plane->bomb[i].position.y-plane->bomb[i].rad;
            barod.z = plane->bomb[i].position.z-plane->bomb[i].rad;
            barod.depth = -2*plane->bomb[i].rad;
            barod.height = 2 * plane->bomb[i].rad;
            barod.width = 2 * plane->bomb[i].rad;
            if(detect_collision(barod,box)) 
            {
                plane->bomb.erase(plane->bomb.begin()+i);
                return true;
            }
    }
    return false;
    
}
Gola::Gola(float x, float y,float z, float r, glm::vec3 dir){
    this->speed = 2.0f;
    this->position = glm::vec3(x, y, z);
    this->rotation = 0.0f; 
    this->rad  = r;
    this->dir = dir;  
    this->timer = clock();
        float yc = 0.0f;
    float delta = 0.1f;
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
void Gola::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    glm::mat4 rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(1, 1, 1));
    Matrices.model *= (translate * rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    for(int i=0 ; i<this->object.size() ; i++ ) draw3DObject(this->object[i]);
}
bool Gola::tick(bounding_box_t air){
    clock_t end = clock();
    int tame = (int)(end - this->timer)/CLOCKS_PER_SEC;
    if(tame > 9) return true;
    bounding_box_t gol;
    this->position.x = this->position.x + this->speed*(this->dir.x);
    this->position.y = this->position.y + this->speed*(this->dir.y);
    this->position.z = this->position.z + this->speed*(this->dir.z);
    gol.x = this->position.x - this->rad;
    gol.y = this->position.y - this->rad;
    gol.z = this->position.z - this->rad;
    gol.height = 2*this->rad;
    gol.width = 2*this->rad;
    gol.depth = 2*this->rad;
    if(detect_collision(air,gol)) exit(0);
    return false;
}