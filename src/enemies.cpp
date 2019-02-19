#include "enemies.h"
float t;
Parachute::Parachute(float x, float y, float z, float r) {
    this->position = glm::vec3(x, y, z);
    this->rotation = 0;
    this->rad = r;
    this->mov_ang=0.0f;
    this->speedy = 0.01f;
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
    color_t color[3];
    color[0] = COLOR_BLACK;
    color[1] = COLOR_VOILET_RED;
    color[2] = COLOR_SLATE_GRAY;
    int inc = 0;
    float theta = 0.0f;
    while(yc <= r){
    // while(theta <= 90.0f){
        float ycor = yc;
        float theta = sqrt(1-float(yc/r));
        float r0 = r*theta;        
        yc += delta;
        theta = sqrt(1 - float(yc/r));
        float r1 = r * theta;
        // float r0 = r*cos((float)(theta*M_PI/180.0f));
        // float r1 = r*cos((float)((theta+1.0f)*M_PI/180.0f));
        // float ycor = r*(1-sin(theta));
        this->para.push_back(make_c(0,ycor,0,r0,r1,0.0f,delta,color[inc%3]));
        inc++;
        // theta+=1.0f;
    }
    this->ropes = create3DObject(GL_TRIANGLES, 6, ropes_data, COLOR_REAL_BLACK, GL_FILL); 
    this->person = create3DObject(GL_TRIANGLES, 18, person_data, COLOR_REAL_BLACK, GL_FILL); 
    bounding_box_t temp;
    temp.x = this->position.x - 2.0f*r;
    temp.z = this->position.z + 2.0f*r;
    temp.y = this->position.y - 3.6f*r;
    temp.width = 4*r;
    temp.height = 5.6f*r;
    temp.depth = -4*r;
    this->attk = temp;
    t = x;


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
bool Parachute::tick(){
    this->speedy -= (1.0f/60.0f)*0.008f;
    this->position.y += this->speedy;
    this->mov_ang += 0.7f;
    if(this->mov_ang > 360.0f) this->mov_ang = 0.0f;
    this->position.x = t + 6*cos((float) (this->mov_ang * M_PI / 180.0f));
    bounding_box_t temp;
    temp.x = this->position.x - 2.0f*this->rad;
    temp.z = this->position.z + 2.0f*this->rad;
    temp.y = this->position.y - 3.6f*this->rad;
    temp.width = 4*this->rad;
    temp.height = 5.6f*this->rad;
    temp.depth = -4*this->rad;
    this->attk = temp;
    if(this->position.y < 2.0f) return true;
    return false;
}

Ring::Ring(float x, float y, float z,float r) {
    this->position = glm::vec3(x, y, z);
    this->rotation = 0.0f;
    this->rad = r;
    this->timer = clock();
    int n= 40;
    int inc = 0;
    GLfloat vertex_buffer_data[18*n];
    GLfloat color_data[18*n];
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
        color_data[i]=COLOR_FIRE.r/256.0f;
        color_data[i+2]=COLOR_FIRE.g/256.0f;
        color_data[i+1]=COLOR_FIRE.b/256.0f;
        color_data[i+3]=COLOR_FIRE.r/256.0f;
        color_data[i+5]=COLOR_FIRE.b/256.0f;
        color_data[i+4]=COLOR_FIRE.g/256.0f;
        color_data[i+6]=COLOR_FIRE.r/256.0f;
        color_data[i+8]=COLOR_FIRE.g/256.0f;
        color_data[i+7]=COLOR_FIRE.b/256.0f;
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
        color_data[9*n+i]=COLOR_WHITE.r/256.0f;
        color_data[9*n+i+2]=COLOR_WHITE.g/256.0f;
        color_data[9*n+i+1]=COLOR_WHITE.b/256.0f;
        color_data[9*n+i+3]=COLOR_WHITE.r/256.0f;
        color_data[9*n+i+5]=COLOR_WHITE.b/256.0f;
        color_data[9*n+i+4]=COLOR_WHITE.g/256.0f;
        color_data[9*n+i+6]=COLOR_WHITE.r/256.0f;
        color_data[9*n+i+8]=COLOR_WHITE.g/256.0f;
        color_data[9*n+i+7]=COLOR_WHITE.b/256.0f;
        inc++;
    }
    this->object = create3DObject(GL_TRIANGLES, 6*n, vertex_buffer_data, color_data, GL_FILL);
}
void Ring::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    glm::mat4 rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(0, 0, 1));
    glm::mat4 scale = glm::scale(glm::vec3(5,5,5));
    Matrices.model *= (translate * rotate * scale);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object);
}

void Ring::set_position(float x, float y) {
    this->position = glm::vec3(x, y, 0);
}

bool Ring::tick() {
    this->rotation += 1.0f;
    clock_t end = clock();
    int tame = (int)(end-this->timer)/CLOCKS_PER_SEC;
    if(tame > 10) return true;
    if(this->rotation > 360.0f) this->rotation = 0.0f;
    return false;
}