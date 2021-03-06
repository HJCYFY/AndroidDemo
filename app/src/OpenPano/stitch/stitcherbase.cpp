//
// Created by huajun on 17-10-20.
//

#include "stitcherbase.h"
#include "lib/timer.h"

namespace pano {

    void StitcherBase::calc_feature() {
        GuardedTimer tm("calc_feature()");
        LOGD("imgs size %d\n",imgs.size());
        feats.resize(imgs.size());
        keypoints.resize(imgs.size());
        // detect feature
#pragma omp parallel for schedule(dynamic)
        REP(k, (int)imgs.size()) {
            imgs[k].load();
            feats[k] = feature_det->detect_feature(*imgs[k].img);
            if (config::LAZY_READ)
                imgs[k].release();
            LOGD("Image %d has %lu features\n", k, feats[k].size());
            keypoints[k].resize(feats[k].size());
            REP(i, feats[k].size())
            keypoints[k][i] = feats[k][i].coor;
        }
    }

    void StitcherBase::free_feature() {
        feats.clear(); feats.shrink_to_fit();  // free memory for feature
        keypoints.clear(); keypoints.shrink_to_fit();  // free memory for feature
    }

}
