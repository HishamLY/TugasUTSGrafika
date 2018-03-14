#ifndef FRAMEBUFFER_H
#define FRAMEBUFFER_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <linux/fb.h>
#include <sys/mman.h>
#include <sys/ioctl.h>
#include <math.h>

#include "warna.h"

class FrameBuffer {
    private:
        int fbfd;
        char *fbp;
        struct fb_var_screeninfo vinfo;
        struct fb_fix_screeninfo finfo;
        long int screensize;


    public:
        // Constructor
        FrameBuffer();
        // Destructor
        ~FrameBuffer();

        // X Resolution
        int getXRes();

        // Y Resolution
        int getYRes();
        
        //Draw Point
        void draw_point(int x, int y, Warna* c);

        //Draw Point Clip
        void draw_point_clip(int x, int y, Warna* c);
};

#endif