#include <jni.h>
#include <string>
#include "imread.h"
#include "imwrite.h"
#include <fstream>
#include "lib/mat.h"
extern "C"
//JNIEXPORT jstring JNICALL
//Java_huajun_myapplicationaa_MainActivity_stringFromJNI(
//        JNIEnv *env,
//        jobject /* this */) {
//    std::string hello = "Hello from C++";
//    return env->NewStringUTF(hello.c_str());
//}

JNIEXPORT jint JNICALL
Java_huajun_myapplicationaa_MainActivity_nativeCompressBitmap(
        JNIEnv *env,
        jobject /* this */,
        jstring souPsth,
        jstring resultPath) {
    const char* source = env-> GetStringUTFChars(souPsth, 0);
    const char* result = env-> GetStringUTFChars(resultPath, 0);
    Matuc img = read_JPEG_file(source);
    if(img.isempty())
        return 0;
    LOGD("img width %d \n",img.width());
    LOGD("img height %d \n",img.height());

//    std::ofstream ofs(result,std::ios::trunc);
//
//    for(int i=0;i<img.height();i++)
//    {
//        for (int j = 0; j < img.width(); ++j) {
//            for(int c=0;c<img.channels();++c)
//            {
//                ofs<<(int)img.at(i,j,c)<<" ";
//            }
//        }
//        ofs<<std::endl;
//    }



    write_JPEG_file(result,img);

    env-> ReleaseStringUTFChars(resultPath, result);
    env-> ReleaseStringUTFChars(souPsth, source);
    return 1;
}




























