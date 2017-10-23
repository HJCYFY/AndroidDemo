//
// Created by huajun on 17-10-20.
//
#include "imageref.h"
#include "imread.h"

namespace pano {
    Mat32f read_img(const char *fname) {

        Matuc img = read_JPEG_file(fname);
        m_assert(img.channels() == 3 || img.channels() == 1);
        Mat32f mat(img.height(), img.width(), 3);
        if (img.channels() == 3) {
            const int size = img.height() * img.width() * 3;
            u_char *souData = img.ptr();
            float *dstData = mat.ptr();
            REP(i, size) {
                dstData[i] = (float) souData[i] / 255.0;
            }
        } else {
            const int size = img.height() * img.width() * 3;
            u_char *souData = img.ptr();
            float *dstData = mat.ptr();
            REP(i, size) {
                dstData[i] = dstData[i + 1] = dstData[i + 2] = (float) souData[i] / 255.0;
            }
        }
        m_assert(mat.rows() > 1 && mat.cols() > 1);
        return mat;
    }
}