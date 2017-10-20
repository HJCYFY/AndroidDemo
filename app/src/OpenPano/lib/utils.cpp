//
// Created by huajun on 17-10-19.
//

#include "utils.h"

void __m_assert_check__(bool val, const char *expr, const char *file, const char *func, int line) {
    if (val)
        return;
    LOGD("assertion \"%s\" failed, in %s, (%s:%d)\n",
              expr, func, file, line);
    abort();
    //exit(1);
}