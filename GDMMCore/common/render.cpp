/**********************************************************************************************
 *
 *
 **********************************************************************************************
 * @创建人：andy
 * @创建日期： 2018/10/19 11:41
 * @版本： 1.0
 **********************************************************************************************
 * @修改人：
 * @修改时间：
 * @修改描述：
 * @版本：
 **********************************************************************************************
 */
#include "render.h"

Render::Render() {
    rectangle = new Rectangle();
}

Render::~Render() {

}

void Render::surface_created() {
    glClearColor(1.0f, 0.0f, 0.0f, 0.0f);
    rectangle = new Rectangle();
}

void Render::surface_changed(int width, int height) {
    glViewport(0, 0, width, height);
}

void Render::draw_frame() {
    glClear(GL_COLOR_BUFFER_BIT);
    rectangle->draw();
}

void Render::set_texture(unsigned int id) {
    rectangle->setTexture(id);
}
