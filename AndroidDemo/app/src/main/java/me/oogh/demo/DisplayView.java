package me.oogh.demo;

import android.content.Context;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.opengl.GLES20;
import android.opengl.GLSurfaceView;
import android.opengl.GLSurfaceView;
import android.opengl.GLUtils;
import android.util.AttributeSet;
import android.util.Log;

import javax.microedition.khronos.egl.EGLConfig;
import javax.microedition.khronos.opengles.GL10;

/**********************************************************************************************
 *
 *
 **********************************************************************************************
 * @创建人：andy
 * @创建日期： 2018/10/18 16:27
 * @版本： 1.0
 **********************************************************************************************
 * @修改人：
 * @修改时间：
 * @修改描述：
 * @版本：
 **********************************************************************************************
 */
public class DisplayView extends GLSurfaceView implements GLSurfaceView.Renderer {

    private JNIHelper mJNIHelper;

    public DisplayView(Context context) {
        super(context);
        init();
    }

    public DisplayView(Context context, AttributeSet attrs) {
        super(context, attrs);
        init();
    }

    private void init(){
        setEGLContextClientVersion(2);
        setRenderer(this);

        mJNIHelper = new JNIHelper();
    }

    @Override
    public void onSurfaceCreated(GL10 gl, EGLConfig config) {
        mJNIHelper.surfaceCreated();
    }

    @Override
    public void onSurfaceChanged(GL10 gl, int width, int height) {
        mJNIHelper.surfaceChanged(width, height);
    }

    @Override
    public void onDrawFrame(GL10 gl) {
        mJNIHelper.drawFrame();
    }

    public void loadImage(final String path) {
        queueEvent(() -> {
            int[] textures = new int[1];
            GLES20.glGenTextures(1, textures, 0);
            int textureId = textures[0];
            GLES20.glBindTexture(GLES20.GL_TEXTURE_2D, textureId);
            GLES20.glTexParameterf(GLES20.GL_TEXTURE_2D, GLES20.GL_TEXTURE_MIN_FILTER, GLES20.GL_LINEAR);
            GLES20.glTexParameterf(GLES20.GL_TEXTURE_2D, GLES20.GL_TEXTURE_MAG_FILTER, GLES20.GL_LINEAR);
            GLES20.glTexParameterf(GLES20.GL_TEXTURE_2D, GLES20.GL_TEXTURE_WRAP_S, GLES20.GL_CLAMP_TO_EDGE);
            GLES20.glTexParameterf(GLES20.GL_TEXTURE_2D, GLES20.GL_TEXTURE_WRAP_T, GLES20.GL_CLAMP_TO_EDGE);

            Bitmap bitmap = null;
            try {
                bitmap = BitmapFactory.decodeFile(path);
            } catch (Exception e) {
                e.printStackTrace();
            }
            if (bitmap != null) {
                GLUtils.texImage2D(GLES20.GL_TEXTURE_2D, 0, bitmap, 0);
                mJNIHelper.setTexture(textureId);
                bitmap.recycle();
            }
        });
    }

}
