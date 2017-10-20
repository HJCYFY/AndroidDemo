//
// Created by huajun on 17-10-20.
//

#include "stitcher.h"

#include <limits>
#include <string>
#include <cmath>
#include <queue>

using namespace std;
using namespace pano;
using namespace config;
namespace pano {

    Mat32f Stitcher::build() {
        calc_feature();
    }

}