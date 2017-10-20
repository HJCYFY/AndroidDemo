//
// Created by huajun on 17-10-19.
//

#pragma once
#include <list>
#include "mat.h"
#include "color.h"

class Matrix;

namespace pano {
    Mat32f hconcat(const std::list<Mat32f>& mats);
    Mat32f vconcat(const std::list<Mat32f>& mats);

// interpolate color. return Color::NO if any of the neighbor is Color::NO
    Color interpolate(const Mat32f& mat, float r, float c);

// interpolate color. return Color::NO only if r,c out of border
// return value still in [0,1]
    Color interpolate(const Matuc& mat, float r, float c);

    Mat32f crop(const Mat32f& mat);

    Mat32f rgb2grey(const Mat32f& mat);

    Matrix getPerspectiveTransform(const std::vector<Vec2D>& p1, const std::vector<Vec2D>& p2);
    Matrix getAffineTransform(const std::vector<Vec2D>& p1, const std::vector<Vec2D>& p2);

    void fill(Mat32f& mat, const Color& c);
    void fill(Mat32f& mat, float c);

    template <typename T>
    void resize(const Mat<T> &src, Mat<T> &dst);

    Matuc cvt_f2uc(const Mat32f& mat);
}