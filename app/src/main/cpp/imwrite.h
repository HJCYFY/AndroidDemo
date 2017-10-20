//
// Created by huajun on 17-10-20.
//

#ifndef MYAPPLICATIONAA_IMWRITE_H
#define MYAPPLICATIONAA_IMWRITE_H

#include <stdio.h>
#include "jpeglib.h"

#include <setjmp.h>
#include "lib/mat.h"
#include "log.h"

GLOBAL(void)
write_JPEG_file (const char * filename, Matuc& mat) ;
#endif //MYAPPLICATIONAA_IMWRITE_H
