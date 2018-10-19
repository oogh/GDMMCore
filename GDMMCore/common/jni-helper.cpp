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
#include "jni-helper.h"
#include "render.h"

Render *render = NULL;

#if __ANDROID__
#include <jni.h>
extern "C" JNIEXPORT void JNICALL
Java_me_oogh_demo_JNIHelper_surfaceCreated(JNIEnv *env, jobject instance) {
    surface_created();
}

extern "C" JNIEXPORT void JNICALL
Java_me_oogh_demo_JNIHelper_surfaceChanged(JNIEnv *env, jobject instance, jint width, jint height) {

    surface_changed(width, height);

}

extern "C" JNIEXPORT void JNICALL
Java_me_oogh_demo_JNIHelper_drawFrame(JNIEnv *env, jobject instance) {

    draw_frame();
}

extern "C" JNIEXPORT void JNICALL
Java_me_oogh_demo_JNIHelper_setTexture(JNIEnv *env, jobject instance, jint id) {

    set_texture(id);
}
#endif

void surface_created(){
    render = new Render();
    render->surface_created();
}

void surface_changed(int width, int height){
    render->surface_changed(width, height);
}

void draw_frame(){
    render->draw_frame();

}

void set_texture(unsigned int id){
    render->set_texture(id);
}
