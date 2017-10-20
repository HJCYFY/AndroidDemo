//
// Created by huajun on 17-10-20.
//

#include "imwrite.h"


GLOBAL(void)
write_JPEG_file (const char * filename, Matuc& mat) {
    struct jpeg_compress_struct cinfo;
    struct jpeg_error_mgr jerr;
    FILE * outfile;		/* target file */
    JSAMPROW row_pointer[1];	/* pointer to JSAMPLE row[s] */
    int row_stride;		/* physical row width in image buffer */
    cinfo.err = jpeg_std_error(&jerr);
    jpeg_create_compress(&cinfo);

    if ((outfile = fopen(filename, "wb")) == NULL) {
        LOGD("can't open %s\n", filename);
        return;
    }
    jpeg_stdio_dest(&cinfo, outfile);

    cinfo.image_width = mat.width(); 	/* image width and height, in pixels */
    cinfo.image_height = mat.height();
    cinfo.input_components = mat.channels();		/* # of color components per pixel */
    if(mat.channels()==1)
        cinfo.in_color_space = JCS_GRAYSCALE;
    else
        cinfo.in_color_space = JCS_RGB; 	/* colorspace of input image */

    jpeg_set_defaults(&cinfo);
    // 设置质量为100
    jpeg_set_quality(&cinfo, 100, TRUE /* limit to baseline-JPEG values */);
    jpeg_start_compress(&cinfo, TRUE);


    while (cinfo.next_scanline < cinfo.image_height) {
        row_pointer[0] =  mat.ptr(cinfo.next_scanline);
        (void) jpeg_write_scanlines(&cinfo, row_pointer, 1);
    }
    jpeg_finish_compress(&cinfo);
    fclose(outfile);
    jpeg_destroy_compress(&cinfo);
}
