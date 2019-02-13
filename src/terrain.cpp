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
    
    this->object = create3DObject(GL_TRIANGLES, 12*3, vertex, COLOR_BLACK, normal, GL_FILL);
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

// const int na=36;        // vertex grid size
// const int nb=18;
// const int na3=na*3;     // line in grid size
// const int nn=nb*na3;    // whole grid size
// GLfloat sphere_pos[nn]; // vertex
// GLfloat sphere_nor[nn]; // normal
// GLfloat sphere_col[nn];   // color
// GLuint  sphere_ix [na*(nb-1)*6];    // indices
// GLuint sphere_vbo[4]={1,1,1,1};
// GLuint sphere_vao[4]={1,1,1,1};
// Tapu::Tapu(float x, float y, int height, int width) {
//         // float w = width;
//         // float h = height;
//         // float span = 5.0f;
//         this->position = glm::vec3(x, 0.0f, y);
//         // this->rotation = 0.0f;
//         // this->height = height;
//         // this->width = width;
//         // this->speedz = 2.0f;
//         // const GLfloat vertex[]={
//         // };
//         GLfloat xs,ys,zs,a,b,da,db,r=3.5;
//         int ia,ib,ix,iy;
//         da=2.0*M_PI/GLfloat(na);
//         db=M_PI/GLfloat(nb-1);
//     // [Generate sphere point data]
//     // spherical angles a,b covering whole sphere surface
//     for (ix=0,b=-0.5*M_PI,ib=0;ib<nb;ib++,b+=db)
//      for (a=0.0,ia=0;ia<na;ia++,a+=da,ix+=3)
//         {
//         // unit sphere
//         xs=cos(b)*cos(a);
//         ys=cos(b)*sin(a);
//         zs=sin(b);
//         sphere_pos[ix+0]=xs*r;
//         sphere_pos[ix+1]=ys*r;
//         sphere_pos[ix+2]=zs*r;
//         sphere_nor[ix+0]=xs;
//         sphere_nor[ix+1]=ys;
//         sphere_nor[ix+2]=zs;
//         }
//     // [Generate GL_TRIANGLE indices]
//     for (ix=0,iy=0,ib=1;ib<nb;ib++)
//         {
//         for (ia=1;ia<na;ia++,iy++)
//             {
//             // first half of QUAD
//             sphere_ix[ix]=iy;      ix++;
//             sphere_ix[ix]=iy+1;    ix++;
//             sphere_ix[ix]=iy+na;   ix++;
//             // second half of QUAD
//             sphere_ix[ix]=iy+na;   ix++;
//             sphere_ix[ix]=iy+1;    ix++;
//             sphere_ix[ix]=iy+na+1; ix++;
//             }
//         // first half of QUAD
//         sphere_ix[ix]=iy;       ix++;
//         sphere_ix[ix]=iy+1-na;  ix++;
//         sphere_ix[ix]=iy+na;    ix++;
//         // second half of QUAD
//         sphere_ix[ix]=iy+na;    ix++;
//         sphere_ix[ix]=iy-na+1;  ix++;
//         sphere_ix[ix]=iy+1;     ix++;
//         iy++;
//         }
     
