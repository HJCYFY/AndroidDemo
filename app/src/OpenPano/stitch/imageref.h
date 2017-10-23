//
// Created by huajun on 17-10-20.
//

#pragma once
#include <string>
#include <memory>
#include "lib/mat.h"
#include "lib/imgproc.h"
#include "match_info.h"
namespace pano {
// A transparent reference to a image in file


    Mat32f read_img(const char* fname);

    struct ImageRef {
        std::string fname;
        Mat32f* img = nullptr;
        int _width, _height;

        ImageRef(const std::string& fname): fname(fname) {}
        //ImageRef(const ImageRef& ) = delete;  // TODO make it work
        ~ImageRef() { if (img) delete img; }

        void load() {
            if (img) return;
            //ToDo
            img = new Mat32f{read_img(fname.c_str())};
            _width = img->width();
            _height = img->height();
        }

        void release() { if (img) delete img; img = nullptr; }

        int width() const { return _width; }
        int height() const { return _height; }
        Shape2D shape() const { return {_width, _height}; }

    };

}
