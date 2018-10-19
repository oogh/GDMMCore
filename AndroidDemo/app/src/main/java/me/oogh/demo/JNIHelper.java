package me.oogh.demo;

/**********************************************************************************************
 *
 *
 **********************************************************************************************
 * @创建人：andy
 * @创建日期： 2018/10/18 16:28
 * @版本： 1.0
 **********************************************************************************************
 * @修改人：
 * @修改时间：
 * @修改描述：
 * @版本：
 **********************************************************************************************
 */

public class JNIHelper {
    static {
        System.loadLibrary("GDMMCore");
    }

    public native void surfaceCreated();
    public native void surfaceChanged(int width, int height);
    public native void drawFrame();
    public native void setTexture(int textureId);

}