//     // this->object = create3DObject(GL_TRIANGLES,nn/3, sphere_pos, COLOR_RED, GL_FILL);
//         GLuint i;
//     glGenVertexArrays(4,sphere_vao);
//     glGenBuffers(4,sphere_vbo);
//     glBindVertexArray(sphere_vao[0]);
//     i=0; // vertex
//     glBindBuffer(GL_ARRAY_BUFFER,sphere_vbo[i]);
//     glBufferData(GL_ARRAY_BUFFER,sizeof(sphere_pos),sphere_pos,GL_STATIC_DRAW);
//     glEnableVertexAttribArray(i);
//     glVertexAttribPointer(i,3,GL_FLOAT,GL_FALSE,0,0);
//     i=1; // indices
//     glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,sphere_vbo[i]);
//     glBufferData(GL_ELEMENT_ARRAY_BUFFER,sizeof(sphere_ix),sphere_ix,GL_STATIC_DRAW);
//     glEnableVertexAttribArray(i);
//     glVertexAttribPointer(i,4,GL_UNSIGNED_INT,GL_FALSE,0,0);
//     i=2; // normal
//     glBindBuffer(GL_ARRAY_BUFFER,sphere_vbo[i]);
//     glBufferData(GL_ARRAY_BUFFER,sizeof(sphere_nor),sphere_nor,GL_STATIC_DRAW);
//     glEnableVertexAttribArray(i);
//     glVertexAttribPointer(i,3,GL_FLOAT,GL_FALSE,0,0);
// /*
//     i=3; // color
//     glBindBuffer(GL_ARRAY_BUFFER,sphere_vbo[i]);
//     glBufferData(GL_ARRAY_BUFFER,sizeof(sphere_col),sphere_col,GL_STATIC_DRAW);
//     glEnableVertexAttribArray(i);
//     glVertexAttribPointer(i,3,GL_FLOAT,GL_FALSE,0,0);
// */
//     glBindVertexArray(0);
//     glBindBuffer(GL_ARRAY_BUFFER,0);
//     glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,0);
//     glDisableVertexAttribArray(0);
//     glDisableVertexAttribArray(1);
//     glDisableVertexAttribArray(2);
//     glDisableVertexAttribArray(3);
// }
// void Tapu::draw(glm::mat4 VP) {
//     Matrices.model = glm::mat4(1.0);
//     glm::mat4 translate = glm::translate (this->position);    // glTranslatef
//     glm::mat4 rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(1, 1, 1));
//     Matrices.model *= (translate * rotate);
//     glm::mat4 MVP = VP * Matrices.model;
//     glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
//     // draw3DObject(this->object);
//         glEnable(GL_CULL_FACE);
//     glFrontFace(GL_CCW);
//     glEnable(GL_LIGHTING);
//     glEnable(GL_LIGHT0);
//     glBindVertexArray(sphere_vao[0]);
// //  glDrawArrays(GL_POINTS,0,sizeof(sphere_pos)/sizeof(GLfloat));                   // POINTS ... no indices for debug
//     glDrawElements(GL_TRIANGLES,sizeof(sphere_ix)/sizeof(GLuint),GL_UNSIGNED_INT,0);    // indices (choose just one line not both !!!)
//     glBindVertexArray(0);
// }
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
            vertex_buffer_data[9*n+i+3]=z+r*cos(angle2);
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
        float r1 = 25.0f;
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
        this->object1 = make_cylinder(0, 0, 25.5f, 25.0f, 0 , 1.0f,COLOR_TAPU);
        this->object = create3DObject(GL_TRIANGLES, 3*n, vertex_buffer_data, COLOR_TAPU, GL_FILL);
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

void Tapu::tick() {
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
    
}

Lava::Lava(float x, float y){
        this->position = glm::vec3(x, 15.0f, y);
        this->rotation = 0.0f;
        this->s = 0.5;
    this->object = make_cylinder(0.0f,0.0f,3.0f,3.0f,0.0f,1.5f,COLOR_SMOKE);

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
        int n= 50;
        int inc = 0;
        this->timer = clock();
        float r1 = 25.0f;
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
        this->object1 = make_cylinder(0, 0, 25.5f, 25.0f, 0 , 1.0f,COLOR_TAPU2);
        this->object = create3DObject(GL_TRIANGLES, 3*n, vertex_buffer_data, COLOR_TAPU2, GL_FILL);
        this->object2 = create3DObject(GL_TRIANGLES, 6*n, wheel_buffer_data, COLOR_BLACK, GL_FILL);
        this->tope = make_cylinder(0.0f,0.0f,3.5f,2.0f, 1.0f, 15.0f,COLOR_REAL_BLACK);


}
void Canon::draw(glm::mat4 VP) {
    for(int i = 0; i < this->lava.size(); i++){
        this->lava[i].draw(VP);
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
// float min(int a,int b)
// {
//     return a>b?b:a;
// }
float maxu(float a,float b)
{
    return a>b?a:b;
}

void Canon::tick(Plane* plane) {
    float a = plane->position.y - this->position.y;
    float b = plane->position.x - this->position.x;
    float c = plane->position.z - this->position.z;
    this->rotation.y = atan(float(b/c));
    this->rotation.x = atan(float(c/a));
    // this->rotation.z = atan(float(a/b));
    // std::cout<<this->rotation.z<<"-"<<this->rotation.y*180.0f/M_PI<<"-"<<this->rotation.x*180.0f/M_PI<<std::endl;

}
