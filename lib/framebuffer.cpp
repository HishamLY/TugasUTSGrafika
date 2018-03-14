#include "framebuffer.h"

FrameBuffer::FrameBuffer() {
    // Mencoba membuka driver framebuffer
    fbfd = open("/dev/fb0", O_RDWR);
    if (fbfd == -1) {
        perror("Error: driver framebuffer tidak dapat dibuka");
        exit(1);
    } 
    screensize = 0;
    // Pada baris ini framebuffer berhasil diakses 
    printf("[ OK ] Framebuffer berhasil diakses\n");

    // Mencoba mendapatkan informasi fixed screen 
    if (ioctl(fbfd, FBIOGET_FSCREENINFO, &finfo) == -1) {
        perror("Error reading fixed information");
        exit(2);
    }
    // Pada baris ini didapatkan informasi fixed screen
    printf("[ OK ] B`erhasil mendapatkan informasi fixed screen\n");


    // Mencoba mendapatkan informasi variabel screen (resolution, bits per pixel)
    if (ioctl(fbfd, FBIOGET_VSCREENINFO, &vinfo) == -1) {
        perror("Error reading variable information");
        exit(3);
    }
    // Pada baris ini didapatkan informasi variabel screen
    printf("[ OK ] Berhasil mendapatkan informasi variabel screen\n");

    // Print informasi layar
    printf("[ INFO ] Informasi Layar: %dx%d px, %dbits per pixel\n", vinfo.xres, vinfo.yres, vinfo.bits_per_pixel);

    // Mengubah ukuran layar ke satuan bytes
    screensize = vinfo.xres * vinfo.yres * vinfo.bits_per_pixel / 8;
    // Print screen size (bytes)
    printf("[ INFO ] Screen size (bytes): %ld\n", screensize);


    // Mapping driver framebuffer ke memori
    fbp = (char *)mmap(0, screensize, PROT_READ | PROT_WRITE, MAP_SHARED, fbfd, 0);
    if(atoi(fbp) == -1){
        perror("Error: failed to map framebuffer device to memory");
        exit(4);
    }
    // Pada baris ini berhasil memetakan driver framebuffer ke memori
    printf("[ OK ] Mapping from framebuffer to memory success\n");
}

FrameBuffer::~FrameBuffer() {

}

int FrameBuffer::getXRes() {
    return vinfo.xres;
}

 int FrameBuffer::getYRes() {
     return vinfo.yres;
 }


void FrameBuffer::draw_point(int x, int y, Warna* c) {
    if ((x > 50 && y > 10) && (x < vinfo.xres-50 && y < vinfo.yres-10)) {
        long int location = (x+vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (y+vinfo.yoffset) * finfo.line_length;
        if(vinfo.bits_per_pixel == 32){
            *(fbp + location) = c->getB();
            *(fbp + location + 1) = c->getG();
            *(fbp + location + 2) = c->getR();
            *(fbp + location + 3) = c->getA();
        } else{ //assume 16 bit color
            int b = c->getB();
            int g = c->getG();
            int r = c->getR();
            unsigned short int t = r<<11 | g << 5 | b;
            *((unsigned short int*)(fbp + location)) = t;
        }
    }
}

