//
// Created by huajun on 17-10-19.
//


#include "config.h"
#include "utils.h"
using namespace std;

namespace config {

// TODO allow different types for a value. using template
    ConfigParser::ConfigParser(const char* fname) {
        //ToDo
    }

    float ConfigParser::get(const std::string& s) {
        if (data.count(s) == 0)
            return -1.0;
        return data[s];
    }

    bool CYLINDER;
    bool TRANS;
    bool CROP;
    float FOCAL_LENGTH;
    bool ESTIMATE_CAMERA;
    bool STRAIGHTEN;
    int MAX_OUTPUT_SIZE;
    bool ORDERED_INPUT;
    bool LAZY_READ;

    int MULTIPASS_BA;
    float LM_LAMBDA;

    int SIFT_WORKING_SIZE;
    int NUM_OCTAVE;
    int NUM_SCALE;
    float SCALE_FACTOR;

    float GAUSS_SIGMA;
    int GAUSS_WINDOW_FACTOR;

    float JUDGE_EXTREMA_DIFF_THRES;
    float CONTRAST_THRES;
    float PRE_COLOR_THRES;
    float EDGE_RATIO;

    int CALC_OFFSET_DEPTH;
    float OFFSET_THRES;

    float ORI_RADIUS;

    int ORI_HIST_SMOOTH_COUNT;

    int DESC_HIST_SCALE_FACTOR;
    int DESC_INT_FACTOR;

    float MATCH_REJECT_NEXT_RATIO;

    int RANSAC_ITERATIONS;
    double RANSAC_INLIER_THRES;
    float INLIER_IN_MATCH_RATIO;
    float INLIER_IN_POINTS_RATIO;

    float SLOPE_PLAIN;

    int MULTIBAND;

}

