#ifndef MATRIKS_H
#define MATRIKS_H

class Matriks {
    private:
    const int MAXROW, MAXCOL;
    int row, col;
    char** M;

    public:
        Matriks(int m_r, int m_c);
        ~Matriks();
        int getRow();
        int getCol();
        char getVal(int x,int y);
        void setVal(int x,int y, char val);

};

#endif