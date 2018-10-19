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
#include "rectangle.h"
#include "utils.h"

Rectangle::Rectangle() {
    init();
}

Rectangle::~Rectangle() {
    delete[] vertex_coords;
    delete[] texture_coords;
}

void Rectangle::init() {
    vertexCount = 4;

    vertex_coords = new float[vertexCount * 3] {
            1.0f, -1.0f, 0.0f,
            -1.0f, -1.0f, 0.0f,
            1.0f, 1.0f, 0.0f,
            -1.0f, 1.0f, 0.0f,
    };

    texture_coords = new float[vertexCount * 2] {
            1.0f, 0.0f, //右下
            0.0f, 0.0f,
            1.0f, 1.0f,
            0.0, 1.0
    };

    const char *vertexShader = GET_STR(
            attribute vec4 aPosition;
            attribute vec2 aTextureCoord;
            varying vec2 vTextureCoord;
            void main() {
                vTextureCoord = vec2(aTextureCoord.x, 1.0 - aTextureCoord.y);
                gl_Position = aPosition;
            }
    );

    const char *fragRGB = GET_STR(
            precision mediump float;
            varying vec2 vTextureCoord;
            uniform sampler2D uTexture;
            void main() {
                gl_FragColor = texture2D(uTexture, vTextureCoord);
            }
    );

    const char *fragYUV420P = GET_STR(
            precision mediump float;
            varying vec2 vTexCoord;
            uniform sampler2D yTexture;
            uniform sampler2D uTexture;
            uniform sampler2D vTexture;
            void main() {
                vec3 yuv;
                vec3 rgb;
                yuv.r = texture2D(yTexture, vTexCoord).r;
                yuv.g = texture2D(uTexture, vTexCoord).r - 0.5;
                yuv.b = texture2D(vTexture, vTexCoord).r - 0.5;
                rgb = mat3(1.0, 1.0, 1.0,
                           0.0, -0.39465, 2.03211,
                           1.13983, -0.58060, 0.0) * yuv;
                gl_FragColor = vec4(rgb, 1.0);
            }
    );

    // 创建着色器程序
    program = createProgram(vertexShader, fragRGB);
    // 获取着色器中的属性引用
    aPosition = glGetAttribLocation(program, "aPosition");
    aTexCoords = glGetAttribLocation(program, "aTextureCoord");
    uTexture = glGetUniformLocation(program, "uTexture");
    // 使用着色器程序
    glUseProgram(program);
    // 给着色器传递顶点坐标数据
    glVertexAttribPointer(aPosition, 3, GL_FLOAT, GL_FALSE, 0, vertex_coords);
    glEnableVertexAttribArray(aPosition);
    // 给着色器传递纹理坐标数据
    glVertexAttribPointer(aTexCoords, 2, GL_FLOAT, GL_FALSE, 0, texture_coords);
    glEnableVertexAttribArray(aTexCoords);
}

void Rectangle::draw() {
    glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
}

void Rectangle::setTexture(GLuint textureId) {
    // 激活纹理单元0
    glActiveTexture(GL_TEXTURE0);
    // 绑定纹理
    glBindTexture(GL_TEXTURE_2D, textureId);
    // 给着色器传递纹理数据
    glUniform1i(uTexture, 0);
}


