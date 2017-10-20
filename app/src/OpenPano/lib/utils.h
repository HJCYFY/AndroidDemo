//
// Created by huajun on 17-10-19.
//

#pragma once

#include <cstdarg>
#include <cstdlib>
#include <string>
#include <cstring>
#include <sstream>
#include <memory>
#include <sys/stat.h>
#include <type_traits>
#include "log.h"

typedef double real_t;
const real_t EPS = 1e-6;
const real_t GEO_EPS_SQR = 1e-14;
const real_t GEO_EPS = 1e-7;
inline float sqr(float x) { return x * x; }

#define between(a, b, c) ((a >= b) && (a <= c - 1))
#define REP(x, y) for (typename std::remove_cv<typename std::remove_reference<decltype(y)>::type>::type x = 0; x < (y); x ++)
#define REPL(x, y, z) for (typename std::remove_cv<typename std::remove_reference<decltype(y)>::type>::type x = y; x < (z); x ++)
#define REPD(x, y, z) for (typename std::remove_cv<typename std::remove_reference<decltype(y)>::type>::type x = y; x >= (z); x --)


void __m_assert_check__(bool val, const char *expr,
                        const char *file, const char *func, int line);


#define m_assert(expr) \
	__m_assert_check__((expr), # expr, __FILE__, __func__ , __LINE__)


template<typename T>
inline bool update_min(T &dest, const T &val) {
    if (val < dest) {
        dest = val; return true;
    }
    return false;
}

template<typename T>
inline bool update_max(T &dest, const T &val) {
    if (dest < val) {
        dest = val; return true;
    }
    return false;
}