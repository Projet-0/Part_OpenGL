#ifndef CUBE_H
#define CUBE_H

#include <QOpenGLFunctions>
#include <QOpenGLShaderProgram>
#include <QOpenGLBuffer>


class cube : protected QOpenGLFunctions
{
public:
    cube();
    cube(float x, float y, float z, float size) {x_ = x ; y_ = y, z_ = z, size_ = size ;};
    void draw(float x,float y,float z, float size);
    ~cube();

//    void initialize();
    void render();

private:
    QOpenGLShaderProgram shaderProgram;
    QOpenGLBuffer vertexBuffer;
    QOpenGLBuffer indexBuffer;

    float x_;
    float y_;
    float z_;
    float size_;


};

#endif // CUBE_H
