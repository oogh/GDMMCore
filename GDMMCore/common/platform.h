#define TAG "GDMMCore"
#define DEBUG 1

#if __ANDROID__

	#include <GLES2/gl2.h>
    #include <android/log.h>

    #ifdef DEBUG
        #define LOGI(...) __android_log_print(ANDROID_LOG_INFO, TAG, __VA_ARGS__)
        #define LOGD(...) __android_log_print(ANDROID_LOG_WARN, TAG, __VA_ARGS__)
        #define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, TAG, __VA_ARGS__)
    #else
        #define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, TAG, __VA_ARGS__)
    #endif
#elif __APPLE__

	#import <OpenGLES/ES2/gl.h>
    #import <stdio.h>

    #if DEBUG
        #define LOGD(fmt, ...) printf("%s: ",TAG);printf((fmt), ##__VA_ARGS__);printf("\n");
    #else
        #define LOGD(fmt, ...) printf("%s: ",TAG);printf((fmt), ##__VA_ARGS__);printf("\n");
    #endif
#endif
