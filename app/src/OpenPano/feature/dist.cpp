//
// Created by huajun on 17-10-19.
//
// ToDo neon加速
#include "dist.h"
#include "lib/utils.h"
#include "lib/timer.h"

#include <limits>

namespace pano {

    float euclidean_sqr(
            const float* x, const float* y,
            size_t size, float now_thres) {
        m_assert(size % 4 == 0);
        float ans = 0;
        float diff0, diff1, diff2, diff3;
        const float* end = x + size;
        while (x < end) {
            diff0 = x[0] - y[0];
            diff1 = x[1] - y[1];
            diff2 = x[2] - y[2];
            diff3 = x[3] - y[3];
            ans += sqr(diff0) + sqr(diff1) + sqr(diff2) + sqr(diff3);
            if (ans > now_thres)
                return std::numeric_limits<float>::max();
            x += 4, y += 4;
        }
        return ans;
    }


    int hamming(const float* x, const float* y, int n) {
        int sum = 0;
        REP(i, n) {
            unsigned int* p1 = (unsigned int*)&x[i];
            unsigned int* p2 = (unsigned int*)&y[i];
            sum += __builtin_popcount((*p1) ^ *(p2));
        }
        return sum;
    }

}
