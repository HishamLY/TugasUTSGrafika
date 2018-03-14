#include "matriks.h"

Matriks::Matriks(int m_r, int m_c):
    MAXCOL(m_c),MAXROW(m_r)
{
    M = new char*[MAXROW];
    for (int i = 0; i < MAXROW; i++) {
        M[i] = new char[MAXCOL];
    }
    for (int i = 0; i < MAXROW; i++)
        for (int j = 0; j < MAXCOL; j++)
            M[i][j] = 0;
    row = MAXROW;
    col = MAXCOL;
}

Matriks::~Matriks() {
    for (int i = 0; i < MAXROW; i++){
        delete [] M[i];
    }
    
    delete [] M;
}

int Matriks::getRow() {
    return this -> row;
}

int Matriks::getCol() {
    return this -> col;
}

char Matriks::getVal(int x, int y){
    if (0 <= x && x < MAXCOL && 0 <= y && y < MAXROW) {
        return M[y][x];
    } else {
        return -1;
    }
}

void Matriks::setVal(int x, int y, char val) {
    if (0 <= x && x < MAXCOL && 0 <= y && y < MAXROW) {
        M[y][x] = val;
    }
}

