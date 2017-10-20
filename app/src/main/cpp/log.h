//
// Created by huajun on 17-10-19.
//

#ifndef MYAPPLICATIONAA_LOG_H
#define MYAPPLICATIONAA_LOG_H

#define TAG "COMPRESS"
#include <android/log.h>

#define LOGI(...) \
        __android_log_print(ANDROID_LOG_INFO,TAG,__VA_ARGS__)

#define LOGD(...) \
        __android_log_print(ANDROID_LOG_DEBUG,TAG,__VA_ARGS__)

#define LOGW(...) \
        __android_log_print(ANDROID_LOG_WARN,TAG,__VA_ARGS__)



#endif //MYAPPLICATIONAA_LOG_H
