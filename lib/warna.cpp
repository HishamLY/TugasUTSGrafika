#include "warna.h"

Warna::Warna(unsigned char _r, unsigned char _g, unsigned char _b, unsigned char _a) :
    r(_r),g(_g),b(_b),a(_a)
{}

unsigned char Warna::getR() {
    return r;
}
unsigned char Warna::getG() {
    return g;
}
unsigned char Warna::getB() {
    return b;
}
unsigned char Warna::getA() {
    return a;
}