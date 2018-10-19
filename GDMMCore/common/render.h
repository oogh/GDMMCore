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
 */#ifndef GDMMCORE_RENDER_H
#define GDMMCORE_RENDER_H

#include "platform.h"
#include "rectangle.h"

class Render {
public:

    Rectangle *rectangle = NULL;

    Render();

    ~Render();

    void surface_created();

    void surface_changed(int width, int height);

    void draw_frame();

    void set_texture(unsigned int id);
};

#endif //GDMMCORE_RENDER_H
