//
// Created by huajun on 17-10-19.
//
#pragma once
#include <vector>
#include "dog.h"

namespace pano {
    struct SSPoint;

    class OrientationAssign {
    public:
        OrientationAssign(
                const DOGSpace& dog, const ScaleSpace& ss,
                const std::vector<SSPoint>& keypoints);

        OrientationAssign(const OrientationAssign&) = delete;
        OrientationAssign& operator = (const OrientationAssign&) = delete;

        // assign orientation to each SSPoint
        std::vector<SSPoint> work() const;

    protected:
        const DOGSpace& dog;
        const ScaleSpace& ss;
        const std::vector<SSPoint>& points;

        std::vector<float> calc_dir(const SSPoint& p) const;
    };

}