#ifndef POINT_H
#define POINT_H


class Point{
    private:
        int x,y;
    public:
        Point(int _x, int _y);
        Point(const Point& p);
        int getX() const;
        int getY() const;
        
};

#endif