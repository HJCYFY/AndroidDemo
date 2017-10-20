//
// Created by huajun on 17-10-19.
//


#include "timer.h"
#include <mutex>

// static member
std::map<std::string, std::pair<int, double>> TotalTimer::rst;

void TotalTimer::print() {
    for (auto& itr : rst)
        LOGD("%s spent %lf secs in total, called %d times.\n",
                    itr.first.c_str(), itr.second.second, itr.second.first);
}

TotalTimer::~TotalTimer() {
    static std::mutex mt;
    std::lock_guard<std::mutex> lg(mt);
    auto& p = rst[msg];
    p.second += timer.duration();
    p.first ++;
}
