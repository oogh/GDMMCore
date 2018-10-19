/**********************************************************************************************
 *
 *
 **********************************************************************************************
 * @创建人：andy
 * @创建日期： 2018/10/19 10:24
 * @版本： 1.0
 **********************************************************************************************
 * @修改人：
 * @修改时间：
 * @修改描述：
 * @版本：
 **********************************************************************************************
 */
#ifndef GDMMCORE_RECTANGLE_H
#define GDMMCORE_RECTANGLE_H

#include "platform.h"
#include "shader.h"

class Rectangle {
public:
    GLuint program;
    GLuint aPosition;
    GLuint aTexCoords;
    GLuint uTexture;

    int vertexCount = 0;
    float *vertex_coords = NULL;
    float *texture_coords = NULL;

    Rectangle();
    ~Rectangle();

    void init();
    void draw();
    void setTexture(GLuint textureId);

};


#endif //GDMMCORE_RECTANGLE_H
