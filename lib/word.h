#ifndef WORD_H
#define WORD_H

#include <queue>
#include "framebuffer.h"
#include "warna.h"
#include "matriks.h"
#include "point.h"

using namespace std;

class Word {
    private:
        char c;
        Matriks drawP();
        Matriks drawY();
	    Matriks drawZ();
        Matriks drawG();
        Matriks drawN();
        Matriks drawA();
        Matriks drawU();
        Matriks drawh();
        Matriks drawParachute();
        void draw_line(Matriks &m,int x0,int y0,int x1,int y1);
        void draw_line_high(Matriks &m,int x0,int y0,int x1,int y1);
        void draw_line_low(Matriks &m,int x0,int y0,int x1,int y1);

    public:
        Word(char c);
        Matriks draw();
        int start_fill_x;
        int start_fill_y;
        static void floodFill(Matriks& m,int s_x, int s_y);
};


#endif
