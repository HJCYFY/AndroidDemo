//
// Created by huajun on 17-10-19.
//


#include "config.h"
#include "utils.h"
using namespace std;

namespace config {

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


    void SetDefaultParam(){
        CYLINDER = false;
        TRANS = false;
        ESTIMATE_CAMERA = true;

        ORDERED_INPUT = false;
        CROP = true;
        MAX_OUTPUT_SIZE = 8000;
        LAZY_READ = true;

        FOCAL_LENGTH = 37;

        SIFT_WORKING_SIZE = 800;
        NUM_OCTAVE = 3;
        NUM_SCALE = 7;
        SCALE_FACTOR = 1.4142135623;
        GAUSS_SIGMA = 1.4142135623;
        GAUSS_WINDOW_FACTOR = 4;

        CONTRAST_THRES = 3e-2;

        JUDGE_EXTREMA_DIFF_THRES = 2e-3;

        EDGE_RATIO = 10;

        PRE_COLOR_THRES = 5e-2;

        CALC_OFFSET_DEPTH = 4;

        OFFSET_THRES = 0.5;

        ORI_RADIUS = 4.5;

        ORI_HIST_SMOOTH_COUNT = 2;
        DESC_HIST_SCALE_FACTOR = 3;
        DESC_INT_FACTOR = 512;

        MATCH_REJECT_NEXT_RATIO = 0.8;

        RANSAC_ITERATIONS = 1500;
        RANSAC_INLIER_THRES = 3.5;

        INLIER_IN_MATCH_RATIO = 0.1;
        INLIER_IN_POINTS_RATIO = 0.04;

        STRAIGHTEN = 1;
        SLOPE_PLAIN = 8e-3;
        LM_LAMBDA = 5;
        MULTIPASS_BA = 1;

        MULTIBAND = 0;

    }


}

