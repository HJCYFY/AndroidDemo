#include <jni.h>
#include <string>
#include "imread.h"
#include "imwrite.h"
#include <ctime>
#include <vector>
#include "stitch/stitcher.h"
#include "stitch/cylstitcher.h"
#include "lib/timer.h"


using namespace std;
using namespace config;
using namespace pano;

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

    write_JPEG_file(result,img);

    env-> ReleaseStringUTFChars(resultPath, result);
    env-> ReleaseStringUTFChars(souPsth, source);
    return 1;
}



void write_rgb(string outFileName,Mat32f mat){

    Matuc img(mat.rows(), mat.cols(),3);
    REP(i, mat.rows())
        REP(j, mat.cols()) {
            // use white background. Color::NO turns to 1
            img.at(i, j, 0) = (mat.at(i, j, 0) < 0 ? 1 : mat.at(i, j, 0)) * 255;
            img.at(i, j, 1) = (mat.at(i, j, 1) < 0 ? 1 : mat.at(i, j, 1)) * 255;
            img.at(i, j, 2) = (mat.at(i, j, 2) < 0 ? 1 : mat.at(i, j, 2)) * 255;
        }

    write_JPEG_file(outFileName.c_str(),img);

}



extern "C"
JNIEXPORT void JNICALL
Java_huajun_myapplicationaa_MainActivity_stitchImg(
        JNIEnv *env,
        jobject /* this */,
        jint imgNum,
        jstring souPsth,
        jstring resultPath) {
    GuardedTimer Totaltm("Total image");
    const char* source = env-> GetStringUTFChars(souPsth, 0);
    const char* result = env-> GetStringUTFChars(resultPath, 0);

    string sSoucrPath = source;
    string sResultPath = result;
    srand(time(NULL));
    config::SetDefaultParam();
    vector<string> imgs;
    char name[20];
    REP(i, imgNum)
    {
        sprintf(name,"/medium%02d.jpg",i);
        string sName = sSoucrPath+name;
        LOGD("name %s \n",sName.c_str());
        imgs.emplace_back(sName);
    }
    env-> ReleaseStringUTFChars(souPsth, source);
    env-> ReleaseStringUTFChars(resultPath, result);

    Mat32f res;
    if (CYLINDER) {
        CylinderStitcher p(move(imgs));
        res = p.build();
    } else {
        Stitcher p(move(imgs));
        res = p.build();
    }
    if (CROP) {
        int oldw = res.width(), oldh = res.height();
        res = crop(res);
        LOGD("Crop from %dx%d to %dx%d\n", oldw, oldh, res.width(), res.height());
    }
    {
        GuardedTimer tm("Writing image");
        write_rgb(sResultPath, res);
    }
    return;
}

























