//
// Created by huajun on 17-10-19.
//

#ifndef MYAPPLICATIONAA_IMREAD_H
#define MYAPPLICATIONAA_IMREAD_H

#include "stdio.h"
#include <setjmp.h>
#include "jpeglib.h"
#include "log.h"
#include "lib/mat.h"

GLOBAL(Matuc)
read_JPEG_file (const char * filename);

#endif //MYAPPLICATIONAA_IMREAD_H
