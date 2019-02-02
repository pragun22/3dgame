#include "terrain.h"
#include "main.h"
double values[100000];
double Terrain::sample(int x, int y)
{
    return values[(x & (this->width - 1)) + (y & (this->height - 1))*width ];
}

void Terrain::setSample(int x, int y, double value)
{
    values[(x & (this->width - 1)) + (y & (this->height - 1)) * this->width] = value;
}

void Terrain::sampleSquare(int x, int y, int size, double value)
{
    int hs = size / 2;
    // a     b
    //
    //    x
    //
    // c     d

    double a = sample(x - hs, y - hs);
    double b = sample(x + hs, y - hs);
    double c = sample(x - hs, y + hs);
    double d = sample(x + hs, y + hs);

    setSample(x, y, ((a + b + c + d) / 4.0) + value);

}

void Terrain::sampleDiamond(int x, int y, int size, double value)
{
    int hs = size / 2;
    double a = sample(x - hs, y);
    double b = sample(x + hs, y);
    double c = sample(x, y - hs);
    double d = sample(x, y + hs);

    setSample(x, y, ((a + b + c + d) / 4.0) + value);
}
Terrain::Terrain(float x, float y, int height, int width, float range,float level) {
    this->position = glm::vec3(x, y, 0);
    this->rotation = 0;
    this->height = height;
    this->width = width;
    speed = 1;
//     void DiamondSquare(unsigned x1, unsigned y1, unsigned x2, unsigned y2, float range, unsigned level) {
//     if (level < 1) return;
//     // diamonds
//     for (unsigned i = x1 + level; i < x2; i += level)
//         for (unsigned j = y1 + level; j < y2; j += level) {
//             float a = m_heightmap[i - level][j - level];
//             float b = m_heightmap[i][j - level];
//             float c = m_heightmap[i - level][j];
//             float d = m_heightmap[i][j];
//             float e = m_heightmap[i - level / 2][j - level / 2] = (a + b + c + d) / 4 + GetRnd() * range;
//         }

//     // squares
//     for (unsigned i = x1 + 2 * level; i < x2; i += level)
//         for (unsigned j = y1 + 2 * level; j < y2; j += level) {
//             float a = m_heightmap[i - level][j - level];
//             float b = m_heightmap[i][j - level];
//             float c = m_heightmap[i - level][j];
//             float d = m_heightmap[i][j];
//             float e = m_heightmap[i - level / 2][j - level / 2];
//             float f = m_heightmap[i - level][j - level / 2] = (a + c + e + m_heightmap[i - 3 * level / 2][j - level / 2]) / 4 + rand() * range;
//             float g = m_heightmap[i - level / 2][j - level] = (a + b + e + m_heightmap[i - level / 2][j - 3 * level / 2]) / 4 + rand() * range;
//         }

//     DiamondSquare(x1, y1, x2, y2, range / 2, level / 2);
// }
    // GLfloat vertex_buffer_data[100000];
    // for(int i = 0 ; i < height ; i++){
    //     for(int j = 0 ; j < widht; j++){
    //         vertex_buffer_data[i] =     1.0f;
    //     }
    // }
    // this->object = create3DObject(GL_TRIANGLES, 12*3, vertex_buffer_data, COLOR_RED, GL_FILL);
}

void Terrain::draw(glm::mat4 VP) {
    // Matrices.model = glm::mat4(1.0f);
    // glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    // glm::mat4 rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(1, 0, 0));
    // Matrices.model *= (translate * rotate);
    // glm::mat4 MVP = VP * Matrices.model;
    // glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    // draw3DObject(this->object);
    	glRotatef(30.0f,0,1,0);
	glRotatef(45.0f,0,0,1);

    glPointSize(3.0f);

    glColor3f(0,0,0);
    for( int y = 0; y < this->height; y += 1)
    for (int x = 0; x < this->width; x += 1)
    {

          glBegin(GL_LINE_LOOP);
          glVertex3f(x,y,sample(x,y));
          glVertex3f(x+1,y,sample(x+1,y));
          glVertex3f(x,y+1,sample(x,y+1));
            glEnd();
            glBegin(GL_LINE_LOOP);
          glVertex3f(x+1,y+1,sample(x+1,y+1));
          glVertex3f(x+1,y,sample(x+1,y));
          glVertex3f(x,y+1,sample(x,y+1));
             glEnd();
    }
}

void Terrain::set_position(float x, float y) {
    this->position = glm::vec3(x, y, 0);
}

void Terrain::tick() {
    this->rotation += speed;
}

