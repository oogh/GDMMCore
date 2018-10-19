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

#ifndef shader_h
#define shader_h

#include "platform.h"

static void print_gl_string(const char *name, GLenum s){
    const char *v = (const char *)glGetString(s);
    LOGD("【OpenGL】 %s = %s", name, v);
}

static void check_gl_error(const char *op) {
    for (GLint error = glGetError(); error; error = glGetError()) {
        LOGD("【OpenGL】执行 %s() 时出现：glError (0x%x)\n", op, error);
    }
}

/**
 *  创建着色器
 */
static GLuint create_shader(GLenum type, const char *code) {
    GLuint shader = glCreateShader(type);
    if (!shader) {
        check_gl_error("glCreateShader");
        return 0;
    }
    glShaderSource(shader, 1, &code, NULL);
    GLint compiled = GL_FALSE;
    glCompileShader(shader);
    glGetShaderiv(shader, GL_COMPILE_STATUS, &compiled);
    if (!compiled) {
        GLint infoLogLen = 0;
        glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &infoLogLen);
        if (infoLogLen > 0) {
            GLchar *infoLog = new GLchar[infoLogLen];
            if (infoLog) {
                glGetShaderInfoLog(shader, infoLogLen, NULL, infoLog);
                LOGD("【OpenGL】编译失败： %s shader:\n%s\n",
                      type == GL_VERTEX_SHADER ? "vertex" : "fragment",
                      infoLog);
                delete[] infoLog;
            }
        }
        glDeleteShader(shader);
        return 0;
    }
    return shader;
}

/**
 * 创建渲染程序
 */
static GLuint createProgram(const char *code_vertex, const char *code_frag) {
    GLuint vShader = 0;
    GLuint fShader = 0;
    GLuint program = 0;
    GLint linked = GL_FALSE;
    vShader = create_shader(GL_VERTEX_SHADER, code_vertex);
    if (!vShader)
        goto exit;
    fShader = create_shader(GL_FRAGMENT_SHADER, code_frag);
    if (!fShader)
        goto exit;
    program = glCreateProgram();
    if (!program) {
        check_gl_error("glCreateProgram");
        goto exit;
    }
    glAttachShader(program, vShader);
    glAttachShader(program, fShader);
    glLinkProgram(program);
    glGetProgramiv(program, GL_LINK_STATUS, &linked);
    if (!linked) {
        GLint len = 0;
        glGetProgramiv(program, GL_INFO_LOG_LENGTH, &len);
        if (len) {
            GLchar *error_msg = new GLchar[len];
            if (error_msg) {
                glGetProgramInfoLog(program, len, NULL, error_msg);
                LOGD("【OpenGL】链接渲染程序失败:\n%s\n", error_msg);
                delete[] error_msg;
            }
        }
        glDeleteProgram(program);
        program = 0;
    }
exit:
    glDeleteShader(vShader);
    glDeleteShader(fShader);
    return program;
}

#endif /* shader_h */
