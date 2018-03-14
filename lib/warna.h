#ifndef WARNA_H
#define WARNA_H

class Warna {
    private:
        unsigned char r;
        unsigned char g;
        unsigned char b;
        unsigned char a;
    public:
        Warna(unsigned char _r, unsigned char _g, unsigned char _b,unsigned char _a);
        unsigned char getR();
        unsigned char getG();
        unsigned char getB();
        unsigned char getA();
};

#endif